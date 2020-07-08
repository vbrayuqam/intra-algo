

#ifndef _MINILIST_HPP_
#define _MINILIST_HPP_


#include <cassert>
#include <exception>

template< typename T >
class MiniList
{
    class Maillon
    {
    public:
        T element;
        Maillon * suivant;

        Maillon( T a_element, Maillon * a_suivant = nullptr );
        virtual ~Maillon( void );
    };

    int _taille;
    Maillon * _premier;
    Maillon * _dernier;

public:
    MiniList( void );
    virtual ~MiniList( void );

    int taille( void );
    bool estVide( void );

    T & operator[]( int a_position );
    void inserer( T a_element );

    void transferer( MiniList< T > & a_miniList );
};


class IndexeHorsBornes : public exception
{
    virtual const char *
    what( void )
    const throw()
    {
        return "L'indexe est hors bornes.";
    }
};


template< typename T >
MiniList< T >::Maillon::Maillon( T a_element, Maillon * a_suivant )
: element( a_element ),
  suivant( a_suivant )
{}

template< typename T >
MiniList< T >::Maillon::~Maillon( void )
{
    if( nullptr != suivant )
    {
        delete suivant;
        suivant = nullptr;
    }
}



template< typename T >
MiniList< T >::MiniList( void )
: _taille( 0 ),
  _premier( nullptr ),
  _dernier( nullptr )
{}

template< typename T >
MiniList< T >::~MiniList( void )
{
    if( nullptr != _premier )
    {
        delete _premier;
        _premier = nullptr;
        _dernier = nullptr;
    }

}

template< typename T >
int
MiniList< T >::taille( void )
{
    return _taille;
}

template< typename T >
bool
MiniList< T >::estVide( void )
{
    return 0 == _taille;
}

template< typename T >
T &
MiniList< T >::operator[]( int a_position )
{
    if( a_position < 0 || _taille <= a_position )
    {
        throw IndexeHorsBornes();
    }

    Maillon * courant = _premier;
    while( 0 < a_position )
    {
        assert( nullptr != courant );
        courant = courant->suivant;
        -- a_position;
    }

    assert( nullptr != courant );
    return courant->element;
}

template< typename T >
void
MiniList< T >::inserer( T a_element )
{
    Maillon * courant = new Maillon( a_element );
    if( 0 == _taille )
    {
        assert( nullptr == _premier );
        _premier = courant;
    }
    else
    {
        assert( nullptr != _dernier );
        _dernier->suivant = courant;
    }

    _dernier = courant;

    ++ _taille;
}


/**
 * Placez vos explications ici :
 * 
 * Nous commencons par verifier si l'objet lui meme contient des elements. A la suite de quoi
 * nous verifions si l'objet donner en argument en contient. 
 * 
 * Si l'objet initial et l'objet en argument en contienne, le dernier maillon de l'objet initial pointe
 * vers le premier maillon de l'objet passe en argument. Ensuite la variable _dernier de l'objet recoit le pointeur 
 * vers le dernier maillon de l'objet passe en argument. Ainsi, les 2 listes sont jointes. A la suite de quoi, on additionne
 * leurs tailles pour assigner la taille totale a l'objet initial. Ensuite, on asssigne des nullptr au variables _premier et 
 * _dernier de l'objet passe en arguement ainsi qu'une taille de 0.
 *
 * Si l'objet initial est vide et l'objet en argument contient des elements, les pointeurs _premier et _dernier de l'objet initial
 * recoivent les pointeurs des maillons _premier et _dernier de la liste passe en argument. Ensuite il recoit la taille de la liste. Ainsi ajoutant 
 * la liste a son contenu (rien). Ensuite, on asssigne des nullptr au variables _premier et _dernier de l'objet passe en arguement ainsi qu'une taille de 0.
 *
 * Dans tout autres cas, rien n'est fait.
 */
template< typename T >
void
MiniList< T >::transferer( MiniList< T > & a_miniList )
{
  if (this->_taille != 0) {
    if (a_miniList.taille() != 0) {
      this->_dernier->suivant = a_miniList._premier;
      this->_dernier = a_miniList._dernier;
      this->_taille += a_miniList._taille;
      a_miniList._premier = nullptr;
      a_miniList._dernier = nullptr;
      a_miniList._taille = 0;
    } 
  } else {
    if (a_miniList.taille() != 0) {
      this->_premier = a_miniList._premier;
      this->_dernier = a_miniList._dernier;
      this->_taille = a_miniList._taille;
      a_miniList._premier = nullptr;
      a_miniList._dernier = nullptr;
      a_miniList._taille = 0;
    }
  }
}


#endif
