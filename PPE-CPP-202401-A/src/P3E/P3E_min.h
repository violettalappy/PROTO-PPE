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
C++20
*/

/*
Learning Resources in case something wrong in compiler or C++ hate me
https://stackoverflow.com/questions/1563897/how-can-you-define-a-static-data-member-of-type-const-stdstring
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
    const std::string K_VERSIONNAME = "P3E_0.0.0";
    const std::string K_PLATFORM = "Win64";
    //TODO Remember to fix file paths
    const std::string K_LOGGER_FILEPATH = "\\log.txt";
    const std::string K_ERRORREPORT_FILEPATH = "\\error.txt";
    const std::string K_PROGRAMCONFIG_FILEPATH = "\\configs\\config.xml";
    const std::string K_CONTROLLERCONFIG_FILEPATH = "\\configs\\controller.xml";
#elif defined(__linux__)
    const std::string K_VERSIONNAME = "P3E_0.0.0-Linux";
    const std::string K_PLATFORM = "Linux";
    //TODO Remember to fix file paths
    const std::string K_LOGGER_FILEPATH = "\\log.txt";
    const std::string K_ERRORREPORT_FILEPATH = "\\error.txt";
    const std::string K_PROGRAMCONFIG_FILEPATH = "\\configs\\config.xml";
    const std::string K_CONTROLLERCONFIG_FILEPATH = "\\configs\\controller.xml";
#endif

    class KLoggerOwner {
    public:
        inline static const std::string Program = "Program";
        inline static const std::string GLFW = "GLFW";
        inline static const std::string P3E = "P3E";
        inline static const std::string P3E_ProgramConfig = "P3E_ProgramConfig";
        inline static const std::string P3E_ControllerConfig = "P3E_ControllerConfig";
        //inline static const std::string AudioProgram = "AudioProgram";
        //inline static const std::string GameProgram = "GameProgram";
        //inline static const std::string P3E_GUI = "P3E_GUI";
        //inline static const std::string P3E_SaveData = "P3E_SaveData";
        // Add your custom tag below here
    };

    /* LOGGER */
    // ? Log messages to console and txt
    // Use KLoggerOwner for asigning owners
    // Severity Order: log > info > warn > fatal > error
    // TODO Add filters when needed
    // ! DO NOT LOG IN UPDATE EVERY FRAME
    // TODO Design fallback system in case not allow to access log file
    // TODO Design fallback system in case unable to access/ write to log file
    // TODO Use printf
    class Logger {
    public:
        bool IsIncludeTimeStamp() {
            return false;
        }
        bool CanLogToFile() {
            return false;
        }
    public:
        static void None(std::string arg_msg, std::string arg_owner = "") {
            if (arg_owner.empty()) {
                std::cout << arg_msg << std::endl;
            }
            else {
                std::cout << arg_owner << ": " << arg_msg << std::endl;
            }
        }
        static void Log(std::string arg_msg, std::string arg_owner = "") {
            if (arg_owner.empty()) {
                std::cout << "> " << arg_msg << std::endl;
            }
            else {
                std::cout << "> " << arg_owner << ": " << arg_msg << std::endl;
            }
        }
        static void Info(std::string arg_msg, std::string arg_owner = "") {
            if (arg_owner.empty()) {
                std::cout << "> INFO: " << arg_msg << std::endl;
            }
            else {
                std::cout << "> INFO: " << arg_owner << ": " << arg_msg << std::endl;
            }
        }
        static void Warn(std::string arg_msg, std::string arg_owner = "") {
            if (arg_owner.empty()) {
                std::cout << "> WARN: " << arg_msg << std::endl;
            }
            else {
                std::cout << "> WARN: " << arg_owner << ": " << arg_msg << std::endl;
            }
        }
        static void Fatal(std::string arg_msg, std::string arg_owner = "") {
            if (arg_owner.empty()) {
                std::cout << "> FATAL: " << arg_msg << std::endl;
            }
            else {
                std::cout << "> FATAL: " << arg_owner << ": " << arg_msg << std::endl;
            }
        }
        static void Error(std::string arg_msg, std::string arg_owner = "") {
            if (arg_owner.empty()) {
                std::cout << "> ERROR: " << arg_msg << std::endl;
            }
            else {
                std::cout << "> ERROR: " << arg_owner << ": " << arg_msg << std::endl;
            }
        }
    };

    // ? Initialize P3E system header
    // Loging basic information of program
    static void P3E_Init() {
        //Log(P3E_NAMEOF(P3E), "Welcome to P3E program development !!");
        Logger::None("===============================================================");
        Logger::None("Welcome to P3E program development !!");
        Logger::None("P3E - Priority Performer Program Engine");
        Logger::None("By P3E FOUNDATION & VIOLETTALAPPY");
        Logger::None("Licensed under Apache2.");
        Logger::None("Remember to read License Agreement for P3E.");
        Logger::None("===============================================================");
        Logger::Info("It will shortly start now !!", KLoggerOwner::P3E);
        Logger::Info("information will be listed below: ", KLoggerOwner::P3E);
        std::string versionMSG = "Version = " + K_VERSIONNAME;
        Logger::Info(versionMSG, KLoggerOwner::P3E);
        std::string platformMSG = "Platform = " + K_PLATFORM;
        Logger::Info(platformMSG, KLoggerOwner::P3E);
        std::string loggerFilePath = "LoggerFilePath = " + H_FS::current_path().string() + K_LOGGER_FILEPATH;
        Logger::Info(loggerFilePath, KLoggerOwner::P3E);
        std::string errorReportFilePath = "ErrorReportFilePath = " + H_FS::current_path().string() + K_ERRORREPORT_FILEPATH;
        Logger::Info(errorReportFilePath, KLoggerOwner::P3E);
        std::string pcfbMSG = "ProgramConfigFilePath = " + H_FS::current_path().string() + K_PROGRAMCONFIG_FILEPATH;
        Logger::Info(pcfbMSG, KLoggerOwner::P3E);
        std::string ccMSG = "ControllerConfigFilePath = " + H_FS::current_path().string() + K_CONTROLLERCONFIG_FILEPATH;
        Logger::Info(ccMSG, KLoggerOwner::P3E);
        Logger::Info("init success !!", KLoggerOwner::P3E);
    }

    class Math {
    public:
        const float K_PI = 3.14159265358979323846f;
        const float K_EPSILON = 0.000001f;
        const float K_DEG2RAD = K_PI / 180.0f;
        const float K_RAD2DEG = 180.0f / K_PI;
    public:
        static float ToMPH(float arg_kmh) {
            float result = 0.0f;
            return result;
        }
        static float ToKMH(float arg_mph) {
            float result = 0.0f;
            return result;
        }
        static float Clamp(float arg_value, float arg_min, float arg_max) {
            float result = (arg_value < arg_min) ? arg_min : arg_value;
            if (result > arg_max) {
                result = arg_max;
            }
            return result;
        }
        static float Lerp(float arg_start, float arg_end, float arg_amount) {
            float result = arg_start + arg_amount * (arg_end - arg_start);
            return result;
        }
        // TODO Remember to add logic that normalize input value to 0 or 1
        static float Normalize01(float arg_value) {
            float result = 0;
            return result;
        }
        static float Normalize(float arg_value, float arg_start, float arg_end) {
            float result = (arg_value - arg_start) / (arg_end - arg_start);
            return result;
        }
    };

    /* PROGRAMCONFIG */
    // ? Customize how program work
    class ProgramConfig {
    public:
        ProgramConfig() {
        }
        ~ProgramConfig() {
        }
        void Init() {
            Logger::Info("init", KLoggerOwner::P3E_ProgramConfig);
            bool isLoadConfigSuccess = false;
            if (isLoadConfigSuccess) {
                // Log all specs from programconfig at the end
                LogProgramConfigInfo();
            }
            else {
                Logger::Fatal("load config fail, emergency fallback measure !!", KLoggerOwner::P3E_ProgramConfig);
                ResetToDefault();
                // Log all specs from programconfig at the end
                LogProgramConfigInfo();
            }
        }
        void ResetToDefault() {
            Logger::Info("reset to default settings !!", KLoggerOwner::P3E_ProgramConfig);
            SetProgramTitle("LearnWebGPU");
            SetProgramVersion("0.0.0");
            SetScreenWidth(800);
            SetScreenHeight(600);
        }
        void LogProgramConfigInfo() {
            Logger::Info("information will be listed below: ", KLoggerOwner::P3E_ProgramConfig);
            std::string programFullTitle = "ProgramFullTitle = " + GetProgramFullTitle();
            Logger::Info(programFullTitle, KLoggerOwner::P3E_ProgramConfig);
            std::string programTitle = "ProgramTitle = " + GetProgramTitle();
            Logger::Info(programTitle, KLoggerOwner::P3E_ProgramConfig);
            std::string programVersion = "ProgramVersion = " + GetProgramVersion();
            Logger::Info(programVersion, KLoggerOwner::P3E_ProgramConfig);
            std::string screenWidth = "ScreenWidth = " + std::to_string(GetScreenWidth());
            Logger::Info(screenWidth, KLoggerOwner::P3E_ProgramConfig);
            std::string screenHeight = "ScreenHeight = " + std::to_string(GetScreenHeight());
            Logger::Info(screenHeight, KLoggerOwner::P3E_ProgramConfig);
        }
    private:
        std::string _programFullTitle = "";
        std::string _programTitle = "Insert program name here !!";
        //NOTE: major.minor.patch
        std::string _programVersion = "0.0.0";
        int _screenWidth = 800;
        int _screenHeight = 600;
    public:
        void Save() {
            if (true) {
                Logger::Info("save success in PROGRAMCONFIG_PATHFILE", KLoggerOwner::P3E_ProgramConfig);
            }
            else {
                Logger::Fatal("save failed !!", KLoggerOwner::P3E_ProgramConfig);
            }
        }
        void Load() {
            if (true) {
                Logger::Info("load success from PROGRAMCONFIG_PATHFILE", KLoggerOwner::P3E_ProgramConfig);
            }
            else {
                Logger::Fatal("load failed !!", KLoggerOwner::P3E_ProgramConfig);
            }
        }
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

    /* ControllerConfig */
    // ? Customize how program work
    class ControllerConfig {
    public:
        ControllerConfig() {
        }
        ~ControllerConfig() {
        }
        void Init() {
            Logger::Info("init", KLoggerOwner::P3E_ControllerConfig);
        }
        void ResetToDefault() {
            Logger::Info("reset to default settings !!", KLoggerOwner::P3E_ControllerConfig);
        }
        void LogInfo() {
            Logger::Info("information will be listed below: ", KLoggerOwner::P3E_ControllerConfig);
        }
    };

    /* P3E EXCEPTION */
    // Only applied to fatal and error reports
    // Save detailed reports to error.txt
    class KErrorCode {
    public:
    public:
        inline static const int GLFW_InitFailed() {
            Logger::Error("init failed !!", KLoggerOwner::GLFW);
            return -1;
        };
        inline static const int GLFW_CreateWindowFailed() {
            Logger::Error("create window failed !!", KLoggerOwner::GLFW);
            return -1;
        };
        int GLEW_InitFailed = -1;
        inline static const int P3E_ProgramConfigNotFound() {
            Logger::Error("ProgramConfig file path not found !!", KLoggerOwner::P3E_ProgramConfig);
            return -1;
        };
        int P3E_ProgramConfigSaveFailed = -1;
        int P3E_ProgramConfigLoadFailed = -1;
        int P3E_ControllerConfigNotFound = -1;
        int P3E_ControllerConfigSaveFailed = -1;
        int P3E_ControllerConfigLoadFailed = -1;
    };

    /* VALUE RANGE */
    // Define most problem
    // TODO Check for system min value
    class ProgramValueRange {
        ProgramValueRange(float arg_value, float arg_defaultValue, float arg_min, float arg_max, float arg_systemMin = FLT_MIN, float arg_systemMax = FLT_MAX) {
            value = arg_value;
            defaultValue = arg_defaultValue;
            min = arg_min;
            max = arg_max;
            systemMin = arg_systemMin;
            systemMax = arg_systemMax;
        }
    public:
        float value = 0;
        float defaultValue = 0;
        float min = 0;
        float max = 0;
        float systemMin = FLT_MIN;
        float systemMax = FLT_MAX;
    public:
        void SetValue() {
        }
        void SetDefaultValue() {
        }
        void SetMin() {
        }
        void SetMax() {
        }
        void SetSystemMin() {
        }
        void SetSystemMax() {
        }
    };

    // Include percentage modifier
    class GameValueRange {
        GameValueRange(float arg_value, float arg_defaultValue, float arg_min, float arg_max, float arg_systemMin = FLT_MIN, float arg_systemMax = FLT_MAX) {
            _value = arg_value;
            _defaultValue = arg_defaultValue;
            _valueMin = arg_min;
            _valueMax = arg_max;
            _systemMin = arg_systemMin;
            _systemMax = arg_systemMax;
        }
    private:
        float _value = 0.0f;
        float _defaultValue = 0.0f;
        float _valueMin = 0.0f;
        float _valueMax = 0.0f;
        float _systemMin = FLT_MIN;
        float _systemMax = FLT_MAX;
    public:
        float GetValue() {
            return _value;
        }
        float GetDefaultValue() {
            return _defaultValue;
        }
        float GetValueMin() {
            return _valueMin;
        }
        float GetValueMax() {
            return _valueMax;
        }
        float GetSystemMin() {
            return _systemMin;
        }
        float GetSystemMax() {
            return _systemMax;
        }
        void SetValue(float arg_value) {
            _value = arg_value;
        }
        void SetDefaultValue(float arg_value) {
            _defaultValue = arg_value;
        }
        void SetValueMin(float arg_value) {
            _valueMin = arg_value;
        }
        void SetValueMax(float arg_value) {
            _valueMax = arg_value;
        }
        void SetRestraintMin() {
        }
        void SetRestraintMax() {
        }
        void SetLimitMin() {
        }
        void SetLimitMax() {
        }
        void SetSystemMin() {
        }
        void SetSystemMax() {
        }
    };
}

#endif // !P3E_H
