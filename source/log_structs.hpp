#ifndef CONSOLE_H_
#define CONSOLE_H_
#include <Windows.h>

namespace ft
{
struct Console
{
	WORD color;
	HANDLE hStdout;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
};

struct LogMode
{
	static const int CONSOLE = 1;
	static const int LOGFILE = 2;
	static const int CON_LOG = 3;
};

struct LogColor
{
	static const WORD INTENSITY = 0x08;
	static const WORD WHITE = 0x0F; 
	static const WORD BLACK = 0x00;
	static const WORD RED = 0x04; 
	static const WORD BLUE = 0x01;
	static const WORD GREEN = 0x02;
};


}


#endif