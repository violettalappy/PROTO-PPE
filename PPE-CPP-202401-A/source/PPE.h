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
#include <string>

// Version Naming Standard as following
// major.minor.patch
// EXAMPLE: 2.0.0, 3.1.12
#define PPE_VERSION "0.0.0"
#define PPE_VERSION_MAJOR 0
#define PPE_VERSION_MINOR 0
#define PPE_VERSION_PATCH 0

std::string GetVersionName() {
	return PPE_VERSION;
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
struct Vec3 {
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

float Normalize(float arg_value, float arg_start, float arg_end) {
	float result = (arg_value - arg_start) / (arg_end - arg_start);
	return result;
}

/*
RENDER
*/
void DrawImage() {
}

/*
AUDIO
Playing audio and stuffs
Like FMOD and WWise
*/
void PlayAudio(char arg_path[]) {
}

/*
GUI
Builtin GUI system
*/
void LoadGUI() {
}

/*
UTILITIES
Useful utilities for common problems
*/
class ProgramValue {
	//value
	//default
	//min
	//max
	//systemMin
	//systemMax
};
class GameValue {
	//value
	//default
	//min
	//max
	//restraintMin
	//restraintMax
	//limitMin
	//limitMax
	//systemMin
	//systemMax
};