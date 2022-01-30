maze = {
    'a' : ['e'],
    'b' : ['c','f'],
    'c' : ['b','d'],
    'd' : ['c'],
    'e' : ['a','i'],
    'f' : ['b','g','j'],
    'g' : ['f', 'h'],
    'h' : ['g','l'],
    'i' : ['e','m'],
    'j' : ['f', 'k', 'n'],
    'k' : ['j','o'],
    'l' : ['h','p'],
    'm' : ['i','n'],
    'n' : ['m','j'],
    'o' : ['k'],
    'p' : ['l']
}

def solve_maze(g, start, end):
    #g는 그래프, start는 시작점, end는 끝
    qu = []
    done = set()
    
    qu.append(start)
    done.add(start)
    
    while qu:
        p = qu.pop(0)
        v = p[-1]    #v = p의 마지막 부분이다.
        if v == end:
            return p
        for x in g[v]:    #마지막 부분에 연결된 부분 중
            if x not in done:
                qu.append(p+x)    #이동 경로에 새로운 꼭짓점을 추가한다.
                done.add(x)
        
        
print(solve_maze(maze, 'a', 'p'))