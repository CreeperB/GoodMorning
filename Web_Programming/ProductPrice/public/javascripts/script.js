document.getElementById("inputForm").addEventListener("submit", async function (event) {
    event.preventDefault();

    const formData = new FormData(event.target);
    const date = formData.get('date');
    const product = formData.get('product');
    const price = formData.get('price');

    console.log(date, product, price)
    const res = await fetch('http://localhost:3001/api/submit', { method: 'POST', body: JSON.stringify({ date, product, price }), headers: { 'Content-Type': 'application/json' } });
    // const data = await res.json()

    // var newRow = document.createElement("tr");
    // newRow.innerHTML = "<td>" + date + "</td><td>" + product + "</td><td>" + price + "</td>";

    // var table = document.getElementById("priceTable");
    // table.appendChild(newRow);

    document.getElementById("date").value = "";
    document.getElementById("product").value = "";
    document.getElementById("price").value = "";
    alert("Submit successfully!");
});

document.getElementById("searchForm").addEventListener("submit", async function (event) {
    event.preventDefault();

    const formData = new FormData(event.target);
    const searchKeyword = formData.get('keyword');

    const res = await fetch('http://localhost:3001/api/search', { method: 'POST', body: JSON.stringify({ keyword: searchKeyword }), headers: { 'Content-Type': 'application/json' } });
    
    const data = await res.json()

    var table = document.getElementById("priceTable");
    table.innerHTML = "<tr><th>日期</th><th>品項</th><th>價格</th></tr>";

    for (var i = 0; i < data.length; i++) {
        var newRow = document.createElement("tr");
        newRow.innerHTML = "<td>" + data[i].date + "</td><td>" + data[i].product + "</td><td>" + data[i].price + "</td>";
        table.appendChild(newRow);
    }
    document.getElementById("keyword").value = "";
});
