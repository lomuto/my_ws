import { RequestHandler} from "express";
import { readFile, writeFile } from "fs/promises";
import { Todo } from '../models/todo';

/*
    RequestHandler라는 @types/express에서 제공해주는 핸들러 콜백 interface가 있다.
*/
export const createTodo: RequestHandler = async (req, res) => {
    try{
        const text = (req.body as {text: string}).text;
        const newTodo = new Todo(Math.random().toString(), text);

        const db = await readFile('./dataBase/TODOS.json');
        const table = JSON.parse(db.toString());
        table.push(newTodo);    // 어차피 object니까 클래스 개체여도 갖다 박을 수 있구나

        const updatedTable = Buffer.from(JSON.stringify(table, null, 4));
        await writeFile('./dataBase/TODOS.json', updatedTable);

        return res.status(201).json({ message: 'list added successfully' });
    } catch(e) {
        console.log(e);
        return res.status(400).json({ message: 'Fail to add list' });
    }
}