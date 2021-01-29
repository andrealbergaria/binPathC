#!/bin/bash

if [[ -z $1 ]];
then
    echo -e "Must set commit msg on arg\n";
    exit;
fi

git add /home/andrec/workspace_c/binPathC/.

git commit -m "$1"
git push https://github.com/andrealbergaria/binPathC



. /home/andrec/workspace_c/binPathC/backup.sh
