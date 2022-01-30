# 이진탐색 예제

# 탐색 범위를 절반으로 줄이는 것을 반복해서 탐색하는 방법이다.
# 이진탐색은 데이터가 정렬이 되어있음을 전제하고 사용하는 탐색 알고리즘이다.
# 계산 복잡도는 O(logn)

# index의 지정은 시작과 끝 두 범위를 따로 지정해서 정의하는 것이 좋다.

def Binary_search(lst, s_value):
    start = 0
    end = len(lst) -1
    #리스트 탐색범위 변수이다.
    
    while start <= end:
        mid = (start + end)//2
        #탐색 범위의 중간위치이다.
        if s_value == lst[mid]:
            return mid
        #찾았을 때 반환하는 값이다.a
        elif s_value>lst[mid]:
            start = mid + 1
        else:
            end = mid - 1
    
    return -1
    #찾지 못했을 때 반환하는 값이다.
	

d = [1,4,9,16,25,36,49,64,81]
n = 36
print(Binary_search(d, n))
d2 = [1,4,9,16,25,36,49,64,81,100,121,144]
n2 = 144
print(Binary_search(d2, n2))
