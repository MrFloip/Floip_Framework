#include "flog.hpp"
#include <sstream>
#include <Windows.h>

namespace ft
{

Flog* Flog::pInstance = NULL;
Flog::Flog()
{
	bool logTime = false;
	int logMode = LogMode::CONSOLE;
	string logFile = "default.log";
	file = new ofstream;

	console.color = LogColor::WHITE;
	console.hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(console.hStdout,&console.csbi);

}


void Flog::openLog(bool append)
{
	if(!file->is_open())
	{
		if(append)
		{
			file->open(logFile,ios::app);
		}else
		{
			file->open(logFile,ios::beg);
		}

	}
}
void Flog::closeLog()
{
	if(file->is_open())	
		file->close();
}

Flog& operator<<(Flog& fl, string msg)
{
	bool writeTime = false;
	if(fl.getLogMode() == LogMode::CONSOLE || fl.getLogMode() == LogMode::CON_LOG)
	{
		if(msg.at(0) == '%' && msg.at(1) == 't')
		{
			writeTime = true;
			msg.erase(0,2);
			clog << fl.getTime().tell();
		}
		SetConsoleTextAttribute(fl.getConsole().hStdout,fl.getConsole().color);
		clog << msg;
		SetConsoleTextAttribute(fl.getConsole().hStdout,fl.getConsole().csbi.wAttributes);
	}
	if(fl.getLogMode() == LogMode::LOGFILE || fl.getLogMode() == LogMode::CON_LOG)
	{
		if(!fl.getFileStream()->is_open())
		{
			fl.openLog(false);
		}
		if(fl.getFileStream()->good())
		{

			if(writeTime)
			{
				*(fl.getFileStream()) << fl.getTime().tell();
			}

			*(fl.getFileStream()) << msg;
		}
	}

	return fl;
}

Flog& operator<<(Flog& fl, char* msg)
{
	string tempStr = msg;
	return fl << tempStr;
}

Flog& operator<<(Flog& fl, int msg)
{
	stringstream stream;
	stream << msg;
	return fl << stream.str();
}

}