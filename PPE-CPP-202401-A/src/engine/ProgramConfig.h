#ifndef PROGRAMCONFIG_H
#define PROGRAMCONFIG_H

class KScreenSize {
public:
	KScreenSize(int arg_width, int arg_height) {
		_width = arg_width;
		_height = arg_height;
	}
private:
	int _width = 0;
	int _height = 0;
public:
	int GetWidth() {
		return _width;
	}
	int GetHeight() {
		return _height;
	}
	const KScreenSize K_640x480() {
		return KScreenSize(640, 480);
	}
	const KScreenSize K_800x600() {
		return KScreenSize(800, 600);
	}
	const KScreenSize K_1280x720() {
		return KScreenSize(1280, 720);
	}
	const KScreenSize K_1920x1080() {
		return KScreenSize(1920, 1080);
	}
};

class KRefreshRate {
public:
	KRefreshRate(int arg_refreshRate) {
		_refreshRate = arg_refreshRate;
	}
private:
	int _refreshRate = 24;
	//Available refresh rates for usage
	//const int _refreshRates[] = [24, 30, 50, 60, 120];
public:
	int GetValue() {
		return _refreshRate;
	}
	/*int[] GetAvailableList() {
		return _refreshRates;
	}*/
	KRefreshRate K_24() {
		return KRefreshRate(24);
	}
	KRefreshRate K_30() {
		return KRefreshRate(30);
	}
	KRefreshRate K_60() {
		return KRefreshRate(60);
	}
};

class KFPS {
public:
	KFPS(int arg_fps) {
		_fps = arg_fps;
	}
private:
	int _fps = 24;
	//Available refresh rates for usage
	//const int _refreshRates[] = [24, 30, 50, 60, 120, 240];
public:
	int GetValue() {
		return _fps;
	}
	/*int[] GetAvailableList() {
		return _refreshRates;
	}*/
	KFPS K_24() {
		return KFPS(24);
	}
	KFPS K_30() {
		return KFPS(30);
	}
	KFPS K_60() {
		return KFPS(60);
	}
};

#define K_PROGRAMCONFIG_FOLDER_PATH "configs/"
#define K_PROGRAMCONFIG_FILENAME "config.txt"
#define K_PROGRAMCONFIG_FILENAME_TXT "config.txt"
#define K_PROGRAMCONFIG_FILENAME_CSV "config.csv"

class ProgramConfig {
public:
	ProgramConfig();
	~ProgramConfig();
public:
	void Save();
	void Load();
public:
/* 
PROGRAM
For program application
*/
	void SetProgramTitle(char arg_title[]);
/* 
SYSTEM 
For application engine system
*/
	void SetFPS(KFPS arg_fps);
	/* DISPLAY */
	void SetScreenSize(KScreenSize arg_screenSize);
	void SetScreenWidth(int arg_width);
	void SetScreenHeight(int arg_height);
	void SetRefreshRate(KRefreshRate arg_refreshRate);
	void SetRefreshRate(int arg_refreshRate);
};

ProgramConfig::ProgramConfig() {
	bool isLoadConfigSuccess = false;
	if (isLoadConfigSuccess) {
	}
	// !! Switch to fallback emergency state
	// use default settings, unable to load config for many reasons
	else {
		SetProgramTitle("Please rename this application name !!");
		SetScreenSize(KScreenSize::K_800x600());
		//SetScreenWidth(KScreenSize::K_800x600);
		//SetScreenHeight(KScreenSize::K_800x600);
		SetRefreshRate(KRefreshRate::K_60);
		//SetRefreshRate(60);
	}
}

#endif // !PROGRAMCONFIG_H
