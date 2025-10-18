let score = 0;
let time = 60;
let hitValue = 0;

const scoreElement = document.getElementById("score");
const timeElement = document.getElementById("time");
const hitElement = document.getElementById("hit");
const bubblesElement = document.getElementById("bubbles");

function makeBubbles() {
    let bubbles = "";
    for (let i = 0; i < 100; i++) {
        let num = Math.floor(Math.random() * 10);
        bubbles += `<div class="bubble">${num}</div>`;
    }
    bubblesElement.innerHTML = bubbles;
}

function runTimer() {
    let timer = setInterval(() => {
        if (time > 0) {
            time--;
            timeElement.textContent = time;
        } else {
            clearInterval(timer);
            bubblesElement.innerHTML = `<h2>Game Over! Your score: ${score}</h2>`;
        }
    }, 1000);
}

function getNewHit() {
    hitValue = Math.floor(Math.random() * 10);
    hitElement.textContent = hitValue;
}

function increaseScore() {
    score += 10;
    scoreElement.textContent = score;
}

bubblesElement.addEventListener("click", (e) => {
    if (e.target.classList.contains("bubble")) {
        let clickedNum = Number(e.target.textContent);
        if (clickedNum === hitValue) {
            increaseScore();
            makeBubbles();
            getNewHit();
        }
    }
});

makeBubbles();
runTimer();
getNewHit();

