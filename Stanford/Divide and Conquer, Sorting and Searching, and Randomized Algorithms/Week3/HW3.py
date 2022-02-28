import statistics

# txt open and pre processing
fd = open('QuickSort.txt', 'r')
text_array = fd.readlines()
for idx, text in enumerate(text_array):
    text_array[idx] = text.strip('\n')
fd.close()
int_array = list(map(int, text_array))

count = 0

# int_array = [3,4,2,6,9,10,16,12,1,5,8,7]

# swap elements in array
def swap(input1, input2):
    temp = input1
    input1 = input2
    input2 = temp
    return input1, input2

# QuickSort Algorithm
def QuickSort(input):
    global count
    length = len(input)
    count += (length - 1)
    if length <= 1:
        return input # 이걸 해결해야됨.
    
    # # Prob 1 #######################################################
    # pivot_idx = 0
    
    # # Prob 2 #######################################################
    # pivot_idx = length - 1
    # input[0], input[pivot_idx] = swap(input[0], input[pivot_idx])
    # pivot_idx = 0
    
    # Prob 3 #######################################################
    pivot_idx = 0
    dic = {}
    dic[0] = input[0]
    dic[length - 1] = input[length - 1]
    dic[length // 2 if length % 2 == 0 else (length + 1) // 2] = input[length // 2 if length % 2 == 0 else (length + 1) // 2]
    key_list = []
    value_list = []
    for key, value in dic.items():
        key_list.append(key)
        value_list.append(value)
    median = statistics.median(value_list)
    for idx in range(len(value_list)):
        if value_list[idx] == median:
            pivot_idx = key_list[idx]
            break
    input[0], input[pivot_idx] = swap(input[0], input[pivot_idx])
    pivot_idx = 0
    
    i = 1
    for j in range(1, length):
        if input[j] < input[pivot_idx]:
            input[j], input[i] = swap(input[j], input[i])
            i += 1
    input[pivot_idx], input[i - 1] = swap(input[pivot_idx], input[i - 1])
    
    input[0:i-1] = QuickSort(input[0:i-1])
    input[i:length] = QuickSort(input[i:length])
    
    return input

if __name__ == '__main__':
    int_array = QuickSort(int_array)
    print(int_array)
    print(count)