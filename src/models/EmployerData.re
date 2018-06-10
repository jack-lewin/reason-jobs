type employer = {
    name: string,
    url: string,
    twitter: string,
    logo: string,
};

let notFound: employer = {
  name: "Sorry, we're working on it...",
  url: "",
  twitter: "",
  logo: "",
};

let defaultStr = (json, fieldName) => {
  switch (Array.get(Json.Decode.(field(fieldName, array(string), json)), 0)) {
  | exception _ => ""
  | _ => Array.get(Json.Decode.(field(fieldName, array(string), json)), 0)
  };
};

let parseJobEmployerJson = json =>
  Json.Decode.{
    name: Array.get(field("employer_name", array(string), json), 0),
    url: defaultStr(json, "employer_url"),
    twitter: defaultStr(json, "employer_twitter"),
    logo: defaultStr(json, "employer_logo"),
  };
