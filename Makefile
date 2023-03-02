########Makefile by Soufou########

#Variables
PROJ= TP2
CC= g++
CFLAGS = -Wall -std=c++14
FLAGS =
RM = rm -f
NOM = so
ZIP = zip -r

#Directories
SRC_DIR=src
BIN_DIR=bin
SUBDIRS=$(wildcard $(SRC_DIR)/*)

#path to .cpp files and .o files
SRCS=$(wildcard $(addsuffix /*.cpp,$(SUBDIRS)))
PROGS=$(foreach dir,$(SUBDIRS),$(BIN_DIR)/$(notdir $(dir)))

# Define build target for all programs
all: $(PROGS)

# Define program targets
$(PROGS): $(SRCS)
	$(CC) $(CFLAGS) $(filter $(SRC_DIR)/$(notdir $@)/%, $^) -o $@

.PHONY : cleanAll
cleanAll : 
	$(RM) $(BIN_DIR)/*.o
	$(RM) $(PROGS)
.PHONY : clean
clean : 
	$(RM) $(PROGS)
.PHONY : save
save :
	cp -a src/. save/

.PHONY : restore
restore :
	rm src/*
	cp -a save/. src/
.PHONY : zip
zip :
	make cleanAll
	zip -r $(NOM)$(PROJ).zip *
