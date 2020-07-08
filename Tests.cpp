
#include <deque>
#include <iostream>

#include "AlgorithmesTri.hpp"
#include "MiniList.hpp"
#include "ProfileTableau.hpp"
#include "Tests.hpp"

using namespace std;

template< typename T >
double similarite( int * attendu, int n, MiniList< T > & obtenu )
{
    double nbrReussi = 0.0;
    int i = 0;

    if( 0 == n )
    {
        nbrReussi = obtenu.estVide() ? 1.0 : 0.0;
    }
    else
    {
        for( i = 0 ; i < n; ++ i )
        {
            try
            {
                if( attendu[i] == obtenu[i] )
                {
                    nbrReussi += 1.0;
                }
                else
                {
                    cerr << "    attendu : " << attendu[i] << " obtenu : " << obtenu[i] << endl;
                }
            }
            catch( exception & e )
            {
                cerr << "    attendu : " << attendu[i] << " obtenu une exception car il n'y a plus d'élément dans le tableau." << endl;
            }
        }
        nbrReussi = nbrReussi / n;
    }

    return nbrReussi;
}



double similarite( int * attendu, int n, deque< int > & obtenu )
{
    double nbrReussi = 0.0;
    int i = 0;

    for( i = 0 ; i < n; ++ i )
    {
        if( obtenu.empty() )
        {
            cerr << "    il manque une valeur." << endl;
        }
        else
        {
            if( attendu[i] == obtenu.front() )
            {
                nbrReussi += 1.0;
            }
            else
            {
                cerr << "    attendu : " << attendu[i] << " obtenu : " << obtenu.front() << endl;
            }
            obtenu.pop_front();
        }
    }

    return nbrReussi / n;
}



double similarite( int * attendu, int n, ProfileTableau & obtenu )
{
    double nbrReussi = 0.0;
    int i = 0;

    for( i = 0 ; i < n; ++ i )
    {
        if( attendu[i] == obtenu[i] )
        {
            nbrReussi += 1.0;
        }
        else
        {
            cerr << "    attendu : " << attendu[i] << " obtenu : " << obtenu[i] << endl;
        }
    }

    return nbrReussi / n;
}

/******************************************************************************/
/** tests AlgorithmesTri::suiteNonDecroissante ********************************/


double testSuiteNonDecroissante1( double ponderation ) {
    cerr << "test suiteNonDecroissante 1 : " << endl;
    int NOMBRE_VALEUR_ATTENDU = 1;
    int attendu[NOMBRE_VALEUR_ATTENDU] = {0};

    ProfileTableau tab(1);
    tab[0] = 1;

    deque< int > * obtenu = new deque< int >();

    suiteNonDecroissante( tab, obtenu );

    return ponderation * similarite( attendu, NOMBRE_VALEUR_ATTENDU, *obtenu );
}


double testSuiteNonDecroissante2( double ponderation ) {
    cerr << "test suiteNonDecroissante 2 : " << endl;
    int NOMBRE_VALEUR_ATTENDU = 1;
    int attendu[NOMBRE_VALEUR_ATTENDU] = {2};

    ProfileTableau tab(3);
    tab[0] = 2;
    tab[1] = 4;
    tab[2] = 7;

    deque< int > * obtenu = new deque< int >();

    suiteNonDecroissante( tab, obtenu );

    return ponderation * similarite( attendu, NOMBRE_VALEUR_ATTENDU, *obtenu );
}

double testSuiteNonDecroissante3( double ponderation ) {
    cerr << "test suiteNonDecroissante 3 : " << endl;
    int NOMBRE_VALEUR_ATTENDU = 2;
    int attendu[NOMBRE_VALEUR_ATTENDU] = {2, 4};

    ProfileTableau tab(5);
    tab[0] = 2;
    tab[1] = 4;
    tab[2] = 7;
    tab[3] = 3;
    tab[4] = 6;

    deque< int > * obtenu = new deque< int >();

    suiteNonDecroissante( tab, obtenu );

    return ponderation * similarite( attendu, NOMBRE_VALEUR_ATTENDU, *obtenu );
}

