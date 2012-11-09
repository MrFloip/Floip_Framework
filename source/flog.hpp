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
	int logMode;
	string logFile;
	ofstream* file;
	//-----singleton-implementation-------
	static Flog *pInstance;
	Flog();
public:

	static Flog* getInstance()
	{
		if(!pInstance)
		{
			pInstance = new Flog();
		}
		return pInstance;
	}
	//-----end of singleton implementation----

	~Flog()
	{
		delete pInstance;
		if(file->is_open())
			file->close();
	}

	int getLogMode(){return logMode;}
	ofstream* getFileStream(){return file;}
	string getLogFile(){return logFile;}
	Console getConsole(){return console;}
	Time getTime(){return time;}

	void setLogMode(int _logMode){logMode = _logMode;}
	void setColor(WORD _logColor){console.color = _logColor;}
	void changeLogFile(string _logFile){logFile = _logFile;}
	void openLog(bool append=false);
	void closeLog();

	//operator overloading. The main reason for all get functions
	friend Flog& operator<<(Flog& fl, string msg);
	friend Flog& operator<<(Flog& fl, int msg);
	friend Flog& operator<<(Flog& fl, char* msg);
	
	Flog* operator=(Flog* fl)
	{
		pInstance = fl->pInstance;
		return this;
	} 
	
};

}

#endif