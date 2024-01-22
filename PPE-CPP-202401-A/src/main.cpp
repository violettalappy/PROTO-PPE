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
#include <PPE/PPE_min.h>

using namespace std;

int main(int argc, char* argv[]) {
	PPE::Log("PPE", "Program Performer Engine starts");
	PPE::LogInfo();
	
	PPE::Log("PPE", "init phase");
	PPE_ProgramConfig programConfig = PPE_ProgramConfig();
	if (!glfwInit()) {
		std::cerr << "Could not initialize GLFW!" << std::endl;
		return 1;
	}
	PPE::Log("GLFW", "init success");
	GLFWwindow* window = glfwCreateWindow(programConfig.GetScreenWidth(), programConfig.GetScreenHeight(), programConfig.GetProgramTitle().c_str(), NULL, NULL);
	if (!window) {
		std::cerr << "Could not open window!" << std::endl;
		glfwTerminate();
		return 1;
	}
	PPE::Log("GLFW", "create window success");

	PPE::Log("PPE", "update phase");
	while (!glfwWindowShouldClose(window)) {
		glfwPollEvents();
	}

	PPE::Log("PPE", "termination phase");
	glfwDestroyWindow(window);
	glfwTerminate();
	PPE::Log("PPE", "terminate success");

	PPE::Log("PPE", "shutdown phase");
	PPE::Log("PPE", "shutdown success");

	return 0;
}
