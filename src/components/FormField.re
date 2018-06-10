let component = ReasonReact.statelessComponent("FormField");

let make = (
  ~_type="text",
  ~label,
  ~value,
  ~onChange,
  ~error,
  ~defaultError="",
  _children
  ) => {
  ...component,
  render: _self =>
    <div className=FormFieldStyle.container>
      <label className=FormFieldStyle.inputContainer>
        <span className=FormFieldStyle.label>(label |> ReasonReact.stringToElement)</span>
        (
          (_type == "textarea")
          ? <textarea value onChange rows=20 className=FormFieldStyle.textarea />
          : <input _type value onChange className=(
            label == "Title"
            ? FormFieldStyle.titleInput
            : FormFieldStyle.input
          ) />
        )
      </label>
      <span>
        (
        error
        |> Belt.Option.getWithDefault(_, defaultError)
        |> ReasonReact.stringToElement
        )
      </span>
    </div>
};
