#ifndef _TIME_H_
#define _TIME_H_
#include <ctime>
#include <string>

using std::string;

namespace ft
{
class Time
{
private:
	time_t now;
	tm localTime;
public:

	Time(){}
	string tell()
	{
		now = time(0);
		localtime_s(&localTime,&now);
		string tempStr = asctime(&localTime);
		//asctime_s(tempStr,&localTime);

		tempStr.erase(tempStr.end()-1);
		tempStr.append(" | ");
		return tempStr;
	}

};

}


#endif