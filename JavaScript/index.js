const http = require("http");
const express = require("express");
const app = express();
let port = process.env.PORT || 3000;
app.get("/",(req, res) => {
     res.send
     {
          res.end("site is running");
     }
});
app.get("/naval",(req, res) => {
     res.send
     {
          const randomLines = require('random-status-lines');
          const quoteline = randomLines.generatenaval();
          data = quoteline;
          res.end(quoteline);
     }
});
app.get("/chanakya",(req, res) => {
     res.send
     {
          const randomLines = require('random-status-lines');
          const quoteline = randomLines.generatechanakya();
          data = quoteline;
          res.end(quoteline);
     }
});
app.get("/kapilgupta",(req, res) => {
     res.send
     {
          const randomLines = require('random-status-lines');
          const quoteline = randomLines.generatekapilgupta();
          data = quoteline;
          res.end(quoteline);
     }
});
app.get("/marcus",(req, res) => {
     res.send
     {
          const randomLines = require('random-status-lines');
          const quoteline = randomLines.generatemarcus();
          data = quoteline;
          res.end(quoteline);
     }
});
app.get("/nntaleb",(req, res) => {
     res.send
     {
          const randomLines = require('random-status-lines');
          const quoteline = randomLines.generatenntaleb();
          data = quoteline;
          res.end(quoteline);
     }
});
app.get("/socrates",(req, res) => {
     res.send
     {
          const randomLines = require('random-status-lines');
          const quoteline = randomLines.generatesocrates();
          data = quoteline;
          res.end(quoteline);
     }
});
app.get("/seneca",(req, res) => {
     res.send
     {
          const randomLines = require('random-status-lines');
          const quoteline = randomLines.generateseneca();
          data = quoteline;
          res.end(quoteline);
     }
});
app.get("/swamiv",(req, res) => {
     res.send
     {
          const randomLines = require('random-status-lines');
          const quoteline = randomLines.generateswamiv();
          data = quoteline;
          res.end(quoteline);
     }
});
app.get("/rtagore",(req, res) => {
     res.send
     {
          const randomLines = require('random-status-lines');
          const quoteline = randomLines.generatertagore();
          data = quoteline;
          res.end(quoteline);
     }
});
app.get("/aboutnaval",(req, res) => {
     res.send
     {
          const randomLines = require('random-status-lines');
          const quoteline = randomLines.generateaboutnaval();
          data = quoteline;
          res.end(quoteline);
     }
});

app.get("/htgr",(req, res) => {
     res.send
     {
          const randomLines = require('random-status-lines');
          const quoteline = randomLines.generatehtgr();
          data = quoteline;
          res.end(quoteline);
     }
});
app.listen(port, () => {
     console.log(`app is running on port http://localhost:${port}`);
});