function sorting(M_Name) {
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
                    to_show += mainGrid(json_result);
                }
            } 
            else {
                to_show = "<h1>something went wrong </h1>";
            }

            document.getElementById("mainGridContainer").innerHTML=to_show;
        }
    }
    xmlhttp.open("GET","php/ajaxSorting.php?M_Name="+M_Name ,true);
    xmlhttp.send();
}

function mainGrid(json_result){
    var to_show1    = "";
    var Movie_ID    = json_result[0];
    var Movie_Name  = json_result[1];
    var Poster      = json_result[2];
    var Director    = json_result[3];
    var Cast        = json_result[4];
    var Genre       = json_result[6];
    var Year        = json_result[8];
    var Rating      = json_result[9];

    to_show1 += '<div class="grid-item">';
        to_show1 += '<a href="php/watchedMovie.php?movieID=' + Movie_ID + '">';
            to_show1 += '<img src = "posters/' + Poster + '.jpg" alt = "' + Movie_Name + '">';
            to_show1 += '<h3>' + Movie_Name + '(' + Year + ')</h3>';
        to_show1 += '</a>';
    to_show1 += '</div>';
        to_show1 += '<div class="grid-item">';
        to_show1 += '<h4>' + Genre + '</h4>';
        to_show1 += '<h4>General Information</h4>';
        to_show1 += 'Director : ' + Director + '<br/><br/>';
        to_show1 += 'Cast : ' + Cast + '<br/><br/>';
        to_show1 += 'Rating : ' + Rating + ' / 10';
        to_show1 += '<input type="hidden" name="movie_id" value = "' + Movie_ID + '"/>';
        to_show1 += '<table style = "float: right;">';
            to_show1 += '<tr><td><button onclick="watchlistDropdown(' + Movie_ID + ')">Add to Watchlist</button></td></tr>';
            to_show1 += '<tr><td><div id="dropdown' + Movie_ID + '"></div></td></tr>';
        to_show1 += '</table>';
    to_show1 += '</div>';

    return to_show1;
}