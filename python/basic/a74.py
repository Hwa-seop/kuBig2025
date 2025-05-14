 def mydecorator(func):
     def wrapper(*argc,**kwargs):
         print(f"func 실행 전 코드...{value}")
    r esult = func(*argc,**kwargs)
print("func 실행 후 코드...")
return result
