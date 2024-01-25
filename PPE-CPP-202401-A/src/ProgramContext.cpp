#include "ProgramContext.h"

ProgramContext::ProgramContext() {
}

ProgramContext::~ProgramContext() {
}

int ProgramContext::Init() {
    P3E::Logger::Info("init in progress...", P3E::KLoggerOwner::Program);

    P3E::P3E_Init();
    _programConfig.Init();

    P3E::Logger::Info("init in progress...", P3E::KLoggerOwner::GLFW);
    if (!glfwInit()) {
        std::cerr << "Could not initialize GLFW!" << std::endl;
        return 1;
    }
    P3E::Logger::Info("init success !!", P3E::KLoggerOwner::GLFW);
    P3E::Logger::Info("create window in progress...", P3E::KLoggerOwner::GLFW);
    _window = glfwCreateWindow(_programConfig.GetScreenWidth(), _programConfig.GetScreenHeight(), _programConfig.GetProgramFullTitle().c_str(), NULL, NULL);
    if (!_window) {
        std::cerr << "Could not open window!" << std::endl;
        glfwTerminate();
        return 1;
    }
    P3E::Logger::Info("create window success !!", P3E::KLoggerOwner::GLFW);

    P3E::Logger::Info("init success !!", P3E::KLoggerOwner::Program);

    return 0;
}

int ProgramContext::Run() {
    P3E::Logger::Info("run loop in progress...", P3E::KLoggerOwner::Program);

    int i = P3E::KErrorCode::GLFW_InitFailed();

    while (!glfwWindowShouldClose(_window)) {
        // process input
        // update
        // render
        // game
        glfwPollEvents();
    }

    P3E::Logger::Info("run end success !!", P3E::KLoggerOwner::Program);

    return 0;
}

int ProgramContext::Close() {
    P3E::Logger::Info("close in progress...", P3E::KLoggerOwner::Program);

    P3E::Logger::Info("destroy window in progress...", P3E::KLoggerOwner::GLFW);
    glfwDestroyWindow(_window);
    P3E::Logger::Info("destroy window success !!", P3E::KLoggerOwner::GLFW);
    P3E::Logger::Info("terminate in progress...", P3E::KLoggerOwner::GLFW);
    glfwTerminate();
    P3E::Logger::Info("terminate success !!", P3E::KLoggerOwner::GLFW);

    P3E::Logger::Info("close success !!", P3E::KLoggerOwner::Program);

    return 0;
}
