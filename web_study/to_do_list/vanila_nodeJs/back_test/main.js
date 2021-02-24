import express from "express";
import path from "path";
import { fileURLToPath } from 'url';
const __dirname = fileURLToPath(import.meta.url);

const app = express();

const frontPath = path.join(__dirname,"..","..","webapp_test");

app.use(express.json());
app.use(express.static(frontPath));

app.get(`/`,(req,res)=>{
    res.sendFile(path.resolve(frontPath,"todo.html"));
})

const PORT = 9999;
app.listen(PORT,()=>{
    console.log(`Server listening to ${PORT} ${path.join(frontPath,"todo.html")}`);
})