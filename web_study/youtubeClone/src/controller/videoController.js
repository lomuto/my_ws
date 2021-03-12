import videosDb from "./../db.js";
import routes from "../routes.js";

// After setting app.set("view engine","pug");
// res.render("foo") will search `foo.pug` file in views folder
export const home = (req,res) => res.render("home",{pageTitle:"Home",videos:videosDb});
export const search = (req,res) => {
    // const searchingBy = req.query.term
    const {query:{ term: title }} = req;
    const targetVideo = videosDb.find((e)=>e.title === title);
    console.log(targetVideo);
    res.render("search",{pageTitle:"Search", searchingBy:title,tVideo:targetVideo});
}  

export const getUpload = (req,res) => {
    res.render("upload",{pageTitle:"Upload"});
}

export const postUpload = (req,res) => {
    const{
        body:{file, title, description}
    } = req;

    //To Do: upload and save video

    res.redirect(routes.videoDetail(32439));
}

export const videoDetail = (req,res) => res.render("videoDetail",{pageTitle:"Video Detail"});
export const editVideo = (req,res) => res.render("editVideo",{pageTitle:"Edit Video"});
export const deleteVideo = (req,res) => res.render("deleteVideo",{pageTitle:"Delete Video"});