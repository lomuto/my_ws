const request = require("request");
const ERR = require(`./chalk.js`);

const geoUrl = `https://api.mapbox.com/geocoding/v5/mapbox.places/${encodeURIComponent(process.argv[2])}.json?access_token=pk.eyJ1IjoieXVuc3VrMDYxNiIsImEiOiJja2x6MHg2ZmUwOWl6MnlvOWIwNHhycXpmIn0.LduNXS6x6Q9zOFs6xjMNTQ&language=ko`

const getCor = (url)=>{
    return new Promise((resolve,rej)=>{
        request.get(url,(err,res,body)=>{
            console.log(body)
            if(JSON.parse(body).features.length === 0){
                rej(ERR("Invalid name of location"));
                return ;
            }
            const data = JSON.parse(body).features[0].center;
            resolve(data);
        });
    })
}

const getWeatherUrl = data=>{
    return `http://api.weatherstack.com/current?access_key=46f0f9a3d93f3df1501fdf24ac4080a2&query=${data[1]},${data[0]}`;
}


const getWeather = url =>{
    request.get(url,(err,res,body)=>{
        if(err){
            console.log(err);
            return ;
        }
        const data = JSON.parse(body).current;
        const {temperature} = data;
        console.log(`Current temperature is ${temperature} and chance of rain in ${data.precip}%`);
    });
}

getCor(geoUrl).then(getWeatherUrl).then(getWeather)
    .catch(console.log)