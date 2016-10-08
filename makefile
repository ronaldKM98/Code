all: Sistema-de-texto-predictivo

Sistema-de-texto-predictivo: Main.o LeerArr.o
	$(CXX) -o $@ $^

	Main.o: Main.cpp

	LeerArr.o: LeerArr.cpp LeerArr.h		

