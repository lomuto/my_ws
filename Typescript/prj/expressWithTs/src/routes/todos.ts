import { Router } from 'express';
import { createTodo } from '../controllers/todo';

const router = Router();

router.post('/', createTodo);

router.get('/');

/*
    자원의 전체 교체: put
    자원의 일부 교체: patch
*/

router.patch('/:id');

router.delete('/:id');

export default router;