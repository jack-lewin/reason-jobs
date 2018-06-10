let component = ReasonReact.statelessComponent("Navigation");

let make = (~updatePath, _children) => {
  ...component,
  render: _self =>
    <div className=NavStyle.container>
      <header>
        <img className=NavStyle.logo onClick=(_e => updatePath([])) alt="Reason Jobs" src="https://reasonml.github.io/img/reason.svg" />
      </header>
      <nav className=NavStyle.nav>
        <p className=NavStyle.navItem onClick=(_e => updatePath([]))>
          <span className=Emojis.unicorn></span>
          [%raw {|'\u00a0'|}]
          <span className=NavStyle.link>("Jobs" |> ReasonReact.stringToElement)</span>
        </p>
        <p className=NavStyle.navItem onClick=(_e => updatePath(["new"]))>
          <span className=Emojis.rocket></span>
          [%raw {|'\u00a0'|}]
          <span className=NavStyle.link>("Post a job" |> ReasonReact.stringToElement)</span>
        </p>
      </nav>
    </div>,
};
