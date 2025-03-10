# kuBig2025
고려대 세종캠퍼스에서  C  수업에 사용하는 저장소이다.

----------------
# 2025-3-04
---------------
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

---------------------
# 2025-03-05
---------------------
-세번째 수업시간입니다.

---------------------

# 2025-03-06
---------------------
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

5. 삼항 연산자
- (조건) ? 문장1 : 문장2
true일 경우 문장1 수행, false이면 문장2 수행


7. 식별자 규약
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

-------------------------------------

#2025-03-10
qsort
우선 qsort는 <stdlib.h>라는 헤더파일에 존재합니다. 그렇기에 먼저 #include <stdlib.h>를 선언해줘야 합니다.

//예시
qsort(﻿①정렬할 값의 주소, ﻿②요소의 개수, ﻿③요소의 크기, ﻿④기준 함수);
qsort(N, 10, sizeof(int), compare);

① 정렬할 값의 주소: 배열 N이 있다고 하면 N을 적어주시면 해당 배열에 대해 정렬을 시작합니다.

② 요소의 개수: 정렬할 요소가 몇 개 있는지 정수로 적어주시면 됩니다.

③ 요소의 크기: 요소 한개당 몇 바이트인지 적어주시면 됩니다. sizeof연산자를 이용하시면 편합니다.

④ 기준 함수: 정렬을 어떤식으로 할 건지 기준 함수를 만들어 그 함수 이름을 이곳에 적어줍니다.


//오름차순 예시
int compare(const int* a, const int* b) {
	return(*a - *b);
}

 return함수: return함수가 양수이면 두 수의 자리를 바꾸고, 음수이면 자리를 바꾸지 않습니다.

*a는 포인터 변수 a가 가리키는 실제 값을 의미하므로 왼쪽의 수 a와 오른쪽의 수 b를 서로 빼서
a가 b보다 크면 a-b일 때 return값이 양수
b가 a보다 크면 a-b일 때 return값이 음수 이므로
a가 b보다 클 때만 두 수의 위치가 바뀌게 됩니다. 이를 계속 반복하면 자연스럽게 오름차순이 되겠죠?

반대로 내림차순이 되게 하려면 return *b - *a; 로 바꾸시면 됩니다.

 참조링크: https://m.blog.naver.com/ygs1090/223105957292

----------------------------------------------------

포인터: 주소값을 저장하는 변수이다.
*(포인터 변수)-> 값을 나타냄
&-> 주소를 나타냄.
int a=10; a의 값, &a-> a의 주소
int *p=10; p->는 주소, *p -> 값

#포인터는 값을 바로 넣느넥 아니라 변수에 연결을 해줘야함/==포인터는 반드시 대상을 가리키고 역참조를 해야한다는 말이다.
int *pVar;
*pVar=200;
-----------> 오류
int var_b;
int *pVar;
pVar=&var_b;
*pVar=200;
----------------> 정답

----------------------------------------------------

littelendian
bigendian

    int a=0x12345678;
    char *pA;
    pA=(char*)&a;
    printf("*pA: 0x%x \n",*pA);
    /// 78 이 나오면 리틀엔디안, 12가 나오면 빅엔디안

통신에선 리틀엔디안으로 통일

빅 엔디안 방식은 낮은 주소에 데이터의 높은 바이트(MSB, Most Significant Bit)부터 저장하는 방식입니다.

이 방식은 평소 우리가 숫자를 사용하는 선형 방식과 같은 방식입니다.


리틀엔디안은 가장 낮은 자릿수의 바이트부터 메모리에 저장하는 방식이다. 즉, 가장 작은 단위인 바이트의 최하위 비트부터 차례로 메모리에 저장된다. 예를 들어, 32비트 정수 0x12345678을 리틀엔디안 방식으로 저장하면 메모리에는 0x78, 0x56, 0x34, 0x12와 같은 순서로 저장된다. 이는 바이트의 순서가 역순으로 되어있다고 볼 수 있다.

반면에 빅엔디안은 가장 높은 자릿수의 바이트부터 메모리에 저장하는 방식이다. 즉, 가장 큰 단위인 바이트의 최상위 비트부터 차례로 메모리에 저장된다. 예를 들어, 32비트 정수 0x12345678을 빅엔디안 방식으로 저장하면 메모리에는 0x12, 0x34, 0x56, 0x78과 같은 순서로 저장된다. 이는 바이트의 순서가 원래의 순서와 동일하다고 볼 수 있다.

-----------------------------------
다중  포인터(이중): 이중포인터는 포인터를 가르킨다.

**pp->*p->type 변수1
  	->*p+1->type 변수2
이중포인터는 각 단일 포인터의 배열을 가르킬떄 제일 많이 사용한다. 



------------------------------
함수포인터

함수의 이름은 포인터이다.
함수를 주소값으로 참조할 수 있다.
------------------------------
void형 포인터 (포괄형generic pointer)
변수의 형태를  여러가지로 선언하고 싶을때 사용함

void함수 사용: 
1. 함수의 인자가없을떄
2. 리턴값이 없을떄
3. 인자를 받을때 어떤 인자도 받게 설계하기 위해

--------------------------------------------
배열과 포인터

[배열명]

---------
함수에 쓰이는 포인터의 종류
1. 호출하는 쪽의 변수를 바꿀때
2. 배열에 인자를 전달할떄 
3. 구조체 자료를 인자로 전달할때
4. 사용자 정의 연산을 넘길때 
5. 임이의 자료를 넘길때



