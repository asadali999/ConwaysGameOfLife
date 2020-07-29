# ConwaysGameOfLife
###PROJECT MEMBERS###
**63610** | **SYED ASAD ALI KAZMI**
63723 | Mohsin Ali

## Approach ##
We spent lot of time to think how can we make it, use some sources from Internet and Youtube to make it work.

## Problems Faces ##

###Problem 1: Faced difficulty to find some info about this game###
It was really difficult to find on internet and make it work according to my need, because I was not able to find proper help on internet and other related source.

###Problem 2: Contact with teammate###
Due to this pendamic situation it was tough to find some info about project together and merge our work, we faced difficulty in sharing our thoughts. 

###Problem 3:UBUNTU failure###
Although it is new but very hard to undrstand and had to make labs and project in limited period of time by usig it.

###INTRODUCTION:###
This is a c implementation of 'Conway's Game of Life'. The rules of the game are simple. The universe of the game is a torus-connected two-dimensional grid filled with 'live' cells (denoted by '*' in my implementation) and 'dead' cells (denoted by '.'). At the beginning of the game, the grid is randomly populated with some distribution of live and dead cells, and cells are either born or destroyed based on their interactions with their eight neighbors:	
Any live cell with fewer than 2 living neighbors dies of loneliness.
Any live cell with more than 3 living neighbors dies of overcrowding.
A live cell with 2 or 3 neighbors continues on to the next generation.
A dead cell surrounded by exactly 3 neighbors will be made live.

###Cyc_Barrier:###
We add “pthread” library, it helps us to use some predefine thread’s keywords. Like “pthread_mutex_t”, “pthread_cond_t”, “cyclic_barrier_init”, “cyclic_barrier_await”, “cyclic_barrier_destroy”.
•	PTHREAD_MUTEX_T:
Locks a mutex object, which identifies a mutex. The thread that has locked a mutex becomes its current owner and remains the owner until the same thread has unlocked it.
•	PTHREAD_COND_T:
This is a synchronization device that allows threads to suspend execution and relinquish the processors until some predicate on shared data is satisfied. 

###Board:###
Board class I add for splitting board in rows and columns. It checks some condition of threads and then split board by rows and columns.

###Time:###
•	Time taken is 2.6 thread used 5
•	Time taken is 0.435 thread used 2

###REFERENCES:###
https://www.geeksforgeeks.org/program-for-conways-game-of-life/
https://codereview.stackexchange.com/questions/208973/conways-game-of-life-in-c-3-mode

