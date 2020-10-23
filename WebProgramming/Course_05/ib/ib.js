function myFunction(elmnt) {
    if (elmnt.style.maxWidth != "none") {
	elmnt.style.maxWidth = "none";
	elmnt.style.maxHeight = "none";
    }
    else {
	elmnt.style.maxWidth = "200px";
	elmnt.style.maxHeight = "200px";
    }
}

function spoiler(elmnt) {
    if (elmnt.style.color != "white") {
	elmnt.style.color = "white";
    } else {
	elmnt.style.color = "black";
    }
}
