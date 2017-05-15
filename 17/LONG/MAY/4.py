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

instr = input()
n,k,q = map(int,instr.split(' '))
s = input()
s = s.replace(' ', '')
qs = input()
i = int(0)
sl = len(s)
mx = int(0)
lq = len(qs)

count1 = s.count('1')
if(k >= n):
	for j in range(0,lq) :
			if(qs[j] == '?'):
				print(count1)
else:
	pq = Q.PriorityQueue()
	cnt = int(0)
	i = n-1
	while(i >= 0 and i >= n-k):
		cnt = cnt + int(s[i])
		i = i - 1;
	x = 0;
	pq.put(Pair(cnt,x))
	x = x + 1
	while(i >= 0):
		cnt = cnt + int(s[i])
		cnt = cnt - int(s[i+k])
		i = i - 1
		pq.put(Pair(cnt,x))
		x = x + 1
	qcnt = int(0)
	for j in range(0,lq):
		if(qs[j] == '?'):
			while(not pq.empty()):
				p = pq.get()
				if(p.second >= qcnt):
					print(p.first)
					pq.put(p)
					break
		else:
			s = s[n-1] + s
			cnt = cnt + int(s[0])
			cnt = cnt - int(s[k])
			pq.put(Pair(cnt,x))
			x = x + 1
			qcnt = qcnt + 1