let request = require('request');
for (let i = 0; i < 1000; i++) {
  request.post({
    url: 'http://127.0.0.1:9902',
    body: {
      id: '4',
      'method':'listunspent',
      'jsonrpc':'2.0',
      'params':{
        'address':'1ek5grn6matf086wtt111b2n3ttq0ewfj0vr535xqrvaakma5exrvqdha'}
    },
    json: true}, (err, res, body) => {
    console.log(body)
  })
}