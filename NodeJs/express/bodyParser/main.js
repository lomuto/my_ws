import http from "http"
import exrpess from "express"
import path from "path"
import serveStatic from "serve-static"
import bodyParser from "body-parser"

const app = exrpess();
const __dirname = path.resolve();
const router = express.Router();

app.use(serveStatic(__dirname));

app.use(express.json());
// app.use(bodyParser.json());

router.route(`/`).get((req,res)=>{
    req.redirect(`/index.html`);
})

router.route('/login').post((req,res)=>{
    res.wrtiteHead(200,{"Content-type":"text/html;charset=utf8"});
    res.write(`<h1>Request from Server</h1>`);
    res.write(req.body.value);
})

app.use('/',router);
app.use('/login',router);

http.createServer(app).listen(5000);