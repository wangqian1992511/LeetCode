001.cpp (12ms):

Use a stack to maintain the status of this elevation map. If the elevation to be pushed to the stack not higher than the top element, then there will be no more trapped water. Otherwise, we should fill keep filling. For example,

Stack: 5 4 3 2 
Len:   1 1 1 1
Candidate: 1 2 3 2 1 3

->

Stack: 5 4 3 2 1
Len:   1 1 1 1 1
Candidate: 2 3 2 1 3

->

Stack: 5 4 3 2 1 2
Len:   1 1 1 1 1 1
Candidate: 3 2 1 3

->

Stack: 5 4 3 2
Len:   1 1 1 3
Candidate: 3 2 1 3
Sum: 1

->

Stack: 5 4 3 2 3
Len:   1 1 1 3 1
Candidate: 2 1 3
Sum: 1

->

Stack: 5 4 3
Len:   1 1 5
Candidate: 2 1 3
Sum: 4

->

......
