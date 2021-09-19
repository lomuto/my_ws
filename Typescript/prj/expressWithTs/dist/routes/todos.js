"use strict";
var __importDefault = (this && this.__importDefault) || function (mod) {
    return (mod && mod.__esModule) ? mod : { "default": mod };
};
Object.defineProperty(exports, "__esModule", { value: true });
const express_1 = require("express");
const todo_1 = __importDefault(require("../controllers/todo"));
const router = express_1.Router();
router.post('/', todo_1.default.createTodo);
router.get('/:id', todo_1.default.getTodo);
router.get('/', todo_1.default.getTodo);
/*
    자원의 전체 교체: put
    자원의 일부 교체: patch
*/
router.patch('/:id', todo_1.default.patchTodo);
router.delete('/:id', todo_1.default.deleteTodo);
exports.default = router;
