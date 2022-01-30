# 큐 : First In First Out. 먼저 들어간 데이터가 가장 먼저 나간다.
# 자료투입을 enqueue, 자료 출력을 dequeue라고 한다.

# 스택 : Last In First Out. 마지막에 들어간 자료가 가장 먼저 나간다.
# 자료투입을 push, 자료출력을 pop이라고 한다.

# 파이썬에서는 리스트 메서드(append, pop)를 이용해 간단히 큐와 스택을 표현할 수 있다.

# 큐와 스택을 이용하여 회문(바로 읽어도 거꾸로 읽어도 같은 문장)을 찾는 알고리즘을 작성하고자 한다.
# 큐와 스택은 출력 순서가 서로 반대이다. 즉 큐에서나 스택에서는 읽는 데이터가 순서가 같다면 그 문장은 회문일 것이다.

def Palindrome(lst):
    #큐와 스택 정의
    qu = []
    st = []
    #qu와 st에 각각 데이터를 추가한다.
    for x in lst:
        if x.isalpha():
            qu.append(x)
            st.append(x)
    while qu:
        if qu.pop(0) != st.pop():
            return False
    # 다른경우 출력하는 값이 false이다.
    return True

print(Palindrome("Wow"))
print(Palindrome("wow"))
print(Palindrome("Mama"))