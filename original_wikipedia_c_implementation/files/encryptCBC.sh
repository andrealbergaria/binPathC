#!/bin/bash


openssl enc -aes-256-cbc -no-pad -p -K 616161 -iv 616161 -in plainTextCBC  -out cipherTextCBC
