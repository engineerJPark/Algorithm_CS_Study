# inversion의 개수 구하기
# i번째 row = array의 i번째 entry
# fast divide and conquer algorithm을 사용할 것

fd = open('C:/Users/jshac/OneDrive - 고려대학교/TIL/CS_Study/Algorithm_Data_Structure/Stanford/Week2/IntegerArray.txt', 'r')
text_array = fd.readlines()
fd.close()
int_array = list(map(int, text_array))

# # for test
# int_array = [3,2,4,1]

inversion_num = 0

# divide and merging
def Find_inversion(array):
    global inversion_num # global variable
    merge_array = []
    if len(array) == 1: # base case
        return array
    
    # dividing
    sub_array1 = array[:len(array) // 2]
    sub_array2 = array[len(array) // 2:]
    
    # recursion
    sub_array1 = Find_inversion(sub_array1)
    sub_array2 = Find_inversion(sub_array2)
    
    # merging & counting
    i = 0
    j = 0
    # i, j가 끝까지 갔을 때 exception 처리가 필요하다.
    for k in range(len(array)):
        # general case
        if sub_array1[i] < sub_array2[j] :
            merge_array.append(sub_array1[i])
            i += 1
        else:
            merge_array.append(sub_array2[j])
            inversion_num += len(sub_array1) - i
            j += 1
        # end case
        if i == len(sub_array1):
            while j <len(sub_array2):
                merge_array.append(sub_array2[j])
                j += 1
            return merge_array
        if j == len(sub_array2):
            while i < len(sub_array1):
                merge_array.append(sub_array1[i])
                i += 1
            return merge_array    
    return merge_array

Find_inversion(int_array)
print('# of inversion : ', inversion_num)