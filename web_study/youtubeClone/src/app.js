import express from "express";
import morgan from "morgan";
import cookieParser from "cookie-parser";
import { userRouter } from "./router/userRouter.js"
import { videoRouter } from  "./router/videoRouter.js";
import { globalRouter } from  "./router/globalRouter.js";
import routes from "./routes.js";
import { localMiddleware } from "./middleware.js";

const app = express();

app.set(`view engine`,`pug`);
app.use(morgan("dev"));
app.use(cookieParser());
app.use(express.json());
app.use(express.urlencoded({extended:true}));

app.use(localMiddleware);

app.use(routes.home, globalRouter);
app.use(routes.users, userRouter);
app.use(routes.videos, videoRouter);

export default app;