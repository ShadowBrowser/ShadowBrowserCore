#include "ShadowCore.h"
#include "version.h"

#ifdef _WIN32

#include <Windows.h>

#endif

#include <iostream>
#include <string>
#include <ctime>

EXPORT void print(std::string text) {
	std::cout << text;
}
EXPORT void println(std::string text) {
	std::cout << text << std::endl;
}

EXPORT void printa(char text[]) {
	std::cout << text;
}
EXPORT void printlna(char text[]) {
	std::cout << text << std::endl;
}

EXPORT int getSysMemoryUsage() {
#ifdef _WIN32
	MEMORYSTATUSEX statex;
	statex.dwLength = sizeof(statex);
	GlobalMemoryStatusEx(&statex);

	return statex.dwMemoryLoad;
#endif
#ifdef linux
	return 0;
#endif
}

time_t now = time(0);
char* dt = ctime(&now);

EXPORT void aboutCore() {
	print("ShadowCore Version "); println(CORE_VERSION);
	print("Time of Run: "); println(dt);
	print("Time of Compile: "); print(__DATE__); print(" "); println(__TIME__);
}

EXPORT std::string coreVersion() {
	return CORE_VERSION;
}
