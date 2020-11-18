
#include "lib.hpp"

std::string Color(std::string color)
{
#ifdef WIN32
	int c = atoi(color.c_str());
	if(c < 16)
	{
		HANDLE hl = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
		GetConsoleScreenBufferInfo(hl, &bufferInfo);
		bufferInfo.wAttributes &= 0x00F0;
		SetConsoleTextAttribute (hl, bufferInfo.wAttributes |= c);
	}
	else
	{
		c %= 16;
		HANDLE hl = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
		GetConsoleScreenBufferInfo(hl, &bufferInfo);
		bufferInfo.wAttributes &= 0x000F;
		SetConsoleTextAttribute (hl, bufferInfo.wAttributes |= (c << 4));
	}
#else
	std::cout << color;
#endif
	return std::string();
}

void printTitle(std::string title, std::string cor)
{
	CLS;
	int spaceOnLeft = (BOXWIDTH-title.length())/2;
	int spaceExtra = title.length()%2;
	std::cout << std::setfill('*') << std::setw(BOXWIDTH) << ""<< std::endl;
	std::cout << "**" 
		<< std::setfill(' ') << std::setw(spaceOnLeft-2) << ""
		<< Color(cor) << title << Color(fRESET) 
		<< std::setfill(' ') << std::setw(spaceOnLeft-2+spaceExtra) << ""
		<< "**" << std::endl;
	std::cout << std::setfill('*') << std::setw(BOXWIDTH) << "" << std::endl;
}

void printMenu(std::string title, std::string subtitle, std::string cor)
{
	CLS;
	int spaceOnLeft = (BOXWIDTH - title.length()) / 2;
	int spaceExtra = title.length()%2;
	std::cout << std::setfill('*') << std::setw(BOXWIDTH) << ""<< std::endl;
	std::cout << "**" 
		<< std::setfill(' ') << std::setw(spaceOnLeft-2) << ""
		<< Color(cor) << title << Color(fRESET) 
		<< std::setfill(' ') << std::setw(spaceOnLeft-2+spaceExtra) << ""
		<< "**" << std::endl;

	spaceOnLeft = (BOXWIDTH - subtitle.length()) / 2;
	spaceExtra = subtitle.length()%2;
	std::cout << "**" 
		<< std::setfill(' ') << std::setw(spaceOnLeft-2) << ""
		<< subtitle 
		<< std::setfill(' ') << std::setw(spaceOnLeft-2+spaceExtra) << ""
		<< "**" << std::endl;
	std::cout << std::setfill('*') << std::setw(BOXWIDTH) << "" << std::endl;
}

void ffBuffer()
{
	int input;
	while ((input = getchar()) != EOF && input != '\n');
}

bool isany(const char letter, std::string vect)
{
	for(auto l : vect)
	{
		if(letter == l)
		{
			return true;
		}
	}
	return false;
}