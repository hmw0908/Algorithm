function solution(nums) {
    var answer = 0;
    let num = nums.length/2;
    let list = [];
    for(let i=0; i<nums.length; i++){
        if(list.length < num){
            if(!list.includes(nums[i])){
                list.push(nums[i]);
            }
        }
    }
    answer = list.length;
    return answer;
}