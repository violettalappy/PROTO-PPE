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
private:
	float GetTimeManager();
public:
	void Awake();
	void Start();
	void Update(float arg_dt, float arg_unscaledDT);
	void Render();
};

#endif // !PROGRAMOBJECT_H
