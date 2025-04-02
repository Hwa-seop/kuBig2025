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

# 2025-03-10

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
    /// 78 이 나오면 리틀 엔디안, 12가 나오면 빅엔디안

통신에선 빅 엔디안으로 통일

빅 엔디안 방식은 낮은 주소에 데이터의 높은 바이트(MSB, Most Significant Bit)부터 저장하는 방식입니다.

이 방식은 평소 우리가 숫자를 사용하는 선형 방식과 같은 방식입니다.


리틀엔디안은 가장 낮은 자릿수의 바이트부터 메모리에 저장하는 방식이다. 즉, 가장 작은 단위인 바이트의 최하위 비트부터 차례로 메모리에 저장된다. 예를 들어, 32비트 정수 0x12345678을 리틀엔디안 방식으로 저장하면 메모리에는 0x78, 0x56, 0x34, 0x12와 같은 순서로 저장된다. 이는 바이트의 순서가 역순으로 되어있다고 볼 수 있다.

반면에 빅엔디안은 가장 높은 자릿수의 바이트부터 메모리에 저장하는 방식이다. 즉, 가장 큰 단위인 바이트의 최상위 비트부터 차례로 메모리에 저장된다. 예를 들어, 32비트 정수 0x12345678을 빅엔디안 방식으로 저장하면 메모리에는 0x12, 0x34, 0x56, 0x78과 같은 순서로 저장된다. 이는 바이트의 순서가 원래의 순서와 동일하다고 볼 수 있다.

-----------------------------------
다중  포인터(이중): 이중포인터는 포인터를 가르킨다.

**pp->*p->type 변수1
  	->*p+1->type 변수2
이중포인터는 각 단일 포인터의 배열을 가르킬떄 제일 많이 사용한다. 


--------------------------------------------------------------

함수포인터: int (*fp)(int,int);
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
--------------------------------------------------------------
# 2025-03-18

Atmega 128 8bit
STMicro

#AVR 마이크로 컨트롤러의 특징
 -RISC구조
#종류,사양 등
Vmware에 Platform IDE 설치(외계인 모양)
IDE를 활용하여 제어


 PORTC = 0x00;  // 0b00000000 LED 제어, 비트로 되어있음 
        _delay_ms(1000); //1초 대기
        PORTC = 0x0F; // 0b00001111, 
        _delay_ms(1000); 

(volatile unit8_t *)(0x14)=0x03; 메모리 설정.플래쉬 메모리
-------------------------------------------------
DDRx레지스터 배움,방향설정
A,B,C,D,E,F,G (각 8개, G만 5개)
PORTx: 출력B설정,마스킹
--------------------------------------
PINx(port in x)=쓰기는 안됌, 읽기는 가능
DDRx를 0으로 셋(생략가능)-
PORTx->0으로 하면 풀업 설정
--------------------------------
외부 라이브러리 쓰는방법


#2025-03-19
-------------------------------------------------------------------
permission error 문제해결법.
1.  lsusb atmel 연결 버스 확인
2. sudo chmod 666 /dev/bus/usb/002/004
(atmega id에 맞는 번호 입력, 매번 바뀔수있음)

--------------------------------------------
디바운스-채터링현상을 없애기 위해 사용

1. hw 해결: 
-커패시터 연결
-ic회로를 통해서 없앰(슈미트 트리거)
2. sw

정렬 : ctrl k+f

인터럽트: 어떤 작업을 진행하다가 갑자기 다른 일이 발생하여 먼저 처리해야 하는 상황을 인터럽트라고 발생이라고함.
-MCU자체가 하드웨어적으로 그 변화를 체크하여 변화시에만 일정한 동작을 하는 방식
-구성요소: 발생원, 우선순위, 인터럽트 벡터
-종류
폴링

외부인터럽트 8개
UART 레지스터

UART 설정
 ls -al /dev/ttyUSB0
sudo chmod 666 /dev/ttyUSB0

----------------------------------------------------------------------
#25-03-20

udev 세팅
-----------------------------------------------------------------------------------------------------------
lsusb -v 문제확인
idVender
idProduct 확인

sudo nano /etc/udev/rules.d/99-avrisp.rules

나노에서 아래 명령문 두개 실행, idvendor,idproduct 값을 바꿔줘야함

SUBSYSTEM=="usb", ATTR(idVendor)=="0403", ATTR(idProduct)=="6001", MODE="0666"
SUBSYSTEM=="usb", ATTR(idVendor)=="03eb", ATTR(idProduct)=="2104", MODE="0666"

sudo udevadm control
sudo udevadm trigger

idVendor           0x0403 Future Technology Devices International, Ltd
idProduct          0x6001 FT232 Serial (UART) IC

