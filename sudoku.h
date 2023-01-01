/****************************************************************/
/* Auteur : S. Gueye						                    */
/* TP : Sudoku bactracking algorithm				            */
/* Date dernière maj : 24/11/2020				                */
/****************************************************************/

/****************************************************************/
/* Objectif : Classe représentant une cellule de la grille
/****************************************************************/
class cellule
{
public:
	int l;								 // Numéro de ligne
	int c;								 // Numéro de colonne
	int b;								 // Numéro du bloc où se situe la cellule (l,c)
	int n;								 // Nombre de chiffres qu'il est possible initialement d'utiliser sur la cellule
	cellule(int i, int j); // C	onstruit la cellule de numéro de ligne i et colonne j
};

/****************************************************************/
/* Objectif : Classe permettant de lire une grille sudoku et de la résoudre
/****************************************************************/
class sudoku
{
	int grille[9][9]; // La grille
	cellule *C[81];		// Cellules vides
	int r;						// nbr de cellules vides

public:
	sudoku(char filename[]); // Lecture de la grille sudoku se trouvant dans le fichier filename
	void affichage();				 // Affichage de la grille
	bool solution();				 // Calcul de solution
	void cellulesVides();		 // Constructions des cellules pour les cases vides
	bool presenceLigne(int chiffre, cellule *C);
	bool presenceColonne(int chiffre, cellule *C);
	bool presenceBlock(int chiffre, cellule *C);
	bool BacktrackingSudoku(int k);
};
