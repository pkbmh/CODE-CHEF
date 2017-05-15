
t = int(input())

for i in range(0,t) :
	n = int(input())
	x = input()
	arr = list(map(int,x.split(' ')))
	# arr = list(map(int, input.split()))
	print(n-max(arr))
