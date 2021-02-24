const express = require(`express`);
const Joi = require(`joi`);

const app = express();

const courses = [
    { id:1, name: `course1` },
    { id:2, name: `course2` },
    { id:3, name: `course3` }
]

app.use(express.json());

app.get(`/api/courses`,(rea,res)=>{     //Config
    res.send(courses);
})

app.get(`/api/courses/:id`,(req,res)=>{     // Search
    const targetCourse = courses.find(c => c.id === parseInt(req.params.id));
    if(!targetCourse){ return res.status(404).send(`Invalid ID`) }
    else{
        res.send(targetCourse);
    }
    
})

app.post(`/api/courses/`,(req,res)=>{    //Add
    const schema = {
        name:Joi.string().min(3).required()     // least 3 characters and exist
    }
    //first param of validate is `request`
    const result = Joi.validate(req.body,schema)  // returns obj

    if(result.error){ return res.status(400).send(result.error.details[0].message) }
    else{
        const course = {
            id: courses.length + 1,
            name: req.body.name
        }
        courses.push(course);
        res.send(courses)
    }
})

app.put(`/api/courses/:id`,(req,res)=>{     // Edit
    const course = courses.find(c => c.id === parseInt(req.params.id));
    if(!course){
        res.status(404).send(`Invalid ID`) 
        return;
    }

    const schema = {
        name: Joi.string().min(3).required()
    }

    const { error } = Joi.validate(req.body,schema);

    if(error) {
        res.status(400).send(error.details[0].message)
        return;
    }
    else{
        course.name = req.body.name;
        res.send(course)
        res.redirect(`/api/courses`);
    }
})

app.delete(`/api/courses/:id`,(req,res)=>{
    const course = courses.find(c => c.id === parseInt(req.params.id)); // DONT FORGET parseInt
    if(!course) {
        res.status(404).send(`Invalid Id`)
        return;
        // return res.status(404).send(`Invalid Id`) Single line
    }

    const indexToDelete = courses.indexOf(course);  // find a element to delete
    courses.splice(indexToDelete,1);    // starting from destinated index, remove just 1

    res.send(courses);
})

const PORT = process.env.PORT || 3000;
app.listen(PORT,()=>{ console.log(`Listening ${PORT}`) });