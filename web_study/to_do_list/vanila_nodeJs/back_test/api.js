const express = require(`express`);
const path = require(`path`);
const fs = require(`fs`);
const cors = require(`cors`);

const app = express();
app.use(express.json());
app.use(cors({origin:"http://nathankys.mynetgear.com"}));

app.use(express.static(path.join(__dirname)));

app.get(`/lists`,(req,res)=>{
    res.sendFile(path.join(__dirname,`list.json`));
})

app.get(`/api/lists`,(req,res)=>{
    const lists = fs.readFileSync(path.join(__dirname,`list.json`));
    res.send(lists);
});

app.post(`/api/lists`,(req,res)=>{
    // BODYPARSER (express.json()) MUST BE REQUIRED TO READ REQ.BODY
    if(!req.body.content){
        res.status(400).send(`Content of list required`);
        return;
    }
    else if(req.body.content.length < 3){
        res.status(400).send(`Length of content is at least 3`);
        return;
    }
    else{
        const lists = JSON.parse(fs.readFileSync(path.join(__dirname,`list.json`)));
        const newList = {
            id:lists.length + 1,
            content:req.body.content
        };

        lists.push(newList);

        const json = JSON.stringify(lists,null,2);
        fs.writeFileSync(path.join(__dirname,`list.json`),json);

        // leave log
        fs.appendFileSync(path.join(__dirname,`log`),`${req.body.content} Added\n`);

        res.send(newList.content);
    }
});

app.put(`/api/lists/:id`,(req,res)=>{
    const lists = JSON.parse(fs.readFileSync(path.join(__dirname,`list.json`)));
    const listToEdit = lists.find(l => l.id === parseInt(req.params.id));
    console.log(req.params.id);
    if(!listToEdit){
        res.status(404).send(`Invalid id`);
        return;
    }
    if(!req.body.content){
        res.status(400).send(`Content required`);
        return;
    }
    else if(req.body.content.length < 3){
        res.status(400).send(`Length of content is at least 3`);
        return;
    }

    //log
    fs.appendFileSync(path.join(__dirname,`log`),`${listToEdit.content} modified to ${req.body.content}\n`);

    listToEdit.content = req.body.content;

    const json = JSON.stringify(lists,null,2);
    fs.writeFileSync(path.join(__dirname,`list.json`),json);

    res.send(listToEdit.content);
});

app.delete(`/api/lists/:id`,(req,res)=>{
    const lists = JSON.parse(fs.readFileSync(path.join(__dirname,`list.json`)));
    const contentId = parseInt(req.params.id);
    const list = lists.find(l => l.id === contentId);
    if(!list){
        res.status(404).send(`Invalid ID\nTry refresh page`);
        return;
    }

    // log
    fs.appendFileSync(path.join(__dirname,`log`),`${list.content} Deleted\n`);

    lists.splice(lists.indexOf(list),1);

    // Keep id of data in oredered with starting of 1
    // O(n)
    let temp = 1; 
    lists.map(element => {
            element.id = temp++;
    })

    const json = JSON.stringify(lists,null,2);
    fs.writeFileSync(path.join(__dirname,`list.json`),json);

    res.send();
});

////////////////////////////////////////////////////////////////////////////////

app.get(`/verify/off`,(req,res)=>{
    const key = 1;
    fs.writeFileSync(path.join(__dirname,`verification`),`${key}`);
    res.send(`${key}`);
});


const PORT = 7700;
app.listen(PORT,()=>{
    console.log(`API server listening to ${PORT}`);
})