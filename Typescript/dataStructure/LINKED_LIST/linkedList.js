class NODE {
    constructor(value) {
        this.value = value;
        if (!NODE.genesisNode) {
            NODE.genesisNode = this;
            this.prev = null;
            this.next = null;
        }
        else {
            let NODEptr = NODE.genesisNode;
            for (; NODEptr.next; NODEptr = NODEptr.next)
                ;
            this.prev = NODEptr;
            NODEptr.next = this;
            this.next = null;
        }
    }
}
NODE.genesisNode = null;
NODE.ADD = (value) => {
    const newNode = new NODE(value);
    if (!NODE.genesisNode) {
        NODE.genesisNode = newNode;
        newNode.prev = null;
        newNode.next = null;
        return;
    }
    let NODEptr = NODE.genesisNode;
    for (; NODEptr.next; NODEptr = NODEptr.next)
        ;
    newNode.prev = NODEptr;
    NODEptr.next = newNode;
    newNode.next = null;
};
NODE.SEARCH = (value) => {
    for (let NODEptr = NODE.genesisNode; NODEptr; NODEptr = NODEptr.next)
        if (NODEptr.value === value)
            return NODEptr;
    return null;
};
NODE.DELETE = (value, nthOfNode) => {
    if (nthOfNode) {
        for (let NODEptr = NODE.genesisNode, count = 1; NODEptr; NODEptr = NODEptr.next, count++) {
            if (count === nthOfNode) {
                if (value !== NODEptr.value) {
                    console.log(`Inconsistent nthOfNODE and value`);
                    return false;
                }
                else {
                    NODEptr.next.prev = NODEptr.prev;
                    NODEptr.prev.next = NODEptr.next;
                    NODEptr = null;
                    return true;
                }
            }
        }
        console.log(`nth of NODE is out of range`);
    }
    else {
        for (let NODEptr = NODE.genesisNode; NODEptr; NODEptr = NODEptr.next) {
            if (value === NODEptr.value) {
                NODEptr.next.prev = NODEptr.prev;
                NODEptr.prev.next = NODEptr.next;
                NODEptr = null;
                return true;
            }
        }
        console.log(`Node of given value doesn't exist`);
        return false;
    }
};
NODE.TRAVERSE = () => {
    process.stdout.write(`null -> `);
    for (let NODEptr = NODE.genesisNode; NODEptr; NODEptr = NODEptr.next)
        process.stdout.write(`${NODEptr.value} -> `);
    process.stdout.write(`null`);
};
// NODE.ADD(12);
// const node = new NODE(1);
// NODE.ADD(2);
// NODE.ADD(3);
// NODE.ADD(4);
// NODE.TRAVERSE();
