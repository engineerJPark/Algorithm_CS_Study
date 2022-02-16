arr = [10,20,30,40,50,70,80]

idx = min(range(len(arr)), key=lambda i: arr[i])

print(idx)