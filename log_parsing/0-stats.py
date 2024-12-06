#!/usr/bin/python3
"""
This is the Log parsing project
By Ced  :q
"""
import sys


def print_stats(total_size, status_codes):
    """Imprime les statistiques"""
    print("File size: {}".format(total_size))
    for code in sorted(status_codes.keys()):
        if status_codes[code] > 0:
            print("{}: {}".format(code, status_codes[code]))


def process_logs(**kwargs):
    """Fonction principale qui traite les logs"""
    total_size = 0
    status_codes = {
        200: 0, 301: 0, 400: 0, 401: 0,
        403: 0, 404: 0, 405: 0, 500: 0
    }
    line_count = 0

    try:
        for line in sys.stdin:
            line_count += 1

            try:
                # Split la ligne et extrait les informations
                parts = line.split()
                status_code = int(parts[-2])  # Avant-dernier élément
                file_size = int(parts[-1])    # Dernier élément

                # Met à jour les statistiques
                total_size += file_size
                if status_code in status_codes:
                    status_codes[status_code] += 1

            except (IndexError, ValueError):
                # Ignore les lignes mal formatées
                # print("heeeeeeu")
                file_size = int(parts[-1])
                pass

            # Imprime les stats toutes les 10 lignes
            if line_count % 10 == 0:
                print_stats(total_size, status_codes)
        print_stats(total_size, status_codes)

    except BrokenPipeError:
        # Suppress broken pipe errors
        pass

    except KeyboardInterrupt:
        # En cas de Ctrl+C, imprime les stats finales
        print_stats(total_size, status_codes)
        sys.exit(0)


if __name__ == "__main__":
    process_logs()
