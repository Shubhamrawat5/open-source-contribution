def rightCheck(l: list) -> int:
    if l == sorted(l):
        return len(l)
    else:
        new_l = l[len(l)//2:]
        if len(new_l) > 1:
            if leftCheck(new_l) >= rightCheck(new_l):
                return leftCheck(new_l)
            else:
                return rightCheck(new_l)
        else:
            return 1

def leftCheck(l: list) -> int:
    if l == sorted(l):
        return len(l)
    else:
        new_l = l[:len(l)//2]
        if len(new_l) > 1:
            if leftCheck(new_l) >= rightCheck(new_l):
                return leftCheck(new_l)
            else:
                return rightCheck(new_l)
        else:
            return 1
        
def main(): 
    n = int(input())
    l = list(map(int, input().split()))
    left_p = leftCheck(l)
    right_p = rightCheck(l)
    if left_p >= right_p:
        return left_p
    else:
        return right_p

if __name__ == "__main__":
    print(main())
