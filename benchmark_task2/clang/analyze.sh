#!/bin/bash

# loop through each file in the directory
for filename in *.c; do
  # run the Infer command on each file
  results="${filename%.c}_results"
  if [ ! -d "${results}" ]; then
    mkdir "${results}"
  fi
    
  clang --analyze -Xanalyzer -analyzer-checker=core "${filename}" > "${results}"/Clang_result.txt 2>&1

done

rm *.plist
