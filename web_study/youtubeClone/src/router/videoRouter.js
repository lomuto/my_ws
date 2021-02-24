import express from "express";
import { videoDetail, getUpload, postUpload, editVideo, deleteVideo, search } from "../controller/videoController.js";
import routes from "../routes.js";

const videoRouter = express.Router();

videoRouter.get(routes.search,search);

videoRouter.get(routes.upload,getUpload);
videoRouter.post(routes.upload,postUpload);

videoRouter.get(routes.videoDetail(),videoDetail);
videoRouter.put(routes.editVideo,editVideo);
videoRouter.delete(routes.deleteVideo,deleteVideo);

export { videoRouter };