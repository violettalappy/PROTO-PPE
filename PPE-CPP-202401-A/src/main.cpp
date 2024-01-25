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

#include <iostream>
#include <GLFW/glfw3.h>
#include <P3E/P3E_min.h>

using namespace std;

int main(int argc, char* argv[]) {
	P3E::Logger::Info("INIT STAGE", P3E::KLoggerOwner::Program);

	P3E::P3E_Init();
	P3E::ProgramConfig programConfig = P3E::ProgramConfig();
	if (!glfwInit()) {
		std::cerr << "Could not initialize GLFW!" << std::endl;
		return 1;
	}
	P3E::Logger::Info("init success !!", P3E::KLoggerOwner::GLFW);
	GLFWwindow* window = glfwCreateWindow(programConfig.GetScreenWidth(), programConfig.GetScreenHeight(), programConfig.GetProgramFullTitle().c_str(), NULL, NULL);
	if (!window) {
		std::cerr << "Could not open window!" << std::endl;
		glfwTerminate();
		return 1;
	}
	P3E::Logger::Info("create window success !!", P3E::KLoggerOwner::GLFW);

	P3E::Logger::Info("INIT SUCCESS !!", P3E::KLoggerOwner::Program);

	P3E::Logger::Info("UPDATE STAGE", P3E::KLoggerOwner::Program);
	while (!glfwWindowShouldClose(window)) {
		glfwPollEvents();
	}

	P3E::Logger::Info("FREE RESOURCES STAGE", P3E::KLoggerOwner::Program);
	glfwDestroyWindow(window);
	glfwTerminate();
	P3E::Logger::Info("FREE RESOURCES SUCCESS !!", P3E::KLoggerOwner::Program);

	P3E::Logger::Info("SHUTDOWN STAGE", P3E::KLoggerOwner::Program);
	P3E::Logger::Info("SHUTDOWN STAGE SUCCESS !!", P3E::KLoggerOwner::Program);

	return 0;
}
