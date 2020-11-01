word_yuan = ["a","e","i","o","u","A","E","I","O","U"]
while True:
    word = str(input("请输入单词,以逗号为分隔符"))
    temp = word.split(",")
    for i in temp:
        for j in word_yuan:
            if i[0] == j[0]:
                print (i)
            else:
                pass
