# callBack hell to heaven

```javascript
USER.checkInfo(
  ID,
  PWD,
  (userId) => {
    USER.getRoles(userId, (ret) => {
      alert(`Hello ${ret.name}, you are ${ret.role}`);
      console.log(`${ret.role} logged in`);
    });
  },
  alert
);
```

to

```javascript
USER.checkInfo(ID, PWD)
  .then((userId) => {
    USER.getRoles(userId) //
      .then((userRole) => {
        alert(`Hello ${userRole.name} you are ${userRole.role}`);
      })
      .catch((userRole) => {
        alert(`Hello ${userRole.name} you are ${userRole.role}`);
      });
  })
  .catch((error) => alert(error));
```
