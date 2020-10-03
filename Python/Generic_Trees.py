# Making a Generic Tree (N-Array Trees) along with implementation.
# Printing tree with good visual representation.

class TreeNode:
	def __init__(self, data1, data2):
		
		self.data1 = data1
		self.data2 = data2
		self.children = []
		self.parent = None

	def add_child(self, child):
		child.parent = self
		self.children.append(child)

# function to print tree as per the hierarchies

	def print_tree(self, arg="both", level=0):
		if(arg=="name"):
			spaces = "  "*level + "!--" if level > 0 else ""
			print(spaces, self.data1)
			for c in self.children:
				c.print_tree(arg, level+1)
		elif(arg=="designation"):
			spaces = "  "*level + "!--" if level > 0 else ""
			print(spaces, self.data2)
			for c in self.children:
				c.print_tree(arg, level+1)
		elif(arg=="both"):
			spaces = "  "*level + "!--" if level > 0 else ""
			print(spaces, self.data1 + " (" + self.data2 + ")")
			for c in self.children:
				c.print_tree(arg, level+1)

# function to print tree as per the levels

	def print_tree_level(self, level1, level=0):
		spaces = "  "*level + "!--" if level > 0 else ""
		print(spaces, self.data1 + " (" + self.data2 + ")")
		for c in self.children:
			if(level1<=level):break
			c.print_tree_level(level1, level+1)

# Used for making the demo tree.
# Organizational Hierarchy has been used in this example.

def build_managing_tree():
	root = TreeNode("Nilupul", "CEO")

	chinmay = TreeNode("Chinmay", "CTO")
	gels = TreeNode("Gels", "HR Head")
	vishwa = TreeNode("Vishwa", "Infrastructure Head")
	aamir = TreeNode("Aamir", "Application Head")

	vishwa.add_child(TreeNode("Dhaval", "Cloud Manager"))
	vishwa.add_child(TreeNode("Abhijit", "App Manager"))

	gels.add_child(TreeNode("Peter", "Recruitment Head"))
	gels.add_child(TreeNode("Waqas", "Policy Manager"))

	chinmay.add_child(vishwa)
	chinmay.add_child(aamir)

	root.add_child(chinmay)
	root.add_child(gels)

	return root

# Main Code

if __name__ == '__main__':
    root_node = build_managing_tree()

    print("Printing only Name hierarchy:")
    root_node.print_tree(arg="name") # prints only name hierarchy
    print(" ")

    print("Printing only Designation hierarchy")
    root_node.print_tree(arg="designation") # prints only designation hierarchy
    print(" ")

    print("Prints both the hierarchies")
    root_node.print_tree(arg="both") # prints both (name and designation) hierarchy
    print(" ")

    print("Level 1 :")
    root_node.print_tree_level(1)
    print(" ")

    print("Level 2 :")
    root_node.print_tree_level(2)
    print(" ")

    print("Level 3 :")
    root_node.print_tree_level(3)
    print(" ")
