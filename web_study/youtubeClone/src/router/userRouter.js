import express from "express";
import { changePassword, editProfile, userDetail, users } from "../controller/userController.js";
import routes from "../routes.js";

export const userRouter = express.Router();

userRouter.get(routes.userDetail(),userDetail);
userRouter.get(routes.users,users);
userRouter.get(routes.editProfile,editProfile);
userRouter.get(routes.changePassword,changePassword);

// export {userRouter};