# Minishell – Projet Epitech

Minishell est un projet réalisé dans le cadre du cursus Epitech, dont l’objectif est de recréer un shell Unix simple, inspiré du comportement de `tcsh`.

## Objectif

Reproduire **les fonctionnalités de base de `tcsh`**, à savoir :
- Exécution de commandes binaires (`ls`, `cat`, `sudo`, `ip`, etc.)
- Recherche des exécutables dans le `PATH`
- Gestion des erreurs simples
- Commandes internes comme `cd`, `exit` (à venir)

##  Fonctionnalités actuelles

-  Parsing de la commande entrée par l’utilisateur
-  Exécution de binaires via `fork()` / `execve()`
-  Gestion dynamique du `PATH`
-  Affichage du prompt simple
-  Implémentation de commandes internes (`cd`, `exit`, etc.)
-  Gestion des redirections (`>`, `<`, `>>`)
-  Support des pipes (`|`)
## À venir

-  Nettoyage mémoire et gestion fine des erreurs
-  Amélioration du prompt
-  Autocompletion
-  Gestion des signiaux
