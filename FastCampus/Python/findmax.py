a = [17,92,18,33,58,7,33,42]

max = a[0]
soonseo = 0

for i in range(1, len(a)):
	if max < a[i]:
		max = a[i] 
		soonseo = i + 1

print(max)
print(soonseo)