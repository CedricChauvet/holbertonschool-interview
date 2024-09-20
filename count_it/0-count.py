#!/usr/bin/python3
"""
2eme version
use a recursive function


"""
import re
import requests


def count_words(subreddit, word_list):
    # Effectuer la requête GET et préparer les données
    url = f'https://www.reddit.com/r/{subreddit}/hot.json'
    response = requests.get(url)
    data = response.json()

    if 'data' in data and 'children' in data['data']:
        titres = list(map(lambda article: article.get('data', {}).get('title', ''), data['data']['children']))
        result = " ".join(titres).lower()
        word_list = sorted(set(map(str.lower, word_list)))
        
        # Appel initial à la fonction récursive
        parcourir_liste_recursif(word_list, result)





def parcourir_liste_recursif(liste, result):
    # Condition d'arrêt : Si la liste est vide, on arrête
    if not liste:
        return
    liste[0] = liste[0].lower()
    pattern = r'\b' + liste[0]+ r'\b' #expression regex pour le mot complet
    count_python =  len(re.findall(pattern, result)) #utilisation de re
    #count_python = result.count(liste[0])
    print(f"{liste[0]}: {count_python}")  
    
    # Appeler la fonction récursive sur le reste de la liste (sauf le premier élément)
    parcourir_liste_recursif(liste[1:],result)