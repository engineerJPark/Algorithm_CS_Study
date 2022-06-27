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

---

