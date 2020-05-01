# Importing function from files
from SJF import sjf
from fcfs import fcfs
from rrobin import round_robin as rr


# Function to read and parse process data
def readFile():
	p = []	# List that stores parsed process data(string)
	x = input("Enter file name ")	# File containing dataset

	process = []	# Array to store raw processes data

	# Try opening the input file
	try:
		with open(x, "r") as f:
			process = f.read().splitlines() # Split each line from the file and append to process
	except:	# Exception handling to when file reading fails
		print("Error opening file")
		exit()

	n = len(process) # length of process list
	for i in range(n):
		p.append(process[i].split(' '))	# Splitting each process line in terms of spaces

	f.close()	# Closing the input file
	return p 	# Return the parsed process data list
	
# Loop to iterate infinitely and execute processes as per given operation
while(True):
	print("Enter required operation")
	print("1: FCFS", "2: SJF", "3: RR", "4:EXIT", sep='\n')
	cmd = input()
	if cmd == '1':
		fcfs(readFile())
	elif cmd == '2':
		sjf(readFile())
	elif cmd == '3':
		rr()
	else: exit()

