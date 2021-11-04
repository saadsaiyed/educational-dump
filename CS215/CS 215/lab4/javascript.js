function SignUpForm(){

    var warn="";
    var rt=true;
    var str_user_inputs = "";
    
    //-- validate email --
    
    var x=document.forms.SignUp.email.value;
    
    if (x==null || x==""){
        
        warn +="Email is empty. \n";
        rt=false;
      
    }
    else if(x.length > 60){
       warn += "Max length for email is 60 characters.\n"
       rt =false;
    }
    
    else{ // if everything is okay, then collect email 
       
        str_user_inputs +="Email: "+x+"\n";
    
    }
    
    //-- validate Username --
    
    var y = document.forms.SignUp.uname.value;

    if (y==null || y==""){
        
        warn +="Username is empty. \n";
        rt=false;
      
    }
    else if(y.length > 40){
       warn += "Max length for username is 40 characters.\n"
       rt =false;
    }
    
    else{ // if everything is okay, then collect email 
       
        str_user_inputs +="Username: "+y+"\n";
    
    }

    //-- validate password --

    var z = document.forms.SignUp.pswd.value;
    if (z==null || z==""){
        
        warn +="Password is empty. \n";
        rt=false;
      
    }
    else if(z.length < 8){
       warn += "Min length for Password is 8 characters.\n"
       rt =false;
    }
    
    else{ // if everything is okay, then collect email 
        str_user_inputs +="Password: "+z+"\n";
    }
    
    
    //-- Confirm password --

    var c=document.forms.SignUp.pswdr.value;
    
    if (c==null || c==""){
        
        warn +="Password confirmation is empty. \n";
        rt=false;
    }

    else if(c != z){
       warn += "Password doesn't match\n"
       rt =false;
    }
    
    else{ // if everything is okay, then collect email 
        str_user_inputs +="Confirmed Password: "+c+"\n";
    }
    
    //warning

    if(rt==false){
      
      alert(warn);
      return false;
    
    }
    else{
      
      // display the user inputs:
      alert(str_user_inputs);
    
      // when return true, we send an HTTP request 
      // and call the .php at the server side
      // Here, we return false, and do not send an HTTP request 
      // to the server, since we haven't learn PHP yet.  
      
      return false; // should be: return true; when using PHP
    
    }
    
}
    
    