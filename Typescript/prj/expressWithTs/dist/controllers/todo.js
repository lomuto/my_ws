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
exports.createTodo = void 0;
const promises_1 = require("fs/promises");
const todo_1 = require("../models/todo");
const createTodo = (req, res) => __awaiter(void 0, void 0, void 0, function* () {
    try {
        const text = req.body.text;
        const newTodo = new todo_1.Todo(Math.random().toString(), text);
        const db = yield promises_1.readFile('./dataBase/TODOS.json');
        const table = JSON.parse(db.toString());
        table.push(newTodo); // 어차피 object니까 클래스 개체여도 갖다 박을 수 있구나
        const updatedTable = Buffer.from(JSON.stringify(table, null, 4));
        yield promises_1.writeFile('./dataBase/TODOS.json', updatedTable);
        return res.status(201).json({ message: 'list added successfully' });
    }
    catch (e) {
        console.log(e);
        return res.status(400).json({ message: 'Fail to add list' });
    }
});
exports.createTodo = createTodo;
