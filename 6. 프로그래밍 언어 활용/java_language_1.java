
/*
 * 유형 분석
 * 개념 => 생성자: 1회
 * 단순 => 반복문: 2회, case문: 1회, 클라스 생성: 1회, 연산: 1회, 배열: 2회, static: 2회
 * 복잡 => 상속/생성자: 1회, 추상 클라스/메서드&오버로딩/라이딩: 1회, 2진법 연산: 1회, 상속/재귀: 2회
 * 
 */


public class java_language_1{

}

class Soojebi{
    /* 단순 반복문 */
    public static void main(String[] args){
        int i;
        int []a={0,1,2,3};
        // 그대로 => 0 1 2 3 cnffur
        for(i=0; i<4; i++){
            System.out.print(a[i] + " ");
        }
    }


    /* 기본적인 case 문 */
    public static void main_1(String[] args){
        int i=3;
        int k=1;

        switch (i) {
            case 0:
            case 1:
            case 2:
            // 여기서 시작: k.. 0 => 3 => -7 => -8
            case 3: k=0;
            case 4: k+=3;
            case 5: k-=10;
            default: k--;
        }
        System.out.print(k);
    }
}



/* 간단한 클라스 객체 생성 */
class Parent{
    public void show(){

    }
}

class Child extends Parent{
    public void show(){
        System.out.print("Child");
    }
}

class Soojebi_1{
    public static void main(String[] args){
        Parent pa = new Child();
        pa.show();
    } 
}



/* 생성자 + 상속 + 오버로딩/오버라이딩 */
class A{
    private int a;
    public A(int a){
        this.a = a;
    }

    public void display(){
        System.out.println("a=" + a);
    }
}

class B extends A{
    public B(int a){
        // A의 생성자 호출 super a 하기 전에는.. 기본값 0인 상태
        super(a);
        // A의 함수를 상속받았으므로 그대로 사용은 가능
        super.display();
    }
}

class Soojebi_2{
    public static void main(String[] args){
        // B 생성자 호출 => 10 넣음 .. A 생성이 아닌 B 객체가 생성됨, 그러나, A 내의 변수도 동시에 생성
        B obj = new B(10);
    }    
}



/* 단순 계산 */
class Soojebi_3{
    public static void main(String[] args){
        int i=0;
        int sum=0;
        
        // i가 0일 때 부터.. if 를 보면 짝 수만 더함
        // 2+4+6+8+10=30
        while(i<10){
            i++;

            if(i%2==1)
                continue;
            sum+=i;
        }
        System.out.println(sum);
    } 
}



/* 추상 클라스 */
// 자식을 통해서만 객체 생성 가능
abstract class Vehicle{
    String name;

    // 자식 클라스에서 반드시 구현해야 하는 메서드
    abstract public String getName(String val);

    public String getName(){
        return "Vehicle name:"+name;
    }
    public void setName(String val){
        name=val;
    }
}

class Car extends Vehicle{
    public Car(String val){
        setName(val);
    }

    // 부모의 getName 추상 메서드 오버라이딩 하고 있음
    public String getName(String val){
        return "Car name:"+val;
    }

    // 인자값이 다르므로 오버로딩
    public String getName(byte val[]){
        return "Car name:"+val;
    }
}

class Soojebi_4{
    public static void main(String[] args){
        // 참조 변수 타입 .. 실제 객체 타입
        // 부모로 참조 선언하면.. 자식의 고유? 메서드는 사용 못함
        // 자동으로 오버라이딩 되는데 => 실제 객체 타입을 기준으로 됨
        Vehicle obj = new Car("Spark");
        System.out.println(obj.getName());
    } 
}



/* 생성자란? */
// 해당 클라스의 객체가 생성될 때, 자동으로 호출됨 => 이를 통해 기본값이 들어가기도 함 



