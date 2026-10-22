#include <stdio.h>

/* 
 * 2번째 페이지로, 앞 페이지와 누적된 유형 분류 횟수가 기록된다
 *
 * c언어로 된 문제를 분석하고 푸는 장소.
 * 문제 유형별로 정리를 해보자.
 * 
 * 용어/개념 물어보기(서술형): 1회
 * 정렬 알고리즘 => 기본: 1회, do_while 문: 1회
 * 단순 => 계산형: 6회, 재귀형: 2회, 추론형: 1회, 구조체: 1회, case 문: 1회
 * 복잡 => 배열: 1회, 증감 연산자: 1회, 수학적: 1회
 * 포인터 => 문자열: 4회, 구조체: 2회, 배열: 2회, 구조체&화살표: 2회
 * 이중 포인터 => 배열: 1회
 * 
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