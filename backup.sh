#!/bin/bash
SHORTPATH="/home/andrec/workspace_3_8/binPathShort"

DESTINATION=("/mnt/pen_2G/" "/mnt/pen_500G/" "/mnt/pen_61G/" "/mnt/windows_xp_60G/" "/root/")

EXCLUDED=("$SHORTPATH/backup.sh" "$SHORTPATH/classes" "$SHORTPATH/.classpath" "$SHORTPATH/.git" "$SHORTPATH/.gitignore" "$SHORTPATH/upload.sh" "$SHORTPATH/.project" "$SHORTPATH/.settings")

for EXC in "${EXCLUDED[@]}"
do
    PARAM_SHORT=$PARAM_SHORT" --exclude=${EXC} "
    
done

for DEST in "${DESTINATION[@]}"
do
    if [[ -e $DEST ]];
    then
    sudo rsync -a $PARAM_SHORT $SHORTPATH $DEST
    else
        echo "$DEST is not a directroy..creating"
        read -n 1 -p "press key to process other directroy"
        sudo mkdir -p $DEST
    fi;
    echo -e "\nEnd copy"
    
done


