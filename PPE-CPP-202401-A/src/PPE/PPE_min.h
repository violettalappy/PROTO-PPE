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

/*
This file is the actual representation of using PPE in project
Add all functions before using PPE.h
*/

#ifndef PPE_H
#define PPE_H

#include <iostream>
#include <string>

class PPE {
public:

	/* LOGGER */
	// ? Loging all program behaviors
	// ! DO NOT LOG IN UPDATE EVERY FRAME
	// TODO Design fallback system in case unable to write to log file

	static void Log(std::string arg_title, std::string arg_msg, bool isIncludeTime = true) {
		std::cout << "> LOG: " << arg_title << ": " << arg_msg << std::endl;
	}
	static void Warn(std::string arg_title, std::string arg_msg, bool isIncludeTime = true) {
		std::cout << "> WARNING: " << arg_title << ": " << arg_msg << std::endl;
	}
	static void Fatal(std::string arg_title, std::string arg_msg, bool isIncludeTime = true) {
		std::cout << "> FATAL: " << arg_title << ": " << arg_msg << std::endl;
	}
};

#endif // !PPE_H
