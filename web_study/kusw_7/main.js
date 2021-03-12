const express = require(`express`);
const path = require(`express`);
const fs = require(`fs`);

const app = express();
const router = express.Router();

app.use(express.static(__dirname));

app.use(express.json());
<<<<<<< HEAD
app.use(express.urlencoded({ extended: false }));

router.get(`/`, (req, res) => {
  res.redirect(`/index.html`);
});

router.post(`/setInfo`, (req, res) => {
  const info = {
    name: req.body.name,
    scholarNum: req.body.scholarNum,
    C: req.body.C,
    Python: req.body.Python,
    JavaScript: req.body.JavaScript,
  };

  const readFile = () => {
    return new Promise((res, rej) => {
      fs.readFile(`${__dirname}/userInfo.json`, (err, data) => {
        if (err) rej(err);
        else res(data);
      });
    });
  };

  readFile() //
    .then((data) => {
      const temp = JSON.parse(data);
      temp.user.push(info);
      const jsonData = JSON.stringify(temp, null, 2);
      fs.writeFileSync(`${__dirname}/userInfo.json`, jsonData);
      console.log(`complete`);
    })
    .catch(console.log);

  res.redirect(`/thx.html`);
});

app.use("/", router);

app.listen(8000);
=======
app.use(express.urlencoded({extended:false}));

router.get(`/`,(req,res)=>{
    res.redirect(`/index.html`);
})

router.post(`/setInfo`,(req,res)=>{
    const info = {
        "name":req.body.name,
        "scholarNum":req.body.scholarNum,
        "C":req.body.C,
        "Python":req.body.Python,
        "JavaScript":req.body.JavaScript
    }

    const readFile = ()=>{
        return new Promise((res,rej)=>{
            fs.readFile(`${__dirname}/userInfo.json`,(err,data)=>{
                if(err)
                    rej(err);
                else
                    res(data);
            })
        })
    }

    readFile()//
        .then((data)=>{
            const temp = JSON.parse(data);
            temp.user.push(info);
            const jsonData = JSON.stringify(temp,null,2);
            fs.writeFileSync(`${__dirname}/userInfo.json`,jsonData);
            console.log(`complete`);
        })
        .catch(console.log);

    res.redirect(`/thx.html`);
})

app.use('/',router);

app.listen(5000,`0.0.0.0`);
>>>>>>> 0a1b8ab2f8faca77f99fedab6e2bd2e7e015ba33
