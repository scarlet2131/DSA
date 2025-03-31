################################################ Automation & Scripting ############################################

import os
import subprocess

result = subprocess.run(['ls', '-l'])
print(result)
print(os.listdir())
# print()

################################################ Error handling ################################################

try:
	with open('try.txt','r') as f:
		content = f.read()
		print(content)
except FileNotFoundError:
	print( "file not found")

# Logging module 
# The logging module allows you to track events and errors in your application. 
# Use it instead of print() for better debugging and monitoring.

import logging 

logging.basicConfig(level= logging.INFO)
# logging.info("THIS IS A ERROR EMSSAGE ")

################################################ Printing ################################################

print("monisha", end=' - ')
print("is good",end = '\n')
print("Monisha got ","10 internhsps ", sep=' - ')

################################################ list/tuple/dict/set ################################################
var = input("please enter the number ")  # by default it takes a string 
a= [] # list
b = () #tuple
c = {'1': '23', '3': '45'}
d = {'2','3','4'}

print(type(a))
print(type(b))
print(type(c))
print(type(d))

lst = [print(char) for char in[1,2,3,4,5]]
myDict = { k:k**2 for k in [1,2,3,4,5,6]}
print(myDict)

# myDict2 = { k:v for (k,v) in zip(d, (v1 for (k1,v1) in myDict) )}
# print(myDict2)

################################################ Mutable / immutable ################################################
# Mutable objects in Python are those that can be changed after they are created, like lists , dictionaries,sets. 
# Immutable objects, on the other hand, cannot be changed after they are created, such as strings, integers, or tuples.

# Pass by value and reference

# if we pass a immutable obj to  a function it behaves as pass by value 
# for mutable obejcts it is pass by refence to if anything is chnged inside the function the outside obj will also change

def myFun(arg1, arg2, arg3):
	arg1 += "h"
	print("arg1:", arg1)
	print("arg2:", arg2)
	print("arg3:", arg3)
# variable argument can be passed to this method
# Now we can use *args or **kwargs to
# pass arguments to this function :
args = ("Geeks", "for", "Geeks")
myFun(*args)
kwargs = {"arg1": "Geeks", "arg2": "for", "arg3": "Geeks"}
myFun(**kwargs)
print(kwargs)

################################################ python builtin map function ################################################
def add(n):
	return n+n
arr = [1,2,3,4]
arr = map(add,arr)
print(list(arr))

################################################# python builtin filter function ################################################
def vowel(ch):
	if ch in ['a','e','i','o','u']:
		return True
	else:
		return False

ch = ['m','o','n','i','s','h','a']
ch  = filter(vowel, ch)
print(list(ch))

################################################ python builtin reduce function ################################################
from functools import reduce
nums = [1,2,3,4]
ans = reduce(lambda x, y : x+y, nums)
ans1 = reduce(lambda x, y : x if x>y else y , nums)

print(ans)
print(ans1)
# the way def keyword is used in python for creating a method lambda keyword s sued to create a anonymous function

################################################ file handlng in python ################################################
import os

# if we write on existing file it overwrites the existing content
def createFile(filename):
	try:
		with open(filename,'w') as f:
			f.write("My name is monisha and i got 10 internships ad 5 full time offer. ")
		print(filename + " Sucessfully created!!!")
	except IOError:
		print("Error: couldn't create file")

def readFile(filename):
	try:
		with open(filename,'r') as f:
			contents = f.read()
			print(contents)
	except IOError:
		print("Error: file not found")

def appendFile(filename):
	try:
		with open(filename,'a') as f:
			f.write("Monisha will do great in life!!")
		print(filename + 'Sucessfully appended')
	except IOError:
		print("Error: couldn't append in file ")

def deleteFile(filename):
	try: 
		os.remove(filename)
		print(filename + 'Sucessfully deleted')
	except IOError:
		print("Error: couldn't delete the file ")

def renameFile(filename):
	try:
		os.rename(filename, "Monisha Sucess Story.txt")
	except IOError:
		print("Error: couldn't rename the file ")

createFile("Mon.txt")
readFile("Mon.txt")
appendFile("Mon.txt")
readFile("Mon.txt")
renameFile("Mon.txt")
deleteFile("Mon.txt")

################################################ List and tuples ################################################
# tuple is fatser than list as doesnt need more space like list 
list = [1,2,3,4]
list.append(5) # at the end
print(list)
print(list[2])
list.remove(3)  # removes the given value
print(list)
list.pop() # removes from last
print(list)
list.extend(nums) # adds any list or tuple to it
print(list)
list.sort() #sorts the list
print(list)

tuple = ( 5,6,7,8,5,9,6)
print(tuple.index(8)) # gives index of given element
print(tuple.count(5)) # retuns count of give ele in tuple

# list cat be used as a keyin dict because it is mutable only tuple can be used 
dict = {(1,2): 'monisha'}
print(dict)

# Both lists and tuples can contain other lists or tuples inside them (nesting).
l1 = [[1,2,3], [4,5,6]]
l2 = ((5,6,7), (8,9,10))

print(l1)
print(l2)

set = {23, 45}

list.extend(set)
print(list)

################################################ Diff b/w extends and append ################################################
# extend(): Adds the elements of the iterable (list, tuple, etc.) to the list individually.
# append(): Adds the entire object (e.g., a list) as a single element to the list.

list.append(set)
print(list)
