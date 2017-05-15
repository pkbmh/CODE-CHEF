import bisect
n,k = map(int,input().split(' '))
line = input()
arr = list(map(int,line.split(' ')))
part1 = int(n / 2)
part2 = n-part1
arr1 = []
arr2 = []

for i in range(0,part1):
	arr1.append(arr[i])
for i in range(part1,n):
	arr2.append(arr[i])

sz1 = 1<<part1
sz2 = 1<<part2
set_part1 = []
set_part2 = []

for i in range(1,sz1):
	mul = 1
	for j in range(0,part1):
		if((i&(1<<j)) != 0):
			mul = mul * arr1[j]
	if(mul <= k):
		set_part1.append(mul)

for i in range(1,sz2):
	mul = 1
	for j in range(0,part2):
		if((i&(1<<j)) != 0) :
			mul = mul * arr2[j]
	if(mul <= k):
		set_part2.append(mul)


set_part1.sort()
set_part2.sort()
l = len(set_part1)
ans = len(set_part1) + len(set_part2)
for i in range(0,l):
	ind = bisect.bisect_right(set_part2,int(k/set_part1[i]))
	ans = ans + ind

print(ans)