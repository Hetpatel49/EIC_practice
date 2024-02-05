import re

def main():

	listofemail=[]	#A list to store all emails 
	validemaillist=[]	#A list to store only valid emails

	try:
	    N=int(input("Enter the number of emails:"))
	    assert N>0,"value less than 1"	#error for negative or zero email validation
	    print("Enter {} email(s):".format(N))
	    for i in range(N):
	        s=input()
	        listofemail.append(s)

	#exception handling
	except ValueError:
	    print("Error: Enter a valid integer number")

	#else section execution only when valid inputs have given

	else:
	#   defining regular expression for valid email
	    regex = r'\b[A-Za-z0-9-_]+@[A-Za-z0-9]+\.[A-Za-z]{1,3}\b'
    
	    for email in listofemail:
	        if(re.match(regex,email)):
	            validemaillist.append(email)
    
	    validemaillist.sort() 
	    print("Valid emails list:",validemaillist)

if __name__=='__main__':
	main()
