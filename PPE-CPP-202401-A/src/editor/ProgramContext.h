#ifndef PROGRAMCONTEXT_H
#define PROGRAMCONTEXT_H

class ProgramContext {
public:
	ProgramContext(){ }
	~ProgramContext(){}
private:
	//GameProgramContext
	//AudioProgramContext
public:
	void Init();
	void Start();
	void Update(float arg_dt, float arg_unscaledDT);
};

#endif // !PROGRAMCONTEXT_H
