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
#include <filesystem>
#include <string>
namespace fs = std::filesystem;

// ? Convert variable class to string
#define PPE_NAMEOF(name) #name

#define K_PPE_VERSION "0.0.0-202401-A"

#ifdef _WIN32
#define K_PROGRAMCONFIG_FILEPATH "\config\config.xml"
#elif defined(__linux__)
#define K_PROGRAMCONFIG_FILEPATH "/config/config.xml"
#endif

class PPE {
public:
	static void LogInfo() {
		std::string versionMSG = "Version = " K_PPE_VERSION;
		PPE::Log(PPE_NAMEOF(PPE), versionMSG);
		std::string pcfbMSG = "ProgramConfigPath = " + fs::current_path().string() + K_PROGRAMCONFIG_FILEPATH;
		PPE::Log(PPE_NAMEOF(PPE), pcfbMSG);
	}
public:
	/* LOGGER */
	// ? Loging all program behaviors
	// ! DO NOT LOG IN UPDATE EVERY FRAME
	// TODO Design fallback system in case unable to write to log file
	static void Log(std::string arg_title, std::string arg_msg, bool isIncludeTime = true) {
		std::cout << "> " << arg_title << ": " << arg_msg << std::endl;
	}
	static void Warn(std::string arg_title, std::string arg_msg, bool isIncludeTime = true) {
		std::cout << "> WARNING: " << arg_title << ": " << arg_msg << std::endl;
	}
	static void Fatal(std::string arg_title, std::string arg_msg, bool isIncludeTime = true) {
		std::cout << "> FATAL: " << arg_title << ": " << arg_msg << std::endl;
	}
};

class PPE_ProgramConfig {
public:
	PPE_ProgramConfig() {
		bool isLoadConfigSuccess = false;
		if (isLoadConfigSuccess) {
		}
		else {
			PPE::Fatal("ProgramConfig", "load config fail, switch to fallback default !!");
			SetProgramTitle("LearnWebGPU");
			SetScreenWidth(800);
			SetScreenHeight(600);
			LogProgramConfigInfo();
		}
	}
	~PPE_ProgramConfig() {
	}
	void LogProgramConfigInfo() {
		std::string programTitleMSG = "ProgramTitle = " + GetProgramTitle();
		PPE::Log(PPE_ProgramConfig::nameof(), programTitleMSG);
		std::string screenWidthMSG = "ScreenWidth = " + std::to_string(GetScreenWidth());
		PPE::Log(PPE_ProgramConfig::nameof(), screenWidthMSG);
		std::string screenHeightMSG = "ScreenHeight = " + std::to_string(GetScreenHeight());
		PPE::Log(PPE_ProgramConfig::nameof(), screenHeightMSG);
	}
private:
	std::string _programTitle = "Insert program name here !!";
	int _screenWidth = 800;
	int _screenHeight = 600;
public:
	const std::string nameof() {
		return "ProgramConfig";
	}
	std::string GetProgramTitle() {
		return _programTitle;
	}
	int GetScreenWidth() {
		return _screenWidth;
	}
	int GetScreenHeight() {
		return _screenHeight;
	}
	void SetProgramTitle(std::string arg_name) {
		_programTitle = arg_name;
	}
	void SetScreenWidth(int arg_value) {
		_screenWidth = arg_value;
	}
	void SetScreenHeight(int arg_value) {
		_screenHeight = arg_value;
	}
};

#endif // !PPE_H
