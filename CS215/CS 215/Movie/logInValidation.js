function SignUpForm(event){
    var elements = event.currentTarget;
    var a = elements[0].value;
    var c = elements[1].value;
    
    var result = true;    
    
    var email_v = /^\w+@[a-zA-Z_]+?\.[a-zA-Z]{2,3}$/; 
    var pswd_v = /^(\S*)?\d+(\S*)?\W+$/;
   
    document.getElementById("email_msg").innerHTML ="";
    document.getElementById("pswd_msg").innerHTML ="";
    
    if (a==null || a==""||!email_v.test(a))
    {	   
	    document.getElementById("email_msg").innerHTML="Email is empty or invalid(example: cs215@uregina.ca)";
        result = false;
    }
	if (c==null || c=="" || pswd_v.test(c) == false || c.length < 8){  
	    document.getElementById("pswd_msg").innerHTML="Please enter the password correctly(8 characters long, at least one non-letter)";
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
    document.getElementById("pswd_msg").innerHTML ="";
}