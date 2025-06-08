def merge_intervals(intervals):
    if len(intervals) == 0 or len(intervals) == 1:
        return intervals
    merged_intervals = [[]]
    intervals.sort()
    curStart = intervals[0][0]
    curEnd = intervals[0][1]
    for i in range(1,len(intervals)):
        if intervals[i][0] > curEnd:
            lst = []
            lst.append(curStart)
            lst.append(curEnd)
            merged_intervals.append(lst)
            curStart = intervals[i][0]
            curEnd = intervals[i][1]
        else:
            curEnd = max(curEnd, intervals[i][1])
    lst = []
    lst.append(curStart)
    lst.append(curEnd)
    merged_intervals.append(lst)
    return merged_intervals[1:]


intervals = [[1, 3], [2, 6], [8, 10], [15, 18]]
print(merge_intervals(intervals))

intervals = [[1, 4], [4, 5]]
print(merge_intervals(intervals))

intervals = [[15, 18],  [2, 6], [8, 10], [1, 3]]
print(merge_intervals(intervals))

intervals = [[15, 18]]
print(merge_intervals(intervals))

intervals = []
print(merge_intervals(intervals))
