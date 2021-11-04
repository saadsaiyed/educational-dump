document.getElementById("1").addEventListener("mouseover", change);
document.getElementById("2").addEventListener("mouseover", change);
document.getElementById("3").addEventListener("mouseover", change);

function change(event){
    document.getElementById("output").innerHTML = "X: " + event.clientX + " Y: " + event.clientY;
    var currentID;
    if(event.clientY >= 8 && event.clientY <= 107){
        currentID = 1;
        document.getElementById("output").style.backgroundColor = "lightblue" ;
    }
    if(event.clientY >= 108 && event.clientY <= 207){
        currentID = 2;
        document.getElementById("output").style.backgroundColor = "lightgreen" ;
    }
    if(event.clientY >= 208 && event.clientY <= 307){
        currentID = 3;
        document.getElementById("output").style.backgroundColor = "red" ;
    }
}