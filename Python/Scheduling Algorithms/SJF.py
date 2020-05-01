from operator import itemgetter				# itemgetter used to sort as per list parameter        
import copy									# copy used to copy list's column
import numpy as np							# numpy used to calculate std deviation and transposing of row
import sys									# sys used to give the sysmaxsize	
def sjf(p):					  # p is a 2D list	
    n = len(p)                # n stores the total no. of processes
    complete = 0 			  # no. of completed processes							
    t = 0                     # intteger to represent time passed in sec
    minm = sys.maxsize         # minm used to store the shortest remaining time (r[t]) 
    shortest = 0	          # stores the index of the process with least remaining time  	
    check = False             # when no process has started execution and t is increementing      
    art = [0]*n               # list to store the arrival time 
    wt = [0]*n				  # list to store the waiting time 	 
    wt = np.transpose(wt)  	  # wt converted to column for simplicity (it is being added with tmp[] to give tat[]  and temp is a column)  	
    p[0][1] = float(p[0][1])  # converting first arrival time to float
    idle = 1                  # flag to show when the cpu is idle (1 when cpu is idle )
    for i in range(n):
        if i!=0:                                             # as arriaval time is relative   
            p[i][1] = float(p[i][1]) + float(p[i-1][1])      # we are cummulating the arrival time 
    p = sorted(p,key=itemgetter(5))		                     # sorting the 2D list p , using priority (indexed - 5)	
    x = input("Enter Choice : general or complex  ----- ")   # general case or comples case 
    if x == "general" or x == "GENERAL":
        rt = [float(row[2]) for row in p]                    # rt copying the values of column 2 i.e burst time     
    else :                                              
        burst   = np.transpose([float(row[2])  for row in p])    
        elapsed = np.transpose([float(row[3]) for row in p])     
        w_p    =  np.transpose([float(row[4])  for row in p])
        rt = burst + elapsed + w_p                  # remaining time (r[t] ) = burst time + elapsed time + time spent waiting  
    temp = copy.copy(rt)                            # temp is used to store the initial value of rt[]            
    # Run until all processes gets                             
    # completed
    while (complete != n): 
        # Find process with minimum
        # remaining time among the
        # processes that arrives till the
        # current time
        for j in range(n):                                       
            if p[j][1]<= t and rt[j] < minm and rt[j] > 0: 
                minm = rt[j]                    
                shortest = j                          
                idle = 0
                check = True                
        
        if check == False:                  # when no process is started , increement t
            t = t + 1
            continue
        
        # Reduce remaining time by one
        if rt[shortest]>0 :
            rt[shortest] = rt[shortest] - 1
        else:
            idle = 1                          # if rt[shortest] is not decreementing then cpu is idle  
        # Update minimum if not idle
        if not idle:                       
            minm = rt[shortest]    
        if (minm == 0):                       # if minm = 0 then rt[shortest ]  = 0  then restore max value in minm
            minm = sys.maxsize                
        # If a process gets completely
        # executed
        if (rt[shortest] == 0 and not idle):  # when rt[shortest ] is 0 and cpu is not idle - then a process has just completed
            # Increment complete
            complete = complete + 1             
            # Find finish time of current      
            # process
            finish_time = t + 1
 
            # Calculate waiting time
            wt[shortest] = finish_time - temp[shortest] - p[shortest][1]    
            if wt[shortest] < 0:
                wt[shortest] = 0
        # Increment time
        t = t + 1
        idle = 0        # reset idle = 0
    tat = wt + temp     # turnaround time = waiting time + run time (run time is the original value of remaining time i.e temp) 
    print("Process Id" ,"Waiting time","TurnAroundTime") 
    if x == "general" or x == "GENERAL":                        #for general case
        for i in range(n):
            print(p[i][0],"         ",wt[i] ,"          ",tat[i])    
    else:                                                         #for complex case  
        for i in range(n):
            print(p[i][0],"         ",wt[i] + elapsed[i] + w_p[i] ,"          ",tat[i])
    avg = sum(tat)/n														 #average time of turnaround 
    print("Average Completion Time  : ",avg)                                
    print("The Standard Deviation of completion is ",np.std(np.array(tat)))  # standard deviation of turnaround calculated using numpy     
