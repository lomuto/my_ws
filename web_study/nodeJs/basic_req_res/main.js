import http from "http"

const server = http.createServer((req,res)=>{
    if(req.url === `/`){

        res.writeHead(200,{"Content-type":`text/html`});
        res.write(`<html><body><h1>This is home</h1></body></html>`);
        res.end();

    }
    else if(req.url === `/student`){

        res.writeHead(200,{"Content-type":`text/html`});
        res.write(`<html><body><h1>This is student</h1></body></html>`);
        res.end();

    }
    else if(req.url === `/admin`){

        res.writeHead(200,{"Content-type":`text/html`});
        res.write(`<html><body><h1>This is admin</h1></body></html>`);
        res.end();

    }
    else if(req.url === `/data`){
        res.writeHead(200,{"Content-Type":`application/json`});
        res.write(JSON.stringify({message:"Hello from obj"}));
        res.end();
    }
    else
        res.end(`Invalid Request!`);
});

server.listen(5000);

console.log(`Node.js web server at port 5000 is running`);