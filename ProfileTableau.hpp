
#ifndef _PROFILE_TABLEAU_HPP
#define _PROFILE_TABLEAU_HPP

/**
 * @brief Un tableau conservant un profil d'accès.
 *
 * Cette classe represente un tableau.  La premiere valeur du tableau
 * est a l'indice 0.
 * Ce tableau conserve une trace du nombre
 * d'acces pour chaque case.  Le nombre d'acces demarre a 0 et augmente de
 * 1 pour les acces de lecture et de un pour les acces d'ecriture.
 * 
 * Il est possible de consulter des statistiques sur le nombre d'acces.
 *    -# nombre d'acces pour chaque case.
 *    -# moyenne du nombre d'acces.
 *    -# ecart type.
 *    -# indexe des cases les plus accedes.
 */
class ProfileTableau {

    /**
	 * Represente le contenue du tableau, donc les valeurs accedes pour chaque 
	 * case.
	 */
    int * _contenue;

	
	/**
	 * Ce tableau est utilise pour maintenir le nombre d'acces total pour 
	 * chaque case du tableau.
	 *
	 * @invariant \f$\forall i, 0 \le \f$ _nbrAcces[\f$i\f$]
	 */
    double * _nbrAcces;


	/**
	 * Conserve la taille du tableau.
	 */
	int _taille;
	
	
    /**
	 * La moyenne des nombres d'acces au tableau.  Cette variable est utilisee 
	 * pour optimiser l'acces a la moyenne.  Elle conserve le resultat du 
	 * calcul de la moyenne tant qu'il n'y a pas de changement dans le 
	 * tableau.
	 */
	double _nbrAccesMoyen;
	
	
	/**
	 * Un booleen indiquant si le contenue de la variable _nbrAccesMoyen est
	 * a jour.
	 */
	bool _estValideNbrAccesMoyen;
	

	/**
	 * L'ecart type calcule sur le nombre d'acces.  Cette variable est utilisee 
	 * pour optimiser l'acces a l'ecart type.  Elle conserve le resultat du 
	 * calcul de l'ecart type tant qu'il n'y a pas de changement dans le 
	 * tableau.
	 */
	double _ecartType;
	
	
	/**
	 * Un booleen indiquant si le contenue de la variable _ecartType est
	 * a jour.
	 */
	bool _estValideEcartType;
	
	


public :

    /**
	 * @brief Constructeur.
	 *
	 * Construit un nouveau tableau avec systeme de profil automatise.
	 *
	 * @param [in] int la taille du tableau construit.
	 *  @pre 0 \f$<\f$ _taille
	 *
	 * @return un nouveau tableau qui a la taille demande.  Les cases du 
	 *         tableau n'ont pas ete initialise.
	 *  @post \f$\forall i, 0 = \f$ _nbrAcces[\f$i\f$]
	 */
    ProfileTableau( int a_nbrElement );


    /**
	 * @brief Destructeur.
	 */
    virtual ~ProfileTableau( void );
    
	
	/**
	 * @brief setter pour les cases du tableau.
	 *
	 * Permet de placer une valeur dans le tableau.
	 * Cela aura pour effet d'incrementer de 1 le compteur d'acces de cette 
	 * case.
	 *
	 * @param [in] int la position a acceder dans le tableau.
	 *  @pre 0 \f$\le\f$ position \f$<\f$ _taille 
     *
	 * @return une reference sur la case du tableau.
	 */
    int & operator []( int );
	
	
    /**
	 * @brief Retourne la taille du tableau.
	 *
	 * @return le nombre d'elements contenu dans le tableau.
	 */
	int taille( void ) const;
	
	
	/**
	 * @brief Permet de consulter le nombre d'acces pour une case specifique.
	 *
	 * @param [in] int la position a acceder dans le tableau.
	 *  @pre 0 \f$\le\f$ position \f$<\f$ _taille 
	 *
	 * @return le nombre d'acces a cette case depuis la construction du 
	 *         tableau.
	 *  @post 0 \f$\le\f$ _nbrAcces[position]
	 */
    double nbrAcces( int ) const;
    double nbrAcces( void ) const;
	
	
	/**
	 * @brief Retourne le nombre moyen d'acces par case pour le tableau.
	 *
	 * Une technique de memoisation est utilise afin de limiter le nombre de
	 * fois que le calcul est effectue.  Afin que cette mecanique reste 
	 * fonctionnelle, il est conseille de toujours utiliser cette fonction
	 * pour acceder a la moyenne.
	 *
	 * @return la moyenne
	 *  @post nbrAccesMoyen \f$= \frac{1}{\textrm{\underscore{}taille}}\sum_{i=0}^{\textrm{\underscore{}_taille}}\f$_nbrAcces[\f$i\f$]
	 */
	double nbrAccesMoyen( void );


	/**
	 * @brief Retourne l'ecart type des acces par case pour le tableau.
	 *
	 * Une technique de memoisation est utilise afin de limiter le nombre de
	 * fois que le calcul est effectue.  Afin que cette mecanique reste 
	 * fonctionnelle, il est conseille de toujours utiliser cette fonction
	 * pour acceder a l'ecart type.
	 *
	 * @return la moyenne
	 *  @post ecartType \f$= \sqrt{\frac{1}{\textrm{\underscore{}taille}}\sum_{i=0}^{\textrm{\underscore{}_taille}}(\textrm{\underscore{}_nbrAcces}[i]-\textrm{\underscore{}_nbrAccesMoyen})^2}
	 */
	double ecartType( void );
	
	
	/**
	 * @brief Retourne un tableau des indices des cases les plus utilises 
	 *        dans le tableau.
	 *
	 * Les cases les plus utilisees sont celles dont le nombre d'acces est 
	 * superieur ou egal a : moyenne + ecart type.
	 * Le tableau retourne doit avoir une taille egal au nombre d'indice
	 * retourne plus 1.
	 * La derniere case du tableau retourne va contenir la valeur -1.
	 * Les autres case vont contenir les indices des cases selectionnees.
	 * S'il n'y a pas de case selectionnee, alors le tableau de retour
	 * va contenir une seule case avec la valeur -1.
     *
	 *
	 *   placez votre analyse ici
	 *
     * @author : placez votre nom et code permanent ici.
	 */
	int * indicesPlusUtilises( void );

	bool estTrie( void );

//	int nbrEchec( void );

//	int initCompteurEchec( void );
};

#endif
