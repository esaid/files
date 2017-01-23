#!/bin/bash
myhost=$1 # parametre hostname
declare -a oid=(
"iso.3.6.1.4.1.36582.1.1.2.2.101.1" # temperature
"iso.3.6.1.4.1.36582.1.1.3.2.101.1" # U0
"iso.3.6.1.4.1.36582.1.1.3.4.101.1" # U1
"iso.3.6.1.4.1.36582.1.1.3.6.101.1" # U2
"iso.3.6.1.4.1.36582.1.1.3.8.101.1" # U3
"iso.3.6.1.4.1.36582.1.1.3.10.101.1" # U4
"iso.3.6.1.4.1.36582.1.1.3.12.101.1" # U5
"iso.3.6.1.4.1.36582.1.1.4.2.101.1" # dustuG
"iso.3.6.1.4.1.36582.1.1.4.4.101.1") # dustdeviation
# echo ${oid[1]}
while (true)
do
    datas=""
    echo $myhost
    # test si hostname est present sur le reseau
    if ping -c 1 $myhost &> /dev/null
        then
        echo "success to ping $myhost"
        else
        echo "fail to ping $myhost bye  !" 
        sleep 5
        exit 0
    fi
    now=$(date +"%d %b%Y %k:%M:%S")
    echo "Current date / time: $now"
    for i in "${oid[@]}"
        do
        echo "oid : $i"
        # -Oqv return single value
	    datas+=","$(snmpget -v 2c  -c public -Oqv localhost  .1.3.6.1.2.1.25.1.5.0)
        done
    datas=$now""$datas
    # ajout des donnees dans le fichier  fichier data.csv
    echo $datas >> data.csv
    echo $datas
    sleep 1m # pause 1 minute
done




