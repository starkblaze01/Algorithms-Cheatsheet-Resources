# Doubly Linked List with implementation
# insert at any side
# print in any direction

class Node:
	def __init__(self, data=None, prev=None, next=None):
		self.data = data
		self.prev = prev
		self.next = next

class DoublyLinkedList:
	def __init__(self):
		self.head = None

	def insert_at_beginning(self, data):
		self.head = Node(data, next=self.head)
		self.head.next.prev = self.head
		return

	def insert_at_end(self, data):
		if self.head == None:
			self.head = Node(data, next=self.head)
			return

		itr=self.head
		while itr:
			if(itr.next==None):
				itr.next = Node(data, prev=itr)
				break
			itr = itr.next
		return

	def print_forward(self):
		if self.head is None:
			print("Linked list is empty")
			return

		itr=self.head
		while itr:
			print(str(itr.data) + " <-->", end=" ")
			itr = itr.next
		print(" ")
		return

	def print_backward(self):
		if self.head is None:
			print("Linked list is empty")
			return
            
		itr=self.head
		while itr.next:
			itr = itr.next
		while itr:
			print( str(itr.data) + " <-->", end=" ")
			itr=itr.prev
		print(" ")
		return

# Main Code

if __name__ == '__main__':
	ll = DoublyLinkedList()

	ll.insert_at_end("How")
	ll.insert_at_end("are")
	ll.insert_at_end("you ?")
	print("3 words appended to the end of the list :")
	ll.print_forward()

	print(" ")

	ll.insert_at_beginning("Hello,")

	print("1 word added at the beginning")
	ll.print_forward()
	
	print(" ")

	print("Printing the Doubly Linked List backwards :")
	ll.print_backward()
