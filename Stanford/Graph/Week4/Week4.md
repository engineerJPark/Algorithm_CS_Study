# Hash Table

## Operation and Application

매우 중요한 자료구조

random access를 array를 이용해서 지원하는 자료구조이다. 대부분의 연산이 Constant한 Big O로 지원된다. 

이제 random access를 지원하는 자료구조를 만들 것이다.

이제 Key와 numerical position을 연결하는 mapping에 대해서 알아볼 것. 이 mapping을 hash function이라고 한다.

그리고 이 key를 이용해서 position에 indexing 접근한다.

아래와 같은 연산을 지원한다. 모두 key를 통해서 접근 가능한 연산이다.

- insert

- delete

- lookup : dictionary라고도 부른다.

**모든 연산이 Constant time을 지원한다.**

order를 정해주는 연산은 없다.

두가지 조건이 만족되어야 정상 작동한다.

1. 정상적으로 구현되었다.

2. non-pathological data이다.

![](https://i.imgur.com/OqWyGWc.png)

De-Duplication에 사용할 수 있다. 중복된 것 없애기

그냥 하나의 data 받을 때마다 비교해서 중복된  것이 아니면 받아들인다는 의미

![](https://i.imgur.com/kWmcomZ.png)

2-Sum Problem

합쳐서 t가 되는 두 정수가 있는 지 찾는 것이다.

기본적인 방법으로는 

    sort하고 합이 t가 되는 수를 binary search로 찾는다.

배운 방법으로는

    hash table에 모든 수를 집어넣고 다음 숫자 t-A를 찾는 것이다.

탐색 자체를 N개의 array에 하므로, 전체 과정은 O(n)이다.

![](https://i.imgur.com/hErYEQG.png)

bottleneck인 compiler를 해결

router blocking(IP 차단)

Search Algorithm : Chess 등. 한 번 했던 체스말의 배열을 피한다.

![](https://i.imgur.com/HJT7fuD.png)

# Implementation Details 1

S = Subset

cardinality. 기수.

이에 대해서는 [이 링크]([Weistern's :: 카디널리티(Cardinality) (tistory.com)](https://sciphy.tistory.com/387))참고할 것. 무한집합 사이의 '일종의 크기'를 비교하는 척도라고 할 수 있다.

먼저 hash table이 아닌 접근법을 보자.

1. Array 
   
   1. S가 U에 근접할수록 메모리 공간이 부족해진다. space에 대해서 $\theta(|U|)$라서...

2. Linked List
   
   1. $\theta(|S|)$의 space를 차지하지만, $\theta(|S|)$의 lookup 시간복잡도

이 둘의 장점을 합하자.

1. bucket = 각 entry of array
   
   1. size of S = 1/2 * n

2. hash function = Keys from Universe -> position of array(buckets)

3. hash function의 결과물을 통해서 array A에 접근해서 data x를 저장한다.

만약 크기가 변해서 더 큰 array가 필요하다면 threshold를 정하고 array를 2배해야한다.

![](https://i.imgur.com/NdIYl67.png)

하지만 아래 문제처럼, 같은 bucket에 여러 개의 원소가 들어가도록 설정되면 어떻게 해야하는 것인가? (이를 Collision이라고 한다.)

문제에 관해서는 [이 링크]([[생일 패러독스] 생일 문제(Birthday Problem)와 조금만 진지한 고찰 : 네이버 블로그 (naver.com)](https://m.blog.naver.com/alwaysneoi/220261751961)) 참고

적은 양의 data로도 중복이 발생할 수 있다. 겹칠수도 있겠다 싶으려면, n bucket일 때 sqrt(n)만큼의 data만 있으면 0.5의 확률로 중복이 생긴다.

k개의 날짜가 있으면, sqrt(k)의 사람이 있으면 0.5의 확률로 중복인 날짜가 생긴다는 것.

사람이 n명이면, 두 사람이 중복이 생기는 경우의 수가 n(n-1)이므로, n^2가 k에 근접하게 되면 0.5의 확률로 중복이 되는 것(???)

[자세한 것](https://destiny738.tistory.com/478)

[[016] Concept(선형자료구조_해시테이블) – Yerim Oh](https://yerimoh.github.io/Algo016/#%EC%83%9D%EC%9D%BC-%EB%AC%B8%EC%A0%9C-birthday-problem)

[생일 문제 - 나무위키 (namu.wiki)](https://namu.wiki/w/%EC%83%9D%EC%9D%BC%20%EB%AC%B8%EC%A0%9C)

![](https://i.imgur.com/w0LVUUX.png)

첫 번째 방법은 hashing1과 hashing2 결과를 계속해서 사용한다. 안되면 hashing1 += hashing2 를 써서 또 접근 시도한다. 이를 반복한다.

두번째 방법은, 그냥 바로 들어가지는 곳 찾아서 계속 접근 시도한다는 것

chaining은 space가 많이 든다. 반면 open addressing은 공간은 적게 든다.

open addressing은 deletion이 어렵다.

![](https://i.imgur.com/rvjfuf7.png)

# Implementation Details 2

Hash Function을 구현하는 방법을 알아보자.

m : object의 개수

n : size of hash table    

1. Chaining
   
   - Insert는 $\theta(1)$이고, Delete와 Lookup은 $\theta(list length)$이다.
     
     - Insert할 때, A[h(x)] 앞에 집어 넣는다. 따로 정렬은 없이
     - 100개의 물건을 100개의 bucket에 넣었다고 하자. 운이 좋다면 딱 100개의 버킷에 들어맞을 것이다. 따라서 $\theta(list length) = \theta(1)$(for insert and delete)이다.
     - 만약 운이 나쁘다면 하나의 bucket에 100개가 다 들어갈 것이다.
     - 따라서 list length(bucket의 길이)는 m/n에서 m까지 될 수 있다.
   
   - running time이 hash function에 매우 의존적이다.

2. Open Addressing은 linked list를 쓸 필요가 없다.
   
   -  running time은 length of probe sequence에 의해 결정된다.
   
   - 그럼 이제 중요한 건 lookup할 때 얼마나 hash table을 뒤적여야하는지, insert할 때에는 empty bucket을 찾는 데까지 필요한 시간이 중요하다. 
   
   - 즉, performance는 length of probe sequence에 의해 결정, probe sequence는 hash function에 의해 결정. 좋은 hash의 경우 evenly, 아닌 경우 probe sequence가 linearly grow한다.

**즉, 양쪽 모두 어떤 hash function을 쓰는 지가 running time 결정에 중요하다.**



여기서 probe sequence란

the list of locations which a method for [*open addressing*](https://xlinux.nist.gov/dads/HTML/openAddressing.html) produces as alternatives in case of a [*collision*](https://xlinux.nist.gov/dads/HTML/collision.html).

즉, open addressing이 collision으로 실패시 그 다음으로 생성되는 위치 목록을 의미한다.



Good hash function이란 무엇인가?

1. output이 고르게 나와야한다. 그래야 collision이 적게 생긴다.
   
   1. 고르게 분포시키는 건 그냥 운빨이다. 다 random function이란다.

2. 또한 hash function이 무엇인지 추측하거나 기억하지 않아도 된다. insert delete lookup 모두 어떤 연산이든 가하면, 그것은 key x에 hash function 가한 것과 같은 것이다.

3. hash에서 완전한 random은 불가능함을 알 수 있다. Alice를 39번지에서 찾았다고 하면 그것을 기록해야할 것이다. 즉, 이런 hash function의 random함을 모두 기억해야한다는 것. 그래서 결국 저번에 말한 list base solution을 사용해야한다. 따라서 $\theta(n)$이 된다.

다른연산이 모두 Constant time에 끝나므로,  hash function도 Constant time에 끝났으면 한다.

![](https://i.imgur.com/z3jh0WV.png)

이번에는 Hash Function을 설계한다. 이건 좀 난해한 부분이다.

나쁜 hash function을 설계하게 되는 원인을 알아보자.



1. 대표적인 수를 bucket으로 지정하는 것은 좋지 않다.
   
   - 지역번호 415를 bucket으로 한다고 했을 때, 정말 수많은 전화번호가 415하나에 담길 것이다. 그리고 정작 다른 버킷에는 담기지 않을 것이다. 이는 낭비다.
   
   - 뒷 3자리를 버킷으로 두는 것도 좋지 않다. 이 결과가 even하다는 증거는 없기에.

2. 메모리의 위치를 저장하는 예시를 보자. 즉, 2의 제곱으로 간격을 두게 될 것이다.
   
   - mod 연산을 쓰는 건 좋지 않다. 모든 odd 버킷이 비게 되기 때문이다. 나뉘는 수 나누는 수 모두 even number라서

![](https://i.imgur.com/TInVVvB.png)

이번에는 Good Hash Function을 보자.



숫자가 아닌 거를 정수로 바꾸고, 또 그 정수를 bucket에 집어넣는다.

첫 번째를 hash coding, 두번째를 compression function이라고 한다.

hash coding은 처음 입력값이 숫자라면 굳이 안해도 된다.



하나의 문장을 구성하는 각 알파벳을 모두 정수로 바꾸고, 앞선 running sum에 character의 고유수를 곱하고, 또 문자의 값을 더한 후, modulo연산을 한다.



여기서 mod 연산으로 compression을 한다면, bucket의 개수 N을 잘 선택해야한다. 안그럼 실패함..

예를 들면 전처럼, object와 N 모두 짝수면, 홀수인 bucket은 낙동강 오리알...



중요한 점은 어떤 N을 고르든, 완벽한 결과는 없다는 것.

하지만 최선은 있다. 이는 아래 필기에 있다.

중요한 건 소수를 쓴다는 것. 주어진 데이터와 공유되는 인수가 있으면 앞선 문제처럼 홀수 자리는 빈다던가하는 문제가 생긴다.

또한 주어진 데이터의 일종의 패턴과 거리가 먼 수가 좋다.

- 전화번호라면 10의 승수, 메모리라면 2의 승수를 피해라.

![](https://i.imgur.com/oawt4Aq.png)

# Universal Hashing



![](https://i.imgur.com/wOFUzQF.png)





![](https://i.imgur.com/tLckoSS.png)





![](https://i.imgur.com/51L9aCp.png)





![](https://i.imgur.com/byC4HNL.png)





![](https://i.imgur.com/jtToPio.png)





![](https://i.imgur.com/tJingKH.png)





![](https://i.imgur.com/C2nAOV2.png)





![](https://i.imgur.com/FEmlhYB.png)





![](https://i.imgur.com/cCunG81.png)

# Universal Hashing (Optional)

---

# Bloom Filter

![](https://i.imgur.com/0OSXAhF.png)





![](https://i.imgur.com/1MJCba9.png)





![](https://i.imgur.com/MIDu7HU.png)





![](https://i.imgur.com/pGw1xGE.png)



![](https://i.imgur.com/2jQsjP2.png)





![](https://i.imgur.com/C94H44g.png)





![](https://i.imgur.com/jZZh5rt.png)



-10000에서 10000까지의 t 에대해서 x+y=t인 조합을 모두 찾아라

lecture보다 한 줄의 코드가 더 필요하다고 한다.
