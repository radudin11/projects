import requests

def say_hello():
    print("Hello world")

say_hello()
x = requests.get('https://w3schools.com')
print(x.json)
