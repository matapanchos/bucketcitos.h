#!/bin/bash

#Script que enumera los archivos (no carpetas) de un directorio en funcion al orden propio de ls
#TODO permitir acceder a archivos ocultos (i.e. .file.jpg)
#i.e. file001.txt file002.txt file003.txt ... file099.txt

#TODO evitar realizar el cambio de nombre si el archivo tendra como nombre el suyo propio

#TODO el script utiliza archivos backup simples como temporales, terminan en "~" se puede utilizar funciones recursivas para colocar tantos "~" como sea necesario y no sobreescribir ningun archivo

#Firts, we verify that doesnt exist backup files in the current dir
if [[ 0 -ne $(ls *~ 2>/dev/null | wc -l) ]]; #If the number of entries in ls *~ is different from 0 the script will stop, message of error because not found files like *~ will go to /dev/null
then
	echo "This script use simple backup files (ended with \"~\")  as temporals files, so please move them before run the script"
	echo "Found $(ls *~ | wc -l) backup files"
	exit
fi;

number=0
extension=".jpg" #TODO se puede mejorar para que la extensión sea un parametro del shell
newName=""
for file in *;
do
	if [ -f "$file" ] || [ ! -e "$file" ]; #Validate that isn't a dir or we has changed its name
	then
		printf -v newName "%03d%s" $((++number)) "$extension"
		if [[ -e "$newName" ]]; #Se valida que no exista un archivo con la numeración que se usara
		then
			if [[ -e "$newName~" ]]; #The script will fail if it attempt to remplace a file #TODO se puede encapsular la función de verificar que existe un archivo
	                then 
                        	echo "Script stopped due to an illegal attempt to remplace the file "$newName~" with "$newName""
				#TODO create a rollback fucntion that erase the "~" from the file names
                	        exit
        	        fi;
			mv -v "$newName" "$newName~" #Si existe, se le adiciona un ~ al final del arcvhivo #TODO se puede hacer que el verbose solo se active a criterio del usuario
		fi;
	fi;
done

number=0 #Reset the counter
for file in *;
do
	if [[ -f "$file" ]]; #Se valida que sea solo archivo
	then
		#printf -v guarda el valor del printf en la variable newName
		printf -v newName "%03d%s" $((++number)) "$extension" #TODO se puede hacer que la cantidad de digitos 0 concuerde con la cantidad de archivos #BUG si la cantidad de 0 es menor que cantidad de archivos, dada la naturaleza de ls, el orden se altera de manera extraña
		if [[ -e "$newName" ]]; #The script will fail if it attempt to remplace a file
		then 
			echo "Script stopped due to an illegal attempt to remplace the file "$newName" with "$file""
			exit
		fi;
		mv -v "$file" "$newName" #TODO se puede hacer que el verbose solo se active a criterio del usuario
	fi;
done

#matapanchos
#cares.guero@gmail.com
