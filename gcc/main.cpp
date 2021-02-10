#include "ShadowCore.h"
#include "version.h"

#ifdef _WIN32

#include <Windows.h>

#endif

#include <iostream>
#include <string>
#include <ctime>
#include <stdlib.h>

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


/* Randomizers */
/* Can be used within ShadowBrowser or by the JavaScript end */

EXPORT int RandomNumber(int seed) {
	
	if (seed == -1) {
		return rand();
	} else {
		srand(seed);
		return rand();
	}
}

/* Utils */

EXPORT char* StringToCharArr(std::string inputString) {
	int stringlength = inputString.length();
	char stringArr[stringlength + 1];
	return strcpy(stringArr, inputString.c_str());
}