//
// Created by tidian on 18/09/22.
//

#include "Application.h"
#include "Log.h"

#include <GLFW/glfw3.h>

namespace PlsEngine {
    
#define BIND_EVENT_FNC(x) std::bind(&x, this, std::placeholders::_1)
    
    Application::Application() {
        m_Window = std::unique_ptr<Window>(Window::Create());
        m_Window->SetEventCallback(BIND_EVENT_FNC(Application::OnEvent));
    }

    Application::~Application() {

    }
    
    void Application::PushLayer(Layer* layer, bool overlay) {
        if(overlay) m_LayerStack.PushOverlay(layer);
        else m_LayerStack.PushLayer(layer);
    }

    void Application::Run() {
        while(m_Running) {
            glClearColor(1, 0, 1, 1);
            glClear(GL_COLOR_BUFFER_BIT);
            for(Layer* l : m_LayerStack) l->OnUpdate();
            m_Window->OnUpdate();
        }
    }
    
    void Application::OnEvent(Event& e) {
        EventDispacher disp(e);
        disp.Dispach<WindowCloseEvent>(BIND_EVENT_FNC(Application::OnWindowClose));
        CORE_TRACE("{0}", e);
        for(auto it = m_LayerStack.end(); it != m_LayerStack.begin();) {
            (*--it)->OnEvent(e);
            if(e.m_Handled) break;
        }
    }
    
    bool Application::OnWindowClose(WindowCloseEvent& e) {
        m_Running = false;
        return true;
    }
} // PlsEngine
