# This file is responsible for configuring your application
# and its dependencies with the aid of the Mix.Config module.
#
# This configuration file is loaded before any dependency and
# is restricted to this project.

# General application configuration
use Mix.Config

config :lifecycle,
  ecto_repos: [Lifecycle.Repo]

# Configures the endpoint
config :lifecycle, LifecycleWeb.Endpoint,
  url: [host: "localhost"],
  secret_key_base: "rnT88WnOs1IjUnJ4I7Exfcd14DVkA1w2VBUN59YmD7d46eI/mW1JBtu6goQyvzGU",
  render_errors: [view: LifecycleWeb.ErrorView, accepts: ~w(html json)],
  pubsub: [name: Lifecycle.PubSub, adapter: Phoenix.PubSub.PG2],
  live_view: [signing_salt: "5zD4VDQ9"]

# Configures Elixir's Logger
config :logger, :console,
  format: "$time $metadata[$level] $message\n",
  metadata: [:request_id]

# Use Jason for JSON parsing in Phoenix
config :phoenix, :json_library, Jason

# Import environment specific config. This must remain at the bottom
# of this file so it overrides the configuration defined above.
import_config "#{Mix.env()}.exs"
