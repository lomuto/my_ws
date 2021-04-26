const express = require("express");
const path = require("path");
const fs = require("fs");

const PORT = 5050;
const app = express();

app.use(express.static(path.join(__dirname)));
const SEARCH = (dir,file)=>{
    return new Promise((res,rej)=>{
        fs.readdir(dir,(err,data)=>{
            if(err)
                rej(err);
            
                data.forEach(f=>{
                    if(f === file)
                        res(1);
                });
                res(0);
        });
    });
};

app.get(`/:url`, async (req,res)=>{ 
    await SEARCH(__dirname,req.params.url).then(is_exist=>{
        if(is_exist){
            res.writeHead(200,{"Content-type":"text/html;charset=utf8"});
            res.sendFile(`${__dirname}/${req.params.url}`);
        }
        else{
            res.writeHead(404);
            res.end("<h1>404 Not Found<h1>");
        }
    })
    .catch(console.log);
});

app.listen(PORT,()=>{
    console.log(`Listening to ${PORT}`);
});