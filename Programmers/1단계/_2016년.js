function solution(a, b) {
    let day = ['SUN','MON','TUE','WED','THU','FRI','SAT'];
    const Mon = [31,29,31,30,31,30,31,31,30,31,30,31]; //매달 마지막일
    var sum = 0;
    
    for(let i=0; i<a-1; i++){ // 예를 들어 a값이 5로 들어왔을때, 4월까지만 Mon값 더해주어야함
        sum += Mon[i]; //월별로 일수 더해준다.
    }
    
    sum += b+4; // 1월 1일이 금요일이므로 그만큼 값인 4 더해주어야함. 만약 1월 1일이 목요일이었다면 +3
    return day[sum%7];
}