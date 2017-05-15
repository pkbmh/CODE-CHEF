import queue as Q

class Pair:
    def __init__(self,first,second):
        self.first = first
        self.second = second

    def __lt__(self, other):
        if(self.first != other.first):
            return self.first > other.first
        else:
            return self.second > other.second


pq = Q.PriorityQueue()
pq.put(Pair(1,1))
pq.put(Pair(1,2))
pq.put(Pair(2,1))
pq.put(Pair(2,0))


while not pq.empty():
    p = pq.get()
    print(p.first, end=" ")
    print(p.second)