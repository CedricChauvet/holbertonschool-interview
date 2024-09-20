

#!/usr/bin/python3
"""
what do I do?
1/ write a recursive function that queries reddit API
"""
import json
import re
import requests

def count_words(subreddit, word_list):
    # Première appel : récupérer les données de Reddit
    #if result is None:
    url = f'https://www.reddit.com/r/{subreddit}/hot.json'
    headers = {'User-Agent': 'MyBot/1.0'}
    response = requests.get(url, headers=headers)
    response.raise_for_status()
    data = response.json()
    
    titres = [article['data']['title'] for article in data['data']['children']]
    result = " ".join(titres).lower()
    word_list = sorted(set(map(str.lower, word_list)))

    # Condition d'arrêt : si la liste de mots est vide
    if not word_list:
        return

    # Compter les occurrences du premier mot
    mot = word_list[0]
    pattern = r'\b' + re.escape(mot) + r'\b'
    count = len(re.findall(pattern, result))
    print(f"{mot}: {count}")

    # Appel récursif pour le reste de la liste
    count_words(subreddit, word_list[1:])
