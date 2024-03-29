import express, { Request, Response, NextFunction } from 'express';
import todoRouter from './routes/todos';

const app = express();

app.use(express.json());

app.use('/todos', todoRouter);

/*
    Error handling middleware.
    this will handling thrown error from callback function
*/
app.use((err: Error, req: Request, res: Response, next: NextFunction) => {
    res.status(500).json({ message: err.message });
})

app.listen(3000, () => {
    console.log(`App listening to ${3000}`);
});