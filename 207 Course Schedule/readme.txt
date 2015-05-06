001.cpp (297ms):
002.cpp (256ms):

The first step is to sort the edge list and build up the forward star (I just suddenly want to practice this data structure). Then Kahn's Algorithm is performed to achieve the topological sort. If no cycle exists (all nodes have been popped out), then the true value can be returned. Due to the sorting in preprocessing, the time complexity is O(n+mlog(m)). The memory complexity is O(m). The time complexity can be improved to O(n+m) with adjacent list as in 002.cpp.
