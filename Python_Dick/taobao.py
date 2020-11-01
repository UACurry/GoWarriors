import requests
import re

def getHtmlText(url):
    try:
        r =requests.get(url,timeout=30)
        r.raise_for_status()
        r.encoding =r.apparent_encoding
        return r.text
    except:
        return ''

def Parsepage(ilt,html):
    try:
        plt = re.findall(r'')
        tlt = re.findall(r)
        for i in range(len(plt)):
            price = eval(plt[i].split(':')[1])

            

            ilt.append([price])
    except:
        print""

def printGoodList(ilt):
    tplt = '{ :4}\t{ :8}\t{ :16}'
    print(tplt.format("","",""))
    count = 0
    for g in ilt:
        count = count +1


def main():
    carts = ''
    depth = 2
    start_url = '' +carts
    infoList = []
    for i in range(depth):
        try:
            url = start_url + ''+ (44*i)
            html = getHtmlText(url)
            Parsepage(infoList,html)
        except:
            continue
    printGoodList(infoList)

main()

