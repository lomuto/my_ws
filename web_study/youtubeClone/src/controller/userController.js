import routes from "../routes.js";

export const getJoin = (_,res) => {
    res.render("Join",{pageTitle:"Join"});
}

export const postJoin = (req,res) => {
    const {
        body:{name, email, password, password2}
    } = req;

    if(password !== password2){
        res.status(400);
        res.render("Join",{pageTitle:"Join"});

        return;
    }
    else{
        // todo => Redistier User
        // todd => log user in
        res.redirect(routes.home);

        return ;
    }
}

export const getLogin = (_,res) => res.render("Login",{pageTitle:"Login"});
export const postLogin = (req,res) => {
    const { body:{ email, password } } = req;
    console.log(email, password);

    res.end(`loged in`);
};

export const logout = (_,res) => {
    // To Do: Process Log out
    res.redirect(routes.home);
};

export const users = (_,res) => res.render("Users",{pageTitle:"Users"});
export const userDetail = (_,res) => res.render("userDetail",{pageTitle:"User detail"});
export const editProfile = (_,res) => res.render("editProfile",{pageTitle:"Edit Profile"});
export const changePassword = (_,res) => res.render("changePassword",{pageTitle:"Change Password"});