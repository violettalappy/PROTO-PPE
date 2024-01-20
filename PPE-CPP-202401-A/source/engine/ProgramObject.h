/*
ProgramObject
The main parent of all objects during application cycle
Should be thought as system operating as the highest priority
It work in main engine core loop of PPE application
*/

#ifndef PROGRAMOBJECT_H
#define PROGRAMOBJECT_H

class ProgramObject {
public:
	ProgramObject();
	~ProgramObject();
public:
	void GetProgramConfig();
	void GetInputManager();
	void GetAudioManager();
	void GetRenderManager();
	void GetQueueManager();
public:
	void Init();
	void Start();
	void Update();
};

#endif // !PROGRAMOBJECT_H
