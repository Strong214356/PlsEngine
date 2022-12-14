//
// Created by tidian on 18/09/22.
//

#ifndef PLSENGINE_ENTRYPOINT_H
#define PLSENGINE_ENTRYPOINT_H

extern PlsEngine::Application* PlsEngine::CreateApplication();

int main(int argc, char** argv) {
    PlsEngine::Log::Init();
    CORE_INFO("Log system Initialized");
    CLIENT_INFO("Log system Initialized");
    auto app = PlsEngine::CreateApplication();
    app->Run();
    delete app;
    return 0;
}

#endif //PLSENGINE_ENTRYPOINT_H
