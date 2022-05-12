function solution(s) {
    var numbers = ["zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"];
    var answer = s;
    for(var i=0; i<numbers.length; i++){
        let arrSplit = answer.split(numbers[i]);
        answer = arrSplit.join(i);
    }
    return Number(answer);
}