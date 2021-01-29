#!/bin/bash
CPATH="/home/andrec/workspace_c/binPathC"

DESTINATION=("/mnt/pen_2G/" "/mnt/pen_500G/" "/mnt/pen_61G/" "/mnt/windows_xp_60G/" "/root/")

EXCLUDED=("$CPATH/*.o" "$CPATH/backup.sh" "$CPATH/.classpath" "$CPATH/.git" "$CPATH/.gitignore" "$CPATH/upload.sh" "$CPATH/.project" "$CPATH/.settings" "$CPATH/README.md")

for EXC in "${EXCLUDED[@]}"
do
    PARAM_SHORT=$PARAM_SHORT" --exclude=${EXC} "
    
done

for DEST in "${DESTINATION[@]}"
do
    if [[ -e $DEST ]];
    then
    sudo rsync -a $PARAM_SHORT $CPATH $DEST
    else
        echo "$DEST is not a directroy..creating"
        read -n 1 -p "press key to process other directroy"
        sudo mkdir -p $DEST
    fi;
    echo -e "\nEnd copy "$DEST
    
done


