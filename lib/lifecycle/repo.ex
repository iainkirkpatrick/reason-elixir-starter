defmodule Lifecycle.Repo do
  use Ecto.Repo,
    otp_app: :lifecycle,
    adapter: Ecto.Adapters.Postgres
end
