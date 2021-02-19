#!/bin/bash
openssl enc -aes-256-ecb -nopad -p -K 61616161 -in plainTextECB -out cipherTextECB
