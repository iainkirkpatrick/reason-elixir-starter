open Todo;

[@react.component]
let make = () => {
  // TODO: not ideal that todos starts with a blank todo
  let (todos, setTodos) = React.useState(() => [{ active: false, content: "", completed: false }]);
  let todosArr = todos |> Array.of_list;

  let todosEls = Array.mapi((i, t: todo ) => {
    let setTodo = (updatedTodo) => {
      todosArr[i] = updatedTodo;
      setTodos(_ => todosArr |> Array.to_list)
    };
    let add = _ => {
      todosArr[i] = { ...t, active: true };
      let todosList = todosArr |> Array.to_list;
      setTodos(_ => [{ active: false, content: "", completed: false }, ...todosList])
    };
    let delete = _ => {
      let newTodos = switch(i === List.length(todos) - 1) {
        | true => List.rev(List.tl(List.rev(todos)))
        | false => Array.concat([Js.Array.slice(0, i, todosArr), Js.Array.slice(i+1, Array.length(todosArr), todosArr)]) |> Array.to_list
      }
      setTodos(_ => newTodos)
    };
    <Todo key=string_of_int(i) data=t setTodo add delete />
  }, todosArr) |> React.array;

  <div>
    todosEls
    <p>{React.string("Double-click to edit a todo")}</p>
    <p>{React.string("Created by iainkirkpatrick")}</p>
    <p>{React.string("Template from TodoMVC")}</p>
  </div>;
};
