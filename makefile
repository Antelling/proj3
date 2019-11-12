COMPILER  = g++ -std=c++11

DEBUG  = 

EXE  = app

HDRS  = Term.h\
	TermArrayList.h\
	TermDblList.h\
	TermVectorList.h\
	TermList.h\

OBJS  = term.o\
	TermArrayList.o\
	TermDblList.o\
	TermVectorList.o\
	app.o\

SRC  = 	Term.cpp\
	TermArrayList.cpp\
	TermDblList.cpp\
	TermVectorList.cpp\
	app.cpp\


##########################################################################
$(EXE): $(OBJS)
	$(COMPILER) -o $(EXE) $(OBJS) $(DEBUG)

Term.o:
	$(COMPILER) -c term.cpp $(DEBUG)

TermArrayList.o:
	$(COMPILER) -c TermArrayList.cpp $(DEBUG)

TermVectorList.o:
	$(COMPILER) -c TermVectorList.cpp $(DEBUG)

TermDblList.o:
	$(COMPILER) -c TermDblList.cpp $(DEBUG)

app.o:
	$(COMPILER) -c app.cpp $(DEBUG)

testll:
	$(COMPILER) $(DEBUG) testLL.cpp -o testll


clean:
	rm *.o $(EXE)

