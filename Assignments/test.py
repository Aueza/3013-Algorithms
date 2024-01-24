#begin

def swap(list, i, j):
    print("moving ", list[i], "to ", list[j])
    temp = list[i]
    list[i] = list[j]
    list[j] = temp

def bubblesort(list):
    min = list[0]
    minPos = 0
    for x in range(len(list)):
        for y in range(len(list)):
            if(list[y] < min):
                min = list[y]
                minPos = y
                swap(list, x, minPos)  

nums = [1, 56, 23, 144, 12]

print(nums)
bubblesort(nums)
print(nums)
