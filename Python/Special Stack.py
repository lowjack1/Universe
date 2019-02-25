''' Implementation of special stack which can perform following operation
    push(s)
    pop()
    getMin()
    top()
    size()

    Time Complexity : O(1)
    Space Complexity: O(1)
'''

class SpecialStack:
    def __init__(self):
        self.__stack = []
        self.__minElement = None; 
        self.__stackSize = 0
        self.__stackTop = None

    def push(self, element):
        if not self.__stackSize:
            self.__stack.append(element)
            self.__minElement = element
        elif element >= self.__minElement:
            self.__stack.append(element)
            self.__stackTop = element            
        else:
            self.__stack.append(2 * element - self.__minElement)
            self.__stackTop = 2 * element - self.__minElement
            self.__minElement = element
        self.__stackSize += 1

    def pop(self):
        topElement = None
        if not self.__stackSize:
            ''' if stack is empty '''
            try:
                raise IndexError('Stack is Empty')
            except IndexError as err:
                print("IndexError: " + str(*err.args))
        elif self.__stackTop >= self.__minElement:
            topElement = self.__stack.pop()
            self.__stackSize -= 1
            
            if self.__stackSize:
                self.__stackTop = self.__stack[-1]
            else:
                self.__stackTop = None
                self.__minElement = None
        else:
            topElement = self.__minElement
            res = self.__stack.pop()
            self.__minElement = 2 * self.__minElement - res
            self.__stackSize -= 1

            if self.__stackSize:
                self.__stackTop = self.__stack[-1]
            else: 
                self.__stackTop = None
                self.__minElement = None
        return topElement

    def getMin(self):
        ''' minimum element of stack '''
        return self.__minElement

    def top(self):
        ''' top element of stack '''
        return self.__stackTop

    def __len__(self):
        ''' size of stack '''
        return self.__stackSize

''' Instantiating the SpecialStack object '''

stack = SpecialStack()

stack.push(3)
stack.push(5)
print(stack.getMin())
while len(stack) > 0:
    print(stack.pop())
