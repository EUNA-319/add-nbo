add_nbo: add-nbo.o 
	g++ -o add-nbo add-nbo.o

add_nbo.o: add-nbo.cpp
	g++ -c add-nbo.cpp

clean:
	rm -rf add-nbo add-nbo.o