double testSuiteNonDecroissante4( double ponderation ) {
    cerr << "test suiteNonDecroissante 4 : " << endl;
    int NOMBRE_VALEUR_ATTENDU = 1;
    int attendu[NOMBRE_VALEUR_ATTENDU] = {3};

    ProfileTableau tab(4);
    tab[0] = 2;
    tab[1] = 4;
    tab[2] = 4;
    tab[3] = 7;

    deque< int > * obtenu = new deque< int >();

    suiteNonDecroissante( tab, obtenu );

    return ponderation * similarite( attendu, NOMBRE_VALEUR_ATTENDU, *obtenu );
}

double testSuiteNonDecroissante5( double ponderation ) {
    cerr << "test suiteNonDecroissante 5 : " << endl;
    int NOMBRE_VALEUR_ATTENDU = 2;
    int attendu[NOMBRE_VALEUR_ATTENDU] = {0, 3};

    ProfileTableau tab(4);
    tab[0] = 7;
    tab[1] = 2;
    tab[2] = 3;
    tab[3] = 5;

    deque< int > * obtenu = new deque< int >();

    suiteNonDecroissante( tab, obtenu );

    return ponderation * similarite( attendu, NOMBRE_VALEUR_ATTENDU, *obtenu );
}

double testSuiteNonDecroissante6( double ponderation ) {
    cerr << "test suiteNonDecroissante 6 : " << endl;
    int NOMBRE_VALEUR_ATTENDU = 2;
    int attendu[NOMBRE_VALEUR_ATTENDU] = {2, 3};

    ProfileTableau tab(4);
    tab[0] = 2;
    tab[1] = 3;
    tab[2] = 5;
    tab[3] = -1;

    deque< int > * obtenu = new deque< int >();

    suiteNonDecroissante( tab, obtenu );

    return ponderation * similarite( attendu, NOMBRE_VALEUR_ATTENDU, *obtenu );
}

double testSuiteNonDecroissante( void )
{
    cout << endl <<  "--------------------" << endl << "SuiteNonDecroissante" << endl;
    double points =
            testSuiteNonDecroissante1( 0.5 ) +
            testSuiteNonDecroissante2( 0.5 ) +
            testSuiteNonDecroissante3( 0.5 ) +
            testSuiteNonDecroissante4( 0.5 ) +
            testSuiteNonDecroissante5( 0.5 ) +
            testSuiteNonDecroissante6( 0.5 );


    cout << endl << "Points suiteNonDecroissante : " << points << " / 3.0" << endl;

    return points;
}

/******************************************************************************/
/** tests AlgorithmesTri::TriFusion2 ******************************************/


double testTriFusion2_1( double ponderation ) {
    cerr << "test TriFusion2 1 : " << endl;
    int NOMBRE_VALEUR_ATTENDU = 1;
    int attendu[NOMBRE_VALEUR_ATTENDU] = {2};

    ProfileTableau tab(1);
    tab[0] = 2;

    triFusion2( tab );

    return ponderation * similarite( attendu, NOMBRE_VALEUR_ATTENDU, tab );
}

double testTriFusion2_2( double ponderation ) {
    cerr << "test TriFusion2 2 : " << endl;
    int NOMBRE_VALEUR_ATTENDU = 2;
    int attendu[NOMBRE_VALEUR_ATTENDU] = {2, 3};

    ProfileTableau tab(2);
    tab[0] = 2;
    tab[1] = 3;

    triFusion2( tab );

    return ponderation * similarite( attendu, NOMBRE_VALEUR_ATTENDU, tab );
}


double testTriFusion2_3( double ponderation ) {
    cerr << "test TriFusion2 3 : " << endl;
    int NOMBRE_VALEUR_ATTENDU = 2;
    int attendu[NOMBRE_VALEUR_ATTENDU] = {2, 3};

    ProfileTableau tab(2);
    tab[0] = 3;
    tab[1] = 2;

    triFusion2( tab );

    return ponderation * similarite( attendu, NOMBRE_VALEUR_ATTENDU, tab );
}

