function SignUpForm(event){ 
    var elements = event.currentTarget;
    var result = true;
    var passCheck = true;
    var a = elements[2].value;
    var b = elements[3].value;
    var c = elements[4].value;
    var d = elements[5].value;
    var e = elements[0].value;
    var f = elements[1].value;

    var email_v = /^\w+@[a-zA-Z_]+?\.[a-zA-Z]{2,3}$/; 
    var name_v = /^[a-zA-Z0-9_-]+$/;
    var pswd_v = /^(\S*)?\d+(\S*)?\W+$/;
   
    document.getElementById("fname_msg").innerHTML ="";
    document.getElementById("lname_msg").innerHTML ="";
    document.getElementById("email_msg").innerHTML ="";
    document.getElementById("uname_msg").innerHTML ="";
    document.getElementById("pswd_msg").innerHTML ="";
    document.getElementById("pswdr_msg").innerHTML ="";
    
 
    if (e==null || e=="" ||!name_v.test(e)){  
	    document.getElementById("fname_msg").innerHTML="Please enter the correct format for First Name. (No leading or trailing spaces)";
	    result = false;
    }
    if (f==null || f=="" ||!name_v.test(f)){  
	    document.getElementById("lname_msg").innerHTML="Please enter the correct format for Last Name. (No leading or trailing spaces)";
	    result = false;
    }
    if (a==null || a==""||!email_v.test(a))
    {	   
	    document.getElementById("email_msg").innerHTML="Email is empty or invalid(example: cs215@uregina.ca)";
        result = false;
    }
    if (b==null || b=="" ||!name_v.test(b)){  
	    document.getElementById("uname_msg").innerHTML="Please enter the correct format for Username. (No leading or trailing spaces)";
	    result = false;
    }
	if (c==null || c=="" ||!pswd_v.test(c) || c.length < 8){  
	    document.getElementById("pswd_msg").innerHTML="Please enter the password correctly(8 characters long, at least one non-letter)";
		result = false;
		passCheck = false;
	}
	if(passCheck == false || c != d){
		document.getElementById("pswdr_msg").innerHTML="The confirmed password should be the same as the password above";
		result = false;
    }

    if(result == false )
    {    
        event.preventDefault();
    }
}

function ResetForm(event)
{
    document.getElementById("email_msg").innerHTML ="";
    document.getElementById("uname_msg").innerHTML ="";
    document.getElementById("pswd_msg").innerHTML ="";
    document.getElementById("pswdr_msg").innerHTML ="";
}