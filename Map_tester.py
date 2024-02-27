import os
import subprocess
import time

def get_cub_files(directory):
    """Obtiene una lista de todos los archivos .cub en el directorio."""
    cub_files = []
    for root, dirs, files in os.walk(directory):
        for file in files:
            if file.endswith(".cub"):
                full_path = os.path.join(root, file)
                cub_files.append(full_path)
    return cub_files

def run_test(file, test_type, test_number):
    """Ejecuta una prueba en el archivo dado y escribe el resultado en la salida."""
    print(f"TEST {test_number} {test_type}: File {file}", end=' ' * (90 - len(f"TEST {test_number} {test_type}: File {file}")))
    with open(f"salida_{test_type}_{test_number}.txt", "w") as output_file:
        process = subprocess.Popen(["./cub3d", file], stdout=output_file, stderr=subprocess.STDOUT)
        time.sleep(1)
        process.kill()
    with open(f"salida_{test_type}_{test_number}.txt", "r") as output_file:
        content = output_file.read()
        if "Error" in content and "error" in file:
            print("\033[32mOK\033[0m")
        elif "Error" in content and "error" not in file:
            print("\033[31mKO\033[0m")
        elif "Error" not in content and "error" in file:
            print("\033[31mKO\033[0m")
        else:
            print("\033[32mOK\033[0m")

def run_leaks_test(file, test_number):
    terminado = False
    """Ejecuta una prueba de fugas de memoria en el archivo dado y escribe el resultado en la salida."""
    print(f"TEST LEAKS {test_number}: File {file}", end=' ' * (90 - len(f"TEST LEAKS {test_number}: File {file}")))
    with open(f"salida_leaks_{test_number}.txt", "w") as output_file:
        process = subprocess.Popen(["valgrind","./cub3d", file], stdout=output_file, stderr=subprocess.STDOUT)
    while terminado == False:
        time.sleep(2)
        with open(f"salida_leaks_{test_number}.txt", "r") as salida_file:
            if "ERROR SUMMARY" in salida_file.read():
                terminado = True    
    with open(f"salida_leaks_{test_number}.txt", "r") as output_file:
        content = output_file.read()
        if "no leaks are possible" in content:
            print("\033[32mOK\033[0m")
        else:
            print("\033[31mKO\033[0m")
def delete_salida_files():
    """Elimina todos los archivos salida_*.txt en el directorio actual."""
    for file in os.listdir():
        if file.startswith("salida_") and file.endswith(".txt"):
            os.remove(file)
def main():
    directory = "maps/"
    cub_files = get_cub_files(directory)
    test_number = 1
    for file in reversed(cub_files):
        run_test(file, "TEST", test_number)
        run_leaks_test(file, test_number)
        test_number += 1
        time.sleep(2)
    print("Se han analizado todos los archivos .cub")
    delete_salida_files()

if __name__ == "__main__":
    main()