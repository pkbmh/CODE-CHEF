import Queue
class obj :
	def __init__(self, a, b, c) :
		self.arrival = a
		self.lecture = b
		self.sadness = c
	def __lt__(self, other) :
		return self.sadness > other.sadness

t = int(raw_input())
for i in range(t) :
	n,d = map(int,raw_input().split())
	arr = {}
	sm = 0
	ans = 0
	for j in range(n) :
		tmp = tuple(raw_input().split())
		tmp = map(int, tmp)
		x = tmp[0] + tmp[1] - 1
		if x > d :
			ans = ans + (x-d) * tmp[2]
			tmp[1] = tmp[1] - (x-d)
		sm = sm + tmp[1];
		if not tmp[0] in arr :
			arr[tmp[0]] = []
		arr[tmp[0]].append(tuple(tmp))
	pq = Queue.PriorityQueue()
	for time in range(1,d+1) :
		if time in arr :
			for x in arr[time] :
				pq.put(obj(x[0],x[1],x[2]))
		if not pq.empty() :
			y = pq.get()
			y.lecture = y.lecture - 1
			if y.lecture > 0 :
				pq.put(y)
	while not pq.empty() :
		x = pq.get()
		ans = ans + x.lecture * x.sadness
	print ans

