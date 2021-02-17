# implementing stack and queue using linked list
class Node:
    def __init__(self, key=0):
        self.key = key
        self.next = None
        self.prev = None


class Deque:
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

    def addRight(self, data):
        newNode = Node(data)
        if self.tail == None:
            self.tail = newNode
        else:
            self.tail.next = newNode
            self.tail = newNode

    def addLeft(self, data):
        newNode = Node(data)
        if self.head == None:
            self.head = newNode
        else:
            newNode.next = self.head
            self.head = newNode

    def popLeft(self):
        if self.head is None:
            return None
        self.head = self.head.next

    def popRight(self):
        if self.tail is None:
            return None
        self.tail = self.tail.prev


if __name__ == "__main__":
    dq = Deque()
    for i in range(1, 5+1):
        dq.addRight(i)
    print(dq)
