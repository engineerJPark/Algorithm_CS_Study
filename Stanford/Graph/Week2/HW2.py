'''
1에서 다른 모든 vertex와의 최단 거리를 구하라. 경로가 없는 경우에는 1000000로 둔다.



다익스트라 가는 길목마다 그 최소경로를 기록하면 된다. 어차피 Greedy 알고리즘이라.
'''

import copy

from numpy import TooHardError

fd = open('Stanford\Graph\Week2\dijkstraData.txt', 'r')
text_file = fd.readlines()

text_array = []
text_array += [text.strip('\n').split('\t')[:-1] for text in text_file]
# print(text_array)

int_array = []
for j in range(len(text_array)):
    for i in range(len(text_array[j])):
        if i == 0:
            int_array += [[int(text_array[j][i])]]
        else:
            temp = text_array[j][i].split(',')
            int_array += [[int(temp[0]), int(temp[1])]]
print(int_array)

# 전역변수 선언. 모든 최소 거리 1000000로 정의. 1에서 부터의 최소경로
processed_vertices = [False for i in range(len(int_array) + 1)] # 시작점 1로 변경
shortest_len = [1000000 for i in range(len(int_array) + 1)]
shortest_len[1] = 0

# 다익스트라
temp_len = []
vertex1 = 1
vertex2 = 0
while False in processed_vertices:
    temp_len = []
    temp_processed_vertices = []
    processed_vertices[vertex1] = True
    for i in range(1, len(int_array[vertex1])):
        temp_len.append(shortest_len[vertex1] + int_array[vertex1][i][1])
    print(temp_len)
    idx = min(range(len(temp_len)), key=lambda x: temp_len[x])
    shortest_len[vertex2] = shortest_len[vertex1] + int_array[vertex1][idx][1]
    vertex2 = int_array[vertex1][idx][0]

    vertex1 = vertex2
    vertex2 = 0
    temp_len = []
    

# 실행
print(shortest_len)