idVendor           0x03eb Atmel Corp.
idProduct          0x2104 AVR ISP mkII

--------------------------------------------------------------------------------------------------

A./D컨버터

타이머/카운터: 
-사용하려면 인터럽트가 필요함


sei();는 전역 인터럽트를 활성화하는 함수입니다.
반대로 cli();는 전역 인터럽트를 비활성화하는 함수입니다.

---------------------------------------------------------------------------------------------------------------

#2025-03-21
udev 규칙 설정 (USB 권한 자동 부여)

1.udev 규칙 설정 
sudo nano /etc/udev/rules.d/99-avrisp.rules

2.udev 규칙 추가 (AVRISP mkII 자동 설정)
# AVRISP mkII 자동 권한 부여

3.udev 규칙 적용
sudo udevadm control --reload-rules
sudo udevadm trigger

4. 현재 사용자가 plugdev그룹에 속해있는지 확인
터미널창에 : groups
출력 예시:  (plugdev가 포함되어 있어야 함)
hwaseop adm dialout cdrom sudo plugdev

5. 적용을 위해 다시 로그인

SUBSYSTEM=="usb", ATTRS{idVendor}=="03eb", ATTRS{idProduct}=="2104", MODE="0666", GROUP="plugdev"

값은 바꿔야함 lsusb 로 확인: lsusb -v


------------------------------
타이머 오버플로우 계산방법

시스템 클럭: 16MHz
분주비: 1024
카운터 범위: 16비트 (TCNT3는 0~65535)
1틱 = 1024 / 16MHz = 64µs
0.3초 = 300,000µs



65535-18750=46785
18750

0.3초 256분주비

분주비/클럭으로 나누고 나눈값을 1틱
구하려는 초/ 1틱 으로 나누고
클럭에서-(구하려는 초/ 1틱 으로 나누고) 값+1 이 나온다.

256/16MHZ=16us
0.3/16us=18750
65535-18750=46785 +1

-----------------------------------------------
#2025-04-01

-라즈베리파이(임베디드 +os)
-운영체제론
-임베디드+os->깊은설정(커널)-> 최적화
		->RTOS(OS같이 여러 프로세스를 다루지지만 임베디드를 최소화하여 사용)

--> 임베디드 리눅스라고한다.

- os 설정시 느려짐
-핸드폰.로봇,키오스크 등

리눅스: 종류가 많음 
-
-------------------------------------
#라즈베리파이 설치 방법
라즈베리 파이 4
운영체제 라즈베리파이 OS 64비트
컴퓨터에 SD카드꽂아야함

사용자이름 : hs
비번 : qwe123 
무선랜: turtle
무선랜 비번 : turtlebot3
무선랜 국가 : KR
로케일 설정- 시간대:Asia/Seoul
		-키보드레이아웃 : us

서비스 SSH 비밀번호 인증사용
옵션 밑에 두개 ON

----VNC설치: vnc viewer 다운로드-windows
https://www.realvnc.com/en/connect/download/viewer/windows/?lai_vid=eeyaMgwXMc4xy&lai_sr=5-9&lai_sl=l
--------------------------------------------------

-리눅스는 POSIX를 지원하기 떄문에 다른 유닉스에서 개발된 애플리케이션을 쉽게 사용할수 있으며. X윈도우 같은 유닉스 표준 GUI 시스템이 지원된다.


ㅕ애
1. 원격 접속ㄴ
와이파이 동글이로 와이파이 접속
turtle, turtlebot3

그다음 인터넷에서 192.168.01 접속
admin
:비번 admin

들어오고 관리도구,


2. 가상환경
sudo apt install net-tools-툴설치
터미널 :ifconifig 
ens33: 192.168 확인

-네트워크 설정 
manage-vurtual machinesetting
vscode창에서 왼쪽 맨 아래 파랑색 누르고 SSH에 연결

터미널에 ssh입력해서 usage확인
터미널에 ssh hs@192.168.0.55 -> 할당 받은 내pc ip
-yes누르고 설치

http://192.168.0.1/sess-bin/timepro.cgi?tmenu=main_frame&smenu=main_frame
누르고ip 확인
--------------------------
sudo raspi-config: 텍스트 인터페이스
5번 선택후 -로테일-0 en_us.utf8-8선택
en_GB.UTF선택

-------------
원격 라즈베리파이 설정
파랑색-connet to host 
-add new ssh host-
-hs@192.168.0.55
-home/hs/ 처음꺼 설정
-오른쪽 아래 connet 누름-> 새창 실행- 비밀번호 입력

