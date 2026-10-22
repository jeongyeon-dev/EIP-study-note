#include <stdio.h>

/* 
 * 2번째 페이지로, 앞 페이지와 누적된 유형 분류 횟수가 기록된다
 *
 * c언어로 된 문제를 분석하고 푸는 장소.
 * 문제 유형별로 정리를 해보자.
 * 
 * 용어/개념 물어보기(서술형): 1회
 * 정렬 알고리즘: 1회 
 * 단순 => 계산형: 4회, 재귀형: 2회, 추론형: 1회, 구조체: 1회, case 문: 1회
 * 복잡 => 배열: 1회, 증감 연산자: 1회
 * 포인터 => 문자열: 4회, 구조체: 1회, 배열: 2회, 구조체&화살표: 1회
 * 이중 포인터 => 배열: 1회
 * 
 * 
 * 추론형..이란 역순, 소수 등 여러 수와 관련된 계산을 의미한다
 */



/** 포인터 문제.. 그런데, 단순 문자열 계산 **/
int len(char *p);

int main(){
    char *p1="2022";
    char *p2="202207";

    // 4 + 6 = 10 이 된다
    printf("%d", len(p1)+len(p2));
    return 0;
}

int len(char *p){
    int r=0;

    // 문자열 맨 마지막은 \0이 들어간다.
    // p에 +1을 하면 char 단위 만큼 포인터가 이동하며, *p의 값을 \0과 비교한다
    // 따라서 사실상 문자열의 길이를 말함
    while(*p != '\0'){
        p++;
        r++;
    }

    return r;
}



/** 포인터.. 배열 **/
int main(){
    int a[4]={0, 2, 4, 8};
    int b[3];

    // int형 포인터 변수
    int *pl;
    int i, j;

    int sum=0;

    // i=1 => a는 배열 a[]의 시작 주소, 즉 pl에는 두 번째 주소가 들어간다
    // b[0]에는 pl 주솟값에 있는 값: 2 에서 배열 a의 첫 번째 값 0을 뺀 값이 들어간다: 2 - 0 = 2 
    // sum은 2(a[1]) + 2(b[0]) = 4를 더해 총 4가 된다

    // i=2 => pl에는 세 번째 주소
    // b[1]에는 4(세 번째 주솟값의 값) - 2(두 번째 값): 4 - 2 = 2가 들어간다
    // sum은 4(a[2]) + 2(b[1]) = 6을 더해 총 10이 된다

    // i=3 => pl에는 네 번째 주소
    // b[2]에는 8 - 4(a[2]) = 4가 들어간다
    // sum은 8(a[3]) + 4(b[2]) = 12를 더해 총 22가 된다 
    for(i=1; i<4; i++){
        pl=a+i;
        b[i-1]=*pl-a[i-1];
        sum=sum+a[i]+b[i-1];
    }

    // 22 출력
    printf("%d", sum);
    return 0;
}



// 뭐 하는 녀석? => 일단 i, j 모두 0 이상이야 유효, h/w 안에서 유효
int calc(int w, int h, int j, int i){
    if(i>=0 && i<h && j>=0 && j<w){
        return 1;
    }
    return 0;
}

int main(){
    int field[4][4] = {{0,1,0,1},{0,0,0,1},{1,1,1,0},{0,1,1,1}};
    int mines[4][4] = {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};

    int w=4, h=4;
    int i, j, k, l;

    for(l=0; l<h; l++){
        for(k=0; k<w; k++){
            // 1인 경우만 연산이 진행된다
            if(field[l][k]==0)
                continue;

            // 해당 세로값 -1 ~ +1 까지 .. 해당 가로값 -1 ~ +1 까지 훑어본다 => 총 9곳
            for(i=l-1; i<=l+1; i++){
                for(j=k-1; j<=k+1; j++){
                    // 총 9 곳 중에서 범위 안에 있는 곳만 모두 1을 추가한다
                    // 일종의 1의 위치로 한 확산식
                    if(calc(w, h, j, i) == 1){
                        // 유일하게 mines 배열에 값이 들어가는 곳
                        mines[i][j]+=1;
                    }
                }
            }
        }
    }

    // 얘는 그냥 배열 출력 함수
    // 수작업으로 계산 해야 한다
    // 1 1 3 2
    // 3 4 5 3
    // 3 5 6 4
    // 3 5 5 3
    for(l=0; l<h; l++){
        for(k=0; k<w; k++){
            printf("%d", mines[l][k]);
        }
        printf("\n");
    }
    return 0;
}



/** 단순 계산형 문제 **/
int main(){
    int i, j, k, s;
    int el=0;

    // i가 6 ~ 30까지 진행
    for(i=6; i<=30; i++){
        s=0;

        // k는 3 ~ 15까지
        k=i/2;

        // 2차 반복문: j는 1 ~ k까지 진행
        // 순차적으로 계산해보자:
        
        // i가 6: j가 1!, 2!, 3!, ... => 1 + 2 + 3 == 6를 s에 더한다
        // 한 마디로 6 ~ 30 까지 각 약수의 합을 더한 것이 s.
        for(j=1; j<=k; j++){
            // i를 j로 나누어 떨어질 경우: s += j함
            if(i%j==0){
                s=s+j;
            }
        }

        // 유일하게 el이 변하는 로직
        // 약수의 합 = 본 수 값인 경우 +1
        if(s==i){
            el++;
        }
    }

    // 노가다 이므로 스킵.. 답은 2라고 한다
    printf("%d", el);
    return 0;
}



