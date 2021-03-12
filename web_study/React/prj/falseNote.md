# 오답노트   
   
`ReactDOM(<Foo/>,document.querySelector(`#root`));`   
JSX 는 무조건 대문자로 시작해야한다.   
      
---   
   


```js
function Potato({name}){    // Potato(prop)
    return(
        <h1>name in prop is { name }</h1>   // ~ prop is {prop.name} 
    );
}

function App(){
    return(
        <h1>This is App</h1>
        <Potato name="yun">
    );
}

export default App;
```   
   
`<Potato name="yun">` 처럼 **prop** 변수를 넘겨줄 수 있음   
위의 함수에서 `function Potato(prop)` 으로 prop 객체를 가져와 `<h1>name in prop is {prop.name}</h1>` 으로 참조 가능.   
   
prop 객체 안의 name 필드에 바로 접근하고 싶으면 인자를 `Potato({name})` 으로 bracket 으로 바로 접근 가능.   
인자로 받아온 필드값 호출 시 `<h1>name in prop is { name }</h1>` 으로 사용 가능.   
**같은 bracket 이지만 인자의 bracket과 innerHTML의 bracket은 다르게 사용됨**   
전자는 객체안의 필드를 접근을, 후자는 string literal 처럼 사용
   
Father(*App*) 가 child(*Potato*)에게 인자를 주는 방식이 **props**

---   
   
## Dynamic Props

```js
const data = [
  {"id":1,"name":"Calub"},
  {"id":2,"name":"Kane"},
  {"id":3,"name":"Jadon"},
  {"id":4,"name":"Ucab"}
]

function App() {
    return(
      <div>
        <h1>Ass</h1>
        {data.map(value=>{
          return <Potato key={value.id} name={value.name}/>
        })}
      </div>
    );
}
```   
   
map 함수를 통한 component 의 동적 생성.   
콜백함수의 리턴값이 react.element 형태임   
   
**prop 에 key 설정 안해주면 오류가나네?**   
객체의 배열에서 id 값을 prop.key 로 넣어주면 react 내부에서 좋아함


---
   


## PropType (nodejs의 Joi 같은거)   
   
```js
function Foo(prop){
    return(
        <div>
            <h1>{prop.name}</h1>
            <h1>{prop.rating}</h1>
        </div>
    );
}

Foo.propTypes={
    name:PropTypes.string.isRequired,
    rating:PropTypes.number
}
```   
   
nodejs 의 Joi 라이브러리처럼 `schema={ name: Joi.string().min(3).required() }`   
validation tool 이다   
   
`.string.isRequired` 이면 문자열이여야하고 무조건 있어야한다   
`.number` 이면 숫자여야하고 `isRequired` 이 없으므로 필수는 아니다   
   

---   
   

## Class Component   

가령   
```js
function App(){
    return(
        <h1>Hello</h1>
    );
}
...
ReactDOM.render(<App/>,document.getElementId(`root`))
```   
가 있다고 하자.   
   
```js
class App{
    render(){
        return(
            <h1>Hello</h1>
        )
    }
}
...
ReactDOM.render(<App/>,document.getElementId(`root`))
```   
   
이거도 동일하게 작동한다.   
`ReactDOM.render(<Foo/>,~);`   
에서 `Foo` 가 **Function Component 일 경우 함수를 실행하고** **Class Component 일 경우 render method를 실행한다**   
   

--- 
   


### `return <h1>hello</h1><h2>world</h2>` 는 왜 안될까요?   
   
위와 같은 syntax는 **JSX** 라는 JavaScriptXml 에서 지원하는 문법으로 리액트에서 유일하다.   
JSX 문법은 Babel이라는 TransCompiler를 통해서 Vanila js 문법으로 변환되어진다.   
   
```js
const element = <h1>Hello World!</h1>
```   
는 Babel을 통해 다음과 같이 변환된다   
```js
React.createElement(`h1`,null,"Hello World!");
```   
가운데 null이 뭔지는 모르지만 중요한거는 첫번째 인자가 `h1` 으로 객체가 아닌 독립적인 문자열로 받는거로 보아서 **한번에 하나의 DOM element를 받는걸 유추할 수 있다.**   
   
그래서 여려개의 dom element를 넘겨주고 싶다면
```jsx
return (
    <div>
        <h1>Hello</h1>
        <h2>world</h2>
    </div>
    );
```   
이렇게 해주면 된다.   
   
참고로 JS 안에서 제공되는 ASI (Auto Semicolon Insertion) 의 경우 `return` 다음에오는 JSX 문법을 인지하지 못한다. 그래서 `return (~~JSX~~);` 이렇게 return expression을 parenthesis로 감싸준다.