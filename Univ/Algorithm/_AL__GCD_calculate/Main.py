def gcd_sub(a, b):
	while a !=0 and b != 0:
		if a < b:
			b = b - a
		else :
			a = a - b
	return a + b
	
def gcd_mod(a, b):
	while a !=0 and b != 0:
		if a < b:
			b = b % a
		else :
			a = a % b
	return a + b
	
def gcd_rec(a, b):
	if a == b:
		return a
	if a>b:
		return gcd_rec(a-b, b)
	else:
		return gcd_rec(a, b-a)
	
# a, b를 입력받는다
# gcd_sub, gcd_mod, gcd_rec을 각각 호출하여, x, y, z에 리턴값을 저장한다

a = input()
a = a.split()	#문자열을 쪼개는 함수 (\ or space)
a[0] = int(a[0])
a[1] = int(a[1])

x = gcd_sub(a[0], a[1])
y = gcd_mod(a[0], a[1])
z = gcd_rec(a[0], a[1])
print(x, y, z)