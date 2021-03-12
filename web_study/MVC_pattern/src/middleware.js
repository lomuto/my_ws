import ROUTES from "./routes/routes.js";

const middleware = (req,res,next)=>{
    // Add sth to set a global middleware   
    res.locals.ROUTES = ROUTES;
    next();
}

export default middleware;