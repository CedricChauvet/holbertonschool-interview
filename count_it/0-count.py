#!/usr/bin/python3
"""
what do I do?
1/ write a recursive function that queries reddit API
VERSION ANTERIEURE DE COUNT IT
"""
import json
import re
import requests


def count_words(subreddit, word_list):
    # Effectuer la requête GET
    url = 'https://www.reddit.com/r/' +subreddit + '/hot.json'
    response = requests.get(url)

    # Extraire le contenu JSON
    data = response.json()

    # Afficher le JSON de manière lisible avec indentation
    # json_string = json.dumps(data, indent=4)    


    titres = [article['data']['title'] for article in data['data']['children']]
    result = " ".join(titres)
    result = result.lower()
    # print("nombre de titres :", len(titres))   

    word_list =  sorted(set(word_list))
    hotlist = word_list

    parcourir_liste_recursif(hotlist, result)


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



