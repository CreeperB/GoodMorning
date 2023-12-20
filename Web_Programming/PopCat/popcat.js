const puppeteer = require('puppeteer');

let page;
let clickcount = 0;
async function click() {
    const browser = await puppeteer.launch({ headless: true });
    const page = await browser.newPage();
    await page.goto('https://popcat.click/');
    setInterval(asyncclick, 1000);
}

async function asyncclick() {
    for (let i = 0; i < 100; i++) {
        await page.click('#app');
    }
    clickcount += 100;
    console.log(clickcount);
}

click();