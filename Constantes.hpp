
#ifndef _CONSTANTES_HPP
#define _CONSTANTES_HPP

#include <string>
#include <utility>

using namespace std;



int const NUMERO_ERREUR_ARGUMENT_INVALIDE = -1;
int const NUMERO_ERREUR_NB_FOIS_INVALIDE = -2;
int const NUMERO_ERREUR_NOMBRE_ARG_INVALIDE = -3;
int const NUMERO_ERREUR_TAILLE_INVALIDE = -4;
int const NUMERO_ERREUR_TROP_DE_VALEUR = -5;

string const ARG_AIDE( "-h" );
string const ARG_TRI_BULLE( "-b" );
string const ARG_TRI_FUSION( "-f" );
string const ARG_TRI_FUSION2( "-F" );
string const ARG_TRI_INSERTION( "-i" );
string const ARG_TRI_RAPIDE( "-q" );
string const ARG_TRI_SELECTION( "-s" );
string const ARG_TESTS( "-t" );

string const MSSG_AIDE( 
  "soit : \n"
  "  " + ARG_TESTS + "  pour lancer les tests.\n"
  "  " + ARG_TRI_INSERTION + " ou " + ARG_TRI_SELECTION + " pour profiler un tri.\n"
  "  #int  indique la taille du tableau a trier.\n"
  "  " + ARG_AIDE + "  pour afficher ce message d'aide." );
string const MSSG_PRESENTATION_ECART_TYPE( "ecart type : " );
string const MSSG_PRESENTATION_INDICES( "indices les plus utilises : " );
string const MSSG_PRESENTATION_MOYENNE( "moyenne : " );
string const MSSG_SEPARATEUR_INDICE( ", " );
string const MSSG_SEPARATEUR_ERREUR( " : " );


string const MSSG_ERREUR_ARGUMENT_INVALIDE( "argument invalide" );
string const MSSG_ERREUR_NB_FOIS_INVALIDE( "nombre de répétition invalide" );
string const MSSG_ERREUR_NOMBRE_ARG_INVALIDE( "nombre d'argument invalide, il ne doit y avoir qu'un seul argument avec le tiret '-'" );
string const MSSG_ERREUR_TAILLE_INVALIDE( "taille invalide" );
string const MSSG_ERREUR_TROP_DE_VALEUR( "trop de valeur numérique" );




int const NOMBRES_TRI = 6;

const pair< string, FonctionTri > TRI[NOMBRES_TRI] =
    {
	    { ARG_TRI_BULLE, triBulle },
	    { ARG_TRI_FUSION, triFusion },
	    { ARG_TRI_FUSION2, triFusion2 },
        { ARG_TRI_INSERTION, triInsertion },
		{ ARG_TRI_RAPIDE, triRapide },
        { ARG_TRI_SELECTION, triSelection }
    };


#endif
