name_dict = {}
name_lst = ['tom', 'jerry', 'mike', 'tom']

def Find_same_name(lst):
    n = len(lst)
    for i in range(0,n):
        if lst[i] in name_dict:
            name_dict[lst[i]] += 1
        else:
            name_dict[lst[i]] = 1
    
    for i in range(0,n):
        if name_dict[lst[i]] != 1:
            print(lst[i], "is in overlapping")
            
Find_same_name(name_lst)