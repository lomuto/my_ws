import ROUTES from "../routes/routes.js"

export const rootCtl = (_,res) =>{
    res.render("root",{pageName:"home"});
};
export const homeCtl = (_,res) =>{
    res.redirect(ROUTES.root);
};
export const htmlCtl = (_,res) =>{
    res.render("html",{pageName:"html"});
};
export const cssCtl = (_,res) =>{
    res.render("css",{pageName:"css"});
};
export const jsCtl = (_,res) =>{
    res.render("js",{pageName:"javascript"});
};
export const introCtl = (_,res) =>{
    res.render("intro",{pageName:"introduce"});
};