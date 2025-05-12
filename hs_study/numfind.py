import random

guess_number = random.randint(1, 100)
print("1~100 사이의 숫자를 맞춰보세요.")

while True:
    try:
        users_input = int(input("숫자 입력: "))
    except ValueError:
        print("숫자를 입력하세요!")
        continue

    if users_input > guess_number:
        print("정답 숫자보다 큽니다.")
    elif users_input < guess_number:
        print("정답 숫자보다 작습니다.")
    else:
        print(f"정답입니다! 입력한 숫자는 {users_input}입니다.")
        break
