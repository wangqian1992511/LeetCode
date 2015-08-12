001.cpp (456ms):

Use the quad-search to determine, whether the sub-matrix on the upper-left corner contains the target or not. By Master's Theorem, the time complexity is O((nm)^log_4(3)), aka O((nm)^0.792).

001.py (124ms):

There is also an O(n + m) algorithm. Check from the lower leftmost element. If the targert is smaller than it, move upwards. Otherwise, move to the right. Hence, at most "n + m" movements are needed.
