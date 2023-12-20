"use strict";
console.log("hello, world");
let age = 20;
if (age < 50)
    age += 10;
console.log(age);
let user = [0, "Bruce", true, 0];
var Size;
(function (Size) {
    Size[Size["small"] = 1] = "small";
    Size[Size["medium"] = 2] = "medium";
    Size[Size["large"] = 3] = "large";
})(Size || (Size = {}));
let mySize = Size.large;
console.log(mySize);
//# sourceMappingURL=t.js.map
