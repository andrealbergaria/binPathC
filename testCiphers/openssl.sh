#!/bin/bash
sudo openssl enc -aes-256-cbc -e iv 0x0 \ 
-nosalt -in files/plaintext.txt \ 
-out files/ciphertext -iv 0     \
-nosalt -p
