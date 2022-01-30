# a = ["tom", "jerry", "mike", "tom"]

# s = set()

# def findsamename(a):
# 	for i in range(0, len(a)-1):
# 		for j in range(i+1, len(a)):
# 			if a[i] == a[j]:
# 				s.add(a[i])
				
# 	return s

# print(findsamename(a))




# a = ["tom", "jerry", "mike"]
# jjak = []
# n = 0 

# def findjjak(lst):
# 	global n 
# 	for i in range(0,len(lst)-1):
# 		for j in range(i+1, len(lst)):
# 			n = n + 1
# 			jjak.append(a[i] + '-' + a[j])
# 	return jjak 

# print(findjjak(a))
# print(n)


# unboundlocalerror를 통해 파이썬의 모든 변수가 지역변수임을 알 수 있다. 값을 할당할 때에는 그 지역에만 있는 변수에 값을 할당할 수 있다.
# 따라서 전역변수로서 변수를 사용하고자 할 때에는 global n 이라고 적어주어야한다. 아니면 다른 방법을 쓰던가...

# https://thebook.io/006888/partxt/xa/07/

# a = ["tom", "jerry", "mike"]
# jjak = []
# n = 0 

# def findjjak(lst):
# 	for i in range(0,len(lst)-1):
# 		for j in range(i+1, len(lst)):
# 			n = n + 1
# 			jjak.append(a[i] + '-' + a[j])
# 	return jjak 

# print(findjjak(a))
# print(n)

# 이게 로컬에러가 나는 코드
# 파이썬은 C언어와 변수의 scope가 다른 듯하다.

# a = ["tom", "jerry", "mike"]

# def findjjak(lst):
#     jjak = []
#     n = 0
#     for i in range(0,len(lst)-1):
#         for j in range(i+1, len(lst)):
#             n = n + 1
#             jjak.append(a[i] + '-' + a[j])
#     print(n)
#     return jjak

# print(findjjak(a))
