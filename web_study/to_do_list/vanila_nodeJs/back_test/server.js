const express = require(`express`);
const path = require(`path`);
const fs = require(`fs`);

const app = express();
const router = express.Router();

app.use(express.json());

// app.use가 없으면 밑에 get에서 res.sendFile 에서 불러온 html파일에서 링크된 css js 로딩 안됨
app.use(`/`,express.static(path.join(__dirname,`..`,`webapp_test`)));


// redirect/////////////////////
router.get(`/home`,(req,res)=>{
    res.redirect(`/`);
});

app.use(`/`,router);
/////////////////////////////////

app.get(`/`,(req,res)=>{
    res.sendFile(path.join(__dirname,`..`,`webapp_test`,`todo.html`));
});

app.get(`/login`,(req,res)=>{
    res.sendFile(path.join(__dirname,`..`,`webapp_test`,`login.html`));
})

// execption url handling
app.use(`*`,(req,res)=>{
    res.writeHead(404,{"Content-Type":"text/html"});
    res.end(`<h1>404 NOT FOUND</h1><h2>INVALID URL</h2>`)
})

/////////////////////////////////////////////////////////////////////////////////
//API

// //REST API

// app.get(`/lists`,(req,res)=>{
//     res.sendFile(path.join(__dirname,`list.json`));
// })


/////////////////////////////////////////////////////////////////////////////////

// //REST API

// app.get(`/api/lists`,(req,res)=>{
//     const lists = fs.readFileSync(path.join(__dirname,`list.json`));
//     res.send(lists);
// });

// app.post(`/api/lists`,(req,res)=>{
//     // BODYPARSER MUST BE REQUIRED TO READ REQ.BODY
//     if(!req.body.content){
//         res.status(400).send(`Content of list required`);
//         return;
//     }
//     else if(req.body.content.length < 3){
//         res.status(400).send(`Length of content is at least 3`);
//         return;
//     }
//     else{
//         const lists = JSON.parse(fs.readFileSync(path.join(__dirname,`list.json`)));
//         const newList = {
//             id:lists.length + 1,
//             content:req.body.content
//         };

//         lists.push(newList);

//         const json = JSON.stringify(lists,null,2);
//         fs.writeFileSync(path.join(__dirname,`list.json`),json);

//         // leave log
//         fs.appendFileSync(path.join(__dirname,`log`),`${req.body.content} Added\n`);

//         res.send(newList);
//     }
// });

// app.put(`/api/lists/:id`,(req,res)=>{
//     const lists = JSON.parse(fs.readFileSync(path.join(__dirname,`list.json`)));
//     const listToEdit = lists.find(l => l.id === parseInt(req.params.id));
//     console.log(req.params.id);
//     if(!listToEdit){
//         res.status(404).send(`Invalid id`);
//         return;
//     }
//     if(!req.body.content){
//         res.status(400).send(`Content required`);
//         return;
//     }
//     else if(req.body.content.length < 3){
//         res.status(400).send(`Length of content is at least 3`);
//         return;
//     }

//     //log
//     fs.appendFileSync(path.join(__dirname,`log`),`${listToEdit.content} modified to ${req.body.content}\n`);

//     listToEdit.content = req.body.content;

//     const json = JSON.stringify(lists,null,2);
//     fs.writeFileSync(path.join(__dirname,`list.json`),json);

//     res.send(listToEdit.content);
// });

// app.delete(`/api/lists/:id`,(req,res)=>{
//     const lists = JSON.parse(fs.readFileSync(path.join(__dirname,`list.json`)));
//     const contentId = parseInt(req.params.id);
//     const list = lists.find(l => l.id === contentId);
//     if(!list){
//         res.status(404).send(`Invalid ID`);
//         return;
//     }

//     // log
//     fs.appendFileSync(path.join(__dirname,`log`),`${list.content} Deleted\n`);

//     lists.splice(lists.indexOf(list),1);

//     // Keep id of data in oredered with starting of 1
//     // O(n)
//     let temp = 1; 
//     lists.map(element => {
//             element.id = temp++;
//     })

//     const json = JSON.stringify(lists,null,2);
//     fs.writeFileSync(path.join(__dirname,`list.json`),json);

//     res.send(list);
// });

// ////////////////////////////////////////////////////////////////////////////////

// app.get(`/verify/off`,(req,res)=>{
//     const key = 1;
//     fs.writeFileSync(path.join(__dirname,`verification`),`${key}`);
//     res.send(`${key}`);
// });


const PORT = process.env.PORT || 9000;

app.listen(PORT,(req,res)=>{
    console.log(`Server Listening to ${PORT}`);
});