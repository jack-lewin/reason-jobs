open Css;

let footer = style([
  alignSelf(flexEnd),
  fontSize(em(1.)),
  paddingBottom(em(0.4)),
  paddingRight(em(0.6)),
  selector(" p", [
    margin(zero),
  ]),
  selector(" img", [
    marginBottom(px(-2)),
  ]),
]);
