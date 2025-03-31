
# likedlist is dynamic in nature
# insertion at beginneing end or mid is done in o(1) time so efficient as well 

# __init is a constructor in python it is called when a new object is creatted 
# self is the insance of the object which is being created 

class node:
	def __init(self, data):
		self.data = data
		self.next = None

def reverse(head):
	prev = head
	prev.next = NULL
	curr = head.next
	next = curr.next

	while(curr!=NULL):
		curr.next = prev
		prev = curr
		curr = next
		next = curr.next

node = new node(self, 0)
for i in range (5):
	n1 = new node(self, i+1)
	node.next = n1
	node = n1