/* 포인터 .. 문자열 문제 */
int main(){
    // 이론 상.. a[9999] 해 버리면 a 시작 주솟값을 기준으로 9999 바이트(char 만큼) 이동한 곳
    // 에서의 값을 출력하게 된다
    char a[]="Art";
    char *p=NULL;
    int i=0;

    // p에는 엄밀히 말해 a의 문자의 주솟값만 저장된다. 다만, 연산자로 문자열 연산 가능
    p=a;

    // 연속적으로 주솟값 시작 위치의 "값"을 출력: Art
    printf("%s\n",a);
    // 포인터 변수 p 자체: 배열의 시작점 주소값 => 해당 주소값의 값 출력: A 
    printf("%c\n",*p);
    // 배열 a[]의 a는 배열의 시작점 주소값 => 주소값의 값 출력: A
    printf("%c\n",*a);
    // Art 배열의 시작 주솟값에서.. %s를 통해 그 주소값의 값을 순차적 출력: Art
    printf("%s\n",p);

    for(i=0; a[i]!='\0'; i++){
        // c%는 문자열 중 문자 하나만 출력한다 != s%는 \0이 나올 때 까지 연속적으로 출력
        // c%는 문자 자체의 값만, s%는 주솟값만 받는다
        // a는 그냥 문자 기반 배열이므로, 순서대로 Art를 출력한다
        printf("%c",a[i]);
    }
    return 0;
}



/** 포인터.. 문자열 문제 **/
int main(){
    // 이론 상.. 어디에 저 문자들이 선언되고 a, b는 각각 시작 주솟값을 가진다
    char *a="qwer";
    char *b="qwety";

    int i, j;

    // a자체는 주소값.. 그러나 []를 붙이면 주솟값의 값이 나온다.
    // 사실상 a 문자열 중에 b에 있는 문자열 중 포함된 문자열이 있는지 알아보는 로직
    for(i=0; a[i]!='\0'; i++){
        for(j=0; b[j]!='\0'; j++){
            if(a[i]==b[j]){
                printf("%c",a[i]);
            }
        }
    }
    return 0;
}



/*===== 20 문제 풂 =====*/



int main(){
    int input=10110;
    int di=1;
    int sum=0;

    while(1){
        // 유일한 조건 탈출문.. input은 매번 10씩 나눠지며 최종적으로 0이 된다
        // : 10110 => 1011 => 101 => 10 => 1 => 0!
        if(input==0) break;
        else{
            // 0인 sum에 더해져야 한다. 
            // di는: 1 => 2 => 4 => 8 => 16 .. 까지
            // 따라서 input의 맨 오른쪽 자릿수가 ()안에 들어야 한다: input%10가 답
            sum=sum+(input % 10) *di;
            di=di*2;
            input=input/10;
        }
    }

    // 2진수를 10진수로 변환하는 코드이며.. 여기에슨 10진수 값이 출력됨
    printf("%d", sum);
    return 0;
}



/** 빈칸 채워넣기.. 단순 반복문 => 반복문에 넣자 **/
int main(){
    int n[5]={5, 4, 3, 2, 1};
    int i;

    for(i=0; i<5; i++){
        printf('%d', n[(i + 1)%5]);
    }
    return 0;
}


/** 단순.. case 문 => 다른 언어 case문과 비슷하다:
    break 없으면 거기서 아래까지 쭈욱 실행함 **/
int main(){
    int n[3]={73, 95, 82};
    int i, sum=0;

    // 73 + 95 + 82 = 250
    for(i=0; i<3; i++){
        sum+=n[i];
    }

    // 나누기.. 나머지 남기지 않음: 250/30 = 8
    // case 8에서 쭈욱 걸린다: "BCD"
    switch(sum/30){
        case 10:
        case 9: printf("A");
        case 8: printf("B");
        case 7:
        case 6: printf("C");
        default: printf("D");
    }
    return 0;
}



/** 증감 연산자
    전위 증가: ++a => 증가 후 값 사용 
    후위 증가: a++ => 값 사용 후 증가 **/
#define MAX_SIZE 10

int isWhat[MAX_SIZE];
int point=-1;

// -1이 될 경우 "빔"이 참이됨
int isEmpty(){
    if(point==-1) return 1;
    return 0;
}

// 10될 경우 "참"이 참이됨
int isFull(){
    if(point==10) return 1;
    return 0;
}

void into(int num){
    // 10이 넘으면 Full 출력하고
    if(point>=10) printf("Full");
    // 아니면, isWhat 배열에 idx 올린 곳에 num 배치
    isWhat[++point]=num;
}

int take(){
    // 빔이면 Empty 출력
    if(isEmpty()==1) printf("Empty");
    // 아니면 point 위치 반환 후 -=1 함
    return isWhat[point--];
}

int main(){
    // 각각 보자:
    // isWhat 배열은: 10개의 빈 공간, point = -1.. point = 0
    // isWhat 0번째에 5 저장
    into(5);

    // isWhat 1번쨰에 2 저장, point는 현재 1
    into(2);

    // point가 -1 될 때까지 실행
    while(!isEmpty()){
        // isWhat[1]인 값 반환 => 출력: 2, 이후 point는 0이 됨
        printf("%d", take());
        // isWhat 1번째에 4, 2번째에 1 넣음. point는 2
        into(4);
        into(1);

        // isWhat[2] = 1 출력, point = 1
        printf("%d", take());
        // isWhat[2] = 3 할당, point = 2
        into(3);

        // 각각 isWhat[2], isWhat[1] 값 출력 => 3, 4.. point는 0
        printf("%d", take());
        printf("%d", take());
        // isWhat[1] = 6, point = 1
        into(6);

        // isWhat[1], isWhat[0] 값 출력 => 6, 5 .. poiont는 -1 => break 됨
        printf("%d", take());
        printf("%d", take());        
    }
    return 0;
}