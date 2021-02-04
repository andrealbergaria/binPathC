#!/bin/bash
seq 1 8 | tr '\n' 'A' >> plainTextCBC
seq 1 8 | tr '\n' 'A' >> plainTextCBC

seq 1 8 | tr '\n' 'A' >> plainTextECB
seq 1 8 | tr '\n' 'A' >> plainTextECB


openssl enc -aes-256-cbc -no-pad -p -K 616161 -iv 616161 -in plainTextCBC  -out cipherTextCBC
openssl enc -aes-256-ecb -no-pad -p -K 616161 -in plainTextECB -out cipherTextECB
