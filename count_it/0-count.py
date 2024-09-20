#!/usr/bin/python3
from functools import reduce
import re
import requests

def count_words(subreddit, word_list, after=None, result="", word_counts=None):
    # Initialisation de word_counts
    if word_counts is None:
        if not word_list:
            return

        word_counts = dict(map(lambda word: (word.lower(), 0), word_list))
        word_counts = dict(sorted(word_counts.items()))
        # print(f"word_counts entiere: {word_counts}")
        #return count_words(subreddit, word_list[1:], after, result, word_counts)

    # Requête à l'API Reddit
    if after is not None or result == "":
        url = f'https://www.reddit.com/r/{subreddit}/hot.json'
        headers = {'User-Agent': 'MyBot/1.0'}
        params = {'limit': 100, 'after': after}
        try:
            response = requests.get(url, headers=headers, params=params)
            data = response.json()
            new_titles = list(map(lambda article: article['data']['title'], data['data']['children']))
            result += ' ' + reduce(lambda x, y: x + ' ' + y, new_titles).lower()
            after = data['data']['after']
        except requests.RequestException:
            after = None

    # Comptage des mots
    if word_list:    
        word_list = sorted(list(map(str.lower, word_list))) 
        word = word_list[0]
        if word in word_counts:
            pattern = r'\b' + re.escape(word) + r'\b'
            word_counts[word] += len(re.findall(pattern, result))
        return count_words(subreddit, word_list[1:], after, result, word_counts)

    # Traitement de la page suivante
    if after:
        return count_words(subreddit, list(word_counts.keys()), after, result, word_counts)

    # Affichage des résultats
    sorted_counts = sorted(word_counts.items(), key=lambda x: (-x[1], x[0]))
    sorted_counts = sorted(filter(lambda x: x[1] > 0, word_counts.items()), key=lambda x: (-x[1], x[0]))

    print("sorted_counts: ", sorted_counts)
    #list(map(lambda item: print(f"{item[0]}: {item[1]}"), filter(lambda x: x[1] >= 0, sorted_counts)))
    list(map(lambda item: print(f"{item[0]}: {item[1]}"), sorted(filter(lambda x: x[1] >= 0, sorted_counts), key=lambda x: x[0])))
