# Ethan Saenz
# 1-24-24
# Bubblesorting a list with a swap function

def swap(list, i, j):
    temp = list[i]
    list[i] = list[j]
    list[j] = temp

def bubblesort(list):
    print("printing the sorted list, using bubblesort")
    for x in range(len(list)):
        min = list[x]
        for y in range(len(list)):
            if(list[y] > min):
                min = list[y]
                swap(list, x, y)

nums = [1, 56, -23, 144, -12, 15, 289]

print(nums)
bubblesort(nums)
print(nums)
