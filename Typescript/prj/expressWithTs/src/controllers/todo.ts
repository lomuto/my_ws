import { RequestHandler} from "express";
import { readFile, writeFile } from "fs/promises";
import { Todo } from '../models/todo';

/*
    req.params: localhost/myServer/thisisparam
    req.query: localhost/myServer?qurey=thisisQuery
*/


/*
    RequestHandler라는 @types/express에서 제공해주는 핸들러 콜백 interface가 있다.
*/

/*
    Generic in Request handelr: Tell ts that
     request.params has such object key value with given type
*/
const getTodos: RequestHandler<({ id: string })> = async (req, res, next) => {
    try{
        const db = await readFile('./src/dataBase/TODOS.json');
        const todos: Todo[] = JSON.parse(db.toString());

        if(req.params.id === undefined) {
            return res.status(200).json(todos);
        }

        // passing a index would be more fast and clear to read
        const indexOfTodo = todos.findIndex(todo => todo.id === req.params.id);
        
        // -1 of index if not founded
        if(indexOfTodo < 0) {
            throw new Error(`Could not find a todo with given id: ${req.params.id}`);
        }

        return res.status(200).json({ todo: todos[indexOfTodo] });
    } catch(e) {
        next(e);
    }
}

const createTodo: RequestHandler = async (req, res, next) => {
    try{
        /*
            Type casting in ts with `as` keyword
            type cast req.body type any to object type with string type key `text` included
        */
        const text = (req.body as {text: string}).text;

        if(text === undefined) {
            throw new Error('Could not find text in request.body');
        }

        const newTodo = new Todo(Math.random().toString(), text);

        const db = await readFile('./src/dataBase/TODOS.json');
        const table: Todo[] = JSON.parse(db.toString());
        table.push(newTodo);    // 어차피 object니까 클래스 개체여도 갖다 박을 수 있구나

        const updatedTable = Buffer.from(JSON.stringify(table, null, 4));   // 4 as newline
        await writeFile('./src/dataBase/TODOS.json', updatedTable);

        return res.status(201).json({ message: 'list added successfully', todo: newTodo });
    } catch(e) {
        /*
            Express doesn't support promises.
            You have to handle caught error in catch block INSIDE OF ASYNC FuNCTION
            OR
            If you have middleware that deals with errors,
            pass an error with next function
        */
        next(e);
    }
}

const patchTodo: RequestHandler<({ id: string })> = async (req, res, next) => {
    try{
        if(req.params.id === undefined) {
            throw new Error(`No given params sent to url`);
        }
        
        const text = (req.body as {text: string}).text;

        if(text === undefined) {
            throw new Error('Could not find text in request.body');
        }

        const db = await readFile('./src/dataBase/TODOS.json');
        const todos: Todo[] = JSON.parse(db.toString());
        
        const indexOfTodo = todos.findIndex(todo => todo.id === req.params.id);
        
        if(indexOfTodo < 0) {
            throw new Error(`Could not find a todo with given id: ${req.params.id}`);
        }

        todos[indexOfTodo].text = text;

        const updatedTable = Buffer.from(JSON.stringify(todos, null, 4));   // 4 as newline
        await writeFile('./src/dataBase/TODOS.json', updatedTable);

        return res.status(200).json({ message: `todo updated`, updatedTodo: todos[indexOfTodo] });
    } catch(e) {
        next(e);
    }
}

const deleteTodo: RequestHandler<( {id: string} )> = async (req, res, next) => {
    try{
        const todoId = req.params.id;

        if(todoId === undefined) {
            throw new Error(`No given id as url params`);
        }

        const db = await readFile('./src/dataBase/TODOS.json');
        const todos: Todo[] = JSON.parse(db.toString());
        
        const indexOfTodo = todos.findIndex(todo => todo.id === todoId);
        
        if(indexOfTodo < 0) {
            throw new Error(`Could not find a todo with given id: ${todoId}`);
        }

        /*
            Remove 1 element starting from indexOfTodo
        */
        todos.splice(indexOfTodo, 1);

        const updatedTable = Buffer.from(JSON.stringify(todos, null, 4));   // 4 as newline
        await writeFile('./src/dataBase/TODOS.json', updatedTable);

        return res.status(200).json({ message: `Todo deleted` });
    } catch(e) {
        next(e);
    }
}

export default {
    getTodo: getTodos,
    createTodo: createTodo,
    patchTodo: patchTodo,
    deleteTodo: deleteTodo
};