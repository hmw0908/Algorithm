function solution(n, lost, reserve) {
    let answer = 0;
    let unif = [];
    
    //우선 총 학생수만큼 1로 초기화
    for(let i=0;i<n;i++){ 
        unif[i] = 1;
    }
    
    //[lost]잃어버린 학생 -1
    for(let i=0; i<lost.length; i++){
        unif[lost[i]-1] = 0;
    }
    
    //[reserve]여유분 학생 +1
    for(let i=0; i<reserve.length; i++){
        unif[reserve[i]-1] += 1;
    }
    
    //앞친구가 빌려줬을경우
    for(let i=0;i<n;i++){
        if(unif[i-1] == 2 && unif[i] == 0){
            unif[i-1] = 1;
            unif[i] = 1;
        }
        //뒷친구가 빌려줬을경우
        else if(unif[i+1] == 2 && unif[i] == 0){
            unif[i] = 1;
            unif[i+1] = 1;
        }
    }
    
    //최종 체육복이 있는 학생 계산
    for(let i=0;i<n;i++){
        if(unif[i] > 0)
            answer++;
    }

    return answer;
}