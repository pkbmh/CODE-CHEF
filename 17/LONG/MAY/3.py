t = int(input())
for i in range(0,t) :
	n = int(input())
	mid_ind = int(n / 2 + 1)
	n = n * 2
	line = input()
	arr = list(map(int, line.split(' ')))
	arr.sort()
	ans = arr[int(n/2+mid_ind-1)]
	i = 0
	j = n-1
	while(i < j) :
		tmp = arr[i]
		arr[i] = arr[j]
		arr[j] = tmp
		i = i + 2
		j = j - 2
	print(ans)
	print(" ".join(str(s) for s in arr))

