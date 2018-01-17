### C++ Implementaion of connect4 Game ###

Author : Vikalp Veer

This program is a c++ implementation of a connect4 Game. 
There are three main components in this project :
1) Board.h/cpp : Defines class and logic for connect4 Board.
2) Players.h/cpp : defines class and logic for players.
3) connect4.h/cpp : Class for actual connect4 game. 

The game supports play with Human vs Human and also support Computer v/s Human.

Note : When playing v/s Computer, first few moves by computer may take few seconds.
When playing against computer, the program implements method "getBestColum" which simulates minimax algo
and tries to find score which maximizes Computer's chance to win.


How to Execute :
---------------
On Linux, just give command :

#make clean
#make

once source is built an executable with the name connect4 would be generated.
To play the game, run ./connect4

Future Work :
------------
1. Computer vs Computer.. This can be easily implemented.
2. Better logic for determining Heuristic's for Computer's best move.
3. Support for player such as adding name.
4. Adding a GUI. ncurses ?? Easier if program is ported to python, can use turtle etc.
