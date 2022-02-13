# Dijkstra's Shortest Path Algorithm
---

single source shortest path에서의 문제이다.

driving과 같은 상황에서 나오는 문제이다.

다음과 같은 input을 고려하자.

m = edge의 개수

n = vertice의 개수

G(V, E)

여기서 추가 변수 두 가지가 생긴다.

nonnegative length $L_{E}$ = 이 경로가 얼마나 긴가? = 에상되는 경로 이동 시간

이 length는 각 edge마다 부여되는 값이다.

두 번째로는...

source =  vertex 중, 우리가 path를 찾는 vertex이다. BFS, DFS 할 때와 마찬가지인 변수이다. 

이제 시작점 s와 도착점 v 간의 최단 거리를 측정하면 된다.

length of path = sum of edge length (그림 참고)

다음 가정을 알아두어야한다.

1. s에서 v로 가는 직접적 경로가 존재해야한다. 즉 경로가 없는 vertices끼리는 미리 없애 놓을 것.

2. nonnegative edge length : negative하다면 Bellman Ford method를 이용해야한다.

![Image](https://i.imgur.com/NXmxhTP.jpg)

최소 경로 길이 $L(v)$를 구하면 다음과 같이 0,1,3,6을 구할 수 있다.

![Image](https://i.imgur.com/JFxgCcS.jpg)

1. BFS는 length of the edge가 1일 때에만 적용 가능하다. 

그래서 Dijkstra 방법이 필요한 것이다. edge가 모두 1이면 Dijkstra 방법은 BFS가 된다.

참고로 이 length of the edge = weight of the edge로 취급하기도 한다.

2. 길이가 있는 edges를 1이 여러개인 edge로 변경할 수 있지만, 길이가 길면 처리가 오히려 곤란해져서 그러지는 않는다.

![Image](https://i.imgur.com/dFB4x8y.jpg)

다음은 대략적인 Pseudo code

X는 이미 탐색이 끝난 부분을 담는 것이다. 여기서 관심사는 X to X-V인 edge

여기서 그리고 crossing edge를 관찰한다. 이를 위한 while 문 내부에서는, 하나는 방금 전에 계산한 v(X에 존재) 하나는 아직 게산 안한 w(X에 없음)를 선택하고 그림과 같이 계산을 진행한다.

Dijkstra에서는 각 vertex에 score를 준다. 그리고 그 중에서 minimum인 score를 택한다.

v* = gready criterion을 최소화하는 이미 계산된 vertex

w* = gready criterion을 최소화하는 계산 안된 vertex

즉, 여기서 A[v*]는 이미 계산이 되어있는 것이고, A[w*]은 아니다.

따라서 w*는 새로 X에 등록되어야한다.

![Image](https://i.imgur.com/gI07N7O.jpg)

# Example
---

![Image](https://i.imgur.com/Cy5IrAA.jpg)

![Image](https://i.imgur.com/c870pLH.jpg)

# Correctness
---

![Image](https://i.imgur.com/5LIXaIk.jpg)

![Image](https://i.imgur.com/gchnJM6.jpg)

![Image](https://i.imgur.com/HLe4PLF.jpg)

![Image](https://i.imgur.com/bBhaFo6.jpg)

![Image](https://i.imgur.com/4cqasDU.jpg)

# Runtime
---

![Image](https://i.imgur.com/yHV0emI.jpg)

![Image](https://i.imgur.com/qVJHlS2.jpg)

![Image](https://i.imgur.com/Bynv3mz.jpg)

![Image](https://i.imgur.com/vc87XMn.jpg)

![Image](https://i.imgur.com/hQQCPj6.jpg)

![Image](https://i.imgur.com/MQPyiep.jpg)

![Image](https://i.imgur.com/0n5nHKq.jpg)