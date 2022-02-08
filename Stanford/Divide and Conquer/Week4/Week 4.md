# Week 4

# Linear Time Selection

---

## Randomized Selection

이번에도 randomized algorithm을 만든다.

mean보다 median이 더 robust하다.

원소 하나가 변하면 mean은 크게 변하지만 median은 보통 그대로이다.

![slides_algo-select-ralgorithm_typed_page-0003.jpg](Week%204%2043144c44a80c4549833a3cd62cca6191/slides_algo-select-ralgorithm_typed_page-0003.jpg)

reduction : 이미 풀 줄 아는 다른 방법으로 푸는 것

selection을 sorting으로 바꿔서 푼다는 건데, 문제는 sorting prob은 최소 O(nlog(n))의 시간복잡도까지만 줄일 수 있다.

QuickSort를 조금 변경해서 풀도록한다.

![slides_algo-select-ralgorithm_typed_page-0004.jpg](Week%204%2043144c44a80c4549833a3cd62cca6191/slides_algo-select-ralgorithm_typed_page-0004.jpg)

QuickSort를 본따서 만든다.

recursion은 어떻게 해야할까?

![slides_algo-select-ralgorithm_typed_page-0005.jpg](Week%204%2043144c44a80c4549833a3cd62cca6191/slides_algo-select-ralgorithm_typed_page-0005.jpg)

5번째 수를 찾는 중이다.

랜덤으로 고른 수가 3번째로 끝나면, 오른쪽 서치를 들어가고 그 오른쪽 array에서 2번째인 수를 고르면 될 것이다.

![slides_algo-select-ralgorithm_typed_page-0006.jpg](Week%204%2043144c44a80c4549833a3cd62cca6191/slides_algo-select-ralgorithm_typed_page-0006.jpg)

이걸 일반화한다.

j = 정렬 이후 p의 위치

마지막 5)번이 방금 위의 문제에서 만났던 경우이다.

![slides_algo-select-ralgorithm_typed_page-0007.jpg](Week%204%2043144c44a80c4549833a3cd62cca6191/slides_algo-select-ralgorithm_typed_page-0007.jpg)

이제는 Correction을 따져야 할 때이다.

![slides_algo-select-ralgorithm_typed_page-0008.jpg](Week%204%2043144c44a80c4549833a3cd62cca6191/slides_algo-select-ralgorithm_typed_page-0008.jpg)

QuickSort와 같은 구조를 가지므로 worst case는 다음과 같다.

median을 찾는다고 가정하고, pivot을 그 array에서 최소의 수로 정한다고 하면 다음과 같을 것이다.

![slides_algo-select-ralgorithm_typed_page-0009.jpg](Week%204%2043144c44a80c4549833a3cd62cca6191/slides_algo-select-ralgorithm_typed_page-0009.jpg)

Key : 문제를 subprob으로 나눌 때마다, 그 크기가 크게 줄어든다. (divided by some factor)

master method를 쓸 때, recursion 밖의 시간복잡도는, comparison 작업만 따지므로 O(n)이 된다.

![slides_algo-select-ralgorithm_typed_page-0010.jpg](Week%204%2043144c44a80c4549833a3cd62cca6191/slides_algo-select-ralgorithm_typed_page-0010.jpg)

random pivot으로는 어떤가?

![slides_algo-select-ralgorithm_typed_page-0011.jpg](Week%204%2043144c44a80c4549833a3cd62cca6191/slides_algo-select-ralgorithm_typed_page-0011.jpg)

여기서 data는 아무런 상관이 없다.(random, general purpose)

randomness in code not in data

## Randomized Selection - Analiysis

아래 증명에서 phase j란, 얼마나 recursion이 일어난 횟수이다.

명확히는 75퍼센트보다 더 적은 크기로 줄어든 것을 하나의 recursion이 일어났다고 보는 것이라고 생각하면 되겠다.

여기서 $c$ = phase j일 때 하는 work

$(3/4)^j * n$ = upper bound in phase j

$X_j$ = # of recursive calls during phase j = # of subprobs in phase j

randomized algorithm이기 때문에, running time of RSelect는 random variable이다.

