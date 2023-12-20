// team054.js

// 假設這是一個全局變數，用來跟蹤當前選擇的日期
const date = new Date();
let selectedDate = {
    year: date.getFullYear(),
    month: date.getMonth() + 1,
    day: date.getDate()
};

const monthNames = [
    'January', 'February', 'March', 'April', 'May', 'June', 'July',
    'August', 'September', 'October', 'November', 'December'
];

// 生成月曆的HTML代碼
function generateCalendarHTML(year, month) {
    const daysInMonth = new Date(year, month, 0).getDate();
    const firstDayOfWeek = new Date(year, month - 1, 1).getDay();

    let calendarHTML = `<table><thead><tr><th colspan="7"><div class="justify-content-space-between"><div id="prev-month"><</div> <span>${monthNames[month - 1]} ${year}</span> <div id="next-month">></div></div></th></tr>`;
    calendarHTML += '<tr><th>S</th><th>M</th><th>T</th><th>W</th><th>T</th><th>F</th><th>S</th></tr></thead><tbody>';

    let dayCounter = 1;

    for (let i = 0; i < 6; i++) {
        calendarHTML += '<tr>';
        for (let j = 0; j < 7; j++) {
            if ((i === 0 && j < firstDayOfWeek) || dayCounter > daysInMonth) {
                calendarHTML += '<td></td>';
            } else {
                calendarHTML += `<td data-day="${dayCounter}">${dayCounter}</td>`;
                dayCounter++;
            }
        }
        calendarHTML += '</tr>';
    }

    calendarHTML += '</tbody></table>';
    return calendarHTML;
}

// 更新月曆內容
function updateCalendar(year, month) {
    const calendarElement = document.querySelector('.calendar');
    calendarElement.innerHTML = generateCalendarHTML(year, month);
}

// 切換到上一個月
function prevMonth() {
    selectedDate.month--;
    if (selectedDate.month < 1) {
        selectedDate.month = 12;
        selectedDate.year--;
    }
    updateCalendar(selectedDate.year, selectedDate.month);
}

// 切換到下一個月
function nextMonth() {
    selectedDate.month++;
    if (selectedDate.month > 12) {
        selectedDate.month = 1;
        selectedDate.year++;
    }
    updateCalendar(selectedDate.year, selectedDate.month);
}

// 更新所選日期訊息
function updateSelectedDate(selectedDate) {
    const selectedDateElement = document.getElementById('selected-date');
    selectedDateElement.textContent = `所選日期: 民國 ${selectedDate.year - 1911}年 ${selectedDate.month}月 ${selectedDate.day}日`;
    // 在月曆中找到先前所選日期的方格並移除selected-date樣式
    const calendarCells = document.querySelectorAll('.calendar td');
    calendarCells.forEach(cell => {
        cell.classList.remove('selected-date');
    });

    // 找到新的所選日期方格，並為其添加selected-date樣式
    const selectedCell = document.querySelector(`.calendar td[data-day="${selectedDate.day}"]`);
    if (selectedCell) {
        selectedCell.classList.add('selected-date');
    }
}

// 初始化日期選擇元件
function initDatePicker() {
    // 更新初始月曆
    updateCalendar(selectedDate.year, selectedDate.month);

    // 為每個日期格子添加點擊事件
    const calendarElement = document.querySelector('.calendar');
    calendarElement.addEventListener('click', function (event) {
        if (event.target.tagName === 'TD' && event.target.textContent !== '') {
            selectedDate.day = parseInt(event.target.textContent);
            updateSelectedDate(selectedDate);
        }
        if (event.target.id === 'prev-month') {
            prevMonth();
        }
        if (event.target.id === 'next-month') {
            nextMonth();
        }
    });
}

// 調用初始化函數
window.onload = function () {
    initDatePicker();
};