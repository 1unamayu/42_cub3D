import os
import subprocess
import time

ruta_directorio = "maps/"

# Obtener una lista de todos los archivos en el directorio
archivos = os.listdir(ruta_directorio)

# Filtrar la lista para obtener solo archivos .cub
archivos_cub = [archivo for archivo in archivos if archivo.endswith(".cub")]


def obtener_archivos_cub(directorio):
	archivos_cub = []
	for raiz, subdirectorios, archivos in os.walk(directorio):
		for archivo in archivos:
			if archivo.endswith(".cub"):
				ruta_completa = os.path.join(raiz, archivo)
				archivos_cub.append(ruta_completa)
	return archivos_cub
contador = 1 
ruta_directorio = "maps/"
archivos_cub = obtener_archivos_cub(ruta_directorio)
# Recorrer la lista de archivos .cub
for archivo_cub in reversed(archivos_cub):
    # Iniciar el proceso cube3s con el archivo como argumento
    mensaje = f"TEST {contador}: File {archivo_cub}"
    print(mensaje, end=' ' * (90 - len(mensaje)))
    with open("salida.txt", "w") as archivo:
        proceso = subprocess.Popen(["./cube3d",  archivo_cub], stdout=archivo, stderr=subprocess.STDOUT)
        time.sleep(1)
        proceso.kill()
    with open("salida.txt", "r") as archivo:
        contenido = archivo.read()
        if "Error" in contenido and "error" in archivo_cub:
            print("\033[32mOK\033[0m")
        elif "Error" in contenido and "error" not in archivo_cub:
            print("\033[31mKO\033[0m")
        elif "Error" not in contenido and "error" in archivo_cub:
            print("\033[31mKO\033[0m")
        else:
            print("\033[32mOK\033[0m")
    mensaje = f"TEST LEAKS {contador}: File {archivo_cub}"
    print(mensaje, end=' ' * (90 - len(mensaje)))
    with open(f"salida_leaks_{contador}.txt", "w") as archivo:
        proceso = subprocess.Popen(["valgrind","./cube3d",  archivo_cub], stdout=archivo, stderr=subprocess.STDOUT)
        time.sleep(2)
        proceso.kill()
    with open(f"salida_leaks_{contador}.txt", "r") as archivo:
        contenido = archivo.read()
        if "no leaks are possible" in contenido:
            print("\033[32mOK\033[0m")
        else:
            print("\033[31mKO\033[0m")
    contador = contador + 1;
    time.sleep(2)
# Imprimir un mensaje al final
print("Se han analizado todos los archivos .cub")