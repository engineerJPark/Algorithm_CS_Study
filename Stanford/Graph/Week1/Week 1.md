# Week 1

# Overview

---

## Motivation

1. network의 연결을 check할 수 있다. 어디로든 input되면 어디로든 갈 수 있는지
2. shortest path를 찾는다
3. plan을 공식화한다.
4. Compute the “pieces” (or “components”) of a graph

이 알고리즘 들은 너무  빨라서 free primitive라고도 부른다.

# Graph Prob에 대한 정의

---

1. 모든 vertex가 접근 가능하게 하고 싶다.
2. 같은 곳에 두번 가고 싶지 않다.

→ $O(m+n)$으로 하고 싶다. 

Generic Algorithm를 initiate하는 방법 중 대표적인 것이 BFS DFS이다.

Generic Algorithm에 대해서는 점점 영역을 넓혀가는 것이라고 생각하면 된다.

1. 간 곳, 안 간 곳 기록한다. 시작 지점 s은 explored에 처음부터 포함된다.
2. 한 곳은 간 곳, 한 곳은 안 간곳인 edge를 선택한다.
    1. 이게 없으면 search를 멈춘다.
3. 간 곳을 추가한다.

이 방법론에 대해서는 directed / undirected가 상관 없다.

![Image](https://i.imgur.com/MiwIEIs.jpg)


이건 뭐 굳이 proof까지 해야하나 싶을 정도로...

알고리즘 따라가면 그대로, 집합 S가 가지고 있는 vertex면 서로 연결되어있는 것이라, 무조건 path를 찾을 수 있다.


![Image](https://i.imgur.com/z1Ghcdy.jpg)


BFS 컨셉

- 각 node를 layer로 층을 나눈다.
- shortest path 찾을 수 있다.
- 연결된 undirected graph의 일부를 계산할 수 있다.

DFS 컨셉

- 깊은 탐색을 한다. 필요한 부분만 backtrack한다.
- cycle이 없는 directed graph에서 topological 순서를 찾을 수 있다.
- 특정한 순서를 지켜야하는 문제를 풀 때 적합하다.
- 연결된 directed graph의 일부를 계산할 수 있다.

BFS는 Queue, DFS는 Stack을 사용한다.

![Image](https://i.imgur.com/YkDY726.jpg)

# BFS

---

begining vertex가 주어지면, 그에 따라서 Graph Search를 행하는 것이 목적이다.

여기서 n은 vertices, m은 edges이고, 어떤 것이든지 더 클 수 있다.

![Image](https://i.imgur.com/a62edJc.jpg)

Pseudo Code

directed graph에서도 그대로 적용된다.

중요한 것은 각 Node가 Queue에 들어가는 순서대로 넘버링이 된다는 것이다.

![Image](https://i.imgur.com/jmOkUfu.jpg)

아래 Claim은 너무 당연하니깐 설명할 필요가 없을 듯 하다.

Queue에 출입하는 작업 n번과 search 작업 2m번

![Image](https://i.imgur.com/9wOLpWg.jpg)

# Shortest Paths

---

BFS의 응용. S에서 V까지의 가장 짧은 거리를 dist(V)로 표시한다.

node의 layer가 뭔지 추적하는 작업을 해야 한다. 그러면 layer가 최소 거리를 자동으로 찾아주게 된다.

추가할 코드 : 

1. 일단 기본 dist를 v = s는 0, v ≠ s는 infinity로 둔다. 
2. edge(v,w)를 정할 때, w가 unexplored → dist(w) = dist(v) + 1이다.

이것 외에 나머지는 그냥 동일하게 해주면 된다.

참고로 같은 dist == 같은 Layer이다

![Image](https://i.imgur.com/tfu14OA.jpg)

**오직 BFS만이 shortest path를 보장한다.**

# Undirected Connectivity

---

이거는 DFS를 이용해서 구현해도 된다.

이렇게 세 개로 나뉜 graph 조각을 각각 connected component라고 한다.

Connected component = maximal regions connected

아래 graph처럼 연결되어있는 것 끼리는 모두 equivalence relation이다.

equivalence relation이려면, 세가지 조건이 만족되어야 한다.

1. reflexive : related to itself 해야한다. 자기 자신이 포함되어야한다.
2. symmetric : u ~ v하면 v ~ u하다.
3. transitive : v ~ u, v ~ w이면, u ~ w이다.

이를 이 문제에 적용하면, **모든 것이 같은(동치인, equivalence relation인) subset의 최대치를 찾고 싶다는 것.**

이제 BFS를 이용해서 이를 해결할 것이다.

![Image](https://i.imgur.com/fcgTbFD.jpg)

왜 Running Time이 O(m + n)인가

모든 node 넘버링 → O(n)

n개의 node 흝기 → O(n) 

BFS 1회에 O(1) → O(m)

총합하면 O(m + n)

![Image](https://i.imgur.com/fGHsueh.jpg)

# DFS

---

maze를 풀 때 주로 사용

depth 방향으로 최대한 깊이 들어가다가, 더 이상 안가본 곳이 없으면, 왔던 대로 다시 되돌아간다.

directed graph에서 주로 사용된다.

![Image](https://i.imgur.com/hVIeyxA.jpg)

BFS code를 따라서 만들고, Queue를 Stack으로 고쳐주면 DFS가 바로 나온다.

![Image](https://i.imgur.com/y2252zL.jpg)

running time : O(n + m)

n = node 개수

m = edge 개수

![Image](https://i.imgur.com/RjuJcVr.jpg)

# Topological Sort

---

acyclic directed edge를 다루는 문제이다.

순서가 정해져 있는 task를 다룰 때 좋다.

여기서 $f()$는 vertice를 1 ~ n으로 변환하는 함수이다. 그리고 1 ~ n은 각 vertex에 지정된다.

vertex가 지정받은 숫자가 큰 것이 head 역할(화살표 위치)을 맡아야 한다.

Graph는 cycle이 없어야한다. 있으면 topological ordering이 안된다. (전제에 대한 오류가 된다.)

cycle만 없으면 바로 topological ordering 설정 가능하다.

![Image](https://i.imgur.com/s7vqFm9.jpg)

![Image](https://i.imgur.com/tA3zVYd.jpg)

최소한 하나의 sink vertex(vertex without outgoing arcs)가 있어야한다.

안그러면 cycle이 생긴다. 그러면 전제와는 반대로 되는 문제가 있다.

첫 번째 그림이 정상인 경우고, 두 번째 그림이 오류인 경우이다.

마지막 위치에는 sink vertex가 올 수 밖에 없다.

이걸 이용해서 역순으로 recursive하게 문제를 푼다.

참고로 이 영상에서는 이 recursive call이 동작한 곳이 delete되었다는 식으로 설명한다.

![Image](https://i.imgur.com/vlzHYRA.jpg)

DFS-Loop은 DFS를 감싸는 더 큰 Loop이다. 즉, 전체 프로그램. 그리고 시작하는 vertice는 그냥 임의로 정한다.

참고로 edge를 for 문 돌릴 때 방향이 맞는 건만 for문에 포함한다는 것을 잊지말자.

그리고 빨간색 부분이 back-tracking되는 것.

![Image](https://i.imgur.com/hF9hwW4.jpg)

BFS와 비슷하게, n개의 node를 1번 보고, m개의 edge를 한 번 보니까, O(m + n)이다.

![Image](https://i.imgur.com/ExQksnD.jpg)

# Computing Strong Components

---

strong connected graph는 한 포인트에서 어떤 포인트로던 서로 오갈 수 있는 graph를 얘기한다.

SCC는 그 자체로 maximal region을 차지하게 된다. 

보라색 원으로 표시된 부분이 SCC이다. 

또한 보라색 원을 하나의 node로 볼 때, 왼쪽에서 오른쪽으로 이동하는 것만 가능하다.

![uploading...](http://i.imgur.com/uploading.png)
![Image](https://i.imgur.com/J8A2Net.jpg)
빨간 원에서 시작한다고 하면 그냥 삼각형만 찾고 끝이다.

즉, 하나를 고르면 그에 해당하는 SCC를 구할 수 있다는 것이다.

하지만 초록색을 고르면 빨간색이 있는 영역까지도 구하게 되고,

노란색을 고르면 아예 전체 영역을 search하게 된다.

**즉, 하나의 SCC만 탐색하는 알고리즘이 필요하다.**

![Image](https://i.imgur.com/anxZk3S.jpg)

참고로 edge의 최소 개수는 node의 개수이다.

과정은 아래 그림을 통해 보자.

first pass는 node의 order를 정하고, second pass에서는 SCC를 찾는다.

first pass에서는 second order가 향할 순서를 정한다. SCC를 정확히 한 번에 찾도록하는 순서

이 때, finishing time도 같이 계산된다.

second pass에서는 각각의 node 중 leader에 label을 한다. SCC 구성원은 모두 같은 leader 표시가 된다.

![Image](https://i.imgur.com/69OtbUN.jpg)

기존의 DFS LOOP함수를 고친다. forward, reverse pass 총 두번 호출된다.ㄴ

t = finishing time 측정. 지나간 node의 개수를 의미한다. first pass에 계산.

s = leaders. second pass하고만 연관이 있다. 가장 최근의 DFS가 시작된 vertex를 추적한다. second pass에 계산

처음 loop은 label을 붙여서한다. 그 다음은 label을 finishing time으로 바꿔서 쓴다.

![Image](https://i.imgur.com/oX11fFY.jpg)

위의 알고리즘을 그대로 실행해보자. 다음과 같이 finishing time이 구해진다.

![Image](https://i.imgur.com/1eYwgxs.jpg)

이어서는 각 label을 finishing time으로 변경한다. 

그리고 모든 edge의 방향을 반대로 뒤집는다. 

그리고 방금 알고리즘을 다시 돌리면 아래처럼 leader가 정해진다. 또한 한 번의 DFS마다 하나의 SCC가 발생한다.

![Image](https://i.imgur.com/nt3p3Rv.jpg)

DFS의 시간복잡도의 2배이므로, 그 크기가 같다.

# Analysis of Computing Strong Components

---

이제 General Argument를 따져보자.

metagraph는 하나의 SCC이다.

arc : meta graph에서 다른 meta graph로 향하는 edge, node에서 node로 가는 edge

![Image](https://i.imgur.com/VuPEkXD.jpg)

앞선 예제에서 해봤듯이 그냥 같은 갯수의 SCC가 나온다.

![Image](https://i.imgur.com/pLSm9lE.jpg)

C1의 가장 큰 finishig time은 C2의 가장큰 finishing time보다 작다.

second pass에서, 그래프 전체에서 가장 큰 finishing time부터 DFS를 시작한다는 것을 생각하자.

f2와 f3는 비교할 수 없다.

아래 결과를 보면, max finishing time in entire graph는 결국 node4에 있다고 한다.

![Image](https://i.imgur.com/BGTac6m.jpg)

어디서 DFS가 시작할지가 중요하다. sink SCC인 C4에서 시작하는 것은 이 최적. 하나의 SCC만 찾을 수 있으니까

C1에서 시작하는 것이 최악이다. 모든 SCC를 찾을 수 있게 되고, 그러면 우리의 목적에 어긋난다.

그래서 sink SCC부터 시작할 수 있게 finishing time이 가장 큰 수가 sink에 가게 한 것이다.

![Image](https://i.imgur.com/vuuP8Zw.jpg)

reverse graph에서의 효과를 살펴본다. 사실상은 forward graph와 차이는 없다.

케이스를 처음 보는 vertex가 C1에 있냐 C2에 있냐로 나눠서 살피자.

C1에서 C2로 넘어갈 수는 없으므로, C1에서의 finishing time은 무조건 C2보다 작을 수밖에 없다.

아래 정리는 당연하므로 그냥 읽어보자. 어차피 기억할 필요까지는 없다.

![Image](https://i.imgur.com/jarc2vm.jpg)

# Structure of the Web (Optional)

---

# Reference

---

[공부하는 완시 (tistory.com)](https://jesus-never-fail.tistory.com/28)

[그래프 기본 용어 · ratsgo's blog](https://ratsgo.github.io/data%20structure&algorithm/2017/11/18/graph/)