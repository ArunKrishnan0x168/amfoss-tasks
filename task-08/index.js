//Author : Arun Krishnan(AM.EN.U4CSE22004)

console.log("Arun Krishnan")

//Creating all the audio objects
let crash = new Audio("sounds/crash.mp3")
let kick_bass = new Audio("sounds/kick-bass.mp3")
let snare = new Audio("sounds/snare.mp3")
let tom_1 = new Audio("sounds/tom-1.mp3")
let tom_2 = new Audio("sounds/tom-2.mp3")
let tom_3 = new Audio("sounds/tom-3.mp3")
let tom_4 = new Audio("sounds/tom-4.mp3")

//adding event listeners to keys
let  w = document.getElementById("w");
let  a = document.getElementById("a");
let  s = document.getElementById("s");
let  d = document.getElementById("d");
let  j = document.getElementById("j");
let  k = document.getElementById("k");
let  i = document.getElementById("i");

w.addEventListener("click",()=>{
    crash.play();
})

a.addEventListener("click",()=>{
    kick_bass.play();
})

s.addEventListener("click",()=>{
    snare.play();
})

d.addEventListener("click",()=>{
    tom_1.play();
})

j.addEventListener("click",()=>{
    tom_2.play();
})

k.addEventListener("click",()=>{
    tom_3.play();
})

l.addEventListener("click",()=>{
    tom_4.play();
})