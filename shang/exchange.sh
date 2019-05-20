./bigbang -daemon

# 导入挖矿私钥和模板
./bigbang importprivkey 8102db22dcc095d4d685613ca89a5d938e2de39954b5aa46f975ded23d9c9d69 123456
5a8c3b6c9c82508f47084f3d2b55ed29ffbf3ab4f5709f9fca2e6052ac191de2
./bigbang unlockkey 5a8c3b6c9c82508f47084f3d2b55ed29ffbf3ab4f5709f9fca2e6052ac191de2 123456

./bigbang getpubkeyaddress 5a8c3b6c9c82508f47084f3d2b55ed29ffbf3ab4f5709f9fca2e6052ac191de2
1w8ehkb2jc0qcn7wze3tv8enzzwmytn9b7n7gghwfa219rv1vhhd82n6h

./bigbang addnewtemplate mint "{\"mint\":\"5a8c3b6c9c82508f47084f3d2b55ed29ffbf3ab4f5709f9fca2e6052ac191de2\",\"spent\":\"1w8ehkb2jc0qcn7wze3tv8enzzwmytn9b7n7gghwfa219rv1vhhd82n6h\"}"
20g02cqqm3hq4txc78b5taeh8x4g88f3vg7t13g2zq232yfz340p0vzh8
 
 # 开始挖矿
./bigbang miner 1w8ehkb2jc0qcn7wze3tv8enzzwmytn9b7n7gghwfa219rv1vhhd82n6h 8102db22dcc095d4d685613ca89a5d938e2de39954b5aa46f975ded23d9c9d69


# 导入交换私钥
./bigbang importprivkey 27ee1dce5fe525a38ffb3ee1515206451fde7443e422cc9a26ae0d65766eb608 123456
8656f962ae73724ea2234e6aa5ea38d059b1e702c8d6d6fcfbdde2cda66d39e4

./bigbang importprivkey 1f6c18ed562d9585de0a43cdefc551bdd1b82878cbb11c3b91209d0eff985b73 123456
abe946e6cc8f250d744936c04cf35730b8107937abd9ec5f721b1c94c34d8952

./bigbang unlockkey 8656f962ae73724ea2234e6aa5ea38d059b1e702c8d6d6fcfbdde2cda66d39e4 123456
./bigbang unlockkey abe946e6cc8f250d744936c04cf35730b8107937abd9ec5f721b1c94c34d8952 123456


./bigbang getpubkeyaddress 8656f962ae73724ea2234e6aa5ea38d059b1e702c8d6d6fcfbdde2cda66d39e4
1wgwpv9pdwbezqz6ptv405sxhb783htn5d97278jee9stwrqsat385v1y

./bigbang getpubkeyaddress abe946e6cc8f250d744936c04cf35730b8107937abd9ec5f721b1c94c34d8952
1aa4mvgwm3gdq4qzcv6nkey8gq0r5fwtcr0v4jx0d4p7wssj6x6nhj7kw

./bigbang addnewtemplate exchange "{\"addr_m\":\"1wgwpv9pdwbezqz6ptv405sxhb783htn5d97278jee9stwrqsat385v1y\",\"addr_s\":\"1aa4mvgwm3gdq4qzcv6nkey8gq0r5fwtcr0v4jx0d4p7wssj6x6nhj7kw\",\"height_m\":15,\"height_s\":20,\"fork_m\":\"92099485ffec67128fe4dbaca96ed8faf54ccc0b4760cd0d78a3d1e051a2498f\",\"fork_s\":\"92099485ffec67128fe4dbaca96ed8faf54ccc0b4760cd0d78a3d1e051a2498f\"}"
20r0b955f95etvs3we2xe8vr74445cdq90w1z2wfaxd4byfvyzq4fayxh


./bigbang sendfrom 20g02cqqm3hq4txc78b5taeh8x4g88f3vg7t13g2zq232yfz340p0vzh8 20r0b955f95etvs3we2xe8vr74445cdq90w1z2wfaxd4byfvyzq4fayxh 10 1 -f="92099485ffec67128fe4dbaca96ed8faf54ccc0b4760cd0d78a3d1e051a2498f"
5ce1fdb0112ec5468797065f25a89c990d2b75245aa2efc4d34653555e4a4a68
./bigbang stop
# 转账完成，备份数据状态

./bigbang -daemon

./bigbang validateaddress 20r0b955f95etvs3we2xe8vr74445cdq90w1z2wfaxd4byfvyzq4fayxh


# 主签名 -a 表示是对地址的签名
./bigbang signmessage 8656f962ae73724ea2234e6aa5ea38d059b1e702c8d6d6fcfbdde2cda66d39e4 20r0b955f95etvs3we2xe8vr74445cdq90w1z2wfaxd4byfvyzq4fayxh -a
a44fa49767de1582138d190d60ea0ebdc1453d4f54b261121140c75e10b70a2d3818d42915114bd56a997b67446631118597efe01d8e23c91f05a47cf8513e0d
# 从签名 -a 表示是对地址的签名
./bigbang signmessage abe946e6cc8f250d744936c04cf35730b8107937abd9ec5f721b1c94c34d8952 20r0b955f95etvs3we2xe8vr74445cdq90w1z2wfaxd4byfvyzq4fayxh -a
95c481bcf3ebb4323fd0cf9249918e77fe6c560ae8adb6cb099f626d6a4ffdf890882d4d20a86b02709b3d2943b83939fd6288c8249f0da5743444c45f47b80e

