const red = document.querySelector(".red");
const cyan = document.querySelector(".cyan");
const violet = document.querySelector(".violet");
const orange = document.querySelector(".orange");
const pink = document.querySelector(".pink");

const center = document.querySelector(".center");

// console.log(window.getComputedStyle(red).backgroundColor);

const getBGColor = (selectedElement) => {
  return window.getComputedStyle(selectedElement).backgroundColor;
};
const getCenterColor = () => {
  return window.getComputedStyle(center).backgroundColor;
};

// var color = getBGColor(pink);

// pink.addEventListener("mouseenter", () => {
//   center.style.background = color;
// });

const magicColorChanger = (element, color) => {
  return element.addEventListener("mouseenter", () => {
    center.style.background = color;
  });
};

magicColorChanger(red, getBGColor(red));
magicColorChanger(cyan, getBGColor(cyan));
magicColorChanger(violet, getBGColor(violet));
magicColorChanger(orange, getBGColor(orange));
magicColorChanger(pink, getBGColor(pink));


const magicColorleaver = (element, color) => {
  return element.addEventListener("mouseleave", () => {
    center.style.background = color;
  });
};

magicColorleaver(cyan, getCenterColor());
magicColorleaver(red, getCenterColor());
magicColorleaver(violet, getCenterColor());
magicColorleaver(orange, getCenterColor());
magicColorleaver(pink, getCenterColor());
