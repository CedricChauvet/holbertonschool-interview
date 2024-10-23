#!/usr/bin/python3
"""
interview project Log parsing
By Ced
"""
import sys


def print_stats(total_size, status_codes):
    """
    Imprime les statistiques
    """
    print("File size: {}".format(total_size))
    for code in sorted(status_codes.keys()):
        if status_codes[code] > 0:
            print("{}: {}".format(code, status_codes[code]))

total_size = 0
status_codes = {
    200: 0, 301: 0, 400: 0, 401: 0,
    403: 0, 404: 0, 405: 0, 500: 0
}
line_count = 0

try:
    """
    boucle qui casse si CTRL+C
    """
    for line in sys.stdin:
        line_count += 1
        
        # Split la ligne et extrait les informations
        parts = line.split()
        status_code = int(parts[-2])  # Avant-dernier élément
        file_size = int(parts[-1])    # Dernier élément
        
        # Met à jour les statistiques
        total_size += file_size
        if status_code in status_codes:
            status_codes[status_code] += 1
                    
        # Imprime les stats toutes les 10 lignes
        if line_count % 10 == 0:
            print_stats(total_size, status_codes)

except KeyboardInterrupt:
    """
    sortie de la boucle
    """
    # En cas de Ctrl+C, imprime les stats finales
    print("sortie")
    print_stats(total_size, status_codes)
    raise