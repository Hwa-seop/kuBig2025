#!/bin/bash  셔뱅,명시용

#반복문
#for 변수 in 리스트; do
    #반복할 코드
#done

for name in "lee" "경영희" "cris"; do
    echo "이름: $name"
done

echo "0 부터 100까지 숫자 프린트-----"
for int in {0..100}; do
    echo -n "$int"
done

#while () 문장1;문장2; --->while [ condition ]; do 문장1; 문장2; done
#until 루프 --> while의 거꾸로 until [ condition ]; do 문장1; 문장2; done
#break continue...동일
echo""

#함수!! ->차이점은 argument(->$1,$2로 접근가능),소괄호,리턴 없음(->$?)
function hello {
    local testInt=45
    echo "안녕하세요~! $1님"
    return 3
}

hello "하이"
echo "반환된 값은 $? 입니다."
echo "$testInt"
#변수의 선언 --->모든 선언이 전역 변수입니다. local 을 붙이면 지역변수로서 사용가능

#crontab cron : 시간에 맞춰어서 쉘 스크립트를 실행하는 기능, 데몬에서 안쪽에서 실행, 로그에 기록남음
