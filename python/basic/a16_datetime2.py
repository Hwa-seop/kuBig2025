#if else elif문 사용해서 현재 시각 오전 오후 표시
# 계절을 표시하는 프로그램
#datetime 모듈활용
#input 받아서 나타나게(시간:월)-> "now" ->now 함수를 불러와서 표시

import datetime

def main():
    ptime=datetime.datetime.now()
    print(ptime)
    if ptime.hour>12:
        timestate="오후"
    else:
        timestate="오전"
    if 3<=ptime.month<=5:
        season="sping"
    elif 6<=ptime.month<=8:
        season="summer"
    elif 9<=ptime.month<=11:
        season="fall"
    else:
        season="winter"
        
    print(f"{ptime.year}년 {ptime.month}월 {ptime.day}일 {timestate} {ptime.hour}시{ptime.minute}분{ptime.second}초")
    print("현재 계절은: " ,season)
    time=input()
    
if __name__=="__main__":
    main()


