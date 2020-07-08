
#include <iostream>

#include "AlgorithmesTri.hpp"

using namespace std;

int
triSelection( ProfileTableau & tab )
{
    int nbComparaison = 0;
    int i = 0;
    int j = 0;
    
    for( i = 0; i < tab.taille() - 1; ++ i )
    {
        int position = i;
        int minima = tab[i];
        
        for( j = i + 1; j < tab.taille(); ++ j ) 
        {
            ++ nbComparaison;
            if( tab[j] < minima )
            {
                position = j;
                minima = tab[j];
            }
        }
        
        tab[position] = tab[i];
        tab[i] = minima;
    }        
    return nbComparaison;
}


int
triInsertion( ProfileTableau & tab )
{
    int nbComparaison = 0;
    int i = 0;
    int j = 0;
    
    for( i = 1; i < tab.taille(); ++ i )
    {
        j = i - 1;
        int temp = tab[i];
        
        ++ nbComparaison;
        while( 0 <= j && temp < tab[j] ) 
        {
            tab[j+1] = tab[j];
            -- j;
            ++ nbComparaison;
        }
        tab[j+1] = temp;
    }
    return nbComparaison;
}


int 
triBulle( ProfileTableau & tab )
{
    int nbComparaison = 0;
	bool estTrie = false;
	int fin = tab.taille();

	while( ! estTrie ) {
		estTrie = true;
		for( int i = 0; i < fin; ++ i ) {
            ++ nbComparaison;
			if( tab[i + 1] < tab[i] ) {
				int temp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = temp;
				estTrie = false;
			}
		}
		-- fin;
	}
    return nbComparaison;
}


int 
triRapide( ProfileTableau & tab, int debut, int fin )
{
    int nbComparaison = 0;
	if( debut < fin ) {
		int pivot = tab[ ( debut + fin ) / 2 ];
		int i = debut - 1;
		int j = fin + 1;
		
		while( i < j ) {
			do{ -- j; ++ nbComparaison; }while( pivot < tab[j] );
			do{ ++ i; ++ nbComparaison; }while( tab[i] < pivot );
			
			if( i < j ) {
				int temp = tab[i];
				tab[i] = tab[j];
				tab[j] = temp;
			}
		}
		
		nbComparaison += triRapide( tab, debut, j );
		nbComparaison += triRapide( tab, j + 1, fin );
	}
    return nbComparaison;
}


int 
triRapide( ProfileTableau & tab )
{
	int nbComparaison = triRapide( tab, 0, tab.taille() - 1 );
    return nbComparaison;
}

int fusion( ProfileTableau & tab, int debut1, int fin1, int fin2 )
{
	int nbComparaison = 0;
	int i = debut1;
	int j = fin1 + 1;
	int k = 0;
	ProfileTableau temp( fin2 - debut1 + 1 );
	
	while( i <= fin1 && j <= fin2 )
	{
		++ nbComparaison;
		if( tab[ i ] < tab[ j ] )
		{
			temp[ k ] = tab[ i ];
			temp[ k ] = tab[ i ];
			++ i;
		}	
		else
		{
			temp[ k ] = tab[ j ];
			temp[ k ] = tab[ j ];
			++ j;
		}
		++ k;
	}
	
	while( i <= fin1 )
	{
		temp[ k ] = tab[ i ];
		temp[ k ] = tab[ i ];
		++ i;
		++ k;
	}
	
	while( j <= fin2 )
	{
		temp[ k ] = tab[ j ];
		temp[ k ] = tab[ j ];
		++ j;
		++ k;
	}
	
	for( k = debut1; k <= fin2; ++ k )
	{
		tab[ k ] = temp[ k - debut1 ];
		tab[ k ] = temp[ k - debut1 ];
	}
	
	return nbComparaison;
}

int 
triFusion( ProfileTableau & tab, int debut, int fin )
{
	int nbComparaison = 0;
	
    if( debut < fin )
	{
		int milieu = ( debut + fin ) / 2;
		nbComparaison += triFusion( tab, debut, milieu );
		nbComparaison += triFusion( tab, milieu + 1, fin );
		
		nbComparaison += fusion( tab, debut, milieu, fin );
	}
	
	return nbComparaison;
}

