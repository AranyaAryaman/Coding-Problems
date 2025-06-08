def most_honey(height):
    maxVol = -1
    i = 0
    j = len(height)-1
    while i < j:
        curVol = (j-i) * min(height[i],height[j])
        if curVol > maxVol:
            maxVol = curVol
        if height[i]==min(height[i],height[j]):
            i = i+1
        else:
            j= j-1
    return maxVol

height = [1, 8, 6, 2, 5, 4, 8, 3, 7]
print(most_honey(height))

height = [1, 1]
print(most_honey(height))
