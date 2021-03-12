import http from "http"
import express from "express"
import path from "path"
import cookieParser from "cookie-parser"

const app = express();
const __dirname = path.resolve();
const router = express.Router();

app.set(`port`,5000);

app.use(express.static(__dirname));

app.use(cookieParser());

router.get(`/setUserCookie`,(req,res)=>{
    res.cookie(`user`,{
        name:"yun",
        age:18,
        height:182
    });

    res.redirect(`/showUserCookie`);
})

router.route(`/showUserCookie`).get((req,res)=>{
    res.send(req.cookies);
});

app.use(`/`,router);

http.createServer(app).listen(app.get(`port`));
