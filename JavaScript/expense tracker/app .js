// const balanceEl = document.querySelector('#balance');
// const incomeEl = document.querySelector('#income');
// const expenseEl = document.querySelector('#expense');
// const addBtn = document.querySelector('#add');
// const textInput = document.querySelector('#text');
// const amountInput = document.querySelector('#amount');
// const historyList = document.querySelector('#history');

// let balance = 0, income = 0, expense = 0;
// let listItems;

// // Initial display on load
// function initialDisplay() {
//   listItems = getFromLS();
//   listItems.forEach(entry => populateUI(entry));
// }

// // Get form input
// function getInput(e) {
//   const text = textInput.value;
//   const amount = amountInput.value;
//   clearFields();

//   if(text !== '' && amount !== '') {
//     const id = Math.random();
//     const entry = { text, amount, id };

//     listItems.push(entry);
//     setToLS(entry);
//     populateUI(entry);
//   } else {
//     alert('Please add a text and amount');
//   }

//   e.preventDefault();
// }

// // Clear input fields
// function clearFields() {
//   textInput.value = '';
//   amountInput.value = '';
// }

// // Populate UI
// function populateUI(entry) {
//   balance += +entry.amount
//   if(entry.amount > 0) {
//     income += +entry.amount;
//   } else {
//     expense += +entry.amount;
//   }

//   balanceEl.innerText = `$${balance.toFixed(2)}`;
//   incomeEl.innerText = `$${income.toFixed(2)}`;
//   expenseEl.innerText = `$${expense.toFixed(2)}`;

//   let classColor;

//   if(+entry.amount > 0) {
//     classColor = 'history-green';
//   } else {
//     classColor = 'history-red';
//   }

//   if(entry.amount > 0 && String(entry.amount).indexOf('+') === -1) {
//     entry.amount = `+${entry.amount}`;
//   }

//   const li = document.createElement('li');
//   li.classList.add('history-content');
//   li.setAttribute('data-id', entry.id);

//   li.innerHTML = `
//     <button class="delete-btn">x</button>
//     ${entry.text}
//     <span class="history-amount">${entry.amount}</span>
//     <span class="${classColor}"></span>
//   `;

//   historyList.appendChild(li);
// }

// // Delete item from history
// function deleteItem(e) {
//   if(e.target.classList.contains('delete-btn')) {
//     historyList.innerHTML = '';
//     const id = e.target.parentElement.dataset.id;
//     listItems = listItems.filter(entry => entry.id !== id);
//     listItems.forEach(entry => populateUI(entry));
//     renewLS();
//   }

//   e.preventDefault();
// }

// // Get from LS
// function getFromLS() {
//   let list;
//   if(localStorage.getItem('history') === null) {
//     list = [];
//   } else {
//     list = JSON.parse(localStorage.getItem('history'));
//   }

//   return list;
// }

// // Store to LS
// function setToLS(entry) {
//   let list = getFromLS();
//   list.push(entry);

//   localStorage.setItem('history', JSON.stringify(list));
// }

// // Replace LS values
// function renewLS() {
//   localStorage.setItem('history', JSON.stringify(listItems));
// }

// // Event Listeners
// addBtn.addEventListener('click', getInput);
// document.addEventListener('DOMContentLoaded', initialDisplay);
// historyList.addEventListener('click', deleteItem);

const balance = document.getElementById('balance');
const money_plus = document.getElementById('income');
const money_minus = document.getElementById('expense');
const list = document.getElementById('history');
const addBtn = document.getElementById('add');
const text = document.getElementById('text');
const amount = document.getElementById('amount');

const localStorageTransactions = JSON.parse(
  localStorage.getItem('transactions')
);

let transactions =
  localStorage.getItem('transactions') !== null ? localStorageTransactions : [];

// Add transaction
function addTransaction(e) {
  e.preventDefault();

  if (text.value.trim() === '' || amount.value.trim() === '') {
    alert('Please add a text and amount');
  } else {
    const transaction = {
      id: generateID(),
      text: text.value,
      amount: +amount.value
    };

    transactions.push(transaction);

    addTransactionDOM(transaction);

    updateValues();

    updateLocalStorage();

    text.value = '';
    amount.value = '';
  }
}

// Generate random ID
function generateID() {
  return Math.floor(Math.random() * 100000000);
}

// Add transactions to DOM list
function addTransactionDOM(transaction) {
  // Get sign
  const sign = transaction.amount < 0 ? '-' : '+';

  const item = document.createElement('li');

  let classColor;

  if(+transaction.amount > 0) {
    classColor = 'history-green';
  } else {
    classColor = 'history-red';
  }

  item.classList.add('history-content');

  item.innerHTML = `
     <button class="delete-btn" onclick="removeTransaction(${transaction.id})">x</button>
     ${transaction.text}
     <span class="history-amount">${sign}${Math.abs(transaction.amount)}</span>
     <span class="${classColor}"></span>
   `;

  list.appendChild(item);
}

// Update the balance, income and expense
function updateValues() {
  const amounts = transactions.map(transaction => transaction.amount);

  const total = amounts.reduce((acc, item) => (acc += item), 0).toFixed(2);

  const income = amounts
    .filter(item => item > 0)
    .reduce((acc, item) => (acc += item), 0)
    .toFixed(2);

  const expense = (
    amounts.filter(item => item < 0).reduce((acc, item) => (acc += item), 0) *
    -1
  ).toFixed(2);

  balance.innerText = `$${total}`;
  money_plus.innerText = `$${income}`;
  money_minus.innerText = `$${expense}`;
}

// Remove transaction by ID
function removeTransaction(id) {
  transactions = transactions.filter(transaction => transaction.id !== id);

  updateLocalStorage();

  init();
}

// Update local storage transactions
function updateLocalStorage() {
  localStorage.setItem('transactions', JSON.stringify(transactions));
}

// Init app
function init() {
  list.innerHTML = '';

  transactions.forEach(addTransactionDOM);
  updateValues();
}

init();

addBtn.addEventListener('click', addTransaction);