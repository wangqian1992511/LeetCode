class Stack:
    # initialize your data structure here.
    def __init__(self):
        self.qa = []
        self.qb = []

    # @param x, an integer
    # @return nothing
    def push(self, x):
        while len(self.qa) > 0:
            self.qb.append(self.qa.pop())
        self.qa.append(x)
        while len(self.qb) > 0:
            self.qa.append(self.qb.pop())

    # @return nothing
    def pop(self):
        self.qa.pop(0)

    # @return an integer
    def top(self):
        return self.qa[0]

    # @return an boolean
    def empty(self):
        return len(self.qa) == 0