class MyQueue(object):

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.inputStack = []
        self.resStack = []
        

    def push(self, x):
        """
        Push element x to the back of queue.
        :type x: int
        :rtype: None
        """
        self.inputStack.append(x)

    def pop(self):
        """
        Removes the element from in front of queue and returns that element.
        :rtype: int
        """
        if self.resStack:
            return self.resStack.pop()
        while len(self.inputStack) is not 0:
            self.resStack.append(self.inputStack.pop())
        return self.resStack.pop()
    
    def peek(self):
        """
        Get the front element.
        :rtype: int
        """
        if self.resStack:
            return self.resStack[-1]
        while len(self.inputStack) is not 0:
            self.resStack.append(self.inputStack.pop())
        return self.resStack[-1]
    

    def empty(self):
        """
        Returns whether the queue is empty.
        :rtype: bool
        """
        return len(self.inputStack) == 0 and len(self.resStack) ==0