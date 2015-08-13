class DoubleLinkedNode:
    def __init__(self, k, x):
        self.prev = None
        self.next = None
        self.val = x
        self.key = k
        
    def prevLink(self, s):
        self.next = s
        s.prev = self
        
    def delLink(self):
        self.prev.next = self.next
        self.next.prev = self.prev

class LRUCache:
    # @param capacity, an integer
    def __init__(self, capacity):
        self.lru = dict()
        self.cap = capacity
        self.tot = 0
        self.head = DoubleLinkedNode(0, 0)
        self.tail = DoubleLinkedNode(0, 0)
        self.head.prevLink(self.tail)

    # @return an integer
    def get(self, key):
        if key in self.lru:
            self.lru[key].delLink()
            self.lru[key].prevLink(self.head.next)
            self.head.prevLink(self.lru[key])            
            return self.lru[key].val
        return -1

    # @param key, an integer
    # @param value, an integer
    # @return nothing
    def set(self, key, value):
        if key not in self.lru:
            self.tot += 1
            self.lru[key] = DoubleLinkedNode(key, value)
        else:
            self.lru[key].val = value
            self.lru[key].delLink()
            
        self.lru[key].prevLink(self.head.next)
        self.head.prevLink(self.lru[key])
        
        if self.tot > self.cap:
            ele = self.tail.prev
            ele.delLink()
            del self.lru[ele.key]
            self.tot -= 1