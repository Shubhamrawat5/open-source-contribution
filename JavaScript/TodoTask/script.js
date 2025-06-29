const taskInput = document.getElementById('taskInput');
const taskList = document.getElementById('taskList');

let tasks = JSON.parse(localStorage.getItem('tasks')) || [];

function renderTasks() {
  taskList.innerHTML = '';
  tasks.forEach((task, index) => {
    const li = document.createElement('li');
    li.textContent = task.text;
    li.className = task.done ? 'done' : '';
    li.onclick = () => toggleTask(index);

    const delBtn = document.createElement('button');
    delBtn.textContent = 'Delete';
    delBtn.onclick = (e) => {
      e.stopPropagation();
      deleteTask(index);
    };

    li.appendChild(delBtn);
    taskList.appendChild(li);
  });
}

function addTask() {
  const text = taskInput.value.trim();
  if (text) {
    tasks.push({ text, done: false });
    taskInput.value = '';
    saveAndRender();
  }
}

function toggleTask(index) {
  tasks[index].done = !tasks[index].done;
  saveAndRender();
}

function deleteTask(index) {
  tasks.splice(index, 1);
  saveAndRender();
}

function saveAndRender() {
  localStorage.setItem('tasks', JSON.stringify(tasks));
  renderTasks();
}

// Initialize on page load
renderTasks();
