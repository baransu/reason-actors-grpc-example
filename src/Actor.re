open Nact;
let system = start();

type msg =
  | Ping(actorRef(msg))
  | Pong(actorRef(msg));

module Actor = {
  let make = (~name) => {
    spawnStateless(
      ~name,
      system,
      (msg, ctx) => {
        switch (msg) {
        | Ping(sender) =>
          Js.log("ping");
          dispatch(sender, Pong(ctx.self));
        | Pong(sender) =>
          Js.log("pong");
          dispatch(sender, Ping(ctx.self));
        };

        Js.Promise.resolve();
      },
    );
  };
};
// dispatch(actor1, Ping(actor1));

let actor1 = Actor.make(~name="actor1");
let actor2 = Actor.make(~name="actor2");