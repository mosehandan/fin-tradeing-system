###使用pytdx获取行业、概念、板块和地域信息


初步框架：
APscheduler作为计时器，定时（交易日）按照固定时间间隔（TICK或者分钟）进行数据的获取。
1. AP ----> 获取实时价格 ----> zmq ----> Redis ----> zmq ----> mysql(永久化)
2. mysql  ----> zmq(待定) ----> push_data ----> web展示或者报告

File_lists:
ap.py
stock_list ----> fun get_price()
TODO 字段 datetime设置
redis 构建
mysql 构建

