#include "ProgramContext.h"

ProgramContext::ProgramContext() {
}

ProgramContext::~ProgramContext() {
}

void ProgramContext::Init() {
    P3E::Logger::Info("INIT STAGE", P3E::KLoggerOwner::Program);
    P3E::P3E_Init();
    _programConfig.Init();
}

int ProgramContext::Run() {
    if (!glfwInit()) {
        std::cerr << "Could not initialize GLFW!" << std::endl;
        return 1;
    }
    P3E::Logger::Info("init success !!", P3E::KLoggerOwner::GLFW);
    GLFWwindow* window = glfwCreateWindow(_programConfig.GetScreenWidth(), _programConfig.GetScreenHeight(), _programConfig.GetProgramFullTitle().c_str(), NULL, NULL);
    if (!window) {
        std::cerr << "Could not open window!" << std::endl;
        glfwTerminate();
        return 1;
    }
    P3E::Logger::Info("create window success !!", P3E::KLoggerOwner::GLFW);
    while (!glfwWindowShouldClose(window)) {
        //program.Run();
        glfwPollEvents();
    }
    return 0;
}

void ProgramContext::Close() {
    P3E::Logger::Info("FREE RESOURCES STAGE", P3E::KLoggerOwner::Program);
    P3E::Logger::Info("FREE RESOURCES SUCCESS !!", P3E::KLoggerOwner::Program);
    P3E::Logger::Info("SHUTDOWN STAGE", P3E::KLoggerOwner::Program);
    P3E::Logger::Info("SHUTDOWN STAGE SUCCESS !!", P3E::KLoggerOwner::Program);
}
