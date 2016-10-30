Sistema-de-texto-predictivo: diccionario.o
	$(CXX) -o $@ $^

diccionario.o: diccionario.cpp diccionario.h

clean:
	rm -f *.cpp~ *.o

 