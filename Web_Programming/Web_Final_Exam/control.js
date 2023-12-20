const itemInput = document.getElementById('itemInput');
const addButton = document.getElementById('addButton');
const itemList = document.getElementById('itemList');
const deleteAllButton = document.getElementById('deleteAllButton');
let editingItem = null;

// 新增項目的函式
function addItem() {
    const itemName = itemInput.value;
    if (itemName) {
        if (editingItem) {
            // 編輯模式
            editingItem.firstChild.textContent = itemName;
            addButton.textContent = '新增項目';
            editingItem = null;
        } else {
            // 新增模式
            const li = document.createElement('li');
            const span = document.createElement('span');
            const editButton = document.createElement('button');
            const deleteButton = document.createElement('button');

            span.textContent = itemName;
            editButton.classList.add('edit-button');
            deleteButton.classList.add('delete-button');

            editButton.addEventListener('click', function () {
                itemInput.value = span.textContent;
                addButton.textContent = '編輯';
                editingItem = li;
            });

            deleteButton.addEventListener('click', function () {
                li.remove();
                checkDeleteAllButtonVisibility();
            });

            li.appendChild(span);
            li.appendChild(editButton);
            li.appendChild(deleteButton);
            itemList.appendChild(li);
        }

        itemInput.value = '';
        checkDeleteAllButtonVisibility();
    }
}

// 刪除所有項目的函式
function deleteAllItems() {
    itemList.innerHTML = '';
    checkDeleteAllButtonVisibility();
}

// 檢查刪除所有項目按鈕的顯示與隱藏
function checkDeleteAllButtonVisibility() {
    deleteAllButton.style.display = itemList.children.length > 0 ? 'block' : 'none';
}

addButton.addEventListener('click', addItem);
deleteAllButton.addEventListener('click', deleteAllItems);