double testTriFusion2_4( double ponderation ) {
    cerr << "test TriFusion2 4 : " << endl;
    int NOMBRE_VALEUR_ATTENDU = 7;
    int attendu[NOMBRE_VALEUR_ATTENDU] = {1, 2, 3, 4, 5, 6, 7};

    ProfileTableau tab(7);
    tab[0] = 6;
    tab[1] = 7;
    tab[2] = 4;
    tab[3] = 5;
    tab[4] = 1;
    tab[5] = 2;
    tab[6] = 3;

    triFusion2( tab );

    return ponderation * similarite( attendu, NOMBRE_VALEUR_ATTENDU, tab );
}

double testTriFusion2_5( double ponderation ) {
    cerr << "test TriFusion2 5 : " << endl;
    int NOMBRE_VALEUR_ATTENDU = 12;
    int attendu[NOMBRE_VALEUR_ATTENDU] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };

    ProfileTableau tab(12);
    tab[0] = 11;
    tab[1] = 12;
    tab[2] = 8;
    tab[3] = 9;
    tab[4] = 10;
    tab[5] = 6;
    tab[6] = 7;
    tab[7] = 4;
    tab[8] = 5;
    tab[9] = 1;
    tab[10] = 2;
    tab[11] = 3;

    triFusion2( tab );

    return ponderation * similarite( attendu, NOMBRE_VALEUR_ATTENDU, tab );
}

double testTriFusion2_6( double ponderation ) {
    cerr << "test TriFusion2 6 : " << endl;
    int NOMBRE_VALEUR_ATTENDU = 5;
    int attendu[NOMBRE_VALEUR_ATTENDU] = {-4, -2, 0, 5, 8};

    ProfileTableau tab(5);
    tab[0] = 8;
    tab[1] = 5;
    tab[2] = 0;
    tab[3] = -2;
    tab[4] = -4;

    triFusion2( tab );

    return ponderation * similarite( attendu, NOMBRE_VALEUR_ATTENDU, tab );
}

double testTriFusion2( void )
{
    cout << endl <<  "--------------------" << endl << "TriFusion2" << endl;
    double points =
            testTriFusion2_1( 0.5 ) +
            testTriFusion2_2( 0.5 ) +
            testTriFusion2_3( 0.5 ) +
            testTriFusion2_4( 0.5 ) +
            testTriFusion2_5( 0.5 ) +
            testTriFusion2_6( 0.5 );


    cout << "Points triFusion2 : " << points << " / 3.0" << endl;

    return points;

}

/******************************************************************************/
/** tests MiniList::transferer ************************************************/

double testTransferer_1a( double ponderation ) {
    cerr << "test transferer 1a : " << endl;
    double points = 0.0;
    int NOMBRE_VALEUR_ATTENDU1 = 0;
    int attendu1[NOMBRE_VALEUR_ATTENDU1] = {};
    int NOMBRE_VALEUR_ATTENDU2 = 0;
    int attendu2[NOMBRE_VALEUR_ATTENDU2] = {};

    MiniList< int > m1;
    MiniList< int > m2;

    m1.transferer( m2 );

    points += similarite( attendu1, NOMBRE_VALEUR_ATTENDU1, m1 );
    points += similarite( attendu2, NOMBRE_VALEUR_ATTENDU2, m2 );

    return ponderation * ( points / 2.0 );
}

double testTransferer_1b( double ponderation ) {
    cerr << "test transferer 1b : " << endl;
    double points = 0.0;
    int NOMBRE_VALEUR_ATTENDU1 = 1;
    int attendu1[NOMBRE_VALEUR_ATTENDU1] = {2};
    int NOMBRE_VALEUR_ATTENDU2 = 0;
    int attendu2[NOMBRE_VALEUR_ATTENDU2] = {};

    MiniList< int > m1;
    MiniList< int > m2;

    m1.transferer( m2 );

    m1.inserer( 2 );

    points += similarite( attendu1, NOMBRE_VALEUR_ATTENDU1, m1 );
    points += similarite( attendu2, NOMBRE_VALEUR_ATTENDU2, m2 );

    return ponderation * ( points / 2.0 );
}

