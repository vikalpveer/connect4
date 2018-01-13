FLAGS = -O
CC = g++
connect4 : main.o connect4.o board.o player.o
	$(CC) $(CLAGS) main.o connect4.o board.o player.o

main.o : main.cpp
	$(CC) $(CLAGS) -c main.cpp

connect4.o : connect4.cpp
	$(CC) $(CLAGS) -c connect4.cpp

board.o : board.cpp
	$(CC) $(CLAGS) -c board.cpp

player.o : player.cpp
	$(CC) $(CLAGS) -c player.cpp

clean:
	rm *.o
	rm connect4
	rm a.out
