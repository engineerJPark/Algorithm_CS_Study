#병합정렬 예제이다.

#내가 먼저 만들어본 코드 오류가 있어서 잡아내야한다....
#정지조건을 l로 놓아서 버그가 생겨난거였다. 변수 n을 추가해서 해결했다.
#문제가 있는 모듈
def mergesort(lst):
    n = len(lst)
    if n<= 1
        return
    l = n//2
    lst1 = lst[:l]
    lst2 = lst[l:]
    mergesort(lst1)
    mergesort(lst2)
    return mergesort_sub(lst1, lst2)


# 병합하는 모듈
def mergesort_sub(lst1, lst2):
    new_lst = []
    n1 = len(lst1)
    n2 = len(lst2)
    i = 0
    j = 0
    while n1>0 and n2>0:
        if lst1[i] > lst2[j]:
            new_lst.append(lst2[j])
            j += 1
            n2 -= 1
        else:
            new_lst.append(lst1[i])
            i += 1
            n1 -= 1
    if n1>0:
        while n1>0:
            new_lst.append(lst1[i])
            i += 1
            n1 -= 1
    if n2>0:
        while n2>0:
            new_lst.append(lst2[j])
            j += 1
            n2 -= 1
    return new_lst

a = [1,3,5,8,9]
b = [2,4,6,7,10]
print(mergesort_sub(a,b))
d = [6,8,3,9,10,1,2,4,7,5]
print(mergesort(d))


# 예제에대한 풀이로 책에 나온것.
# 이렇게 간결하게 풀다니 그들은 신인가?
def merge_sort(a):
    n = len(a)
    if n<=1:
        return a
    mid = n//2
    g1 = merge_sort(a[:mid])
    g2 = merge_sort(a[mid:])
    result = []
    while g1 and g2:
        if g1[0]<g2[0]:
            result.append(g1.pop(0))
        else:
            result.append(g2.pop(0))
    while g1:
        result.append(g1.pop(0))
    while g2:
        result.append(g2.pop(0))
    return result

d = [6,8,3,9,10,1,2,4,7,5]
print(merge_sort(d))
    
    
#또다른 예제

def merge_sort(a):
    n = len(a)
    #종료조건
    if n<=1:
        return
    #나누고 재귀호출하기
    mid = n//2
    g1 = a[:mid]
    g2 = a[mid:]
    merge_sort(g1)
    merge_sort(g2)
    #병합과정
    i1 = 0
    i2 = 0
    ia = 0
    while i1<len(g1) and i2<len(g2):
        if g1[i1]<g2[i2]:
            a[ia] = g1[i1]
            i1 += 1
            ia += 1
        else:
            a[ia] = g2[i2]
            i2 += 1
            ia += 1
    #남아있는 자료들을 정리한다.
    while i1<len(g1):
        a[ia] = g1[i1]
        i1 += 1
        ia += 1
    while i2<len(g2):
        a[ia] = g2[i2]
        i2 += 1
        ia += 1
        
d = [6,8,3,9,10,1,2,4,7,5]
merge_sort(d)
print(d)
