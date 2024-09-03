// step1: create a folder
// step2: move into that folder
// step3: npm init -y
// step4: open folder using vs code
// step5: npm i express
// step6: create server.js file

// Server Instantiate
const express = require('express');
const app = express();

// used to parse req.body in express -> PUT or POST
const bodyParser = require('body-parser');

// specifically parse JSON data and add it to the request.Body object
app.use(bodyParser.json())


// Activate the server on 3000 port
app.listen(3000 , () => {
    console.log("Server started at port number 3000");
})

// Routes
app.get( '/' , (req , res) => {
    res.send("hii Yash Bro")
})

app.post( '/api/cars' , (req , res) => {
    const { name , brand } = req.body;
    console.log(name);
    console.log(brand);
    res.send("your car added succesfully");
})


const mongoose = require('mongoose');
mongoose.connect('mongodb://localhost:27017/myDatabase' )
.then( ()=> { console.log("Connection established between mongoDb and express")})
.catch( (error)=>{ console.log("Received an error")})