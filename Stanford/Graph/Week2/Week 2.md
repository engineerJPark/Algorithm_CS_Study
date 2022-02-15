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

Greedy Algorithm으로 매번의 노드마다 최소의 지점을 찾아서 이동한다. 이 방식으로 최소 경로를 얻는다.

조금씩 X의 크기를 늘려가면서 한 번씩 $A[v] + l_{v,w}$를 연결된 X의 node에 모두 적용한다.

s -> v -> w -> t

![Image](https://i.imgur.com/Cy5IrAA.jpg)

음수인 length에 대해서는 왜 안될까?

양수를 더하는 방식으로 해결할 수는 없는걸까?

결론적으로는 length의 최소최대치가 바뀌어서 해결되지 않는다.

그림의 그래프에서 +5를 한다고하면, svt가 아니라 st로 이동을 하게된다. 즉, 최소최대 경로가 보존되지 않는다.

![Image](https://i.imgur.com/c870pLH.jpg)

거기다가 애초에 맞지도 않는다. 당장 s에서부터가 최소가 -2라서 st로 가게 된다. 전체 최소 경로는 svt인데도!

# Correctness

---

중요하지는 않지만 일단은 봐보자.

아래는 알고리즘의 요약

![Image](https://i.imgur.com/5LIXaIk.jpg)

다익스트라 알고리즘이 계산하는 A[v]는 결국 L(v) = 최소 경로 길이를 계산하는 것과 같다.

~~아니 근데 이거 그냥 그 동안 그렇게 정의했잖아~~

![Image](https://i.imgur.com/gchnJM6.jpg)

![Image](https://i.imgur.com/HLe4PLF.jpg)

아래 그림과 같이 추가 node z를 만들어서, $A[w*] = L(v*) + l_{v*w*}$이 맞음을 증명한다.

![Image](https://i.imgur.com/bBhaFo6.jpg)

여기서 z와 w\*가 동일하면 명제가 참이 된다.

아래 그림에서 C_yz = l_yz 이다.

P는 s에서 w*까지 가는 임의의 경로

아래의 결론은 $A[w*] = L(v*) + l_{v*w*}$보다 작은 것이 없으니 명제가 참이라는 뜻이다.

왜냐하면 $A[y]$도, $l_{yz}$도, l_{zw\*}도 모두$L(v*), l_{v*w*}$보다 클 가능성이 있기 때문이다.

![Image](https://i.imgur.com/4cqasDU.jpg)

# Runtime

---

heap 자료구조를 이용해서 다익스트라 알고리즘을 구현할 것이다.

아래는 지난 강의의 정리

![Image](https://i.imgur.com/yHV0emI.jpg)

이건 의사코드

![Image](https://i.imgur.com/qVJHlS2.jpg)

이건 문제

main while loop를 보자. n개의 node에 대해 m개의 각 edge를 탐색하므로(조건에 맞는 지, 아닌 지), O(nm)이 된다.

data structure를 변경함으로써 속도를 더 빠르게 변경할 수 있다.

![Image](https://i.imgur.com/Bynv3mz.jpg)

heap은 보통 완전이진트리의 형상을 띈다. 보통 linear array로 구현 가능하다.

특성

    key의 값이 children보다 같거나 작아야한다. -> 제일 작은 숫자가 root가 된다.
    최소값을 구하려면, 최하단 우측 leaf와 root를 바꾸고, bubbling down 해나간다.
    값을 넣으려면 최하단 우측 leaf에 넣고 swap을 진행하면 된다. 
    값을 지우려면 bubble up or down하면 된다.

![Image](https://i.imgur.com/vc87XMn.jpg)

**heap에 있는 것은 V-X의 vertex 뿐이다.**

V-X에 있는 vertices를 대상으로, Key값은 다익스트라 그리디 score(length)로 한다.

하나의 vertex에서 여러 개의 edge에 대해서 최소값을 구하고 그 다음 vertex끼리의 최소값을 구한다.

![Image](https://i.imgur.com/hQQCPj6.jpg)

w가 X에 추가되면, w에 있는 edge가 crossing edge애 추가 된다!

그리고 그 edge랑 연결된 vertex들의 Key값(최소 length)를 update해야한다. 만약에 wv가 새로운 Key가 될 수 있다면.

heap을 이용한 과정은 아래 그림을 참고하자.

![Image](https://i.imgur.com/MQPyiep.jpg)

heap opeartion 덕분에 시간이 줄어든 것이다.

한 번의 delete - insert combo로 모든 연산이 해결되었다.

**그 이하는 다시 확인해볼 것. Run Time에 관한 것**



**시간복잡도**

모든 노드 (O(V))에 대해 힙에서 최소값을 추출(O(logV))

각 노드마다 모든 이웃을 확인하는 것은 모든 edge를 확인하는 것과 같고 O(E), 매번 힙에서 최단 거리를 갱신O(logV)

이 둘을 조합하면

    각 노드마다 미방문 노드 중 출발점으로부터 현재까지 계산된 최단 거리를 가지는 노드를 찾는데 O(VlogV)

    각 노드마다 이웃한 노드의 최단 거리를 갱신 O(ElogV)

    결론은 O((V+E)logV)

**이에 대해서 다른 설명**

하나는 각 정점마다 인접한 간선들을 모두 검사하는 작업이고, 다른 하나는 우선순위 큐에 원소를 넣고 삭제하는 작업입니다. 각 정점은 정확히 한 번씩 방문되고, 따라서 모든 간선은 한 번씩 검사된다는 사실을 떠올리면 간선들을 검사하는 데는 전체 O(|E|)의 시간이 걸립니다. 

우선순위 큐가 가장 커지는 최악의 시나리오는 그래프의 모든 간선이 검사될 때마다 dist[]가 갱신되고 우선순위 큐에 정점의 번호가 추가되는 것입니다. 이때 추가는 각 간선마다 최대 한 번 일어나기 때문에, 우선순위 큐에 추가되는 원소의 수는 최대 O(|E|)의 시간이 걸리고, O(|E|)개의 원소에 대해 이 작업을 하려면 전체 시간 복잡도는 O(|E||log|E|)가 됨을 알 수 있습니다. (**즉, 최소 경로인 간선을 찾는데 드는 시간이 최악의 경우 O(|E||log|E|)라는 것이다.**)

이 두 작업에 걸리는 시간을 더하면 O(|E||log|E|)가 됩니다만, 대개의 경우 그래프에서 간선의 개수 |E|는 |V|^2보다 작기 때문에 O(log|E|)=O(log|V|)라고 볼 수 있습니다. 따라서 시간 복잡도는 O(|E||log|V|)가 됩니다.

![Image](https://i.imgur.com/0n5nHKq.jpg)

# REFERENCE

우선순위 큐를 위하여 만들어진 자료구조. 우선순위 큐는 배열, 연결리스트, 힙 으로 구현이 가능하다. 이 중에서 힙(heap)으로 구현하는 것이 가장 효율적이다.

## 자료구조 ‘힙(heap)’이란?

완전 이진 트리의 일종으로 우선순위 큐를 위하여 만들어진 자료구조이다.

여러 개의 값들 중에서 최댓값이나 최솟값을 빠르게 찾아내도록 만들어진 자료구조이다.

힙은 일종의 반정렬 상태(느슨한 정렬 상태) 를 유지한다.

    큰 값이 상위 레벨에 있고 작은 값이 하위 레벨에 있다는 정도
    간단히 말하면 부모 노드의 키 값이 자식 노드의 키 값보다 항상 큰(작은) 이진 트리를 말한다.

힙 트리에서는 중복된 값을 허용한다. (이진 탐색 트리에서는 중복된 값을 허용하지 않는다.)

## 힙(heap)의 종류

### 최대 힙(max heap)

부모 노드의 키 값이 자식 노드의 키 값보다 크거나 같은 완전 이진 트리

key(부모 노드) >= key(자식 노드)

### 최소 힙(min heap)

부모 노드의 키 값이 자식 노드의 키 값보다 작거나 같은 완전 이진 트리

key(부모 노드) <= key(자식 노드)

![Image](https://i.imgur.com/TZC2s0C.png)

### 삽입 삭제 등의 연산은 링크를 참고

https://gmlwjd9405.github.io/2018/05/10/data-structure-heap.html