int 
triFusion( ProfileTableau & tab )
{
	int nbComparaison = triFusion( tab, 0, tab.taille() - 1 );
    return nbComparaison;
}


/**
   complexite temporelle de votre fonction :

   La complexite temporelle de ma fonction dans le pire cas est O(n).
   Tout les elements sont compares un a un a l'interieur d'une boucle FOR. Les
   autres operations n'affecte pas reellement la complexite temporelle de
   la fonction car emsemble ils ne representent qu'une constante additioner ou multiplier.
*/
int
suiteNonDecroissante( ProfileTableau & tab, deque< int > * fins )
{
	
  int nbComparaison = 0;

  if (tab.taille() == 1) {
    fins->push_back(0);
  } else {
    for (int i = 0; i < tab.taille(); i++) {
        nbComparaison++;
    	if (i + 1 == tab.taille()) {
	  fins->push_back(i);
	} else if (tab[i] > tab[i+1]) {
	  fins->push_back(i);
	}
    } 
  }
 

  return nbComparaison;
}


/**
   analyse des statistiques ici :
        vb@vbdt:~/Desktop/intra$ ./pTri -q 1000 10
        nbElement, nbComp, nbAcces, total
        1000, 13631, 25322, 38953
        2000, 30851, 56090, 86941
        3000, 50717, 90196, 140913
        4000, 67198, 121257, 188455
        5000, 90454, 159153, 249607
        6000, 110599, 194514, 305113
        7000, 133747, 232750, 366497
        8000, 148770, 263585, 412355
        9000, 167122, 298809, 465931
        10000, 199756, 344879, 544635

        vb@vbdt:~/Desktop/intra$ ./pTri -f 1000 10
        nbElement, nbComp, nbAcces, total
        1000, 8700, 58304, 67004
        2000, 19407, 128622, 148029
        3000, 30883, 204382, 235265
        4000, 42856, 281328, 324184
        5000, 55240, 362712, 417952
        6000, 67800, 444832, 512632
        7000, 80705, 527642, 608347
        8000, 93625, 610482, 704107
        9000, 106985, 697434, 804419
        10000, 120483, 785430, 905913

        vb@vbdt:~/Desktop/intra$ ./pTri -F 1000 10
        nbElement, nbComp, nbAcces, total
        1000, 9235, 55324, 64559
        2000, 22277, 134252, 156529
        3000, 32660, 196250, 228910
        4000, 44955, 269732, 314687
        5000, 59250, 355906, 415156
        6000, 71484, 429018, 500502
        7000, 84751, 508604, 593355
        8000, 97725, 586876, 684601
        9000, 116379, 698788, 815167

	Comparaisons:
	Le tri fusion fait moins de comparaisons que le tri rapide, car il divise le tableau en plus petit tableaux.
	Mon tri fusion2 en fait un peu plus que le tri fusion avec moins d'elements mais semble legerement plus efficace avec beaucoup d'elements.

	Acces:
	Le tri fusion fait plus d'acces que le tri rapide, surement a cause qu'il divise les tableaux avec des appels recursifs.
	Mon tri fusion2 fait un peu moins d'acces que le tri fusion traditionel avec beaucoup d'elements et parfois moins avec moins d'elements.
	L'organisation initiale du tableau doit y jouer beaucoup.

	Total:	
	Mon tri fusion2 obtient des totaux similaires a ceux du tri fusion mais semble etre un peu plus efficaces avec beaucoup d'elements.
	Le tri rapide reste le meilleur en terme de total.
 */
int
triFusion2( ProfileTableau & tab )
{
  int nbComparaison = 0;
  deque<int> * index = new deque<int>();
  nbComparaison = suiteNonDecroissante(tab, index);
 
  while (index->size() > 1) {
    int indexInit = index->size();
    int valInit = 0;
    
    for (int i = 0; i < index->size(); i++) {
      if (indexInit % 2 == 0 || (i != index->size() - 1)){
        nbComparaison += fusion(tab, valInit, index->at(i), index->at(i + 1));
        index->erase(index->begin() + i);
        valInit = index->at(i) + 1;
      }
    }

    for (int i = 0; i < tab.taille(); i++) {
    }
  }

  delete index;
  return nbComparaison;
}
