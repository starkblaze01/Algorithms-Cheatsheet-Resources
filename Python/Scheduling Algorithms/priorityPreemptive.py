from prettytable import PrettyTable


pid = [int(x) for x in input('Enter the process ids: ').split()] #Should be consecutive starting with 1
burst = [int(x) for x in input('Enter the burst time: ').split()] #Space seprated int values
arrival = [int(x) for x in input('Enter the arrival time: ').split()] #Space seprated int values
priority = [int(x) for x in input('Enter the priority: ').split()] #Space seprated int values (low value high priority)

table = PrettyTable(['Process Id','Burst Time','Arrival Time','Priority'])
n = len(pid)
for i in range(n):
    table.add_row(['P'+str(pid[i]),burst[i],arrival[i],priority[i]])

print('\nInput Table\n')
print(table)
print('\n')

arr = list(zip(pid,burst,arrival,priority))
arr = sorted(arr,key=lambda x: x[2])

tt = [None]*n
time = 0
ready_queue = [['P'+str(arr[0][0]),arr[0][1],arr[0][3]]]
timeline = [[ready_queue[0][0],time]]
prev = ready_queue[0]
ind = 1

while len(ready_queue) > 0 or ind < n:
    if (ind < n) and (arr[ind][2] == time):
        ready_queue.append(['P'+str(arr[ind][0]),arr[ind][1],arr[ind][3]])
        ready_queue = sorted(ready_queue,key=lambda x: x[2])
        ind+=1

    curr = ready_queue.pop(0)
    if prev != curr:
        timeline.append([curr[0],time])
    curr[1] -= 1
    if curr[1] >0:
        ready_queue.insert(0,curr)
    else:
        id = int(curr[0][-1])-1
        tt[id] = time - arrival[id] + 1 
    prev = curr
    time+=1

wt = []
for i in range(n):
    wt.append(tt[i]-burst[i])

print(f'Timeline: {timeline}')

head = [" "]
for i in range(n):
    head.append('P'+str(pid[i]))
table = PrettyTable(head)
table.add_row(['Waiting Time: ']+wt)
table.add_row(['TurnAround Time: ']+tt)

print(f'\n{table}\n')
print(f'Average Waiting Time: {sum(wt)/n}')    
print(f'Average Turnaround Time: {sum(tt)/n}')    