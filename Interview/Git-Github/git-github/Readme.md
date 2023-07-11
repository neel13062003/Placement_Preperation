# Git-GitHub

*** Most Important Things to keep it in your mind - Code With Harry Playlist { approx 18 videos youtube } ***

*** Git not store your whole code it only store your track just like you can understand as google histroy not store video you watch but it store which video you watch and when ***


1) First Step create git repository(public or private) from github {With Out Readme file tick}
2) You Can Add Colloborator via their email 
3) Get SSH(git@github.com:neel13062003/BitCoin-MLM.git) like...

{In Your PC where you create git repositru where you can see hidden folder with ".git" name with ls --a commma} 
*** Some HelpFul Linux Command ***
ls = listing file
ls --a = see all files + folder including hidden(.git-where all your contian store)
touch filename = create file {Using this help you can create git.ignore file }
{ In this git.ignore file whatever you write as folder path or filename is not including to push into github
  For Ex.You not want to store your required library to push.
}
rm -rf .git =  you can delete your .git folder
mkdir fold_name = create folder using command
clear = clear screen


1) git init  = Initialise Git repositry where which folder you want to push into github
2) git add . or git add --a = add all files or you can add one by one file as your wish
3) git status = check git status
4) git commit -m "First Commit" = after clean working tree
5) git log = you can see your commit histroy of your branch
6) git branch = you can ensure you are in which branch         

7) git checkout -b alpha = you can create alpha branch with move to alpha branch                  
8) git checkout alpha = you can move to alpha branch { if already exists } 
{ Always Keep in mind while changing branch your branch must be clean }

*** Make Sure You want to publish your code to connect with github account with locally you create SSH key and add it{ Code With Harry Video } *** 
6) git remote add origin "git@github.com:neel13062003/BitCoin-MLM.git" 
7) git push -u origin master{current Branch name} - Your First Branch Set As Your Default branch in github
[  You can add Readme.md file with it ] - git add Readme.md

{ If You work on team and create alpha,beta branch then you can create.
    Then switch to this branch and do your work and simply push your code
}

***  In alpha1 branch you want to merge with master then ***
=> You are currently in alpha branch
9) git fetch origin
10) git merge origin/master  {Some time not work then below}
10) git merge origin/master --allow-unrelated-histories 
 {   press - "i" to insert write something you want to write as msg 
     press - "Esc" + ":" + "w" + "q" - To Quit from this}
11) git push origin alpha1:master

*** Now Coming to master branch and check it diff ***
12) git checkout master
13) git branch 
look like = {    
    *master
    alpha 
    beta 
}
14) git pull
15) git add . 
16) git commit -m "msg".

*** Some Extra Commands ***

1) You want to show your origin = git remote -v
2) You want to restore your code as your last commit =  git checkout -f
3) You can directly getting your code from github zip but in command  - git clone "path.git"


*** Important ***

- It's very simple when you only want to track your code into github 
- In team project structure should be

    master
       alpha
           beta1
           beta2
           beta3
- In Open Source project you required to be first fork project it will show you in listed github repositrhy


*** Github/Git is Very Vast learning platform keep it learning you can't learn everything in one day ***




Learn => https://www.w3schools.com/git/default.asp</br>
PlayList => https://youtube.com/playlist?list=PLu0W_9lII9agwhy658ZPA0MTStKUJTWPi </br>(Code With Harry)</br>
19 Videoes

https://github.com/kunjgit/GameZone/blob/main/.github/CONTRIBUTING_GUIDELINE.md  = open source
