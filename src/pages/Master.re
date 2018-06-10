type action =
  | UpdatePath(list(string));

type state = {
  path: list(string),
  search: string
};

let lookupPageFromPath = (path, send) =>
  switch (path) {
  | ["home"] => <Home updatePath=(path => send(UpdatePath(path))) />
  | ["job", _] => <JobPage slug=List.nth(path, 1) />
  | ["new"] => <NewJob />
  | _ => <Home updatePath=(path => send(UpdatePath(path))) />
  };

let generateUrlPathString = path =>
  List.fold_left((a, b) => a ++ b ++ "/", "", path);

let component = ReasonReact.reducerComponent("Master");

let make = _children => {
  ...component,
  initialState: () => (
    {
      path: ReasonReact.Router.dangerouslyGetInitialUrl().path,
      search: ReasonReact.Router.dangerouslyGetInitialUrl().search == "" ? "" : "?" ++ ReasonReact.Router.dangerouslyGetInitialUrl().search
    }: state
  ),
  subscriptions: self => [
    Sub(
      () =>
        ReasonReact.Router.watchUrl(url => self.send(UpdatePath(url.path))),
      ReasonReact.Router.unwatchUrl,
    ),
  ],
  reducer: (action, state) =>
    switch (action) {
    | UpdatePath(path) => {
        ReactGa.pageView("https://reasonjobs.io/" ++ generateUrlPathString(path));
        ReasonReact.UpdateWithSideEffects(
          {
            path,
            search: ""
          },
          (
            _self =>
              if (path != state.path) {
                ReasonReact.Router.push("/" ++ generateUrlPathString(path));
              }
          ),
        )
      }
    },
  didMount: self => {
    ReactGa.pageView("https://reasonjobs.io/" ++ generateUrlPathString(self.state.path) ++ self.state.search);
    ReactGa.initialize("UA-120654702-1");
    ReasonReact.NoUpdate;
  },
  render: self =>
    <div className=MasterStyle.master>
      <Nav updatePath=(path => self.send(UpdatePath(path))) />
      (lookupPageFromPath(self.state.path, self.send))
      <Footer />
    </div>,
};
