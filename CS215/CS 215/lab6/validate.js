function SignUpForm(event){ 

    // This example treats all 4 input fields (Email, Username, Password, Confirm Password)
    // as elements of the event currentTarget.
    // Pay attention to SignUp-r.js since the form id is "SignUp".
    // You can also implement individual function to validate each input field
    // by modify the online lab6 website example "DOM2 Event Registration", 
    // therefore each input field is a function. For example, checkEmail(), CheckUsername(), CheckPswd(), CheckMatchPswd()




    var elements = event.currentTarget;

    //declare variable a for the email value
    var passCheck = true;
    var a = elements[0].value;
    var b = elements[1].value;
    var c = elements[2].value;
    var d = elements[3].value;


    // add code here to 
    // declare Username,Password and confirm 
    // Password as elements in event.curretTarget
    // for example: var b = elements[1].value
   
    
    var result = true;    
        
    // declare variables for valid input in regular expression for email, username and password

    var email_v = /^\w+@[a-zA-Z_]+?\.[a-zA-Z]{2,3}$/; 
    var uname_v = /^[a-zA-Z0-9_-]+$/;
    var pswd_v = /^(\S*)?\d+(\S*)?$/;
   
   
    document.getElementById("email_msg").innerHTML ="";
    document.getElementById("uname_msg").innerHTML ="";
    document.getElementById("pswd_msg").innerHTML ="";
    document.getElementById("pswdr_msg").innerHTML ="";
    
 
    //email can not be empty or wrong format
    if (a==null || a==""||!email_v.test(a))
    {	   
	    document.getElementById("email_msg").innerHTML="Email is empty or invalid(example: cs215@uregina.ca)";
        result = false;
    }

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

    //prevent form to be submitted if one of above field is invalid		
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