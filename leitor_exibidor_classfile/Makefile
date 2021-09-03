#Name of the Project
PROJ_NAME=jvm

#Contain CPP files
SRC_DIRECTORY=src

#Contain Header files to include
INC_DIRECTORY=./include

#Contain Object files
OBJ_DIRECTORY=obj

#Commands to get the files
CPP_COM=$(wildcard $(SRC_DIRECTORY)/*.cpp)
INCLUDE_COM=$(wildcard $(INC_DIRECTORY)/*.h)
OBJ_COM=$(CPP_COM:$(SRC_DIRECTORY)/%.cpp=$(OBJ_DIRECTORY)/%.o)


#Compilator Flags
CC_FLAGS = -g -I$(INC_DIRECTORY) -Wall -Wextra

#Operation System Check
ifeq ($(OS),Windows_NT)
	#Project Name
	PROJ_NAME = bin\jvm.exe
	#Compilator
	CC = g++
	#Remove Command
	RM = del /Q

	#Remove Objects
	RM_OBJ = $(RM) $(OBJ_DIRECTORY)
	#Remove Binary
	RM_BINARY = $(RM) $(PROJ_NAME)
else
	PROJ_NAME = bin/jvm
	CC = g++
	RM = rm -rf

	RM_OBJ = $(RM) $(OBJ_DIRECTORY)/*
	RM_BINARY = $(RM) $(PROJ_NAME)
endif
         
#
#Linking and Compiling
#
all: $(PROJ_NAME)


$(PROJ_NAME): $(OBJ_COM)
	@ echo "Building "$@" using G++ Linker"  
	@$(CC) $(CC_FLAGS) $(OBJ_COM) -o $@
	@ echo "Finished building binary"

$(OBJ_COM): $(OBJ_DIRECTORY)/%.o : $(SRC_DIRECTORY)/%.cpp
	@echo "Building "$< "to" $@ "using GCC Compiler"
	@$(CC) $(CC_FLAGS) -c $< -o $@


.PHONY: clean

clean: clean_obj clean_bin

clean_obj:
	$(RM_OBJ)

clean_bin:
	$(RM_BINARY)
	