/* 이진법 계산.. */
class Soojebi_5{
    public static void main(String[] args){
        int []a=new int[8];
        int i=0;
        int n=10;

        // 최소 n이 살아 있을 때 동안은 진행되어야 겠지?
        // i = 0일 때 부터 => 0101000이 넣어져야 함
        while(n > 0){
            // 첫 째 자리에 넣고 이동하는 로직
            a[i++]= n%2;
            // n을 매번 반타작 한다
            // 10 -> 5 -> 2 -> 1 -> 끝
            // 0 1 0 1 이렇게 되어야 함
            n/=2;
        }

        // 끝에서 처음까지 역순으로 출력
        // 10을 이진수로 변환하는 로직
        // 0001010 이 출력되어야 함
        for(i=7; i>=0; i--){
            System.out.println(a[i]);
        }
    }    
}



/* 2차원 배열 선언 문제.. 비교적 간단: 스킵 */



/* 상속 + 재귀 문제 */
class Parent_2{
    public int compute(int num){
        if(num<=1) return num;
        return compute(num-1)+compute(num-2);
    }
}

class Child_1 extends Parent_2{
    public int compute(int num){
        if(num<=1) return num;
        return compute(num-1)+compute(num-3);
    }
}

class Soojebi_6{
    public static void main(String[] args){
        // 참조: 부모형, 실제 타입: 자식
        Parent_2 obj=new Child_1();
        // 자동으로 오버라이딩 됨
        // 재귀로 호출하여 => 1
        // 자식에서 별도로 선언하지 않더라도.. 부모의 것을 그대로 사용이 가능하다
        System.out.print(obj.compute(4));
    }    
}



/* ===== 여기까지 10문제 풂 ===== */



/* 간단한 2차원 배열 접근하기 */



/* 사칙연산 + 반복문 */
class Soojebi_7{
    public static void main(String[] args){
        int i, j;

        // i는 0 -> 1 -> 2 -> 3 -> 4 -> 5 까지..
        // j는 0 -> 1 -> 3 -> 6 -> 10 -> 15
        // 0 +1+2+3+4+5=15 나옴
        for(j=0, i=0; i<=5; i++){
            j+=i;
            System.out.print(i);
            
            if(i==5){
                System.out.print("=");
                System.out.print(j);
            }else{
                System.out.print("+");
            }
        }
    }    
}



/* 재귀 + 상속 */
class ovr1{
    public static void main(String[] args){
        // 실제 부모가 실제 객체니 오버라이딩 되지 않는다
        ovr1 a1=new ovr1();
        ovr2 a2=new ovr2();
        // a1는 비교적 간단하다: 그냥 부모의 것 사용 => 3+2=5
        // a2는 자식의 오버라이딩 된 것 사용 => 3 - 2 + 여기에 super된 부모의 것 사용:5 => 1 + 5 = 6
        // 11 출력
        System.out.print(a1.san(3,2)+a2.san(3,2));
    }

    int san(int x, int y){
        return x+y;
    }
}

class ovr2 extends ovr1{
    int san(int x, int y){
        // super 하려면 부모 class에도 동일한 메서드가 존재해야 함
        return x-y+super.san(x,y);
    }
}



/* static 변수  */
// static: 객체를 생성하지 않아도 존재하는 클래스 변수
class Soojebi_8{
    static private Soojebi_8 instance=null;
    private int count=0;
    // new로 객체를 생성하지 않아도 호출이 가능
    static public Soojebi_8 get(){
        // 안에서는 새 객체를 생성할 수 있으나.. 있으면 기존의 것을 재새용 함
        if(instance==null){
            instance=new Soojebi_8();
        }
        return instance;
    }
    
    public void count(){count++; }
    public int getCount(){return count; }
}

class Soojebi_8_2{
    public static void main(String[] args){
        Soojebi_8 s1=Soojebi_8.get();
        s1.count();
        Soojebi_8 s2=Soojebi_8.get();
        s2.count();
        Soojebi_8 s3=Soojebi_8.get();
        s3.count();

        System.out.print(s1.getCount());
    }
}



/* new 해서 접근하지 않고 바로 사용이 가능하므로 static 
   하나의 클라스 내에서도 static이냐 아니냐에 따라 바로 접근 방식이 다름 */