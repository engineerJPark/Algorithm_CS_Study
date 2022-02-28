# Week 2

# Part 3

# Divide & Conquer Algorithm

Divide and Conquer를 하는 원칙

Subproblem을 만든다.
Conquer via recursive calls
Combine solutions of subproblems into one : for the original problem

![Untitled](Week%202%2019aabfd5e2d6475cb125132b26a28525/Untitled.png)

그림과 같이, sorted list와 주어진 list 사이에서 graph를 그려서 그 사이의 교차점의 개수를 세서 답을 구할 수도 있다.

![Untitled](Week%202%2019aabfd5e2d6475cb125132b26a28525/Untitled%201.png)

다음은 문제다.

![Untitled](Week%202%2019aabfd5e2d6475cb125132b26a28525/Untitled%202.png)

모든 원소가 inversed 된 상태임을 가정하면 5+4+3+2+1=15가 된다.

새로운 알고리즘을 도입해서 Divide and Conquer를 한다. 이를 이용해서 O(nlogn)으로 만든다.

![Untitled](Week%202%2019aabfd5e2d6475cb125132b26a28525/Untitled%203.png)

이를 pseudo code로 만들면 다음과 같다.

![Untitled](Week%202%2019aabfd5e2d6475cb125132b26a28525/Untitled%204.png)

## Piggybacking on Merge Sort

다른 방법으로, inversion을 세는 것과 동시에, sorted list를 반환하는 것도 한다.

이를 Piggybacking on Merge Sort라고 한다.

![Untitled](Week%202%2019aabfd5e2d6475cb125132b26a28525/Untitled%205.png)

![Untitled](Week%202%2019aabfd5e2d6475cb125132b26a28525/Untitled%206.png)

B,C에서 D로 Merge sort할 때와 같은 방법으로 옮길 때, 서로 다른 split에서 D로 옮겨지는 것을 보고 inversion을 파악할 수 있다.

단, 아래 그림과 같이 subprob인 B와 C는 sorted 되어있어야한다.

2를 옮길 때, 3,5보다 그 split에서의 index가 작으므로 inversion이 있다고 파악할 수 있다.

4도 마찬가지로, 3,5보다 그 split에서의 index가 작으므로 inversion이 있다고 파악할 수 있다.

![Untitled](Week%202%2019aabfd5e2d6475cb125132b26a28525/Untitled%207.png)

## General Claim

여기선 x가 왼쪽의 B array의 원소이고, y가 오른쪽의 C array의 원소가 되겠다.

Claim에 따르면, inversion의 개수는 y를 D로 옮기는 시점에서 B에서의 남은 index 개수를 모든 경우를 모아 합한 것으로 친다는 것이다.

![Untitled](Week%202%2019aabfd5e2d6475cb125132b26a28525/Untitled%208.png)

Big O 계산에 고려되는 대상은 merge 과정에서의 O(n)와, 반복횟수를 측정하는 O(n)이다.

![Untitled](Week%202%2019aabfd5e2d6475cb125132b26a28525/Untitled%209.png)

# Matrix Multiplication and Strassen Algorithm

---

Dot product로 계산하면 $O(n^3)$ 된다. 

이를 해결하기 위해 Strassen Multiplication을 이용한다.

![Untitled](Week%202%2019aabfd5e2d6475cb125132b26a28525/Untitled%2010.png)

![Untitled](Week%202%2019aabfd5e2d6475cb125132b26a28525/Untitled%2011.png)

그래서 이 cleverly chosen된 7은 무엇인가? 다음 사진에서 알아볼 수 있다.

![Untitled](Week%202%2019aabfd5e2d6475cb125132b26a28525/Untitled%2012.png)

Strassen’s Algorithm을 적용한다.

이 일곱개의 행렬(P_1 ~ P_7)을 구한 후 덧셈 – 뺄셈 만으로 곱셈 결과를 구할 수 있다.

![Untitled](Week%202%2019aabfd5e2d6475cb125132b26a28525/Untitled%2013.png)

# O(n log n) Algorithm for Closest Pair

---

가장 가까운 두 점을 찾는 알고리즘. Euclidean distance를 사용한다.

