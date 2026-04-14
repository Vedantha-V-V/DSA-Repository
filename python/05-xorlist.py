import ctypes

class Node:
    def __init__(self, value):
        self.value = value
        self.both = 0
        

class XORLinkedList:
    def __init__(self):
        self.head = None
        self.tail = None
        self.__nodes = []

    def insert_beginning(self, value):
        node = Node(value)
        if self.head is None: 
            self.head = node
            self.tail = node
        else:
            self.head.both = id(node) ^ self.head.both
            node.both = id(self.head)
            self.head = node
        self.__nodes.append(node)

    def insert_end(self, value):
        node = Node(value)
        if self.head is None: 
            self.head = node
            self.tail = node
        else:
            self.tail.both = id(node) ^ self.tail.both
            node.both = id(self.tail)
            self.tail = node
        self.__nodes.append(node)

    def delete(self,key):
        if self.head is None:
            print("XOR linkedlist is empty.")
            return

        if self.head.value == key:
            next_node_id = self.head.both
            next_node = self.__type_cast(next_node_id)
            if next_node:
                next_node.both ^= id(self.head)
            self.head = next_node
            if self.head is None:
                self.tail = None
            return

        prev = 0
        curr = self.head
        next = 0

        while curr:
            next = prev ^ curr.both
            
            if curr.value == key:
                prev_node = self.__type_cast(prev_id)
                if prev_node:
                    prev_node.both = (prev_node.both ^ id(curr)) ^ next

                if next != 0:
                    next_node = self.__type_cast(next)
                    if next_node:
                        next_node.both = (next_node.both ^ id(curr)) ^ prev
                else:
                    self.tail = prev_node
                return

            prev_id = id(curr)
            curr = self.__type_cast(next)

    def traverse_left_right(self):
        if self.head == None:
            print("XOR linkedlist is empty.")
            return
        prev = 0
        node = self.head
        next = 1
        print(node.value, end=' ')
        while next:
            next = prev ^ node.both
            if next:
                prev = id(node)
                node = self.__type_cast(next)
                print(node.value, end=' ')
            else:
                return

    def traverse_right_left(self):
        if self.head == None:
            print("XOR linkedlist is empty.")
            return
        prev = 0
        node = self.tail
        next = 1
        print(node.value, end=' ')
        while next:
            next = prev ^ node.npx
            if next:
                prev = id(node)
                node = self.__type_cast(next)
                print(node.value, end=' ')
            else:
                return

    def __type_cast(self, id):
        return ctypes.cast(id, ctypes.py_object).value
      
xorlinkedlist = XORLinkedList()

is_on = True
while(is_on):
    print("-------------------------------")
    print("Enter your choice (numeric):")
    print("1.) Insert Beginning")
    print("2.) Insert End")
    print("3.) Delete specific value")
    print("4.) Traversal Left to Right")
    print("5.) Traversal Right to Left")
    print("6.) Exit")
    print("--------------------------------")
    choice = int(input())
    if(choice == 1):
        val = int(input("Enter the value:")) 
        xorlinkedlist.insert_beginning(val)
    elif(choice == 2):
        val = int(input("Enter the value:")) 
        xorlinkedlist.insert_end(val)
    elif(choice == 3):
        val = int(input("Enter the value:")) 
        xorlinkedlist.delete(val)
    elif(choice == 4):
        print("Linked List:")
        xorlinkedlist.traverse_left_right()
        print()
    elif(choice == 5):
        print("Linked List:")
        xorlinkedlist.traverse_right_left()
        print()
    elif(choice == 6):
        print("Exiting...")
        is_on = False
    else:
        print("Invalid choice")



