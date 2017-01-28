#pragma once
#ifndef _KEYCONSTANTS_H
#define _KEYCONSTANTS_H

#include <map> //c++11 is love, c++11 is life
#include <string>

class KeyPair 
{
	// dont ask me for comments pls
public:
	KeyPair(const std::string &vk = "", const std::string &name = "") : VKName(vk), Name (name) {}

	std::string VKName;
	std::string Name;

};

//stores a map of keys that we get from system

class Keys 
{
public:
	static std::map<int, KeyPair> KEYS;

};

#endif // !_KEYCONSTANTS_H
