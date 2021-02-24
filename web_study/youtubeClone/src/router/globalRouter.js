import express from "express";
import { home,search } from "../controller/videoController.js"
import { getJoin, postJoin, getLogin, postLogin, logout } from "../controller/userController.js";
import routes from "../routes.js";

const globalRouter = express.Router();

globalRouter.get(routes.home,home);

globalRouter.get(routes.join,getJoin);
globalRouter.post(routes.join,postJoin);

globalRouter.get(routes.login,getLogin);
globalRouter.post(routes.login,postLogin);

globalRouter.get(routes.logout,logout);
globalRouter.get(routes.search,search);

export { globalRouter };