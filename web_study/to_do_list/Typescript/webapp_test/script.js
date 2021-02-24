"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
const addButton = document.querySelector("#addButton");
const inputSec = document.querySelector("#inputText");
const contentWrapper = document.querySelector("#contentWrapper");
const ipAdress = `nathankys.mynetgear.com:7700`;
function ajaJPromise(method, url, data) {
    return new Promise((resolve, reject) => {
        const xhr = new XMLHttpRequest();
        xhr.open(method, url);
        xhr.onload = () => { resolve(xhr); };
        xhr.onerror = () => { reject(new Error(`network error`)); };
        if (data) {
            const objData = { content: data };
            xhr.setRequestHeader("Content-Type", "application/json");
            xhr.send(JSON.stringify(objData));
        }
        else {
            xhr.send();
        }
    });
}
window.onload = freshList;
addButton.onclick = addList; // addList(); will execute function while setting it
document.addEventListener(`keydown`, (e) => {
    if (e.key === `Enter`) { // e.keyCode deprecated. e.key Recommended
        if (document.activeElement === inputSec)
            addButton.click();
        else if (document.activeElement.className == `editBox`) // INPUT for upper letter not `input`
            document.activeElement.nextElementSibling.click();
    }
});
function freshList() {
    ajaJPromise(`GET`, `http://${ipAdress}/api/lists`) //
        .then(xhr => {
        const data = JSON.parse(xhr.response);
        for (let i = 0; i < data.length; i++) {
            const newContent = createList(data[i].content);
            contentWrapper.append(newContent);
            setAction(newContent);
        }
    })
        .catch(console.log);
}
function createList(text) {
    const newListWrapper = document.createElement(`div`);
    newListWrapper.className = `content`;
    const newList = document.createElement(`li`);
    newList.className = `list`;
    newList.innerHTML = text;
    const newDeleteBox = document.createElement(`span`);
    newDeleteBox.className = `deleteBox`;
    newDeleteBox.innerHTML = `X`;
    const newFixBox = document.createElement(`span`);
    newFixBox.className = `fixBox`;
    newFixBox.innerHTML = `Edit`;
    newListWrapper.append(newList);
    newListWrapper.append(newFixBox);
    newListWrapper.append(newDeleteBox);
    return newListWrapper;
}
function addList() {
    const text = inputSec.value; // inputSec.innerHTML 과의 차이는?
    if (text === ``) {
        alert(`Input box is empty`);
        return;
    }
    ajaJPromise(`POST`, `http://${ipAdress}/api/lists`, text) //
        .then(xhr => {
        if (xhr.status === 400) {
            alert(xhr.response);
        }
        else {
            const receivedData = xhr.response;
            const newContent = createList(receivedData);
            contentWrapper.append(newContent);
            setAction(newContent);
        }
    })
        .catch(console.log);
}
function setAction(newContent) {
    newContent.childNodes[0].onclick = () => {
        if (newContent.className === `content`)
            newContent.className = `checkedContent`;
        else
            newContent.className = `content`;
    };
    newContent.childNodes[1].onclick = () => {
        if (newContent.childNodes[1].innerHTML === `Edit`) {
            const temp = newContent.childNodes[0].innerHTML;
            const editBox = document.createElement(`input`);
            editBox.className = `editBox`;
            newContent.replaceChild(editBox, newContent.childNodes[0]);
            newContent.childNodes[1].innerHTML = `Save`;
            newContent.childNodes[0].value = temp;
            newContent.childNodes[0].focus();
        }
        else if (newContent.childNodes[1].innerHTML === `Save`) {
            const editedContent = newContent.childNodes[0].value;
            // Make an array of parents' childnodes and find index number of itself
            const indexNum = Array.from(newContent.parentNode.childNodes).indexOf(newContent);
            ajaJPromise(`PUT`, `http://${ipAdress}/api/lists/${indexNum}`, editedContent) //
                .then(xhr => {
                if (xhr.status === 400) {
                    alert(xhr.response);
                    newContent.childNodes[0].focus();
                    return;
                }
                const editedList = document.createElement(`li`);
                editedList.className = `list`;
                editedList.innerHTML = xhr.response;
                newContent.replaceChild(editedList, newContent.childNodes[0]);
                newContent.childNodes[1].innerHTML = `Edit`;
                newContent.className = `content`;
                // After editing, list won't turn to checked.
                // Re-add event toggle handler
                ////////////////////////////////////////
                newContent.childNodes[0].onclick = () => {
                    if (newContent.className === `content`)
                        newContent.className = `checkedContent`;
                    else
                        newContent.className = `content`;
                };
            })
                .catch(console.log);
        }
    };
    newContent.childNodes[2].onclick = () => {
        const indexNum = Array.from(newContent.parentNode.childNodes).indexOf(newContent);
        console.log(`Deleted index is ${indexNum}`);
        ajaJPromise(`DELETE`, `http://${ipAdress}/api/lists/${indexNum}`) //
            .then(xhr => {
            if (xhr.status === 404) {
                alert(xhr.response);
                return;
            }
            newContent.remove();
        })
            .catch(console.log);
    };
    inputSec.value = "";
}
