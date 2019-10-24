class Node:

    def __init__(self, val):
        self.val = val
        self.next = None
    
def reverse_linked_list(head):

    last = head
    nxt = last.next
    last.next = None
    

    while nxt:
        temp = nxt.next
        nxt.next = last
        last = nxt
        nxt = temp
    
    return last

if __name__ == "__main__":

    new_node = Node(1)
    new_node.next = Node(2)
    new_node.next.next = Node(3)
    node = reverse_linked_list(new_node)

    while node:
        print(node.val) #print 3 2 1
        node = node.next
        