# 验证签名 -a 表示是对地址的签名
./bigbang verifymessage 8656f962ae73724ea2234e6aa5ea38d059b1e702c8d6d6fcfbdde2cda66d39e4 20r0b955f95etvs3we2xe8vr74445cdq90w1z2wfaxd4byfvyzq4fayxh a44fa49767de1582138d190d60ea0ebdc1453d4f54b261121140c75e10b70a2d3818d42915114bd56a997b67446631118597efe01d8e23c91f05a47cf8513e0d -a

# 从模板转账
./bigbang unlockkey abe946e6cc8f250d744936c04cf35730b8107937abd9ec5f721b1c94c34d8952 123456
./bigbang sendfrom 20r0b955f95etvs3we2xe8vr74445cdq90w1z2wfaxd4byfvyzq4fayxh 1wgwpv9pdwbezqz6ptv405sxhb783htn5d97278jee9stwrqsat385v1y 9 1 -sm="a44fa49767de1582138d190d60ea0ebdc1453d4f54b261121140c75e10b70a2d3818d42915114bd56a997b67446631118597efe01d8e23c91f05a47cf8513e0d" -ss="95c481bcf3ebb4323fd0cf9249918e77fe6c560ae8adb6cb099f626d6a4ffdf890882d4d20a86b02709b3d2943b83939fd6288c8249f0da5743444c45f47b80e" -f="92099485ffec67128fe4dbaca96ed8faf54ccc0b4760cd0d78a3d1e051a2498f"

# 查看交易
./bigbang gettransaction 5ce240cb0ca9d680e9aa5765f204d0f0f7ea09916aa59465526015fc32424362
{
    "transaction" : {
        "txid" : "5ce240cb0ca9d680e9aa5765f204d0f0f7ea09916aa59465526015fc32424362",
        "version" : 1,
        "type" : "token",
        "time" : 1558331595,
        "lockuntil" : 0,
        "anchor" : "73fa97ac47ba9f4a3e1d7536f14d770e14962ec0c38ab18ab2ad8ebc657d9e0f",
        "vin" : [
            {
                "txid" : "5ce1fdb0112ec5468797065f25a89c990d2b75245aa2efc4d34653555e4a4a68",
                "vout" : 0
            }
        ],
        "sendto" : "1wgwpv9pdwbezqz6ptv405sxhb783htn5d97278jee9stwrqsat385v1y",
        "amount" : 9.000000,
        "txfee" : 1.000000,
        "data" : "",
        "sig" : "01e4396da6cde2ddfbfcd6d6c802e7b159d038eaa56a4e23a24e7273ae62f956860152894dc3941c1b725fecd9ab377910b83057f34cc03649740d258fcce646e9ab0f000000140000008f49a251e0d1a3780dcd60470bcc4cf5fad86ea9acdbe48f1267ecff859409928f49a251e0d1a3780dcd60470bcc4cf5fad86ea9acdbe48f1267ecff8594099240000000a44fa49767de1582138d190d60ea0ebdc1453d4f54b261121140c75e10b70a2d3818d42915114bd56a997b67446631118597efe01d8e23c91f05a47cf8513e0d4000000095c481bcf3ebb4323fd0cf9249918e77fe6c560ae8adb6cb099f626d6a4ffdf890882d4d20a86b02709b3d2943b83939fd6288c8249f0da5743444c45f47b80e4000000087fb5f20ab4213f23baa0ca5529fdf0b2f75eeeff82ed178332e53040e954f9b017c4e6525198ccd026e853485690875af4952a005d7b4d7de3288af51390a05",
        "fork" : "92099485ffec67128fe4dbaca96ed8faf54ccc0b4760cd0d78a3d1e051a2498f",
        "confirmations" : 0
    }
}

# 正常转账
./bigbang sendfrom 1wgwpv9pdwbezqz6ptv405sxhb783htn5d97278jee9stwrqsat385v1y 1aa4mvgwm3gdq4qzcv6nkey8gq0r5fwtcr0v4jx0d4p7wssj6x6nhj7kw 8 1 -f="92099485ffec67128fe4dbaca96ed8faf54ccc0b4760cd0d78a3d1e051a2498f"
5ce24188fa9296b8e02664530013f937736bc019158d7c333b0ed569ba97a721

# 查看正常转账
./bigbang gettransaction 5ce24188fa9296b8e02664530013f937736bc019158d7c333b0ed569ba97a721
{
    "transaction" : {
        "txid" : "5ce24188fa9296b8e02664530013f937736bc019158d7c333b0ed569ba97a721",
        "version" : 1,
        "type" : "token",
        "time" : 1558331784,
        "lockuntil" : 0,
        "anchor" : "f739c45a67bff48175d76752d9781d10f11987c40bbb4ba26cb946a15b31abf3",
        "vin" : [
            {
                "txid" : "5ce240cb0ca9d680e9aa5765f204d0f0f7ea09916aa59465526015fc32424362",
                "vout" : 0
            }
        ],
        "sendto" : "1aa4mvgwm3gdq4qzcv6nkey8gq0r5fwtcr0v4jx0d4p7wssj6x6nhj7kw",
        "amount" : 8.000000,
        "txfee" : 1.000000,
        "data" : "",
        "sig" : "2c07c65c173f1bb79fad11ac50bb471794f2edd36ec765c5e31841b430c0cc6034dd9be2e2896bcec290d3274a16757c5e5cf7d98f5c663829f8e27e158c1b0e",
        "fork" : "92099485ffec67128fe4dbaca96ed8faf54ccc0b4760cd0d78a3d1e051a2498f",
        "confirmations" : 0
    }
}
