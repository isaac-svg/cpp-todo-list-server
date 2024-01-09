let TODOS = []


const addForm = document.querySelector("form.add");
console.log(addForm)
const ul = document.querySelector("ul.todos");
const searchFormInput = document.querySelector("form.search input");

getTodos()
loadUI()
//ADD NEW TODO
const handleAddItem = (inputValue) => {
  const html = `
   <li class="list-group-item d-flex justify-content-between align-items-center">
      <span>${inputValue}</span>
      <span class="trash-icon">X</span>
    </li>
  `;
  ul.innerHTML += html;
};

addForm.addEventListener("submit",async (e) => {
  e.preventDefault();
  const inputValue = addForm.add.value;
  if (inputValue.length) handleAddItem(inputValue);
  // send data to backend
try {
  const res =   await fetch("http://localhost:3000/todo",{
    method:"POST",
    body:inputValue,
    headers:{
      "Content-Type":"application/json"
    }
  })
  const data =  await res.json();
  console.log(data)
  getTodos()
} catch (error) {
  console.log(error)
}

  addForm.add.value = "";
});

//REMOVE TODO
ul.addEventListener("click", async(e) => {
  
  if (e.target.classList.contains("delete")) {
    const id = e.target.id;
    console.log(id)
    try {
      const res = await fetch(`http://localhost:3000/${id}`,{
        method:"DELETE"
      })
      const data =  await res.json();
      console.log(data, "From server")
       TODOS = data 
      
       removeFromLocalStorage(id)
       loadUI()
    } catch (error) {
      console.log(error)
    }
    e.target.parentElement.remove();
  }
});



searchFormInput.parentElement.addEventListener("submit", (e) =>
  e.preventDefault()
);

//SEARCH AND FILTER TODOS
const filterItems = (value) => {
  Array.from(ul.children).forEach((li) => {
    if (!li.textContent.toLowerCase().includes(value)) li.classList.add("filtred");
    else li.classList.remove("filtred");
  });
};

searchFormInput.addEventListener("keyup", (e) => {
  const value = searchFormInput.value.toLowerCase().trim();
  filterItems(value);
});



// getTodos

async function getTodos(){

 try {
   const res = await fetch("http://localhost:3000/todos");
  const data = await res.json()

  TODOS = data 
  addToStorage(data);
  loadUI()
 } catch (error) {
  console.log(error)
 }
}

function filterTodos(){
  searchFormInput.addEventListener("keyup", (e) => {
  const value = searchFormInput.value.toLowerCase().trim();
  filterItems(value);
});
}



function addToStorage(data=[]){
  clearLocalStorage()
  localStorage.setItem("todos", JSON.stringify(data));

}
function clearLocalStorage(){
  localStorage.clear();
}
function removeFromLocalStorage(id){

  if (!id)
  {
    console.error("Must provide an id as the second argument");
    return;
  }
  TODOS = TODOS.filter((item) => item.id != id);
  console.log(TODOS, " removed TODOS")
  addToStorage(TODOS)
}
filterTodos()


function loadUI(){

  ul.innerHTML = ""
  TODOS.forEach(item=>{

    const html = `
   <li  class="list-group-item d-flex justify-content-between align-items-center">
      <span>${item.todo}</span>
      <span id=${item.id} class="delete">X</span>
    </li>
  `;

  ul.innerHTML +=html;
  })
  
}