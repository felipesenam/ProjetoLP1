#Makefile for multiples projects
#By Felipe Sena 10/11/2020

#################### SUBTITLE ####################
#TARGET_LIST=[id]          #DON'T FORGET TO ADD THE TARGET ID TO THE TARGETS LIST

#                       ...

#              FILE_[id] = #EXECUTABLE NAME (AND EXTENSION)

#          COMPILER_[id] = #COMPILER
# COMPILATION_FLAGS_[id] = #COMPILATION FLAGS
#      LINKER_FLAGS_[id] = #LINKER FLAGS

#          MAINFILE_[id] = #MAIN FUNCTION'S FILE (WITHOUT EXTENSION)
#           SRCPATH_[id] = #WHERE THE SOURCE FILES ARE LOCATED
#           INCPATH_[id] = #WHERE THE HEADER FILES ARE LOCATED
#           OBJPATH_[id] = #WHERE THE BINARY FILES WILL BE LOCATED

#        SOURCE_EXT_[id] = #SOURCE FILES EXTENSION
#        HEADER_EXT_[id] = #HEADER FILES EXTENSION
##################################################

#################### EXAMPLE #####################
# TARGET_LIST=1 #ALWAYS SEPARATE TARGETS WITH BLANK SPACES

# FILE_1=prog.exe

# COMPILER_1=x86_64-w64-mingw32-c++
# COMPILATION_FLAGS_1=-Wall -Wextra -pedantic
# LINKER_FLAGS_1=-static -static-libgcc -static-libstdc++ #YOU CAN LEAVE THIS SPACE IN BLANK

# MAINFILE_1=main
# SRCPATH_1=./src/
# INCPATH_1=./include/ #SEPARATE WITH BLANK SPACES IF THERE IS MORE THAN ONE PATH
# OBJPATH_1=./objects/Windows/

# SOURCE_EXT_1=.cpp
# HEADER_EXT_1=.h
##################################################

##################### TARGETS ####################
TARGET_LIST=1 2
#================================================#
FILE_1=prog.exe

COMPILER_1=x86_64-w64-mingw32-g++-win32
COMPILATION_FLAGS_1=-O3 -Wall -Wextra -pedantic
LINKER_FLAGS_1=-static -static-libgcc -static-libstdc++

MAINFILE_1=main
SRCPATH_1=./src/
INCPATH_1=./include
OBJPATH_1=./objects/Windows/

SOURCE_EXT_1=.cpp
HEADER_EXT_1=.h
#================================================#
FILE_2=prog

COMPILER_2=g++
COMPILATION_FLAGS_2=-Wall -Wextra -pedantic -Wno-unused-result -g
      LINKER_FLAGS_2=

MAINFILE_2=main
SRCPATH_2=./src/
INCPATH_2=./include/
OBJPATH_2=./objects/Linux/

SOURCE_EXT_2=.cpp
HEADER_EXT_2=.h
##################################################

##################### DEFINES ####################
.DEFAULT_GOAL:=all

FILE?=$(firstword $(TARGET_LIST))

FILE_SOURCE=$(wildcard $(SRCPATH_$(FILE))*$(SOURCE_EXT_$(FILE)))
HEADERS=$(wildcard $(INCPATH_$(FILE))*$(HEADER_EXT_$(FILE)))
OBJECTS=$(subst $(SOURCE_EXT_$(FILE)),.o,$(subst $(SRCPATH_$(FILE)),$(OBJPATH_$(FILE)),$(FILE_SOURCE)))

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
	@ if [ "$(findstring $(FILE),$(TARGET_LIST))" = "$(FILE)" ]; then ($(MAKE) --silent --stop FILE=$(FILE) $(FILE_$(FILE));printf "[100%%] Built target %s\n" $(FILE);); else (echo "make: There is no recipe for target '$(FILE)'"; exit); fi

$(FILE_$(FILE)): $(OBJECTS)
	@ printf "[%3i%%]" $$(($(CURCOUNT)*100/$(OBJCOUNT)))
	@ echo " \e[92mLinking executable $(FILE_$(FILE))\e[0m"
	@ $(COMPILER_$(FILE)) $^ $(COMPILATION_FLAGS_$(FILE)) $(LINKER_FLAGS_$(FILE)) -o $(FILE_$(FILE)) $(foreach I,$(INCPATH_$(FILE)),$(shell echo -I$(I)))

$(OBJPATH_$(FILE))%.o: $(SRCPATH_$(FILE))%$(SOURCE_EXT_$(FILE)) $(HEADERS)
	@ printf "[%3i%%]" $$(($(CURCOUNT)*100/$(OBJCOUNT)))
	@ echo " \e[32mBuilding $(COMPILER_$(FILE)) object $@\e[0m"
	@ $(COMPILER_$(FILE)) $< -c $(COMPILATION_FLAGS_$(FILE)) -o $@ $(foreach I,$(INCPATH_$(FILE)),$(shell echo -I$(I)))
	@ $(eval CURCOUNT=$(shell echo $$(($(CURCOUNT)+1))))

$(OBJPATH_$(FILE))$(MAINFILE_$(FILE)).o: $(SRCPATH_$(FILE))$(MAINFILE_$(FILE))$(SOURCE_EXT_$(FILE)) $(HEADERS)
	@ printf "[%3i%%]" $$(($(CURCOUNT)*100/$(OBJCOUNT)))
	@ echo " \e[32mBuilding $(COMPILER_$(FILE)) object $@\e[0m"
	@ $(COMPILER_$(FILE)) $< -c $(COMPILATION_FLAGS_$(FILE)) -o $@ $(foreach I,$(INCPATH_$(FILE)),$(shell echo -I$(I)))
	@ $(eval CURCOUNT=$(shell echo $$(($(CURCOUNT)+1))))

objdir:
	@ $(foreach F,$(TARGET_LIST), $(shell mkdir -p $(OBJPATH_$(F))))

clean:
	@ $(foreach F,$(TARGET_LIST), $(shell rm -rf $(OBJPATH_$(F))*.o $(FILE_$(F)) *~))
	@ echo "make: All binaries have been deleted."

.PHONY: all clean
