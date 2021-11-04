function watchlistDropdown(dropdownID) {
    if (window.XMLHttpRequest) {
        // code for IE7+, Firefox, Chrome, Opera, Safari
        xmlhttp=new XMLHttpRequest();
    } else {  // code for IE6, IE5
        xmlhttp=new ActiveXObject("Microsoft.XMLHTTP");
    }

    xmlhttp.onreadystatechange = function() {
        if (this.readyState==4 && this.status==200) {
            var to_show = "";
            var results = JSON.parse(this.responseText)
            if (results.length > 0){
                for (var i = 0; i < results.length; i++) 
                {
                    var json_result = results[i];
                   // to_show += "<button id = '"; to_show += dropdownID + i; to_show += "'>"; 
                    to_show += "<button onclick = 'addToWatchlist("; 
                    to_show += '"'; to_show += json_result[0]; to_show += '"'; to_show += ", " + dropdownID + ")'>"; 
                    to_show += json_result[2];
                    to_show += "</button><br/>";
                }
            }
            else {
                to_show = "Noresult found";
            }
            var getID = "dropdown" + dropdownID;
            console.log(getID);
            document.getElementById(getID).innerHTML = to_show;
            setTimeout(function(){document.getElementById(getID).disabled = true;},10000);
        }
    }
    xmlhttp.open("GET","php/ajaxAddWatchlistButton.php", true);
    xmlhttp.send();
}

function addToWatchlist(WID, MID){
    console.log("INSIDE" + WID + MID);
    if (window.XMLHttpRequest) {
        // code for IE7+, Firefox, Chrome, Opera, Safari
        xmlhttp=new XMLHttpRequest();
    } else {  // code for IE6, IE5
        xmlhttp=new ActiveXObject("Microsoft.XMLHTTP");
    }

    xmlhttp.onreadystatechange = function() {
        if (this.readyState==4 && this.status==200) {
            var to_show = "";

            var results = JSON.parse(this.responseText)
            if (results === 1){
                to_show = "Successful";
            }
            else {
                to_show = "Error Adding Movie, check if it already exists";
            }
            //var getID = "dropdown" + dropdownID;
            console.log(to_show);
            alert(to_show);
            //document.getElementById(getID).innerHTML = to_show;
        }
    }
    get_Link = "WID=" + WID + "&MID=" + MID;
    xmlhttp.open("GET","php/ajaxAddWatchlistMovie.php?"+get_Link, true);
    xmlhttp.send();
}