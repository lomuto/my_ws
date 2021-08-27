# Singleton in typescript

Singleton is one of well-known design pattern.  
To implement singleton in typescript...

```ts
class SingleTon {
  private static instance: SingleTon | null = null;

  private constructor() {}

  public static getInstance() {
    if (SingleTon.instance === undefined) {
      SingleTon.instance = new SingleTon();
    }
    return SingleTon.instance;
  }
}
```

If static property has not been initialized yet, its value is `undefined`
