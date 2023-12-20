console.log("hello, world");
let age : number = 20;
if (age < 50)
    age += 10;
console.log(age);
let user: [number, string, boolean, number] = [0, "Bruce", true, 0];
enum Size{
    small = 1,
    medium,
    large
}
let mySize = Size.large;
console.log(mySize)

function tax(income: number, year = 2022){
    if(year == 2022){
        return income * 1.2;
    }
    return income * 1.3;
}

console.log(tax(20000, 2023));