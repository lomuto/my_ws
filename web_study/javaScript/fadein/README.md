# fadein function   
   
```ts
function fadeIn(el:HTMLElement, visibility: string, sec: number) {
  el.style.visibility = visibility;
  el.style.opacity = `0`;
  const weight: number = 0.02/sec;
  (function fade() {
      let val = parseFloat(el.style.opacity);
      if (!((val += weight) > 1)) {
          el.style.opacity = `${val}`;
          requestAnimationFrame(fade);
      }
  })();
};
```
