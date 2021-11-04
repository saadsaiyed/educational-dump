function SignUpForm(event){ 
    var elements = event.currentTarget;
    var result = true;
    var passCheck = true;
    var a = elements[0].value;
    var b = elements[1].value;
    var c = elements[2].value;
    var d = elements[3].value;
    var e = elements[4].value;
    var f = elements[5].value;
    var g = elements[6].value;
    var h = elements[7].value;
    var i = elements[8].value;

    var email_v = /^\w+@[a-zA-Z_]+?\.[a-zA-Z]{2,3}$/; 
    var name_v = /^[a-zA-Z0-9_-]+$/;
    var pswd_v = /^(\S*)?\d+(\S*)?\W+$/;
    var dob_v = /^[0-9()+-]+$/;
   
    document.getElementById("fname_msg").innerHTML ="";
    document.getElementById("lname_msg").innerHTML ="";
    document.getElementById("dob_msg").innerHTML ="";
    document.getElementById("phone_msg").innerHTML ="";
    document.getElementById("email_msg").innerHTML ="";
    document.getElementById("uname_msg").innerHTML ="";
    document.getElementById("pswd_msg").innerHTML ="";
    document.getElementById("pswdr_msg").innerHTML ="";
    document.getElementById("photo_msg").innerHTML ="";

    if (a==null || a=="" ||!name_v.test(a)){  
	    document.getElementById("fname_msg").innerHTML="Please enter the correct format for First Name. (No leading or trailing spaces)";
	    result = false;
    }
    if (b==null || b=="" ||!name_v.test(b)){  
	    document.getElementById("lname_msg").innerHTML="Please enter the correct format for Last Name. (No leading or trailing spaces)";
	    result = false;
    }
    if (c==null || c==""||!dob_v.test(c)||c.length>10)
    {	   
	    document.getElementById("dob_msg").innerHTML="Please enter the correct format for DOB(example: 2000-12-31 or yyyy-mm-dd)";
	    result = false;
    }
    if (d==null || d==""||!dob_v.test(d)||d.length<10||d.length>13)
    {	   
        document.getElementById("phone_msg").innerHTML="Please enter the correct format for Phone Number(example: 3068075776)";
        result = false;
    }
    if (e==null || e==""||!email_v.test(e))
    {	   
	    document.getElementById("email_msg").innerHTML="Email is empty or invalid(example: cs215@uregina.ca)";
	    result = false;
    }
    if (f==null || f=="" ||!name_v.test(f)){  
	    document.getElementById("uname_msg").innerHTML="Please enter the correct format for Username. (No leading or trailing spaces)";
	    result = false;
    }
	if (g==null || g=="" ||!pswd_v.test(g) || g.length < 8){  
	    document.getElementById("pswd_msg").innerHTML="Please enter the password correctly(8 characters long, at least one non-letter)";
		result = false;
		passCheck = false;
	}
	if(passCheck == false || g != h){
		document.getElementById("pswdr_msg").innerHTML="The confirmed password should be the same as the password above";
		result = false;
    }
    if (i==null || i==""){  
        document.getElementById("photo_msg").innerHTML="Please upload a photo";
        result = false;
    }

    if(result == false )
    {    
        event.preventDefault();
    }
}

function ResetForm(event)
{
    document.getElementById("fname_msg").innerHTML ="";
    document.getElementById("lname_msg").innerHTML ="";
    document.getElementById("email_msg").innerHTML ="";
    document.getElementById("uname_msg").innerHTML ="";
    document.getElementById("pswd_msg").innerHTML ="";
    document.getElementById("pswdr_msg").innerHTML ="";
}
