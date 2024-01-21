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

using namespace std;

#define K_PPE_VERSION "0.0.0"

int main(int argc, char* argv[]) {
	std::cout << "Program Performer Engine" << std::endl;
	
	std::cout << "> PPE: INIT" << std::endl;
	if (!glfwInit()) {
		std::cerr << "Could not initialize GLFW!" << std::endl;
		return 1;
	}
	std::cout << "> PPE: GLFW init success" << std::endl;

	GLFWwindow* window = glfwCreateWindow(640, 480, "Learn WebGPU", NULL, NULL);
	if (!window) {
		std::cerr << "Could not open window!" << std::endl;
		glfwTerminate();
		return 1;
	}
	std::cout << "> PPE: GLFW create window success" << std::endl;


	std::cout << "> PPE: UPDATE" << std::endl;
	while (!glfwWindowShouldClose(window)) {
		glfwPollEvents();
	}

	std::cout << "> PPE: FREE MEMORY" << std::endl;
	glfwDestroyWindow(window);
	glfwTerminate();

	std::cout << "> PPE: SHUTDOWN" << std::endl;
	return 0;
}
