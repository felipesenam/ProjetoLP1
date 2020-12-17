#Makefile by Felipe Sena
#Last updated in 14/11/2020 at 15:57

##################### TARGETS ####################
FILE-release=Pet_Fera

COMPILER-release=g++
COMPILATION_FLAGS-release=-O3 -Wall -Wextra -pedantic -Wno-unused-result -std=c++11 -I./include/
LINKER_FLAGS-release=

OBJPATH-release=./objects/Release/
#================================================#
FILE-debug=prog

COMPILER-debug=g++
COMPILATION_FLAGS-debug=-Wall -Wextra -pedantic -g -DDEBUG -DNOCLS -std=c++11 -I./include/
LINKER_FLAGS-debug=

OBJPATH-debug=./objects/Debug/
##################################################

##################### SYSTEM #####################

REMOVE=rm -f   #COMO REMOVER ARQUIVOS
MKDIR=mkdir -p #COMO CRIAR DIRETÓRIOS

##################################################


#	$@	Nome da regra.
#	$<	Nome da primeira dependência
#	$^	Lista de dependências
#	$?	Lista de dependências mais recentes que a regra.
#	$*	Nome do arquivo sem sufixo


.DEFAULT_GOAL:=release
TARGET?=release

HEADERS=$(wildcard ./include/*.hpp)
SOURCE=$(wildcard ./src/*.cpp)

OBJECTS-$(TARGET)=$(subst .cpp,.o, $(subst ./src/,$(OBJPATH-$(TARGET)),$(SOURCE)))

all: release debug
	@ echo "Finished all"

clean: clean-release clean-debug
	@ $(REMOVE) *~

.PHONY: all clean release clean-release debug clean-debug


##################### TARGETS ####################
release:
	@ $(MAKE) --silent TARGET=$@ $(FILE-$@)

clean-release: $(OBJPATH-release)
	@ $(REMOVE) $(OBJPATH-release)*.o $(FILE-release)

debug:
	@ $(MAKE) --silent TARGET=$@ $(FILE-$@)

clean-debug: $(OBJPATH-debug)
	@ $(REMOVE) $(OBJPATH-debug)*.o $(FILE-debug)

$(OBJPATH-$(TARGET)):
	@ $(MKDIR) $(OBJPATH-$(TARGET))

$(FILE-$(TARGET)): $(OBJECTS-$(TARGET))
	@ echo "Linking executable $@"
	@ $(COMPILER-$(TARGET)) $^ $(COMPILATION_FLAGS-$(TARGET)) $(LINKER_FLAGS-$(TARGET)) -o $@
	@ echo "Built target: $(TARGET)"

$(OBJPATH-$(TARGET))main.o: ./src/main.cpp $(HEADERS)
	@ echo "Building object $@"
	@ $(COMPILER-$(TARGET)) $< -c $(COMPILATION_FLAGS-$(TARGET)) -o $@

$(OBJPATH-$(TARGET))%.o: ./src/%.cpp ./include/%.hpp
	@ echo "Building object $@"
	@ $(COMPILER-$(TARGET)) $< -c $(COMPILATION_FLAGS-$(TARGET)) -o $@
