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

HEADERS=$(wildcard ./include/*.hpp)
SOURCE=$(wildcard ./src/*.cpp)

OBJECTS-release=$(subst .cpp,.o, $(subst ./src/,$(OBJPATH-release),$(SOURCE)))
OBJECTS-debug=$(subst .cpp,.o, $(subst ./src/,$(OBJPATH-debug),$(SOURCE)))

all: release debug
	@ echo "Finished all"

clean: release_clean debug_clean
	@ $(REMOVE) *~

.PHONY: all clean release release_clean debug_clean debug  


##################### RELEASE ####################
release: $(OBJPATH-release) $(FILE-release)

release_clean: $(OBJPATH-release)
	@ $(REMOVE) $(OBJPATH-release)*.o $(FILE-release)

$(OBJPATH-release):
	@ $(MKDIR) $(OBJPATH-release)

$(FILE-release): $(OBJECTS-release)
	@ echo "Linking executable $@"
	@ $(COMPILER-release) $^ $(COMPILATION_FLAGS-release) $(LINKER_FLAGS-release) -o $@
	@ echo "Built target: release"

$(OBJPATH-release)main.o: ./src/main.cpp $(HEADERS)
	@ echo "Building object $@"
	@ $(COMPILER-release) $< -c $(COMPILATION_FLAGS-release) -o $@

$(OBJPATH-release)%.o: ./src/%.cpp ./include/%.hpp
	@ echo "Building object $@"
	@ $(COMPILER-release) $< -c $(COMPILATION_FLAGS-release) -o $@

###################### DEBUG #####################
debug: $(OBJPATH-debug) $(FILE-debug)

debug_clean: $(OBJPATH-debug)
	@ $(REMOVE) $(OBJPATH-debug)*.o $(FILE-debug)

$(OBJPATH-debug):
	@ $(MKDIR) $(OBJPATH-debug)

$(FILE-debug): $(OBJECTS-debug)
	@ echo "Linking executable $@"
	@ $(COMPILER-debug) $^ $(COMPILATION_FLAGS-debug) $(LINKER_FLAGS-debug) -o $@
	@ echo "Built target: debug"

$(OBJPATH-debug)main.o: ./src/main.cpp $(HEADERS)
	@ echo "Building object $@"
	@ $(COMPILER-debug) $< -c $(COMPILATION_FLAGS-debug) -o $@

$(OBJPATH-debug)%.o: ./src/%.cpp ./include/%.hpp
	@ echo "Building object $@"
	@ $(COMPILER-debug) $< -c $(COMPILATION_FLAGS-debug) -o $@
