#섭씨->화씨 변환 프로그램 input->casting->연산->출력
#섭씨 → 화씨: (섭씨 온도 * 1.8) + 32
def main():
    degree=input("섭씨온도를 입력하세요! ")
    for i in degree.split('.'):
        if degree.isdigit():
            print("섭씨 온도:",degree)
        
    celsius=float(degree)
    fahrenheit=celsius*1.8+32
    print("화씨 온도:",fahrenheit)
    
if __name__=="__main__":
    main()


