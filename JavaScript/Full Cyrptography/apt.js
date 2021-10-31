const alphabet = ["A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"]; //, "1", "2", "3", "4", "5", "6", "7", "8", "9", "0"
const alp_alt = ["A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"];
const alphabet_morse = [".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----.", "-----"];
$(document).ready(function () {
    $("#convert").click(function () {
        var books = $('#techniques-cont');
        if (document.getElementById("caesar").selected) {
            const entry = $("#inp").val();
            const step = $("#spsize").val();
            caesar(entry, step);
        } else if (document.getElementById("basic_slide").selected) {
            const entry = $("#inp").val();
            const step = $("#spsize").val();
            basic_slide(entry, step);
        } else if (document.getElementById("subs_cipher").selected) {
            const entry = $("#inp").val();
            const step = $("#spsize").val();
            console.log("Hey");
            sub_key = document.getElementById("subs_key").value;
            let alphabet_temp = sub_key.split("");
            subs_cipher(entry, step, alphabet_temp, sub_key);
        } else if (document.getElementById("affine_cipher").selected) {
            const entry = $("#inp").val();
            const val_a = Number($("#inp_a").val());
            const val_b = Number($("#inp_b").val());
            affine_cipher(entry, val_a, val_b);
        } else if (document.getElementById("pig_latin").selected) {
            let entry = $("#inp").val();
            entry = entry.split(" ");
            pig_latin(entry);
        } else if (document.getElementById("morse_d").selected) {
            let entry = $("#inp").val();
            entry = entry.split(" ");
            morse_decode(entry);
        } else if (document.getElementById("morse_e").selected) {
            let entry = $("#inp").val();
            morse_encode(entry);
        } else if (document.getElementById("rot13").selected) {
			      let entry = $("#inp").val();
			      rot13(entry);
		    } else if (document.getElementById("base64").selected) {
			      let entry = $("#inp").val();
			      base64(entry);
		    }
    });
});
$(document).ready(function () {
    if (document.getElementById("subs_cipher").selected) {
        $('#subs_key').css('display', 'inline');
        $('#spsize').css('display', 'none');
        $('#info').css('display', 'none');
        $("#inp_a").css('display', 'none');
        $("#inp_b").css('display', 'none');
    } else if (document.getElementById("affine_cipher").selected) {
        $('#info').css('display', 'block');
        $("#inp_a").css('display', 'inline');
        $("#inp_b").css('display', 'inline');
        $('#spsize').css('display', 'none');
    } else if (document.getElementById("pig_latin").selected) {
        $('#subs_key').css('display', 'none');
        $('#spsize').css('display', 'none');
        $('#info').css('display', 'none');
        $("#inp_a").css('display', 'none');
        $("#inp_b").css('display', 'none');
    } else if (document.getElementById("morse_d").selected) {
        $('#subs_key').css('display', 'none');
        $('#spsize').css('display', 'none');
        $('#info').css('display', 'none');
        $("#inp_a").css('display', 'none');
        $("#inp_b").css('display', 'none');
    } else if (document.getElementById("morse_e").selected) {
        $('#subs_key').css('display', 'none');
        $('#spsize').css('display', 'none');
        $('#info').css('display', 'none');
        $("#inp_a").css('display', 'none');
        $("#inp_b").css('display', 'none');
    } else if(document.getElementById("rot13").selected) {
        $('#subs_key').css('display', 'none');
        $('#spsize').css('display', 'none');
        $('#info').css('display', 'none');
        $("#inp_a").css('display', 'none');
        $("#inp_b").css('display', 'none');
    } else if (document.getElementById("base64").selected) {
        $('#subs_key').css('display', 'none');
        $('#spsize').css('display', 'none');
        $('#info').css('display', 'none');
        $("#inp_a").css('display', 'none');
        $("#inp_b").css('display', 'none');
    } else {
        $('#subs_key').css('display', 'none');
        $('#spsize').css('display', 'inline');
        $('#info').css('display', 'none');
        $("#inp_a").css('display', 'none');
        $("#inp_b").css('display', 'none');
    }
});

function eventlisten(object) {
    object.addEventListener("keydown", function (event) {
        if (event.keyCode == 13) {
            //event.preventDefault();
            document.getElementById("convert").click();
        }
    });
}

let inp = document.getElementById("inp");
let spsize = document.getElementById("spsize");
eventlisten(inp);
eventlisten(spsize);



