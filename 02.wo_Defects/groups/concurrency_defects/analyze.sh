#!/bin/bash

# loop through each file in the directory
for filename in *.c; do
  # run the Infer command on each file
  results="${filename%.c}_results"
  if [ ! -d "${results}" ]; then
    mkdir "${results}"
  fi

  infer run \
    --starvation\
    --racerd\
    --enable-issue-type ARBITRARY_CODE_EXECUTION_UNDER_LOCK\
    --enable-issue-type DEADLOCK\
    --enable-issue-type IPC_ON_UI_THREAD\
    --enable-issue-type LOCKLESS_VIOLATION\
    --enable-issue-type STARVATION\
    --enable-issue-type STRICT_MODE_VIOLATION\
    --enable-issue-type GUARDEDBY_VIOLATION\
    --enable-issue-type GUARDEDBY_VIOLATION_NULLSAFE\
    --enable-issue-type INTERFACE_NOT_THREAD_SAFE\
    --enable-issue-type LOCK_CONSISTENCY_VIOLATION\
    --enable-issue-type THREAD_SAFETY_VIOLATION\
    --enable-issue-type THREAD_SAFETY_VIOLATION_NULLSAFE\
    --disable-issue-type DEAD_STORE\
    -o "${results}"/Infer_result -- clang -c "${filename}"
  
  clang --analyze -Xanalyzer -analyzer-checker=core "${filename}" > "${results}"/Clang_result.txt 2>&1

done

rm *.o
rm *.plist