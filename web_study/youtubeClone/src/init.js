import app from "./app.js";

const PORT = 5555;
app.listen(PORT,(req,res)=>{
    console.log(`✅ Server listening on ${PORT}`);
})