OBJECTS = Main.o TuringMachine.o State.o Alphabet.o Tape.o Transition.o
CFLAGS = -g -c -O3 -std=c++17 -I../include

exe: $(OBJECTS)
	g++  $(OBJECTS) -o ../bin/exe
	mv *.o ../obj

Main.o:
	g++ $(CFLAGS) ../src/Main.cc

TuringMachine.o:
	g++ $(CFLAGS) ../src/TuringMachine.cc

State.o:
	g++ $(CFLAGS) ../src/State.cc

Alphabet.o:
	g++ $(CFLAGS) ../src/Alphabet.cc

Tape.o:
	g++ $(CFLAGS) ../src/Tape.cc

Transition.o:
	g++ $(CFLAGS) ../src/Transition.cc

.PHONY: clean

clean:
	rm -rf ../obj/*.o
	rm -rf ../build/*.o
	rm -rf ../bin/*

run:
	make -s clean && make -s && ../bin/exe
