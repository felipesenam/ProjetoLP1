
#include "lib.hpp"

/**
 * @brief Colore a saída padrão
 * @details Altera a cor da letra ou do fundo da letra
 * @param color :: String referente à cor desejada, definida em lib.hpp
 * @return Retorna um string vazio
*/
std::string lib::color(const std::string& color)
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
void lib::printTitle(const std::string& title, const std::string& cor)
{
	CLS;
	int spaceExtra = chartcount(title) % 2;
	int spaceOnLeft = (BOXWIDTH - chartcount(title) - spaceExtra) / 2;
	
	std::cout << color(bLIGHT_YELLOW) << std::setfill(' ') << std::setw(BOXWIDTH) << "" << color(bRESET) << std::endl;
	std::cout << color(bLIGHT_YELLOW) << "  " << color(bRESET) 
		<< std::setfill(' ') << std::setw(spaceOnLeft-2) << ""
		<< color(cor) << title << color(fRESET) 
		<< std::setfill(' ') << std::setw(spaceOnLeft-2+spaceExtra) << ""
		<< color(bLIGHT_YELLOW) << "  " << color(bRESET) << std::endl;
	std::cout << color(bLIGHT_YELLOW) << std::setfill(' ') << std::setw(BOXWIDTH) << "" << color(bRESET) << std::endl;
	NEWLINE;
}	

/**
 * @brief Imprime o cabeçalho de um menu
 * @details Limpa a tela e imprime no topo da tela, um cabeçalho de menu com subtitulo
 * @param title :: Título do menu
 * @param subtitle :: Subtítulo do menu
 * @param cor :: Cor do título do menu
*/
void lib::printMenu(const std::string& title, const std::string& subtitle, const std::string& cor)
{
	CLS;
	int spaceExtra = chartcount(title) % 2;
	int spaceOnLeft = (BOXWIDTH - chartcount(title) - spaceExtra) / 2;
	
	std::cout << color(bLIGHT_YELLOW) << std::setfill(' ') << std::setw(BOXWIDTH) << "" << color(bRESET) << std::endl;
	std::cout << color(bLIGHT_YELLOW) << "  " << color(bRESET) 
		<< std::setfill(' ') << std::setw(spaceOnLeft-2) << ""
		<< color(cor) << title << color(fRESET) 
		<< std::setfill(' ') << std::setw(spaceOnLeft-2+spaceExtra) << ""
		<< color(bLIGHT_YELLOW) << "  " << color(bRESET) << std::endl;

	spaceOnLeft = (BOXWIDTH - chartcount(subtitle)) / 2;
	spaceExtra = chartcount(subtitle) % 2;
	std::cout << color(bLIGHT_YELLOW) << "  " << color(bRESET) 
		<< std::setfill(' ') << std::setw(spaceOnLeft-2) << ""
		<< subtitle 
		<< std::setfill(' ') << std::setw(spaceOnLeft-2+spaceExtra) << ""
		<< color(bLIGHT_YELLOW) << "  " << color(bRESET) << std::endl;
	std::cout << color(bLIGHT_YELLOW) << std::setfill(' ') << std::setw(BOXWIDTH) << "" << color(bRESET) << std::endl;
	NEWLINE;
}

/**
 * @brief Limpa o buffer de entrada
 * @details A função coleta toda a informação armazenada no buffer de entrada até encontrar uma quebra de linha
*/
void lib::ffBuffer()
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
bool lib::isany(const char letter, const std::string& vect)
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

bool lib::isany(const std::string& word, const std::string& vect)
{
	for(const auto& wl : word)
	{
		for(const auto& vl : vect)
		{
			if(wl == vl)
			{
				return true;
			}
		}
	}
	return false;
}

size_t lib::chartcount(const std::string& string)
{
	size_t count = string.length();
	for(unsigned char cc : string)
	{
		if(cc == 195 || cc == 194)
		{
			count -= 1;
		}
	}
	return count;
}

std::string lib::stolower(const std::string& word)
{
	std::stringstream ss;

	for(auto c : word)
	{
		ss << (unsigned char)tolower(c);
	}

	return ss.str();
}