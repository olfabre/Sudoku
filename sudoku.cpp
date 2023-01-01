#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

#include "sudoku.h"

/****************************************/
/* Objectif : Construction d'une cellule
/****************************************/
cellule::cellule(int i, int j)
{
    /*
    Algorithme à programmer:
    - On affecte les valeurs ligne, colonne, block à l'objet créé
    */
    n = 9;
    l = i;
    c = j;
    // Détermination du block de la cellule
    if (j >= 0 && j <= 2)
    {
        // Blocks 1,4,7

        if (i >= 0 && i <= 2)
        {
            b = 1;
        }
        if (i >= 3 && i <= 5)
        {
            b = 4;
        }
        if (i >= 6 && i <= 8)
        {
            b = 7;
        }
    }
    if (j >= 3 && j <= 5)
    {
        // Blocks 2,5,8
        if (i >= 0 && i <= 2)
        {
            b = 2;
        }
        if (i >= 3 && i <= 5)
        {
            b = 5;
        }
        if (i >= 6 && i <= 8)
        {
            b = 8;
        }
    }
    if (j >= 6 && j <= 8)
    {
        // Blocks 3,6,9
        if (i >= 0 && i <= 2)
        {
            b = 3;
        }
        if (i >= 3 && i <= 5)
        {
            b = 6;
        }
        if (i >= 6 && i <= 8)
        {
            b = 9;
        }
    }
}

/****************************************/
/* Objectif : Construteur avec argument
permettant la création d'une grille à partir d'un
fichier.
/****************************************/
sudoku::sudoku(char filename[])
{
    // grille remise à zéro
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
            grille[i][j] = 0;
    }
    // Ouverture objet "file" flux de lecture sur un fichier en argument
    ifstream file(filename);
    int nb;
    // lecture et affectation des valeurs dans le tableau grille[i][j]
    for (int ligne = 0; ligne < 9; ligne++)
    {

        for (int colonne = 0; colonne < 9; colonne++)
        {
            file >> nb;
            grille[ligne][colonne] = nb;
        }
    }

    // on ferme l'objet "file"
    file.close();
}

/***********************************************/
/* Objectif : Constructions des cellules vides
/***********************************************/
void sudoku::cellulesVides()
{
    /*
    Algorithme à programmer:
    - On parcours toute la grille
    - On incrémente le compteur "r" à chaque case 0 racontrée
    - On créé 1 cellule vide à chaque case contenant 0
    - On retourne le nbr de cellule créée
    */
    // Initialisation
    int compteur = 0;

    // Parcours grille
    for (int i = 0; i < 9; i++)
    {

        for (int j = 0; j < 9; j++)
        {
            if (grille[i][j] == 0)
            {
                // incrementation
                compteur++;
                // création
                C[compteur] = new cellule(i, j);
            }
        }
    }
    // vérification tests
    /*
    for (int i = 1; i < (compteur + 1); i++)
    {
        cout << "Cellule N°" << i << " l= " << C[i]->l << " c= " << C[i]->c << " b= " << C[i]->b << endl;
    }
    */
    // On affecte le nombre de cellules vides
    r = compteur;
}

/*******************************************************/
/* Objectif : vérifie la présence d'un chiffre sur ligne
/*******************************************************/
bool sudoku::presenceLigne(int chiffre, cellule *C)
{
    /*
    Vrai si le chiffre passer en argument est présent dans la ligne passer en argument
    Faux si le chiffre passer en argument est présent dans la ligne passer en argument
    */
    // Initialisation
    for (int i = 0; i < 9; i++)
    {
        if (grille[C->l][i] == chiffre)
            return true;
    }
    return false;
}

/*******************************************************/
/* Objectif : vérifie la présence d'un chiffre sur colonne
/*******************************************************/
bool sudoku::presenceColonne(int chiffre, cellule *C)
{
    /*
    Vrai si le chiffre passer en argument est présent dans la ligne passer en argument
    Faux si le chiffre passer en argument est présent dans la ligne passer en argument
    */
    // Initialisation
    for (int i = 0; i < 9; i++)
    {
        if (grille[i][C->c] == chiffre)
            return true;
    }
    return false;
}