double testTransferer_1c( double ponderation ) {
    cerr << "test transferer 1c : " << endl;
    double points = 0.0;
    int NOMBRE_VALEUR_ATTENDU1 = 0;
    int attendu1[NOMBRE_VALEUR_ATTENDU1] = {};
    int NOMBRE_VALEUR_ATTENDU2 = 1;
    int attendu2[NOMBRE_VALEUR_ATTENDU2] = {2};

    MiniList< int > m1;
    MiniList< int > m2;

    m1.transferer( m2 );

    m2.inserer( 2 );

    points += similarite( attendu1, NOMBRE_VALEUR_ATTENDU1, m1 );
    points += similarite( attendu2, NOMBRE_VALEUR_ATTENDU2, m2 );

    return ponderation * ( points / 2.0 );
}




double testTransferer_2a( double ponderation ) {
    cerr << "test transferer 2a : " << endl;
    double points = 0.0;
    int NOMBRE_VALEUR_ATTENDU1 = 1;
    int attendu1[NOMBRE_VALEUR_ATTENDU1] = { 2 };
    int NOMBRE_VALEUR_ATTENDU2 = 0;
    int attendu2[NOMBRE_VALEUR_ATTENDU2] = {};

    MiniList< int > m1;
    MiniList< int > m2;

    m2.inserer( 2 );

    m1.transferer( m2 );

    points += similarite( attendu1, NOMBRE_VALEUR_ATTENDU1, m1 );
    points += similarite( attendu2, NOMBRE_VALEUR_ATTENDU2, m2 );

    return ponderation * ( points / 2.0 );
}

double testTransferer_2b( double ponderation ) {
    cerr << "test transferer 2b : " << endl;
    double points = 0.0;
    int NOMBRE_VALEUR_ATTENDU1 = 2;
    int attendu1[NOMBRE_VALEUR_ATTENDU1] = {1, 2};
    int NOMBRE_VALEUR_ATTENDU2 = 0;
    int attendu2[NOMBRE_VALEUR_ATTENDU2] = {};

    MiniList< int > m1;
    MiniList< int > m2;

    m2.inserer( 1 );

    m1.transferer( m2 );

    m1.inserer( 2 );

    points += similarite( attendu1, NOMBRE_VALEUR_ATTENDU1, m1 );
    points += similarite( attendu2, NOMBRE_VALEUR_ATTENDU2, m2 );

    return ponderation * ( points / 2.0 );
}

double testTransferer_2c( double ponderation ) {
    cerr << "test transferer 2c : " << endl;
    double points = 0.0;
    int NOMBRE_VALEUR_ATTENDU1 = 1;
    int attendu1[NOMBRE_VALEUR_ATTENDU1] = {1};
    int NOMBRE_VALEUR_ATTENDU2 = 1;
    int attendu2[NOMBRE_VALEUR_ATTENDU2] = {2};

    MiniList< int > m1;
    MiniList< int > m2;

    m2.inserer( 1 );

    m1.transferer( m2 );

    m2.inserer( 2 );

    points += similarite( attendu1, NOMBRE_VALEUR_ATTENDU1, m1 );
    points += similarite( attendu2, NOMBRE_VALEUR_ATTENDU2, m2 );

    return ponderation * ( points / 2.0 );
}




double testTransferer_3a( double ponderation ) {
    cerr << "test transferer 3a : " << endl;
    double points = 0.0;
    int NOMBRE_VALEUR_ATTENDU1 = 2;
    int attendu1[NOMBRE_VALEUR_ATTENDU1] = { 2, 3 };
    int NOMBRE_VALEUR_ATTENDU2 = 0;
    int attendu2[NOMBRE_VALEUR_ATTENDU2] = {};

    MiniList< int > m1;
    MiniList< int > m2;

    m2.inserer( 2 );
    m2.inserer( 3 );

    m1.transferer( m2 );

    points += similarite( attendu1, NOMBRE_VALEUR_ATTENDU1, m1 );
    points += similarite( attendu2, NOMBRE_VALEUR_ATTENDU2, m2 );

    return ponderation * ( points / 2.0 );
}

