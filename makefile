Sistema-de-texto-predictivo: Main.o
	$(CXX) -o $@ $^

clean:
	rm -f *.cpp~ *.o

