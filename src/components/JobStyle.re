open Css;
/*
backgroundColor(rgba(239, 134, 122, 0.25)),
boxShadow(~x=px(1), ~blur=px(1), rgba(0, 0, 0, 0.1)),
*/

let title = style([
  marginBottom(zero),
]);
let detailTitle = style([
  fontSize(em(1.5)),
  marginBottom(em(0.5)),
]);

let jobCSS = detail => [
  borderBottomColor(transparent),
  borderLeftColor(transparent),
  borderRightColor(transparent),
  borderStyle(solid),
  borderTopColor(hex("ccc")),
  borderWidth(px(1)),
  color(rgb(35, 50, 57)),
  display(flexBox),
  flexDirection(column),
  paddingBottom(em(0.5)),
  paddingLeft(em(1.5)),
  paddingRight(em(1.5)),
  paddingTop(em(0.)),
  lastChild([
    borderBottomColor(hex("ccc")),
    marginBottom(em(3.)),
  ]),
  selector(":hover ." ++ title, [
    textDecoration(underline),
  ]),
  media(MasterStyle.aboveMobile, [
    flexDirection(detail ? column : row),
  ]),
];
let jobHover = [
  hover([
    cursor(`pointer),
  ]),
];
let jobHighlighted = [
  backgroundColor(rgba(239, 134, 122, 0.1)),
];
let job = (detail, highlighted) => style(merge([
  jobCSS(detail),
  detail ? [] : jobHover,
  (!detail && highlighted) ? jobHighlighted : []
]));

let main = style([
  flexGrow(1),
]);

let info = style([
  important(textDecoration(none)),
  display(`flex),
  flexWrap(wrap),
]);

let employer = style([
  color(rgb(0, 0, 0)),
  whiteSpace(nowrap),
]);
let salary = style([
  color(rgba(35, 50, 57, 0.8)),
]);
let location = style([
  color(rgba(35, 50, 57, 0.8)),
]);

let space = style([
  color(rgba(35, 50, 57, 0.4)),
  fontSize(em(0.9)),
  marginLeft(em(0.25)),
  marginRight(em(0.25)),
]);

let logo = detail => style([
  alignSelf(flexStart),
  marginTop(zero),
  media(MasterStyle.aboveMobile, [
    alignSelf(flexEnd),
    marginTop(detail ? px(-90) : zero),
  ]),
]);

let apply = style([
  backgroundColor(rgb(221, 75, 57)),
  borderRadius(em(0.3)),
  color(white),
  display(inlineBlock),
  marginBottom(em(1.)),
  marginTop(em(1.)),
  paddingBottom(em(1.)),
  paddingLeft(em(2.)),
  paddingRight(em(2.)),
  paddingTop(em(1.)),
  textDecoration(none),
  hover([
    backgroundColor(rgba(221, 75, 57, 0.9)),
  ])
]);

let link = style([
  color(rgb(35, 50, 57)),
  float(`right),
  marginLeft(em(1.)),
  marginTop(em(2.)),
  textDecoration(none),
  hover([
    opacity(0.9),
  ])
]);

let details = style([
  whiteSpace(nowrap),
]);