double testTransferer_3b( double ponderation ) {
    cerr << "test transferer 3b : " << endl;
    double points = 0.0;
    int NOMBRE_VALEUR_ATTENDU1 = 3;
    int attendu1[NOMBRE_VALEUR_ATTENDU1] = {1, 2, 3};
    int NOMBRE_VALEUR_ATTENDU2 = 0;
    int attendu2[NOMBRE_VALEUR_ATTENDU2] = {};

    MiniList< int > m1;
    MiniList< int > m2;

    m2.inserer( 1 );
    m2.inserer( 2 );

    m1.transferer( m2 );

    m1.inserer( 3 );

    points += similarite( attendu1, NOMBRE_VALEUR_ATTENDU1, m1 );
    points += similarite( attendu2, NOMBRE_VALEUR_ATTENDU2, m2 );

    return ponderation * ( points / 2.0 );
}

double testTransferer_3c( double ponderation ) {
    cerr << "test transferer 3c : " << endl;
    double points = 0.0;
    int NOMBRE_VALEUR_ATTENDU1 = 2;
    int attendu1[NOMBRE_VALEUR_ATTENDU1] = {1, 2};
    int NOMBRE_VALEUR_ATTENDU2 = 1;
    int attendu2[NOMBRE_VALEUR_ATTENDU2] = {3};

    MiniList< int > m1;
    MiniList< int > m2;

    m2.inserer( 1 );
    m2.inserer( 2 );

    m1.transferer( m2 );

    m2.inserer( 3 );

    points += similarite( attendu1, NOMBRE_VALEUR_ATTENDU1, m1 );
    points += similarite( attendu2, NOMBRE_VALEUR_ATTENDU2, m2 );

    return ponderation * ( points / 2.0 );
}




double testTransferer_4a( double ponderation ) {
    cerr << "test transferer 4a : " << endl;
    double points = 0.0;
    int NOMBRE_VALEUR_ATTENDU1 = 1;
    int attendu1[NOMBRE_VALEUR_ATTENDU1] = { 2 };
    int NOMBRE_VALEUR_ATTENDU2 = 0;
    int attendu2[NOMBRE_VALEUR_ATTENDU2] = {};

    MiniList< int > m1;
    MiniList< int > m2;

    m1.inserer( 2 );

    m1.transferer( m2 );

    points += similarite( attendu1, NOMBRE_VALEUR_ATTENDU1, m1 );
    points += similarite( attendu2, NOMBRE_VALEUR_ATTENDU2, m2 );

    return ponderation * ( points / 2.0 );
}

double testTransferer_4b( double ponderation ) {
    cerr << "test transferer 4b : " << endl;
    double points = 0.0;
    int NOMBRE_VALEUR_ATTENDU1 = 2;
    int attendu1[NOMBRE_VALEUR_ATTENDU1] = {1, 2};
    int NOMBRE_VALEUR_ATTENDU2 = 0;
    int attendu2[NOMBRE_VALEUR_ATTENDU2] = {};

    MiniList< int > m1;
    MiniList< int > m2;

    m1.inserer( 1 );

    m1.transferer( m2 );

    m1.inserer( 2 );

    points += similarite( attendu1, NOMBRE_VALEUR_ATTENDU1, m1 );
    points += similarite( attendu2, NOMBRE_VALEUR_ATTENDU2, m2 );

    return ponderation * ( points / 2.0 );
}

double testTransferer_4c( double ponderation ) {
    cerr << "test transferer 4c : " << endl;
    double points = 0.0;
    int NOMBRE_VALEUR_ATTENDU1 = 1;
    int attendu1[NOMBRE_VALEUR_ATTENDU1] = {1};
    int NOMBRE_VALEUR_ATTENDU2 = 1;
    int attendu2[NOMBRE_VALEUR_ATTENDU2] = {2};

    MiniList< int > m1;
    MiniList< int > m2;

    m1.inserer( 1 );

    m1.transferer( m2 );

    m2.inserer( 2 );

    points += similarite( attendu1, NOMBRE_VALEUR_ATTENDU1, m1 );
    points += similarite( attendu2, NOMBRE_VALEUR_ATTENDU2, m2 );

    return ponderation * ( points / 2.0 );
}




