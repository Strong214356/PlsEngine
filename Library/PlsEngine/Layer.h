#pragma once

#include "Core.h"
#include "Event/Event.h"

namespace PlsEngine {
    class Layer {
    protected:
        std::string m_DebugName;
    public:
        Layer(const std::string& name = "Layer");
        virtual ~Layer();
        
        virtual void OnAttach() {}
        virtual void OnDetach() {}
        virtual void OnUpdate() {}
        virtual void OnEvent(Event& e) {}
        
        inline const std::string& GetName() const {return m_DebugName;}
    };
}
