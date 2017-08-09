t = int(raw_input())
for i in range(t) :
	str = raw_input()
	str = str.title()
	str = str.split()
	tmp = map(lambda x : x[0]+'.', str[:len(str)-1])
	tmp.append(str[len(str)-1])
	print ' '.join(tmp)