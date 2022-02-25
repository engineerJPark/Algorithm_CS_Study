'''
강의에서의 pseudo code와는 조금 다르지만, 같은 원리로 동작한다.

가장 큰 5 개의 SCC를 출력하라.

거꾸로 -> finishing time으로 node 명명 -> 다시 DFS해서 leader 구하긴

DFS_LOOP(G)
    global t = 0 # finishing time
    global s = NULL # leaders

    for i = n to 1:
        if i not explored:
            s = i
            DFS(G, i)

DFS(G, i)
    mark i explored
    leader(i) = s
    for each arc(i, j) in G:
        if j not explored
            DFS(G, j)
    t += 1
    set f(i) = t # finishing time record
'''

# graph와 이를 역전시킨 graph_r (reversed) 생성
f = open('SCC.txt', 'r')
N = 875714
graph = []
graph_r = []
for i in range(N):
    graph += [[]]
    graph_r += [[]]
ls = f.readline()
while ls:
    data = list(map(int, ls.split(' ')[:-1]))
    ls = f.readline()
    if data[0] == data[1]: # loop case. don't record this
        continue
    graph[data[0] - 1] += [data[1]] # vertex1 to vertex2
    graph_r[data[1] - 1] += [data[0]] # vertex2 to vertex1
f.close()

def create(g):
    return [i.copy() for i in g]

g1 = create(graph)
g2 = create(graph_r)

# ex : 가본 곳 기록
# f : finishing time 기록 
# s : start vertex
# t : current finishing time
# i : input node
# g : graph

# finishing time이 일정 수치를 넘길 때마다 해당 node와 finishig time을 공개한다.
m = 0
def record(i):
    global t, m
    if t >= m * 100000:
        print('Point %i t = %i' % (i + 1, t))
        m += 1

# DFS 함수
def tdone(g, i):
    global f, t, leader, s, ex
    i -= 1 # node i는 g[i - 1]에 있다.
    for j in g[i]: # 해당 노드의 모든 연결점에 대하여
        if not ex[j - 1]: # 아직 안가본 곳이 있다면, 한 곳
            ex[j - 1] = True # 가봤다고 하고
            leader[j - 1] = s # leader는 s로
            return j # 안가본 곳이 있다면 이걸 반환. 간 곳을 기록하기 위함
    t += 1 # 모두 가봤다면 finishing time 증가
    f[i] = t
    record(i) # finishing time이 일정 수치 넘겼다면 출력
    return 0 # 안가본 곳이 없다면 이걸 반환. 갈 곳이 없다는 뜻

def DFS_loop(g): # 전체 DFS 함수. tdone 함수를 이용한다.
    global t, s, ex, f, N
    for i in list(range(N))[::-1]: # 역순으로
        if not ex[i]:
            s = i + 1 # idx가 아닐 때에는 +1 상태로
            ex[i] = True
            leader[i] = s
            exlist = [i + 1] # 접근한 node를 list에 저장 + 경계조건 설정
            while True:
                if len(exlist) == 0:
                    break
                j = tdone(g, exlist[-1])
                if j == 0:
                    exlist.pop(-1) # 이 길이 아니다... 라는 뜻
                else:
                    exlist += [j] # 이 길이 맞다...! 라는 뜻

# 역방향으로 한 번
t = 0
s = None
ex = [False] * N
f = [0] * N
leader = [0] * N
print('Loop1')
DFS_loop(g2)

# change name as finishinge time
for i in range(len(g1)):
    for j in range(len(g1[i])):
        g1[i][j] = f[g1[i][j] - 1]
     
# 정방향 DFS  
t = 0
s = None
ex = [False] * N
f = [0] * N
leader = [0] * N
print('Loop2')
DFS_loop(g1)

# leader 기록
sccdic = {}
for i in leader:
    if i in sccdic:
        sccdic[i] += 1
    else:
        sccdic[i] = 1

# leader 상위 5개 출력
sccrank = list(sccdic.values()) # value를 기준으로 list를 만든다.
sccrank.sort(reverse=True)
print(sccrank[:5])