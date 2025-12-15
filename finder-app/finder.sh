#!/usr/bin/env bash


filesdir="$1"
searchstr="$2"

if [ $# -lt 2 ] || [ -z "$filesdir" ] || [ -z "$searchstr" ]; then
  echo "Error: missing required arguments."
  echo "Usage: $0 <filesdir> <searchstr>"
  exit 1
fi


if [ ! -d $filesdir ]; then
  echo "filesdir $filesdir does not exist"
  exit 1
fi

X=$(find "$filesdir" -type f  | wc -l )

Y=$(grep -R -F "$searchstr" "$filesdir"  | wc -l )

echo "The number of files are $X and the number of matching lines are $Y"
exit 0

