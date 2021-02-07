def LinearSearch(arr, val):
    for i in range(len(arr)):
        if arr[i] == val:
            return True
    
    return False