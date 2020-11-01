import easyquotation

quotation = easyquotation.use('sina')  # 新浪 ['sina'] 腾讯 ['tencent', 'qq']
code = input('请输入股票代码:')
#print(quotation.real(code))
paras_Chin = [
    '股票名', '开盘价', '昨日收盘价', '现价', '今日最高价', '今日最低价', '竞买价', '竞卖价', '成交额', '交易额',
    '买一价', '买一量', '买一量', '卖一量', '日期', '时间'
]
paras_Eng = [
    'name', 'open', 'close', 'now', 'high', 'low', 'buy', 'sell', 'turnover',
    'volume', 'bid1', 'bid1_volume', 'ask1', 'ask1_volume', 'date', 'time'
]
print('股票代号:', end='')
print(code)

for i, j in zip(paras_Chin, paras_Eng):
    print(i, ':', end='')
    print(quotation.real(code)[code][j])

# print('股票名:', end='')
# print(quotation.real(code)[code]['name'])
# print('开盘价:', end='')
# print(quotation.real(code)[code]['open'])
# print('昨日收盘价:', end='')
# print(quotation.real(code)[code]['close'])
# print('现价:', end='')
# print(quotation.real(code)[code]['now'])
# print('今日最高价:', end='')
# print(quotation.real(code)[code]['high'])
# print('今日最低价:', end='')
# print(quotation.real(code)[code]['low'])
# print('竞买价:', end='')
# print(quotation.real(code)[code]['buy'])
# print('竞卖价:', end='')
# print(quotation.real(code)[code]['sell'])
# print('成交额:', end='')
# print(quotation.real(code)[code]['turnover'])
# print('交易额:', end='')
# print(quotation.real(code)[code]['volume'])
# print('买一价:', end='')
# print(quotation.real(code)[code]['bid1'])
# print('买一量:', end='')
# print(quotation.real(code)[code]['bid1_volume'])
# print('卖一价:', end='')
# print(quotation.real(code)[code]['ask1'])
# print('卖一量:', end='')
# print(quotation.real(code)[code]['ask1_volume'])
# print('日期:', end='')
# print(quotation.real(code)[code]['date'])
# print('时间:', end='')
# print(quotation.real(code)[code]['time'])