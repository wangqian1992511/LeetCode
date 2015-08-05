class Queue:
    # initialize your data structure here.
    def __init__(self):
        self.sa = []
        self.sb = []

    # @param x, an integer
    # @return nothing
    def push(self, x):
        while len(self.sa) > 0:
            self.sb.append(self.sa.pop())
        self.sa.append(x)
        while len(self.sb) > 0:
            self.sa.append(self.sb.pop())

    # @return nothing
    def pop(self):
        self.sa.pop()

    # @return an integer
    def peek(self):
        return self.sa[len(self.sa) - 1]

    # @return an boolean
    def empty(self):
        return len(self.sa) == 0