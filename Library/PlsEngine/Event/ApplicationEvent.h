//
// Created by tidian on 20/09/22.
//

#ifndef PLSENGINE_APPLICATIONEVENT_H
#define PLSENGINE_APPLICATIONEVENT_H

#include "Event.h"

namespace PlsEngine {
    class WindowResizeEvent : public Event {
    private:
        unsigned int m_Width, m_Height;
    public:
        WindowResizeEvent(unsigned int width, unsigned int height) : m_Width(width), m_Height(height) {}
        
        inline unsigned int GetWidth() const {return m_Width;}
        inline unsigned int GetHeight() const {return m_Height;}
        
        std::string ToString() const override {
            std::stringstream ss;
            ss << "WindowResizeEvent : <resolution : {" << m_Width << "; " << m_Height << "}>";
            return ss.str();
        }
        
        EVENT_CLASS_TYPE(WindowResize)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)
    };
    
    class WindowCloseEvent : public Event {
    public:
        WindowCloseEvent() {}
        
        EVENT_CLASS_TYPE(WindowClose)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)
    };
    
    class AppTickEvent : public Event {
    public:
        AppTickEvent() {}
        
        EVENT_CLASS_TYPE(AppTick)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)
    };
    
    class AppUpdateEvent : public Event {
    public:
        AppUpdateEvent() {}
        
        EVENT_CLASS_TYPE(AppUpdate)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)
    };
    
    class AppRenderEvent : public Event {
    public:
        AppRenderEvent() {}
        
        EVENT_CLASS_TYPE(AppRender)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)
    };
}

#endif //PLSENGINE_APPLICATIONEVENT_H
