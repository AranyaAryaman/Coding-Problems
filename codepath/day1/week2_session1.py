def total_treasures(treasure_map):
    """
    Captain Blackbeard has a treasure map with several clues that point to different locations on an island.
    Each clue is associated with a specific location and the number of treasures buried there. 
    Given a dictionary treasure_map where keys are location names and values are integers representing 
    the number of treasures buried at those locations, write a function total_treasures() that returns 
    the total number of treasures buried on the island.

    U:
      I: A treasure map
      O: total num of treasures : Int 
      C: N/A
      E: no item in the map
    P: Create a total which counting all the values in the map
    I:
    """
    total = 0
    for value in treasure_map.values():
        total += value
    
    return total

treasure_map1 = {
    "Cove": 3,
    "Beach": 7,
    "Forest": 5
}

treasure_map2 = {
    "Shipwreck": 10,
    "Cave": 20,
    "Lagoon": 15,
    "Island Peak": 5
}

#print(total_treasures(treasure_map1)) 
#print(total_treasures(treasure_map2)) 


###################
def can_trust_message(message):
    """
    Taken captive, Captain Anne Bonny has been smuggled a secret message from her crew.
     She will know she can trust the message if it contains all of the letters in the alphabet.
      Given a string message containing only *lowercase English letters and whitespace*, 
      write a function can_trust_message() that returns True if the message contains every 
      letter of the English alphabet at least once, and False otherwise.
    U: 
        I: string 
        O: boolean 
        C: only lowercase english letters & whitespace
        E: empty string, just all whitespaces
    P: 
        list = ['a', 'b' , ... 'z']
        new_letters = []

        loop thru message, check if letter in list 
        new_letters.append(letter)

        return len(new_letters) == 26 

    r - 'a' = 0 25
        Captain Blackbeard has an integer array chests of length n where all the integers in chests are in the range [1, n] and each integer appears once or twice. Return an array of all the integers that appear twice, representing the treasure chests that have duplicates.

def find_duplicate_chests(chests):
    pass

    """
    alphabet = ['a', 'b', 'c', 'd', 'e', 'f','g', 'h', 'i','j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z']
    new_letters = [0] * 26
    if len(message) < 26: 
        return False 
    
    for char in message: 

        index = ord(char) - ord('a')

        if index < 0 or index > 25: 
            continue 

        new_letters[index] = 1

    for item in new_letters: 
        if item != 1: 
            return False

    return True 

# message1 = "sphinx of black quartz judge my vow"
# message2 = "trust me"

# print(can_trust_message(message1))
# print(can_trust_message(message2))


##################

def find_duplicate_chests(chests):
    """
    Captain Blackbeard has an integer array 
    chests of length n where all the integers 
    in chests are in the range [1, n] 
    and each integer appears once or twice.
    Return an array of all the integers that appear twice, 
    representing the treasure chests that have duplicates.

    U: 
        I: an list of chests
        O: a list of number 
        C: N/A
        E: empty chests
    P:  loop the chests, and save the amount and frequent in the dictionary. if the frequent
        equals two, add this amount the the result list.
        
        for each in chests
       

    """
    my_dict = {}
    ret = []
    for each in chests:
        if each in my_dict:
            my_dict[each] += 1
            if my_dict[each] == 2:
                ret.append(each)
        else:
            my_dict[each] = 1
    
    return ret


# def find_duplicates(chests):
#     res = []
#     for num in chests:
#         index = abs(num) - 1
#         if chests[index] < 0:
#             res.append(abs(num))  # Already visited
#         else:
#             chests[index] *= -1   # Mark as visited
#     return res

chests1 = [4, 3, 2, 7, 8, 2, 3, 1]
chests2 = [1, 1, 2]
chests3 = [1]

print(find_duplicate_chests(chests1))
print(find_duplicate_chests(chests2))
print(find_duplicate_chests(chests3))   

# Example Output: 
# [2, 3]
# [1]
# []
    
