import numpy as np
import tabulate
import matplotlib.pyplot as plt


def display(data):
    print("ProcessID\tArrival Time\tBurst Time")
    for i in range(len(data)):
        print("{}\t\t{}\t\t{}".format(
            data[i][0], data[i][1], data[i][2]))
    print("\n")


def change(processInOrder, arrived):
    for i in range(len(processInOrder)):
        if processInOrder[i][0] == arrived[0][0]:
            processInOrder[i][2] = processInOrder[i][2] - 1
            break


def printGanttChart(RunningQueue):
    finalTimeLine = list(list())
    j = 0
    for i in range(len(RunningQueue)):
        if RunningQueue[j][0] != RunningQueue[i][0] or i == len(RunningQueue) - 1:
            if i == len(RunningQueue) - 1:
                finalTimeLine.append(RunningQueue[i])
            else:
                finalTimeLine.append(RunningQueue[i - 1])
            j = i
    return finalTimeLine


def IndividualValues(l, heading):
    print(f"\n{heading}")
    for i in range(len(l)):
        print(f"{l[i][0]} : {l[i][1]}")
    print("\n")


n = 4
processInOrder = [['P1', 3, 1], ['P2', 0, 1], ['P3', 2, 5], ['P4', 3, 2]]

copyProcessInOrder = list(list())
for j in range(len(processInOrder)):
    copyProcessInOrder.append(processInOrder[j].copy())

processName = list()
for i in range(len(processInOrder)):
    processName.append(processInOrder[i][0])
print(tabulate.tabulate(processInOrder, headers=[
    "ProcessID", "Arrival Time", "Burst Time"], tablefmt="fancy_grid"))
print()

readyQueue = list(list())
RunningQueue = list(list())
processInOrder.sort(key=lambda x: x[1])
if processInOrder[0][1] == 0:
    processInOrder[0][2] -= 1
    time = 1
    RunningQueue.append([processInOrder[0][0], time])
else:
    time = processInOrder[0][1]
    RunningQueue.append([processInOrder[0][0], time])
# processInOrder[0][2] -= 1

flag = True
while len(processInOrder) > 0:
    readyQueue = list(list())
    arrived = list(list())
    for j in range(len(processInOrder)):
        if processInOrder[j][1] <= time:
            arrived.append(processInOrder[j])
            readyQueue.append(processInOrder[j].copy())
            flag = False
    arrived.sort(key=lambda x: x[2])
    if len(arrived) > 0:
        if arrived[0][2] > 0:
            time += 1
            change(processInOrder, arrived)
            RunningQueue.append([arrived[0][0], time])
        else:
            processInOrder.remove(arrived[0])
    else:
        time += 1
    check = True
    for t in range(len(readyQueue)):
        if readyQueue[t][2] == 0:
            check = False
            break
    if check:
        print(f"Time {time - 1} : {readyQueue}")
    flag = True

table = tabulate.tabulate(RunningQueue, headers=[
                          "Process", "Time"], tablefmt="fancy_grid")
print(table)

copyRunningQueue = RunningQueue.copy()
copyRunningQueue.reverse()

completionTime = list(list())
for i in range(len(processName)):
    for j in range(len(copyRunningQueue)):
        if processName[i] == copyRunningQueue[j][0]:
            completionTime.append([processName[i], copyRunningQueue[j][1]])
            break

turnAroundTime = list(list())
for i in range(len(copyProcessInOrder)):
    turnAroundTime.append(
        [copyProcessInOrder[i][0], completionTime[i][1] - copyProcessInOrder[i][1]])


waitingTime = list(list())
for i in range(len(copyProcessInOrder)):
    waitingTime.append(
        [copyProcessInOrder[i][0], turnAroundTime[i][1] - copyProcessInOrder[i][2]])

finalTime = list(list())
for i in range(len(copyProcessInOrder)):
    finalTime.append(
        [copyProcessInOrder[i][0], turnAroundTime[i][1], waitingTime[i][1], completionTime[i][1]])

print(tabulate.tabulate(finalTime, headers=[
    "ProcessID", "TurnAround Time", "Waiting Time", "Completion Time"], tablefmt="fancy_grid"))
print("Average Waiting Time : " +
      str(sum(list(map(lambda x: x[1], waitingTime))) / len(waitingTime)))

print("Average Turn around Time : " +
      str(sum(list(map(lambda x: x[1], turnAroundTime))) / len(turnAroundTime)))

print("Average Completion Time : " +
      str(sum(list(map(lambda x: x[1], completionTime))) / len(completionTime)))


fig, gnt = plt.subplots()
gnt.set_ylim(0, n*10)
gnt.set_xlim(0, len(RunningQueue), 1)
gnt.set_xlabel('Time in Seconds')
gnt.set_yticks([10, 20, 30, 40])
gnt.set_ylabel('Process')
gnt.set_yticklabels(processName)
gnt.grid(True)
finalTimeLine = printGanttChart(RunningQueue)
yAxisMeasurements = list(list())
for i, j in zip(range(n), range(n)):
    yAxisMeasurements.append([processName[i], j*10])
for i in range(len(finalTimeLine)):
    for j in range(len(yAxisMeasurements)):
        if yAxisMeasurements[j][0] == finalTimeLine[i][0]:
            if i != 0:
                gnt.broken_barh([(finalTimeLine[i - 1][1], finalTimeLine[i]
                                [1] - finalTimeLine[i - 1][1])], (yAxisMeasurements[j][1], 10), facecolors=('tab:orange'))
            else:
                gnt.broken_barh([(0, finalTimeLine[i][1])],
                                (yAxisMeasurements[j][1], 10), facecolors=('tab:orange'))
print(finalTimeLine)
plt.show()
