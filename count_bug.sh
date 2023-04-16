#!/bin/bash

# loop through each file in the directory
cd 01.w_Defects || exit
for filename in *.c; do
  # run the Infer command on each file
  results="${filename%.c}_results"
    rm -rf "${results}"

echo "${filename} $(cat "${filename}" | grep -o "Tool" | wc -l)"

done

cd ..
