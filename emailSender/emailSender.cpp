// emailSender.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

class Mail
{
private:
	char sendmailcmd[256];
	FILE *mfp;

public:
	Mail()
	{
		mfp = NULL;
	}
	~Mail()
	{
	}
	int Send(char *sender, char *addr ,char *header, char *body);
};

int Mail::Send(char *sender, char *addr, char *header, char *body)
{
	snprintf(sendmailcmd, 255, "%s %s", sender, addr);

	mfp = popen(sendmailcmd, "w");
	if (mfp == NULL)
	{
		perror("sendmail open error");
		return 0;
	}

	fputs(header, mfp);

	fputs("\n\n", mfp);
	fputs(body, mfp);
	if (pclose(mfp) == -1)
	{
		cout << "send mail error\n" << endl;
		return 1;
	}
	else
		cout << "send mail ok\n" << endl;
	return 1;
}



int _tmain(int argc, _TCHAR* argv[])
{


	return 0;
}

