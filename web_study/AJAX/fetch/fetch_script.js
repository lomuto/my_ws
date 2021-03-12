const showBtn = document.querySelector(`#showBtn`);
const searchBtn = document.querySelector(`#searchBtn`);
const addBtn = document.querySelector(`#addBtn`);
const editBtn = document.querySelector(`#editBtn`);
const deleteBtn = document.querySelector(`#deleteBtn`);
const display = document.querySelector(`#json`);

showBtn.onclick = ()=>{
    fetch(`http://localhost:3030/api`)
        .then(response=>{
            return response.json();
        })
            .then(data => {
                display.innerHTML="";
                for(i = 0; i<data.length; i++){
                    display.appendChild(document.createTextNode(JSON.stringify(data[i])));
                    display.appendChild(document.createElement(`br`));
                }
            })
        .catch(console.log);
}

searchBtn.onclick = ()=>{
    const id = prompt(`Enter id of content to find`);
    fetch(`http://localhost:3030/api/${id}`)
    .then(res => res.json())
    .then(data => display.innerHTML = JSON.stringify(data))
    .catch(console.log);
}

async function fetchPost(){
    const newName = prompt(`Enter name for content to add`);
    try{
        const response = await fetch(`http://localhost:3030/api`,{
            method:"POST",
            body: JSON.stringify({
                name:newName
            }),
            headers:{
                "Content-type":"application/json"
            }
        });
        if(response.status === 400){
            const err = await response.text();
            throw err;
        }
        const data = await response.text();
        display.innerHTML = data;
    }catch(e){
        alert(e);
    }
}

addBtn.onclick = fetchPost;
