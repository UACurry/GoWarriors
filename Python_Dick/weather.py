import requests
from bs4 import BeautifulSoup


def get_citycode(city_name):
    city = {"北京": "101010100", "上海": "101020100", "苏州": "101190401"}

    for k in city:
        if (city_name in k):
            code = k.split(':')[0].strip()
            return code


def get_15d_url(city_name):
    url = 'http://www.weather.com.cn/weather15d/'
    code = get_citycode(city_name)
    return url + code + '.shtml'


def get_content(url, data=None):
    rep = requests.get(url, timeout=60)
    rep.encoding = 'utf-8'
    return rep.text


def get_15d_data(htmltext, city):
    content = []
    bs = BeautifulSoup(htmltext, "html.parser")
    body = bs.body
    data = body.find('div', {'code': '15d'})
    ul = data.find('ul')
    li = ul.find_all('li')
    for day in li:
        line = [city]
        span = day.find_all('span')
        date = span[0].string
        text = span[1].string
        if span[2].find('em') is None:
            temperature_H = None
        else:
            temperature_H = span[2].find('em').string
        temperature_L = span[2].string
        wind_direction = span[3].string
        wind_force = span[4].string
        line.append(date)
        line.append(text)
        line.append(temperature_H)
        line.append(temperature_L)
        line.append(wind_direction)
        line.append(wind_force)
        content.append(line)
    return content


def save_data(data, filename):
    with open(filename, 'a', errors='ignore', newline='') as f:
        f_csv = csv.writer(f)
        f_csv.writerows(data)


def _15d(city):
    url = get_15d_url(city)
    html = get_content(url)
    result = get_15d_data(html, city)
    save_data(result, 'D:/weather.xlsx')


if __name__ == '__main__':
    cities = input('city name: ').split(' ')
    for city in cities:
        _15d(city)