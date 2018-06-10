type state = {
  jobs: list(JobData.job)
};

type action =
  | JobsLoaded(list(JobData.job));

let component = ReasonReact.reducerComponent("Home");

let make = (~updatePath, _children) => {
  ...component,

  initialState: () => {
    jobs: [/*JobData.placeholder*/]
  },

  didMount: (self) => {
    let handleJobsLoaded = jobs => self.send(JobsLoaded(jobs));

    JobData.getJobs()
      |> Js.Promise.then_(
        jobs => {
          handleJobsLoaded(jobs);
          Js.Promise.resolve();
        }
      )
      |> Js.Promise.catch(
        _err => {
          handleJobsLoaded([JobData.notFound]);
          Js.Promise.resolve();
        }
      )
      |> ignore;

    ReasonReact.NoUpdate;
  },

  reducer: (action, _prevState) => {
    switch action {
    | JobsLoaded(jobs) =>
      ReasonReact.Update({
        jobs: jobs
      })
    }
  },

  render: (self) =>
    <div className=MasterStyle.container>
      {
        self.state.jobs
        |> List.map((job: JobData.job) => <Job updatePath job=job key=job.slug />)
        |> Array.of_list
        |> ReasonReact.arrayToElement
      }
    </div>
};
