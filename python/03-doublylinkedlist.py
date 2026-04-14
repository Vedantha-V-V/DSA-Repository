class Node:
    def __init__(self,value):
        self.prev = None
        self.data = value
        self.next = None

class DoublyLinkedList:
    def __init__(self):
        self.head = None

    def insert_end(self,value):
        new_node = Node(value)
        if(self.head==None):
            self.head = new_node
            return
        temp = self.head
        while(temp.next!=None):
            temp=temp.next
        temp.next = new_node
        new_node.prev = temp

    def insert_beginning(self,value):
        new_node = Node(value)
        if(self.head==None):
            self.head = new_node
            return
        new_node.next = self.head
        self.head.prev = new_node
        self.head = new_node

    def insert_at_position(self,value,x):
        temp = self.head
        while(temp.next!=None):
            if(temp.data == x):
                break
            else:
                temp = temp.next
        new_node = Node(value)
        new_node.next = temp.next
        temp.next.prev = new_node
        temp.next = new_node
        new_node.prev = temp

    def delete(self,value):
        if(self.head==None):
            return
        temp = self.head
        if(temp.data == value):
            self.head = temp.next
            self.head.prev = None
            return
        while(temp.next!=None):
            if(temp.data == value):
                temp.prev.next = temp.next
                temp.next.prev = temp.prev
                return
            temp = temp.next
        if(temp.data == value):
            temp.prev.next = None    
        

    def traversal(self):
        temp = self.head
        while(temp.next!=None):
            print(temp.data,end=" <-> ")
            temp = temp.next
        print(temp.data)

dll = DoublyLinkedList()
dll.insert_end(10)
dll.insert_end(20)
dll.insert_end(30)
dll.insert_end(40)
dll.insert_beginning(5)
dll.insert_at_position(50,20)
dll.delete(5)
dll.delete(50)
dll.delete(40)
dll.traversal()