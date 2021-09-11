ROOT=..
MODULE=cpp
HOME=$(ROOT)/$(MODULE)

#----------------------------------------------------------
# Path for project directories
#----------------------------------------------------------
SDIR=$(HOME)/src
IDIR=$(HOME)/include
BDIR=$(HOME)/bin
ODIR=$(BDIR)/obj
LDIR=$(HOME)/lib

#----------------------------------------------------------
# Compiler and it option
#----------------------------------------------------------
CC=gcc-11
CXX=g++-11
IFLAGS= -I$(IDIR)
CFLAGS= -Wall -c 
CXXFLAGS= -std=c++17 -std=gnu++17
LFLAGS=
LDIR=
LIBS=

#----------------------------------------------------------
# Source files
#----------------------------------------------------------
OUT=$(BDIR)/$(MODULE).out
CSRCS= $(shell find $(SDIR) -type f -name *.c)
#CXXSRCS= $(wildcard $(SDIR)/*.cpp)
CXXSRCS= $(shell find $(SDIR) -type f -name *.cpp)
OBJS:=$(filter $(ODIR)/%.o, $(patsubst $(SDIR)/%.c, $(ODIR)/%.o, $(CSRCS)) \
	$(patsubst $(SDIR)/%.cpp, $(ODIR)/%.o, $(CXXSRCS)))

#----------------------------------------------------------
# Pattern rules
#----------------------------------------------------------
$(ODIR)/%.o: $(SDIR)/%.c | $(ODIR)
	@mkdir -p $(dir $@)
	$(CC) $(IFLAGS) $(CFLAGS) $^ -o $@

$(ODIR)/%.o: $(SDIR)/%.cpp | $(ODIR)
	@mkdir -p $(dir $@)
	$(CC) $(IFLAGS) $(CXXFLAGS) $(CFLAGS) $^ -o $@

#----------------------------------------------------------
# Rules
#----------------------------------------------------------
$(OUT): $(OBJS)
	@echo "\n\nGenerating output file..."
	$(CXX) $(CXXFLAGS) $(LFLAGS) $(LDIR) $(LIBS) $^ -o $@

$(ODIR):
	@mkdir -p $@
	@echo "Object directory created...!!"

all: build run

build: $(OUT)
run:
	@echo "Executing binary...\n"
	@./bin/cpp.out
	@echo "\nExecution ends!!!"

clean:
	@echo "Performing clean up..."
	@rm -rf $(ODIR)
cleanall:
	@echo "Performing clean up..."
	@rm -rf $(ODIR)
	@rm -rf $(BDIR)

print-%  : ; @echo $* = $($*)

.phony: all build run clean