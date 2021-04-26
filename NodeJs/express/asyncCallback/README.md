# 라우팅 콜백 함수에 async지정

```js
app.get(`/:url`, async (req, res) => {
  // async in callback
  await SEARCH(__dirname, req.params.url)
    .then((is_exist) => {
      if (is_exist) {
        res.writeHead(200, { "Content-type": "text/html;charset=utf8" });
        res.sendFile(`${__dirname}/${req.params.url}`);
      } else {
        res.writeHead(404);
        res.end("<h1>404 Not Found<h1>");
      }
    })
    .catch(console.log);
});
```

promise 객체를 return 하는 SEARCH 함수는 해당 디렉토리에 두번째 인자값으로 들어온 파일이 디렉토리에 존재하는지 알려주는 함수이다.  
해당 디렉토리 search 하는게 시간이 걸릴수도 있어서 promise를 써야 하는데 await때문에 고민하다가 콜백에 async 넣어봤는데 된다.  
콜백함수도 함수니까 될법한데 그냥 신기해서 적어봄
