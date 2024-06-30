## Simple BPC-PPC projekt makefile example by: Pety 2022
## $Id: Makefile 3 2022-10-26 17:03:14Z petyovsky $

##CXX = clang++
CXX = g++
CXXFLAGS = -c -O3 -std=c++20 -frtti -Wall -Wextra -pedantic -Wno-keyword-macro -Wno-stringop-truncation
LDFLAGS =
RM = rm -f

.PHONY: all docs opendocs run clean cleandocs

all: Project

Project: main.o CBlock_TWeekDay.o check.o demagle.o
	$(CXX) $(LDFLAGS) -o Project main.o CBlock_TWeekDay.o check.o demagle.o

main.o: main.cpp CContainer.h CBlock.h CBlock_bool.h CBlock_TWeekDay.h CBlockBase.h demagle.h ClassInfo.h check.h
	$(CXX) $(CXXFLAGS) main.cpp

CContainer.o: CContainer.cpp CContainer.h CBlock.h CBlock_bool.h CBlock_TWeekDay.h CBlockBase.h demagle.h ClassInfo.h check.h
	$(CXX) $(CXXFLAGS) CContainer.cpp

CBlock_TWeekDay.o: CBlock_TWeekDay.cpp CBlock.h CBlock_TWeekDay.h CBlockBase.h demagle.h ClassInfo.h check.h
	$(CXX) $(CXXFLAGS) CBlock_TWeekDay.cpp

check.o: check.cpp check.h
	$(CXX) $(CXXFLAGS) check.cpp

demagle.o: demagle.cpp demagle.h
	$(CXX) $(CXXFLAGS) demagle.cpp

docs: Doxyfile Introduction.md Documentation.md Tasks.md main.cpp CContainer.h CContainer.cpp CBlock.h CBlock_bool.h CBlock_TWeekDay.h CBlockBase.h demagle.h check.h ClassInfo.h
	export LC_CTYPE="en_US.UTF-8"; doxygen Doxyfile

opendocs: docs
	open html/index.html

run: Project
	./Project

clean:
	-$(RM) Project main.o CContainer.o CBlock_bool.o CBlock_TWeekDay.o check.o demagle.o

cleandocs:
	-$(RM) -r html latex
