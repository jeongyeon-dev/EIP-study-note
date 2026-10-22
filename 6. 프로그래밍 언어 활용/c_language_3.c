#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* 
 * 2번째 페이지로, 앞 페이지와 누적된 유형 분류 횟수가 기록된다
 *
 * c언어로 된 문제를 분석하고 푸는 장소.
 * 문제 유형별로 정리를 해보자.
 * 
 * 용어/개념 물어보기(서술형): 1회
 * 정렬 알고리즘 => 기본: 1회, do_while 문: 1회
 * 단순 => 계산형: 6회, 재귀형: 3회, 추론형: 1회, 구조체: 1회, case 문: 1회
 * 복잡 => 배열: 1회, 증감 연산자: 1회, 수학적: 1회, 구조체&포인터&연산: 1회
 * 포인터 => 문자열: 5회, 구조체: 2회, 배열: 2회, 구조체&화살표: 2회, 아스키코드: 1회
 * 이중 포인터 => 배열: 1회
 * 기타 => 삼항&비트연산: 1회
 * 
 * 추론형..이란 역순, 소수 등 여러 수와 관련된 계산을 의미한다
 */



/** 포인터.. 구조체? **/
char n[30];

// 반환되는 n이 배열 n의 시작주소로 자동 변환
char *soojebi(){
    // 요 녀석이 입력을 하는 함수라 한다. 실제 c 라이브러리에 있는 함수
    // 계속 이대로 쓰면 배열 n에 덮어쓰는게 반복 됨
    gets(n);
    return n;
}

int main(){
    // 한글은 char 2개에 한 글자 저장
    char *p1=soojebi();
    char *p2=soojebi();
    char *p3=soojebi();

    printf("%s\n", p1);
    printf("%s\n", p2);
    printf("%s\n", p3);
    return 0;
}



/** 빈칸 채워넣기.. 단순 계산 **/
int main(){
    int m=4620;
    int a, b, c , d;

    a= m/1000;
    b=(m%1000)/500;
    c=(m%500)/100;
    d=(m%100)/10;

    printf("1000원 %d개\n", a);
    printf("500원 %d개\n", b);
    printf("100원 %d개\n", c);
    printf("10원 %d개\n", d);
    return 0;
}



/** 빈칸 채워넣기... do_while 문 => bubble 정렬 문제 같음 **/
int main(){
    int arr[]={64, 25, 12, 22, 11};
    // 바이트 단위를 항상 반환한다 => 20/4 = 5
    int n=sizeof(arr)/sizeof(arr[0]);
    int i=0, j, tmp;

    // while과의 차이? => do를 먼저 실행 하고 이후 while로 참/거짓을 봄 => 거짓이면 바로 끊김

    // 정렬 알고리즘
    // 1회 => 11 64 25 22 12
    // 2회 => 11 12 64 25 22
    // 3회 => 11 12 22 64 25
    // 4회 => 11 12 22 25 64
    do{
        j=i+1;
        do{
            if(arr[i] > arr[j]){
                // 자리 바꾸기
                tmp=arr[i];
                arr[i]=arr[j];
                arr[j]=tmp;
            }
            j++;
        }while(i<n);
        i++;
    }while(i<n-1);

    for(i=0; i<=4; i++){
        printf("%d ", arr[i]);
    }
    // 결과값이 11 12 22 25 64 
    // 가 나온다고 함
    return 0;
}



/** 단순 계산 **/
int main(){
    int c=0;
    int i;

    // i는 1, 2, 3 ... 2023까지
    // 이 중 4로 나누어 떨어지는 것이 있으면 count
    // 일단 2000까지 500개가 존재한다. 이후 2004, 2008, 2012, 2016, 2020 5개 추가 => 505개
    for(i=1; i<=2023; i++){
        if(i%4==0) c++;
    }

    printf("%d", c);
    return 0;
}



/** 완전수 문제(약수의 합=본 값) **/
int perfect_number(int n){
    int i, sum=0;

    // 약수를 모두 더하는 로직
    for(i=1; i<=n/2; i++){
        if(n%i==0){
            sum+=i;
        }
    }

    // 약수의 합 = 본 숫자 값 이면 true 반환
    if(n==sum)
        return 1;

    return 0;
}

int main(){
    int i, sum=0;

    for(i=2; i<=100; i++){
        if(perfect_number(i))
            sum +=i;
    }

    // 외우자 6 + 28 = 34
    printf("%d", sum);
    return 0;
}



/** 포인터 개념 문제 **/
// struct Person arr[2] = { .. }
// struct Person *p = arr 뭐 이런 식일 때
// p[1].age 가능
// (p + 1)->age 가능 => 역참조(주소값에서 구조체 레벨로 올라옴)와 접근(.)을 합친 문법
//(*(p + 1)).age 가능



/* ===== 30문제 풂 ===== */



/** 비교적 간단한 재귀함수 문제 **/
int soojebi_1(int n){
    if(n<=1){
        return n;
    }else{
        // 손코딩으로 풀었음~
        return soojebi_1(n-1) + soojebi_1(n-3);
    }
}

int main(){
    printf("%d", soojebi(7));
    return 0;
}



