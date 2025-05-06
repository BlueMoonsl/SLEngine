#pragma once

#include "SLEngine.h"

class ExampleLayer : public SLEngine::Layer
{
public:
    ExampleLayer();
    virtual ~ExampleLayer() = default;

    virtual void OnAttach() override;
    virtual void OnDetach() override;

    void OnUpdate(SLEngine::Timestep ts) override;
    virtual void OnImGuiRender() override;
    void OnEvent(SLEngine::Event& e) override;
private:
    SLEngine::ShaderLibrary m_ShaderLibrary;
    SLEngine::Ref<SLEngine::Shader> m_Shader;
    SLEngine::Ref<SLEngine::VertexArray> m_VertexArray;

    SLEngine::Ref<SLEngine::Shader> m_FlatColorShader;
    SLEngine::Ref<SLEngine::VertexArray> m_SquareVA;

    SLEngine::Ref<SLEngine::Texture2D> m_Texture, m_ChernoLogoTexture;

    SLEngine::OrthographicCameraController m_CameraController;
    glm::vec3 m_SquareColor = { 0.2f, 0.3f, 0.8f };
};