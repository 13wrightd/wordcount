#!/bin/bash
# My first script

INPUT_STRING="ABC# .1-2-3"
OUTPUT_STRING=$(echo $INPUT_STRING | sed 's/[^\s/a-zA-Z0-9]//g')
echo $OUTPUT_STRING