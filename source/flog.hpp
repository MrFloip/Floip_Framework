#ifndef FLOG
#define FLOG

#include <string>
#include <iostream>
#include <fstream>
#include <Windows.h>
#include "log_structs.hpp"
#include "f_exception.hpp"
#include "time.hpp"
using namespace std;

namespace ft
{

class Flog
{
private:
	Time time;
	Console console;
	bool logTime;
	int logMode;
	string logFile;
	ofstream* file;
	//-----singleton-implementation-------
	Flog();
public:
	~Flog()
	{
		file->close();
	}
	static Flog& getInstance();
	//-----end of singleton implementation----

	int getLogMode(){return logMode;}
	ofstream* getFileStream(){return file;}
	string getLogFile(){return logFile;}
	Console getConsole(){return console;}
	bool getLogTime(){return logTime;}
	Time getTime(){return time;}

	void setLogMode(int _logMode){logMode = _logMode;}
	void setColor(WORD _logColor){console.color = _logColor;}
	void setLogTime(bool _logTime){logTime = _logTime;}	
	void changeLogFile(string _logFile){logFile = _logFile;}
	void openLog(bool append=false);
	void closeLog();

	friend Flog& operator<<(Flog& fl, string msg);
	friend Flog& operator<<(Flog& fl, int msg);
	friend Flog& operator<<(Flog& fl, char* msg);
	
};

}

#endif