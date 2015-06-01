001.cpp (TLE):

This is a very nice BFS problem. At first, I code this TLE version. The object in the rolling queue for BFS is the path. 

002.cpp (1012ms):

Notice that, for each node in the BFS tree, we check 26m extending nodes, where m is the length of each word. What we should do is try to decrese this number. Obviously, not all of these 26m nodes are in original dictionary. So, we build up the adjacent list for each string, so that we can access to the unnecessary node less frequently. However, this version is still not fast enough, since the initilization, whose time complexity is about O(nm^3), costs a long time. Here, n is the number of strings in the dictionary. Here, we just suppose that each word has a length of about 5 to 7, so it is acceptable to consider 26 equal to m^2.

003.cpp (812ms):

Actually, the path is not the optimal object for BFS in this problem. Consider the following figure.

     2
   /   \
  /     \
1         4---------5
  \     /
   \   /
	 3
	 
The path 4 - 5 will be visited twice in the first two files, once in 1 - 2 - 4 - 5, and once in 1 - 3 - 4 - 5. But if we use the string as the object, we only need to enque node 4 once. But instead we should record all its precedences, so that we can recover all the paths later. In this circumstance, each node will only be pushed into the queue once. Thus the time complexity for the BFS is exactly O(nm^3).

004.cpp (484ms):

By now the BFS part has the same time complexity with the initilization part. Thus, it is meaningless to keep the initilization in the solution. Remove it to get a faster solution.