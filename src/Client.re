let serverAddress = "127.0.0.1:12345";

let credentials = Grpc.Client.Credentials.createInsecure();

let chatServiceClient =
  Grpc.Chat.ChatService.Client.makeClient(serverAddress, credentials);

let payload =
  Grpc.Chat.MessageRequest.make(
    ~channel="channel",
    ~text="name",
    ~urgency=Grpc.Chat.Urgency.UrgencyNormal,
    (),
  );

chatServiceClient
->Grpc.Chat.ChatService.Client.SendMessageRpc.invokeFuture(payload)
->Future.mapOk(res => Js.log2("Ok", res))
->Future.tapError(err => Js.log2("Error", err));
