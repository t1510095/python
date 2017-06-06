# -*- coding: utf-8 -*-

f = open('fread1.py', 'r')    # f = open('README.md', 'r') なども試す
data1 = f.read()              # ファイル全部を1つの文字列に読み込む
f.close()

print data1
