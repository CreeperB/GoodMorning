function download() {
    if(document.getElementById('text').innerHTML == ""){
        alert('請先輸入文字')
        return false
    }
    let box = document.getElementById('box')
    let canvas = document.createElement('canvas')
    let textText = document.getElementById('text').innerHTML
    let textX = document.getElementById('text').getBoundingClientRect().left - box.getBoundingClientRect().left;
    let textY = document.getElementById('text').getBoundingClientRect().top - box.getBoundingClientRect().top + 20;

    canvas.width = 300
    canvas.height = 157

    let ctx = canvas.getContext('2d')
    ctx.fillStyle = window.getComputedStyle(box, null).getPropertyValue('background-color')
    ctx.fillRect(0, 0, canvas.width, canvas.height)
    ctx.fillStyle = window.getComputedStyle(document.getElementById('text'), null).getPropertyValue('color')
    ctx.font = '20px Noto Sans'
    var lineHeight = ctx.measureText("M").width * 1.2;
    var lines = textText.split("\n");
    for (var i = 0; i < lines.length; ++i) {
        ctx.fillText(lines[i], textX, textY);
        textY += lineHeight;
    }

    let dataURL = canvas.toDataURL('image/jpeg')
    let a = document.createElement('a')
    a.href = dataURL
    a.download = 'image.jpg'
    a.click()
}

function changeTextInput() {
    console.log("changeTextInput")
    let text = document.getElementById('text')
    let text_input = document.getElementById('textInput')
    text.innerHTML = text_input.value
}

function blackBgWhiteWd(){
    let text = document.getElementById('text')
    let box = document.getElementById('box')
    text.style.color = 'white'
    box.style.backgroundColor = 'black'
}

function whiteBgBlackWd(){
    let text = document.getElementById('text')
    let box = document.getElementById('box')
    text.style.color = 'black'
    box.style.backgroundColor = 'white'
}

function blackBgGreenWd() {
    let text = document.getElementById('text')
    let box = document.getElementById('box')
    text.style.color = 'green'
    box.style.backgroundColor = 'black'
}

function redBgYellowWd() {
    let text = document.getElementById('text')
    let box = document.getElementById('box')
    text.style.color = 'yellow'
    box.style.backgroundColor = 'red'
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