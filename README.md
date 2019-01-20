# My project's README

Q1. What do you see in the command screen?

 	On branch master
 	Your branch is up-to-date with 'origin/master'.

 	Untracked files:
   	 (use "git add <file>..." to include in what will be committed)

		doc/

 	nothing added to commit but untracked files present (use "git add" to track)

Podem veure que el nostre repositori només tenim una carpeta anomenada "doc"
i està actualitzat només localment, per això "doc" apareix de color vermell.
A més, si volem afegir un arxiu, s'indica en la última línia com fer-ho.

-------------------------------------------------------------------------------

Q2. Use the command git status again and explain what has changed?

	 On branch master
 	Your branch is up-to-date with 'origin/master'.

  	Changes to be committed:
   	 (use "git reset HEAD <file>..." to unstage)

		modified:   README.md

 	Untracked files:
   	 (use "git add <file>..." to include in what will be committed)

		README.md~
		doc/

Se'ns informa que l'arxiu README.md ha estat afegit i per això ens apareix
llistat a sota, juntament amb la carpeta "doc".

-------------------------------------------------------------------------------

Q3. What is the output of the command? What is the current status?

	diff --git a/README.md b/README.md
	index 2724cb0..96f3aa2 100644
	--- a/README.md
	+++ b/README.md
	@@ -1,2 +1,3 @@
 	# My project's README
 	 upf-se-09
	+Prova per veure si s'ha modificat.

A la tercera i quarta fila s'indica que l'arxiu modificat només està localment,
mentre que l'online encara no ha estat actualitzat.
Podem veure que a la última fila, apareix la frase que hem afegit amb un "+"
davant, com a indicador del que ha canviat dins l'arxiu.

-------------------------------------------------------------------------------

Q4. What can be a good message for the first commit? What is the current status?

 	Committer: u124277 <u124277@54003p34.aulesca.upf.edu>
	Your name and email address were configured automatically based
	on your username and hostname. Please check that they are accurate.
	You can suppress this message by setting them explicitly:

    		git config --global user.name "Your Name"
    		git config --global user.email you@example.com

	After doing this, you may fix the identity used for this commit with:

    		git commit --amend --reset-author

 	1 file changed, 2 insertions(+)

Un bon missatge pel primer commit podria ser "first commit" o "prova", per exemple.
Nosaltres hem optat per posar "lol" perquè és el primer que se'ns ha passat pel cap,
abans de veure la pregunta de l'enunciat.
Se'ns indica quin usuari ha fet el commit i què ha aportat: en el nostre cas s'ha
canviat un arxiu i s'han realitzat dues insercions.

-------------------------------------------------------------------------------

Q5. How many commits there are in the log? What are the first seven digits 
(letters and numbers) that identify the first README.md commit?

	commit 19a668c25ce10d6518bad6a28a673faefc7b5036
	Author: u124277 <u124277@54003p34.aulesca.upf.edu>
	Date:   Wed Jan 18 17:38:08 2017 +0100

    		lol

	commit fcc59a4e2d05c7e751d6f15589493e9385997917
	Author: u124277 <u124277@54003p34.aulesca.upf.edu>
	Date:   Wed Jan 18 16:58:26 2017 +0100

    		Initial commit

Veiem que al log apareixen dos commits, l'inicial, "Initial commit", i el primer
commit que hem realitzat nosaltres, "lol". Els 7 primers dígits o lletres que hi
trobem al primer commit són "fcc59a4", que creiem que és l'identificador del commit.

Q6. Modify one line of the README.md, add to the staging area and commit. 
Then use the commandgit show HEAD, and explain the output.

	commit 4d05e6162658c7de1f3f00b373e01eee61af211c
	Author: u124283 <u124283@54021p14u.ds.upf.edu>
	Date:   Thu Jan 19 16:17:14 2017 +0100

    		lol2

	diff --git a/README.md b/README.md
	index 96f3aa2..166afc9 100644
	--- a/README.md
	+++ b/README.md
	@@ -1,3 +1,4 @@
 	# My project's README
 	upf-se-09
 	Prova per veure si s'ha modificat.
	+Segona modificació.

Mostra la comparació del que hi ha en el fitxer amb el commit anterior. 
Ens mostra les diferencies exactes que hi ha entre els dos commits. 
En el nostre cas ens indica que hem afegit una frase al final del document README.md.

-------------------------------------------------------------------------------

Q7. Rewrite the sentence you restored with the previous command. After that, 
add the README.md to the staging area. Then, run a reset in the README.md 
and explain what happens.

	Unstaged changes after reset:
	M	README.md

Com podem veure, se'ns informa que s'han realitzat canvis després de la restauració.

-------------------------------------------------------------------------------

Q8. Create a new branch called “documents”. Use git branch and explain where 
you are and how many branches you have?

	  documents
	* master

Hem creat el branch "documents" i al fer "git branch" ens apareixen dos branch.
L'asterisc indica que "master" es el branch que tenim actualment.

-------------------------------------------------------------------------------

Q9. Add the file and make a commit with a nice message.  What is the content 
of the README.md in both branches?

	Branch "documents":
 	 We are in the documents branch
	Branch "master":
 	 upf-se-09
 	 Prova per veure si s'ha modificat.
 	 Segona modificació.
 	 Prova pel head commit.

Com podem veure, en el branch "documents" es troba la informació que hem canviat i,
en el branch "master", es troba la informació que teníem prèviament.


