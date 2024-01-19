#ifndef PROGRAMGUI_H
#define PROGRAMGUI_H

class ProgramGUI {
public:
	ProgramGUI();
	~ProgramGUI();
public:
	void Init();
	void Start();
	void Update(float arg_dt, float arg_unscaledDT);
};

#endif // !PROGRAMGUI_H
