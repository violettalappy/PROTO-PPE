/*
Copyright 2024 ViolettaLappy { hoanglongplanner }

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at
http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

#include "ProgramContext.h"

int main(int argc, char* argv[]) {
    ProgramContext program;
    program.Init();

    if (!glfwInit()) {
        std::cerr << "Could not initialize GLFW!" << std::endl;
        return 1;
    }
    P3E::Logger::Info("init success !!", P3E::KLoggerOwner::GLFW);
    GLFWwindow* window = glfwCreateWindow(program.GetProgramConfig().GetScreenWidth(), program.GetProgramConfig().GetScreenHeight(), program.GetProgramConfig().GetProgramFullTitle().c_str(), NULL, NULL);
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

    glfwDestroyWindow(window);
    glfwTerminate();

    program.Close();
    return 0;
}
