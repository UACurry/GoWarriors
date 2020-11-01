class Dog:
    def __init__(self, name, color):
        self.name = name
        self.color = color

    def printInfo(self):
        print('Dog:' + self.name + ',' + 'color:' + self.color)


def main():
    a, b = input().split(',')
    dog = Dog(a, b)
    dog.printInfo()


main()