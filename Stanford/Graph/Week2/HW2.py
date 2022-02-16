'''
1에서 다른 모든 vertex와의 최단 거리를 구하라. 경로가 없는 경우에는 1000000로 둔다.
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

# 모든 최소 거리 1000000로 정의. 1에서 부터의 최소경로
shortest_len = [1000000 for i in range(len(int_array))]

# 다익스트라 함수
def dijkstra():
    

# 실행