물론 오른쪽도 $X_j$때문에 random variable이다.

![slides_algo-select-ranalysis_typed_page-0004.jpg](Week%204%2043144c44a80c4549833a3cd62cca6191/slides_algo-select-ranalysis_typed_page-0004.jpg)

![slides_algo-select-ranalysis_typed_page-0005.jpg](Week%204%2043144c44a80c4549833a3cd62cca6191/slides_algo-select-ranalysis_typed_page-0005.jpg)

Geometric Random Variable은 Geometric distribution(이산 확률 분포)의 확률변수를 얘기하는 것이다.

최소한 한 번의 flip은 필요하므로 일단은 1이상일 것이다. 이를 이용해서 점화식을 쓴다.

![slides_algo-select-ranalysis_typed_page-0006.jpg](Week%204%2043144c44a80c4549833a3cd62cca6191/slides_algo-select-ranalysis_typed_page-0006.jpg)

이를 이용해서 정리하면 다음과 같이 증명이 끝난다.

![slides_algo-select-ranalysis_typed_page-0007.jpg](Week%204%2043144c44a80c4549833a3cd62cca6191/slides_algo-select-ranalysis_typed_page-0007.jpg)

# Linear Time Selection (Optional) - Skipped

---

# Graphs and the Contraction Algorithm

---

## Graphs and Minimum Cuts

![slides_algo-karger-overview_typed_page-0002.jpg](Week%204%2043144c44a80c4549833a3cd62cca6191/slides_algo-karger-overview_typed_page-0002.jpg)

vertex, vertices : 꼭짓점

edge : 두 vertices를 묶은 것. 즉, 선.

![slides_algo-karger-overview_typed_page-0003.jpg](Week%204%2043144c44a80c4549833a3cd62cca6191/slides_algo-karger-overview_typed_page-0003.jpg)

cut은 Vertices의 부분 집합. 여기서는 A, B

crossing edge는 A, B를 지나는 edge

undirected와 directed edge 둘의 차이는 방향의 유무이다.

directed된 경우, left to right의 경우만 cut되었다고 가정한다. tail을 A에 head를 B에 따로 둔다.

![slides_algo-karger-overview_typed_page-0004.jpg](Week%204%2043144c44a80c4549833a3cd62cca6191/slides_algo-karger-overview_typed_page-0004.jpg)

n개의 원소마다 A 혹은 B를 선택하라고 하면 되니까, 결과는 $2^n$

![slides_algo-karger-overview_typed_page-0005.jpg](Week%204%2043144c44a80c4549833a3cd62cca6191/slides_algo-karger-overview_typed_page-0005.jpg)

**min cut = 가장 적은 crossing edges를 가진 cut**

parallel edge란, 아래 그림처럼 하나의 vertice에 여러 edge가 있는 경우를 의미한다.

![slides_algo-karger-overview_typed_page-0006.jpg](Week%204%2043144c44a80c4549833a3cd62cca6191/slides_algo-karger-overview_typed_page-0006.jpg)

가장 많은 부분을 감싸면 되니까, 저렇게 된다.

![slides_algo-karger-overview_typed_page-0007.jpg](Week%204%2043144c44a80c4549833a3cd62cca6191/slides_algo-karger-overview_typed_page-0007.jpg)

min cut의 다양한 활용

![slides_algo-karger-overview_typed_page-0008.jpg](Week%204%2043144c44a80c4549833a3cd62cca6191/slides_algo-karger-overview_typed_page-0008.jpg)

## Graph Representation

일렬로 연결하면 최소로 $n-1$이 나오고, 각각 연결하면 $n + n-1 + n-2 + \dots = n(n-1)/2$

![slides_algo-karger-representations_typed_page-0003.jpg](Week%204%2043144c44a80c4549833a3cd62cca6191/slides_algo-karger-representations_typed_page-0003.jpg)

m을 구하려면 최소 $n-1$에 최대 $n(n-1)/2$이므로, 그 시간복잡도의 최소 최대치가 $\Omega (n) \space , \space O(n^2)$이다.

후에는 parallel arc를 허용할 것이다. 물론 no parallel edges가 더 흔하다.

