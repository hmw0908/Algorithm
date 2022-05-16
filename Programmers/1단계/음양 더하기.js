function solution(absolutes, signs) {
    let fal = 0;
    let tru = 0;
    
    for(let i=0; i<absolutes.length; i++){
        if(signs[i] == false){
            fal += absolutes[i];
        }
        else{
            tru += absolutes[i];
        }
    }
    let answer = tru -fal;
    
    return answer;
}