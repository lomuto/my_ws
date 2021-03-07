# Call stack and Task Queue with Event loop

## **Event loop won't run untill call stack is empty!**

</br>

```js
console.log("Starting");

setTimeout(() => {
  console.log("Hello 2000");
}, 2000);

setTimeout(() => {
  console.log("Hello 0");
}, 0);

console.log("Stopped");
```

</br>

Assume logically, output of console must be print `Starting` first  
and print `Hello 2000` after 2 sec  
and `Hello 0` right away  
`Stopped` at last.

But the result is....

</br>

```js
// result

$ Starting
$ Stopped
$ Hello 0
$ Hello 2000
```

How become every step is tangled?

</br>

As `setTimeout` is not supported in javascript, it runs in `V8`, `spider monkey` like **web api** or **Node api**.

Javascript is single threaded language so sequence of those `console.log` and `setTimeout` function pushed in call stack is same as those are written in code.

While normal function is executed in javascript right away, such `setTimeout` function will move to node or web api to be executed.  
After two `setTimeout` moved to apis, it executed and time reduces. `setTimeout` with given parameter `0` will end faster than given parameter `2000` so **result of function in formal one goes to task queue first, eventhough latter one in apis executed faster**

```
`TASK QUEUE`  (head) | console.log("Hello 0") | console.log("Hello 2000") | (tail)
```

Atfer some task queued to `task-queue`, `event-loop` moves them to `call-stack`. And as I mentioned before, **Event loop won't run untill call stack is empty.**  
_And `Render-Queue` keep tracking of whether `stack-queue` is empty or not_

So after executing `console.log("Starting")` and `console.log("Stopped")`, tasks in `task-queue` dequeued in sequence starting from head.

That's why output is

```js
$ Starting      // comes out of call-stack right away
$ Stopped       // comes out of call-stack right away after "Starting"
$ Hello 0       // Moved to apis after "Hello 2000" but finished and moved to task-queue faster than that.
$ Hello 2000
```
