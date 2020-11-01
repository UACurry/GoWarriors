import urllib.request
import urllib.parse
import json
import time
import tkinter
import tkinter.messagebox


win = tkinter.Tk()
win.title('欢迎来到无道翻译软件')
win.geometry('400x300') 
cv = tkinter.Canvas(win, bg='red', width=300, height=300)
label1 = tkinter.Label(win, text='请输入需要翻译的内容:')
label1.grid(row=2,column=0,sticky='w')

text = tkinter.Entry(win, width=20)
text.grid(row=2,column=1,sticky='w')

 
url = 'http://fanyi.youdao.com/translate?smartresult=dict&smartresult=rule'

head = {}
head['User-Agent'] = 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/78.0.3904.108 Safari/537.36'

data = {}
data['i'] =  text
data['from'] = 'AUTO'
data['to'] = 'AUTO'
data['smartresult'] = 'dict'
data['client'] = 'fanyideskweb'
data['salt'] =  '15742526380178'
data['sign'] = 'aa9f7d3e26d3cb8473a4441b7c43a685'
data['ts']= '1574252638017'
data['bv'] =  'bc250de095a39eeec212da07435b6924'
data['doctype'] = 'json'
data['version'] = '2.1'
data['keyfrom'] =  'fanyi.web'
data['action'] =  'FY_BY_CLICKBUTTION'
data = urllib.parse.urlencode(data).encode('UTF-8')


response = urllib.request.urlopen(url,data)
html = response.read().decode('utf-8')

target = json.loads(html)


def make():
    tkinter.messagebox.showinfo('结果','翻译结果:'+(target['translateResult'][0][0]['tgt']))

button2 = tkinter.Button(win,command = make ,text='确定',width=10,bg='Blue')
button2.grid(row=2,column=2,sticky='s',padx=8, pady=8)



win.mainloop() 