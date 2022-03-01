# Hash Table

## Operation and Application

- 매우 중요한 자료구조

- random access를 array를 이용해서 지원하는 자료구조이다. 대부분의 연산이 Constant한 Big O로 지원된다. 

- 이제 random access를 지원하는 자료구조를 만들 것이다.
  
  - 또한 Key와 numerical position을 연결하는 mapping에 대해서 알아볼 것. 이 mapping을 hash function이라고 한다.
  
  - 그리고 이 key를 이용해서 position에 indexing 접근한다.

- 아래와 같은 연산을 지원한다. 모두 key를 통해서 접근 가능한 연산이다.
  
  - insert
  
  - delete
  
  - lookup : dictionary라고도 부른다.
  
  - **모든 연산이 Constant time을 지원한다.**
  
  - order를 정해주는 연산은 없다.

- 두가지 조건이 만족되어야 정상 작동한다.
  
  - 정상적으로 구현되었다.
  
  - non-pathological data이다.

![](https://i.imgur.com/OqWyGWc.png)

- De-Duplication에 사용할 수 있다. 중복된 것 없애기
  
  - 그냥 하나의 data 받을 때마다 비교해서 중복된  것이 아니면 받아들인다는 의미

![](https://i.imgur.com/kWmcomZ.png)

- 2-Sum Problem
  
  - 합쳐서 t가 되는 두 정수가 있는 지 찾는 것이다.

- 기본적인 방법으로는 
  
  - sort하고 합이 t가 되는 수를 binary search로 찾는다.

- 배운 방법으로는
  
  - hash table에 모든 수를 집어넣고 다음 숫자 t-A를 찾는 것이다.

- 탐색 자체를 N개의 array에 하므로, 전체 과정은 O(n)이다.

![](https://i.imgur.com/hErYEQG.png)

- 사용 예시
  
  - bottleneck인 compiler를 해결
  
  - router blocking(IP 차단)
  
  - Search Algorithm : Chess 등. 한 번 했던 체스말의 배열을 피한다.

![](https://i.imgur.com/HJT7fuD.png)

# Implementation Details 1

- S = Subset

- cardinality. 기수.
  
  - 이에 대해서는 [이 링크]([Weistern's :: 카디널리티(Cardinality) (tistory.com)](https://sciphy.tistory.com/387))참고할 것. 무한집합 사이의 '일종의 크기'를 비교하는 척도라고 할 수 있다.

- 먼저 hash table이 아닌 접근법을 보자.
1. Array 
   
   1. S가 U에 근접할수록 메모리 공간이 부족해진다. space에 대해서 $\theta(|U|)$라서...

2. Linked List
   
   1. $\theta(|S|)$의 space를 차지하지만, $\theta(|S|)$의 lookup 시간복잡도
- 이 둘의 장점을 합하자.
1. bucket = 각 entry of array
   
   - size of S = 1/2 * n

2. hash function = Keys from Universe -> position of array(buckets)

3. hash function의 결과물을 통해서 array A에 접근해서 data x를 저장한다.
- 만약 크기가 변해서 더 큰 array가 필요하다면 threshold를 정하고 array를 2배해야한다.

![](https://i.imgur.com/NdIYl67.png)

- 하지만 아래 문제처럼, 같은 bucket에 여러 개의 원소가 들어가도록 설정되면 어떻게 해야하는 것인가? (이를 Collision이라고 한다.)

- 문제에 관해서는 [이 링크]([[생일 패러독스] 생일 문제(Birthday Problem)와 조금만 진지한 고찰 : 네이버 블로그 (naver.com)](https://m.blog.naver.com/alwaysneoi/220261751961)) 참고

- 적은 양의 data로도 중복이 발생할 수 있다. 겹칠수도 있겠다 싶으려면, n bucket일 때 sqrt(n)만큼의 data만 있으면 0.5의 확률로 중복이 생긴다.

- k개의 날짜가 있으면, sqrt(k)의 사람이 있으면 0.5의 확률로 중복인 날짜가 생긴다는 것.

- 사람이 n명이면, 두 사람이 중복이 생기는 경우의 수가 n(n-1)이므로, n^2가 k에 근접하게 되면 0.5의 확률로 중복이 되는 것(???)

- 참고 링크
  
  - [자세한 것](https://destiny738.tistory.com/478)
  
  - [[016] Concept(선형자료구조_해시테이블) – Yerim Oh](https://yerimoh.github.io/Algo016/#%EC%83%9D%EC%9D%BC-%EB%AC%B8%EC%A0%9C-birthday-problem)
  
  - [생일 문제 - 나무위키 (namu.wiki)](https://namu.wiki/w/%EC%83%9D%EC%9D%BC%20%EB%AC%B8%EC%A0%9C)

![](https://i.imgur.com/w0LVUUX.png)

- 첫 번째 방법은 hashing1과 hashing2 결과를 계속해서 사용한다. 안되면 hashing1 += hashing2 를 써서 또 접근 시도한다. 이를 반복한다.

- 두번째 방법은, 그냥 바로 들어가지는 곳 찾아서 계속 접근 시도한다는 것

- chaining은 space가 많이 든다. 반면 open addressing은 공간은 적게 든다.

- open addressing은 deletion이 어렵다.

![](https://i.imgur.com/rvjfuf7.png)

# Implementation Details 2

- Hash Function을 구현하는 방법을 알아보자.
  
  - m : object의 개수
  
  - n : size of hash table    
1. Chaining
   
   - Insert는 $\theta(1)$이고, Delete와 Lookup은 $\theta(list length)$이다.
     
     - Insert할 때, A[h(x)] 앞에 집어 넣는다. 따로 정렬은 없이
     - 100개의 물건을 100개의 bucket에 넣었다고 하자. 운이 좋다면 딱 100개의 버킷에 들어맞을 것이다. 따라서 $\theta(list length) = \theta(1)$(for insert and delete)이다.
     - 만약 운이 나쁘다면 하나의 bucket에 100개가 다 들어갈 것이다.
     - 따라서 list length(bucket의 길이)는 m/n에서 m까지 될 수 있다.
   
   - running time이 hash function에 매우 의존적이다.

2. Open Addressing은 linked list를 쓸 필요가 없다.
   
   - running time은 length of probe sequence에 의해 결정된다.
   
   - 그럼 이제 중요한 건 lookup할 때 얼마나 hash table을 뒤적여야하는지, insert할 때에는 empty bucket을 찾는 데까지 필요한 시간이 중요하다. 
   
   - 즉, performance는 length of probe sequence에 의해 결정, probe sequence는 hash function에 의해 결정. 좋은 hash의 경우 evenly, 아닌 경우 probe sequence가 linearly grow한다.
- **즉, 양쪽 모두 어떤 hash function을 쓰는 지가 running time 결정에 중요하다.**

<br />

- 여기서 Probe Sequence란,
  
  - the list of locations which a method for [*open addressing*](https://xlinux.nist.gov/dads/HTML/openAddressing.html) produces as alternatives in case of a [*collision*](https://xlinux.nist.gov/dads/HTML/collision.html).
  
  - 즉, open addressing이 collision으로 실패시 그 다음으로 생성되는 위치 목록을 의미한다.

<br />

- Good hash function이란 무엇인가?
1. output이 고르게 나와야한다. 그래야 collision이 적게 생긴다.
   
   1. 고르게 분포시키는 건 그냥 운빨이다. 다 random function이란다.

2. 또한 hash function이 무엇인지 추측하거나 기억하지 않아도 된다. insert delete lookup 모두 어떤 연산이든 가하면, 그것은 key x에 hash function 가한 것과 같은 것이다.

3. hash에서 완전한 random은 불가능함을 알 수 있다. Alice를 39번지에서 찾았다고 하면 그것을 기록해야할 것이다. 즉, 이런 hash function의 random함을 모두 기억해야한다는 것. 그래서 결국 저번에 말한 list base solution을 사용해야한다. 따라서 $\theta(n)$이 된다.
- 다른연산이 모두 Constant time에 끝나므로,  hash function도 Constant time에 끝났으면 한다.

![](https://i.imgur.com/z3jh0WV.png)

- 이번에는 Hash Function을 설계한다. 이건 좀 난해한 부분이다.

- 나쁜 hash function을 설계하게 되는 원인을 알아보자.
1. 대표적인 수를 bucket으로 지정하는 것은 좋지 않다.
   
   - 지역번호 415를 bucket으로 한다고 했을 때, 정말 수많은 전화번호가 415하나에 담길 것이다. 그리고 정작 다른 버킷에는 담기지 않을 것이다. 이는 낭비다.
   
   - 뒷 3자리를 버킷으로 두는 것도 좋지 않다. 이 결과가 even하다는 증거는 없기에.

2. 메모리의 위치를 저장하는 예시를 보자. 즉, 2의 제곱으로 간격을 두게 될 것이다.
   
   - mod 연산을 쓰는 건 좋지 않다. 모든 odd 버킷이 비게 되기 때문이다. 나뉘는 수 나누는 수 모두 even number라서

![](https://i.imgur.com/TInVVvB.png)

- 이번에는 Good Hash Function을 보자.
  
  - 숫자가 아닌 거를 정수로 바꾸고, 또 그 정수를 bucket에 집어넣는다.
  
  - 첫 번째를 hash coding, 두번째를 compression function이라고 한다.
  
  - hash coding은 처음 입력값이 숫자라면 굳이 안해도 된다.

- 하나의 문장을 구성하는 각 알파벳을 모두 정수로 바꾸고, 앞선 running sum에 character의 고유수를 곱하고, 또 문자의 값을 더한 후, modulo연산을 한다.

- 여기서 mod 연산으로 compression을 한다면, bucket의 개수 N을 잘 선택해야한다. 안그럼 실패함..

- 예를 들면 전처럼, object와 N 모두 짝수면, 홀수인 bucket은 낙동강 오리알...

- 중요한 점은 어떤 N을 고르든, 완벽한 결과는 없다는 것.

- 하지만 최선은 있다. 이는 아래 필기에 있다.
  
  - 중요한 건 소수를 쓴다는 것. 주어진 데이터와 공유되는 인수가 있으면 앞선 문제처럼 홀수 자리는 빈다던가하는 문제가 생긴다.
  
  - 또한 주어진 데이터의 일종의 패턴과 거리가 먼 수가 좋다.
    
    - 전화번호라면 10의 승수, 메모리라면 2의 승수를 피해라.

![](https://i.imgur.com/oawt4Aq.png)

# Universal Hashing

- pathological data set에 대해서 살펴볼 것이다.

- 이 필기는 앞서 살펴본 해시테이블 기본 연산

---

- properly implemented의 의미
1. number of bucket이 보관할 수량과 어울려야한다 = N값을 잘 정해라

2. use descent hash function을 사용해라
- 여기서는 non-pathological data를 사용하라는 것은 결국 collision이 없는 data를 이용하라는 뜻이다. 물론 항상 이러는 건 불가능.

---

- 그리고 collision이 발생했을 때 어떻게 처리할 것인지도 배울 것이다.

![](https://i.imgur.com/wOFUzQF.png)

- 이것도 저번에 했던 것.

- chaining 방법과 open addressing 방법이 있다.
  
  - 여기서는 chaining에 대한 증명만 있다.

![](https://i.imgur.com/tLckoSS.png)

- Load는 hash table의 성능을 나타내는 중요한 지표이다.
  
  - 즉 하나의 bucket이 얼마나 꽉찼는지를 나타내는 지표이다.    

![](https://i.imgur.com/51L9aCp.png)

퀴즈.

- open addressing은 기본적으로 하나의 bucket에 하나의 object만 허용하므로,

- Load는 기본적으로 chaining에만 적용되는 개념이다.

![](https://i.imgur.com/byC4HNL.png)

- **load가 constant하면 lookup은 constant time이게 된다.**
  
  - load를 1보다는 크게하지 않는게 좋다.
  
  - n bucket에 nlogn object라면, load는 대략 logn일 것이다. 그럼 logarithm한 lookup time이 나오게 된다.

- 만약 open addressing 방법이라면 load는 1보다 한참 낮아야한다.

- 이때, bucket의 수를 조절해서 이 load를 control할 수 있다. alpha를 일정하게 하도록 설정하면, 자동으로 bucket의 수를 늘릴 수 있을 것이다.

- 때로는 deletion할 때, hash table을 shrink할 수도 있다.

![](https://i.imgur.com/jtToPio.png)

- number of object가 bucket의 수에 가까워야 성능이 잘나온다는 걸 알았다.

- 이걸 실현하려면 even하게 data를 나눠주는 hash function이 필요하다.
  
  - 그런데 그런 hash function은 존재하지 않는다. **모든 hash functiondms 하나의 pathological dataset이 존재한다.**

- 비둘기집 원리에 따라서, bucket의 개수가 넘어가면 무조건 겹치는 곳이 나온다.
  
  - 너무 많은 input data가 collision하면 성능이 크게 줄어든다.
  
  - 그 결과 lookup의 시간복잡도가 constant time에서 linear time으로 계산 시간이 늘어날수도 있다.

- Reason 부분을 보자.
  
  * 필기의 상황에 따르면 각 bucket마다 최소 |u| / n개의 원소가 존재해야한다.
  - U : universe, n : # of bucket, I : bucket, U >> n
  
  - 이 때, 각 데이터가 fair share되었다고 생각하고, 31번(그 외의 것도 괜찮다.)을 고르면 pathological dataset(중복이 많은 데이터)을 구할 수 있다. 이러면 성능이 저하된다.

- 다른 알고리즘과는 다르게 hash function은 특정한 data에 취약하다

![](https://i.imgur.com/tJingKH.png)

- Pathological data는 random하게 발생하는 것이 아니다.

- 아래 예시 같은 경우는, pathological dataset을 찾아서 입력해서 느리게 만드는 공격.

![](https://i.imgur.com/C2nAOV2.png)

- dataset을 못찾게 암호화를 한다.

- randomization을 이용한다.
  
  - hash function을 여러 개를 두고, 랜덤하게 골라서 사용한다.

![](https://i.imgur.com/FEmlhYB.png)

아래는 Option video 소개

![](https://i.imgur.com/cCunG81.png)

# Universal Hashing (Optional)

---

# Bloom Filter : Basic

- Hash Table의 일종이다. 효과가 좋다고 한다. light weight version이라고...

- error를 허용하는 space가 더 있다고 한다.

- 빠른 insert and Lookup

- 차지하는 공간 적다.

- 단점
  
  - object나 pointer를 보관하지 않는다. (공간 활용 극대화를 위해서)
  
  - deletion이 없다. only insert
  
  - small false positive probaiblity(실수가 있을 수 있다.)
    
    - insert 안했었는데 있다고 답변이 오는 경우를 이야기하는 것이다.
    
    - 이게 문제가 될 수 있다면 Bloom Filter를 사용하면 안된다.

![](https://i.imgur.com/0OSXAhF.png)

- 아래는 사용 예

![](https://i.imgur.com/1MJCba9.png)

- 이제는 실제 구현 방법을 알아보자.

- 구성요소
  
  - array of bits (0 or 1) : number of bits per object = $n/|S|$이다..
    - n = number of bits, S = objects
    - 일단은 $n/|S| = 8$이라고 가정하자.
  - hash function
    - k개

- 연산 순서를 보자.
  
  - insertion
    
    - 해시 결과 나온 k개의 비트를 1로 바꿔준다.
  
  - LookUp
    
    - 과거 insertion의 흔적을 찾는다. 해당 비트가 1이라면 이미 있다는 뜻!

- no false negative, yes false positive

![](https://i.imgur.com/MIDu7HU.png)

# Bloom Filter : Analysis

- bloom filter는 space와 correctness 사이에 trade off가 있는 자료구조이다.
  
  - 그럼 space를 많이 쓰면 correctness가 상승할 것이라고 기대할 수 있다.
  
  - 그래서 이 sweet spot을 찾는 것이 목적이다.

- 가정은 다음과 같다.
  
  - hash의 결과물이 uniform random하고 다른 output에 대하여 independent하다.
  
  - n bits, data S

![](https://i.imgur.com/pGw1xGE.png)

- data S를 모두 insert했을 때, 각 bit가 1일 확률은 얼마나 될까?
  
  - data S와 hash k : k|S|번 다트를 던진다고 생각하자
  
  - 1st 자리에 맞을 확률은 1/n이니깐, 안맞을 확률은 1-1/n이다.
  
  - 이제 이를 던진 횟수만큼 승수를 올리면 하나의 비트에서 1인 아닐 확률이 나온다.
  
  - 이를 이용하면 1일 확률을 구할 수 있다.

![](https://i.imgur.com/2jQsjP2.png)

- 이어서.

- 여기서 **cardinality**는 집합의 원소 개수에 대한 척도이다. 농도라고도 한다.

- 여기서 $1 + x <= e^x$를 이용해서 다음과 같이 식을 바꾼 것이다.
  
  - $1 - x <= e^{-x}$, $1/n = x$

- 여기서 **b = number of bits per object**

- 종합하면, 주어진 비트가 1이 되는 것은 점점 그 확률이 0이 된다.
  
  - bigger space  : 더 많은 비트 1

![](https://i.imgur.com/C94H44g.png)

- 필기를 따라가서 읽어라.

- 여기서 $[1-e^{-k/b}]^k$는 error rank $\epsilon$이라고도 부른다.

- b 상승 -> $\epsilon$ 하락

- **b를 고정해라. 그리고 이에 대해서 error rank를 최소로 하는 k를 구해라.** 

![](https://i.imgur.com/jZZh5rt.png)

# Reference

[Algorithm Design & Analysis 6 – Hash Table, Universal Hashing, Bloom filters – 1ambda](https://1ambda.blog/2018/06/30/algorithm-design-analysis-6-hash-table-universal-hashing-bloom-filters/)

[[자료구조] 해시테이블(HashTable)이란? - MangKyu's Diary (tistory.com)](https://mangkyu.tistory.com/102)
