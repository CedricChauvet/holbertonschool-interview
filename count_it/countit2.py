

"""
what do I do?
1/ write a recursive function that queries reddit API
"""
import json
import re
import requests

def count_words(subreddit, word_list, result=None):
    # Première appel : récupérer les données de Reddit
    if result is None:
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
    count_words(subreddit, word_list[1:], result)


"""
2eme version
"""
#!/usr/bin/python3
"""
make a List of keywords
"""
from functools import reduce
import re
import requests


def count_words(subreddit, word_list):
    # Effectuer la requête GET et préparer les données
    url = f'https://www.reddit.com/r/{subreddit}/hot.json'
    response = requests.get(url)
    data = response.json()

    if 'data' in data and 'children' in data['data']:
        titres = list(map(lambda article: article.get('data', {}).get('title', ''), data['data']['children']))
        result = reduce(lambda x, y: x + ' ' + y, titres).lower()
        word_list = sorted(set(map(str.lower, word_list)))
        
        # Appel initial à la fonction récursive
        count_words_recursive(word_list, result)
    else:
        print("La structure de la réponse n'est pas celle attendue.")


def count_words_recursive(word_list, result):
    # Cas de base : si la liste de mots est vide, on arrête la récursion
    if not word_list:
        return
    
    # Traiter le premier mot de la liste
    mot = word_list[0]
    pattern = r'\b' + re.escape(mot) + r'\b'
    count = len(re.findall(pattern, result))
    print(f"{mot}: {count}")
    
    # Appel récursif avec le reste de la liste
    count_words_recursive(word_list[1:], result)

