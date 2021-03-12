const express = require(`express`);
const path = require(`path`);

const app = express();
const router = express.Router();

app.use(`/`,express.static(path.join(__dirname,"..","webapp")));    // 상위경로인 `__dirname`,`..` 을 올리면 css 적용 안됨. "webapp"을 포함한 exact path 필요한가봄 
app.get(`/`,(req,res)=>{
    res.sendFile(path.join(__dirname,"..","webapp","index.html"));
})

app.use(`*`,(req,res)=>{
    res.writeHead(404,{"Content-type":"text/html"});
    res.end(`<h1>404 Error</h1><h2>Invalid URL</h2>`);
})

const PORT = 5555;
app.listen(PORT,()=>{
    console.log(`PORT listening to ${PORT}`);
})