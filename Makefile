.SUFFIXES:

main: src/board.o src/board_states.o src/main.o src/type.o
	g++ -o $@ $^

%.o: %.cpp
	g++ -I ./include -o $@ -c $<
