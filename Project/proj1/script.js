var counter = document.getElementsByClassName("counter");
var followers = document.querySelector(".followers");
let count = 1000;
setInterval(() => {
  if (count > 0) {
    count--;
    counter[0].innerHTML = count;
  }
}, 1);
setTimeout(() => {
  followers.innerHTML = "INFINITE";
}, 6700);
