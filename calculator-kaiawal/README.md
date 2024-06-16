# Assignment 5
This is your assignment repo. It was created when you accepted the assignment on GitHub Classroom.

## Getting Started
To get started on the programming portion of this assignment, simply clone this repository to some local space (e.g., your file space on the ENGR servers); complete the starter code, fulfilling all of the requirements outlined in the assignment description document; and then stage, commit, and push your work back to this repo. You can do this following the same steps as you did in past assignments. For your convenience, here are those steps (Important: These steps assume that you've already configured SSH keys to authenticate with GitHub from the ENGR servers; if you haven't done this, refer to studio 2 before continuing):

1. Copy this repo's SSH URL by clicking on the "<> Code" button at the topright of this repo's main page (probably the page that you're reading this text in right now), selecting the "SSH" tab, and clicking on the clipboard icon
2. Open your terminal and connect to the ENGR servers via SSH
3. Using commands like `ls`, `pwd`, and `cd`, navigate to the directory in which you want to store all of your assignment work for this class.
4. Execute `git clone <PASTE SSH URL FOR THIS REPO HERE>`
5. Execute `ls`. There will now be a new directory called `calculator-XXX`, where `XXX` is your GitHub username. Enter that directory via `cd`.
6. Execute `ls`. You should now be able to see this file (`README.md`) along with the rest of the starter code. Use `vim` to edit and complete the starter code, fulfilling the assignment requirements in the assignment description document.

## What to complete

This assignment contains a lot of starter code that you generally shouldn't modify. All you need to do is fill in the blanks by completing the "TODO" items in `calculator.cpp` and `main.cpp`. Read the comments thoroughly to make sure you understand your responsibilities versus what I've already done for you.

## Building the program

This program consists of multiple `.cpp` and `.hpp` files. This is necessary to get the grading script to work (see the next section of this README file).

You do not need to create any more files (just modify the existing ones, as explained above), nor do you need to understand *how* these files are connected together. However, you do need to understand this: in order to build this program, you should execute the `make` command in the terminal (similar to the last assignment). This will execute the default target of the provided `Makefile` and build your executable, which will be called `calculator`. After running `make` to build your program, you'll then be able to test it by running `./calculator`.

## Grading script

This repository also includes a grading script that you can use to approximate what your actual grade will be on a large chunk of the assignment rubric. It can be executed from within your project directory via:

`make test`

Disclaimer: This grading script is similar but not identical to the actual grading script that will be used by a TA to compute this part of your assignment grade. It only produces an *approximation* of what your grade will be. Hard-coding solutions in an effort to fool the grading script will not work; it will only overestimate what your actual grade will be.

The grading script gives you a grade out of 100. This includes the max 30pts of extra credit, so the highest score that the grading script will output if you **don't** complete any extra credit work is 70/100. A maximum of 30 **more** points can be earned when your randomly assigned TA grades the remaining parts of the rubric (the points for array usage in `main.cpp` and the points for following the style guidelines). In total, this means that you can earn 130/100 on this assignment if you complete all of the extra credit.

This assignment has no demo, so there are no points allotted to Q&A.

## Submitting your work
As you work on your assignment, you should **frequently** test your code and create new commits reflecting the small changes that you've made since the last commit (remember---VCS helps you rollback your changes to an old commit in case you accidentally break something, but this is only useful if you make new commits frequently).

To submit your work, all you have to do is:
1. Make sure that all of your work has been reflected in your latest commit (all files should be in a committed state---`git status` should not report anything to be in a modified or staged state)
2. Push all of your commits back to this GitHub repo via `git push`
3. Open this repo in your browser, refresh the page, and verify that it contains your latest work

The instructor and TAs have access to this GitHub repo, so as long as your work has been pushed here, you can consider it submitted. Note that we will check the timestamp of your latest commit to determine whether it's a late submission (review the course's late policy in the syllabus).
