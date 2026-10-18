#include <stdio.h>

/* 
 * c언어로 된 문제를 분석하고 푸는 장소.
 * 문제 유형별로 정리를 해보자.
 * 
 * 용어/개념 물어보기(서술형): 1회
 * 정렬 알고리즘: 1회 
 * 단순 => 계산형: 2회, 재귀형: 2회, 추론형: 1회, 구조체: 1회
 * 포인터 => 문자열: 1회, 구조체: 1회, 배열: 1회, 구조체&화살표: 1회
 * 이중 포인터 => 배열: 1회
 * 
 * 
 * 추론형..이란 역순, 소수 등 여러 수와 관련된 계산을 의미한다
 */

int main(){
    int i, j;
    int temp;
    int a[5] = {75, 95, 85, 100, 50};

    for(i=0; i<4; i++){
        for(j=0; j<4; j++){
            // 여기가 조건이다.
            // 이전 값이 앞 값보다 크다면? => 둘의 자리를 바꾼다.
            if(a[j]>a[j+1]){
                temp=a[i];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }

    // 이는 "정렬 알고리즘" 문제
    // 0차: 75 85 95 50 100
    // 1차: 75 85 50 95 100
    // 2차: 75 50 85 95 100
    // 3차: 50 75 85 95 100

    // 출력 방식: 각 요소를 "숫자"로 출력하고 space 함
    for(i=0; i<5; i++){
        printf("%d ", a[i]);
    }
}


/** 단순 계산형 문제 **/
int main(){
    int i=0, c=0;

    // 일단 10번 반복을 함
    // 0부터 계속 곱하니까... 결과는 어차피 0
    while(i<10){
        i++;
        c *= i;
    }

    print("%d", c);
    return 0;
}



/** 단순 재귀형 문제 **/
int r1(){
    return 4;
}

int r10(){
    return(30+r1());
}

int r100(){
    return(200+r10());
}

int main(){
    // 200 + (30 + (4)) = 234
    printf("%d\n", r100());
    return 0;
}


/** 포인터 문자열 대상 문제 **/
int main(){
    // char p = "korea" 는 안된다. 왜냐하면 문자 하나만 저장이 가능 
    // char 특성 상 "하나" 만 저장이 가능하다. 따라서 *p는 문자열 korea의 가장 앞 주소값만 저장.
    char *p = "KOREA";
    
    // %p => 포인터 이니 얘는 주소값을 출력하게 된다.
    // %s => 시작부터 \0에 도달할 때까지 출력: KOREA
    printf("%s\n", p);

    // 주소를 자연수로 연산. 엄밀히 말해 p+p도 가능.
    // 시작 주소에서 +3 이동: e, 여기서 \0까지 출력: EA
    printf("%s\n", p+3);

    // %c => 문자 하나를 출력하라
    // 선언이 아닌 사용부에서 *p: p주소지의 값을 가져와라.. 따라서 시작주소의 문자: K
    printf("%c\n", *p);

    // 먼저 포인터 연산, +3 이동하여 e의 위치
    // e의 위치의 주소값이 있는 곳의 값을 가져와라.. 따라서: E
    printf("%c\n", *(p+3));

    // 이미 *p로 값을 가져왔다: K
    // 여기에 연산을 하면 아스키 코드 식 문자열 연산이 된다: K + 2 = M
    printf("%c\n", *p+2);
    return 0;
}



/** 포인터 구조체 대상 문제 **/
struct Soojebi_1 {
    char name[10];
    int age;
};

int main(){
    struct Soojebi_1 s[]={
        "Kim", 28, "Lee", 38, "Seo", 50, "Park", 35
    };

    // 위의 p의 경우 +1 하면 문자 하나 만큼 이동하나, 
    // 여기서는 Soojebi 가 차지하는 공간(size of) 만큼 이동한다.

    struct Soojebi_1 *p;

    // 첫 째 주소가 할당된다, size of Soojebi 만큼 + 1 한다.
    p=s;
    p++;

    // 포인터로 값 찾기: 두 번째인 Lee, 38이 출력된다.
    printf("%s\n", p->name);
    printf("%d\n", p->age);
    return 0;
}



/** 포인터 배열 대상 문제 **/
int main(){
    int ary[3]={1};
    int s=0;
    int i=0;

    // 배열 ary를 그냥 ary로 사용하면 포인터 주소(배열 첫 째 값의)가 된다
    // 그러니 1의 주소값이고 +0 이므로 그대로 1의 주소값. *역 했으니 1이 그대로 1이 나오고
    // 1 + 2 = 3
    ary[1]=*(ary+0)+2;

    // 1 + 3 = 4
    ary[2]=*ary+3;


    // 0에 배열의 값들을 더함: 0 + 1 + 3 + 4 = 8
    for(i=0; i<3; i++){
        s=s+ary[i];
    }

    print("%d",s);
    return 0;
}



/** 단순 계산 문제 **/
int Soojebi(int base, int exp){
    int i, result=1;

    // exp: 10 => i는 0~9까지 진행
    // 1에다가 계속 *2, *3, *4.. *9까지 진행
    for(i=0;i<exp;i++)
        result *=base;
        
    // 답은 1024
    return result;
}

int main(){
    print("%d", Soojebi(2,10));
    return 0;
}



/** 이중 포인터 배열 문제 **/
int main(){
    // int형? 포인터 주솟값 3개를 넣을 수 있는 배열이다;
    int *arr[3];
    int a=12, b=24, c=36;

    // 각 a, b, c의 주솟값이 arr에 들어간다
    arr[0]=&a;
    arr[1]=&b;
    arr[2]=&c;

    // arr[1]는 b의 주솟값, 이 주솟값에 있는 값을 말하는 거니 24가 된다
    
    // arr 자체는 arr[]라는 배열의 (시작) 주솟값을 의마한다
    // 따라서 *arr => 시작 주솟값에 있는 값 => a의 주솟값 => **arr: 그 주솟값의 값 => 12
    // 24 + 12 + 1 = 37
    printf("%d\n", *arr[1]+**arr+1);
    return 0;
}



/** 구조체 + 화살표 + 연산 **/
struct Soojebi_2{
    char name[20];
    int os, db, hab1, hab2;
};

// 주의!. 여기서 중간의 + 는 다른 포인터 연산 후 최종적으로 더하는 역할을 한다
int main(){
    struct Soojebi_2 s[3]={{"데이터1",95,88},{"데이터2",84,91},{"데이터3",86,75}};
    struct Soojebi_2 *p;

    // s[0]은 순전 첫 번째의 객체? => 이것의 주솟값을 p에 넣음.
    p=&s[0];
    
    // Soojebi 단위 연산 따라서 p+1: 두 번째 객체 
    // 두 번째 객체 ->os: 84    +    세 번째 객체 ->db: 75
    // 두 번째 객체 ->hab1 == 159가 됨
    (p+1)->hab1=(p+1)->os+(p+2)->db;

    // 두 번째 객체 ->hab1: 159    +    첫 번째 객체 ->os: 95     +     첫 번째 객체 ->db: 88
    // 두 번째 객체 ->hab2 == 159 + 95 + 88 = 342
    (p+1)->hab2=(p+1)->hab1+p->os+p->db;

    printf("%d\n",(p+1)->hab1+(p+1)->hab2);
    return 0;
}



/*===== 10 문제 풂 =====*/



/** 재귀함수... 피보니치? **/
int fn(int a){
    if(a<=1) return 1;

    // 5가 입력 되었다:
    // 5 * fn(4)
    // 5 * (4 * fn(3))
    // 5 * (4 * (3 * fn(2)))
    // => 5 * 4 * 3 * 2 * 1 = 120
    return a * fn(a-1);
}

int main(){
    int a;
    scanf("%d", &a);
    printf("%d", fn(a));
    return 0;
}



/** 빈칸 추론형 문제: 반복문.. 전형적인 역순 만들기 문제 **/
int main(){
    int number=1234;
    int div=10;
    int result=0;

    // result가 4321(역순) 이 나왔다고 한다. 빈 칸에 뭘 넣어야 할까?
    // 먼저 number는 0 보다 커다.. 식으로 조건이 있어야 할 듯
    // 기존 숫자에 10을.. 곱해서 자릿수를 왼쪽으로 옮긴다
    // 맨 오른쪽 자릿수를 result에 옮겨야 하니 %가 좋을 듯
    // 맨 오른쪽 자릿수를 없애 총 자릿수를 -1 해야 하니 /가 좋을 듯
    while(number > 0){
        result=result*div;
        result=result+number%div;
        number=number/div;
    }

    printf("%d",result);
    return 0;
}



/** 수학적 접근: 소수와 최대공약수 **/
// 소수임을 판별한다 소수일 경우: 1, 아닐 경우: 0
int isPrime(int number){
    int i;

    for(i=2; i<number; i++){
        if(number%i==0) return 0;
    }

    return 1;
}

int main(){
    int number=13195, max_div=0, i;

    for(i=2; i< number; i++)
        // 2부터 13195까지 가는데...
        // 만약 => n이 소수이고 & 13195가 n으로 나누어 떨어진다면
        if(isPrime(i)==1 && number%i==0)
            // 그 숫자 중 제일 큰 수가 max_div가 된다
            max_div=i;
    
    // 먼저 13195 약수(소수)들을 찾자 => 5, 7, 13, 29
    // 이들 중 가장 큰 29 가 답
    printf("%d", max_div);
    return 0;
}



/** 단순 계산형 + 구조체 **/
struct student{
    int n, g;
};

int main(){
    // 구조체 2개를 넣는 배열 생성
    struct student st[2];
    int i=0;

    // i = 0일 때 => 배열 첫 째의 n은 0, 배열 첫 째의 g는 1
    // i = 1일 때 => 배열 둘 째의 n은 1, 배열 둘 째의 g는 2
    for(i; i<2; i++){
        st[i].n=i;
        st[i].g=i+1;
    }

    // 배열 첫 째의 n + 배열 둘 째의 g => 0 + 2 == 2
    printf("%d", st[0].n+st[1].g);
    return 0;
}