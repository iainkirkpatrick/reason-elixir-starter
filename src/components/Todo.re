type todo = {
  active: bool,
  content: string,
  completed: bool
};

let container =
   ReactDOMRe.Style.make(
     ~display="flex",
     ~flexDirection="row",
     (),
   );
let todoStyle = (active) =>
  ReactDOMRe.Style.make(
    ~textDecoration=active ? "line-through" : "none",
    (),
);

[@react.component]
let make = (~data: todo, ~setTodo, ~add, ~delete) => {
  let checkbox = switch(data.active) {
    | true => (<input
        type_="checkbox"
        checked=data.completed
        onChange={_ => {
          let newTodo = { ...data, completed: !data.completed };
          setTodo(newTodo)
        }}
      />)
    | false => React.null
  };

  let deleteBtn = switch(data.active) {
    | true => (<button
        onClick=delete
      >{React.string("X")}</button>)
    | false => React.null
  };

  let handleKeyDown = keyCode => switch(keyCode) {
    | 13 => switch (data.content) {
      | "" => ()
      | _ => add()
    }
    | _ => ()
  };

  <div style=container>
    checkbox
    <input
      type_="text"
      placeholder="What needs to be done?"
      value=data.content
      onChange={e => {
        let newTodo = { ...data, content: ReactEvent.Form.target(e)##value };
        setTodo(newTodo)
      }}
      onKeyDown={e => handleKeyDown(ReactEvent.Keyboard.which(e))}
      style=todoStyle(data.completed)
    />
    deleteBtn
  </div>;
};
