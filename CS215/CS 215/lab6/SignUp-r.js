window.onload = function(event){
    document.getElementById("SignUp").addEventListener("submit", SignUpForm, false);
    //add code here to call addEventListener for ResetForm() function
    document.getElementById("SignUp").addEventListener("reset", ResetForm, false);
}