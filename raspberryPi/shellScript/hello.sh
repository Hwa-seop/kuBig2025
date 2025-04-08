#!/bin/bash

# 이 주석이다.
#name="lee hwa seop"
#export age=25

#echo "Hello, world!, $name"
#echo "date : " `date`  #날짜를 출력

#text="hello, world"
#echo ${text:0:5}
#echo ${text:7}

text="I like cats"
echo ${text/cats/dogs}

text="I like cats, I really love cats"
echo ${text//cats/dogs} #여러개 바꿀때 사용
echo ${#text}

# 중요! unset env
unset 환경변수

# read
echo "이름을 입력하시요 :" 
read name
read -s -p "비밀번호를 입력하세요 :" passward
echo "입력한 이름: $name"
echo "패스워드 : $passward "
export name = $name
./envTest

#화면 출력 echo, printf
echo -n "이어지는 "
ehco "문장"
ehco -e "엔터가 들어가는 \n 문장" #escape문자 작동 옵션
printf "이름: %s, 나이: %d\n" "홍길동" 25


#중요!! argument 받기 $1, $2 인자갯수: $# 모든 인자: $* $@
echo "첫 번째 인자: $1"
echo "두 번째 인자: $2"
ehco "인자들의 갯수: $#"
ehco "모든인자: $@ "

#제어문 if then fi(endif)
read -p "나이를 넣으시오:" age
if [ $age -lt 18 ]; then
    echo "성인 아닙니댜."
elif [ $age -gt 70 ]; then
    echo "노인입니다."
elif [ $age -ge 20 ] && [ $age -lt 30 ]; then
    echo "20대입니다."
else
    echo "성인입니다."
fi

#연산자 비교(숫자)
#같다 == : -eq, 
#같지않다 != : -ne
#크다 > : -gt
#작다 < : -lt
#크거나 같다 >= : -ge
#작거나 같다 <= : -le

#연산자 비교 (문자)
#같다 == : =
#같지않다. != : !=
#길이가 0 len(문자열) : z
#길이가 0이 아님 len(문자열) : n

read -p "입력값을 넣으세요." input
if [ ! -z "$input" ]; then
    echo "입력값이 있습니다."
else
    echo "입력값이 없습니다."
fi

#논리연산 똑같음 && || ! 


#switch -case -> case로 통합되있음

read -p "과일 입력 " fruit
case $fruit in
    "사과")|"딸기" echo "빨간 과일" ;;
    "바나나")"망고" echo "노란 과일" ;;
    *) echo "알 수 없음";;
esac
