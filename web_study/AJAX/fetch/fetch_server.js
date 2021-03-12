const express = require(`express`);
const fs = require(`fs`);
const path = require(`path`);
const cors = require(`cors`);

const app = express();

app.use(cors());
app.use(express.json());
app.use(express.static(path.join(__dirname)));

// 여기를 app.use 로 설정해놔서 미들웨에 index.html 파일 전송이 등록됨
// 모든 API 요청 시 `/` root 경로를 지나면서 응답이 html 파일로 됐음...
app.get(`/`,(req,res)=>{
    res.sendFile(path.join(__dirname,`index.html`));
})

app.get(`/api`,(req,res)=>{
    const data = fs.readFileSync(`data.json`);
    res.send(data);
});

app.get(`/api/:id`,(req,res)=>{
    const data = JSON.parse(fs.readFileSync(path.join(__dirname,`data.json`)));
    const result = data.find( d => d.id === parseInt(req.params.id));
    if(!result){
        res.status(404).send(`Invalid ID`);
        return;
    }
    else{
        res.send(result);
    }
})

app.post(`/api`,(req,res)=>{
    const postData = req.body.name;
    if(!postData){
        res.status(400).send(`name required`);
        return;
    }
    else if(postData.length < 2){
        res.status(400).send(`Length of name must be at least 2`);
        return;
    }
    else{
        const data = JSON.parse(fs.readFileSync(`data.json`));
        const newData={
            id:data.length + 1,
            name:postData
        };

        data.push(newData);

        res.send(newData);
    }
})

const PORT = 3030;
app.listen(PORT,()=>{
    console.log(`Server listening ${PORT}`);
})