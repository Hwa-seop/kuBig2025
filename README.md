# kuBig2025
고려대 세종캠퍼스에서  C  수업에 사용하는 저장소이다.

---
# 2025-3-04
---
1. Vmware 설치
Ubuntu 22.04 설치

2.Gitbub
Github 계정 생성
Github 저장소 생성
Github 저장소 Clone

3.
리눅스 설명
4.
간단한 프로그램 작성 nano (infinit.c)
5. C 언어 설명
자료형
숫자형 - 정수형, 실수형

온도 예제 작성 celcius2fahr.c

makefile 작성
make 실행
char 설명 및 예제 작성 charNumber.c
복습 및 정리

-----
# 2025-03-05
----
-세번째 수업시간입니다.
----

# 2025-03-06
-------
1. if문
-조건이 참이면 블럭을 수행, 거짓이면 블럭을 수행 하지 않는다.

if(조건)
{ 
  블럭
}

2. if else
	if(조건1)
	{A블럭}
	else if(조건2)
	{B블럭}
	else 
	{C블럭}

->조건1이 참이면  A수행, 거짓이면 조건2 확인
->조건2가 참이면 B블럭 수행, 거짓이면 else로 이동
->c블럭 수행

3. switch문

switch(변수)
{	case: 0
	A
	case: 1
	B
	case: 2
	C
	case: 3
	D
...
	default
}
	F

변수(int)값에 따라서 해당 case문으로 이동한다
ex) 변수=2일때  case2,3 문 출력: CDF
	

4. while(조건문)
{
 if( ) 
{}
}

5. 삼항 연산자 (조건)? 문장1 : 문장2
true이면 문장1, false이면 문장2 수행


6. 식별자 규약
의미가있는 구절
Type : int,float 등,, 소문자
구조체,클래스, 내가 원하는 것은 첫글자대문자로 ex) Mydata

snake case:(언더바(_)로 연결)


int main(int argc, char*argv[])

-int main(int argc, char *argv[]) 함수에서는 윈도우나 리눅스 같은 OS 명령 프롬포트를 이용해 인자를 전달해서 작동할 수 있도록 한다. 

1. int argc
- argc = argument count
- argc는 운영체제가 이 프로그램을 실행했을 때 전달되는 인수의 갯수이다. 
- 즉, main()함수에 전달되는 데이터의 갯수를 의미한다.

2. char *argv[]
- argv = argument variable
- char *argv[]: 문자열의 주소를 저장하는 포인터 배열
- argv[0]은 프로그램의 실행경로이다. 
- argv[1], argv[2] ... 에는 순서대로 사용자가 입력한 argument가 저장된다. 
 
예를 들어, int main(int argc, char *argv[])에 ./tiny 8000 aaa이라는 입력을 준다면, 
argc는 2개일 것이고, argv[0]에는 실행경로인 ./tiny가 들어가고, argv[1]에는 8000이 들어가고, argv[2]에는 aaa가 들어갈 것이다. 
=> argv의 각 인자는 띄어쓰기로 구분된다. 
	

atoi: 문자 스트링을 정수로 변환

----------------
