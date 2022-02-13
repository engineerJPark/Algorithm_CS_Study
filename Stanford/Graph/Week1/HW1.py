'''
###############################################################
TODO

###############################################################

가장 큰 5 개의 SCC를 출력하라.

거꾸로 -> finishing time으로 node 명명 -> 다시 DFS해서 leader 구하긴

DFS_LOOP(G)
    global t = 0 # finishing time
    global s = NULL # leaders

    for i = n to 1:
        if i not explored:
            s = i
            DFS(G, i)

DFS(G, i)
    mark i explored
    leader(i) = s
    for each arc(i, j) in G:
        if j not explored
            DFS(G, j)
    t += 1
    set f(i) = t # finishing time record
'''

import copy

from numpy import TooHardError

fd = open('C:/Users/jshac/OneDrive/Desktop/TIL/CS_Study/Algorithm_Data_Structure/Stanford/Graph/Week1/SCC.txt', 'r')
text_file = fd.readlines()

text_array = []
text_array += [text.strip('\n') for text in text_file]
# print(text_array)

row_array = []
row_array += [row.split() for row in text_array]
# print(row_array)

int_array = []
int_array += [list(map(int, i)) for i in row_array]
# print(int_array)

def swap(arr):
    temp = arr[0]
    arr[0] = arr[1]
    arr[1] = temp
    return arr

def DFS(G, i):
    global recorder
    global leader
    global leaders
    global finishing
    global finishing_time
    recorder[i] = True
    leaders[i] = leader
    for i_G in range(len(G)):
        if G[i_G][0] == i and recorder[G[i_G][1]] == False:
                DFS(G, G[i_G][1])
    finishing += 1
    finishing_time[i] = finishing
    
G_reverse = copy.deepcopy(int_array)
G_reverse = list(map(swap, G_reverse))
G_reverse.sort()
num_node = 875714
finishing = 0
leader = 0
recorder = []
recorder += [False for i in range(875714 + 1)]
leaders = []
leaders += [0 for i in range(875714 + 1)]
finishing_time = []
finishing_time += [0 for i in range(875714 + 1)]

# reverse pass
for i in range(875714, 0, -1): # i is node
    if recorder[i] == False:
        leader = i
        DFS(G_reverse, i)

G = copy.deepcopy(int_array)
num_node = 875714
finishing = 0
leader = 0
recorder = []
recorder += [False for i in range(875714 + 1)]
leaders = []
leaders += [0 for i in range(875714 + 1)]
# node number to finishing time
for i, G_part in enumerate(G):
    G_part[0], G_part[1] = finishing_time[G_part[0]], finishing_time[G_part[1]]
    G[i] = [G_part[0] + G_part[1]]
G.sort()

# forward pass
for i in range(875714, 0, -1): # i is node
    if recorder[i] == False:
        leader = i
        DFS(G, i)

# print(largest leader5...)
leaders.sort()
count = 1
max_num = max(leaders)
print(max_num)
for i in range(len(leaders)):
    if max(leaders) < max_num :
        max_num = max(leaders)
        print(max_num)
        count += 1
    leaders.pop()
    if count == 5:
        break