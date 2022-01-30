fr_info = {
    'Summer' : ['John','Justin','Mike'],
    'John' : ['Summer','Justin'],
    'Justin' : ['John', 'Summer','Mike','May'],
    'Mike' : ['Summer','Justin'],
    'May' : ['Justin','Kim'],
    'Kim' : ['May'],
    'Tom' : ['Jerry'],
    'Jerry' : ['Tom']
}

def print_all_freinds(g, start):
    #g는 그래프, start는 모든 친구를 찾을 대상
    qu = []
    done = set()
    inti = 0
    qu.append((start, 0))
    done.add(start)
    
    while(qu):
        while(qu):
            (p,inti) = qu.pop(0)
            print((p, inti))
            for x in g[p]:
                if x not in done :
                    qu.append((x, inti + 1))
                    done.add(x)
                
print_all_freinds(fr_info, 'Summer')
print()
print_all_freinds(fr_info, 'Jerry')