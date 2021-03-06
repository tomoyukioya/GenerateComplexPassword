// gcp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <random>
#include <iostream>
#include <string>

	// パスワード長は、３２文字（=128bit）
	// 英大文字、英小文字、数字、記号をすべて含む（0x21-0x7e）

int main()
{
	std::random_device rnd;

	std::string password;
	char ch;
	bool type[4];	// 英大文字、英小文字、数字、記号

	for (int j = 0; j < 10; j++) {
		do {
			password.clear();
			type[0]=type[1]=type[2]=type[3] = false;

			for (int i = 0; i < 32; i++) {
				while ((ch = rnd() & 0x7f) < 0x21 || ch > 0x7e);

				if (0x41 <= ch && ch <= 0x5a) type[0] = true;
				else if (0x61 <= ch && ch <= 0x7a) type[1] = true;
				else if (0x30 <= ch && ch <= 0x39) type[2] = true;
				else type[3] = true;

				password.push_back(ch);
			}
		} while (type[0]==false || type[1]==false || type[2]==false || type[3]==false);

		std::cout << password << std::endl;
		password.clear();
	}

	std::cin.ignore();

    return 0;
}
