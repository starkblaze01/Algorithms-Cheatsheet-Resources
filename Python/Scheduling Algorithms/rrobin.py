import pandas as pd
import warnings
import numpy as np
import copy as cp
import matplotlib.pyplot as plt
warnings.filterwarnings("ignore")
def round_robin():

    df = pd.read_csv("input.csv") # Reading the c.s.v file using pandas library

    arrival_time = df['Arrival_time']

    print("Enter complex or simple case")
    case = input()
    if case == "simple":
        burst_time = df['Execution']
    elif case == "complex":
        burst_time = df['Execution'] + df['i'] + df['io']

    # Add the arrival times with previous value to get the absolute time
    for values in range(1,len(df)):
        arrival_time[values] = arrival_time[values] + arrival_time[values - 1]

    # Sort the data frame w.r.t arrival time
    df = df.sort_values('Arrival_time')

    index = [] # Array of indices used for plotting later
    turnaround_array = [] # Stores the turn around values for each process
    wait_array = [] # Stores the wait time for each process
    avg_wait_array = [] # Store the average wait time for various quantum time

    print("Process_Id\tWait_time\tTurnaroundtime")

    for quantam in range(1, 100):

        remaining = len(df) # Number of unfinished processes
        flag = 0
        wait_time = 0
        turnaround_time = 0
        time = 0 # Total time progress
        count = 0 # Counter to iterate through processes
        remain_time = cp.copy(burst_time) # Initially the remaining time is equal to burst time
        while remaining != 0:
            # The process ends before the quantum time
            if remain_time[count] <= quantam and remain_time[count] > 0:
                time += remain_time[count] # Add remain time to the elapsed time
                remain_time[count] = 0
                flag = 1 # The process has finished

            # The remain time is greater than quantum
            elif remain_time[count] > 0:
                remain_time[count] -= quantam
                time += quantam # Add the quantum to elapsed time

            # If a process has just finished...
            if remain_time[count] == 0 and flag == 1:
                remaining -= 1 # Decrement the unfinished process
                if case == "simple":
                    wait_time = time - arrival_time[count] - burst_time[count]
                elif case == "complex":
                    wait_time = time - arrival_time[count] - burst_time[count] + df['io'][count] + df['i'][count]
                turnaround_time = time - arrival_time[count]

                if quantam == 2:
                    print("P[%d]\t|\t%d\t|\t%d" % (count + 1, wait_time, turnaround_time))
                    turnaround_array.append(turnaround_time)  # Append the turnaround time to turnaround array

                wait_array.append(wait_time) # Append the wait time to wait time array

                flag = 0

            # All the processes have arrived
            if count == len(df)-1:
                count = 0 # Set count to zero and iterate again to finish the unfinished processes

            # If next process has arrived before the current process has finished
            elif arrival_time[count + 1] <= time:
                count += 1 # Schedule the next process after the initial quantum

            # If the current process has finished but next process hasn't arrived wait for it while
            # you finish the previous unfinished process
            else:
                count = 0
                time = time + 1
        # Calculate and store average wait times in an array
        avg_wt = sum(wait_array)/len(df)
        avg_wait_array.append(avg_wt)

        # Store indexes for plotting later
        index.append(quantam)

        # Empty these arrays after processing for each quantum
        wait_array = []


    print("The standard deviation is:")
    print(np.std(np.array(turnaround_array)))
    plt.plot(index, avg_wait_array)
    plt.show()
