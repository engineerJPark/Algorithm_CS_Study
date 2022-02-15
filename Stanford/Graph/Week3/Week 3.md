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



# Heaps: Supported Operations

---

![Image](https://i.imgur.com/RxImb0N.png)

![Image](https://i.imgur.com/xdneJoa.png)

![Image](https://i.imgur.com/y0T9gQK.png)

![Image](https://i.imgur.com/SlDU6Vy.png)

# Balanced Search Trees : Operations and Applications

---

![Image](https://i.imgur.com/lNF1qmw.png)

![Image](https://i.imgur.com/3SbOjcj.png)

# 

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