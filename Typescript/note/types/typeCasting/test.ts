interface IFoo {
    name: string
}

let obj:IFoo = {
    name: 'kim'
};

const he = obj as unknown as {name: number};