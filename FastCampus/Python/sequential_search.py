def search_list(lst, findingvalue):
    n = len(lst)
    for i in range(0, n):
        if findingvalue == lst[i]:
            return i
    
    return -1

lst_v = [17,92,18,33,58,7,33,42]
print(search_list(lst_v, 18))
print(search_list(lst_v, 33))
print(search_list(lst_v, 900))

//이런 순차탐색의 경우 보수적으로 계산 복잡도를 정한다. ,O(n)이다.
