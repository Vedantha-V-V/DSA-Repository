class Node:
    def __init__(self,info,next=None):
        self.info = info
        self.next = next

class SinglyLinkedList:
    def __init__(self,head=None):
        self.head = head

    def insert_end(self,val):
        new_node = Node(val)
        if(self.head!=None):
            temp = self.head
            while(temp.next!=None):
                temp = temp.next
            temp.next = new_node
        else:
            self.head = new_node
        
    def insert_beginning(self,val):
        new_node = Node(val)
        if(self.head!=None):
            new_node.next = self.head
            self.head = new_node
        else:
            self.head = new_node

    def insert_middle(self,value,x):
        new_node = Node(value)
        temp = self.head
        while(temp.next!=None):
            if(temp.info == x):
                new_node.next = temp.next
                temp.next = new_node
            temp = temp.next

    def delete(self,val):
        temp = prev = self.head
        if(temp.info == val):
            self.head = temp.next
        while(temp.next!=None):
            if(temp.info == val):
                prev.next = temp.next
                break
            else:
                prev = temp
                temp = temp.next
        if(temp.info == val):
            prev.next = None


    def traversal(self):
        temp = self.head
        while(temp!=None):
            print(temp.info)
            temp = temp.next

linked_list = SinglyLinkedList()
linked_list.insert_end(10)
linked_list.insert_end(20)
linked_list.insert_end(30)
linked_list.insert_beginning(5)
linked_list.insert_middle(40,20)
linked_list.delete(5)
linked_list.traversal()