double testTransferer_5a( double ponderation ) {
    cerr << "test transferer 5a : " << endl;
    double points = 0.0;
    int NOMBRE_VALEUR_ATTENDU1 = 2;
    int attendu1[NOMBRE_VALEUR_ATTENDU1] = { 1, 2 };
    int NOMBRE_VALEUR_ATTENDU2 = 0;
    int attendu2[NOMBRE_VALEUR_ATTENDU2] = {};

    MiniList< int > m1;
    MiniList< int > m2;

    m1.inserer( 1 );
    m1.inserer( 2 );

    m1.transferer( m2 );

    points += similarite( attendu1, NOMBRE_VALEUR_ATTENDU1, m1 );
    points += similarite( attendu2, NOMBRE_VALEUR_ATTENDU2, m2 );

    return ponderation * ( points / 2.0 );
}

double testTransferer_5b( double ponderation ) {
    cerr << "test transferer 5b : " << endl;
    double points = 0.0;
    int NOMBRE_VALEUR_ATTENDU1 = 3;
    int attendu1[NOMBRE_VALEUR_ATTENDU1] = {1, 2, 3};
    int NOMBRE_VALEUR_ATTENDU2 = 0;
    int attendu2[NOMBRE_VALEUR_ATTENDU2] = {};

    MiniList< int > m1;
    MiniList< int > m2;

    m1.inserer( 1 );
    m1.inserer( 2 );

    m1.transferer( m2 );

    m1.inserer( 3 );

    points += similarite( attendu1, NOMBRE_VALEUR_ATTENDU1, m1 );
    points += similarite( attendu2, NOMBRE_VALEUR_ATTENDU2, m2 );

    return ponderation * ( points / 2.0 );
}

double testTransferer_5c( double ponderation ) {
    cerr << "test transferer 5c : " << endl;
    double points = 0.0;
    int NOMBRE_VALEUR_ATTENDU1 = 2;
    int attendu1[NOMBRE_VALEUR_ATTENDU1] = {1, 2};
    int NOMBRE_VALEUR_ATTENDU2 = 1;
    int attendu2[NOMBRE_VALEUR_ATTENDU2] = {3};

    MiniList< int > m1;
    MiniList< int > m2;

    m1.inserer( 1 );
    m1.inserer( 2 );

    m1.transferer( m2 );

    m2.inserer( 3 );

    points += similarite( attendu1, NOMBRE_VALEUR_ATTENDU1, m1 );
    points += similarite( attendu2, NOMBRE_VALEUR_ATTENDU2, m2 );

    return ponderation * ( points / 2.0 );
}




double testTransferer_6a( double ponderation ) {
    cerr << "test transferer 6a : " << endl;
    double points = 0.0;
    int NOMBRE_VALEUR_ATTENDU1 = 3;
    int attendu1[NOMBRE_VALEUR_ATTENDU1] = { 1, 2, 3 };
    int NOMBRE_VALEUR_ATTENDU2 = 0;
    int attendu2[NOMBRE_VALEUR_ATTENDU2] = {};

    MiniList< int > m1;
    MiniList< int > m2;

    m1.inserer( 1 );
    m1.inserer( 2 );

    m2.inserer( 3 );

    m1.transferer( m2 );

    points += similarite( attendu1, NOMBRE_VALEUR_ATTENDU1, m1 );
    points += similarite( attendu2, NOMBRE_VALEUR_ATTENDU2, m2 );

    return ponderation * ( points / 2.0 );
}

double testTransferer_6b( double ponderation ) {
    cerr << "test transferer 6b : " << endl;
    double points = 0.0;
    int NOMBRE_VALEUR_ATTENDU1 = 4;
    int attendu1[NOMBRE_VALEUR_ATTENDU1] = {1, 2, 3, 4};
    int NOMBRE_VALEUR_ATTENDU2 = 0;
    int attendu2[NOMBRE_VALEUR_ATTENDU2] = {};

    MiniList< int > m1;
    MiniList< int > m2;

    m1.inserer( 1 );
    m1.inserer( 2 );

    m2.inserer( 3 );

    m1.transferer( m2 );

    m1.inserer( 4 );

    points += similarite( attendu1, NOMBRE_VALEUR_ATTENDU1, m1 );
    points += similarite( attendu2, NOMBRE_VALEUR_ATTENDU2, m2 );

    return ponderation * ( points / 2.0 );
}

