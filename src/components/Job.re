let component = ReasonReact.statelessComponent("Job");

let make = (~job: JobData.job, ~updatePath=(_) => (), ~detail=false, _children) => {
  ...component,

  render: _self => {
    <div className={JobStyle.job(detail, job.highlighted)} onClick={(_e) => updatePath(["job", job.slug])}>
      <div className={JobStyle.main}>
        <h3 className={detail ? JobStyle.detailTitle : JobStyle.title}>
          (
            job.highlighted
            ? <span className=Emojis.loudspeaker></span>
            : ReasonReact.nullElement
          )
          (job.title |> ReasonReact.stringToElement)
        </h3>
        <p className=JobStyle.info>
          <span className=JobStyle.employer>
            (job.employer.name |> ReasonReact.stringToElement)
          </span>
          <span className=JobStyle.details>
            {
              job.salary == ""
              ? ReasonReact.nullElement
              : (
                <span>
                  <span className=JobStyle.space>
                    (" | " |> ReasonReact.stringToElement)
                  </span>
                  <span className=JobStyle.salary>
                    (job.salary |> ReasonReact.stringToElement)
                  </span>
                </span>
              )
            }
            <span className=JobStyle.space>
              (" | " |> ReasonReact.stringToElement)
            </span>
            <span className=JobStyle.location>
              (job.location |> ReasonReact.stringToElement)
            </span>
          </span>
        </p>
      </div>
      {
        job.employer.logo == ""
          ? ReasonReact.nullElement
          : <img className=JobStyle.logo(detail) src=job.employer.logo alt=job.employer.name height="80" width="auto" />
      }
      {
        detail
          ? (
            <div>
              <p dangerouslySetInnerHTML={"__html": job.description} />
              {
                job.url == ""
                ? ReasonReact.nullElement
                : <a className=JobStyle.apply href=job.url>("Apply now" |> ReasonReact.stringToElement)</a>
              }
              {
                job.email == ""
                ? ReasonReact.nullElement
                : {
                  job.url == ""
                  ? <a className=JobStyle.apply href={"mailto:" ++ job.email}>
                      ("Apply now" |> ReasonReact.stringToElement)
                    </a>
                  : <a className=JobStyle.link href={"mailto:" ++ job.email}>
                      <span className=Emojis.email style={ReactDOMRe.Style.make(~marginTop="0em", ())}></span>
                      ("email" |> ReasonReact.stringToElement)
                    </a>
                }
              }
              {
                job.employer.url == ""
                ? ReasonReact.nullElement
                : <a className=JobStyle.link href={"https://www." ++ job.employer.url}>
                  <span className=Emojis.www></span>
                  (job.employer.url |> ReasonReact.stringToElement)
                  </a>
              }
            </div>
          )
          : ReasonReact.nullElement;
      }
    </div>
  }
};
