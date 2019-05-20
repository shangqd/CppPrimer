#!/usr/bin/env python
# -*- coding: utf-8 -*-

import pymysql
 
conn = pymysql.connect(host="127.0.0.1",port=13307,user="root",database="bigbang",charset="utf8")
cursor = conn.cursor()

import os  
import json
import sys
def insert(sql):
        #sql = "insert into tx(bn)values(11)"
        cursor.execute(sql)
        conn.commit()
print "OK"
fork = " -f=92099485ffec67128fe4dbaca96ed8faf54ccc0b4760cd0d78a3d1e051a2498f"
fork = " -f=b9bb2f2e62fefdcc44a269a2743714b17a87daa5b28b32c7579e210ba137980f"
fork = " -f=d2df3ecc7ee78eae594731e54944c72aa600e662700cfe52aec3304a5188cf97"

#sys.exit()
c = os.popen("bigbang getblockcount" + fork).read()
c = int(c)
for n in range(c):
    print n
    cmd = "bigbang getblockhash " + str(n) + fork
    json_str = os.popen(cmd).read()
    cmd = "bigbang getblock " + json.loads(json_str)[0]
    json_str = os.popen(cmd).read()
    obj = json.loads(json_str)
    sql = "insert into block(bn,hash,type,fork)values(%s,'%s','%s','%s')" % (n,obj["hash"],obj["type"],fork)
    #print sql
    insert(sql)
    continue
    
    for tx in json.loads(json_str)["tx"]:
        cmd = "bigbang gettransaction " + tx
        obj = json.loads(os.popen(cmd).read())
        txid = obj["transaction"]["txid"]
        type_ = obj["transaction"]["type"]
        sendto = obj["transaction"]["sendto"]
        amount = obj["transaction"]["amount"]

        if len(obj["transaction"]["vin"]) == 1:
                #print n, obj["transaction"]["txid"],obj["transaction"]["type"],obj["transaction"]["amount"],obj["transaction"]["sendto"],obj["transaction"]["vin"][0]["txid"],obj["transaction"]["vin"][0]["vout"]
                vin_txid = obj["transaction"]["vin"][0]["txid"]
                vin_vout = obj["transaction"]["vin"][0]["vout"]
                sql = "insert into tx(bn,txid,type,sendto,amount,fork,vin_txid,vin_vout)values(%s,'%s','%s','%s',%s,'%s','%s',%s);" % (n,txid,type_,sendto,amount,fork,vin_txid,vin_vout)
                insert(sql)
                #print sql
        else:
                sql = "insert into tx(bn,txid,type,sendto,amount,fork)values(%s,'%s','%s','%s',%s,'%s');" % (n,txid,type_,sendto,amount,fork)
                insert(sql)
                #print sql
        #os.system(cmd)

cursor.close()
conn.close()
sys.exit()
json_str = os.popen('bigbang listfork').read()

fs = json.loads(json_str)

for f in fs:
    cmd = "bigbang getblockcount -f=" + f['fork']
    os.system(cmd)



