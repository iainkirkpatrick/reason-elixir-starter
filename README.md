# Reason Elixir Starter

A starter template for a project using ReasonML to build a web client, and Elixir (Phoenix) to serve the client + API.
This doesn't yet have any (tested) scripts for deployment to production - TBD...

### Useful commands:
- `npm start`: starts `bsb` in watch mode, along with parcel in watch mode to bundle the compiled JS to a single file. Note currently if you don't also start the server, the compiled JS isn't served from anywhere.
- `npm run server`: starts the Phoenix server
- `npm run dev`: run both the client compiliation + bundling in watch mode, and the server for the full dev pipeline.

### Get started

- have Node, NPM, Elixir, Erlang deps installed (I use [asdf](https://github.com/asdf-vm/asdf))
- install ReasonML / other project dependencies with `npm install`
- install Phoenix dependencies with `mix deps.get`
- create and migrate your database with `mix ecto.setup`
- run everything with `npm run dev`

Now you can visit [`localhost:4000`](http://localhost:4000) from your browser.

Phoenix readme notes: "Ready to run in production? Please [check our deployment guides](https://hexdocs.pm/phoenix/deployment.html)."