function caesar(rawtext, stepsize) {
    $("#output").empty();
    rawtext = rawtext.toUpperCase();
    stepsize = Number(stepsize);
    if (stepsize > alphabet.length) {
        stepsize = stepsize - alphabet.length + 1;
    }
    document.getElementById("spsize").value = stepsize;
    //console.log(rawtext, stepsize);
    if (stepsize >= 0) {
        for (ia in rawtext) {
            if (rawtext[ia] === " ") {
                output = "_";
                $("#output").append(output);
            }
            //console.log("In the for loop");
            for (ja = 0; ja < alphabet.length; ja++) {
                if (rawtext[ia] === alphabet[ja]) {
                    //console.log("In if" , j > alphabet.length - stepsize, j , alphabet.length , stepsize);
                    if (ja >= alphabet.length - stepsize) {
                        let alt = (ja + 1) - alphabet.length + (stepsize - 1);
                        console.log(alt);
                        $("#output").append(alphabet[alt]);
                    } else {
                        //caesar_encrypted.push(alphabet[j + stepsize]);
                        $("#output").append(alphabet[ja + stepsize]);
                        //console.log(j, alphabet[j + stepsize]);
                    }

                }

            }
        }
    } else {
        $("#output").html("You can't use negative numbers in the Caesar Technique");
        $("#output").append("\nSo write a positive number...");
        setTimeout(function () {
            do {
                stepsize = parseInt(window.prompt("Please write number greater than -1..."));
                document.getElementById("spsize").value = stepsize;
                $("#output").html("You need to restart the program by clicking 'Convert'");
            } while (stepsize < 0);
        }, 1500);

    }

}

function basic_slide(rawtext, stepsize) {
    $("#output").empty();
    rawtext = rawtext.toUpperCase();
    stepsize = Number(stepsize);
    if (Math.abs(stepsize) > alphabet.length) {
        stepsize = stepsize - alphabet.length + 1;
    }
    document.getElementById("spsize").value = stepsize;
    //console.log(rawtext, stepsize);
    for (ib in rawtext) {
        if (rawtext[ib] === " ") {
            output = "_";
            $("#output").append(output);
        }
        //console.log("In the for loop");
        for (jb = 0; jb < alphabet.length; jb++) {
            if (rawtext[ib] === alphabet[jb]) {
                //console.log("In if" , j > alphabet.length - stepsize, j , alphabet.length , stepsize);
                if (jb >= alphabet.length - stepsize) {
                    let alt = (jb + 1) - alphabet.length + (stepsize - 1);
                    console.log(alt);
                    $("#output").append(alphabet[alt]);
                } else if (jb > stepsize) {
                    let alt = (-stepsize - jb) * -1;
                    console.log(alt);
                    $("#output").append(alphabet[alt]);
                } else {
                    //caesar_encrypted.push(alphabet[j + stepsize]);
                    $("#output").append(alphabet[jb + stepsize]);
                    //console.log(j, alphabet[j + stepsize]);
                }

            }
        }
    }

}

function subs_cipher(rawtext, stepsize, alphabet_temp, sub_key) {
    //console.log(sub_key);
    $("#output").empty();
    if (sub_key === "") {
        do {
            sub_key = window.prompt("Please enter a valid key");
            document.getElementById("subs_key").value = sub_key;
        } while (sub_key === "")
    } else {
        for (ic in rawtext) {
            if (rawtext[ic] === " ") {
                output = "_";
                $("#output").append(output);
            }
            for (jc = 0; jc < alphabet.length; jc++) {
                //console.log(ic , jc);
                if (rawtext[ic].toUpperCase() === alphabet[jc]) {
                    output = alphabet_temp[jc];
                    //console.log(output);
                    $("#output").append(output);
                }
            }
        }

    }
}

function affine_cipher(rawtext, inp_a, inp_b) {
    $("#output").empty();
    for (id in rawtext) {
        if (rawtext[id] === " ") {
            output = "_";
            $("#output").append(output);
        }
        //console.log(rawtext[id], id);
        if (rawtext[id] === " ") {
            output = "_";
        } else {
            temp = Number(alphabet.indexOf(rawtext[id].toUpperCase()));
            //console.log(temp);
            out_temp = (inp_a * temp + inp_b) % alphabet.length;
            console.log(out_temp, inp_a, inp_b, temp);
            if (out_temp > alphabet.length) {
                out_temp = out_temp % alphabet.length;
            }
            console.log(out_temp, temp);
            output = alphabet[out_temp];
        }
        //console.log(output);
        $("#output").append(output);
    }
}

