#!/bin/bash

# Usage: ./zip.sh [directory]
# Zips all the files in the specified directory (or the current directory if no directory is specified)
# If the specified directory does not exist or is not readable, the script exits with an error message
# If the specified directory does not contain any files, the script prints a message and exits without creating a zip file
# If the specified directory contains files, the script creates a zip file named dir.zip containing all the files in the directory

# Check if a directory argument is provided; if not, default to the current directory
if [ $# -eq 0 ]; then
  dir="."
else
  dir="$1"
fi

# Check if the specified directory exists
if [ ! -d "$dir" ]; then
  echo "$dir is not a directory"
  exit 1
fi

# Check if the specified directory is readable
if [ ! -r "$dir" ]; then
  echo "$dir is not readable"
  exit 2
fi

# Print a message indicating the directory that will be zipped
echo "zipping files in the directory \"$dir\""

# Set the name of the zip file
zipfile=dir.zip

# If the zip file already exists, remove it
if [ -e "$zipfile" ]; then
  rm "$zipfile"
fi

# Initialize variables to store the list of files to zip and a counter for the number of files
files=""
declare -i n=0

# Loop through the files in the specified directory
for file in "$dir"/*; do
  # Check if the current item is a regular file and if it's readable
  if [ -f "$file" ] && [ -r "$file" ]; then
    # Append the file's path to the list and increment the counter
    files+=" $file"
    n=$((n+1))
  fi
done

# Check if there are no files to zip
if [ $n -eq 0 ]; then
  echo "no files to zip"
else
  # Print a message indicating the number of files to be zipped and the list of file paths
  echo "zipping the following $n files"
  echo $files

  # Create a zip archive containing the listed files
  zip "$zipfile" $files
fi
