a=[]
b=[]
c=[]

def getdata():
	global x	
	x=int(input("How many students play cricket="))
	for i in range(0,x):
		p=input("Enter the names=")
		a.append(p)
	
	global y
	y=int(input("How many students play badminton="))
	for i in range(0,y):
		q=input("Enter the names=")
		b.append(q)
		
	global z	
	z=int(input("How many students play football="))
	for i in range(0,z):
		r=input("Enter the names=")
		c.append(r)
	return(a,b,c)
	
getdata()
print(a)
print(b)
print(c)

#def intersection(l1,l2):
#	res=[]
#	for i in range(0,x):
#		for j in range(0,y):
#			if(l1[i]==l2[j]):
#				res.append(l1[i])
#	return (res)
#print(intersection(a,b))

def intersection(l1,l2):
	res=[]
	for i in range (0,len(l1)):
		flag=0
		for j in range(0,len(l2)):
			if(l1[i]==l2[j]):
				flag=1
		if(flag==1):
			res.append(l1[i])
	return(res)
print(intersection(a,b))
		
def union(l1,l2):
	res=l1.copy()
	for i in range(0,len(l2)):
		flag = 0
		for j in range(0,len(l1)):
			if(l2[i] == l1[j]):
				flag = 1
		if (flag==0):
				res.append(l2[i])				
	return (res)
print(union(a,b))

def diff(l1,l2):
	res=[]
	for i in range(len(l1)):
		flag=0
		for j in range(len(l2)):
			if(l1[i] == l2[j]):
				flag=1
		if(flag==0):
				res.append(l1[i])
	return (res)
diff(a,b)
#print(diff(a,b))
print(union(diff(a,b),diff(b,a)))

# def ex_or(l1,l2):
# 	x1=diff(l1,l2)
# 	x2=diff(l2,l1)
# 	x3=union(x1,x2)
# 	return(x3)
#print(ex_or(a,b))