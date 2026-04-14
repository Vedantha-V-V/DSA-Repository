class Stack:
    def __init__(self):
        self.stack = []

    def length(self):
        return len(self.stack)
    
    def push(self,value):
        self.stack.insert(0,value)

    def peek(self):
        if(len(self.stack)==0):
            raise Exception("Stack underflow")
        else:
            return self.stack[0]

    def pop(self):
        if(len(self.stack)==0):
            raise Exception("Stack underflow")
        else:
            return self.stack.pop(0)
    
stack = Stack()
stack.push(10)
stack.push(20)
stack.push(30)
print(stack.pop())
print(stack.peek())