import random

# txt open and pre processing
fd = open('Stanford/Divide and Conquer, Sorting and Searching, and Randomized Algorithms/Week4/kargerMinCut.txt', 'r')
text_array = fd.readlines()
for idx, text in enumerate(text_array):
    text_array[idx] = text.strip('\n')
    # print(text_array)
fd.close()

row_array =[]
for row in text_array:
    row_array.append(row.split('\t'))
    # print(row_array)
    
int_row_array = [list(map(int, i[:-1])) for i in row_array]

# copy graph
def create_graph(int_row_array):
    graph = int_row_array.copy()
    return graph

# algorithm
def minimum_cut(g): # graph input
    while len(g) > 2:
        vertex_delete = g.pop(random.choice(range(len(g))))
        #  융합해서 없앨 노드, 융합 해서 남길 노드 찾음. 정확히는 이 두 vertex 사이의 edge를 없앤다는 것
        vertex_fuse1, vertex_fuse2 = vertex_delete[0], vertex_delete[random.choice(range(1, len(vertex_delete)))]
        while vertex_fuse2 in vertex_delete: # v2가 중복되면 안되므로 제거
            vertex_delete.remove(vertex_fuse2)
        for i in range(len(g)): # 모든 vertex에서 vertex_fuse1를 vertex_fuse2로 대체
            if g[i][0] == vertex_fuse2:
                g[i] += vertex_delete # vertex_fuse2로 합침
                while vertex_fuse1 in g[i]:
                    g[i].remove(vertex_fuse1) # vertex_fuse1 제거
            for j in range(len(g[i])): # vertex_fuse1 -> vertex_fuse2
                if g[i][j] == vertex_fuse1:
                    g[i][j] = vertex_fuse2
    return len(g[0]) - 1


N = 500
min_cut = []
for i in range(N):
    min_cut += [minimum_cut(create_graph(int_row_array))]
print(min(min_cut))