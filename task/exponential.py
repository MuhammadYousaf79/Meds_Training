import time
import math

def fact(n):
	a = 1
	for j in range(1,n+1):
		a =  a * j
	return a

def exponential(expi, terms=20):
	r = 0
	for i in range(terms):
		r = r + ((expi ** i) / fact(i))
	return f"The exponential of {expi} is {r}"

b = int(input("Enter number : "))
r1 = exponential(b)
print(f"{math.exp(b)}")
print(f"The exponential of {b} is {r1}")


time.sleep(10)