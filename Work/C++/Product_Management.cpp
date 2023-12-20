#include <cctype>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

// criteria
const int CRI_PRICE = 1;
const int CRI_COST = 2;
const int CRI_GROSS = 3;
const int CRI_QTY = 4;
const int CRI_REVENUE = 5;
const int CRI_PROFIT = 6;

const int MAX_NAME_LEN = 100;

class Item {
   private:
    char* name;
    int materialCost;

   public:
    // n: name , mc: material cost
    Item(char* n, int mc);
    ~Item();
    int getMaterialCost() const;
    char* getName() const;
};

// constructor
Item::Item(char* n, int mc) {
    this->name = new char[strlen(n) + 1];
    strcpy(this->name, n);
    this->materialCost = mc;
}

// destructor
Item::~Item() {
    delete[] this->name;
}

// get material cost
int Item::getMaterialCost() const {
    return this->materialCost;
}

// get name
char* Item::getName() const {
    return this->name;
}

class Product {
   private:
    char* name;
    int price;
    int cost;
    int salesQty;
    int gross;    // There is no need to store gross, revenue, profit since it's redundent.
    int revenue;  // These variables are only stored to speed up the operation.
    int profit;   // You can adopt different solutions depending on the situation.
    int itemIdx;
    int itemCnt;
    Item** itemList;
    void updateInfo();

   public:
    Product(char* name, int price, int cost, int salesQty, int itemCnt);
    ~Product();
    Product(const Product& p);
    int getProfit() const;
    char* getName() const;
    void addItem(Item* item);
    void print() const;
    bool isInFrontOf(const Product& p, int criterion) const;
};

// constructor
Product::Product(char* name, int price, int cost, int salesQty, int itemCnt) {
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
    this->price = price;
    this->cost = cost;
    this->salesQty = salesQty;
    this->itemList = new Item*[itemCnt];
    this->itemCnt = itemCnt;
    this->itemIdx = 0;
    this->updateInfo();
}

// constructor for Product
Product::Product(const Product& p) {
    this->name = new char[strlen(p.name) + 1];
    strcpy(this->name, p.name);
    this->price = p.price;
    this->cost = p.cost;
    this->salesQty = p.salesQty;
    this->itemList = new Item*[p.itemCnt];
    this->itemCnt = p.itemCnt;
    this->itemIdx = p.itemIdx;
    this->updateInfo();
}

// destructor
Product::~Product() {
    delete[] this->name;
}


// update info for other criteria
void Product::updateInfo() {
    this->gross = this->price - this->cost;
    this->revenue = this->price * this->salesQty;
    this->profit = this->gross * this->salesQty;
}

// get profit
int Product::getProfit() const {
    return this->profit;
}

// get name
char* Product::getName() const {
    return this->name;
}

// add item
void Product::addItem(Item* item) {
    this->itemList[this->itemIdx++] = item;
    this->cost += item->getMaterialCost();
    printf("cost: %d\n", this->cost);
    this->updateInfo();
}

// print all info
void Product::print() const {
    cout << this->name << ' ' << this->price << ' ' << this->cost << ' ' << this->salesQty << ' '
         << this->gross << ' ' << this->revenue << ' ' << this->profit << ' ' << '\n';
}

// if a->isInFrontOf(p, c) == True, product a should be sorted in front of product p
bool Product::isInFrontOf(const Product& p, int criterion) const {
    bool nameIsInFrontOf = strcmp(this->name, p.name) < 0;
    switch (criterion) {
        case CRI_PRICE:
            return (this->price > p.price) || (this->price == p.price && nameIsInFrontOf);
        case CRI_COST:
            return (this->cost > p.cost) || (this->cost == p.cost && nameIsInFrontOf);
        case CRI_GROSS:
            return (this->gross > p.gross) || (this->gross == p.gross && nameIsInFrontOf);
        case CRI_QTY:
            return (this->salesQty > p.salesQty) || (this->salesQty == p.salesQty && nameIsInFrontOf);
        case CRI_REVENUE:
            return (this->revenue > p.revenue) || (this->revenue == p.revenue && nameIsInFrontOf);
        case CRI_PROFIT:
            return (this->profit > p.profit) || (this->profit == p.profit && nameIsInFrontOf);
    }
}

void swapPointer(Product*& ptrA, Product*& ptrB);
void sortProduct(Product** products, int productCnt, int criterion);
int firstKProfitSum(Product** products, int k);

int main() {
    int productCnt = 0, itemTotalCnt = 0, relationships = 0;
    cin >> productCnt >> itemTotalCnt >> relationships;
    cin.get();

    Product** products = new Product*[productCnt];
    Item** items = new Item*[itemTotalCnt];
    // read in data and construct objects
    for (int i = 0; i < productCnt; i++) {
        char name[MAX_NAME_LEN + 1] = {0};
        int price = 0, cost = 0, salesQty = 0, item = 0;
        cin.getline(name, MAX_NAME_LEN + 1, ',');  // +1 for the space for '\n'
        cin >> price >> cost >> salesQty >> item;
        cin.get();
        products[i] = new Product(name, price, cost, salesQty, item);
    }

    for (int i = 0; i < itemTotalCnt; i++) {
        char name[MAX_NAME_LEN + 1] = {0};
        int materialCost = 0;
        cin.getline(name, MAX_NAME_LEN + 1, ',');
        cin >> materialCost;
        cin.get();
        items[i] = new Item(name, materialCost);
    }
    for(int i = 0; i < relationships; i++) {
        // format jPhone 41,Screen
        char productName[MAX_NAME_LEN + 1] = {0};
        char itemName[MAX_NAME_LEN + 1] = {0};
        cin.getline(productName, MAX_NAME_LEN + 1, ',');
        cin.getline(itemName, MAX_NAME_LEN + 1, '\n');
        for (int j = 0; j < productCnt; j++) {
            printf("||%s||, ||%s||\n", productName, products[j]->getName());
            if (strcmp(productName, products[j]->getName()) == 0) {
                for (int k = 0; k < itemTotalCnt; k++) {
                    printf("||%s||, ||%s||\n", itemName, items[k]->getName());
                    if (strcmp(itemName, items[k]->getName()) == 0) {
                        products[j]->addItem(items[k]);
                        break;
                    }
                }
                break;
            }
        }
    }

    int criterion = 0, k = 0;
    cin >> criterion >> k;

    sortProduct(products, productCnt, criterion);
    cout << firstKProfitSum(products, k);

    for (int i = 0; i < productCnt; i++)
        delete products[i];  // not delete [] products[i];
    delete[] products;
    return 0;
}

// swap two pointer
void swapPointer(Product*& ptrA, Product*& ptrB) {
    Product* temp = ptrA;
    ptrA = ptrB;
    ptrB = temp;
}

// sort product according to criterion
void sortProduct(Product** products, int productCnt, int criterion) {
    // sort the products according to criterion desecendingly; just a bubble sort
    for (int i = productCnt - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (products[j + 1]->isInFrontOf(*products[j], criterion))
                swapPointer(products[j], products[j + 1]);
        }
    }
    return;
}

// sum profit of first k products
int firstKProfitSum(Product** products, int k) {
    int profitSum = 0;
    for (int i = 0; i < k; i++)
        profitSum += products[i]->getProfit();
    return profitSum;
}
