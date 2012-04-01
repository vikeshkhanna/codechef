'''
Algorithm [from editorial]
A1,A2...Ak - Generate all paritions of n (distinct, unordered)
Find B(i) = number of occurences of i in the parition.
Number of occurences of cos(A1*x/n)...cos(Ak*x/n) = M!/(B1!*B2!...Bk!)*(M-k)! because cos(0) = 1 and note the permutations with identical items (0 and B(i))
Sum up for all paritions.
'''
import math

'''
def partitions(n):
	# base case of recursion: zero is the sum of the empty list
	if n == 0:
		yield []
		return
		
	# modify partitions of n-1 to form partitions of n
	for p in partitions(n-1):
		yield [1] + p
		
		if p and (len(p) < 2 or p[1] > p[0]):
			yield [p[0] + 1] + p[1:]
				
def fact(n):
	if n<=1:
		return 1
	else:
		return n * fact(n-1)
		
'''

def partitions(n):
	a = [0 for i in range(n + 1)]
	k = 1
	a[0] = 0
	a[1] = n
	while k != 0:
		x = a[k - 1] + 1
		y = a[k] - 1
		k -= 1
		while x <= y:
			a[k] = x
			y -= x
			k += 1
		a[k] = x + y
		yield a[:k + 1]
		
t = int(raw_input())
		
def f(m,n,x):
	#Generate all partitions of n
	sum = 0
	
	for p in partitions(n):
		if len(p) <= m :
			#find duplicate entries
			k = len(p)
			b = [p.count(i) for i in range(k+1)] 
			prod = 1.0
			
			for i in range(k):
				prod = (prod * (m-i)* math.cos(p[i]*float(x)/n))/float(fact[b[i+1]])
			
			sum = sum + prod
			
	return sum

fact = [1 for i in range(31)]

for i in range(2,31):
		fact[i] = i * fact[i-1]
	
for T in range(t):
	s = raw_input()
	input = s.split(' ')
	m = int(input[0])
	n = int(input[1])
	x = float(input[2])
	
	print "%.10f"%f(m,n,x)