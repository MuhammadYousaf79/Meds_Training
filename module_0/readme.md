# **BASH SCRIPT TUTORIAL** 

### Overview

This is a mini **file manager** that manupilates files and directories.File run in the working directory.This Bash script acts as a simple **file management utility**. It allows users to perform basic file operations via a menu-driven interface in the terminal.

## SCRIPT
```
#!/bin/bash
echo -e "You are now at:\n"
pwd
echo -e "\n1- To create a file"
echo "2- To open a file"
echo "3- To delete a file/directory"
echo "4- To copy file/directory"
echo "5- To move file/directory"
read options
case $options in
    1)
        echo -e "\nEnter file name:"
        read filename
        if [ -f "$filename" ]; then
            echo "$filename already exists."
        else
            touch $filename
            if [ $? -eq 0 ]; then
                echo "$filename created in $(pwd)"
            fi
        fi
        ;;
    2)
        while true; do
            ls
            echo -e "\nEnter file name You wish to go:"
            read filename
            if [ -f "$filename" ]; then
                vim "$filename"
                break
            else
                echo -e "\n$filename does not exist. Enter a valid file name.\n"
                echo " OR Press e to exit"
                read ans
                if [ "$ans" = "e" ]; then
                    break
                fi
                echo "-------------------------------------------------------------------"
            fi
        done
        ;;
    3)
        while true; do
            ls
            echo -e "\nEnter file/directory name You wish to delete:"
            read filename
            if [ -f "$filename" ] || [ -d "$filename" ]; then
                echo "$filename will be permanently deleted."
                echo "This is irreversible. Are you sure? [y/n]"
                read ans
                if [ "$ans" = "y" ] || [ "$ans" = "Y" ]; then
                    rm -rf "$filename"
                fi
                break
            else
                echo -e "\n$filename does not exist. Enter a valid name.\n"
                echo " OR Press e to exit"
                read ans
                if [ "$ans" = "e" ]; then
                    break
                fi
                echo "-------------------------------------------------------------------"
            fi
        done
        ;;
    4)
        ls
        echo -e "\nChoose which file or directory to copy."
        read filename
        if [ -f "$filename" ] || [ -d "$filename" ]; then
            echo -e "\nGive the path where to copy."
            read filpath
            if [ -e "$filpath" ]; then
                cp -r "$filename" "$filpath"
                if [ $? -eq 0 ]; then
                    echo -e "\n$filename copied at $filpath"
                else
                    echo -e "\n$filename not copied at $filpath"
                fi
            fi
        fi
        ;;
    5)
        ls
        echo -e "\nChoose which file or directory to move."
        read filename
        if [ -f "$filename" ] || [ -d "$filename" ]; then
            echo -e "\nGive the path where to move."
            read filpath
            if [ -e "$filpath" ]; then
                mv -r "$filename" "$filpath"
                if [ $? -eq 0 ]; then
                    echo -e "\n$filename moved to $filpath"
                else
                    echo -e "\n$filename not moved to $filpath"
                fi
            fi
        fi
        ;;
    *)
        echo "Invalid Option chosen"
        ;;
esac

```
Save this in a file that ends with .sh as file extention.


### Features

1. CREATE a file in a directory.
2. OPEN a file usig VIM.
3. DELETE a file or a directory. (Confirms the action with warning.)
4. COPY a file or directory to another directory.
5. MOVE file or directory to another directory. 

## Menu Options Explained

### Option 1: Create a File

- Prompts you for a filename.  
- Checks if it already exists.  
- If not, creates the file in the current directory.

### Option 2: Open a File

- Lists the files in the current directory.  
- Prompts for a filename.  
- Opens the file in `vim` if it exists.  
- Allows retrying or exiting if the file doesn't exist.

### Option 3: Delete File/Directory

- Lists contents of the directory.  
- Asks which file or directory to delete.  
- Asks for confirmation before deletion.  
- Deletes using `rm -rf`.

> ⚠️ **This is irreversible. Be cautious.**

### Option 4: Copy File/Directory

- Lists files/directories.  
- Asks which item to copy.  
- Asks for the destination path.  
- Copies using `cp -r`.

### Option 5: Move File/Directory

- Lists current contents.  
- Asks which item to move.  
- Asks for the destination path.  
- Moves using `mv`.

## ⚠️ Notes

- Make sure you have the required permissions for file operations.  
- Ensure the paths you provide exist (especially for copy/move).  
- The script uses `vim` for opening files — feel free to change this to `nano`, `gedit`, or your preferred editor.


## How To Run This Script

Make you have executable permissions for this file.
you can do so by ruing this in terminal.
```
chmod +x file_manager.sh
```
then run the script using this
```
source file_manager.sh
```