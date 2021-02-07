def BinarySearch(arr, val):
    start = 0
    end = len(arr)
    arr.sort()

    while(start <= end):
        mid = int((start+end)/2)
        if arr[mid] == val:
            return True
        elif arr[mid] > val:
            end = mid - 1
        else:
            start = mid + 1
    
    return False