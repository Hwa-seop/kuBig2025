cnt = 0


def fibonacci(n):
    global cnt # 전역변수 명시
    cnt += 1
    if n == 1:
        return 1
    elif n == 2:
        return 1
    else:
        return fibonacci(n-1)+fibonacci(n-2)
        
def main():
    print(fibonacci(100))
    print(f"fibonacci가 수행된 횟수 {cnt}")

if __name__=="__main__":
    main()