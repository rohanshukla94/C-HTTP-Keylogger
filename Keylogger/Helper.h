#pragma once
#ifndef _HELPER_H_
#define _HELPER_H_

// song used https://www.youtube.com/watch?v=1mjlM_RnsVE
#include <ctime>
#include <string>
#include <sstream>

#include <fstream>

namespace Helper
{
	template  <class T> 

	std::string toString(const T &); 

	struct DateTime
	{
		DateTime()
		{
			time_t ms;
			time(&ms);

			struct tm *info = localtime(&ms);

			D = info->tm_mday;
			m = info->tm_mon + 1;
			y = 1900 + info->tm_year;
			M = info->tm_min;
			H = info->tm_hour;
			S = info->tm_sec;
		}
		DateTime(int D, int m, int y, int H, int M, int S) : D(D), m(m), y(y), H(H), M(M), S(S) {}
	    DateTime(int D, int m, int y) : D(D), m(m), y(y), H(0), M(0), S(0) {}

		DateTime Now() const
		{
			return DateTime();
		}
		int D, m, y, H, M, S;

		std::string GetDateString() const
		{
			return std::string(D < 10 ? "0" : "") + toString(D) +
				std::string(m < 10 ? ".0" : ".") + toString(m) + "." +
				toString(y);
			//return time like DD.MM.YYYY
		}


		std::string GetTimeString(const std::string &sep = ":") const
		{
			return std::string(H < 10 ? "0" : "") + toString(H) + sep +
				std::string(M < 10 ? "0" : "") + toString(M) + sep +
				std::string(S < 10 ? sep : "") + toString(S);
			//return this HH:MM:SS
		}
		std::string GetDateTimeString(const std::string &sep = ":") const
		{
			return GetDateString() + " " + GetTimeString(sep);
		}

	
	};

	template <class T>

	std::string toString(const T &e)
	{
		std::ostringstream s;
		s << e;

		return s.str();
	}

	void DetectErrorLog(const std::string &s)
	{
		std::ofstream file("AppLog.txt", std::ios::app);
		file << "[" << Helper::DateTime().GetDateTimeString() << "]" <<
			"\n" << s << std::endl << '\n';
		file.close();
	}
		

}

#endif // !_HELPER_H
