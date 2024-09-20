# Script Python pour compter les mots dans les titres Reddit

import requests
import re
from functools import reduce

def count_words(subreddit, word_list, result=None):
    # Première appel : récupérer les données de Reddit
    if result is None:
        url = f'https://www.reddit.com/r/{subreddit}/hot.json'
        headers = {'User-Agent': 'MyBot/1.0'}
        response = requests.get(url, headers=headers)
        response.raise_for_status()
        data = response.json()
        
        # Utilisation de map() et lambda au lieu d'une compréhension de liste
        titres = list(map(lambda article: article['data']['title'], data['data']['children']))
        
        # Utilisation de reduce() pour joindre les titres
        result = reduce(lambda x, y: x + ' ' + y, titres).lower()
        
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
    count_words(subreddit, word_list[1:], result)