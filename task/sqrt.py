def square_root(number, epsilon= 0.00001):
	if number < 0:
		return f"ERROR: cannot compute square root of a negative number."

	guess = number / 2
	
	while abs(guess * guess - number) > epsilon:
		guess = (guess + number / guess ) / 2
	
	return f"The square root of {number} is {guess}"

n = float(input("Enter number : "))
print(square_root(n))
