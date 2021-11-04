function searchResult(str) {
    if (str.length==0) {
        document.getElementById("livesearch").innerHTML="";
        document.getElementById("livesearch").style.border="0px";
        return;
    }
    if (window.XMLHttpRequest) {
        // code for IE7+, Firefox, Chrome, Opera, Safari
        xmlhttp=new XMLHttpRequest();
    } else {  // code for IE6, IE5
        xmlhttp=new ActiveXObject("Microsoft.XMLHTTP");
    }
    xmlhttp.onreadystatechange=function() {
        if (this.readyState==4 && this.status==200) {
            var to_show = "";
            var results = JSON.parse(this.responseText)
            if (results.length > 0){
                for (var i = 0; i < results.length; i++) 
                {
                    var json_result = results[i];
                    to_show += json_result[0];
                    to_show += "<br/>";
                }
            } 
            else {
                to_show = "There is no user name starts with '"+letter+"'";
            }

            document.getElementById("livesearch").innerHTML=to_show;
            document.getElementById("livesearch").style.border="1px solid #A5ACB2";
        }
    }
    xmlhttp.open("GET","php/ajaxSearch.php?search="+str ,true);
    xmlhttp.send();
}