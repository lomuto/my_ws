import express from "express";
import ROUTES from "./routes/routes.js"
import Route from "./routes/pageRouter.js"
import middleware from "./middleware.js";
const app = express();

app.set("view engine","pug");

app.use(middleware);
app.use(ROUTES.root,Route);

export default app;