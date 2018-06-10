open Css;

let aboveMobile = "all and (min-width: 500px)";

global(
  "body", 
  [
    fontFamily("Montserrat, -apple-system, BlinkMacSystemFont, Helvetica Neue, Segoe UI, sans-serif")
  ]
);

let minPageHeight = Calc.(vh(100.) - px(6));
let basePadding = px(3);

let master = style([
  minHeight(minPageHeight),
  display(flexBox),
  flexDirection(column),
  margin(px(0)),
  padding(basePadding),
]);

let container = style([
  flexGrow(1),
  marginLeft(auto),
  marginRight(auto),
  width(`percent(100.)),
  media("(min-width: 600px) and (max-width: 799px)", [
    width(`percent(90.)),
  ]),
  media("(min-width: 400px) and (max-width: 599px)", [
    width(`percent(80.)),
  ]),
  media("(min-width: 800px) and (max-width: 999px)", [
    width(`percent(70.)),
  ]),
  media("(min-width: 1000px) and (max-width: 1199px)", [
    width(`percent(60.)),
  ]),
  media("(min-width: 1200px)", [
    width(`percent(50.)),
  ])
]);
