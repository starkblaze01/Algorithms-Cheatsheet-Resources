import numpy as np 		# Contains the method to calculate Standard Deviation

def fcfs(process):

	case = int(input('Without Interrupt (1) or With Interrupt (2): '))

	# If the relative arrival time is 0 this sort according to priority
	for i in range(1, len(process)):
		if process[i][1] == '0':
			if process[i][5] < process[i - 1][5]:
				j = i
				while process[j][5] < process[j - 1][5] and j >= 1:
					process[j], process[j - 1] = process[j - 1], process[j]
					j-=1

	# Case for without interrupt
	if case == 1:

		print('Process\tTurnaround Time\t\tWaiting Time\tCompletion Time')
		print(process[0][0], "\t\t", int(process[0][2]) - int(process[0][1]), "\t\t\t", 0, "\t\t", int(process[0][2]) + int(process[0][1]))

		arrivalTime = 0												# Arrival Time of every process
		completionTime = int(process[0][2])						# Overall completion time
		turnAround = [int(process[0][2]) - int(process[0][1])] 		# Stores Turnaround time of every process
		waiting = [0]												# Stores Waiting Time of every process

		for i in range(1, len(process)):
			arrivalTime += int(process[i][1])															# Arrival time of the current process
			completionTime = int(completionTime + max(0,int(process[i][1])- int(process[i-1][2]))+int(process[i][2]))		# Completion time of the current process
			#totalCompletion += int(process[i][2])														# Total completion time till current process
			turnAroundTime = completionTime - arrivalTime												# Turnaround Time of the current process
			turnAround.append(turnAroundTime)															# Adding Turnaround time of the current process to the list
			waiting.append(max(0, turnAroundTime - int(process[i][2])))									# Adding waiting time of the current process to the list
			print(process[i][0], "\t\t", turnAroundTime, "\t\t\t", waiting[i], "\t\t", completionTime)
		
		print('Average Waiting Time : ', sum(waiting) / len(waiting))									# Printing average waiting time
		print('Standard Deviation of Turnaround Time : ', np.std(turnAround))							# Printing Standard Deviation of the Turnaround time

	# Case for with interrupt
	elif case == 2:

		print('Process\tTurnaround Time\t\tWaiting Time\tCompletion Time')
		print(process[0][0], "\t\t", int(process[0][2]) + float(process[0][3]) + float(process[0][4]) - int(process[0][1]), "\t\t\t", float(process[0][3]) + float(process[0][4]), "\t\t", int(process[0][2]) + float(process[0][3]) + float(process[0][4]) + int(process[0][1]))

		arrivalTime = 0																							# Arrival Time of every process
		completionTime = int(process[0][2]) + float(process[0][3]) + float(process[0][4])						# Overall completion time
		turnAround = [int(process[0][2]) + float(process[0][3]) + float(process[0][4]) - int(process[0][1])]	# Stores Turnaround time of every process
		waiting = [float(process[0][3]) + float(process[0][4])]													# Stores Waiting Time of every process

		for i in range(1, len(process)):
			arrivalTime += int(process[i][1])																											# Arrival time of the current process
			completionTime = float(completionTime + max(0,int(process[i][1])-int(process[i-1][2]) - float(process[i-1][3]) - float(process[i-1][4])) + float(process[i][2]) + float(process[i][3]) + float(process[i][4]))		# Completion time of the current process
			turnAroundTime = completionTime - arrivalTime																								# Turnaround Time of the current process
			turnAround.append(turnAroundTime)																											# Adding Turnaroud time of the current process to the list
			waiting.append(max(0, turnAroundTime - (int(process[i][2]))))																				# Adding waiting tiem of the current process to the list
			print(process[i][0], "\t\t", turnAroundTime, "\t\t\t", waiting[i], "\t\t", completionTime)
		
		print('Average Waiting Time : ', sum(waiting) / len(waiting))																					# Printing average waiting time
		print('Standard Deviation of Turnaround Time : ', np.std(turnAround))																			# Printing Standard Deviation of the Turnaround time

	# Case for invalid input
	else:
		print('Invalid Input\nGive Valid input')
		fcfs(process)
