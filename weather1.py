# -*- coding: utf-8 -*-

import urllib
import json

# データを web から取ってくる
src = 'http://weather.livedoor.com/forecast/webservice/json/v1?city=400040'
f = urllib.urlopen(src)
str = f.read()
f.close()

# JSON レコードの解析
q = json.loads(str)

# とりあえず採ってきたデータのタイトルを表示
print q['title']
