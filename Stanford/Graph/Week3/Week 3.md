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

# Binary Search Tree : Operation

---



![Image](https://i.imgur.com/i7oCWeA.png)



![Image](https://i.imgur.com/btTTi6V.png)



![Image](https://i.imgur.com/MXVpNB8.png)



![Image](https://i.imgur.com/VtlfBRh.png)



![Image](https://i.imgur.com/rjzNYjH.png)



![Image](https://i.imgur.com/oopIKkM.png)



![Image](https://i.imgur.com/T0bJWKT.png)



![Image](https://i.imgur.com/xVJzk7B.png)



![Image](https://i.imgur.com/4OA1M7p.png)



![Image](https://i.imgur.com/lpjmN7W.png)



![Image](https://i.imgur.com/laO1gtZ.png)



![Image](https://i.imgur.com/8f1utr7.png)

# Red Black Tree

---



![Image](https://i.imgur.com/WyAZ6M1.png)



![Image](https://i.imgur.com/aTlfxey.png)

![Image](https://i.imgur.com/xyD6qeP.png)

![Image](https://i.imgur.com/67XU3o9.png)

![Image](https://i.imgur.com/q4VwRcH.png)

![Image](https://i.imgur.com/iIxAHsm.png)

![Image](https://i.imgur.com/90lTE9s.png)

![Image](https://i.imgur.com/PL0nQHB.png)

![Image](https://i.imgur.com/0UWRlOS.png)

# 

---

![Image](https://i.imgur.com/ltSVW41.png)

![Image](https://i.imgur.com/xImpSuC.png)

# 

---

![Image](https://i.imgur.com/mh4C9u9.png)

![Image](https://i.imgur.com/Gej5kbR.png)

![Image](https://i.imgur.com/ivDPhc7.png)

![Image](https://i.imgur.com/AR3hR2v.png)