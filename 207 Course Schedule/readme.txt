001.cpp (297ms):

The first step is to sort the edge list and build up the forward star. Then Kahn's Algorithm is performed to achieve the topological sort. If no cycle exists (all nodes have been popped out), then the true value can be returned. Due to the sorting in preprocessing, the time complexity is O(nlog(n)+m).
