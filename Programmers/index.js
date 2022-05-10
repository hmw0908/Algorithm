const fs = require('fs');
let inputData = fs.readFileSync('./example.txt').toString();
console.log(inputData);
inputData = inputData.split('\n');
console.log(inputData);

const A = parseInt(inputData[0]);
const B = parseInt(inputData[1]);

console.log(A-B);