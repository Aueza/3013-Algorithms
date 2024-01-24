#begin

def fillList(list):
    total = int(input("how many numbers would you like to enter: "))
    count = 0
    while(count < total):
        number = getNum()
        list.append(number)
        print("added",number, "to the list.")

        count = count+1
    
def getNum():
    number = int(input("please enter a number: "))
    return number

def printList(list):
    print("printing list...")
    for numbers in range(len(list)):
        print(list[numbers])

def findSum(list):
    sum = 0
    for number in range(len(list)):
        sum = sum + list[number]
    return sum
        

nums = []

fillList(nums)
printList(nums)
print("now printing with the sorted list...")
nums.sort()
printList(nums)
print("the sum of the list is: ", findSum(nums))





