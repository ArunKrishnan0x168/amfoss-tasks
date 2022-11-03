# This documentation includes all the terminal commands,git commands that i've used to get the password to unlock the Secret-Scroll pdf.

## Part-1 and 2

So first i had to clone the repository to my local machine so i've used git for this on the terminal so the command was

``` git clone https://github.com/gauthamk02/TerminalHunt.git ``` 

then i had to move into the cloned repo so i've used the linux terminal command ``` cd ``` for this purpose and i then had to make a directory called "solution" so i've used another linux command ie, ``` mkdir solution ```. after this the part1 and part2 password parts were easy to find.

## Part-3

Then on i had to take a look at the commit log to see what was the hint so for that i've used another git command ie, ``` git log main ``` as i was working with "main" branch, thereafter i solved the puzzle and got part3 of the password as well.

Then i had to commit all the changes to the main branch so i used another git command ie ``` git commit -m "New files" ```, Hence i successfully commited all the changes.

## Part-4

On to the final part, so the file was in a different branch so at first i used ``` git branch -a ``` to see all the branches then i used ``` git checkout asia ``` to change my branch from main to asia, Now i needed to find the file so i've used another linux command ie ``` find . -name athens.txt ``` to get the file, Now i had the file in the asia branch i had  to merge this branch to main so that i can copy contents of athens.txt to part4.txt so for that i've used ``` git checkout main ``` to move back to the main branch and then i used ``` git merge asia ``` to merge the contents of asia to the main branch. Now i just copied the file contents from athens.txt to part4.txt in my solutions folder, hence i got all the 4 parts and then i just combined them to make a password which was then used to open the Secret-Scroll pdf file, which is provided in this folder.

I thank you for reading this, thank you for making such a beautiful task.