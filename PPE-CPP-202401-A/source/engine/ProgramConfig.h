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
	void SetProgramTitle(char arg_title[]);
	void SetScreenSize(KScreenSize arg_screenSize);
	void SetRefreshRate(KRefreshRate arg_refreshRate);
};

ProgramConfig::ProgramConfig() {
}

ProgramConfig::~ProgramConfig() {
}

#endif // !PROGRAMCONFIG_H
