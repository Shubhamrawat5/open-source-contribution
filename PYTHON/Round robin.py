from prettytable import PrettyTable

pid = [int(x) for x in input('Enter the process ids: ').split()]
burst = [int(x) for x in input('Enter the burst time: ').split()]
table = PrettyTable(['Process Id', 'Burst Time'])

# Assumption: All processes arrive at time t=0

n = len(pid)
timeQuantum = int(input("Enter the time quantum: "))
print('\n')

queue = []

for i in range(n):
    queue.append(['P'+str(pid[i]), burst[i]])

t = 0
gantt = []
wt = [0]*n
tt = [0]*n
while queue:
    t += timeQuantum
    process_id, process_b = queue.pop(0)
    process_burst = process_b - timeQuantum
    if process_burst > 0:
        queue.append([process_id, process_burst])
        gantt.append([process_id, timeQuantum])
    else:
        tt[int(process_id[1:])-1] = t + process_burst
        t += process_burst
        gantt.append([process_id,process_b])

for i in range(len(tt)):
    wt[i] = tt[i] - burst[i]


print("GANTT CHART\n")
print("|", end="")
print("----------"*len(gantt), end="")
print("|")
for i in gantt:
    print("|   "+str(i[0])+"    ", end="")
print(" |\n|", end="")
print("----------"*len(gantt), end="")
print("|")
print(0,end="         ")
s = 0
for i in gantt:
    s = s+i[1]
    print(s, end=" "*(10-len(str(s))))
print("\n")

table = PrettyTable()
table.field_names = ["Process id", "Burst time",
                     "Waiting time", "Turnaround time"]
for i in range(len(pid)):
    table.add_row([pid[i], burst[i], wt[i], tt[i]])
print(table)

print('\nThe average waiting time is:', sum(wt))
