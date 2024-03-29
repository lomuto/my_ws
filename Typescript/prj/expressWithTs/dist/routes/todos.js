"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
const express_1 = require("express");
const todo_1 = require("../controllers/todo");
const router = express_1.Router();
router.post('/', todo_1.createTodo);
router.get('/:id', todo_1.getTodos);
router.get('/', todo_1.getTodos);
/*
    자원의 전체 교체: put
    자원의 일부 교체: patch
*/
router.patch('/:id', todo_1.patchTodo);
router.delete('/:id', todo_1.deleteTodo);
exports.default = router;