3번(Interface options) 들어가고 VNC,I2C,SPI ENABLE
---------------------------
VNCviewer:-ip192.168.0.55입력(하고 들어갔음.
내 ip가(55랑76)이있음
--------------------------------------------
깃 연결: gitclone https://github.com/Hwa-seop/kuBig2025.git
오픈 폴더하고 원래 사용하던 폴더에 접속


라즈베리 파이 실행.
hs@hs:~/kuBig2025/raspberryPi $ cc -o hello  helloRaspberry.c
hs@hs:~/kuBig2025/raspberryPi $ ./hello
안녕하세요!


-와이어링 파일 설치
git clone https://github.com/WiringPi/WiringPi.git
hs@hs:~/kuBig2025/raspberryPi/WiringPi $ sudo ./build

cc-o hello  helloRaspberry.c -lwiringPi
-l을 뒤에 붙여줘야한다.

-----------------------------
현재 git clone 연결

git remote -v 로 본인의 레포지토리로 지정이 되어있는지 확인하시고

git config --global user.name "사용자 이름"
git config --global user.email "이메일 주소"

을 본인에 맞춰 수정해서 입력하시면 git push가 정상적으로 될겁니다
------------------------------------------
표준규약 HAL
led 스위치 제어하고
make 파일 만듦

-------------------------
사용자 모드 .커널 모드가 있는데 권한 설정이 되어있음
메모리 문제 때문에 그럼, 핵심적인것은 커널모드에있음.
메모리 접근을 못하게 되어있음.(보안,리소스관리 등을 위해)
커널을 통해서 접근을 할수밖에 없음


------------------------------------------
make파일

TARGET= helloRaspberry switch_led device_gpio interupt
all: ${TARGET}
CFLAGS = -lwiringPi

% : %.c
	cc -o $@ $< ${CFLAGS}
clean :
	rm ${TARGET}

---------------------------------------------
커널 모듈 추가 책 67P~71P 참고

#2025-04-02

복합적인 프로세스 방법
1. 다중터미널
2. 데몬- 터미널 종속적으로 실행된다
멀티태스킹 운영 체제에서 데몬은 사용자가 직접적으로 제어하지 않고, 백그라운드에서 돌면서 여러 작업을 하는 프로그램을 말한다. 시스템 로그를 남기는 syslogd처럼 보통 데몬을 뜻하는 ‘d’를 이름 끝에 달고 있으며, 일반적으로 프로세스로 실행된다.
3. nohup

프로세스 종료명령어(ps,kil),

tmux(터미널 멀티플렉서): 터미널을 다루는데 터미널이 꺼지지 않음.

-systemd(시스템 데몬): systemd는 리눅스 시스템과 서비스 관리자로, 초기화 시스템(init), 시스템 서비스 관리자, 그리고 세션 관리자의 역할을 합니다. 대부분의 최신 리눅스 배포판에서는 기본 초기화 시스템으로 systemd를 사용합니다. systemd는 시스템의 부팅 과정을 책임지며, 시스템이 가동되는 동안 서비스들을 시작, 중지, 관리합니다.

------------------------------------------------------

터미널 다중제어.
-top : os확인
-tail -f /var/log/syslog
-sudo apt install htop: 설치
-ps -al

nohup htop &
----------------------------------------------------------
touch mydemon.sh
code mydemon.sh


#daemon.sh

#!/bin/bash

mkdir -p /var/log/mydaemon

while true; do
    date >> /var/log/mydaemon/system_info.log
    uptime >> /var/log/mydaemon/system_info.log
    echo "----------------------------" >> /var/log/mydaemon/system_info.log
    sleep 5
done
-----------------------------------------------------
#mydaemon.service

[Unit]
Description=My System Monitor Daemon
After=network.target

[Service]
Type=simple
ExecStart=/home/hwaseop/mydemon.sh
Restart=always
User=root
StandardOutput=append:/var/log/mydaemon/service.log
StandardError=append:/var/log/mydaemon/error.log

[Install]
WantedBy=multi-user.target
-------------------------------------------------------
 ls -al 권한 확인
sudo chmod +x mydaemon.sh: -> x 권한 부여
o ./mydemon.sh
$ cat /var/log/mydaemon/system_info.log

=-------------------------------------------
sudo systemctl start mydaemon.service
sudo systemctl status mydaemon.service

1. sudo touch mydaemon.service
2. sudo nano mydaemon.service
3. cat mydaemon.service
cd /etc/systemd/system
4. sudo systemctl stop mydaemon.service
5. sudo systemctl start mydaemon.service
6. sudo systemctl status mydaemon.service
sudo systemctl daemon-reload 


LED_PWD제어
BUZZER제어
i2cdetect -y 1 : i2c장비를 연결했을떄 하드웨어 장비를 감지