Assumption : all points have distinct coordinate

이 강의에서는 Brute-Force Search를 O(n^2)에 해당하는 알고리즘을 의미한다.

1-D Version of Closest Pair :

1. Sort points (O(nlog(n)) time) 
2. Return closest pair of adjacent points (O(n) Time)

이거를 O(nlog(n))까지 줄이고 싶다.

x coordinate와 y coordinate를 받는다고 하자. 이 때, merge sort로는 해결이 안나는데, 이는 다음 그림과 같은 경우 때문이다. 즉, linear가 아니기 때문

![Untitled](Week%202%2019aabfd5e2d6475cb125132b26a28525/Untitled%2014.png)

빨간색끼리 가장 가까운데, merge sort로는 이를 반영하지 못한다. 파란 빨강, 초록 빨강 가깝다고 할 것.

이를 위해 

1. x coordinate와 y coordinate를 받는다고 하자.
2. Divide and Conquer를 이용해서 sorting과 finding을 하자.

## Divide and Conquer Paradigm

1. divide into smaller subprob
2. conquer problem recursively
3. combine solution of subprobs into general solution

## Closest Pair Finding Algorithm

![Untitled](Week%202%2019aabfd5e2d6475cb125132b26a28525/Untitled%2015.png)

여기서 $Q_x, Q_y, R_x, R_y$는 각각 분할된 부분문제를 또 $x, y$축으로 나눈 것을 의미한다.

4번의 경우, $Q, R$에 closest pair가 떨어져 있으면 찾을 수가 없는 경우가 발생하므로 추가한 것이다.

우리가 merge sort를 하므로 $O(n\log n)$이고, outside the reccursion에서는 $O(n)$이므로, 전체 시간 복잡도는 $O(n\log n)$이다.

### linear subroutine correction

이를 $O(n)$로 만들기 위한 idea는 다음과 같다.

lucky case는 위의 예시에서 closest pair가 P혹은 Q에 모두 몰려있는 것을 얘기한다.

unlucky case는 P와 Q에 closest pair가 떨어져 있는 것을 의미한다.

![Untitled](Week%202%2019aabfd5e2d6475cb125132b26a28525/Untitled%2016.png)

이를 활용해서 알고리즘을 새로 작성하면

![Untitled](Week%202%2019aabfd5e2d6475cb125132b26a28525/Untitled%2017.png)

$\delta$는 델타보다 작은 분할쌍이 존재하는 상황에서 가장 가까운 분할쌍을 계산하기 위해 필요하다.

### Pseudo Code

5번 상황에서, $\delta$이내에서만 closest pair를 찾는다.

![Untitled](Week%202%2019aabfd5e2d6475cb125132b26a28525/Untitled%2018.png)

outer loop를 일찍 마치면, 몇 개의 point를 놓친다. 따라서 i = 1 ~ $S_y - 1$이 되어야 한다.

inner loop에서는 j = 1 ~ min{7, $S_y - 1$}이어야 한다.

만약 $\delta$내에서 closest pair가 없으면 NULL을 방출한다. 즉 서로 거리가 infinite distance인 것이다.

위 그림을 종합해서 보면, 이 알고리즘을 통해 Closest Split Pair는 $O(n)$의 시간복잡도임을 알 수 있다.

![Untitled](Week%202%2019aabfd5e2d6475cb125132b26a28525/Untitled%2019.png)

(A) : $\delta$의 범위에 있다.

(B) : $\delta$의 범위 바로 옆에 있다.

### Proof

![Untitled](Week%202%2019aabfd5e2d6475cb125132b26a28525/Untitled%2020.png)

$\delta$가 update됨에 따라 점점 $x_1, x_2$가 가까운 것이 선정된다.

이 케이스에서 두 점은 SY로 끝날 뿐만 아니라 실제로 SY에 거의 인접한다.

즉, 두 점의 인덱스는 최대 7의 위치 차이만 있다.

이제 이 박스 안에 두 점이 있다는 것을 증명해야 한다.