![slides_algo-karger-representations_typed_page-0004.jpg](Week%204%2043144c44a80c4549833a3cd62cca6191/slides_algo-karger-representations_typed_page-0004.jpg)

edges를 matrix로 표현한다.

vertices 사이에 edge가 있으면 그 행렬 원소는 1이다.

1을 넘는 정수를 이용해서 parallel edges를 표현할 수도 있다.

edge의 weight를 표현할 수도 있다.

1, -1을 이용해서 방향을 표현할 수도 있다.

...

여기서 중요한 건

1. space the data structure needs
2. data structure의 operation

![slides_algo-karger-representations_typed_page-0005.jpg](Week%204%2043144c44a80c4549833a3cd62cca6191/slides_algo-karger-representations_typed_page-0005.jpg)

Adjacency Matrix에서는 결국 n^2의 공간이 필요하다. 

다만 sparese한 경우에는 거의 linear한 data라서, 이렇게 표현하면 낭비다.

![slides_algo-karger-representations_typed_page-0006.jpg](Week%204%2043144c44a80c4549833a3cd62cca6191/slides_algo-karger-representations_typed_page-0006.jpg)

sparse한 데이터를 Lists로 표현한다고 하면 다음과 같은 성분들이 필요하다.

특히 vertex와 edge를 상호 확인이 가능하게 해야한다.

edge point → endpoint

vertext points → edges incident

![slides_algo-karger-representations_typed_page-0009.jpg](Week%204%2043144c44a80c4549833a3cd62cca6191/slides_algo-karger-representations_typed_page-0009.jpg)

세번째와 네번째 정보는 일대일 대응 되므로, 그 space 복잡도가 같아야한다t.

이건 문제

![slides_algo-karger-representations_typed_page-0008.jpg](Week%204%2043144c44a80c4549833a3cd62cca6191/slides_algo-karger-representations_typed_page-0008.jpg)

## Random Contract Algorithm

vertices를 1씩 줄인다. 2개가 남으면 멈춘다.

두개의 vertices를 합친다...! 이를 contraction이라고 부른다.

그리고 parallel edges는 놔두고, self loop은 없앤다.

총 N-2 generation을 거친다.

![slides_algo-karger-algorithm_typed_page-0003.jpg](Week%204%2043144c44a80c4549833a3cd62cca6191/slides_algo-karger-algorithm_typed_page-0003.jpg)

random하게 하나의 edge를 골라서, 두 개의 vertices를 계속 fuse한다.

그 결과 융합된 A영역과 나머지 B영역이 남는다.

**이런 fusing 과정을 cut하는 것과 동치로 볼 수 있다.**

![slides_algo-karger-algorithm_typed_page-0004.jpg](Week%204%2043144c44a80c4549833a3cd62cca6191/slides_algo-karger-algorithm_typed_page-0004.jpg)

다른 경우를 찾아본다. 이 경우는 min cut이 아닌 걸 알 수 있다.

그래서 맞는 답을 낼 확률을 알아야 한다.

![slides_algo-karger-algorithm_typed_page-0005.jpg](Week%204%2043144c44a80c4549833a3cd62cca6191/slides_algo-karger-algorithm_typed_page-0005.jpg)

## Analysis of Random Contract Algorithm

지난 번까지 한 것 정리

![slides_algo-karger-analysis_typed_page-0002.jpg](Week%204%2043144c44a80c4549833a3cd62cca6191/slides_algo-karger-analysis_typed_page-0002.jpg)

![slides_algo-karger-analysis_typed_page-0003.jpg](Week%204%2043144c44a80c4549833a3cd62cca6191/slides_algo-karger-analysis_typed_page-0003.jpg)

문제 정의

min cut(A, B)를 평균 내고 이를 FIX한다. 만약 다른 output을 낸다면 그건 무시한다.

graph를 고정한다. n은 vertices, m은 edges를 의미한다.

crossing edges를 F라고 명명하고, 그 갯수는 k가 된그런데 

![slides_algo-karger-analysis_typed_page-0004.jpg](Week%204%2043144c44a80c4549833a3cd62cca6191/slides_algo-karger-analysis_typed_page-0004.jpg)

