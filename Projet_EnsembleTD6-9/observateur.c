/*
 * @Author: ThearchyHelios
 * @Date: 2022-11-26 18:06:12
 * @LastEditTime: 2022-11-26 18:06:13
 * @LastEditors: ThearchyHelios
 * @Description: 
 * @FilePath: /Projet_EnsembleTD6-9/observateur.c
 */
#include "observateur.h"

Etat initial()
{
    return Init;
}

Etat transition(Etat e, Alphabet c)
{
    switch(e)
    {
        case Init:
            switch(c)
            {
                case A:
                    return Erreur;

                case G:
                case D:
                    return Init;

                case M:
                    return Mes;
            }
    
        case Mes:
            switch(c)
            {
                case A:
                    return Init;
                
                case M:
                case G:
                case D:
                    return Mes;
            }

        case Erreur:
            return Erreur;
    }
}

int est_final(Etat e)
{
    return e != Erreur;
}