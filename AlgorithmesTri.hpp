
#ifndef _ALGORITHMES_TRI_HPP
#define _ALGORITHMES_TRI_HPP

#include <deque>

using namespace std;

#include "ProfileTableau.hpp"

typedef int (* FonctionTri )( ProfileTableau & );

int triSelection( ProfileTableau & tab );

int triInsertion( ProfileTableau & tab );

int triBulle( ProfileTableau & tab );

int triRapide( ProfileTableau & tab );

int triFusion( ProfileTableau & tab );



/**
 * Cette fonction trouve les suites non decroissante de valeurs dans
 * le tableau.
 *
 * par exemple, si nous avons le tableau suivant :
 * valeurs : [ 4, 6, 6, 8, 2, 1, 5, 8, 6 ]
 * indices :   0  1  2  3  4  5  6  7  8
 * Il y a 4 suite de valeurs non decroissante :
 *   [ 4, 6, 6, 8 ][ 2 ][ 1, 5, 8 ][ 6 ]
 * L'indice des dernieres valeurs de chaque sous-suite sont :
 *   [ 3, 4, 7, 8 ]
 * Donc, le deque en parametre va recevoir ces quatres valeurs, dans l'ordre.
 *
 * @param [in,out] ProfileTableau & tab, est le tableau a analyser.
 *  @pre nullptr != tab
 *
 * @param [in,out] deque< int > * fins, va contenir les indices des fins des intervalles
 *       non decroissante du tableau.
 *  @pre nullptr != fins
 *  @pre deque->empty()
 *
 * @return le nombre de comparaison qu'il y a eu entre les valeurs du tableaux.
 */
int suiteNonDecroissante( ProfileTableau & tab, deque< int > * fins );



/**
 * version modifié d'un tri-fusion.
 *
 * Utilise les fonctions 'suiteNonDecroissante' et 'fusion' afin de faire le tri
 * des éléments d'un tableau.
 *
 * @param [in,ou] ProfileTableau & tab, contient les valeurs a trier.
 *  @pre nullptr != tab
 *
 * @return le nombre de comparaison qu'il y a eu entre les valeurs du tableaux.
 */
int triFusion2( ProfileTableau & tab );


#endif
