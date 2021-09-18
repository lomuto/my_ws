"use strict";
var __awaiter = (this && this.__awaiter) || function (thisArg, _arguments, P, generator) {
    function adopt(value) { return value instanceof P ? value : new P(function (resolve) { resolve(value); }); }
    return new (P || (P = Promise))(function (resolve, reject) {
        function fulfilled(value) { try { step(generator.next(value)); } catch (e) { reject(e); } }
        function rejected(value) { try { step(generator["throw"](value)); } catch (e) { reject(e); } }
        function step(result) { result.done ? resolve(result.value) : adopt(result.value).then(fulfilled, rejected); }
        step((generator = generator.apply(thisArg, _arguments || [])).next());
    });
};
Object.defineProperty(exports, "__esModule", { value: true });
exports.patchTodo = exports.getTodos = exports.createTodo = void 0;
const promises_1 = require("fs/promises");
const todo_1 = require("../models/todo");
/*
    RequestHandler라는 @types/express에서 제공해주는 핸들러 콜백 interface가 있다.
*/
const createTodo = (req, res) => __awaiter(void 0, void 0, void 0, function* () {
    try {
        const text = req.body.text;
        if (text === undefined) {
            return res.status(400).json({ message: "No given key value text inside body" });
        }
        const newTodo = new todo_1.Todo(Math.random().toString(), text);
        const db = yield promises_1.readFile('./src/dataBase/TODOS.json');
        const table = JSON.parse(db.toString());
        table.push(newTodo); // 어차피 object니까 클래스 개체여도 갖다 박을 수 있구나
        const updatedTable = Buffer.from(JSON.stringify(table, null, 4)); // 4 as newline
        yield promises_1.writeFile('./src/dataBase/TODOS.json', updatedTable);
        return res.status(201).json({ message: 'list added successfully', todo: newTodo });
    }
    catch (e) {
        console.log(e);
        return res.status(400).json({ Error: e });
    }
});
exports.createTodo = createTodo;
const getTodos = (req, res) => __awaiter(void 0, void 0, void 0, function* () {
    try {
        const db = yield promises_1.readFile('./src/dataBase/TODOS.json');
        const todos = JSON.parse(db.toString());
        if (req.query.id !== undefined) {
            const todoWithParamId = todos.find(todo => todo.id === req.query.id);
            if (todoWithParamId === undefined) {
                return res.status(400).json({ message: `Given todo with id: ${req.query.id} does not exist` });
            }
            return res.status(200).json({ todo: todoWithParamId });
        }
        return res.status(200).json(todos);
    }
    catch (e) {
        return res.status(400).json({ Error: e });
    }
});
exports.getTodos = getTodos;
const patchTodo = (req, res) => __awaiter(void 0, void 0, void 0, function* () {
    try {
        if (req.query.id === undefined) {
            return res.status(400).json({ message: `No given query string id` });
        }
        const text = req.body.text;
        if (text === undefined) {
            return res.status(400).json({ message: "No given key value text inside body" });
        }
        const db = yield promises_1.readFile('./src/dataBase/TODOS.json');
        const todos = JSON.parse(db.toString());
        // todo: add instruction of modify object after find it
        const todoWithParamId = todos.find(todo => todo.id === req.query.id);
        if (todoWithParamId === undefined) {
            return res.status(400).json({ message: `Given todo with id: ${req.query.id} does not exist` });
        }
        return res.status(200).json({ todo: todoWithParamId });
        return res.status(200).json(todos);
    }
    catch (e) {
        return res.status(400).json({ Error: e });
    }
});
exports.patchTodo = patchTodo;
