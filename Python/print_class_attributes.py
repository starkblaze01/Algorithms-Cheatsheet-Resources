"""
This script can quickly print all the attributes of a class
"""

class Animal(object):
    def __init__(self):
        self.legs = 2
        self.name = 'Dog'
        self.color = 'Spotted'
        self.smell = 'Alot'
        self.age = 10
        self.kids = 0


an = Animal()
attrs = vars(an)
print('\n'.join("%s: %s" % item for item in attrs.items()))
