import { query, RequestHandler} from "express";
import { readFile, writeFile } from "fs/promises";
import { Todo } from '../models/todo';

/*
    RequestHandler라는 @types/express에서 제공해주는 핸들러 콜백 interface가 있다.
*/
export const createTodo: RequestHandler = async (req, res) => {
    try{
        const text = (req.body as {text: string}).text;

        if(text === undefined) {
            return res.status(400).json({ message: "No given key value text inside body" });
        }

        const newTodo = new Todo(Math.random().toString(), text);

        const db = await readFile('./src/dataBase/TODOS.json');
        const table: Todo[] = JSON.parse(db.toString());
        table.push(newTodo);    // 어차피 object니까 클래스 개체여도 갖다 박을 수 있구나

        const updatedTable = Buffer.from(JSON.stringify(table, null, 4));   // 4 as newline
        await writeFile('./src/dataBase/TODOS.json', updatedTable);

        return res.status(201).json({ message: 'list added successfully', todo: newTodo });
    } catch(e) {
        console.log(e);
        return res.status(400).json({ Error: e });
    }
}

export const getTodos: RequestHandler = async (req, res) => {
    try{
        const db = await readFile('./src/dataBase/TODOS.json');
        const todos: Todo[] = JSON.parse(db.toString());

        if(req.query.id !== undefined) {
            const todoWithParamId = todos.find(todo => todo.id === req.query.id);
            
            if(todoWithParamId === undefined) {
                return res.status(400).json({ message:`Given todo with id: ${req.query.id} does not exist` });
            }

            return res.status(200).json({ todo: todoWithParamId });
        }

        return res.status(200).json(todos);
    } catch(e) {
        return res.status(400).json({ Error: e });
    }
}

export const patchTodo: RequestHandler = async (req, res) => {
    try{
        if(req.query.id === undefined) {
            return res.status(400).json({ message:`No given query string id` });
        }
        
        const text = (req.body as {text: string}).text;

        if(text === undefined) {
            return res.status(400).json({ message: "No given key value text inside body" });
        }

        const db = await readFile('./src/dataBase/TODOS.json');
        const todos: Todo[] = JSON.parse(db.toString());
        // todo: add instruction of modify object after find it
        const todoWithParamId = todos.find(todo => todo.id === req.query.id);
        
        if(todoWithParamId === undefined) {
            return res.status(400).json({ message:`Given todo with id: ${req.query.id} does not exist` });
        }

        return res.status(200).json({ todo: todoWithParamId });

        return res.status(200).json(todos);
    } catch(e) {
        return res.status(400).json({ Error: e });
    }
}