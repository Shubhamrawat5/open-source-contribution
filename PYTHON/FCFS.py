from prettytable import PrettyTable
x = PrettyTable()

pid = list(map(int, input("Enter process ids: ").split()))
arrival = list(map(int, input("Enter arrival time: ").split()))
burst = list(map(int, input("Enter the burst time: ").split()))

for i in range(len(pid)-1):
    for j in range(i, len(pid)):
        if arrival[j] < arrival[i]:
            pid[j], pid[i] = pid[i], pid[j]
            arrival[j], arrival[i] = arrival[i], arrival[j]
            burst[j], burst[i] = burst[i], burst[j]

ct = 0
wt = [0]*len(pid)
for i in range(len(pid)):
    if arrival[i] <= ct:
        wt[i] = ct - arrival[i]
        ct = ct + burst[i]
    else:
        wt[i] = 0
        ct = arrival[i] + burst[i]
# wt = [0]

# for i in range(len(pid)-1):
#     wt.append(wt[i] + burst[i])

tt = []
for i in range(len(pid)):
    tt.append(wt[i] + burst[i])

x.field_names = ["Process id", "Burst time", "Waiting time", "Turnaround time"]
for i in range(len(pid)):
    x.add_row([pid[i], burst[i], wt[i], tt[i]])
print(x)

avg_wt = sum(wt)/len(pid)
print("Average waiting time:", avg_wt)
avg_tt = sum(tt)/len(pid)
print("Average turn around time:", avg_tt)
