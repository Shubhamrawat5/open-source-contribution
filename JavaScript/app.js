const Quote= document.querySelector('.quote');
const Quoter = document.querySelector('.person');
const button = document.querySelector('.btn');
const an =[{
Quote:"Honest Is the Very Expensive Gift Make Sure You I s Correct",
Quoter:'Warren Buffet'

},
{
    Quote:"Honest Is the Very Expensive Gift Make Sure You I s Correct2",
    Quoter:'Warren Buffet2'
    
},{
    Quote:"Honest Is the Very Expensive Gift Make Sure You I s Correct3",
Quoter:'Warren Buffet3'

}
];

button.addEventListener('click',function(){
    let random = Math.floor(Math.random()*an.length);
    Quote.innerText=an[random].Quote;
    Quoter.innerText=an[random].Quoter;

})

// const butn = document.querySelector('.btn');
// const psn = document.querySelector('.person');
// const cot = document.querySelector('.text');
// const quotes =[{
//     cot:'Hi This ME',
//     psn:'Bsdk'

// },
// {
//     cot:'this is 2',
//     psn:'BSDK 2'
// },{
//     cot:"This is Three",
//     psn: "BSDK3"
// }
// ];
// butn.addEventListener('click',function(){
//     let random = Math.floor(Math.random()*quotes.length);
//     cot.innerText=quotes[random].cot;
//     psn.innerText=quotes[random].cot;
// })