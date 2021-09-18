"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
const express_1 = require("express");
const todo_1 = require("../controllers/todo");
const router = express_1.Router();
router.post('/', todo_1.createTodo);
router.get('/');
/*
    자원의 전체 교체: put
    자원의 일부 교체: patch
*/
router.patch('/:id');
router.delete('/:id');
exports.default = router;
