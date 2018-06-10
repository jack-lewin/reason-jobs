open Css;

let emoji = [
  height(em(1.5)),
  width(em(1.5)),
  backgroundPosition(`percent(50.), `percent(50.)),
  backgroundRepeat(`noRepeat),
  backgroundSize(`contain),
  display(`inlineBlock),
  verticalAlign(`bottom),
];

let rocketImg = [
  background(url("https://twemoji.maxcdn.com/2/72x72/1f680.png")),
  backgroundImage(url("https://twemoji.maxcdn.com/2/svg/1f680.svg")),
];
let rocket = style(merge([emoji, rocketImg]));

let unicornImg = [
  background(url("https://twemoji.maxcdn.com/2/72x72/1f984.png")),
  backgroundImage(url("https://twemoji.maxcdn.com/2/svg/1f984.svg")),
];
let unicorn = style(merge([emoji, unicornImg]));

let loudspeakerImg = [
  background(url("https://twemoji.maxcdn.com/2/72x72/1f4e2.png")),
  backgroundImage(url("https://twemoji.maxcdn.com/2/svg/1f4e2.svg")),
  paddingRight(em(1.)),
];
let loudspeaker = style(merge([emoji, loudspeakerImg]));

let emailImg = [
  background(url("https://twemoji.maxcdn.com/2/72x72/2709.png")),
  backgroundImage(url("https://twemoji.maxcdn.com/2/svg/2709.svg")),
  paddingRight(em(1.)),
];
let email = style(merge([emoji, emailImg]));

let wwwImg = [
  background(url("https://twemoji.maxcdn.com/2/72x72/1f4bb.png")),
  backgroundImage(url("https://twemoji.maxcdn.com/2/svg/1f4bb.svg")),
  paddingRight(em(1.)),
];
let www = style(merge([emoji, wwwImg]));
