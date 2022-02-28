import copy

from numpy import TooHardError

fd = open('Stanford\Graph\Week2\dijkstraData.txt', 'r')
text_file = fd.readlines()

text_array = []
text_array += [text.strip('\n').split('\t')[:-1] for text in text_file]
# print(text_array)

int_array = [[[0]]]
temp_array = []
for j in range(len(text_array)):
    temp_array.append([int(text_array[j][0])])
    for i in range(1, len(text_array[j])):
        temp = text_array[j][i].split(',')
        temp_array.append([int(temp[0]), int(temp[1])])
    int_array.append(temp_array)
    temp_array = []
print(int_array)