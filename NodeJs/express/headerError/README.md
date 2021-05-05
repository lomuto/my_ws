# Error: Can't set headers after they are sent.

```js
res.writeHead(200, { "Content-type": "text/html;charset=utf8" });
res.sendFile(`${__dirname}/public/${req.params.url}`);
```

이렇게 할 경우 `writeHead`에서 헤더를 한번, 그리고 이어서 `sendFile`에서 헤더를 한번 더 정의하게된다.

**`sendFile`할때는 헤더 또 정의해서 중복정의되는 문제 생기지 않게 하기.**
