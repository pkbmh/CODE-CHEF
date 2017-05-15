t = int(input())
for i in range(0,t) :
	s = str(input())
	l = len(s)
	j = 0
	while (j < l and s[j] == 'C') :
		j = j + 1
	while(j < l and s[j] == 'E') :
		j = j + 1
	while(j < l and s[j] == 'S') :
		j = j + 1
	if j == l :
		print('yes')
	else :
		print('no')

