print("Hello, world!!")

a = 10 
b = 15.5
c = "this is a string"

print("=============================================")

num = int(input("Enter a number: "))

if num > 0:
    print("The number is positive.")
elif num < 0:
    print("The number is negative.")
else:    
    print("Kuch nahi, zero hai!!")

print("=============================================")

f = 1
while f <= 5:
    print(f)
    f += 1

print("=============================================")

fruits = ["apple", "banana", "cherry"]

print(fruits)
print(fruits[0])
fruits.append("orange")
print(fruits)

print("=============================================")

numbers = [10, 20, 30, 40, 50]
for num in numbers:
    print(num)

print("=============================================")

for num in reversed(numbers):
    print(num)

print("=============================================")
total = 0
for num in numbers:
    total += num
print("Total: ", total)

print("=============================================")

coordinates = (10, 20)
print(coordinates)
print(coordinates[0])

print("=============================================")

student = {
    "name": "chintu",
    "age": 22,
    "course": "DESD"
}
print(student)
print(student["name"])

print("==================EOP========================")