function pig_latin(rawtext) {
    $("#output").empty();
    for (ie in rawtext) {
        temp_inp = rawtext[ie].split("");
        temp = temp_inp[0];
        //console.log(temp);
        temp_inp.shift();
        //console.log(temp_inp);
        temp_inp.push(temp);
        temp_out = temp_inp.join('');
        output = temp_out + "ay";
        $("#output").append(output);
    }
}

function morse_decode(rawtext) {
    $("#output").empty();
    for (ig in rawtext) {
        for (jg in alphabet_morse) {
            if (rawtext[ig] === alphabet_morse[jg]) {
                output = alphabet[jg];
                $("#output").append(output);
            }
        }
    }
}

function morse_encode(rawtext) {
    $("#output").empty();
    console.log(rawtext);
    for (ih in rawtext) {
        for (jh in alphabet) {
            if (rawtext[ih].toUpperCase() === alphabet[jh]) {
                output = alphabet_morse[jh];
                $("#output").append(output + " ");
            }
        }
    }
}

function rot13(rawtext) {
  $("#output").empty();
	for (ii in rawtext) {
		for(ji in alp_alt) {
			if (rawtext[ii].toUpperCase() === alp_alt[ji]) {
				ji = parseInt(ji);
					console.log(alp_alt.length);
					if (ji >= alp_alt.length - 13) {
						console.log("hey");
						ji = (ji + 13) - alp_alt.length;
						//console.log(ji);
						output = alp_alt[ji];
						//console.log(output);
						$("#output").append(output);
					}
					else {
            console.log("in else");
						ji = ji + 13;
						//output = alp_alt[ji];
						$("#output").append(alp_alt[ji]);
					}
			}
		}
	}
}

function base64(rawtext) {
  $("#output").empty();
  output = (/*atob(btoa(a))*/"Decoded: " + rawtext + "<br>Encoded: " + btoa(rawtext));
  $("#output").append(output);
}

function key_control() {
    if (document.getElementById("subs_cipher").selected) {
        $('#subs_key').css('display', 'inline');
        $('#spsize').css('display', 'none');
        $('#info').css('display', 'none');
        $("#inp_a").css('display', 'none');
        $("#inp_b").css('display', 'none');
    } else if (document.getElementById("affine_cipher").selected) {
        $('#info').css('display', 'block');
        $("#inp_a").css('display', 'inline');
        $("#inp_b").css('display', 'inline');
        $('#spsize').css('display', 'none');
    } else if (document.getElementById("pig_latin").selected) {
        $('#subs_key').css('display', 'none');
        $('#spsize').css('display', 'none');
        $('#info').css('display', 'none');
        $("#inp_a").css('display', 'none');
        $("#inp_b").css('display', 'none');
    } else if (document.getElementById("morse_d").selected) {
        $('#subs_key').css('display', 'none');
        $('#spsize').css('display', 'none');
        $('#info').css('display', 'none');
        $("#inp_a").css('display', 'none');
        $("#inp_b").css('display', 'none');
    } else if (document.getElementById("morse_e").selected) {
        $('#subs_key').css('display', 'none');
        $('#spsize').css('display', 'none');
        $('#info').css('display', 'none');
        $("#inp_a").css('display', 'none');
        $("#inp_b").css('display', 'none');
    } else if (document.getElementById("rot13").selected) {
        $('#subs_key').css('display', 'none');
        $('#spsize').css('display', 'none');
        $('#info').css('display', 'none');
        $("#inp_a").css('display', 'none');
        $("#inp_b").css('display', 'none');
    } else if (document.getElementById("base64").selected) {
        $('#subs_key').css('display', 'none');
        $('#spsize').css('display', 'none');
        $('#info').css('display', 'none');
        $("#inp_a").css('display', 'none');
        $("#inp_b").css('display', 'none');
    } else {
        $('#subs_key').css('display', 'none');
        $('#spsize').css('display', 'inline');
        $('#info').css('display', 'none');
        $("#inp_a").css('display', 'none');
        $("#inp_b").css('display', 'none');
    }

}