double testTransferer_6c( double ponderation ) {
    cerr << "test transferer 6c : " << endl;
    double points = 0.0;
    int NOMBRE_VALEUR_ATTENDU1 = 3;
    int attendu1[NOMBRE_VALEUR_ATTENDU1] = {1, 2, 3};
    int NOMBRE_VALEUR_ATTENDU2 = 1;
    int attendu2[NOMBRE_VALEUR_ATTENDU2] = {4};

    MiniList< int > m1;
    MiniList< int > m2;

    m1.inserer( 1 );
    m1.inserer( 2 );

    m2.inserer( 3 );

    m1.transferer( m2 );

    m2.inserer( 4 );

    points += similarite( attendu1, NOMBRE_VALEUR_ATTENDU1, m1 );
    points += similarite( attendu2, NOMBRE_VALEUR_ATTENDU2, m2 );

    return ponderation * ( points / 2.0 );
}




double testTransferer_7a( double ponderation ) {
    cerr << "test transferer 7a : " << endl;
    double points = 0.0;
    int NOMBRE_VALEUR_ATTENDU1 = 3;
    int attendu1[NOMBRE_VALEUR_ATTENDU1] = { 1, 2, 3 };
    int NOMBRE_VALEUR_ATTENDU2 = 0;
    int attendu2[NOMBRE_VALEUR_ATTENDU2] = {};

    MiniList< int > m1;
    MiniList< int > m2;

    m1.inserer( 1 );

    m2.inserer( 2 );
    m2.inserer( 3 );

    m1.transferer( m2 );

    points += similarite( attendu1, NOMBRE_VALEUR_ATTENDU1, m1 );
    points += similarite( attendu2, NOMBRE_VALEUR_ATTENDU2, m2 );

    return ponderation * ( points / 2.0 );
}

double testTransferer_7b( double ponderation ) {
    cerr << "test transferer 7b : " << endl;
    double points = 0.0;
    int NOMBRE_VALEUR_ATTENDU1 = 4;
    int attendu1[NOMBRE_VALEUR_ATTENDU1] = {1, 2, 3, 4};
    int NOMBRE_VALEUR_ATTENDU2 = 0;
    int attendu2[NOMBRE_VALEUR_ATTENDU2] = {};

    MiniList< int > m1;
    MiniList< int > m2;

    m1.inserer( 1 );

    m2.inserer( 2 );
    m2.inserer( 3 );

    m1.transferer( m2 );

    m1.inserer( 4 );

    points += similarite( attendu1, NOMBRE_VALEUR_ATTENDU1, m1 );
    points += similarite( attendu2, NOMBRE_VALEUR_ATTENDU2, m2 );

    return ponderation * ( points / 2.0 );
}

double testTransferer_7c( double ponderation ) {
    cerr << "test transferer 7c : " << endl;
    double points = 0.0;
    int NOMBRE_VALEUR_ATTENDU1 = 3;
    int attendu1[NOMBRE_VALEUR_ATTENDU1] = {1, 2, 3};
    int NOMBRE_VALEUR_ATTENDU2 = 1;
    int attendu2[NOMBRE_VALEUR_ATTENDU2] = {4};

    MiniList< int > m1;
    MiniList< int > m2;

    m1.inserer( 1 );

    m2.inserer( 2 );
    m2.inserer( 3 );

    m1.transferer( m2 );

    m2.inserer( 4 );

    points += similarite( attendu1, NOMBRE_VALEUR_ATTENDU1, m1 );
    points += similarite( attendu2, NOMBRE_VALEUR_ATTENDU2, m2 );

    return ponderation * ( points / 2.0 );
}





