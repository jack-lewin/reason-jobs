type job = {
  slug: string,
  title: string,
  description: string,
  location: string,
  salary: string,
  url: string,
  email: string,
  highlighted: bool,
  employer: EmployerData.employer
};

let notFound: job = {
  slug: "",
  title: "Whoops!",
  description: "",
  location: "wrong",
  salary: "something's",
  url: "",
  email: "",
  highlighted: false,
  employer: EmployerData.notFound
};

let jobsUrl = "https://reason-jobs-api-proxy.herokuapp.com/jobs";

let getDescription = json => {
  switch (
    Json.Decode.(field("description", string, json))
  ) {
  | exception _ => ""
  | _ => Json.Decode.(field("description", string, json))
  };
};
let getSalary = json => {
  switch (
    Json.Decode.(field("salary", string, json))
  ) {
  | exception _ => ""
  | _ => Json.Decode.(field("salary", string, json))
  };
};
let getUrl = json => {
  switch (
    Json.Decode.(field("url", string, json))
  ) {
  | exception _ => ""
  | _ => Json.Decode.(field("url", string, json))
  };
};
let getEmail = json => {
  switch (
    Json.Decode.(field("email", string, json))
  ) {
  | exception _ => ""
  | _ => Json.Decode.(field("email", string, json))
  };
};
let getHighlighted = json => {
  switch (
    Json.Decode.(field("isHighlighted", bool, json))
  ) {
  | exception _ => false
  | true => true
  | false => false
  };
};

let parseJobJson = json =>
  Json.Decode.{
    slug: field("slug", string, json),
    title: field("title", string, json),
    description: json |> getDescription,
    location: field("location", string, json),
    salary: json |> getSalary,
    url: json |> getUrl,
    email: json |> getEmail,
    highlighted: json |> getHighlighted,
    employer: json |> EmployerData.parseJobEmployerJson
  };

let parseJobFieldJson = json =>
  json |> Json.Decode.(at([
    "fields",
  ], parseJobJson));

let parseJobResultsJson = json =>
  Json.parseOrRaise(json) |> Json.Decode.(at([
    "records",
  ], list(parseJobFieldJson)));

let getJobs = () =>
  Js.Promise.(
    Bs_fetch.fetch(jobsUrl)
      |> then_(Bs_fetch.Response.text)
      |> then_(
        jsonText => {
          switch (parseJobResultsJson(jsonText)) {
          | exception e => reject(e);
          | jobs => {
            if (List.length(jobs) == 0) {
              reject(Not_found);
            } else {
              resolve(jobs);
            }
          }
          };
        }
      )
    );

let getJob = (slug) =>
  Js.Promise.(
    Bs_fetch.fetch(jobsUrl ++ "?slug=" ++ URL.encode(slug))
      |> then_(Bs_fetch.Response.text)
      |> then_(
        jsonText => {
          switch (parseJobResultsJson(jsonText)) {
          | exception e => reject(e);
          | job => resolve(List.nth(job, 0));
          };
        }
      )
    );
