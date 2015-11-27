#!/bin/bash
if [ -n "$1" ];           
then
    pipe=$1
else
    pipe=./fif
fi 

echo $pipe
menu1()
{
loop=0
while [ $loop = 0 ]
do
    clear
    echo "get-led-state" >$pipe
    read state < $pipe
    echo "get-led-color" >$pipe
    read color < $pipe
    echo "get-led-rate" >$pipe
    read rate < $pipe
    PS3='Please enter your choice: '
    menuText1=("turn on\off($state)" "change color($color)" "change rate($rate)" "Quit")
    select opt in "${menuText1[@]}"
    do
        case $opt in
            "turn on\off($state)")
                echo "get-led-state" >$pipe
                read state < $pipe
         
                if [ "$state" = "OK off" ];
                then  
                    echo "set-led-state on" > $pipe
                else
                    echo "set-led-state off"> $pipe
                fi 
                read state < $pipe
                echo $state
                break 
                ;;
            "change color($color)")
                menu2
                break
                ;;
            "change rate($rate)")
                menu3
                break
                ;;
            "Quit")
                
                echo "quit"
                exit
                break
                ;;
            *) echo invalid option;;
        esac
    done
done
}
menu2()
{
menuText2=("red" "green" "blue")
select opt in "${menuText2[@]}"
do
    case $opt in
        "red")
            echo "set-led-color red"> $pipe
            read color < $pipe
            echo $color
            break
            ;;
        "green")
            echo "set-led-color green"> $pipe
            read color < $pipe
            echo $color
            break
            ;;
        "blue")
            echo "set-led-color blue"> $pipe
            read color < $pipe
            echo $color
            break
            ;;
        *) echo invalid option;;
    esac
done
}

menu3()
{
menuText3=("0" "1" "2" "3" "4" "5")
select opt in "${menuText3[@]}"
do
    case $opt in
        "0")
            echo "set-led-rate 0"> $pipe
            read rate < $pipe
            echo $rate
            break
            ;;
        "1")
            echo "set-led-rate 1"> $pipe
            read rate < $pipe
            echo $rate
            break
            ;;
        "2")
            echo "set-led-rate 2"> $pipe
            read rate < $pipe
            echo $rate
            break
            ;;
        "3")
            echo "set-led-rate 3"> $pipe
            read rate < $pipe
            echo $rate
            break
            ;;
        "4")
            echo "set-led-rate 4"> $pipe
            read rate < $pipe
            echo $rate
            break
            ;;
        "5")
            echo "set-led-rate 5"> $pipe
            read rate < $pipe
            echo $rate
            break
            ;;
        *) echo invalid option;;
    esac
done
}

menu1