직관적으로는 q점에서 다른 칸의 점과 비교하였을 때, 딱 7개의 indices 만큼만 차이가 나기에, 위의 box 안에 들어가는 것을 알 수 있다

.

![Untitled](Week%202%2019aabfd5e2d6475cb125132b26a28525/Untitled%2021.png)

이들의 x,y축 모두를 고려해서 그 거리가 $\delta$이므로, 다음과 같은 증명이 성립한다.

![Untitled](Week%202%2019aabfd5e2d6475cb125132b26a28525/Untitled%2022.png)

만약 하나의 구역?에 두 개 이상의 point가 있으면, 전체 범위를 search하지 못하므로, 다음이 증명되어야 한다.

![Untitled](Week%202%2019aabfd5e2d6475cb125132b26a28525/Untitled%2023.png)

따라서, q점이 있으면, p점이 찾아지는 것이 보장된다.

![Untitled](Week%202%2019aabfd5e2d6475cb125132b26a28525/Untitled%2024.png)

---

# Part 4

# Master Method

## Motivation

mathematical analysis를 도입한다. 첫날 했던 곱셈 알고리즘처럼.

![Untitled](Week%202%2019aabfd5e2d6475cb125132b26a28525/Untitled%2025.png)

Recursive하게 Algorithm을 작성한다. 그리고 이를 T(n)으로 쓴다.

T(n) = n digit의 수를 곱셈하기 위해 가해야하는 최대 연산회수

base time : 더 이상 recursion 불필요한 시점

n > 1 : $T(n) \leq 4T(n/2) + O(n)$ = work done by recursive calls + work done here

4개의 recursive call이고, digit은 절반이 되었으니까. 

그리고 그 시점에서 모인 조각들을 모으는 데에 드는 시간복잡도가 O(n)

수식 관계를 보면 Linear 하다.

---

다른 곱셈 알고리즘이 있다고 하자.

![Untitled](Week%202%2019aabfd5e2d6475cb125132b26a28525/Untitled%2026.png)

이 경우 3개의 분할이 생겨서 recursion이 3개가 생기니깐, $T(n) \leq 3T(n/2) + O(n)$이 성립할 것이다.

$T(n/2)$의 계수가 줄어들었으므로, 분명 직전 알고리즘 보다는 빠르다. 그러나 분명 merge sort와 같은 방법보다는 느리지만, 얼마나 느린지 확실하게 표현하기 어렵다.

---

## Formal Statement

Assumption : 모든 subproblem은 equal size이다. 

→ Multiplying Method

→ Merge sort

## Recurrence Format

1. Base case : $T(n) \leq a \space constant$ for all sufficeint small n
2. For all larger n → $T(n) \leq aT(n/b) + O(n^d)$ : $a, b, d$는 모두 $n$과는 무관한 상수이다.
    1. $a$는 subproblems/recursive call의 개수
    2. $b$는 $n$을 나누는 계수(factor).
    3. $d$는 outside of recure

## Master Method

Recurrence Algorithm의 upper bound

$T(n) = O(n^d\log n) \space for \space a = b^d$ : logarithm의 base가 중요하지 않다. 어차피 n에 맞게 지워져서

$T(n) = O(n^d) \space for \space a < b^d$ 

$T(n) = O(n^{\log_b a}) \space for \space a > b^d$ : 이 경우 logarithm의 base가 중요하다.

다 $\Theta(n)$이 된다.

![Untitled](Week%202%2019aabfd5e2d6475cb125132b26a28525/Untitled%2027.png)

적용예시를 보자.

![Untitled](Week%202%2019aabfd5e2d6475cb125132b26a28525/Untitled%2028.png)

binary search의 경우

![Untitled](Week%202%2019aabfd5e2d6475cb125132b26a28525/Untitled%2029.png)

![Untitled](Week%202%2019aabfd5e2d6475cb125132b26a28525/Untitled%2030.png)

Gauss Trick Multiplication

![Untitled](Week%202%2019aabfd5e2d6475cb125132b26a28525/Untitled%2031.png)

![Untitled](Week%202%2019aabfd5e2d6475cb125132b26a28525/Untitled%2032.png)

이 case는 가상의 recurrence를 따지는 것

