# Week 1

# Karatsuba Multiplication

![Untitled](Week%201%20c539cd6c517547e0be47dc6455e0a6a1/Untitled.png)

ac,bd를 순환되게 계산해서 점점 작은 단위로 계산해간다.
한자리 곱셈과 같은 simple base case는 생략하고 간단한 곱연산으로 처리한다.

![Untitled](Week%201%20c539cd6c517547e0be47dc6455e0a6a1/Untitled%201.png)

![Untitled](Week%201%20c539cd6c517547e0be47dc6455e0a6a1/Untitled%202.png)

# Merge Sort

Merge Sort : 여러 개의 작은 단위로 나눈 후, Recursive하게 순서를 맞춘다.

Pseudo Code

Ignore base cases

Recursively sort 1st half of array

Recursively sort 2nd half of array

Merge two sorted subarray into one

![Untitled](Week%201%20c539cd6c517547e0be47dc6455e0a6a1/Untitled%203.png)

A, B 내부에서의 순서이므로 어디가 더 작을 지 모른다.

따라서 다음과 같이 하나씩 비교하면서 작은 것을 merge한다.

![Untitled](Week%201%20c539cd6c517547e0be47dc6455e0a6a1/Untitled%204.png)

얼마나 오래걸리냐 = 디버거에서 한줄씩 실행한다고 할때, 몇 번이나 실행 버튼을 눌렀냐를 세면 된다.

하나의 segment의 순환마다 6m의 시간복잡도를 갖는다.

참고로 원래 4m+2인데, m을 가장 작은 1로 치는 경우로 해서 6m으로 치고 상수를 없앴다.

![Untitled](Week%201%20c539cd6c517547e0be47dc6455e0a6a1/Untitled%205.png)

![Untitled](Week%201%20c539cd6c517547e0be47dc6455e0a6a1/Untitled%206.png)

Merge Sort의 총 required time

![Untitled](Week%201%20c539cd6c517547e0be47dc6455e0a6a1/Untitled%207.png)

나누는 회수가 다음과 같다. $\log_2 n$

![Untitled](Week%201%20c539cd6c517547e0be47dc6455e0a6a1/Untitled%208.png)

실제로는 맨 위가 level=0이고, 맨 아래가 level=log_2⁡𝑛 이므로 $\log_2 n + 1$

각 level에서의 subproblem과 그 subprob의 element의 개수들은 각각 $2^j, n/2^j$이다.

따라서 각 level에서의 subproblem과 남은 array size를 곱하면, 그 level에서의 총 계산양이 나올 것이다.

그 결과가 바로 6n

그리고 이를 나눈 횟수 = level의 개수를 곱하면 전체 계산양이 나온다.

![Untitled](Week%201%20c539cd6c517547e0be47dc6455e0a6a1/Untitled%209.png)

# Worst-case Analysis

가정이 필요없고, 제일 연산이 많이, 오래걸리는 upper bound를 찾는 분석방법이다.

Average-case, benchmarks 방법은 해당 domain에 관한 지식이 있어야 주요 input을 정할 수 있다.

Constant facto와 lower-order term은 모두 무시한다.

이유?

계산 용이.

Machine architecture/compiler/programmer의 영향 없이 high level에서만 계산하기 위해서

실제로 이렇게 해도 알고리즘끼리의 비교에 문제가 없다.

Input size n은 충분히 큰 수로 취급한다. 거의 무한 정도로

Big Inputs are interest!

이 과정을 통해 얻게되는 알고리즘의 계산 양에대한 주요 식을 ‘sweet spot’이라고한다.

Fast algorithm = Worst-case running Time grows slowly With input size

![Untitled](Week%201%20c539cd6c517547e0be47dc6455e0a6a1/Untitled%2010.png)

# Asymptotic Analysis

Big-O 표기를 배운다.

High level에서의 계산양
architecture/language/compiler-dependent details로 인한 계산양을 무시한다.
다른 알고리즘과 비교가 용이해진다.

Suppress constant factors(machine dependent) and lower-order terms(irrelevant for large input)

$6\log_n + 6n \to \log_n + n$, Running time is O(n log n)

## One loop의 경우

상수 계수 혹은 상수항이 붙을 수 있지만, big O notation에서는 이를 모두 제거한다.

Two Loop의 경우에도 마찬가지의 big O notation을 보인다.

