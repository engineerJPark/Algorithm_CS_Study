# 선택정렬, 삽입정렬, 병합정렬 세가지 중 선택정렬에 관한 예제이다.
# 선택정렬은 O(n^2)인 알고리즘이다.

# 쉽게 쓴 것 먼저 

def finding_min_index(lst):
    n = len(lst)
    min_index = 0
    for i in range(0, n):
        if lst[i]<lst[min_index]:
            min_index = i 
    return min_index

def sel_sort(lst):
    result = []
    while lst:
        min_index = finding_min_index(lst)
        value = lst.pop(min_index)
        result.append(value)
    return result

lst_d = [2,4,5,1,3]
print(sel_sort(lst_d))


# 좀 어렵게 쓴것

def sel_sort(lst):
    n = len(lst)
    print(n, "\n")
    for i in range(0, n-1):
        min_index = i
        for j in range(i + 1, n):
            if lst[j] < lst[min_index]:
                min_index = j
        tmp = lst[min_index]
        lst[min_index] = lst[i]
        lst[i] = tmp
        # lst[i], lst[min_index] = lst[min_index], lst[i]

d = [2,4,5,1,3]
sel_sort(d)
print(d)