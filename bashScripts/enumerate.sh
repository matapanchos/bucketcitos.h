#!/bin/bash

#Script que enumera los archivos (no carpetas) de un directorio
#TODO permitir acceder a archivos ocultos (i.e. .file.jpg)
#i.e. file001.txt file002.txt file003.txt ... file099.txt

number=0
extension=".jpg" #TODO se puede mejorar para que la extensión sea un parametro del shell
newName=""
for file in *;
do
	if [[ -f "$file" ]]; #Se valida que sea solo archivo
	then
		#printf -v guarda el valor del printf en la variable newName
		printf -v newName "%03d%s" $((++number)) "$extension" #TODO se puede hacer que la cantidad de digitos 0 concuerde con la cantidad de archivos
		mv -v "$file" "$newName" #TODO se puede hacer que el verbose solo se active a criterio del usuario
	fi;
done

#matapanchos
