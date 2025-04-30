#pragma once

#include "SLEngine.h"

class Sandbox2D : public SLEngine::Layer    
{
public:
    Sandbox2D();
    virtual ~Sandbox2D() = default;

    virtual void OnAttach() override;
    virtual void OnDetach() override;

    void OnUpdate(SLEngine::Timestep ts) override;
    virtual void OnImGuiRender() override;
    void OnEvent(SLEngine::Event& e) override;
private:
    SLEngine::OrthographicCameraController m_CameraController;

    // Temp
    SLEngine::Ref<SLEngine::VertexArray> m_SquareVA;
    SLEngine::Ref<SLEngine::Shader> m_FlatColorShader;

    glm::vec4 m_SquareColor = { 0.2f, 0.3f, 0.8f, 1.0f };
};
