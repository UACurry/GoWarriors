
#日期
week_day_dict = {
    1 : '星期一',
    2 : '星期二',
    3 : '星期三',
    4 : '星期四',
    5 : '星期五',
    6 : '星期六',
    7 : '星期天',
    }
def week(year, month, day):
    #定义变量
    #为了安全，转换为整型，
    #就像做爱带套一样
    month = int(month)
    year = int(year)
    day =int(day)

    #要求取前后两位
    year = year - int(year / 100) * 100   
    #年份前两位
    century = int(year/100)  
    
    if month == 1 or month == 2:
        month = month + 12
        year = year - 1   
        
    w = (int(century/4) - 2 * century + year + int(year/4) + int(13 * (month + 1)/5) + day - 1) % 7
    return week_day_dict[w]

while(1):
    date = input("输入日期")
    if date == 'out':
        exit()
    else:
        date_split = date.split("/")
        print(week(date_split[0],date_split[1],date_split[2]))
