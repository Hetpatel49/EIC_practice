while read line
do
cut -c3 <<< "$line"	#same as   echo "$line" | cut -c3
done < file.txt 
