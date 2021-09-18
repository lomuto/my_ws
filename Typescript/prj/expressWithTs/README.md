# express + TS

## package.json

```json
{
  ...
  "devDependencies": {
    "@types/express": "^4.17.13",
    "@types/node": "^16.9.2",
    "nodemon": "^2.0.12"
  }
}

```

배포 시 dist 만 올라갈꺼니까 `@types/express`,`@types/node` 는 `npm i --save-dev`로 추가.

## tsconfig.json

`tsc --init` 으로 tsconfig 생성

```json
    "moduleResolution": "Node",
    "outDir": "./dist",
    "rootDir": "./src",
```

`moduleResolution` 이랑 src, dist 폴더 분리하기 위해서 `outDir`, `rootDir` 정도만 추가해주자.
