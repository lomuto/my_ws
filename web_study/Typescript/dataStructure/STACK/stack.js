var STACK = /** @class */ (function () {
    //   set STACK_PTR(value:STACK_TYPE){
    //   }
    function STACK(size) {
        var _this = this;
        this.isEmpty = function () {
            return _this._STACK_PTR < 0 ? true : false;
        };
        this.isFull = function () {
            return _this._STACK_PTR >= _this.STACK_SIZE - 1 ? true : false;
        };
        this.PUSH = function (value) {
            if (_this.isFull()) {
                alert("STACK OVERFLOW");
                return false;
            }
            else {
                _this.stack[++_this._STACK_PTR] = value;
                return true;
            }
        };
        this.POP = function () {
            if (_this.isEmpty()) {
                alert("STACK UNDERFLOW");
                return false;
            }
            else {
                _this.stack[_this._STACK_PTR--];
                return true;
            }
        };
        this.PEEK = function () {
            return _this.stack[_this._STACK_PTR];
        };
        this.STACK_SIZE = size;
        this._STACK_PTR = -1;
        this.stack = [];
    }
    Object.defineProperty(STACK.prototype, "STACK_PTR", {
        /*
        get and set accessor must have the same type ERROR occured
        must set the get's return type and set's param as SAME TYPE
        */
        get: function () {
            return this._STACK_PTR;
        },
        enumerable: false,
        configurable: true
    });
    return STACK;
}());
///////////////////////////////////////////////////////
var sizeBtn = document.querySelector("#size-btn");
var stack = document.querySelector("#stack");
var pushBtn = document.querySelector("#push-btn");
var pushValue = document.querySelector("#value");
var popBtn = document.querySelector("#pop-btn");
var stk;
window.onload = function () {
    document.querySelector("#stack-size").focus();
};
document.addEventListener("keydown", function (e) {
    if (e.key === "Enter") { // e.keyCode deprecated. e.key Recommended
        if (document.activeElement === document.querySelector("#stack-size"))
            sizeBtn.click();
        else
            pushBtn.click();
    }
    if (e.key === "Escape") {
        popBtn.click();
    }
});
function fadeIn(el, visibility, sec) {
    el.style.visibility = visibility;
    el.style.opacity = "0";
    var weight = 0.02 / sec;
    (function fade() {
        var val = parseFloat(el.style.opacity);
        if (!((val += weight) > 1)) {
            el.style.opacity = "" + val;
            requestAnimationFrame(fade);
        }
    })();
}
;
sizeBtn.onclick = function () {
    var size = parseInt(document.querySelector("#stack-size").value) * 30;
    stk = new STACK(size / 30);
    stack.style.height = size + "px";
    fadeIn(stack, "visible", 2);
    document.querySelector("#set-size").remove();
    // (<HTMLElement>document.querySelector(`#modify`)).style.visibility = `visible`;
    fadeIn(document.querySelector("#modify"), "visible", 1);
    pushValue.focus();
};
pushBtn.onclick = function () {
    var newVal = pushValue.value;
    if (!stk.PUSH(parseInt(newVal))) {
        pushValue.value = "";
        return;
    }
    var newEl = document.createElement("div");
    newEl.innerHTML = newVal;
    newEl.className = "element";
    stack.appendChild(newEl);
    pushValue.value = "";
};
popBtn.onclick = function () {
    if (!stk.POP()) {
        return;
    }
    stack.removeChild(stack.childNodes[stk.STACK_PTR + 2]);
};
