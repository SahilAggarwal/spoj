# your code goes here
# your code goes here
t=int(input())

def getMirror(nm):
	nod=len(nm)
	if nod%2 == 0:
		mid=int(nod/2)
		first_half=nm[0:mid]
		second_half=first_half[::-1]
		return first_half + second_half
	else:
		mid=int(nod/2)
		first_half=nm[0:mid]
		second_half=first_half[::-1]
		return first_half + [nm[mid]] + second_half

def isGreater(pall,num):
	if len(pall) != len(num):
		return len(pall) > len(num)
	mid=int(len(pall)/2)
	for i in range(mid-1,len(pall)):
		if pall[i] != num[i]:
			return pall[i] > num[i]
	return False
	
def getBiggerPallindrome(num,pos1,pos2):
	if pos1 < 0:
		num = ['1'] + num
		num[len(num)-1] = 1
		return num
	if int(num[pos1]) < 9:
		new_num=int(num[pos1]) + 1
		num[pos1],num[pos2] = new_num,new_num
		return num
	else:
		num[pos1],num[pos2]='0','0'
		return getBiggerPallindrome(num,pos1-1,pos2+1)
	
def pallindrome(nm):
	nod = len(nm)
	mirror=getMirror(nm)
	if isGreater(mirror,nm):
		return ''.join(str(e) for e in mirror)
	else:
		pos1,pos2=0,0
		if nod%2 !=0:
			pos1,pos2=nod/2,nod/2
		else:
			pos1,pos2=nod/2-1,nod/2
		nm = getBiggerPallindrome(mirror,int(pos1),int(pos2))
		return ''.join(str(e) for e in nm)
		
while (t>0) :
	nm=raw_input()
	print pallindrome(list(nm))
	t=t-1
	
