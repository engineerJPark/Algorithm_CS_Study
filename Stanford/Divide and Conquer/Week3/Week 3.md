# Week 3

# Quick Sort

---

보통 $O(n\log n)$의 시간복잡도. 메모리를 추가로 요구하지 않는다.

pivot을 구하고 그걸로 pivot보다 작은것/큰것으로 나눈다.

pivot은 첫번째 원소로 둔다. (일단은)

이렇게 해서 나눈 partition은 아직 정렬된 것이 아니다.

**pivot은 partitioning 과정을 통해 원래 있어야하는 정확한 위치에 있게 된다. 이를 이용하는 정렬법.**

![Untitled](Week%203%20216d6b6b13874989b8c4f75526b0fa60/Untitled.png)

Quick Sort 특징

1. $O(n)$으로 구현이 가능하다. 그리고 no extra memory. 그 메모리 내에서 해결할 수 있다.
2. reduce problem size ← partition

# Quick Sort : High Level Description

---

```python
QuickSort(array A, lenght n)
if n = 1
	return
p = ChoosePivot(A, n) // first element
partition around p -> smaller to left, bigger to right
recursively sort the 1st part
recursively sor the 2nd part
```

놀랍게도 merge 과정이 없다.

# Partitioning Around a Pivot

---

### 추가 메모리를 사용하는 경우

---

O(n)의 메모리를 추가로 사용한다면, partition을 O(n)으로 행하는 것이 더 쉬워진다.

3을 기준으로 quicksort한다고 하면, 그 다음 원소를 scan하면서 부터는 3보다 크면 남은 자리 중 가장 오른쪽에, 작은 경우 남은 자리 중 가장 왼쪽에 박아놓는다.

![Untitled](Week%203%20216d6b6b13874989b8c4f75526b0fa60/Untitled%201.png)

### 주어진 메모리 그대로 사용하는 경우

---

 여전히 pivot은 첫 번째로 가정한다.

pivot / 본 것 / 안 본것으로 분류한다.

single scan만을 이용하며, 이미 본 것들은 여전히 partitioned 되어있다.

![Untitled](Week%203%20216d6b6b13874989b8c4f75526b0fa60/Untitled%202.png)

### 순서

---

i = pivot보다 작은 것/큰 것을 구분하는 index

j = pivot보다 큰 것/아직 scan하지 않은 것을 구분하는 index

...

linear한 algorithm이 되도록, j가 전진하면서 하나씩 확인한다.

그리고 pivot보다 큰 거는 그냥 j만 전진한 것으로 끝내고, pivot보다 작은 것이 등장하면 i 바로 뒤와 위치를 바꾼다.

마지막으로, pivot은 i를 이용해서 넣는다.

![Untitled](Week%203%20216d6b6b13874989b8c4f75526b0fa60/Untitled%203.png)

![Untitled](Week%203%20216d6b6b13874989b8c4f75526b0fa60/Untitled%204.png)

### Pseudocode

---

l, r은 subarray의 왼/오른쪽 boundary이다.

i = pivot보다 작은 것/큰 것을 구분하는 index

j = pivot보다 큰 것/아직 scan하지 않은 것을 구분하는 index

```python
parition(A,l,r) # input corresponds to A[l ... r]
	p := A[l] # pivot = leftmost element
	i := l + 1
	for j = l + 1 to r
		if A[j] < p # if A[j] > p -> do nothing
			swap A[j] and A[i]
			i := i + 1
	swap A[l] and A[i - 1] # pivot을 원래 위치로 이동
```

![Untitled](Week%203%20216d6b6b13874989b8c4f75526b0fa60/Untitled%205.png)

물론 아직 pivot보다 큰 element를 만나지 못한 경우, redundant swap이 있을 수 있다.

## Running Time

---

n = array의 element 개수

running time = O(n), n = r - l + 1

→ 하나의 array entry마다 그저 comparision밖에 안한다 = O(1)이다.

→ 한 공간의 memory에서 잘 동작한다.

## Correctness

---

![Untitled](Week%203%20216d6b6b13874989b8c4f75526b0fa60/Untitled%206.png)

## Correctness for Addition

---

수학적 귀납법을 이용해서 알고리즘의 정당성을 보여주겠다는 말이다.

![Untitled](Week%203%20216d6b6b13874989b8c4f75526b0fa60/Untitled%207.png)

여기서 hypothesis는 P(k) holds for all k<n 이다.

