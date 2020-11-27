
#include "lib.hpp"

/**
 * @brief Colore a saída padrão
 * @details Altera a cor da letra ou do fundo da letra
 * @param color :: String referente à cor desejada, definida em lib.hpp
 * @return Retorna um string vazio
*/
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

/**
 * @brief Imprime o cabeçalho de um menu sme subtítulo
 * @details Limpa a tela e imprime no topo da tela, um cabeçalho de menu
 * @param title :: Título do menu
 * @param cor :: Cor do título do menu
*/
void printTitle(std::string title, std::string cor)
{
	CLS;
	int spaceExtra = title.length() % 2;
	int spaceOnLeft = (BOXWIDTH - title.length() - spaceExtra) / 2;
	
	std::cout << Color(bLIGHT_YELLOW) << std::setfill(' ') << std::setw(BOXWIDTH) << "" << Color(bRESET) << std::endl;
	std::cout << Color(bLIGHT_YELLOW) << "  " << Color(bRESET) 
		<< std::setfill(' ') << std::setw(spaceOnLeft-2) << ""
		<< Color(cor) << title << Color(fRESET) 
		<< std::setfill(' ') << std::setw(spaceOnLeft-2+spaceExtra) << ""
		<< Color(bLIGHT_YELLOW) << "  " << Color(bRESET) << std::endl;
	std::cout << Color(bLIGHT_YELLOW) << std::setfill(' ') << std::setw(BOXWIDTH) << "" << Color(bRESET) << std::endl;
	NEWLINE;
}	

/**
 * @brief Imprime o cabeçalho de um menu
 * @details Limpa a tela e imprime no topo da tela, um cabeçalho de menu com subtitulo
 * @param title :: Título do menu
 * @param subtitle :: Subtítulo do menu
 * @param cor :: Cor do título do menu
*/
void printMenu(std::string title, std::string subtitle, std::string cor)
{
	CLS;
	int spaceExtra = title.length() % 2;
	int spaceOnLeft = (BOXWIDTH - title.length() - spaceExtra) / 2;
	
	std::cout << Color(bLIGHT_YELLOW) << std::setfill(' ') << std::setw(BOXWIDTH) << "" << Color(bRESET) << std::endl;
	std::cout << Color(bLIGHT_YELLOW) << "  " << Color(bRESET) 
		<< std::setfill(' ') << std::setw(spaceOnLeft-2) << ""
		<< Color(cor) << title << Color(fRESET) 
		<< std::setfill(' ') << std::setw(spaceOnLeft-2+spaceExtra) << ""
		<< Color(bLIGHT_YELLOW) << "  " << Color(bRESET) << std::endl;

	spaceOnLeft = (BOXWIDTH - subtitle.length()) / 2;
	spaceExtra = subtitle.length()%2;
	std::cout << Color(bLIGHT_YELLOW) << "  " << Color(bRESET) 
		<< std::setfill(' ') << std::setw(spaceOnLeft-2) << ""
		<< subtitle 
		<< std::setfill(' ') << std::setw(spaceOnLeft-2+spaceExtra) << ""
		<< Color(bLIGHT_YELLOW) << "  " << Color(bRESET) << std::endl;
	std::cout << Color(bLIGHT_YELLOW) << std::setfill(' ') << std::setw(BOXWIDTH) << "" << Color(bRESET) << std::endl;
	NEWLINE;
}

/**
 * @brief Limpa o buffer de entrada
 * @details A função coleta toda a informação armazenada no buffer de entrada até encontrar uma quebra de linha
*/
void ffBuffer()
{
	int input;
	while ((input = std::cin.get()) != EOF && input != '\n');
}

/**
 * @brief Verifica a presença de algum caractere na palavra passada
 * @param letter :: Caractere a ser localizado
 * @param vect :: Vetor de caracteres a ser lido
 * @return Retorna um valor booleano referente à existência do caractere na palavra
*/
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
