import express from "express";
import path from "path";

const app = express();
const __dirname = path.resolve();

app.set("view engine","pug");
app.set("views", path.join(__dirname, "views"));

app.get("/",(_,res)=>{
    res.render("home");
})

const PORT = 9999;
app.listen(PORT,()=>{
    console.log(`✅ Listening to http://localhost:${PORT}`);
})