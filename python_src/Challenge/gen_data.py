#Run this file once and the data will be generated
#Every other time, just read the file for the 'friends_data' from main.py
import random

def gen_inp(n_people, max_fr):
    friend_data = []
    for person in range(1, n_people + 1):
        n_friends = random.randint(1, min(max_fr, n_people - 1))
        friends = random.sample(range(1, n_people + 1), n_friends)
        for friend in friends:
            if friend != person:
                friend_data.append((person, friend))
    return friend_data

friend_data = gen_inp(1000, 25)
f = open('friends.txt', 'a')
for f1, f2 in friend_data:
    f.write(f"{f1} {f2}\n")
f.close()
