import express from "express";
import { cssCtl, homeCtl, htmlCtl, introCtl, jsCtl, rootCtl } from "../controller/pageController.js";
import ROUTES from "./routes.js";

const Route = express.Router();

Route.get(ROUTES.root,rootCtl);
Route.get(ROUTES.home,homeCtl);
Route.get(ROUTES.html,htmlCtl);
Route.get(ROUTES.css,cssCtl);
Route.get(ROUTES.js,jsCtl);
Route.get(ROUTES.intro,introCtl);

export default Route;