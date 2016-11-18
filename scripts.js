/* global hljs */
var currURL, initialURL = "https://api.github.com/repos/ohnx/ccc/contents/solutions?ref=gh-pages", lastURL, lastPath;

function hGET(url, cb) {
    var xmlHttp = new XMLHttpRequest();
    xmlHttp.onreadystatechange = function() { 
        if (xmlHttp.readyState == 4 && xmlHttp.status == 200)
            cb(xmlHttp.responseText);
    };
    xmlHttp.open("GET", url, true); // true for asynchronous 
    xmlHttp.send(null);
}

var fmHandleClick = function() {
    var type = this.getAttribute("data-type");
    if (type == "dir") {
        lastURL = currURL;
        currURL = this.getAttribute("data-url");
        hGET(currURL, initCB);
    } else if (type == "file") {
        hGET(this.getAttribute("data-dlurl"), fetchFileA);
    }
};

function reRegisterListeners() {
    var classname = document.getElementsByClassName("fileman-link");

    for (var i = 0; i < classname.length; i++) {
        classname[i].addEventListener('click', fmHandleClick, false);
    }
}

var initCB = function(j) {
    var e = document.getElementById("fileman");
    var v = "";
    var t = JSON.parse(j);
    
    if (currURL != initialURL) {
        v += "<li data-path=\""+lastPath+"\" data-url=\""+lastURL+"\" data-type=\"dir\" class=\"fileman-link\">.</li>";
    }
    
    for (var i = 0; i < t.length; i++) {
        v += "<li data-url=\""+t[i].url+"\" data-type=\""+t[i].type+"\" "+(t[i].type=="file"?"data-dlurl=\""+t[i].download_url+"\"":"")+" class=\"fileman-link\">"+t[i].name+"</li>";
    }
    
    e.innerHTML = v;
    reRegisterListeners();
};

var fetchFileA = function(j) {
    var block = document.getElementById("file-contents");
    block.innerHTML = j
    hljs.highlightBlock(block);
};

(function() {
    currURL = initialURL;
    hGET(currURL, initCB);
})();