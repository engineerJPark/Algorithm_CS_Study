# Week 3

---

# Data Structure

---

BFS는 Queue를 사용한다. DFS는 Stack을 사용한다.

둘다 insert, delete는 linear time이고, 각각 FIFO, FILO이다.

보통 제공하는 연산이 적을 수록 차지하는 공간도 적다.

![Image](https://i.imgur.com/9nmN0uU.png)

그냥 단계별 수준을 얘기하고 싶으셨다고 한다...

![Image](https://i.imgur.com/YzxabkR.png)

# Heaps: Operations and Applications

---

중요한 연산 두가지는 Insertion과 Extracting Minimum

Heap은 크게 Object와 Key로 이루어진다. Object는 추상화 대상이고, Key는 그 대상을 표현하는데 필요한 수치

이와 반대로 Heap이 Max값을 추출하도록 설계할 수도 있다. 대신 이러면 Min 추출은 안된다.

둘다 동시에 되기를 바란다면 Binary Search Tree를 이용해라.

Heapify = n개의 batch로 heap을 initializing하는 것

Delete = 원소 하나 정해서 삭제

operation과 running time을 정리해놓은 것

![Image](https://i.imgur.com/tv0zVMZ.png)

**언제 Heap을 사용하게 되는가?**

    **알고리즘에서 Minimum을 Exhausive하게 찾는 일이 반복될 때**

Selection Sort : 최소값을 차례대로 찾아서 순서대로 놓는 Sort 방법론

여기에 Heap을 사용하면 Heap sort가 된다.

참고로 O(nlogn)보다 더 나은 Comparison based sorting algorithm은 없다.

![](https://imgur.com/rFB8GUR.jpg)

Heap을 이용하면 Priority Queue(우선순위 큐)를 만들 수 있다.

최소값만을 추출하는 것이 반복되는 상황이라면 힙으로 자료구조를 사용한다.

![Image](https://i.imgur.com/0dwMpZo.png)

중간값을 찾는 문제이다. 이에 대하여 Max/Min을 추출하는 Heap을 따로 만들어서 문제를 해결할 수 있다.  전체 object의 절반을 하나의 heap에 넣는 것이다.

총 크기의 절반만큼만 두 Heap에서 추출을 하면, 중간값이 나올 것이다.

두 Heap이 imbalance하면 한쪽에서 최대/최소를 꺼내서 반대쪽에 넣어주는 식으로 해결할 수 있다.

![Image](https://i.imgur.com/7VOhcwS.png)

다익스트라를 효율적으로 만드는데에 사용할 수도 있다. 이는 지난 강의에서 했었다.

![Image](https://i.imgur.com/yzl2Lry.png)

# Heaps: Implementation Details

---

아래는 Heap에서 할 수 있는 연산을 정리한 것이다.

![Image](https://i.imgur.com/RxImb0N.png)

Tree로 생각한다. root가 있는 completed binary tree

children의 Key는 항상 그 바로 위의 node의 Key보다 크다.

heap이 하나의 형태뿐만이 아니라, 여러개의 형태로 나올 수도 있다. 그림 참고

root Key는 무조건 최소값이어야 한다.

![Image](https://i.imgur.com/hsQcawR.png)

Array를 이용해서 Heap을 표현해본다. 꼭 포인터로 표현할 필요가 없다.

헷갈림 방지를 위해서 index 0는 비워둔다.

parent는 i가 짝수면 i/2, 홀수면 (i-1)/2이다.

children은 2i, 2i + 1이다.

![Image](https://i.imgur.com/xdneJoa.png)

### 계산

7, 10을 넣는  것을 가정해보자. 아직 bottom에 4가 있어서 문제가 없다.

하지만 그 다음부터는 문제가 생긴다. 5를 넣는다고 해보자. 그럼 이제 순서를 바꿔야한다.

1. 5와 12를 바꾼다.

2. 그리고 5와 8을 바꾼다.

3. 그럼 heap의 조건(child key >= parent key)이 모두 만족된다. 그대로 둔다.

다른 부분은 그림 참고

![Image](https://i.imgur.com/y0T9gQK.png)

이번에는 root를 추출하는 것을 해보자.

1. root 삭제

2. last leaf를 root로

3. root를 점점 아래로 보낸다. **이때, 둘 중 더 작은 child와 교환을 한다.** 아니면 연산 후, parent가 child보다 커지는 문제가 발생한다.

![Image](https://i.imgur.com/SlDU6Vy.png)

# Balanced Search Trees : Operations and Applications

---

배열 안에는 각 객체에 대한 식별이 가능한 수를 모았다.

정렬된 배열의 각각의 Opeartion에 대한 running time을 보라.

rank의 경우, 23이 input이라고 하면, 23을 binary search로 찾는 것이다.

![Image](https://i.imgur.com/lNF1qmw.png)

하지만 insertion deletion이 linear time이니까, 더 개선한 자료구조를 사용하는 것이 좋다.

그래서 Binary search Tree가 나온 것이다. 똑같이 다 지원하지만 insertion과 deletion을 더 빠른 속도로 지원한다.

다른 연산들이 모두 O(logn)이지만, insertion and deletion이 O(logn)이다.

만약 insertion과 deletion이 필요하다면 binary search tree가 가장 효율적인 방법이다.

heap의 경우에는 max/min value까지 필요한 경우

빠른 LookUp에는 hash table

많은 연산이 필요하다면 Balanced Search Tree가 가장 적합

![Image](https://i.imgur.com/3SbOjcj.png)

# Binary Search Tree Basic

---

직전까지 이런 연산이 가능하다는 것을 보았다.

![Image](https://i.imgur.com/rjzNYjH.png)

Binary Search Tree는 좌측은 자신의 Key보다 작아야하고, 우측은 자신의 Key보다 커야한다.

Heap과는 다르다. Heap은 그냥 Parent가 child보다 작아야한다는 형태.

Heap : 최소값 찾기 특화, Binary Search Tree : Search 특화

![Image](https://i.imgur.com/oopIKkM.png)

BST는 Height(Depth)에 범위가 있다. $\log_2n$ ~ $n$ 

![Image](https://i.imgur.com/T0bJWKT.png)

아래는 recursion을 이용한 BST의 Searching과 inserting에 관한 알고리즘

rewire final NULL ptr = 마지막으로 찾은 그 포인터를 새로운 node를 만들 곳으로 정한다. 

만약 중복값을 허용한다면, 같은 값은 왼쪽으로 보내는 convention을 두면 된다.

![Image](https://i.imgur.com/xVJzk7B.png)

# Binary Search Tree Basic 2

---

 일직선 형태로 있을 때에는 그냥 Queue랑 다를 게 없으니 최악의 상황이다.

![Image](https://i.imgur.com/4OA1M7p.png)

이번에는 Min, Max를 찾는 방법을 보자.

heap에서는 min과 max 중 하나만 쉽게 찾을 수 있었는데, BST는 둘 다 쉽게 찾을 수 있다.

min의 경우

- minus infinity를 찾는다고 해보자. 그럼 계속해서 왼쪽 subtree만 찾으면 된다. NULL pointer가 나올 때 까지

- max도 반대로 하면된다.

k의 predecessor 찾기 = next smallest

- 좌측 subtree의 최대값

- 좌측 subtree가 없는 경우, k보다 작은값이 나올 때까지 parent pointer 추적 (2, 4와 같은 case) (왼쪽 방향으로 최초 상승할 때 발견한다.)

![Image](https://i.imgur.com/lpjmN7W.png)

이 경우도 마찬가지로 일렬로 나열되어있는 경우가 있을 것이다.

따라서 $\Theta (height)$ 

![Image](https://i.imgur.com/laO1gtZ.png)

오름차순 출력하기

최소값 구하기를 각 TL과 TR에서 끝까지 계속 반복하면 될 것이다.

시간 복잡도는 O(n) : 하나의 node에 대해서 한 번의 recursive call이기 때문이다. 그리고 recursive call에서는 O(1)이고

![Image](https://i.imgur.com/8f1utr7.png)

삭제는 3가지 경우의 수가 있다.

1. no children
   
   - 그냥 삭제

2. one children
   
   - 남은 child가 그 자리를 채운다.

3. 2 children
   
   - k의 다음 작은 값을 계산한다. 이를 l이라고 정한다.
   
   - k와 l을 swap
   
   - k를 지운다.

predecessor를 찾는 과정이 있기에, 시간복잡도가 O(height)이다.

![Image](https://i.imgur.com/i7oCWeA.png)

![Image](https://i.imgur.com/btTTi6V.png)

몇 번째 node를 선택하는 연산

data of populated subtree를 추가 정보로 놓는다.

**이를 size라고 이름 붙이고, 해당 subtree에 node가 몇개인지로 정의한다.**

subtree 두개의 size를 알면 그 parent의 size도 쉽게 알 수 있다.

그렇기에 insertion과 deletion 마다 그 data를 유지하기 쉽다.    

![Image](https://i.imgur.com/MXVpNB8.png)

아래는 pseudo code이다.

**i는 찾는 수이고, a는 왼쪽 tree의 size**

running time의 경우 최악의 경우에는 height만큼 이동이 가능하므로 **O(height)**이다.

![Image](https://i.imgur.com/VtlfBRh.png)

# Red Black Tree : Balanced Binary Search Tree

---

balance를 유지하면 그 높이가 $log_2n$이 되는 것을 통해 빠르게 계산할 수가 있다.

그래서 계속 balance를 유지하게 할 것이다.

이 중에서 Red Black Tree에 대해서 알아볼 것이다.

![Image](https://i.imgur.com/67XU3o9.png)

AVL, splay, B tree도 알면 좋다. 

보통 이런 거는 database에 사용되는데, key가 여러개이고 그에 따른 branch가 여러 개 이다.



Red Black의 특성

어떻게 이 invariants는 height가 logarithmic하게 만드는가?



1. red/black을 구분할 bit

2. root는 black

3. tree를 타고 내려갈 때 연속으로 red가 나올 수 없다.
   
   red node의 parent/child는 black이어야 한다.

4. root에서 NULL까지의 경로는 모두 같은 black node 개수를 지닌다.

![Image](https://i.imgur.com/q4VwRcH.png)

이 경우 마지막 4번의 invariant가 위반되어서 안된다.

![Image](https://i.imgur.com/iIxAHsm.png)

맨 처음 3, 5, 7이 있을 때에도 문제가 없었다.

만약 node 7에 6만 추가했다면 node 6이 red가 되어야 모든 invariant가 만족된다.



이번에는 node 7에 6,8을 추가로 저장해보자.

이경우 node 7이 red가 되면 모든 invariant가 만족된다.



즉, **추가 한 번만 할 때에는 추가한 곳에 red를 놓고, 그 곳에 하나가 더 축가되면 red를 그 parent로 올려준다.**

![Image](https://i.imgur.com/90lTE9s.png)

다른 방법으로 binary함을 유지하려면 회전과 같은 연산을 하면된다.



위의 네가지 invariant를 지키면 height가 $2log_2(n + 1)$으로, 연산이 빨라진다.

k는 tree의 최소 길이라고 둔다. 즉 path에 black만 있다는 의미

이렇게 되면 tree의 size의 lower bound도 $2^k - 1$이 된다.

![Image](https://i.imgur.com/PL0nQHB.png)

최악의 경우에는 red와 black이 반복되는 경우가 생길 수 있다. 이 때에는 path length가 매우 2배가 되므로 "By 3rd Invairant"가 성립한다.

![Image](https://i.imgur.com/0UWRlOS.png)

따라서 모든 연산이 O(logn)이다.

# Rotation (Optional)

---

![Image](https://i.imgur.com/WyAZ6M1.png)

![Image](https://i.imgur.com/ltSVW41.png)

![Image](https://i.imgur.com/xImpSuC.png)

# Red Black Tree Insertion (Optional)

---

![Image](https://i.imgur.com/mh4C9u9.png)

![Image](https://i.imgur.com/Gej5kbR.png)

![Image](https://i.imgur.com/ivDPhc7.png)

![Image](https://i.imgur.com/AR3hR2v.png)