![Untitled](Week%202%2019aabfd5e2d6475cb125132b26a28525/Untitled%2033.png)

## Proof 1

이제 이걸 증명한다.

![Untitled](Week%202%2019aabfd5e2d6475cb125132b26a28525/Untitled%2034.png)

가정은 다음과 같다.

![Untitled](Week%202%2019aabfd5e2d6475cb125132b26a28525/Untitled%2035.png)

이제 recursion tree를 이용해서 MergeSort를 분석하듯이 할 것이다. depth(level) J를 두고, 이를 기반으로 서술한다.

![Untitled](Week%202%2019aabfd5e2d6475cb125132b26a28525/Untitled%2036.png)

 전체적인 큰 그림은 다음과 같다. 가장 밑의 level이 base case가 되는 것.

![Untitled](Week%202%2019aabfd5e2d6475cb125132b26a28525/Untitled%2037.png)

이에 따라서 하나의 level에서의 work를 다음과 같이 계산할 수 있다.

![Untitled](Week%202%2019aabfd5e2d6475cb125132b26a28525/Untitled%2038.png)

모든 level에 대해서 summing을 하면

![Untitled](Week%202%2019aabfd5e2d6475cb125132b26a28525/Untitled%2039.png)

# Interpretation of the 3 Cases

 

![Untitled](Week%202%2019aabfd5e2d6475cb125132b26a28525/Untitled%2040.png)

a = subproblem이 늘어나는 속도

b^d = subproblem의 크기가 줄어드는 속도. outside of recursive call의 변수인 d도 영향을 줄 것이다.

d = 2 : n^2인 경우에 subproblem이 절반으로 나뉜다면, outside도 그 연산양이 n^2만큼 줄어드니까.

![Untitled](Week%202%2019aabfd5e2d6475cb125132b26a28525/Untitled%2041.png)

다음 문제를 한 번 보자

![Untitled](Week%202%2019aabfd5e2d6475cb125132b26a28525/Untitled%2042.png)

![Untitled](Week%202%2019aabfd5e2d6475cb125132b26a28525/Untitled%2043.png)

![Untitled](Week%202%2019aabfd5e2d6475cb125132b26a28525/Untitled%2044.png)

  

여기서 마지막 third case가 명확히 나오지 않았는데, 이는 다음 단원에서 설명한다.

![Untitled](Week%202%2019aabfd5e2d6475cb125132b26a28525/Untitled%2034.png)

# Proof 2

case 1의 경우 다음과 같이 증명

![Untitled](Week%202%2019aabfd5e2d6475cb125132b26a28525/Untitled%2045.png)

big O 에서는 상수곱은 무시되므로.

1번 케이스는 앞쪽 항이 지배적이고, 2번 케이스는 뒤쪽 항이 지배적이다.

RHS는 우측항을 얘기하는 것이다.

![Untitled](Week%202%2019aabfd5e2d6475cb125132b26a28525/Untitled%2046.png)

이에 따라서 방금의 case 2를 고려하면 초기항에 의해 지배적인 것을 설명할 수 있다.

![Untitled](Week%202%2019aabfd5e2d6475cb125132b26a28525/Untitled%2047.png)

Case 3의 경우 뒤쪽 항이 지배적이므로 다음과 같이 증명할 수 있다.

![Untitled](Week%202%2019aabfd5e2d6475cb125132b26a28525/Untitled%2048.png)

여기서 $a^{\log_b n}$은 leaves의 개수이다. 아래 그림을 참고하자.

![Untitled](Week%202%2019aabfd5e2d6475cb125132b26a28525/Untitled%2049.png)

Note를 이용해서 정리한다.

![Untitled](Week%202%2019aabfd5e2d6475cb125132b26a28525/Untitled%2050.png)

정리.

![Untitled](Week%202%2019aabfd5e2d6475cb125132b26a28525/Untitled%2051.png)

# Problems

![Untitled](Week%202%2019aabfd5e2d6475cb125132b26a28525/Untitled%2052.png)

![Untitled](Week%202%2019aabfd5e2d6475cb125132b26a28525/Untitled%2053.png)