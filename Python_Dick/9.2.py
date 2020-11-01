import re
import requests
from bs4 import BeautifulSoup

path = "D:/top250.txt"

def getHTmlText(url):
    try:
        r = requests.get(url,timeout=30)
        r.raise_for_status()
        r.encoding = r.apparent_encoding
        return r.text
    except:
        return "产生异常"


for i in range(0,2):
    headers = {
        'user-agent': 'Mozilla/5.0 (Windows NT 6.1; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/52.0.2743.82 Safari/537.36'
    }

    url = 'https://movie.douban.com/top250?start='+str(25*i)

    r = requests.get(url, headers=headers, timeout=10)

    soup = BeautifulSoup(r.text, "html.parser")
    div_list = soup.find_all('div', class_='item')
    movies = []
    for each in div_list:
        movie = {}
        moviename = each.find('div', class_='hd').a.span.text.strip()
        movie['电影名字'] = moviename
        rank = each.find('div', class_='pic').em.text.strip()
        movie['排名'] = rank
        info = each.find('div', class_='bd').p.text.strip()
        info = info.replace('\n', "")
        info = info.replace(" ", "")
        info = info.replace("\xa0", "")
        director = re.findall(r'[导演:].+[主演:]', info)[0]
        director = director[3:len(director) - 6]
        movie['导演'] = director
        release_date = re.findall(r'[0-9]{4}', info)[0]
        movie['上映时间'] = release_date
        plot = re.findall(r'[0-9]*[/].+[/].+', info)[0]
        plot = plot[1:]
        plot = plot[plot.index('/') + 1:]
        plot = plot[plot.index('/') + 1:]
        movie['情节'] = plot
        star = each.find('div', class_='star')
        star = star.find('span', class_='rating_num').text.strip()
        movie['评分'] = star
        movies.append(movie)
        with open(path,"wb") as f:
            f.write(movie)
            f.close

if __name__ == "__main__":
    url = 'movie.douban.com/top250?start='+str(25*i)
    print(getHTmlText(url))
