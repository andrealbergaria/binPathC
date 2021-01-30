#!/bin/bash
openssl enc -aes-256-cbc -p -K 61616161 -iv 61616161 -in plainText  -out cipherText
