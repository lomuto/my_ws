type NODE_t = any;

class NODE{
    public value: NODE_t;
    public next: NODE;
    public prev: NODE;

    static firstNode: NODE = null;
    static lastNode: NODE = null;

    constructor(value: NODE_t){
        this.value = value;

        if(!NODE.firstNode){
            NODE.firstNode = this;
            NODE.lastNode = this;

            this.prev = null;
            this.next = null;
            return;
        }
        else{
            let NODEptr: NODE = NODE.firstNode;
            for( ; NODEptr.next ; NODEptr = NODEptr.next)
                ;
            
            NODE.lastNode = this;
            this.prev = NODEptr;
            this.next = null;
            NODEptr.next = this;
        }
    }

    static ADD = (value: NODE_t): NODE => {
        return new NODE(value);
    }

    static SEARCH = (value:NODE_t): NODE => {
        for(let NODEptr = NODE.firstNode ; NODEptr ; NODEptr = NODEptr.next)
            if(NODEptr.value === value)
                return NODEptr;

        return null;
    }

    static DELETE = (value: NODE_t, nthOfNode?: number): boolean => {
        if(nthOfNode){
            for(let NODEptr = NODE.firstNode, count = 1 ; NODEptr ; NODEptr = NODEptr.next, count++){
                if(count === nthOfNode){
                    if(value !== NODEptr.value){
                        console.log(`Inconsistent nthOfNODE and value`)
                        return false;
                    }
                    else{
                        if(NODEptr === NODE.firstNode){
                            NODE.firstNode = NODEptr.next;

                            NODEptr.next.prev = null;
                        }
                        else if(NODEptr === NODE.lastNode){
                            NODE.lastNode = NODEptr.prev;
                            NODEptr.prev.next = null;
                        }
                        else{
                            NODEptr.next.prev = NODEptr.prev;
                            NODEptr.prev.next = NODEptr.next;
                        }

                        //dealloc
                        NODEptr = null;
                        return true; 
                    }
                }
            }
            console.log(`nth of NODE is out of range`)
        }
        else{
            for(let NODEptr = NODE.firstNode ; NODEptr ; NODEptr = NODEptr.next){
                if(value === NODEptr.value){
                    NODEptr.next.prev = NODEptr.prev;
                    NODEptr.prev.next = NODEptr.next;
                    NODEptr = null;
                    return true; 
                }
            }
            console.log(`Node of given value doesn't exist`)
            return false;
        }
    }

    static TRAVERSE = (): void => {
        for(let NODEptr = NODE.firstNode ; NODEptr ; NODEptr = NODEptr.next)
            process.stdout.write(`${NODEptr.value} <-> `);
        console.log(``);
    }

    static rTRAVERSE = (): void => {
        for(let NODEptr = NODE.lastNode ; NODEptr ; NODEptr = NODEptr.prev)
            process.stdout.write(`${NODEptr.value} <-> `);
        console.log(``);
    }
}

NODE.ADD(12);

const node = new NODE(1);

NODE.ADD(2);
NODE.ADD(3);
NODE.ADD(4);

NODE.TRAVERSE();

NODE.rTRAVERSE();

console.log(NODE.firstNode);
console.log(NODE.lastNode);

console.log(NODE.SEARCH(3));