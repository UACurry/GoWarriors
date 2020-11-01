from bs4 import BeautifulSoup
from urllib.request import urlopen
import re
import random
import lxml

base_url = "https://baike.baidu.com"
his = ["/item/%E7%BD%91%E7%BB%9C%E7%88%AC%E8%99%AB/5162711?fromtitle=%E8%9C%98%E8%9B%9B&fromid=8135707"]

for i in range(20):
    url = base_url + his[-1]

    html = urlopen(url).read().decode("utf-8")
    soup = BeautifulSoup(html,features='lxml')

    sub_urls = soup.find_all("a",{"target":"_blank"}, "href" : re.compile("/item/(%.{2})+$")})
    print(sub_url)
    #print(soup.find('h1').get_text())