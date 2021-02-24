import http from "http"
import express from "express"

const app = express();

// If enviroment var PORT has set, then use does number to PORT
// if not, use 5000
app.set(`port`, process.env.PORT || 5000); 

http.createServer(app)//
    .listen(app.get(`port`), ()=>{      //.listen(5000);
    console.log(`Web is running in express. ${app.get(`port`)}`);
})