![Untitled](Week%203%20216d6b6b13874989b8c4f75526b0fa60/Untitled%208.png)

![Untitled](Week%203%20216d6b6b13874989b8c4f75526b0fa60/Untitled%209.png)

n이 주어진 array의 길이이고, k1,k2은 pivot을 기준으로한 그 일부이다. 둘다 모두 n보다 작다. 

따라서 inductive hypothesis를 만족한다.

# Choose good pivot

---

![Untitled](Week%203%20216d6b6b13874989b8c4f75526b0fa60/Untitled%2010.png)

Running Time이 Pivot에 따라서 결정되는 문제가 있다.

가장 좋은 경우는 equal하게 subprob이 생기는 경우.

제일 나쁜 경우는 완전히 한 쪽으로 몰리는 경우.

...

아래는 나쁜 경우이다.

매 순간 recursion이 일어나므로 계속 그 bigO를 더해준다.

![Untitled](Week%203%20216d6b6b13874989b8c4f75526b0fa60/Untitled%2011.png)

아래는 좋은 경우다.

![Untitled](Week%203%20216d6b6b13874989b8c4f75526b0fa60/Untitled%2012.png)

random pivot을 사용하면 여전히 O(nlog(n))이 된다.

![Untitled](Week%203%20216d6b6b13874989b8c4f75526b0fa60/Untitled%2013.png)

pivot choice와 같은 것을 random하게 선정하는 경우, general하게 average big O는 항상 O(nlog(n))이다.

![Untitled](Week%203%20216d6b6b13874989b8c4f75526b0fa60/Untitled%2014.png)

# Quick Sort Analysis - Decomposition Principle

---

이거 보고 오자.

![Untitled](Week%203%20216d6b6b13874989b8c4f75526b0fa60/Untitled%2015.png)

QuickSort는 모든 input에 대해 general한 average 결과를 가져다준다.

![Untitled](Week%203%20216d6b6b13874989b8c4f75526b0fa60/Untitled%2016.png)

QuickSort의 running time이 O(nlog(n))임을 수학적으로 보이는 것이 목적이다.

![Untitled](Week%203%20216d6b6b13874989b8c4f75526b0fa60/Untitled%2017.png)

$z_i$와 $X_{ij}$의 수학적인 정의

pivot $\sigma$가 주어질 때, $z_i$와 $z_j$가 비교되는 횟수

![Untitled](Week%203%20216d6b6b13874989b8c4f75526b0fa60/Untitled%2018.png)

두 fixed element 사이에 몇 번이나 comparison이 발생하는가?

오직 pivot과만 비교하므로, 최대 한 번까지만 비교가 발생한다. pivot이 recursive call에서는 없으니까.

즉, $X_{ij} = 0 \space or \space 1$이고, 이렇게 0,1

![Untitled](Week%203%20216d6b6b13874989b8c4f75526b0fa60/Untitled%2019.png)

C를 그냥 수식으로 쓰기는 어렵지만 X를 이용하면 간단하다.

![Untitled](Week%203%20216d6b6b13874989b8c4f75526b0fa60/Untitled%2020.png)

Decomposition Principle에 대한 general한 설명

![Untitled](Week%203%20216d6b6b13874989b8c4f75526b0fa60/Untitled%2021.png)

# Quick Sort Analysis - The Key Insight

---

![Untitled](Week%203%20216d6b6b13874989b8c4f75526b0fa60/Untitled%2022.png)

pivot이 j-i+1 set에서 뽑히지 않으면 전부 동일한 recursive call로 passed 된다. 

array length = 0, 1일 때 sorting 끝

![Untitled](Week%203%20216d6b6b13874989b8c4f75526b0fa60/Untitled%2023.png)

여기서 1번의 경우를 bad case → 끝부분이니까

2번의 경우를 good case라고 한다.

정리하면...

![Untitled](Week%203%20216d6b6b13874989b8c4f75526b0fa60/Untitled%2024.png)

# Quick Sort Analysis - Final Calculation

---

Note 부터 보라. 수학적으로 옮다.

![Untitled](Week%203%20216d6b6b13874989b8c4f75526b0fa60/Untitled%2025.png)

직사각형보다 blue curve밑의 영역이 더 큰 걸 이용해서 log(n)을 구한다.

![Untitled](Week%203%20216d6b6b13874989b8c4f75526b0fa60/Untitled%2026.png)