다음의 생각 과정에 따라서 Contraction이 F에 일어나면 안된다는 것을 알 수 있다.

A와 B가 서로 내부에 있는 node 끼리만 fuse하면 정답 (A, B)가 나온다.

꺽쇠 표시는 NOT을 의미한다.

![slides_algo-karger-analysis_typed_page-0005.jpg](Week%204%2043144c44a80c4549833a3cd62cca6191/slides_algo-karger-analysis_typed_page-0005.jpg)

당연한 문제

그 다음 iteration에서는 m이 1만 낮아지는 게 아니라 더 많이 낮아질 수도 있는데, 이는 self loop 때문이다.

![slides_algo-karger-analysis_typed_page-0006.jpg](Week%204%2043144c44a80c4549833a3cd62cca6191/slides_algo-karger-analysis_typed_page-0006.jpg)

애초에 min cut 자체가 원래는 랜덤으로 잘라서 생기는 최소 K를 의미하는 것이므로, 모든 vertex에 대해서 최소 K의 F를 가지는 것이 맞다.

edge 하나에 degree는 2개 올라간다.

![slides_algo-karger-analysis_typed_page-0007.jpg](Week%204%2043144c44a80c4549833a3cd62cca6191/slides_algo-karger-analysis_typed_page-0007.jpg)

조건부 확률의 정의를 이용한다.

모든 node의 cut 결과는 k이다.

![slides_algo-karger-analysis_typed_page-0008.jpg](Week%204%2043144c44a80c4549833a3cd62cca6191/slides_algo-karger-analysis_typed_page-0008.jpg)

contraction algorithm이 성공하는 lower bound를 구하는 것.

즉, lower bound가 $1/n^2$그

그런데 너무 확률이 적다는 문제가 있다. 그런데 전체를 이분하는 cut은 이것보다 더 낮다고 한다...

![slides_algo-karger-analysis_typed_page-0009.jpg](Week%204%2043144c44a80c4549833a3cd62cca6191/slides_algo-karger-analysis_typed_page-0009.jpg)

독립 사건이므로, 확률을 서로 곱할 수 있다.

![slides_algo-karger-analysis_typed_page-0010.jpg](Week%204%2043144c44a80c4549833a3cd62cca6191/slides_algo-karger-analysis_typed_page-0010.jpg)

$n^2\log(n)$번의 시도를 함으로써, 실패 확률의 upper bound를 $1/n$까지 낮출 수 있다.

시간복잡도는, $n^2$의 시도와, 모든 edges를 살펴야하므로 $m$까지 곱해줘야한다.

![slides_algo-karger-analysis_typed_page-0011.jpg](Week%204%2043144c44a80c4549833a3cd62cca6191/slides_algo-karger-analysis_typed_page-0011.jpg)

## Counting Minim um Cuts

이번엔 Graph가 1개 보다 더 많은 min cut을 가지는 경우로 제한해서 본다.

n개의 vertice가 있을 때, 가장 큰 min cut은 얼마인가?

![slides_algo-karger-counting_typed_page-0002.jpg](Week%204%2043144c44a80c4549833a3cd62cca6191/slides_algo-karger-counting_typed_page-0002.jpg)

두 개의 edge를 골라서 제거하면 cut이 발생한다.

![slides_algo-karger-counting_typed_page-0003.jpg](Week%204%2043144c44a80c4549833a3cd62cca6191/slides_algo-karger-counting_typed_page-0003.jpg)

앞서서 min cut(A, B)를 fix해서 주어진 min cut을 구하는 것만을 생각했었다.

즉, 특정한 (A_i, B_i)를 구하는 것과 같은 이치.

여기서 (A_i, B_i)를 구하는 확률을 구하자.

여기서 S_i는 disjoint이다.

t는 (A_i, B_i)를 구하는 갯수이다.

![slides_algo-karger-counting_typed_page-0004.jpg](Week%204%2043144c44a80c4549833a3cd62cca6191/slides_algo-karger-counting_typed_page-0004.jpg)

# Reference

---

[Min Cut에 대한 설명](https://www.crocus.co.kr/755)