# Étude de cas - Garderie d'animaux

Contexte : on veut modéliser une **garderie d’animaux** en C, en utilisant des **structures**, des **modules** et de **l’allocation dynamique**.

Vous allez progressivement construire trois modules :

1. `mod_animal` : gestion d’un animal et de son propriétaire (version simple, propriétaire contenu dans l’animal).
2. `mod_personne` : on sort la personne dans un module séparé, et l’animal ne stocke plus la personne elle-même mais **une référence** vers une personne.
3. `mod_garderie` : gestion d’une garderie qui contient un **tableau dynamique d’animaux**.

------

### Étape 0 – Définir la structure de données 

1. Définir le type `t_personne` représentant un propriétaire :

- nom (chaîne de caractères dynamique)
- prénom (chaîne de caractères dynamique)
- téléphone (chaîne de caractères, max ~20)

2. Définir le type `t_animal` représentant un animal :

- nom (ex. "Rex")
- espèce (ex. "Chien", "Chat")
- race (ex. "Golden Retriever")
- Date de naissance (jour, mois et année)
- propriétaire : une personne allouée de façon statique

3. Dans un main créer l'animal suivant: Le chien Choupi, un Golden Retriever né le 20 janvier 2021 qui appartient à Romy Boulanger dont le numéro de téléphone est le 514-345-8967.

   À la fin de votre main, libérer l'espace alloué par votre animal.

4. Modifier la structure de données pour que le propriétaire soit alloué de façon dynamique. Modifiez votre main en conséquence. 

### Étape 1 – Modules `mod_personne` et `mod_animal`

1. Créez un module `mod_personne` qui encapsule le type `t_personne` et qui définit les fonctions suivantes: 

```
t_personne* init_personne(const char* nom, const char* prenom, const char* telephone);
void afficher_personne(const t_personne* p);
void free_personne(t_personne* p);
```



2. Créez le module `mod_animal` qui définit les fonctions suivantes 

```
t_animal* init_animal( const char* nom,
                 const char* espece,
                 const char* race,
                 int annee_naiss, int mois_naiss, int jour_naiss,
                 const t_personne* proprietaire);
void afficher_animal(const t_animal* a);
void free_animal(t_animal* a);
```

3. Écrire un petit programme `main.c` qui :

- crée  **deux propriétaires** (`t_personne`)
- crée  **trois animaux** (`t_animal`), avec des propriétaires
- appelle `afficher_animal` pour afficher les informations
- Libère la mémoire occupée à la fin.

------

### Étape 2 – Module Garderie

1. Créer le module `mod_garderie` qui définit une garderie comme un tableau dynamique d'animaux. 
2. Depuis le main, créer une garderie et y ajouter des animaux. 

### Étape 3 – Fonctions d'ajout et de suppression d'animaux

1. Créez la fonction `garderie_ajouter_animal` qui ajoute à la liste des animaux l'animal reçu en paramètre. Assurez-vous de ne pas déborder de la taille du tableau (l'agrandir au besoin) et de mettre à jour les champs de la garderie adéquatement. La fonction renvoie une valeur vraie si l'animal a bien été ajouté, ou fausse sinon.  

   Voici le prototype de la fonction: 

    ```c
    int garderie_ajouter_animal(t_garderie* g, const t_animal* a);
    ```

2. Créez la fonction `garderie_retirer_animal` qui supprime l'animal se trouvant à l'indice reçu en paramètre dans le tableau des animaux. Votre fonction doit retourner la référence vers  l'animal supprimé. Si l'animal ne se trouve pas dans le tableau, votre fonction retourne le pointeur `NULL`. 

   Voici le prototype de la fonction: 

   ```c
   t_animal* garderie_retirer_animal(t_garderie* g, int indice);
   ```

   **Note importante:** Il ne faut pas laisser de trous *vides* dans le tableau. 

3. Créez la fonction `garderie_chercher_animal` qui identifie la position d'un animal dans le tableau des animaux d'une garderie. Votre fonction retournera -1 si l'animal ne s'y trouve pas. 

   ```c
   int garderie_chercher_animal(const t_garderie* g, const t_animal* a);
   ```

   

4. Créez la fonction `garderie_retirer_animal_ref` qui supprime l'animal du tableau d'animaux d'une garderie dont la référence est passée en paramètre. Votre fonction doit retourner la référence vers  l'animal supprimé. Si l'animal ne se trouve pas dans le tableau, votre fonction retourne le pointeur `NULL`. 

   **Indice: ** Utilisez les deux fonctions précédentes.

   ```c
   t_animal* garderie_retirer_animal_ref(t_garderie* g, const t_animal* a);
   ```



### Étape 4: Sauvegarde et chargement d'une garderie

1. Écrivez la fonction `garderie_sauvegarder` qui sauvegarde dans un fichier texte l'ensemble de la garderie. Le fichier texte créé devra avoir le format suivant: 

   ```bash
   Nbre_Animaux
   NomAnimal1
   EspeceAnimal1
   RaceAnimal1
   jour mois annee
   NomProprietaire1
   PrenomProprietaire1
   TelProprietaire1
   ```

   Par exemple, le fichier suivant représente une garderie ayant 2 animaux: 

   ```
   2
   Choupi
   Chien
   Golden Retriever
   20 1 2021
   Boulanger
   Romy
   5149807867
   Ghost
   Loup
   Direwolf
   18 10 1999
   Snow
   Jon
   5147865456
   ```

   Votre fonction reçoit une référence vers la garderie ainsi que le nom du fichier (chemin d'accès) où la sauvegarde doit être effectuée. Elle retourne une valeur vraie si la sauvegarde a bien eu lieu, ou fausse sinon. Voici le prototype de votre fonction: 

   ```c
   int garderie_sauvegarder(const t_garderie* g, const char* nom_fichier);
   ```

   **Conseil:** Pour faciliter l'écriture de cette fonction et respecter les principes d'encapsulation, créez les fonctions utilitaires suivantes dans vos modules `mod_personne` et `mod_animal` qui se chargent d'écrire *dans un fichier déjà* ouvert les informations d'une personne et d'un animal (respectivement).

   ```C
   int personne_sauvegarder(FILE* fichier, const t_personne* p);
   int animal_sauvegarder(FILE* fichier, const t_animal* p);

2. Écrire la fonction `garderie_charger` qui lit les informations d'une garderie à partir d'un fichier texte respectant le même format que la question précédente et qui charge toutes les informations en mémoire dans une `t_garderie`. Votre fonction retourne une référence vers la `t_garderie` créée si le chargement a bien eu lieu, ou `NULL` sinon. 

   ```c  
   t_garderie* garderie_charger(const char* nom_fichier);
   ```

   