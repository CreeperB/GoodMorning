document.addEventListener("DOMContentLoaded", function () {
    const productPriceInput = document.getElementById("productPrice");
    const targetCurrencyDropdown = document.getElementById("targetCurrency");
    const convertedPriceSpan = document.getElementById("convertedPrice");
    const currencyRatesDiv = document.getElementById("currencyRates");

    // Sample exchange rates JSON (replace with actual data)
    const exchangeRates = {
        usdToTwd: 30.95,
        cnyToTwd: 4.31,
        eurToUsd: 1.09,
        usdToJpy: 141.59,
        gbpToUsd: 1.27,
        audToUsd: 0.67,
        usdToHkd: 7.83,
        usdToCny: 7.19,
        usdToZar: 18.74,
        nzdToUsd: 0.61,
    };

    // Function to update converted price
    function updateConvertedPrice() {
        const productPriceUSD = parseFloat(productPriceInput.value) || 0;
        const targetCurrency = targetCurrencyDropdown.value;
        const exchangeRateKey = `usdTo${targetCurrency}`;
        const exchangeRate = exchangeRates[exchangeRateKey] || 1;
        const convertedPrice = (productPriceUSD * exchangeRate).toFixed(2);
        convertedPriceSpan.textContent = convertedPrice;
    }

    // Event listeners
    productPriceInput.addEventListener("input", updateConvertedPrice);
    targetCurrencyDropdown.addEventListener("change", updateConvertedPrice);

    // Function to display exchange rates in Frame 2
    function displayExchangeRates() {
        currencyRatesDiv.innerHTML = "";
        for (const currency in exchangeRates) {
            const rate = exchangeRates[currency];
            currencyRatesDiv.innerHTML += `<p>${currency}: ${rate}</p>`;
        }
    }

    // Initial display of exchange rates
    displayExchangeRates();
});
