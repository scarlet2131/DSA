# Reverse a string
import sys
inputStr = input("Please enter the string to revers : ")
outStr = ""
for i in range(len(inputStr)-1,-1,-1):
	outStr = outStr + inputStr[i]
print(outStr)

ouStr = inputStr[::-1]
print(ouStr)



# Python stack implementation with list 

def push(list, num):
	list.append(num)
def pop(list):
	list.pop()
def top(list):
	return  list[len(list)-1] if (len(list)>0)  else float('-inf')
stk = []
push(stk, 1)
print(top(stk))
pop(stk)
print(top(stk))
push(stk,-1)
push(stk,9)
print(top(stk))
push(stk,5)

# Python queue implementation with list 
print("------------------- Queue ----------------")
def qPop(que):
	que.reverse()  
	que.pop()  
	que.reverse()  
	

def qTop(list):
	return float('-inf') if len(list)==0 else list[0]
que = []
push(que, 1)
push(que, 4)
print(qTop(que))
qPop(que)
print(que)


print(qTop(que))
push(que,-1)
qPop(que)
print(que)

push(que,9)
print(qTop(que))
push(que,5) 





