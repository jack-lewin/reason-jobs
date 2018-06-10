type optionOrError('a) =
  | Some('a)
  | None
  | Error;

type state = {
  job: optionOrError(JobData.job)
};

type action =
  | JobLoaded(JobData.job)
  | JobError;

let component = ReasonReact.reducerComponent("JobPage");

let make = (~slug, _children) => {
  ...component,

  initialState: () => {
    job: None
  },

  didMount: (self) => {
    let handleJobLoaded = job => self.send(JobLoaded(job));

    JobData.getJob(slug)
      |> Js.Promise.then_(
        job => {
          handleJobLoaded(job);
          Js.Promise.resolve();
        }
      )
      |> Js.Promise.catch(
        _err => {
          handleJobLoaded(JobData.notFound);
          Js.Promise.resolve();
        }
      )
      |> ignore;

    ReasonReact.NoUpdate;
  },

  reducer: (action, _prevState) => {
    switch action {
    | JobLoaded(job) =>
      ReasonReact.Update({
        job: Some(job)
      })
    | JobError => {
      ReasonReact.Update({
        job: Error
      })
    }
    }
  },

  render: (self) =>
    <div className=MasterStyle.container>
      {
        switch (self.state.job) {
        | Some(job) => <Job detail=true job=job key=job.slug />
        /*
        | None => <Job job=JobData.placeholder key="-1" />
        | Error => <Job job=JobData.placeholder key="-1" />
        */
        | None => ReasonReact.nullElement
        | Error => ReasonReact.nullElement
        };
      }
    </div>
};