연산량이 2nlog(n)이므로, big O는 nlog(n)이다.

# Probability Review

---

![Untitled](Week%203%20216d6b6b13874989b8c4f75526b0fa60/Untitled%2027.png)

sample space = 모든 가능한 경우

![Untitled](Week%203%20216d6b6b13874989b8c4f75526b0fa60/Untitled%2028.png)

EX1

![Untitled](Week%203%20216d6b6b13874989b8c4f75526b0fa60/Untitled%2029.png)

EX2

![Untitled](Week%203%20216d6b6b13874989b8c4f75526b0fa60/Untitled%2030.png)

event = sample space의 subset

![Untitled](Week%203%20216d6b6b13874989b8c4f75526b0fa60/Untitled%2031.png)

random variable은 sample space $\Omega \to R$인 function

realization이라고 한다.

![Untitled](Week%203%20216d6b6b13874989b8c4f75526b0fa60/Untitled%2032.png)

그냥 average이다.EX1 : Use Linearity of Expectation

![Untitled](Week%203%20216d6b6b13874989b8c4f75526b0fa60/Untitled%2033.png)

EX2 : 이 이유 때문에 결국엔 O(nlog(n))이 성립하게 되는 것이다.

![Untitled](Week%203%20216d6b6b13874989b8c4f75526b0fa60/Untitled%2034.png)

그냥 average이다.

![Untitled](Week%203%20216d6b6b13874989b8c4f75526b0fa60/Untitled%2035.png)

이건 Theorem이 아니라, 일종의 definition이다. 이는 매우 중요하다.. Lin Exp라고도 불린다.

![Untitled](Week%203%20216d6b6b13874989b8c4f75526b0fa60/Untitled%2036.png)

first sum = column sum

second sum = row sum

![Untitled](Week%203%20216d6b6b13874989b8c4f75526b0fa60/Untitled%2037.png)

마지막 EX

![Untitled](Week%203%20216d6b6b13874989b8c4f75526b0fa60/Untitled%2038.png)

아래는 풀이 과정

![Untitled](Week%203%20216d6b6b13874989b8c4f75526b0fa60/Untitled%2039.png)

![Untitled](Week%203%20216d6b6b13874989b8c4f75526b0fa60/Untitled%2040.png)

이어서... 저번 시간에 한 것

![Untitled](Week%203%20216d6b6b13874989b8c4f75526b0fa60/Untitled%2041.png)

![Untitled](Week%203%20216d6b6b13874989b8c4f75526b0fa60/Untitled%2042.png)

조건부 확률

주어진 사건2에 대해서 사건1이 발생할 확률. 즉 사건2가 이미 일어난 걸 전재로 할 때의 확률을 의미한다.

![Untitled](Week%203%20216d6b6b13874989b8c4f75526b0fa60/Untitled%2043.png)

예시

![Untitled](Week%203%20216d6b6b13874989b8c4f75526b0fa60/Untitled%2044.png)

다음 식 자체가 independence의 정의이다.

물리적 의미가 X, Y가 서로 영향이 없는 사건이라는 것. 다만, 물리적 의미가 다소 불분명하니깐 주의할 것

그러므로 물리적 의미는 확실한 거 아니면 사용하지 않고, 수식 정의만 사용하자.

![Untitled](Week%203%20216d6b6b13874989b8c4f75526b0fa60/Untitled%2045.png)

여기서는 random variable의 independence를 가린다.

**두 random variable이 가지는 event가 서로 independent하다는 뜻이다.**

즉, 하나의 random variable을 통해서 다른 random variable의 값을 알아낼 수 없다는 뜻.

random variable이 independent해야 random variable의 곱의 평균이 평균의 곱이 된다.

![Untitled](Week%203%20216d6b6b13874989b8c4f75526b0fa60/Untitled%2046.png)

Random variable의 independence에 대해서 hypothesis가 필요하다는 사실을 잊지 말자.

...

EX

![Untitled](Week%203%20216d6b6b13874989b8c4f75526b0fa60/Untitled%2047.png)

# Problem Set

---

한쪽에 대한 값이 $1/2(1-2\alpha)$. 양쪽 다하면 2배가된다.

![Untitled](Week%203%20216d6b6b13874989b8c4f75526b0fa60/Untitled%2048.png)

![Untitled](Week%203%20216d6b6b13874989b8c4f75526b0fa60/Untitled%2049.png)