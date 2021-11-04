function PlaylistForm(event){ 
    var result = true;
    var elements = event.currentTarget;
    var a = elements[0].value;

    var name_v = /^[a-zA-Z0-9_-]{0,15}$/;
   
    document.getElementById("plist_msg").innerHTML ="";

    if (a==null || a=="" ||!name_v.test(a)){  
	    document.getElementById("plist_msg").innerHTML="Please enter the correct format for Username. (No leading or trailing spaces)";
	    event.preventDefault();
    }
    document.getElementById("count_msg").innerHTML =a.length;
}

function charCount(event){
    document.getElementById("count_msg").innerHTML = "Total Characters: "+event.length+"\nRemaining Characters: "+ (15 - event.length);
}