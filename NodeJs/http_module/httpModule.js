import http from "http"

// Create web server object
const server = http.createServer();


const port = 5000;
const host = `192.168.35.123`       // `ipconfig` for configurate IP address for host variable
server.listen(port,host,`3`,()=>{
    console.log(`Web Server is running: ${host},${port}`)
})

// Set EventHandler for `connection`
// configurate client's address and port with `address` method in `socket` object
server.on(`connection`,(socket)=>{
    const addr = socket.address();
    console.log(`Client has connected ${addr.address}:${addr.port}`);
})


// Set EventHandler for `request`
// writeHead: make header for request
// wrtie: build body data for request
// end: SEND RESPONSE TO CLIENT ( res.write won't work without res.end )
server.on(`request`,(req,res)=>{
    console.log(`request from client`);

    res.writeHead(200,{"Content-type":"text/html"});
    res.write(`Hello`);
    res.end();
})
