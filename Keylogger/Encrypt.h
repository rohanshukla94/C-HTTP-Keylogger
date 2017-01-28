#pragma once
#ifndef _ENCRYPT_H_
#define _ENCRYPT_H_
// song used https://www.youtube.com/watch?v=hSnmuY1d2Ks
#include <vector>
#include <string>

namespace Base64 // its not plain base64 i promise
{
	std::string base64_encode(const std::string &);

	const std::string &SALT1 = "LM::TB::BB";
	const std::string &SALT2 = " _:/_77";
	const std::string &SALT3 = "line=NTTITON=ISKOOL";

	std::string Encrypt(std::string s);


	const std::string &BASE64_CODES = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";


	std::string base64_encode(const std::string &s);
 

}



#endif // !_ENCRYPT_H_
