from prettytable import PrettyTable
x = PrettyTable()

pid = list((input("Enter process ids: ").split()))
burst = list(map(int, input("Enter the burst time: ").split()))
priority = list(map(int, input("Enter the priority: ").split()))

# Assumption: All processes arrive at time 0

for i in range(0, len(priority)):
    for j in range(i, len(priority)):
        if priority[j] < priority[i]:
            priority[j], priority[i] = priority[i], priority[j]
            pid[j], pid[i] = pid[i], pid[j]
            burst[j], burst[i] = burst[i], burst[j]

print("\n\nGANTT CHART\n")
print("|", end="")
print("----------"*len(pid), end="")
print("|")
for i in pid:
    print("|   "+i+"    ", end="")
print(" |\n|", end="")
print("----------"*len(pid), end="")
print("|")

wt = [0]

for i in range(len(pid)):
    wt.append(wt[i] + burst[i])

tt = []
for i in range(len(pid)):
    tt.append(wt[i] + burst[i])

for i in range(len(wt)):
    print(wt[i], end="         ")

print("\n\n")
x.field_names = ["Process id", "Burst time",
                 "Priority", "Waiting time", "Turnaround time"]
for i in range(len(pid)):
    x.add_row([pid[i], burst[i], priority[i], wt[i], tt[i]])
print(x)

avg_wt = (sum(wt)-wt[-1])/len(pid)
print("\nThe average waiting time will be "+str(avg_wt)+"ms")
avg_tt = sum(tt)/len(pid)
print("Average turn around time:", avg_tt)
