import sys

def gcd(r0,r1):
	if r0<r1:
		temp=r0
		r0 = r1
 		r1 = temp
        
        rem = r0%r1
	r0 = r1
	r1 = rem
		
	while rem!=0:
		rem = r0%r1
		r0 = r1
		r1 = rem
	return r0

t = raw_input();

for i in range(0,t):
