function play() {
    var audio = document.getElementById("moo-sound");
    audio.play();
}

var text = "正在等待牛乳運送中...";
var i = 0;
function updateText() {
    if (i < text.length) {
        document.getElementById("text").innerHTML += text.charAt(i);
        i++;
        if(i == text.length){
            setTimeout(updateText, 800);
        }
        else if(i >= text.length - 3){
            setTimeout(updateText, 400);
        }
        else{
            setTimeout(updateText, 100);
        }
    }
    else{
        i = 0;
        document.getElementById("text").innerHTML = "";
        setTimeout(updateText, 100);
    }
}
window.addEventListener("load", updateText);