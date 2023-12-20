function doFirst() {
    // 先跟 HTML 畫面產生關連，再建事件聆聽功能
    document.getElementById('theFile').onchange = fileChange
}

var imageHeight = 0
var imageWidth = 0
var file_exist = false
function fileChange() {
    let file = document.getElementById('theFile').files[0]

    let readFile = new FileReader()
    readFile.readAsDataURL(file)
    readFile.addEventListener('load', () => {
        let box = document.getElementById('box')
        // if (box.querySelector('img')) {
        //     box.removeChild(box.querySelector('img'))
        // }
        let image = document.createElement('img')
        image.setAttribute('draggable', false)
        image.setAttribute('id', 'imgbg')
        image.src = readFile.result


        image.addEventListener('load', () => {
            imageHeight = image.height
            imageWidth = image.width
            console.log(imageHeight, imageWidth)

            //判斷式，圖片小於block，自動撐開
            if (image.style.width < 300 || image.style.height < 300) {
                image.style.width = '300px'
                image.style.height = '300px'
            }
            image.style.maxWidth = '300px'
            image.style.maxHeight = '300px'

            box.appendChild(image)
        })
    })
    file_exist = true
}

function download() {
    //判斷是否有圖片
    if (!file_exist) {
        alert('請先上傳圖片')
        return false
    }
    let box = document.getElementById('box')
    let image = box.querySelector('img')
    let canvas = document.createElement('canvas')
    let upperTextText = document.getElementById('upperText').innerHTML
    let upperFontSize = parseFloat(window.getComputedStyle(document.getElementById('upperText'), null).getPropertyValue('font-size'))
    let upperX = document.getElementById('upperText').getBoundingClientRect().left - box.getBoundingClientRect().left;
    let upperY = document.getElementById('upperText').getBoundingClientRect().top - box.getBoundingClientRect().top + upperFontSize;
    let lowerTextText = document.getElementById('lowerText').innerHTML
    let lowerFontSize = parseFloat(window.getComputedStyle(document.getElementById('lowerText'), null).getPropertyValue('font-size'))
    let lowerX = document.getElementById('lowerText').getBoundingClientRect().left - box.getBoundingClientRect().left;
    let lowerY = document.getElementById('lowerText').getBoundingClientRect().top - box.getBoundingClientRect().top + lowerFontSize;

    canvas.width = 300
    canvas.height = 300

    let ctx = canvas.getContext('2d')
    ctx.drawImage(image, 0, 0, 300, 300)
    ctx.font = upperFontSize + 'px Noto Sans'
    var lineHeight = ctx.measureText("M").width * 1.2;
    var lines = upperTextText.split("\n");
    for (var i = 0; i < lines.length; ++i) {
        ctx.fillText(lines[i], upperX, upperY);
        upperY += lineHeight;
    }
    ctx.font = lowerFontSize + 'px Noto Sans'
    var lineHeight = ctx.measureText("M").width * 1.2;
    var lines = lowerTextText.split("\n");
    for (var i = 0; i < lines.length; ++i) {
        ctx.fillText(lines[i], lowerX, lowerY);
        lowerY += lineHeight;
    }

    let dataURL = canvas.toDataURL('image/jpeg')
    let a = document.createElement('a')
    a.href = dataURL
    a.download = 'image.jpg'
    a.click()

    console.log("Image: " + imageHeight, imageWidth)
}



function changeUpperInput() {
    let upper = document.getElementById('upperText')
    let upper_input = document.getElementById('upperInput')
    console.log(upper_input.value)
    upper.innerHTML = upper_input.value
}

function upperFontIncrease() {
    let upper = document.getElementById('upperText');
    let style = window.getComputedStyle(upper, null).getPropertyValue('font-size');
    let currentSize = parseFloat(style);
    upper.style.fontSize = (currentSize + 1) + 'px';
}

function upperFontReduce() {
    let upper = document.getElementById('upperText');
    let style = window.getComputedStyle(upper, null).getPropertyValue('font-size');
    let currentSize = parseFloat(style);
    upper.style.fontSize = (currentSize - 1) + 'px';
}

function changeLowerInput() {
    let lower = document.getElementById('lowerText')
    let lower_input = document.getElementById('lowerInput')
    lower.innerHTML = lower_input.value
}

function lowerFontIncrease() {
    let lower = document.getElementById('lowerText');
    let style = window.getComputedStyle(lower, null).getPropertyValue('font-size');
    let currentSize = parseFloat(style);
    lower.style.fontSize = (currentSize + 1) + 'px';
}

function lowerFontReduce() {
    parseFloat(window.getComputedStyle(document.getElementById('lowerText'), null).getPropertyValue('font-size'))
    let lower = document.getElementById('lowerText');
    let style = window.getComputedStyle(lower, null).getPropertyValue('font-size');
    let currentSize = parseFloat(style);
    lower.style.fontSize = (currentSize - 1) + 'px';
}

function move(obj) {
    var dragobj = null, h1, i1, oLeft, oTop, oRight, oBottom;
    var boundBox;
    var boundBoxX;
    var boundBoxY;
    var cursor = {
        x: 0,
        y: 0
    };

    boundBox = document.getElementById('box').getBoundingClientRect();
    boundBoxX = boundBox.width;
    boundBoxY = boundBox.height;

    if (obj) {
        dragobj = rel(obj.id);
        document.onmousedown = startMove;
        document.onmouseup = drop;
        document.onmousemove = moving;
    }

    function rel(ob) {
        if (ob) {
            return document.getElementById(ob)
        } else {
            return null
        }
    }

    function startMove(e) {
        if (dragobj) {
            getCursorPos(e);
            dragobj.className = "moving";
            i1 = cursor.x - dragobj.offsetLeft;
            h1 = cursor.y - dragobj.offsetTop;
        }
    }

    function drop() {
        if (dragobj) {
            dragobj.className = "move";
            dragobj = null;
        }
    }

    function getCursorPos(e) {
        e = e || window.event;
        if (e.pageX || e.pageY) {
            cursor.x = e.pageX;
            cursor.y = e.pageY;
        } else {
            var de = document.documentElement;
            var db = document.body;
            cursor.x = e.clientX +
                (de.scrollLeft || db.scrollLeft) - (de.clientLeft || 0);
            cursor.y = e.clientY +
                (de.scrollTop || db.scrollTop) - (de.clientTop || 0);
        }
        return cursor;
    }

    function moving(e) {
        getCursorPos(e);
        if (dragobj) {
            console.log("Cursor: " + cursor.x, cursor.y);
            console.log("BoundBox: " + boundBoxX, boundBoxY);
            oLeft = cursor.x - i1;
            oRight = boundBoxX - (cursor.x - i1 + dragobj.offsetWidth);
            oTop = cursor.y - h1;
            oBottom = boundBoxY - (cursor.y - h1 + dragobj.offsetHeight);

            if (oLeft > 0 && oRight > 0) {
                dragobj.style.left = oLeft + 'px';
            }
            if (oTop > 0 && oBottom > 0) {
                dragobj.style.top = oTop + 'px';
            }

            console.log("Obj: " + oLeft, oRight, oTop, oBottom);

        }
    }
}

window.addEventListener('load', doFirst)