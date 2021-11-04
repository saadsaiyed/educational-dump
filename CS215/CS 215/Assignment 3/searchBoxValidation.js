function SearchBox(event){ 
    var elements = event.currentTarget;
    var a = elements[0].value;
    console.log("a = " + a);
    var result = true;

    if (a==null || a==""){  
	    document.getElementById("srch_msg").innerHTML="Please enter something";
	    event.preventDefault();
    }
}