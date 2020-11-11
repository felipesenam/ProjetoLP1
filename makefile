#Makefile for multiples projects *Linux version
#By Felipe Sena - Last updated in 11/11/2020 at 00:59

#################### SUBTITLE ####################
#TARGET_LIST=[id]          #DON'T FORGET TO ADD THE TARGET ID TO THE TARGETS LIST

#                       ...

#              FILE-[id] = #EXECUTABLE NAME (AND EXTENSION)

#          COMPILER-[id] = #COMPILER
# COMPILATION_FLAGS-[id] = #COMPILATION FLAGS
#      LINKER_FLAGS-[id] = #LINKER FLAGS

#          MAINFILE-[id] = #MAIN FUNCTION'S FILE (WITHOUT EXTENSION)
#           SRCPATH-[id] = #WHERE THE SOURCE FILES ARE LOCATED
#           INCPATH-[id] = #WHERE THE HEADER FILES ARE LOCATED
#           OBJPATH-[id] = #WHERE THE BINARY FILES WILL BE LOCATED

#        SOURCE_EXT-[id] = #SOURCE FILES EXTENSION
#        HEADER_EXT-[id] = #HEADER FILES EXTENSION
##################################################

#################### EXAMPLE #####################
# TARGET_LIST=1 #ALWAYS SEPARATE TARGETS WITH BLANK SPACES

# FILE-1=prog.exe

# COMPILER-1=x86_64-w64-mingw32-c++
# COMPILATION_FLAGS-1=-Wall -Wextra -pedantic #YOU CAN LEAVE THIS SPACE IN BLANK
# LINKER_FLAGS-1=-static -static-libgcc -static-libstdc++ #YOU CAN LEAVE THIS SPACE IN BLANK

# MAINFILE-1=main
# SRCPATH-1=./src/
# INCPATH-1=./include/ #SEPARATE WITH BLANK SPACES IF THERE IS MORE THAN ONE PATH
# OBJPATH-1=./objects/Windows/

# SOURCE_EXT-1=.cpp
# HEADER_EXT-1=.h
##################################################

##################### TARGETS ####################
TARGET_LIST=PROJETO_LP1

FILE-PROJETO_LP1=prog

COMPILER-PROJETO_LP1=g++
COMPILATION_FLAGS-PROJETO_LP1=-Wall -Wextra -pedantic -g
LINKER_FLAGS-PROJETO_LP1=

MAINFILE-PROJETO_LP1=main
SRCPATH-PROJETO_LP1=./src/
INCPATH-PROJETO_LP1=./include/
OBJPATH-PROJETO_LP1=./objects/Linux/

SOURCE_EXT-PROJETO_LP1=.cpp
HEADER_EXT-PROJETO_LP1=.h
##################################################

##################### DEFINES ####################
.DEFAULT_GOAL:=all

FILE?=$(firstword $(TARGET_LIST))

FILE-SOURCE=$(wildcard $(SRCPATH-$(FILE))*$(SOURCE_EXT-$(FILE)))
HEADERS=$(wildcard $(INCPATH-$(FILE))*$(HEADER_EXT-$(FILE)))
OBJECTS=$(subst $(SOURCE_EXT-$(FILE)),.o,$(subst $(SRCPATH-$(FILE)),$(OBJPATH-$(FILE)),$(FILE-SOURCE)))

OBJCOUNT=$$(($(words $(OBJECTS))+1))
CURCOUNT=1
##################################################


#	$@	Nome da regra.
#	$<	Nome da primeira dependência
#	$^	Lista de dependências
#	$?	Lista de dependências mais recentes que a regra.
#	$*	Nome do arquivo sem sufixo


all: objdir
	@ $(foreach F,$(TARGET_LIST), $(MAKE) --silent --stop $(F);)

%:
	@ $(eval FILE=$@)
	@ if [ "$(findstring $(FILE),$(TARGET_LIST))" = "$(FILE)" ]; then ($(MAKE) --silent --stop FILE=$(FILE) $(FILE-$(FILE));printf "[100%%] Built target %s\n" $(FILE);); else (echo "make: There is no recipe for target '$(FILE)'"; exit); fi

$(FILE-$(FILE)): $(OBJECTS)
	@ printf "[%3i%%]" $$(($(CURCOUNT)*100/$(OBJCOUNT)))
	@ echo " \e[92mLinking executable $(FILE-$(FILE))\e[0m"
	@ $(COMPILER-$(FILE)) $^ $(COMPILATION_FLAGS-$(FILE)) $(LINKER_FLAGS-$(FILE)) -o $(FILE-$(FILE)) $(foreach I,$(INCPATH-$(FILE)),$(shell echo -I$(I)))

$(OBJPATH-$(FILE))%.o: $(SRCPATH-$(FILE))%$(SOURCE_EXT-$(FILE)) $(HEADERS)
	@ printf "[%3i%%]" $$(($(CURCOUNT)*100/$(OBJCOUNT)))
	@ echo " \e[32mBuilding $(COMPILER-$(FILE)) object $@\e[0m"
	@ $(COMPILER-$(FILE)) $< -c $(COMPILATION_FLAGS-$(FILE)) -o $@ $(foreach I,$(INCPATH-$(FILE)),$(shell echo -I$(I)))
	@ $(eval CURCOUNT=$(shell echo $$(($(CURCOUNT)+1))))

$(OBJPATH-$(FILE))$(MAINFILE-$(FILE)).o: $(SRCPATH-$(FILE))$(MAINFILE-$(FILE))$(SOURCE_EXT-$(FILE)) $(HEADERS)
	@ printf "[%3i%%]" $$(($(CURCOUNT)*100/$(OBJCOUNT)))
	@ echo " \e[32mBuilding $(COMPILER-$(FILE)) object $@\e[0m"
	@ $(COMPILER-$(FILE)) $< -c $(COMPILATION_FLAGS-$(FILE)) -o $@ $(foreach I,$(INCPATH-$(FILE)),$(shell echo -I$(I)))
	@ $(eval CURCOUNT=$(shell echo $$(($(CURCOUNT)+1))))

objdir:
	@ $(foreach F,$(TARGET_LIST), $(shell mkdir -p $(OBJPATH-$(F))))

clean:
	@ $(foreach F,$(TARGET_LIST), $(shell rm -rf $(OBJPATH-$(F))*.o $(FILE-$(F)) *~))
	@ echo "make: All binaries have been deleted."

.PHONY: all clean
