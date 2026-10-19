

# Python 언어로 된 문제를 분석하고 푸는 장소. 
# 문제 분석 및 유형 분류하기
#
# 단순 => 세트: 1회, 배열: 1회, 클라스: 1회, 비트연산: 1회, 참/거짓: 1회, 함수: 1회. 문자열: 1회
# 질문형 => 함수 물어보기: 1회



# 01: 세트(키-벨류 아니므로 딕셔너리 아님)
a={'한국', '중국', '일본'}
a.add('베트남')

# 중복을 허용 안함
a.add('중국')
a.remove('일본')

# 중복을 허용 안하는 만큼, 새 것만 들어감
a.update('홍콩', '한국', '태국')

# : 한국, 중국, 홍콩, 베트남, 태국.. 이렇게 => 순서는 상관 없음
print(a)



# 02: 배열(print는 줄바꿈이 기본임)
lol=[[1,2,3],[4,5],[6,7,8,9]]

# 당연히 첫 행을 출력하고.. 다음은 특정 행의 열의 한 요소를 출력한다
print(lol[0])
print(lol[2][1])

for sub in lol:
    for item in sub:
        # 행의 각 요소들을 space 간격으로 출력 줄바꿈이 안된다
        print(item, end=" ")
    # 다음 행일 경우 enter
    print()



# 03: 클라스 + 문자열 문제
class Soojebi:
    li=['Seoul','Kyeonggi','Incheon','Deajeon','Deagu','Pusan']

s=Soojebi

str01=''

# 각 li의 단어는 => i, 이 단어의 맨 앞 글자 i[0]을 각각 더해서 새 문자열 만듦: SKIDDP
for i in s.li:
    str01=str01+i[0]
print(str01)



# 04: 비트연산(오른쪽 계속 shift하여 사라지는 것도 가능)
a=100
i=0
result=0

# 1 => result에서 a를 오른쪽으로 1만큼 shift 한다: 1100100 => 110010.. 100 => 50
# 이후 1을 더해 51이 된다

# 2 => 2만큼 오른쪽 shift: 1100100 => 11001: 100 => 25
# 이후 1을 더해 26이 된다
for i in range(1,3):
    result=a>>i
    result+=1
print(result)



# 05: boolean 단순 계산 => 같냐 유무가 print 내에서 판별이 된다
a, b = 100, 200
print(a==b)



# 06: 단순 함수 => 인자 기본 설정.. input에 없을 경우 그대로 사용
def func(num1, num2=2):
    print('a=', num1, 'b=', num2)
func(20)



# 07: 질문형.. 함수 물어보기
# 리스트에 한 꺼번에 여러 요소 추가하는 함수: extend()
# 마지막 요소를 삭제하고 이를 반환: pop()
# 역순으로 뒤집는 함수: reverse()



# 08: 문자열 파싱 및 출력
# [:3] => 처음부터 3번쨰 까지.. 따라서, 'REM', [12:16] 12~16까지.. 따라서, 'EMBE'
a='REMEMBER NOVEMBER'
b=a[:3]+a[12:16]

# 중간 %s 위치에 'STR'를 넣는다
c='R AND %s'%'STR'

# 이렇게 해서.. REMEMBE + R AND STR 가 된다
print(b+c)