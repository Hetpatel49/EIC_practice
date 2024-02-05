#leapyear check for integer input
def main():
	try:
		year=int(input("Enter a year between 1900-100000:"))
		assert year>=1900 and year<=100000

	except ValueError:	#error for input only in integer
		print("Error: Enter a valid year")

	except AssertionError:	#error for assertion statement
		print("Error: Year must be in-between 1900-100000")

	else:
		#starting condition check from highest priority 
		if year%400==0:
			print(True)
		elif year%100==0:
			print(False)
		elif year%4==0:
			print(True)
		else:
			print(False)

if __name__=='__main__':
	main()
