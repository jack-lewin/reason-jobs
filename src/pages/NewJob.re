/*
  module JobFormParams = {
    type state = {
      jobTitle: string,
      jobDescription: string,
      jobLocation: string,
      jobSalary: string,
      jobUrl: string,
      jobEmail: string,
      companyName: string,
      companyUrl: string,
      companyTwitter: string,
      companyLogo: string,
    };

    type fields = [
      | `jobTitle
      | `jobDescription
      | `jobLocation
      | `jobSalary
      | `jobUrl
      | `jobEmail
      | `companyName
      | `companyUrl
      | `companyTwitter
      | `companyLogo
    ];
    
    /* (fieldName, getter, setter) */
    let lens = [(
      `jobTitle,
      s => s.jobTitle,
      (s, jobTitle) => {...s, jobTitle}
    ), (
      `jobDescription,
      s => s.jobDescription,
      (s, jobDescription) => {...s, jobDescription}
    ), (
      `jobLocation,
      s => s.jobLocation,
      (s, jobLocation) => {...s, jobLocation}
    ), (
      `jobSalary,
      s => s.jobSalary,
      (s, jobSalary) => {...s, jobSalary}
    ), (
      `jobUrl,
      s => s.jobUrl,
      (s, jobUrl) => {...s, jobUrl}
    ), (
      `jobEmail,
      s => s.jobEmail,
      (s, jobEmail) => {...s, jobEmail}
    ), (
      `companyName,
      s => s.companyName,
      (s, companyName) => {...s, companyName}
    ), (
      `companyUrl,
      s => s.companyUrl,
      (s, companyUrl) => {...s, companyUrl}
    ), (
      `companyTwitter,
      s => s.companyTwitter,
      (s, companyTwitter) => {...s, companyTwitter}
    ), (
      `companyLogo,
      s => s.companyLogo,
      (s, companyLogo) => {...s, companyLogo}
    )];  
  };

  module JobForm = ReForm.Create(JobFormParams);

  let defaults = (defaultValue, optional) => switch (optional) {
    | Some(value) => value
    | None => defaultValue
  };

  let initialState: JobFormParams.state = {
    jobTitle: "",
    jobDescription: "",
    jobLocation: "",
    jobSalary: "",
    jobUrl: "",
    jobEmail: "",
    companyName: "",
    companyUrl: "",
    companyTwitter: "",
    companyLogo: ""
  };

  let schema = [
    (`jobTitle, ReForm.Validation.Required ),
    (`jobDescription, ReForm.Validation.Required ),
    (`jobLocation, ReForm.Validation.Required ),
    (`jobEmail, ReForm.Validation.Email ),
    (`companyName, ReForm.Validation.Required ),
    (`companyUrl, ReForm.Validation.Required ),
  ];
*/

let typeform = ReasonReact.cloneElement(
  <div className="typeform-widget" />,
  ~props={
    "data-url": "https://reasonjobs.typeform.com/to/f67GOT",
    "data-transparency": "100",
    "style": ReactDOMRe.Style.make(
      ~width="100%",
      ~height="500px",
      ()
    )
  },
  [||]
);


let component = ReasonReact.statelessComponent("NewJob");

let make = (_children) => {
  ...component,

  didMount: _self => {
    [%bs.raw {|
      (function() { var qs,js,q,s,d=document, gi=d.getElementById, ce=d.createElement, gt=d.getElementsByTagName, id="typef_orm", b="https://embed.typeform.com/"; if(!gi.call(d,id)) { js=ce.call(d,"script"); js.id=id; js.src=b+"embed.js"; q=gt.call(d,"script")[0]; q.parentNode.insertBefore(js,q) } })()
    |}];
    ReasonReact.NoUpdate;
  },

  render: _self =>
    <div className=MasterStyle.container>
    {typeform}
      /* <script src="https://static.airtable.com/js/embed/embed_snippet_v1.js"></script>
      <iframe className="airtable-embed airtable-dynamic-height" src="https://airtable.com/embed/shrgH5vb4LuEOwIR5?backgroundColor=cyan" width="100%" height="2198" style=(
        ReactDOMRe.Style.make(~background="transparent", ~border="1px solid #ccc", ())
      ) /> */
      /*
        <JobForm initialState schema onSubmit=(({values}) => Js.log(values))>
          ...(
              ({handleSubmit, handleChange, form, getErrorForField}) =>
                <form className=NewJobStyle.form onSubmit=(ReForm.Helpers.handleDomFormSubmit(handleSubmit))>
                  <fieldset>
                    <legend>("Job information" |> ReasonReact.stringToElement)</legend>
                    <FormField
                      label="Title"
                      value=form.values.jobTitle
                      onChange=(ReForm.Helpers.handleDomFormChange(handleChange(`jobTitle)))
                      error=getErrorForField(`jobTitle)
                    />
                    <FormField
                      _type="textarea"
                      label="Description"
                      value=form.values.jobDescription
                      onChange=(ReForm.Helpers.handleDomFormChange(handleChange(`jobDescription)))
                      error=getErrorForField(`jobDescription)
                    />
                    <FormField
                      label="Location"
                      value=form.values.jobLocation
                      onChange=(ReForm.Helpers.handleDomFormChange(handleChange(`jobLocation)))
                      error=getErrorForField(`jobLocation)
                    />
                    <FormField
                      label="Salary"
                      value=form.values.jobSalary
                      onChange=(ReForm.Helpers.handleDomFormChange(handleChange(`jobSalary)))
                      error=getErrorForField(`jobSalary)
                      defaultError="Jobs that don't pay the national minimum wage (or equivalent) will not be accepted."
                    />
                    <FormField
                      label="URL"
                      value=form.values.jobUrl
                      onChange=(ReForm.Helpers.handleDomFormChange(handleChange(`jobUrl)))
                      error=getErrorForField(`jobUrl)
                    />
                    <FormField
                      _type="email"
                      label="Email"
                      value=form.values.jobEmail
                      onChange=(ReForm.Helpers.handleDomFormChange(handleChange(`jobEmail)))
                      error=getErrorForField(`jobEmail)
                    />
                  </fieldset>
                  <fieldset>
                    <legend>("Company information" |> ReasonReact.stringToElement)</legend>
                    <FormField
                      label="Name"
                      value=form.values.companyName
                      onChange=(ReForm.Helpers.handleDomFormChange(handleChange(`companyName)))
                      error=getErrorForField(`companyName)
                    />
                    <FormField
                      label="URL"
                      value=form.values.companyUrl
                      onChange=(ReForm.Helpers.handleDomFormChange(handleChange(`companyUrl)))
                      error=getErrorForField(`companyUrl)
                    />
                    <FormField
                      label="Twitter"
                      value=form.values.companyTwitter
                      onChange=(ReForm.Helpers.handleDomFormChange(handleChange(`companyTwitter)))
                      error=getErrorForField(`companyTwitter)
                    />
                    <FormField
                      label="Logo (link)"
                      value=form.values.companyLogo
                      onChange=(ReForm.Helpers.handleDomFormChange(handleChange(`companyLogo)))
                      error=getErrorForField(`companyLogo)
                    />
                  </fieldset>
                  <button _type="submit">
                    ("Submit" |> ReasonReact.stringToElement)
                  </button>
                </form>
            )
        </JobForm>
      */
    </div>
};
