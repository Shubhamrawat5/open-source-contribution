// Password for TVDB - hayaomiyazaki
populateFilms();
let movies;

function movieIterator(movies) {
    console.log(movies.length);
    let nextIndex = 0;
    return {
        next: function () {
            return nextIndex < movies.length ?
                { value: movies[nextIndex++], done: false } :
                { done: true };
        }
    }
}

function generateHtml(movieInfo) {
    let html = `
      <h2 class="movieTitle">${movieInfo.title} (${movieInfo.original_title_romanised})</h2>
      <p>${movieInfo.description}</p>
      <p class="strongText"><strong>Directed By : ${movieInfo.director}<strong></p>
      <p class="strongText">Rotten Tomatoes Score: ${movieInfo.rt_score}%</p>
      <p class="strongText">Run Time: ${movieInfo.running_time} minutes</p>
      <p class="strongText">Released in : ${movieInfo.release_date}</p>
    `
    document.querySelector('.information').innerHTML = html;
}


function populateFilms() {
    let url = "https://ghibliapi.herokuapp.com/films";
    fetch(url).then((response) => {
        console.log('Inside first then');
        return response.json();
    })
        .then((data) => {
            movies = data;
            const moviesIntance = movieIterator(movies);
            let i = 0;
            setBackGround(i);
            generateHtml(moviesIntance.next().value);
            document.getElementById('nextMovie').addEventListener('click', () => {
                setBackGround(++i);
                document.querySelector('.information').innerHTML = "";
                let movieInfo = moviesIntance.next();
                if (!movieInfo.done) {
                    generateHtml(movieInfo.value);
                }
                else {
                    document.querySelector('.information').innerHTML = "That's all there is.";
                    document.getElementById('nextMovie').innerHTML = 'Very Good.'
                }
            });
        });
}

function setBackGround(index){
    document.body.style.background = `linear-gradient(0deg, rgba(0, 0, 0, 0.5), rgba(20, 0, 0, 0.5)), url(bg/${index}.jpg)`;
    document.body.style.backgroundSize = 'cover';
    document.body.style.backgroundPosition = 'center';
}

