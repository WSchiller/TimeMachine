output: egypt.o information.o jurassic.o medieval.o revolution.o roman.o space.o game.o menu.o main.o
	g++ -std=c++0x egypt.o information.o jurassic.o medieval.o revolution.o roman.o space.o game.o menu.o main.o -o output # compiles and links the ten object files created below into one executable file named output.   

egypt.o: egypt.cpp egypt.hpp
	g++ -std=c++0x -c egypt.cpp #-c option compiles egypt.cpp into an object(.o) file

information.o: information.cpp information.hpp
	g++ -std=c++0x -c information.cpp #-c option compiles information.cpp into an object(.o) file	

jurassic.o: jurassic.cpp jurassic.hpp
	g++ -std=c++0x -c jurassic.cpp #-c option compiles jurassic.cpp into an object(.o) file 

medieval.o: medieval.cpp medieval.hpp
	g++ -std=c++0x -c medieval.cpp #-c option compiles medieval.cpp into an object(.o) file

revolution.o: revolution.cpp revolution.hpp
	g++ -std=c++0x -c revolution.cpp #-c option compiles revolution.cpp into an object(.o) file

roman.o: roman.cpp roman.hpp
	g++ -std=c++0x -c roman.cpp #-c option compiles roman.cpp into an object(.o) file

space.o: space.cpp space.hpp
	g++ -std=c++0x -c space.cpp #-c option compiles space.cpp into an object(.o) file

game.o: game.cpp game.hpp
	g++ -std=c++0x -c game.cpp  #-c option compiles game.cpp into an object(.o) file

menu.o: menu.cpp menu.hpp
	g++ -std=c++0x -c menu.cpp  #-c option compiles menu.cpp into an object(.o) file

main.o: main.cpp
	g++ -std=c++0x -c main.cpp  #-c option compiles main.cpp into an object(.o) file

clean:
	rm *.o output #removes all object files with .o extension and output executable.
