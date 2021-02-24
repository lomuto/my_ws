const ourRequest = new XMLHttpRequest();

const box = document.querySelector(`#json`);
const showBtn = document.querySelector(`#showBtn`);
const searchBtn = document.querySelector(`#searchBtn`);
const addBtn = document.querySelector(`#addBtn`);
const editBtn = document.querySelector(`#editBtn`);
const deleteBtn = document.querySelector(`#deleteBtn`);

showBtn.onclick = ()=>{
    ourRequest.open(`GET`,`http://konkuksw.mynetgear.com/api/courses`);

    ourRequest.onload = ()=>{
        show(JSON.parse(ourRequest.response));
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
    ourRequest.open(`GET`,`http://konkuksw.mynetgear.com/api/courses/${idNum}`);

    ourRequest.onload = ()=>{
        if(ourRequest.status === 404){
            box.innerHTML = "";
            alert(ourRequest.response);
        }
        else{
            const data = JSON.parse(ourRequest.response);
            console.log(data);
            box.innerHTML = `id: ${data.id} / name: ${data.name}`;
        }
    }
    ourRequest.send();
}


addBtn.onclick = ()=>{
    const xhr = new XMLHttpRequest();
    const nameToAdd = prompt(`Enter a name of list to add`);
    xhr.open(`POST`,`http://konkuksw.mynetgear.com/api/courses`);

    xhr.onload = ()=>{
            if(xhr.status === 400){
                alert(xhr.responseText);
            }
            else{
                const data = JSON.parse(xhr.response);
                box.innerHTML = `[ id: ${JSON.stringify(data.id)} /  name: ${JSON.stringify(data.name)}] Added`;
            }
    };
    // 아 시발 함수끝에 따옴표 안찍었다고 onload 안되는게 말이되냐?
    // 변수선언은 세미콜론 안찍어도 되던데 시발 지 좆대로인 개 좆같은 언어네

    const dataToSend = {name:nameToAdd};
    // MUST SPECIFY THAT DATA TO BE SENT IS JSON
    xhr.setRequestHeader('Content-Type', 'application/json');
    xhr.send(JSON.stringify(dataToSend));
}

editBtn.onclick = ()=>{
    const idNum = prompt(`Enter number of id to edit`);
    const nameToEdit = prompt(`Enter name for editing`);
    ourRequest.open(`PUT`,`http://konkuksw.mynetgear.com/api/courses/${idNum}`);

    ourRequest.onload = ()=>{
        if(this.status === 404)
            alert(`Invalid ID`);
        else if(this.status === 400)
            alert(this.responseText);
        else
            box.innerHTML= `${ourRequest.response}`
    };
    const dataToSend = {name:nameToEdit};
    ourRequest.setRequestHeader(`Content-Type`,`application/json`);
    ourRequest.send(JSON.stringify(dataToSend));
}



deleteBtn.onclick = ()=>{
    const xhr = new XMLHttpRequest();

    const idToDelete = prompt(`Enter id of element to delete`);
    xhr.open(`DELETE`,`http://konkuksw.mynetgear.com/api/courses/${idToDelete}`);
    xhr.onload = ()=>{
        if(this.status === 404)
            alert(`Invalid ID`);
        else
            box.innerHTML = xhr.response;
    };

    xhr.send();
}