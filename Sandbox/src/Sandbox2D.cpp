#include "Sandbox2D.h"
#include "imgui/imgui.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Platform/OpenGL/OpenGLShader.h"

Sandbox2D::Sandbox2D()
    : Layer("Sandbox2D"), m_CameraController(1280.0f / 720.0f)
{
}

void Sandbox2D::OnAttach()
{
    m_SquareVA = SLEngine::VertexArray::Create();

    float squareVertices[5 * 4] = {
        -0.5f, -0.5f, 0.0f,
         0.5f, -0.5f, 0.0f,
         0.5f,  0.5f, 0.0f,
        -0.5f,  0.5f, 0.0f
    };

    SLEngine::Ref<SLEngine::VertexBuffer> squareVB;
    squareVB.reset(SLEngine::VertexBuffer::Create(squareVertices, sizeof(squareVertices)));
    squareVB->SetLayout({
        { SLEngine::ShaderDataType::Float3, "a_Position" }
        });
    m_SquareVA->AddVertexBuffer(squareVB);

    uint32_t squareIndices[6] = { 0, 1, 2, 2, 3, 0 };
    SLEngine::Ref<SLEngine::IndexBuffer> squareIB;
    squareIB.reset(SLEngine::IndexBuffer::Create(squareIndices, sizeof(squareIndices) / sizeof(uint32_t)));
    m_SquareVA->SetIndexBuffer(squareIB);

    m_FlatColorShader = SLEngine::Shader::Create("assets/shaders/FlatColor.glsl");
}

void Sandbox2D::OnDetach()
{
}

void Sandbox2D::OnUpdate(SLEngine::Timestep ts)
{
    // Update
    m_CameraController.OnUpdate(ts);

    // Render
    SLEngine::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1 });
    SLEngine::RenderCommand::Clear();

    SLEngine::Renderer::BeginScene(m_CameraController.GetCamera());

    std::dynamic_pointer_cast<SLEngine::OpenGLShader>(m_FlatColorShader)->Bind();
    std::dynamic_pointer_cast<SLEngine::OpenGLShader>(m_FlatColorShader)->UploadUniformFloat4("u_Color", m_SquareColor);

    SLEngine::Renderer::Submit(m_FlatColorShader, m_SquareVA, glm::scale(glm::mat4(1.0f), glm::vec3(1.5f)));

    SLEngine::Renderer::EndScene();
}

void Sandbox2D::OnImGuiRender()
{
    ImGui::Begin("Settings");
    ImGui::ColorEdit4("Square Color", glm::value_ptr(m_SquareColor));
    ImGui::End();
}

void Sandbox2D::OnEvent(SLEngine::Event& e)
{
    m_CameraController.OnEvent(e);
}