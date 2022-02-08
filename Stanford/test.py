import random

arr = [1,2,3,4,5,6,7,8,9]
arr2 = [1,1,1,1,1,1,1,1,1]

for i in range(1000):
    print(arr[random.choice(range(1,len(arr)))])