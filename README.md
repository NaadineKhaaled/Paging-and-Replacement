# Paging-and-Replacement
Implemented Some of paging replacement algorithms 
Your input will be from standard input. Your output will be from standard output. The input
will contain the number of pages allocated to the process, the simulated algorithm
(OPTIMAL, FIFO, LRU, or CLOCK), and then a sequence of page references like below:
3
FIFO
5
12
5
2
4
2
5
......
-1
Note: The last line in the input is -1 (and is ignored)
For each run, you should print the following:
1. A trace recording page faults for each memory reference in the sequence.
2. Counter recording total page faults.

2

We will have the following results (notice the two-digit page numbers):
Replacement Policy = FIFO
-------------------------------------
Page Content of Frames
---- -----------------
05 05
12 05 12
05 05 12
02 05 12 02
04 F 04 12 02
02 04 12 02
05 F 04 05 02
-------------------------------------
Number of page faults = 2
