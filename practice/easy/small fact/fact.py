
t = int(raw_input())
a = [0 for x in range(0,101)]

a[0] = 1

for i in range(1,101):
	a[i] = i*a[i-1]

for i in range(0,t):
	n = int(raw_input())
	print a[n]

