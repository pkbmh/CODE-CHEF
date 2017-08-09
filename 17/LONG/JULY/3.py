t = int(raw_input())
for i in range(t) :
	n,b = raw_input().split()
	n = int(n)
	b = int(b)
	if(b > n) :
		print 0
	else :
		x = (n-b) / 2
		print 'x' ,x
		print x * (n-x) / b
