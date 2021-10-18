a = [74,-72,94,-53,-59,-3,-66,36,-13,22,73,15,-52,75]

def maxSubArraySum(a):
    current_sequence = 0
    best_sequence = a[0]
    for x in a:
        current_sequence = max(x,current_sequence+x)
        best_sequence = max(best_sequence,current_sequence)
    return best_sequence     

print("Largest sum contiguous subarray:",maxSubArraySum(a))