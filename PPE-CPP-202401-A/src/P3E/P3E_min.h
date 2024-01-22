/*
Copyright (c) 2024 ViolettaLappy { hoanglongplanner }

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
Priority Performer Program Engine - P3E
*/

#ifndef P3E_H
#define P3E_H

#include <iostream>
#include <filesystem>
#include <string>
namespace H_FS = std::filesystem;

/* MACRO FUNCTIONALITY */
// ? Convert variable class to string
#define P3E_NAMEOF(name) #name

namespace P3E {
    const int K_VERSION_MAJOR = 0;
    const int K_VERSION_MINOR = 0;
    const int K_VERSION_PATCH = 0;
#ifdef _WIN32
    const std::string K_VERSIONNAME = "P3E_0.0.0-Win64";
    //TODO Remember fixing this path
    const std::string K_PROGRAMCONFIG_FILEPATH = "\configs""\config.xml";
#elif defined(__linux__)
    const std::string K_VERSIONNAME = "P3E_0.0.0-Linux";
    const std::string K_PROGRAMCONFIG_FILEPATH = "\configs""\config.xml";
#endif

    /* API DECLEARATION */
    static void Info(std::string arg_title, std::string arg_msg, bool isIncludeTime = true, bool canLogToFile = true);
    static void Log(std::string arg_title, std::string arg_msg, bool isIncludeTime = true, bool canLogToFile = true);
    static void Warn(std::string arg_title, std::string arg_msg, bool isIncludeTime = true, bool canLogToFile = true);
    static void Fatal(std::string arg_title, std::string arg_msg, bool isIncludeTime = true, bool canLogToFile = true);
    static void Error(std::string arg_title, std::string arg_msg, bool isIncludeTime = true, bool canLogToFile = true);

    // ? Initialize P3E system header
    // Loging basic information of program
    static void Init() {
        Log(P3E_NAMEOF(P3E), "Welcome to P3E program development !!");
        Log(P3E_NAMEOF(P3E), "It will shortly start now !!");
        Log(P3E_NAMEOF(P3E), "  ^ ^ ");
        Log(P3E_NAMEOF(P3E), " (O,O)");
        Log(P3E_NAMEOF(P3E), " (   )  P3E_BY_VIOLETTALAPPY");
        Log(P3E_NAMEOF(P3E), "- v-v --------"";");
        Info(P3E_NAMEOF(P3E), "display P3E specs");
        std::string versionMSG = "Version = " + K_VERSIONNAME;
        Log(P3E_NAMEOF(P3E), versionMSG);
        std::string pcfbMSG = "ProgramConfigFilePath = " + H_FS::current_path().string() + K_PROGRAMCONFIG_FILEPATH;
        Log(P3E_NAMEOF(P3E), pcfbMSG);
        Log(P3E_NAMEOF(P3E), "init phase");
    }

    /* LOGGER */
    // ? Loging all program behaviors
    // ! DO NOT LOG IN UPDATE EVERY FRAME
    // TODO Design fallback system in case not allow to access log file
    // TODO Design fallback system in case unable to access/ write to log file
    // TODO Use printf
    void Info(std::string arg_title, std::string arg_msg, bool isIncludeTime, bool canLogToFile) {
        std::cout << "> INFO: " << arg_title << ": " << arg_msg << std::endl;
    }
    void Log(std::string arg_title, std::string arg_msg, bool isIncludeTime, bool canLogToFile) {
        std::cout << "> " << arg_title << ": " << arg_msg << std::endl;
    }
    void Warn(std::string arg_title, std::string arg_msg, bool isIncludeTime, bool canLogToFile) {
        std::cout << "> WARNING: " << arg_title << ": " << arg_msg << std::endl;
    }
    void Fatal(std::string arg_title, std::string arg_msg, bool isIncludeTime, bool canLogToFile) {
        std::cout << "> FATAL: " << arg_title << ": " << arg_msg << std::endl;
    }
    void Error(std::string arg_title, std::string arg_msg, bool isIncludeTime, bool canLogToFile) {
        std::cout << "> ERROR: " << arg_title << ": " << arg_msg << std::endl;
    }

    /* PROGRAMCONFIG */
    // ? Customize how program work
    class ProgramConfig {
    public:
        ProgramConfig() {
            bool isLoadConfigSuccess = false;
            if (isLoadConfigSuccess) {
                // Log all specs from programconfig at the end
                LogProgramConfigInfo();
            }
            else {
                Fatal(P3E_NAMEOF(ProgramConfig), "load config fail, emergency fallback measure !!");
                ResetToDefault();
                // Log all specs from programconfig at the end
                LogProgramConfigInfo();
            }
        }
        ~ProgramConfig() {
        }
        void ResetToDefault() {
            Info(P3E_NAMEOF(ProgramConfig), "reset to default settings");
            SetProgramTitle("LearnWebGPU");
            SetProgramVersion("0.0.0");
            SetScreenWidth(800);
            SetScreenHeight(600);
        }
        void LogProgramConfigInfo() {
            Info(P3E_NAMEOF(ProgramConfig), "display programconfig specs");
            std::string programFTMSG = "ProgramFullTitle = " + GetProgramFullTitle();
            Log(P3E_NAMEOF(ProgramConfig), programFTMSG);
            std::string programTitleMSG = "ProgramTitle = " + GetProgramTitle();
            Log(P3E_NAMEOF(ProgramConfig), programTitleMSG);
            std::string programVersionMSG = "ProgramVersion = " + GetProgramVersion();
            Log(P3E_NAMEOF(ProgramConfig), programVersionMSG);
            std::string screenWidthMSG = "ScreenWidth = " + std::to_string(GetScreenWidth());
            Log(P3E_NAMEOF(ProgramConfig), screenWidthMSG);
            std::string screenHeightMSG = "ScreenHeight = " + std::to_string(GetScreenHeight());
            Log(P3E_NAMEOF(ProgramConfig), screenHeightMSG);
        }
    private:
        std::string _programFullTitle = "";
        std::string _programTitle = "Insert program name here !!";
        //NOTE: major.minor.patch
        std::string _programVersion = "0.0.0";
        int _screenWidth = 800;
        int _screenHeight = 600;
    public:
        std::string GetProgramFullTitle() {
            return GetProgramTitle() + "-" + GetProgramVersion();
        }
        std::string GetProgramTitle() {
            return _programTitle;
        }
        std::string GetProgramVersion() {
            return _programVersion;
        }
        int GetScreenWidth() {
            return _screenWidth;
        }
        int GetScreenHeight() {
            return _screenHeight;
        }
        void SetProgramFullTitle(std::string arg_name) {
            _programFullTitle = arg_name;
        }
        void SetProgramTitle(std::string arg_name) {
            _programTitle = arg_name;
        }
        void SetProgramVersion(std::string arg_name) {
            _programVersion = arg_name;
        }
        void SetScreenWidth(int arg_value) {
            _screenWidth = arg_value;
        }
        void SetScreenHeight(int arg_value) {
            _screenHeight = arg_value;
        }
    };

    /* P3E EXCEPTION */
    // Only applied to fatal and error reports
    // Save detailed reports to error.txt
    class Exception {
    public:
        bool NoWritePermitToProgramConfig() {
            return true;
        }
        bool NoProgramConfigFile() {
            return true;
        }
        bool UnableToAccessProgramConfig() {
            return true;
        }
        bool LoadProgramConfigFail() {
            return true;
        }
    };
}

#endif // !P3E_H
