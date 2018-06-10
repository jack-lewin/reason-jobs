open Css;

let basePadding = px(3);
let w = px(400);

let container = style([
  display(flexBox),
  flexDirection(column),
  alignSelf(center),
  textAlign(center),
  marginTop(em(1.)),
  media(MasterStyle.aboveMobile, [
    marginTop(em(2.)),
  ])
]);

let nav = style([
  width(w),
  display(flexBox),
  flexDirection(row),
  alignSelf(center),
  justifyContent(center),
  fontSize(pt(13)),
  marginBottom(em(1.)),
  marginTop(em(1.)),
  media(MasterStyle.aboveMobile, [
    justifyContent(spaceAround),
    marginBottom(em(2.)),
    marginTop(em(2.)),
  ])
]);

let navItem = style([
  margin(px(0)),
  paddingLeft(em(1.)),
  paddingRight(em(1.)),
  media(MasterStyle.aboveMobile, [
    paddingLeft(zero),
    paddingRight(zero),
  ])
]);

let logoCSS = ([
  width(`percent(60.)),
  marginBottom(zero),
  media(MasterStyle.aboveMobile, [
    width(w),
    marginBottom(em(1.))
  ])
]);

let linkCSS = [
  color(hex("dd4b39")),
  cursor(`pointer),
  marginBottom(em(1.)),
  hover([
    opacity(0.9),
    textDecoration(underline)
  ])
];

let logo = style(merge([logoCSS, linkCSS]));
let link = style(linkCSS);
