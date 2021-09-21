
# Original solution. Doesn't quite work, unfrotunately.
# In focusing on who bribes who, and how much the bribers move. We lose  information when a briber is bribed.
def minimumBribes(q):
    leftover = []
    numBribes = 0
    iterator = 1  # start at 1 because ticket system does not start at 0
    for ticket in q:
        if ticket > (iterator + 2):  # person has bribed too many
            print('Too chaotic')
            return
        elif (ticket > iterator):  # Person has been bribed
            numBribes += (ticket - iterator)
        # Movement to the right indicates person has been bribed.
        elif (ticket < iterator):
            leftover.append(ticket)
        else:
            # ticket == iterator
            # No movement means no bribes.
            pass
        iterator += 1

    # Go through leftovers to see if they moved
    prevLeft = 0
    for left in leftover:
        if (left < prevLeft):  # bribed
            numBribes += 1
        prevLeft = left

    print(numBribes)
    return


def minimum_bribes(q):
    bribes = 0
    # Much cleaner. enumerate does the same thing I do above
    # (going through actual object in list, and getting another variable to represent the index of said object)
    for i, o in enumerate(q):
        # + 1 is needed since numbering system of ticketing system starts with 1 and not 0.
        cur = i + 1

        # Check to see if current person bribed more than two times.
        if o - cur > 2:
            print("Too chaotic")
            return

        #print('o: ' + str(o))
        # Here we create a list from a range. This range is the from the original position of the person - 2, to the current position
        for k in q[max(o - 2, 0):i]:
            if k > o:  # If the values we pass are greater than that of the current person,  then those bribed the person.
                #print(str(k) + ' > ' + str(o))
                bribes += 1

    print(bribes)


# define list with inputs
array = [1, 2, 5, 3, 7, 8, 6, 4]
minimum_bribes(array)