/** 포인터 문제 .. 간단 연산 문자열 **/
int main(){
    char *p="KOREA";            // 문자열 KOREA의 시작 K의 주솟값을 가진다
    printf("%s\n", p);          // 처음부터 \0까지 => KOREA
    printf("%s\n", p+1);        // 두 번째 부터 \0까지 => OREA
    printf("%c\n", *p);         // 시작 주솟값의 값 => K
    printf("%c\n", *(p+3));     // 시작 주솟값에서 3번 이동.. 이후 그 값 => E
    printf("%c\n", *p+4);       // 시작 주솟값의 값: K에서 4 더하기.. 알파벳 순으로 이동 => O
    return 0;
}



/** 삼항연산자 + 비트연산 **/
int main(){
    int v1=0, v2=35, v3=29;
    // 0일 경우 시행을 안하고 나머지 수(음수 포함)면 수행한다
    // 0 > 25가 사실이 아니므로, v1 이 나옴. 즉 0이므로 false가 된다
    if(v1>v2 ? v2:v1){
        v2=v2 << 2;
    }else{
        // 얘가 계산됨
        // v3.. 이진법으로: 11101 .. 얘를 비트연산하면 1110100 => 116
        v3=v3 << 2;
    }

    // 116 + 35 = 151
    printf("%d", v2+v3);
    return 0;
}



/** 문자열 + 포인터.. 좀 난잡하다 **/
// 첫 번째를 바라보는 포인터로 자동 변환
void fn(char *str){
    char t;
    // \0이 나오기 전 까지 계속 재는 len 함수 => 8나옴
    int len=strlen(str);

    // str 시작 점
    char *p1=str;
    // 시작점 + 7 => H가 있는 주소값
    char *p2=str+len-1;

    // 비교: 같은 문자열이라면 뒤에 있는 곳이 보통 크다
    // 사실상 중앙을 기준으로 대칭으로 값 바꾸는 연산
    while(p1<p2){
        t=*p1;
        // 동일한 역참조. p2주소값의 값을 가져와 => p1 주소값의 값을 해당 값으로 바꾼다
        *p1=*p2;
        *p2=t;

        p1++;
        p2--;
    }
}

int main(int argc, char *argv[]){
    // 그냥 문자열이다 H 이후에는 \0으로 채워짐
    char str[100]="ABCDEFGH";
    int len, i;

    fn(str);
    len=strlen(str);

    // str 출력하는 함수
    // HGFEDCBA에서 GECA를 출력한다
    for(i=1; i<len; i+=2){
        printf("%c", str[i]);
    }
    return 0;
}



/** 난해한 문제.. **/
// 동일한 구조체나 간단히 선언 가능
typedef struct{
    int acc;
    double bal;
}Acc;

// 1.1과 3이 들어간다.
double fn_1(double b, int y){
    int i;
    double r=1.0;
    
    // i는 0, 1, 2 이렇게.. r에다가 1.1을 곱한다 => 1.331
    for(i=0; i<y; i++){
        r=r*b;
    }
    return r;
}

void init(Acc *a, int x, double y){
    a->acc=x;
    a->bal=y;
}

void A(Acc *a, double en){
    if(en>0 && en<a->bal){
        a->bal=a->bal-en;
    }else{
        a->bal=a->bal+en;
    }
}

void B(Acc *a){
    a->bal=a->bal * fn_1((1+0.1),3);
}

int main(){
    Acc ba;
    // ba 구조체에 각각 9981, 2200.0이 들어간다
    init(&ba, 9981, 2200.0);

    // en=100.0이고, 0보다 크다. bal 보다 작으므로 true => 구조체의 bal은 -=100을 하여, 2100.0이 된다
    A(&ba, 100.0);
    // bal이 또 조작된다.. 기존 bal에 fn()함수를 곱하는 것
    // 2100에 1.331을 곱해 =>2795.1이 된다
    B(&ba);

    // 두 번째 => 소수점 2자리까지 반올림
    // 안바뀐 9981, 2자리까지 한 2795.10 이 출력
    printf("%d and %.2f", ba.acc, ba.bal);
    return 0;
}



/** 복잡한 연산 .. 아스키 코드 기반 연산인 듯 **/
int main(){
    char *p="It is 8";
    char result[100];
    int i;

    // I => N, t => 한 바퀴 돌아 d, i => s, s => 한 바퀴 돌아 c
    // 8 => 1
    for(i=0; p[i]='\0'; i++){
        // 윗 대문자 => p[i]-'A'+5 .. 재 자리로 돌아와서 +=5 한다. 문자 수 만큼 나눈 후 + 'A': 사실상 5자리 업
        // %26 덕에 한 바퀴 재자리 돌기 가능
        if(isupper(p[i]))
            result[i]=(p[i]-'A'+5)%26+'A';
        else if(islower(p[i]))
            result[i]=(p[i]-'a'+10)%26+'a';
        // 숫자는 0 -> 1 ... -> 9 까지 한 바퀴
        else if(isdigit(p[i]))
            result[i]=(p[i]-'0'+3)%10+'0';
        // 그냥 space 바 이면 그대로
        else if(!(isupper(p[i]) || islower(p[i]) || isdigit(p[i])))
            result[i]=p[i];
    }

    result[i]='\0';
    printf("%s\n", result);
    return 0;
}