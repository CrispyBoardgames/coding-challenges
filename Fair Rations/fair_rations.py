# Every time you give a loaf of bread to some person, i, you must also give a loaf of bread to the person immediately in
# front of OR behind them in the line (i.e. persons i + 1 or i - 1)
# After all bread is distributed, each person must have an even number of loaves.

# Given a number of loaves already held by each citizen, find and print the minimum number of loaves you must distribute to satisfy the two roles.
# If this is not possible, print NO.

# function: string fairRations(int B[N])
# Doesn't quite work. I left this to mark my progress. Second one was done right after. Wrote pseudocode and cleaned the code.
def fairRations1(B):
    # First, determine if possible.
    # This is done by checking the number of "odd people". It must be even. If odd, return "NO"
    oddPeople = 0
    # Then, determine the amount of loaves through the following formula:
    # Total # of Loaves Given = # of people between pairs (inclusive) + # of people between odd value pairs
    # The # of people between odd value pairs = # of people between pairs - 2
    totalLoaves = 0
    # Each entry tells the number of of people between pairs (inclusive)
    loavesBetween = []
    pairCount = -1
    for count, person in enumerate(B):
        if(person % 2 == 1):  # odd
            if(oddPeople % 2 == 0):  # Only want to add a new list every two odd values (every pair)
                loavesBetween.append(1)
                pairCount += 1
            else:
                loavesBetween[pairCount] += 1
            oddPeople += 1
        elif loavesBetween:  # Not empty
            loavesBetween[pairCount] += 1
    if oddPeople % 2 == 1:
        return "NO"
    for pair in loavesBetween:
        totalLoaves += ((2 * pair) - 2)
    return str(totalLoaves)


def fairRations(B):
    oddPeople = 0
    totalLoaves = 0
    first = 0
    second = 0
    for current_index, person in enumerate(B):
        print(f"Current index: {current_index}\t Number  of Loaves: {person}")
        if(person % 2):  # is odd
            if(not oddPeople % 2):  # if even we are on first
                first = current_index
            else:  # we are on second
                second = current_index
                totalLoaves += (second-first + 1) * 2 - 2
            oddPeople += 1
    if(oddPeople % 2):
        return "NO"
    return str(totalLoaves)


