defmodule LifecycleTest do
  use ExUnit.Case
  doctest Lifecycle

  test "greets the world" do
    assert Lifecycle.hello() == :world
  end
end
