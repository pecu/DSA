# -*- coding: utf-8 -*-
"""
Created on Fri Nov 15 22:24:29 2019

@author: pecu
"""

class RedBlackTreeNode(object):
    
    def __init__(self, x, c='red'):
        self.val = x
        self.left = None
        self.right = None
        self.color = c
        
    def insert(self, x):        
        if self.val:
            if x <= self.val:
                if self.left is None:
                    self.left = RedBlackTreeNode(x)
                else:
                    self.left.insert(x)
            elif x > self.val:
                if self.right is None:
                    self.right = RedBlackTreeNode(x)
                else:
                    self.right.insert(x)
        else:
            self.val = x
            
    def rightRotate(self):
        x = self.left
        self.left = x.right
        x.right = self
        x.color = x.right.color
        x.right.color = 'red'
        return x

    def leftRotate(self):
        x = self.right
        self.right = x.left
        x.left = self
        x.color = x.left.color
        x.left.color = 'red'
        return x
            
    def preorder(self):
        print(self.val)
        if self.left:
            self.left.preorder()
        if self.right:
            self.right.preorder()
            
########################################
            
root = RedBlackTreeNode(12)
root.insert(6)
root.insert(14)
root.insert(3)
root.insert(1)
root.insert(0)
root.preorder()

print("get right rotate node")
p = root.left.left
p.preorder()

print("right rotate")
new_p = p.rightRotate()
new_p.preorder()