open Css;

let container = style([
  marginBottom(em(1.)),
  width(`percent(100.)),
]);

let inputContainer = style([
  display(`flex),
  flexDirection(column),
]);

let inputCSS = [
  color(rgb(23, 62, 71)),
  borderColor(rgba(23, 62, 71, 0.4)),
  borderStyle(solid),
  borderWidth(px(1)),
  width(`percent(50.)),
  fontSize(em(1.2)),
  padding(em(0.2)),
  marginBottom(em(0.5)),
];

let titleInputCSS = [
  width(`percent(100.)),
  paddingRight(em(1.)),
];

let input = style(inputCSS);
let titleInput = style(merge([titleInputCSS, inputCSS]));

let textareaCSS = [
  width(`percent(100.)),
  padding(em(0.6)),
  fontFamily("Montserrat, -apple-system, BlinkMacSystemFont, Helvetica Neue, Segoe UI, sans-serif"),
];

let textarea = style(merge([textareaCSS, inputCSS]));

let label = style([
  marginBottom(em(0.5)),
]);
