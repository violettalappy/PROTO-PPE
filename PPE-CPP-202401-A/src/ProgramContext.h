#ifndef PROGRAMCONTEXT_H
#define PROGRAMCONTEXT_H

class ProgramContext {
public:
	ProgramContext(){ }
	~ProgramContext(){}
public:
	/* ENGINE DEVELOPMENT */
	// For engine use only
	void Run();
	
	/* COMMON DEVELOPMENT */
	// Place all your development here, useful for game development and other things
	void Init();
	void Start();
	void Update(float arg_dt, float arg_unscaledDT);
	void Render();

	/* AUDIO DEVELOPMENT */
	void PrepareToPlay(double arg_sampleRate, int arg_samplesPerBlock);
	void ReleaseResources();
	void ProcessBlock(double arg_bufferSamples, float arg_midiMSG);
};

#endif // !PROGRAMCONTEXT_H
