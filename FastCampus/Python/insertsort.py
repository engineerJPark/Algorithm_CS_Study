#삽입정렬 예제이다.

#먼저 연습

def insert_sort(lst):
    l = len(lst)
    i = 0
    lst_sort = []
    lst_sort.append(lst[i])
    for i in range(0,l):
        m = len(lst_sort)
        for j in range(0, m):
            if lst[i] < lst_sort[j]:
                lst_sort.insert(j, lst[i])
                break
            #맨 뒤까지 다 찾아봤으나 안보이는 경우 맨 뒤에 쳐박아야한다.
            if (j == (m-1)) and (lst[i] not in lst_sort) :
                lst_sort.append(lst[i])
    return lst_sort

d = [3,1,5,2,4]
print(insert_sort(d))

# 책에서 제시하는 삽입정렬 예시이다.

def ins_sort(lst):
    n = len(lst)
    for i in range(1,n):
        key = lst[i]        #i번위치의 값을 key라고 지정한다.
        j = i - 1
        while j>=0 and lst[j]>key : 
            lst[j+1] = lst[j]        #한칸씩 밀어내는 과정이다.
            j -= 1
        lst[j+1] = key
        
d = [2,4,5,1,3]
ins_sort(d)
print(d)