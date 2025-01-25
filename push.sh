#!/bin/bash

# Get the current date in YYYY-MM-DD format
current_date=$(date +"%Y-%m-%d")

# Check if a custom message was passed
if [ $# -eq 0 ]; then
  # Default commit message with the current date
  commit_message="Commit made on $current_date"
else
  # Append user-provided message to the current date
  commit_message="$current_date: $*"
fi

# Stage all changes
git add .

# Make the commit with the constructed message
git commit -m "$commit_message"

git push