![Untitled](Week%201%20c539cd6c517547e0be47dc6455e0a6a1/Untitled%2011.png)

![Untitled](Week%201%20c539cd6c517547e0be47dc6455e0a6a1/Untitled%2012.png)

이 경우 입력치의 제곱으로 연산량이 늘어나므로,O(n^2)이 된다.

결과적으로, iteration의 nested 된 개수마다 n에 승수가 올라간다.

![Untitled](Week%201%20c539cd6c517547e0be47dc6455e0a6a1/Untitled%2013.png)

![Untitled](Week%201%20c539cd6c517547e0be47dc6455e0a6a1/Untitled%2014.png)

Big-O의 수학적 정의

어떤 함수 f(n)의 Big-O notation이 O(g(n))라는 것은,
n의 값이 일정 수준이 넘어가면(충분히 많은 아이템을 사용한다면)
그 이상의 어떤 n을 대입하여도 c*g(n)보다 결과값이 작은 상수 c가 존재한다는 뜻이다.

예를 들어, 어떤 함수 f(n)의 Big-O notation이 O(n)이라면, 특정 값보다 커지면 무한대까지 계속 f(n)이 c*n(c는 임의의 상수)보다 작다는 것이다.

[[자료구조] 빅오 표기법(Big-O notation)이란? (tistory.com)](https://holika.tistory.com/entry/%EC%9E%90%EB%A3%8C%EA%B5%AC%EC%A1%B0-%EB%B9%85%EC%98%A4-%ED%91%9C%EA%B8%B0%EB%B2%95Big-O-notation%EC%9D%B4%EB%9E%80#:~:text=%EB%A7%A8%20%EC%B2%98%EC%9D%8C%EC%97%90%20%EB%A7%90%ED%96%88%EB%93%AF%20Big,%EB%9D%BC%EA%B3%A0%20%EC%83%9D%EA%B0%81%ED%95%B4%20%EB%B3%BC%20%EC%88%98%20%EC%9E%88%EB%8B%A4.)

![Untitled](Week%201%20c539cd6c517547e0be47dc6455e0a6a1/Untitled%2015.png)

C는 상수곱을 의미, 𝑛_0는 n이 충분히 큰 수임을 의미한다.

![Untitled](Week%201%20c539cd6c517547e0be47dc6455e0a6a1/Untitled%2016.png)

## Big O 표기에 대한 몇가지 정리

상수 계수 삭제/고차원을 제외한 다른 항의 제거 가능 증명

![Untitled](Week%201%20c539cd6c517547e0be47dc6455e0a6a1/Untitled%2017.png)

두번째 증명으로 인해 다항식의 다른 거듭제곱은 붕괴되지 않고, 서로 구분된다.

![Untitled](Week%201%20c539cd6c517547e0be47dc6455e0a6a1/Untitled%2018.png)

# Big O와 비슷한 의미의 다른 정의들

![Untitled](Week%201%20c539cd6c517547e0be47dc6455e0a6a1/Untitled%2019.png)

![Untitled](Week%201%20c539cd6c517547e0be47dc6455e0a6a1/Untitled%2020.png)

# Problems

f(n) = 1/2n^2
인 경우, g(n) = n^2 이 되는 경우를 생각해보자
Never와 Always는 당연히 아니고, 숫자가 커지면 충분히 들어맞으므로 마지막 선지가 맞고, general한 경우는 성립하지 않으므로 첫 번째 선지도 맞다.

![Untitled](Week%201%20c539cd6c517547e0be47dc6455e0a6a1/Untitled%2021.png)

K * k * n

K 개의 array->k번 반복
Merge 과정의 연속으로 Array가 커져서 (k-1)n과 n의 merge와 같은 case가 생길 수 있으므로, kn

![Untitled](Week%201%20c539cd6c517547e0be47dc6455e0a6a1/Untitled%2022.png)

![Untitled](Week%201%20c539cd6c517547e0be47dc6455e0a6a1/Untitled%2023.png)

그냥 wolfram alpha로 그래프 그려서 비교하는 게 더 낮다.

근데 오히려 답변이 틀린 것 같다. 왜지?

![Untitled](Week%201%20c539cd6c517547e0be47dc6455e0a6a1/Untitled%2024.png)

![Untitled](Week%201%20c539cd6c517547e0be47dc6455e0a6a1/Untitled%2025.png)