001.cpp (2ms):
001.py (132ms):

Rectangle cutting is the general solution to this kind of problems, no matter how may rectangles there are. Recursively ignore the area covered by the previous rectangles.

 ______________________________________
|                                      |
|       __________________             |
|      |                  |            |
|      |      NO. i       |            |
|      |                  |            |
|      |__________________|            |
|                                      |
|______________________________________|

------------cutting----------------->>

 ______________________________________
|      |        A         |            |
|  B   |__________________|      C     |
|      |                  |            |
|      |      NO. i       |            |
|      |                  |            |
|      |__________________|            |
|      |                  |            |
|______|________D_________|____________|

Regions A, B, C, D are still remaining to be cutted by Rectangle No. (i+1).