/*******************************************************/
/* Objectif : vérifie la présence d'un chiffre sur Block
/*******************************************************/
bool sudoku::presenceBlock(int chiffre, cellule *C)
{
    /*
    Vrai si le chiffre passer en argument est présent dans la ligne passer en argument
    Faux si le chiffre passer en argument est présent dans la ligne passer en argument
    */
    // Initialisation
    int ligneMin, ligneMax, colonneMin, colonneMax;
    // Affectation
    if (C->b == 1)
    {
        ligneMin = 0;
        ligneMax = 3;
        colonneMin = 0;
        colonneMax = 3;
    }
    if (C->b == 2)
    {
        ligneMin = 0;
        ligneMax = 3;
        colonneMin = 3;
        colonneMax = 6;
    }
    if (C->b == 3)
    {
        ligneMin = 0;
        ligneMax = 3;
        colonneMin = 6;
        colonneMax = 9;
    }
    //-----
    if (C->b == 4)
    {
        ligneMin = 3;
        ligneMax = 6;
        colonneMin = 0;
        colonneMax = 3;
    }
    if (C->b == 5)
    {
        ligneMin = 3;
        ligneMax = 6;
        colonneMin = 3;
        colonneMax = 6;
    }
    if (C->b == 6)
    {
        ligneMin = 3;
        ligneMax = 6;
        colonneMin = 6;
        colonneMax = 9;
    }
    //-----
    if (C->b == 7)
    {
        ligneMin = 6;
        ligneMax = 9;
        colonneMin = 0;
        colonneMax = 3;
    }
    if (C->b == 8)
    {
        ligneMin = 6;
        ligneMax = 9;
        colonneMin = 3;
        colonneMax = 6;
    }
    if (C->b == 9)
    {
        ligneMin = 6;
        ligneMax = 9;
        colonneMin = 6;
        colonneMax = 9;
    }

    // lecture du block dans la grille
    for (int ligne = ligneMin; ligne < ligneMax; ligne++)
    {

        for (int colonne = colonneMin; colonne < colonneMax; colonne++)
        {
            if (grille[ligne][colonne] == chiffre)
                return true;
        }
    }

    return false;
}
/****************************************/
/* Objectif : backtracking
/****************************************/
bool sudoku::BacktrackingSudoku(int k)
{
    // Cas d'arrêt
    if (k == (r + 1))
    {
        return (true);
    }
    else
    {
        for (int nombre = 1; nombre < 10; nombre++)
        {
            if ((presenceLigne(nombre, C[k]) == false) && (presenceColonne(nombre, C[k]) == false) && (presenceBlock(nombre, C[k]) == false))
            {
                // cout << "N°" << nombre << endl;
                grille[C[k]->l][C[k]->c] = nombre;
                if (BacktrackingSudoku(k + 1) == true)
                {
                    return (true);
                }
                grille[C[k]->l][C[k]->c] = 0;
            }
        }
    }

    return (false);
}

/****************************************/
/* Objectif : Affichage de la grille sudoku
/****************************************/
void sudoku::affichage()
{
    cout << setw(3) << "-"
         << "------------------------------------" << endl;
    for (int i = 0; i < 9; i++)
    {
        if ((i == 3) || (i == 6))
            cout << setw(3) << "-"
                 << "------------------------------------" << endl;
        cout << setw(3) << "|";
        for (int j = 0; j < 8; j++)
        {
            if ((j == 3) || (j == 6))
                cout << setw(3) << "|" << setw(3) << grille[i][j];
            else
                cout << setw(3) << grille[i][j];
        }
        cout << setw(3) << grille[i][8] << setw(3) << "|" << endl;
    }
    cout << setw(3) << "-"
         << "------------------------------------" << endl;
}

/****************************************/
/* Objectif : Détermination d'une solution de la grilleées.
La méthode renvoie vrai si une solution a été trouvée, 0 sinon
/****************************************/
bool sudoku::solution()
{
    // Création des cellules vides, on retourne leurs nombres
    cellulesVides();
    // cout << "nbr = " << r << endl;
    // cout << "bizzz" << C[51]->l;
    // Tests
    // cout << presenceLigne(2, C[22]);
    // cout << presenceColonne(1, C[1]);
    // cout << presenceBlock(1, C[50]);
    bool reponse = false;
    reponse = BacktrackingSudoku(1);

    return (reponse);
}
