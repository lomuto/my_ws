import http from "http"
import express from "express"

const app = express();

// If enviroment var PORT has set, then use does number to PORT
// if not, use 5000
app.set(`port`, process.env.PORT || 5000); 

app.use((req,res,next)=>{
    console.log(`First middleware requested`);

    req.user = `yun`;   // Add name field in req obj

    next();
})

app.use((req,res,next)=>{
    console.log(`Second middleware requested`);

    // res.writeHead(200,{"Content-type":"text/html;charset=utf8"});
    // res.end(`<h1> response from server : ${req.user}`);     // bring `name` field from former middleware `req` obj
    // Able to abbreviate 2 line in `res.send(~~string~~)` one line


    // Able to send object by res.send()
    const me = {name:"yun",age:18};
    //res.send(me);

    // Also able to send json string
    res.send(JSON.stringify(me));
})


http.createServer(app)//
    .listen(app.get(`port`), ()=>{
    console.log(`Web is running in express. ${app.get(`port`)}`);
})