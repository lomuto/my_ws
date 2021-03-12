type STACK_TYPE = any ;

class STACK{
  private STACK_SIZE: number;
  private _STACK_PTR: number;

  public stack: STACK_TYPE[];

  /*
  get and set accessor must have the same type ERROR occured
  must set the get's return type and set's param as SAME TYPE
  */

  get STACK_PTR():STACK_TYPE{
    return this._STACK_PTR;
  }
//   set STACK_PTR(value:STACK_TYPE){

//   }

  constructor(size: number){
    this.STACK_SIZE = size;
    this._STACK_PTR = -1;
    this.stack = [];
  }

  public isEmpty = ():boolean => {
    return this._STACK_PTR < 0 ? true : false ;
  }

  public isFull = ():boolean => {
    return this._STACK_PTR >= this.STACK_SIZE-1 ? true : false ;
  }

  public PUSH = (value: STACK_TYPE):boolean=>{
    if(this.isFull()){
      alert(`STACK OVERFLOW`);
      return false;
    }
    else{
      this.stack[++this._STACK_PTR] = value;
      return true;
    }
  }

  public POP = ():boolean=>{
    if(this.isEmpty()){
      alert(`STACK UNDERFLOW`);
      return false;
    }
    else{
      this.stack[this._STACK_PTR--];
      return true;
    }
  }

  public PEEK = ():STACK_TYPE => {
    return this.stack[this._STACK_PTR];
  }
}

///////////////////////////////////////////////////////

const sizeBtn: HTMLElement = document.querySelector(`#size-btn`);
const stack: HTMLElement = document.querySelector(`#stack`);
const pushBtn: HTMLElement = document.querySelector(`#push-btn`);
const pushValue: HTMLElement = document.querySelector(`#value`);
const popBtn: HTMLElement = document.querySelector(`#pop-btn`);

let stk: STACK;

window.onload = ()=>{
  (<HTMLInputElement>document.querySelector(`#stack-size`)).focus();
}

document.addEventListener(`keydown`,(e)=>{
  if(e.key === `Enter`){      // e.keyCode deprecated. e.key Recommended
    if(document.activeElement === document.querySelector(`#stack-size`))
      sizeBtn.click();
    else
      pushBtn.click();
  }
  if(e.key === `Escape`){
    popBtn.click();
  }
});

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

sizeBtn.onclick = ()=>{
  const size: number = parseInt((<HTMLInputElement>document.querySelector(`#stack-size`)).value)*30;
  stk = new STACK(size/30);
  stack.style.height = `${size}px`;
  fadeIn(stack,`visible`,2);

  document.querySelector(`#set-size`).remove();
  // (<HTMLElement>document.querySelector(`#modify`)).style.visibility = `visible`;
  fadeIn(document.querySelector(`#modify`),`visible`,1);

  pushValue.focus();
}

pushBtn.onclick = ()=>{
  const newVal = (<HTMLInputElement>pushValue).value;
  if(!stk.PUSH(parseInt(newVal))){
    (<HTMLInputElement>pushValue).value = ``;
    return;
  }

  const newEl = document.createElement(`div`);
  newEl.innerHTML = newVal;
  newEl.className = "element";

  stack.appendChild(newEl);

  (<HTMLInputElement>pushValue).value = ``;
}

popBtn.onclick = ()=>{
  if(!stk.POP()){
    return;
  }
  
  stack.removeChild(stack.childNodes[stk.STACK_PTR+2]);
}