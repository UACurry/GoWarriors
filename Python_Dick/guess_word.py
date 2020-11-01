import random

word = (
    'python',
    'warriors',
    'computer',
    'problem',
    'money',
    'fame',
    'remove',
    'append',
    'game',
    'sense',
)
print("欢乐时光就要开始了，下面有请游玩猜单词游戏！")
Go_on = 'Y'
while Go_on == 'Y' or Go_on == 'y':
    randomWord = random.choice(word)
    answer = randomWord
    newWord = ''
    while randomWord:
        index = random.randrange(len(randomWord))
        newWord += randomWord[index]
        randomWord = randomWord[:index] + randomWord[(index + 1):]
    print('乱序后单词：', newWord)
    guessWord = input('猜一下正确的答案：')
    while guessWord != answer:
        print("不好意思，猜的不正确。")
        guessWord = input("请再次输入：")
    if guessWord == answer:
        print("恭喜大爷！猜对啦！")
    Go_on = input("\n大爷还玩吗:")
