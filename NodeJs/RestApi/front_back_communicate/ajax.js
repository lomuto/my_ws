const ourRequest = new XMLHttpRequest();

const box = document.querySelector(`#json`);
const showBtn = document.querySelector(`#showBtn`);
const searchBtn = document.querySelector(`#searchBtn`);
const editBtn = document.querySelector(`#editBtn`);
const deleteBtn = document.querySelector(`#deleteBtn`);

showBtn.onclick = ()=>{
    ourRequest.open(`GET`,`http://localhost:3000/api/courses`);

    ourRequest.onload = ()=>{
        show(ourRequest.responseText);
    }
    
    ourRequest.send();
}

function show(data){
    box.innerHTML = "";
    for(let i=0; i<data.length; i++){
        box.appendChild(document.createTextNode(`id: ${data[i].id} / name: ${data[i].name}`));
        box.appendChild(document.createElement(`br`));
    }
}



searchBtn.onclick = ()=>{
    const idNum = prompt(`Enter number of id to search`);
    ourRequest.open(`GET`,`http://localhost:3000/api/courses/${idNum}`);

    ourRequest.onload = ()=>{

    }
}
// document.addEventListener(`keydown`,(e)=>{
//     if(e.key === `Enter`){
//         ourRequest.open(`GET`,`./test.json`);

//     ourRequest.onload = ()=>{
//         const text = JSON.parse(ourRequest.responseText);
//         console.log(text.name);
//     }
    
//     ourRequest.send();
//     }
// })