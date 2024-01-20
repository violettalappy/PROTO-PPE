/*
This should be used for all audio development
*/

#ifndef AUDIOPROGRAMOBJECT_H
#define AUDIOPROGRAMOBJECT_H

class AudioProgramObject {
public:
	AudioProgramObject();
	~AudioProgramObject();
public:
	void GetInputManager();
	void GetRenderManager();
	void GetQueueManager();
public:
	void Init();
	void ProcessBlock();
};

#endif // !AUDIOPROGRAMOBJECT_H
