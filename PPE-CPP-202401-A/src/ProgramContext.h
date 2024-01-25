#ifndef PROGRAMCONTEXT_H
#define PROGRAMCONTEXT_H

#include <iostream>
#include <GLFW/glfw3.h>
#include <P3E/P3E_min.h>

class ProgramContext {
public:
    ProgramContext();
    ~ProgramContext();
private:
    GLFWwindow* _window;
    P3E::ProgramConfig _programConfig;
private:
    void _HandleInput();
    void _Update();
    void _Render();
public:
    P3E::ProgramConfig GetProgramConfig() {
        return _programConfig;
    }
    int Init();
    int Run();
    int Close();
    // void AddWindow();
};

#endif // !PROGRAMCONTEXT_H
