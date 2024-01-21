#ifndef CONTROLLERCONFIG_H
#define CONTROLLERCONFIG_H

#define K_CONTROLLERCONFIG_FOLDER_PATH "configs/"
#define K_CONTROLLERCONFIG_FILENAME "controller"

class InputContext {
public:
	InputContext();
};

class ControllerConfig {
public:
	ControllerConfig();
	~ControllerConfig();
public:
	void ResetToDefault();
	void SaveXML();
	void LoadXML();
};

ControllerConfig::ControllerConfig() {
	
}

#endif // !CONTROLLERCONFIG_H
