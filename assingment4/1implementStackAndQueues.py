# implementing stack and queue using linked list
class Node:
    def __init__(self, key=0):
        self.key = key
        self.next = None


class Stack:
    def __init__(self):
        self.head = None

    def __repr__(self):
        res = ""
        curr = self.head
        while curr is not None:
            res = res + str(curr.key) + " "
            curr = curr.next
        return res

    def add(self, data):
        if self.head is None:
            newNode = Node(data)
            self.head = newNode
        else:
            newNode = Node(data)
            newNode.next = self.head
            self.head = newNode

    def top(self):
        if self.head is not None:
            return self.head.key
        return self.head

    def pop(self):
        if self.head is None:
            return None
        self.head = self.head.next


class Queue:
    def __init__(self):
        self.head = None
        self.tail = None

    def __repr__(self):
        res = ""
        curr = self.head
        while curr is not None:
            res = res + str(curr.key) + " "
            curr = curr.next
        return res

    def add(self, data):
        newNode = Node(data)
        if self.tail == None:
            self.tail = newNode
        else:
            self.tail.next = newNode
            self.tail = newNode

    def top(self):
        if self.head is not None:
            return self.head.key
        return None

    def pop(self):
        if self.head is None:
            return None
        self.head = self.head.next


if __name__ == "__main__":
    s = Stack()
    for i in range(1, 5+1):
        s.add(i)
    print(s)
    print(s.top())
