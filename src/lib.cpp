
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

void printTitle(std::string title, int largura, std::string cor)
{
	CLS;
	int spaceOnLeft = (largura-title.length())/2;
	int spaceExtra = title.length()%2;
	std::cout << std::setfill('*') << std::setw(largura) << ""<< std::endl;
	std::cout << "**" 
		<< std::setfill(' ') << std::setw(spaceOnLeft-2) << ""
		<< Color(cor) << title << Color(fRESET) 
		<< std::setfill(' ') << std::setw(spaceOnLeft-2+spaceExtra) << ""
		<< "**" << std::endl;
	std::cout << std::setfill('*') << std::setw(largura) << "" << std::endl;
}

void printMenu()
{
	CLS;
	std::string title="Pet Fera";
	int spaceOnLeft = (60-title.length())/2;
	int spaceExtra = title.length()%2;
	std::cout << std::setfill('*') << std::setw(60) << ""<< std::endl;
	std::cout << "**" 
		<< std::setfill(' ') << std::setw(spaceOnLeft-2) << ""
		<< Color(fGREEN) << "Pet Fera" << Color(fRESET) 
		<< std::setfill(' ') << std::setw(spaceOnLeft-2+spaceExtra) << ""
		<< "**" << std::endl;
	title="Menu Principal";
	spaceOnLeft = (60-title.length())/2;
	spaceExtra = title.length()%2;
	std::cout << "**" 
		<< std::setfill(' ') << std::setw(spaceOnLeft-2) << ""
		<< "Menu Principal" 
		<< std::setfill(' ') << std::setw(spaceOnLeft-2+spaceExtra) << ""
		<< "**" << std::endl;
	std::cout << std::setfill('*') << std::setw(60) << "" << std::endl;
}