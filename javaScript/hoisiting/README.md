### Conceptually,  it moves a ***declartion*** of  and variable with `var` keyword  and `function` to top of the scope

```jsx
{
	console.log(a) // undefined.   variable `a` is in memory but not initialized

	var a = 3;
}

{
	console.log(a) // error

	const a = 3;   // same for `let a = 3;` 
}
```

---

```jsx
{
	a();   // Hello. 

	function a(){   // Declare of function includes initialization.
		console.log(`Hello`);
	}
}

{
	a();   // Error

		/*
		 * undefined var `a` will be hoistied,
		 * while function statement is declaration of variable `a`
		*/
		var a = ()=>{  
		console.log(`Hello`);
	}
}
```
