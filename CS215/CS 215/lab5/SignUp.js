function SignUpForm(){ 
	var result = true;
	var passCheck = true;
	var a = document.forms.SignUp.email.value;
	var b = document.forms.SignUp.uname.value;
	var c = document.forms.SignUp.pswd.value;
	var d = document.forms.SignUp.pswdr.value;
	
	// javascript regular expression for valid email, username and password requirement
	
       
    var email_v = /^\w+@[a-zA-Z_]+?\.[a-zA-Z]{2,3}$/; 
	
	var uname_v = /^[a-zA-Z0-9_-]+$/;
	
	var pswd_v = /^(\S*)?\d+(\S*)?$/;
	
	
  // initialize email_msg, uname_msg, password_msg and pswdr_msg

    document.getElementById("email_msg").innerHTML = "";
	
	document.getElementById("uname_msg").innerHTML = "";
	document.getElementById("pswd_msg").innerHTML = "";
	 
	document.getElementById("pswdr_msg").innerHTML = "";
	
	
  
   	// if email is left empty or email format is wrong, error message displays above email field in red color   
	if (a==null || a =="" || email_v.test(a) == false){
			
		document.getElementById("email_msg").innerHTML="Email address empty or wrong format. example: username@somewhere.sth";
		result = false;
		}
		
	// add code here to validate username
	if (b==null || b=="" ||uname_v.test(b) == false){  
	    document.getElementById("uname_msg").innerHTML="Please enter the correct format for Username. (No leading or trailing spaces)";
	    result = false;
    }
	
	//add code here to validate password
	if (c==null || c=="" || pswd_v.test(c) == false){  
	    document.getElementById("pswd_msg").innerHTML="Please enter the password correctly(8 characters long, at least one non-letter)";
		result = false;
		passCheck = false;
	}
		
	// add code here to confirm password
	if(passCheck == false || c != d){
		document.getElementById("pswdr_msg").innerHTML="The confirmed password should be the same as the password above";
		result = false;
	}
	
	
	// User Information is displayed on the bottom if correct information is entered.		
	if (result == true)
    {
		document.getElementById("display_info").innerHTML="Email: " +a+"<br>"+"Username: "+b+"<br>"+"Password: " +c+"<br>"+"Confirm Password: "+d+"<br>";
		document.getElementById("SignUp").reset();
    }													
}

function ResetForm(){ 
   document.getElementById("email_msg").innerHTML ="";
	document.getElementById("uname_msg").innerHTML ="";
	document.getElementById("pswd_msg").innerHTML ="";	 
	document.getElementById("pswdr_msg").innerHTML ="";
}
