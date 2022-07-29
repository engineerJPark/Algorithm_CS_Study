# Week 1

## Motivation

Web 환경은 Graph로 표현이 간편하다.

![Image](https://i.imgur.com/BrwumBg.png)

그리고 빠른 통신을 위해서 그래프 내에서 출발-목적지 간 최소 경로를 찾아야만 한다.
앞으로는 이를 알아볼 것이다.

![Image](https://i.imgur.com/TnfD2ge.png)

이런 문제에 Dijkstra Algorithm을 사용할 수도 있지만, 문제는 Web은 그 크기가 매우 크다는 문제가 있다. Dijkstra로는 이 크기를 감당하지 못한다.

하지만, 각 node가 이웃 node와 interaction을 유지하고 상호작용하면, 모든 목적지 node에 대하여 shortest path에 수렴하는 path를 찾을 수 있을 것이다.
그래서 distributed(분산되는) implementation이 가능한 알고리즘을 사용해야한다.

그중 하나가 Bellman Ford Algorithm을 사용한다.
이 알고리즘은 local computation만으로 최소경로를 찾고, 각 vertex는 이웃 vertex와 매번의 pass마다 상호작용한다. 또한 음의 가중치를 가진 경로도 이용 가능하다.

---

## Sequence Alignment

![Image](https://i.imgur.com/fYpZu9Z.png)

![Image](https://i.imgur.com/4GaXAgq.png)

위의 그림과 같이, 2가지 차이가 있다. 하나는 빈 공간이고, 하나는 문자가 다르다.

즉, similarity는 best alignment를 통하여 구할 수 있다.

하지만 어떠한 유형의 dissimilarity가 더 치명적인지 알아야할 필요가 있다. gap인가 mismatch인가?

![Image](https://i.imgur.com/SnzLGVC.png)

이제 problem을 state해보자.

input으로는 string, output으로는 penalty를 최소로하는 alignment를 내보낸다.

이를 또 다르게 생각할 수 있다. 이 minimum cost alignment를 string 1이 어떻게 string 2로 변화한 것에 관한 일종의 변수로 볼 수도 있다.
이렇게 보게 된다면, gap의 경우 deletion을 하지 않는 작업으로 볼 수 있고, mismatch의 경우 mutation이라고 볼 수 있다.

이런 penalty score를 Needleman-Wunsch score라고 한다.

만약 비슷한 string이라면 이 NW score가 0에 가까울 것이다.

![Image](https://i.imgur.com/jRkrvnz.png)

이제 best alignment를 찾기 위해서 NW score를 측정하는 알고리즘을 찾아보자.

우선, brute force 알고리즘으로 모든 경우의 수의 NW score를 찾고, best alignment를 찾는 방법이 있다.
하지만 너무 많은 계산양 때문에, 이런 방법은 실현될 수 없다.

--- 

## Greedy Algorithm

이 강좌 전반에서 말하는 거지만, 계산을 효율적으로 하는 일반적인 방법은 없다.
다만 일반적으로 많이 사용되는 테크닉을 익히고 알고리즘을 설계하는 것이 이 강좌의 목표이다.

아래는 테크닉들의 예시이다.
여기서 greedy algorithm은 Dijkstra Algorithm에서 사용되는 방법이다.
dynamic programming은 앞서 본 sequence alignment나 distributed shortest path에서 자주 사용되는 방법이다.

![Image](https://i.imgur.com/9xDlPyw.png)

여기서는 greedy algorithm을 살펴본다.
greedy algorithm은 대체로 어떤 특성을 지닐까?
일단 근시적이라고 볼 수 있다. 한 시점마다 가장 좋은 것을 선택하고, 그것이 계속되기를 바라는 것이다.

예를 들어 다익스트라 알고리즘이 있다.
하나의 shortest path를 찾아내고, 다시 돌아가지도 않고 계속 가장 짧은 경로를 찾아서 진행한다.

![Image](https://i.imgur.com/5Zfk5lC.png)

다음은 Divide & Conquer 방법과 비교하여 알 수 있는 Greedy Algorithm의 장단점이다.

![Image](https://i.imgur.com/i04MVsz.png)

Greedy Algorithm은 일반적으로는 보통 not correct하다. 이를 유념해두고 항상 정합성에 대한 증명을 해야한다. 

다음은 다익스트라 알고리즘에서 그래프 가중치가 음의 수 일때 오류가 나는 경우를 문제로 만든 것이다.
보다시피 다익스트라 알고리즘에 따라서 최종 거리가 1이 되는 목적지 가 아니라 2인 목적지로 가게 된다는 것을 알 수 있다.

![Image](https://i.imgur.com/kKZa7gF.png)

증명 방법은 다음과 같이 세가지가 있다.  

1. induction : “greedy stays ahead”
   - Greedy Algorithm은 매번 최상 선택을 하는 것이 반복되므로, induction은 algorithm에 의해서 결정된다. 
   - 다익스트라의 증명을 이와같이 행했다.
   - "직전의 상황이 모두 맞았다면, 현재의 연산 또한 맞다."
2. exchange of argument 
   - 하나는 contradiction으로 접근한다. Greedy Algorithm이 틀리다는 가정으로 접근하고, optimal solution을 가르키고, optimal solution의 두 element를 서로 exchange하여, 더 나은 결과를 보인다. 이를 통해서 optimal solution이라는 가정이 부정된다. 따라서 Greedy Algorithm이 증명된다.
   - 다른 하나는 optimal solution을 점점 더 greedy algorithm의 output으로 exchange하여 증명하는 것이다. 단, 이때 worse하지는 않아야한다.
     - greedy algorithm의 output으로 변경하는 횟수는 induction처럼 구해야한다.
3. anything


## Application: Optimal Caching

Cache Memory는 작고 빠른 메모리이다. 저장 공간이 작아서, 기존 데이터를 지우고 새로 써야하는 경우가 발생한다.

![Image](https://i.imgur.com/MEfuC0A.png)

다음을 보자. 문제는 cache에 없는 것에 대해서 접근이 요청될 때 발생한다. 이를 fault라고 하는 것이다.
e, f를 받을 때 fault가 발생했고, 그 뒤에 오는 a, b는 e, f로 교체됨에 따라 접근이 또 불가능해졌다.

![Image](https://i.imgur.com/Qf3zq4Q.png)

이 문제를 푸는 natural greedy algorithm 중 optimal한 algorithm을 “furthest-in-future” algorithm이라고 부른다.

![Image](https://i.imgur.com/nPpJKSG.png)

----

## Scheduling Application

작업에 weight와 length가 주어질 때, 어떻게 배치하는 것이 가장 효율적인가?

기본적으로 각 job에는 weight와 length가 주어진다고 하자.

![Image](https://i.imgur.com/lrWJX6M.png)

다음과 같은 경우 각 task 별 종료 시간은 다음과 같다.

![Image](https://i.imgur.com/zUe5XjT.png)

여기에 weight가 추가되는 경우, 다음과 같이 계산해야한다.

![Image](https://i.imgur.com/fibGMM4.png)

이 score function을 분석하자. 이 score function은 weight가 큰 것이 빠르게 올 수록 유리하고,
length가 작은 것이 빠르게 올 수록 유리하다.(score function = completion time이 작아진다.)

![Image](https://i.imgur.com/xwdiP19.png)

하지만 이를 동시에 고려하는 것은 어렵다. 이를 위해서 score를 따로 지정해주어서 task의 순서를 지정한다.

아래와 같이 빼기 혹은 나누기를 통해서 정할 수 있다.

이 둘 중 더 우수한 것을 고르기 위해서는, 다른 하나의 task가 부적절함을 보여야한다.

![Image](https://i.imgur.com/d132OPw.png)

아래의 경우와 같이, 나누기거 더 좋은 선택임을 볼 수 있다.

빼기의 경우 task 1 = -2, task 2 = -1이고
나누기의 경우 task 1 = 0.6, task 2 = 0.5이다.

빼기 score와 나누기 score 모두, 그 score가 큰 것이 더 앞으로 나와야한다.

따라서 빼기는 task2가 먼저 실행되고, 그 결과 23 score를 보인다.
나누기는 task1이 먼저 실행되어, 그 결과 22 score를 보인다.

![Image](https://i.imgur.com/dEBtzJu.png)

이를 정리하면 다음과 같이 score를 나누기로 정의할 수 있고, running time은 O(nlogn)이 된다.
이는 sorting만 수행하면 되기 때문이다.

![Image](https://i.imgur.com/X6zo9FD.png)

# Proof of the Scheduling Application

위의 Claim을 어떻게 증명할 것인가?

기존 greedy schedule보다 더 성능이 좋은 sigma\*를 가정하고, 이 sigma\*보다 더 좋은 성능의 알고리즘이 있음을 증명해서 contradiction을 만들어 증명할 것이다.

![Image](https://i.imgur.com/gPdHGvt.png)

앞서 말했듯이 score가 클 수록 일찍와야한다. 그리고 sigma*는 이 순서를 반대로 뒤집은 단 두 개의 index i,j 순서대로 schedule을 잡아놓는다.

![Image](https://i.imgur.com/C1qNZBV.png)

다음을 보자.
sigma*에 있는 i, j 작업을 서로 변경해줘서 새로운 schedule을 만든다.

![Image](https://i.imgur.com/58Ur083.png)

이렇게 했을 때 어떤 일이 발생하는가?
우선 후순위로 밀린 작업은 completion time이 늘어나고, 선순위로 당겨진 작업은 completion time이 줄어들게 된다.

![Image](https://i.imgur.com/64PMqsX.png)

이렇게 얻게된 exchange의 부산물을 cost / benefit of exchange라고 한다.
이들의 계산은 아래와 같이 하면 된다.

이 때, 아래의 계산과 같이, benefit이 cost보다 더 크므로, sigma*보다 새로운 schedule이 더 효과적임을 알 수 있다.

즉, sigma*는 존재하지 않는다. 따라서 초기의 주장이 옳다.

![Image](https://i.imgur.com/47w2xsS.png)

# MST : Minimum Spanning Trees

Minimum Spanning Tree란?
각 지점을 가장 저비용으로 연결하는 것이 목표이다.

heap structure를 이용해서 알고리즘의 빠른 속도를 이용한다.

Kruskal Algorithm의 경우, union fine data structure를 새로 정의하여 사용한다.

![Image](https://i.imgur.com/4sJJgvl.png)

오로지 undirected graph에서만 문제가 정의된다.

Spans all vertices라는 것의 의미는 다음과 같다.

- 루프가 없어야한다.
- 모든 두 subgraph(혹은 vertex)가 연결되어야 한다.

![Image](https://i.imgur.com/JC85K3p.png)

본 강의에서는 다음과 같이 가정을 한다.

첫 번째 가정이 지켜지지 않을 경우, forest가 생기고, 이를 위해서는 minimum spanning forest를 푸는 방식으로 발전해야한다.

두 번째 가정은 깨지더라도, Prim 알고리즘과 Kruskal 알고리즘은 그대로 MST를 구한다.

![Image](https://i.imgur.com/3wFEMXX.png)

## Prim's MST Algorithm

다익스트라 알고리즘과 매우 유사하다.

다익스트라는 시작점이 명확히 있었지만, 여기서는 아니다.
그러나 임의로 시작점을 지정해서 시작해도 상관없다.

다음의 순서를 따른다고 하자.
- 우측상단을 시작점으로 잡는다.
- cheapest한 cost 1의 edge를 선택한다.
- 이렇게 spanning tree가 일부 발생한다.
- 그 다음 또 cheapest한 cost 2의 edge를 고른다.
- 이제 cost 3 edge는 vertex를 추가하지 못하므로 제외한다.
- 이제 나머지 cost 4 edge를 선택한다.

이렇게 Minimum Cost Spanning Tree가 완성된다.

![Image](https://i.imgur.com/DVKMqni.png)

이제부터는 Pseudo Code를 보자.

- X는 spanning에 추가된 정점
- T는 edge를 추가한다.
- 알고리즘은 모든 vertex를 span할 때까지 반복한다.
- edge는 하나의 정점이 X에 포함되게 하나는 X 밖에 있는 edge를 선택한다.

![Image](https://i.imgur.com/MSNqIhh.png)

Prim 알고리즘은 spanning tree를 minimum cost로 반환하는 것이 자명하다.

이를 증명하려면, 다음과 같이한다.

- spanning tree를 하나 만든다. 최소가 아니라고 가정하고
- 그리고 이것이 최소임을 보인다.

![Image](https://i.imgur.com/tKh38EJ.png)

## Correctness Proof

![Image](https://i.imgur.com/F3WxXU2.png)

![Image](https://i.imgur.com/m1EqwX8.png)

![Image](https://i.imgur.com/VzWcG6G.png)

![Image](https://i.imgur.com/FjNFcBJ.png)

![Image](https://i.imgur.com/ueRfcCt.png)

![Image](https://i.imgur.com/XGN6xdD.png)

![Image](https://i.imgur.com/jaRfanF.png)

![Image](https://i.imgur.com/BMMRoXo.png)
## Proof of Cut Property (Skip)

![Image](https://i.imgur.com/cRkAwGe.png)

![Image](https://i.imgur.com/K8jhiiT.png)

![Image](https://i.imgur.com/WtpoIu2.png)

![Image](https://i.imgur.com/uyY76Jf.png)

![Image](https://i.imgur.com/T83TZDi.png)

# Fast Implementation

![Image](https://i.imgur.com/EyYZV6Q.png)

![Image](https://i.imgur.com/iIEqNmY.png)

![Image](https://i.imgur.com/suU9zRV.png)

![Image](https://i.imgur.com/L29eMpD.png)

![Image](https://i.imgur.com/NpM3Jzg.png)