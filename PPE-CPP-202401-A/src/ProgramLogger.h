#ifndef PROGRAMLOGGER
#define PROGRAMLOGGER

#include <iostream>
#include <string>

#define K_PROGRAMLOGGER_FILENAME "log.txt"

class ProgramLogger {
public:
	static void Log(std::string arg_msg) {
		std::cout << "> PPE: " << arg_msg << std::endl;
	}
};

#endif // !PROGRAMLOGGER
