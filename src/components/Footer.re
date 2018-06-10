let component = ReasonReact.statelessComponent("Footer");

let make = (_children) => {
  ...component,
  render: _self =>
    <footer className=FooterStyle.footer>
      <p>
        <span>(ReasonReact.stringToElement("Built with "))</span>
        <img src="/re.png" alt="ReasonML" width="24" height="24" />
      </p>
    </footer>
};
