# ex1 = '3141592653589793238462643383279502884197169399375105820974944592'
# ex2 = '2718281828459045235360287471352662497757247093699959574966967627'

ex1 = '1234'
ex2 = '5678'

def Karatsuba(num1, num2):
    if len(str(num1)) == 1 or len(str(num2)) == 1 :
        return str(int(num1) * int(num2))           
    else:
        halfLen = max(len(num1), len(num2)) // 2
        a,b,c,d = num1[:halfLen], num1[halfLen:],num2[:halfLen], num2[halfLen:]
        
        data1 = Karatsuba(a, c)
        data2 = Karatsuba(b, d)
        data3 = str(int(Karatsuba(str(int(a) + int(b)), str(int(c) + int(d)))) - int(data1) - int(data2))
        return int(data1) * (10 ** (halfLen*2)) + int(data3) * (10 ** halfLen) + int(data2)    

print(Karatsuba(ex1, ex2))

## 아래 정상 작동과 boundary condition을 비교하라.

# ex1 = 1234
# ex2 = 5678

# def karatsuba(x,y):
# 	"""Function to multiply 2 numbers in a more efficient manner than the grade school algorithm"""
# 	if len(str(x)) == 1 or len(str(y)) == 1:
# 		return x*y
# 	else:
# 		n = max(len(str(x)),len(str(y)))
# 		nby2 = n // 2
		
# 		a = x // 10**(nby2)
# 		b = x % 10**(nby2)
# 		c = y // 10**(nby2)
# 		d = y % 10**(nby2)
		
# 		ac = karatsuba(a,c)
# 		bd = karatsuba(b,d)
# 		ad_plus_bc = karatsuba(a+b,c+d) - ac - bd
        
#         	# this little trick, writing n as 2*nby2 takes care of both even and odd n
# 		prod = ac * 10**(2*nby2) + (ad_plus_bc * 10**nby2) + bd

# 		return prod

# print(karatsuba(int(ex1), int(ex2)))