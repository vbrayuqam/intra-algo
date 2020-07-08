




#include <cassert>
#include <cmath>

#include "ProfileTableau.hpp"
ProfileTableau::ProfileTableau( int a_nbrElement )
: _contenue( new int[ a_nbrElement ] ),
  _nbrAcces( new double[ a_nbrElement ] ),
  _estValideNbrAccesMoyen( false ),
  _taille( a_nbrElement )
{
	assert( 0 < a_nbrElement );

	int i = 0;

    for( i = 0; i < a_nbrElement; ++ i )
    {
        _nbrAcces[ i ] = 0.0;
    }

//    initCompteurEchec();
}


ProfileTableau::~ProfileTableau( void )
{
    delete [] _contenue;
    _contenue = nullptr;
    delete [] _nbrAcces;
    _nbrAcces = nullptr;
}


int & 
ProfileTableau::operator []( int a_position ) 
{
	assert( 0 <= a_position );
	assert( a_position < _taille );
	
    _estValideNbrAccesMoyen = false;
    ++ _nbrAcces[ a_position ];


    return _contenue[ a_position ];
}
    

int 
ProfileTableau::taille( void ) const
{
    return _taille;
}


double 
ProfileTableau::nbrAcces( int a_position ) const
{
	assert( 0 <= a_position );
	assert( a_position < _taille );
	
    return _nbrAcces[ a_position ];
}

double 
ProfileTableau::nbrAcces( void ) const
{
    int i = 0;
    double somme = 0.0;
    
    for( i = 0; i < _taille; ++i ) 
    {
        somme += _nbrAcces[ i ];
    }
	
    return somme;
}



double 
ProfileTableau::nbrAccesMoyen( void )
{
	if( ! _estValideNbrAccesMoyen )
	{
	    int i = 0;
		double somme = 0.0;
		
		for( i = 0; i < _taille; ++i ) 
		{
			somme += _nbrAcces[ i ];
		}
		
		_nbrAccesMoyen = somme / _taille;
		_estValideNbrAccesMoyen = true;
		_estValideEcartType = false;
	}
	
	return _nbrAccesMoyen;
}


double 
ProfileTableau::ecartType( void )
{
    double moyenne = nbrAccesMoyen();
	
	if( ! _estValideEcartType )
	{
		int i = 0;
		double somme = 0.0;
		
		for( i = 0; i < _taille; ++ i )
		{
		    double ecart = _nbrAcces[ i ] - moyenne;
			somme += ( ecart * ecart );
		}
		
		_ecartType = sqrt( somme / _taille );
		_estValideEcartType = true;
	}
	
	return _ecartType;
}


int * 
ProfileTableau::indicesPlusUtilises( void )
{
    // placez votre code ici.
	int nbr = 0;
	int i = 0;
	double limite = nbrAccesMoyen() + ecartType();
	
	for( i = 0; i < _taille; ++ i ) 
	{
	    if( limite <= _nbrAcces[ i ] )
			++ nbr;
	}
	
	int * resultat = new int[ nbr + 1 ];
	int j = 0;
	for( i = 0; i < _taille; ++ i ) 
	{
	    if( limite <= _nbrAcces[ i ] )
		{
			resultat[ j ] = i;
			++ j;
		}
	}
	resultat[ j ] = -1;
	
	return resultat;
}

bool
ProfileTableau::estTrie( void )
{
    int i = 0;
    bool resultat = true;

    for( i = 0; i < _taille - 1; ++ i )
    {
        resultat = resultat && ( _contenue[i] <= _contenue[i + 1] );
    }

    return resultat;
}
