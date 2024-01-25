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
    P3E::ProgramConfig _programConfig;
public:
    P3E::ProgramConfig GetProgramConfig() {
        return _programConfig;
    }
    void Init();
    int Run();
    void Close();
    // void AddWindow();
};

#endif // !PROGRAMCONTEXT_H
