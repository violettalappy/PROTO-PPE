#ifndef GAMEPROGRAMOBJECT_H
#define GAMEPROGRAMOBJECT_H

class GameProgramObject {
public:
	GameProgramObject();
	~GameProgramObject();
public:
	void Init();
	void Start();
	void Update(float arg_dt, float arg_unscaledDT);
public:
	void SetSpawnManager();
	void GetSpawnManager();
};

#endif // !GAMEPROGRAMOBJECT_H
