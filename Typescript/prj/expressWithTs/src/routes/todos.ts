import { Router } from 'express';
import { createTodo, getTodos, patchTodo } from '../controllers/todo';

const router = Router();

router.post('/', createTodo);

router.get('/:id', getTodos);

router.get('/', getTodos);

/*
    자원의 전체 교체: put
    자원의 일부 교체: patch
*/

router.patch('/:id', patchTodo);

router.delete('/:id');

export default router;