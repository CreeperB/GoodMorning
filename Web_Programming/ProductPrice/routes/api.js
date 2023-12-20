const express = require('express');
const app = express.Router();
const bodyParser = require('body-parser');
const sqlite = require('sqlite3').verbose();

db = new sqlite.Database("database/database.db", sqlite.OPEN_READWRITE, (err) => {
    if (err) {
        console.error(err.message);
    }
    console.log('Connected to the database.');
});

sql = `CREATE TABLE IF NOT EXISTS items (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    date TEXT,
    product TEXT,
    price REAL
)`

app.use(bodyParser.urlencoded({ extended: false }));
app.use(bodyParser.json());

app.use("/public", express.static(__dirname + '/public'));

app.get("/", (req, res) => {
    res.sendFile(__dirname + "/index.html");
});

app.post('/submit', (req, res) => {
    const date = req.body.date;
    const product = req.body.product;
    const price = req.body.price;

    db.run('INSERT INTO items (date, product, price) VALUES (?, ?, ?)', [date, product, price], (err) => {
        if (err) {
            console.error(err);
            return res.status(500).send('Internal Server Error');
        }
    });
    res.redirect('/');
    return res.status(200);
});

app.post('/search', (req, res) => {
    const keyword = req.body.keyword;
    console.log(keyword);
    db.all('SELECT * FROM items WHERE product LIKE ?', ['%' + keyword + '%'], (err, rows) => {
        if (err) {
            console.error(err);
            res.status(500).send('Internal Server Error');
        } else {
            res.send(rows);
        }
    });
});

module.exports = app;