double testTransferer_8a( double ponderation ) {
    cerr << "test transferer 8a : " << endl;
    double points = 0.0;
    int NOMBRE_VALEUR_ATTENDU1 = 4;
    int attendu1[NOMBRE_VALEUR_ATTENDU1] = { 1, 5, 2, 3 };
    int NOMBRE_VALEUR_ATTENDU2 = 0;
    int attendu2[NOMBRE_VALEUR_ATTENDU2] = {};

    MiniList< int > m1;
    MiniList< int > m2;

    m1.inserer( 1 );
    m1.inserer( 5 );

    m2.inserer( 2 );
    m2.inserer( 3 );

    m1.transferer( m2 );

    points += similarite( attendu1, NOMBRE_VALEUR_ATTENDU1, m1 );
    points += similarite( attendu2, NOMBRE_VALEUR_ATTENDU2, m2 );

    return ponderation * ( points / 2.0 );
}

double testTransferer_8b( double ponderation ) {
    cerr << "test transferer 8b : " << endl;
    double points = 0.0;
    int NOMBRE_VALEUR_ATTENDU1 = 5;
    int attendu1[NOMBRE_VALEUR_ATTENDU1] = {1, 5, 2, 3, 4};
    int NOMBRE_VALEUR_ATTENDU2 = 0;
    int attendu2[NOMBRE_VALEUR_ATTENDU2] = {};

    MiniList< int > m1;
    MiniList< int > m2;

    m1.inserer( 1 );
    m1.inserer( 5 );

    m2.inserer( 2 );
    m2.inserer( 3 );

    m1.transferer( m2 );

    m1.inserer( 4 );

    points += similarite( attendu1, NOMBRE_VALEUR_ATTENDU1, m1 );
    points += similarite( attendu2, NOMBRE_VALEUR_ATTENDU2, m2 );

    return ponderation * ( points / 2.0 );
}

double testTransferer_8c( double ponderation ) {
    cerr << "test transferer 8c : " << endl;
    double points = 0.0;
    int NOMBRE_VALEUR_ATTENDU1 = 4;
    int attendu1[NOMBRE_VALEUR_ATTENDU1] = {1, 5, 2, 3};
    int NOMBRE_VALEUR_ATTENDU2 = 1;
    int attendu2[NOMBRE_VALEUR_ATTENDU2] = {4};

    MiniList< int > m1;
    MiniList< int > m2;

    m1.inserer( 1 );
    m1.inserer( 5 );

    m2.inserer( 2 );
    m2.inserer( 3 );

    m1.transferer( m2 );

    m2.inserer( 4 );

    points += similarite( attendu1, NOMBRE_VALEUR_ATTENDU1, m1 );
    points += similarite( attendu2, NOMBRE_VALEUR_ATTENDU2, m2 );

    return ponderation * ( points / 2.0 );
}




double testTransferer( void )
{
    cout << endl << "--------------------" << endl << "Transferer" << endl;
    double ponderation = 1.0 / 8.0;
    double points =
            testTransferer_1a( ponderation ) +
            testTransferer_1b( ponderation ) +
            testTransferer_1c( ponderation ) +
            testTransferer_2a( ponderation ) +
            testTransferer_2b( ponderation ) +
            testTransferer_2c( ponderation ) +
            testTransferer_3a( ponderation ) +
            testTransferer_3b( ponderation ) +
            testTransferer_3c( ponderation ) +
            testTransferer_4a( ponderation ) +
            testTransferer_4b( ponderation ) +
            testTransferer_4c( ponderation ) +
            testTransferer_5a( ponderation ) +
            testTransferer_5b( ponderation ) +
            testTransferer_5c( ponderation ) +
            testTransferer_6a( ponderation ) +
            testTransferer_6b( ponderation ) +
            testTransferer_6c( ponderation ) +
            testTransferer_7a( ponderation ) +
            testTransferer_7b( ponderation ) +
            testTransferer_7c( ponderation ) +
            testTransferer_8a( ponderation ) +
            testTransferer_8b( ponderation ) +
            testTransferer_8c( ponderation );

    cout << endl << "Points transferer : " << points << " / 3.0" << endl;

    return points;
}
/******************************************************************************/
/** tests *********************************************************************/

void lancerTests( void )
{
    double points =
            testSuiteNonDecroissante() +
            testTriFusion2() +
            testTransferer();
    cout << endl
         <<  "--------------------" << endl
         << "total : " << points << endl;
}
