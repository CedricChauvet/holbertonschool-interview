#!/usr/bin/python3
"""
Second version
Uses a recursive function
Counts the given words in every hot Reddit article
"""
import re  # Import the regular expression library
import requests  # Import the requests library to make HTTP requests


def count_words(subreddit, word_list):
    """
    Count the occurrences of words in the titles of hot articles
    from a subreddit
    param subreddit: The subreddit to get the hot articles from
    param word_list: A list of words to count the occurrences of in the titles
    """

    # Prepare and make a GET request to the Reddit API
    # to get hot posts from the subreddit
    url = f'https://www.reddit.com/r/{subreddit}/hot.json'
    response = requests.get(url)  # Send the GET request
    data = response.json()  # Parse the response as JSON

    # Check if the response contains the necessary data
    if 'data' in data and 'children' in data['data']:
        # map les données dans data['data']['children'] pour obtenir
        # les titres grace a la fonctoin lambda
        titres = list(map(lambda article: article['data']['title'],
                          data['data']['children']))

        # Combine all titles into a single string and convert to
        # lowercase  case-insensitive matching
        result = " ".join(titres).lower()

        # Sort and convert the word_list to lowercase word_list
        word_list = sorted(map(str.lower, word_list))

        # Initial call to the recursive function to count word occurrences
        parcourir_liste_recursif(word_list, result)


def parcourir_liste_recursif(word_list, result):
    """
    Recursive function to count occurrences of each word in the word list
    pop the first element of the list and count its occurrences in the result
    then do it again with the rest of the list
    """
    # Base condition: If the list is empty, stop recursion
    if not word_list:
        return

    # Create a regex pattern to match whole words (word boundaries using \b)
    pattern = r'\b' + word_list[0] + r'\b'
    # Count occurrences of the word in the combined titles using regex
    count_python = len(re.findall(pattern, result))

    # Print the word and its count
    print(f"{word_list[0]}: {count_python}")

    # Recursively call  function
    parcourir_liste_recursif(word_list[1:], result)


"""
version 2 en une seule fonction
"""
#!/usr/bin/python3
"""
Script Python pour compter les mots dans les titres Reddit
"""

import re
import requests


def count_words(subreddit, word_list, result=None):
    # Première appel : récupérer les données de Reddit
    if result is None:
        url = f'https://www.reddit.com/r/{subreddit}/hot.json'

        response = requests.get(url)
        data = response.json()
        
        # Utilisation de map() et lambda au lieu d'une compréhension de liste
        titres = list(map(lambda article: article['data']['title'], data['data']['children']))
        
        # Utilisation de reduce() pour joindre les titres
        result = " ".join(titres).lower()
        word_list = sorted(map(str.lower, word_list))

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