B = [6, 8, 1, 4, 3, 4, 9, 10, 8, 7, 10, 8, 10, 1, 2, 3, 2, 9, 7, 6, 7, 5, 1, 10, 7, 5, 2, 9, 4, 2, 1, 9, 4, 2, 2, 6, 3, 3, 5, 9, 2, 9, 8, 4, 8, 2, 1, 3, 4, 4, 2, 9, 10, 5, 1, 1, 2, 9, 2, 2, 4, 8, 9, 6, 1, 7, 6, 3, 6, 9, 10, 2, 9, 2, 8, 3, 3, 1, 7, 6, 7, 1, 9, 10, 6, 7, 7, 9, 5, 5, 7, 1, 5, 10, 3, 9, 7, 6, 10, 6, 10, 3, 2, 2, 7, 3, 7, 1, 1, 9, 8, 10, 1, 3, 8, 7, 10, 6, 3, 7, 4, 4, 5, 3, 4, 9, 5, 2, 9, 8, 7, 5, 8, 7, 8, 3, 5, 8, 2, 5, 9, 4, 8, 10, 4, 8, 2, 10, 5, 2, 2, 5, 1, 6, 3, 10, 8, 1, 3, 1, 7, 3, 4, 6, 5, 4, 3, 4, 4, 2, 3, 1, 3, 4, 5, 5, 9, 4, 1, 5, 5, 5, 4, 9, 3, 5, 1, 1, 5, 7, 3, 10, 10, 4, 10, 5, 5, 1, 1, 10, 10, 9, 9, 7, 5, 5, 1, 3, 1, 6, 8, 9, 7, 10, 8, 5, 2, 5, 2, 10, 9, 5, 10, 7, 2, 2, 2, 4, 3, 1, 4, 2, 7, 8, 2, 6, 6, 4, 2, 1, 5, 8, 8, 9, 10, 8, 6, 4, 5, 7, 4, 3, 5, 4, 8, 5, 8, 5, 8, 9, 8, 5, 9, 2, 6, 9, 1, 5, 9, 3, 4, 2, 8, 2, 6, 5, 9, 10, 3, 1, 10, 5, 1, 4, 2, 7, 2, 4, 8, 10, 9, 2, 3, 6, 3, 10, 2, 2, 4, 6, 8, 8, 5, 7, 8, 4, 7, 6, 4, 6, 7, 8, 1, 4, 7, 5, 2, 2, 8, 7, 3, 8, 10, 10, 8, 5, 4, 4, 1, 1, 6, 10, 3, 8, 7, 8, 5, 7, 3, 2, 10, 4, 5, 2, 8, 2, 3, 4, 8, 6, 1, 6, 5, 2, 9, 8, 8, 5, 7, 1, 2, 9, 6, 10, 3, 8, 5, 8, 3, 8, 1, 7, 5, 3, 5, 8, 7, 9, 8, 3, 5, 1, 1, 5, 9, 9, 4, 8, 10, 10, 2, 10, 10, 4, 4, 9, 8, 2, 9, 4, 1, 1, 10, 10, 10, 4, 7, 10, 2, 8, 9, 5, 10, 2, 7, 5, 7, 6, 5, 9, 1, 1, 1, 10, 8, 10, 5, 1, 2, 8, 9, 2, 2, 1, 9, 8, 3, 5, 8, 9, 3, 9, 1, 7, 7, 6, 6, 7, 4, 8, 10, 4, 9, 10, 4, 4, 10, 10, 7, 3, 8, 2, 9, 1, 7, 5, 4, 4, 10, 3, 9, 1, 3, 2, 9, 4, 3, 9, 7, 6, 10, 5, 7, 7, 7, 5, 9, 7, 1, 3, 1, 4, 1, 9, 6, 1, 6, 5, 1,
     4, 3, 2, 1, 9, 8, 4, 2, 1, 6, 3, 3, 9, 10, 5, 10, 1, 10, 4, 5, 9, 4, 1, 3, 4, 10, 5, 10, 8, 6, 2, 1, 3, 5, 10, 7, 1, 1, 6, 3, 8, 3, 1, 4, 7, 1, 7, 9, 3, 1, 2, 6, 3, 7, 7, 2, 5, 4, 8, 3, 8, 9, 10, 1, 6, 7, 9, 4, 10, 8, 9, 8, 1, 9, 3, 1, 2, 8, 8, 3, 2, 5, 8, 9, 7, 6, 9, 5, 10, 10, 1, 7, 9, 6, 5, 2, 8, 7, 4, 1, 7, 10, 5, 10, 5, 7, 8, 8, 1, 6, 9, 3, 5, 5, 10, 8, 2, 1, 8, 7, 7, 7, 8, 4, 5, 4, 7, 5, 3, 4, 2, 1, 8, 1, 4, 2, 6, 4, 9, 1, 5, 5, 8, 8, 2, 10, 5, 3, 1, 8, 9, 1, 1, 10, 9, 9, 10, 3, 7, 4, 3, 6, 3, 4, 6, 8, 1, 1, 10, 6, 10, 6, 2, 8, 10, 7, 1, 1, 2, 1, 10, 9, 9, 8, 2, 9, 5, 8, 6, 8, 3, 9, 6, 7, 8, 10, 1, 2, 3, 1, 4, 10, 10, 5, 10, 1, 3, 3, 4, 8, 8, 9, 5, 7, 4, 7, 1, 3, 2, 5, 4, 9, 6, 7, 4, 4, 8, 3, 2, 10, 2, 5, 2, 2, 7, 9, 7, 1, 4, 6, 5, 9, 3, 5, 2, 5, 2, 3, 5, 9, 5, 1, 6, 6, 8, 10, 4, 2, 8, 8, 6, 1, 10, 4, 2, 3, 9, 9, 7, 5, 6, 6, 3, 3, 1, 8, 5, 6, 6, 5, 3, 1, 10, 8, 5, 2, 9, 7, 9, 1, 10, 2, 3, 7, 6, 5, 6, 9, 10, 3, 2, 9, 7, 10, 9, 9, 10, 9, 2, 9, 9, 10, 10, 5, 1, 9, 8, 6, 5, 6, 3, 2, 3, 1, 3, 6, 5, 8, 5, 7, 5, 2, 5, 4, 2, 4, 6, 10, 3, 10, 3, 3, 4, 7, 8, 4, 6, 6, 7, 3, 10, 9, 7, 4, 1, 6, 7, 9, 3, 6, 3, 5, 10, 2, 9, 3, 9, 2, 8, 8, 3, 7, 7, 3, 8, 6, 5, 2, 1, 1, 9, 9, 1, 9, 5, 6, 10, 6, 8, 8, 2, 6, 9, 8, 5, 5, 5, 5, 9, 1, 6, 9, 8, 1, 8, 2, 1, 10, 9, 7, 1, 7, 4, 7, 3, 2, 2, 9, 3, 2, 3, 3, 1, 8, 10, 1, 8, 5, 10, 1, 2, 6, 3, 5, 8, 4, 7, 10, 1, 4, 1, 7, 10, 6, 3, 1, 10, 4, 7, 8, 10, 3, 1, 9, 8, 10, 5, 1, 9, 8, 3, 4, 6, 3, 9, 9, 1, 9, 7, 4, 10, 6, 6, 2, 9, 2, 2, 1, 2, 1, 5, 10, 2, 1, 5, 2, 1, 5, 5, 9, 9, 1, 3, 2, 2, 5, 1, 10, 3, 8, 3]
print(fairRations(B))
