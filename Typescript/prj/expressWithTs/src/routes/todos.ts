import { Router } from 'express';
import controller from '../controllers/todo';

const router = Router();

router.post('/', controller.createTodo);

router.get('/:id', controller.getTodo);

router.get('/', controller.getTodo);

/*
    자원의 전체 교체: put
    자원의 일부 교체: patch
*/

router.patch('/:id', controller.patchTodo);

router.delete('/:id', controller.deleteTodo);

export default router;