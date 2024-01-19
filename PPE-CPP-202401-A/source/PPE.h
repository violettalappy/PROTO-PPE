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
Program Performer Engine (PPE)
Single header file for most needs
*/

#include <iostream>
#include <string>

// Version Naming Standard as following
// major.minor.patch
// EXAMPLE: 2.0.0, 3.1.12
#define K_PPE_VERSION "0.0.0"
#define K_PPE_VERSION_MAJOR 0
#define K_PPE_VERSION_MINOR 0
#define K_PPE_VERSION_PATCH 0

std::string GetVersionName() {
	return K_PPE_VERSION;
}

/*
MATH
*/
#ifndef PI
#define PI 3.14159265358979323846f
#endif

#ifndef EPSILON
#define EPSILON 0.000001f
#endif

#ifndef DEG2RAD
#define DEG2RAD (PI/180.0f)
#endif

#ifndef RAD2DEG
#define RAD2DEG (180.0f/PI)
#endif

/*
TRANSFORM
*/
struct Vector3 {
	float x;
	float y;
	float z;
};

struct Vector4 {
	float x;
	float y;
	float z;
	float w;
};

float Clamp(float arg_value, float arg_min, float arg_max) {
	float result = (arg_value < arg_min) ? arg_min : arg_value;
	if (result > arg_max) {
		result = arg_max;
	}
	return result;
}

float Lerp(float arg_start, float arg_end, float arg_amount) {
	float result = arg_start + arg_amount * (arg_end - arg_start);
	return result;
}

// TODO Remember to add logic that normalize input value to 0 or 1
float Normalize01(float arg_value) {
	float result = 0;
	return result;
}

float Normalize(float arg_value, float arg_start, float arg_end) {
	float result = (arg_value - arg_start) / (arg_end - arg_start);
	return result;
}

/*
RENDER
*/
#define K_IMAGE_FOLDER_PATH "images/";
void DrawImage() {
}

/*
ANIMATION TIMELINE
*/
void LoadAnimationTimeline() {
}

/*
AUDIO & VIDEO
Playing audio and stuffs
Like FMOD and WWise
*/
#define K_AUDIO_FOLDER_PATH "audios/";
#define K_VIDEO_FOLDER_PATH "videos/";
struct AudioFile {
};
struct AudioStream {
};
struct AudioMixer {
};
struct VideoStream {
};
void PlayAudio(std::string arg_filename) {
	// Check for extension exception MP3, WAV, OGG, OPUS, M4A
}
void PlayVideo(std::string arg_filename) {
	// Check for extension exception MP4, MOV
}

/*
GUI
Builtin GUI system
*/
#define K_GUI_FOLDER_PATH "gui/";
void LoadGUI() {
}

/*
TWEEN
*/
void Tween() {
}

/*
INPUT CONTROLLER
Keyboard, Gamepad, Mouse
*/
#define K_INPUT_FOLDER_PATH "controllerconfig/";
class KMouseButton {
public:
	// Mouse button left
	const int MOUSE_BUTTON_LEFT = 0;
	// Mouse button right
	const int MOUSE_BUTTON_RIGHT = 1;
	// Mouse button middle (pressed wheel)
	const int MOUSE_BUTTON_MIDDLE = 2;
	// Mouse button side (advanced mouse device)
	const int MOUSE_BUTTON_SIDE = 3;
	// Mouse button extra (advanced mouse device)
	const int MOUSE_BUTTON_EXTRA = 4;
	// Mouse button forward (advanced mouse device)
	const int MOUSE_BUTTON_FORWARD = 5;
	// Mouse button back (advanced mouse device)
	const int MOUSE_BUTTON_BACK = 6;
};

/*
SAVEDATA - SAVELOAD
Save like PS2 and stuffs
Default locations is "savedata/"
*/

#define K_SAVEDATA_FOLDER_PATH "savedata/";
class SaveData {
};
void Save(std::string arg_filename) {
}
void Load(std::string arg_filepath) {
}
void ConvertSaveDataToCSV() {
}
void ConvertSaveDataToXML() {
}

/*
GAME STUFFS
Useful utilities for common problems
*/
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

// Also has percentage modifier
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