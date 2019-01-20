/* 
 * File:   main.cpp
 * Author: oscar99
 *
 * Created on 7 de febrero de 2017, 22:06
 */

#include <cstdlib>
#include "animals.hxx"
#include <sstream>
#include <list>

using namespace std;

int main(int argc, char** argv) {

    int opt = 0;
    string input = "";
    typedef std::list<Animal*> Animals;
    Animals Recinte_1;
        Animal unAnimal;
	unAnimal.nom("Pikatxu");
	Recinte_1.push_back(&unAnimal);

	Elefant unElefant;
	unElefant.nom("Jumbo l'Orellut");
	Recinte_1.push_back(&unElefant); 

	Granota unaGranota;
	unaGranota.nom("Gustavo el Reporter");
	Recinte_1.push_back(&unaGranota);
        
    Animals Recinte_2;
        Gat unGat;
	unGat.nom("Gat Amb Botes");
	Recinte_2.push_back(&unGat);
        
        Animal unAnimal2;
	unAnimal2.nom("Lunala");
	Recinte_2.push_back(&unAnimal2);
        
        Pingui Elies;
        Elies.nom("Elies");
        Recinte_2.push_back(&Elies);
        
    Animals Recinte_3;
        Lleo unLleo;
        unLleo.nom("El Rei Lleó");
        Recinte_3.push_back(&unLleo);
        
        Lleo unLleo2;
        unLleo2.nom("La Reina Lleona");
        Recinte_3.push_back(&unLleo2);
        
        Granota unaGranota2;
	unaGranota2.nom("La Rana");
	Recinte_3.push_back(&unaGranota2);
        
    Animals Recinte_4;
        Pingui Pinguino1;
        Pinguino1.nom("Comandante");
        Recinte_4.push_back(&Pinguino1);
        
        Pingui Pinguino2;
        Pinguino2.nom("Kowalski");
        Recinte_4.push_back(&Pinguino2);
        
        Pingui Pinguino3;
        Pinguino3.nom("Recluta");
        Recinte_4.push_back(&Pinguino3);
        
        Pingui Pinguino4;
        Pinguino4.nom("Rico");
        Recinte_4.push_back(&Pinguino4);
        
    while (opt != 5) {
        cout <<"Benvingut al Zoologic de Óscar i la Lucía\n";
        cout <<"Al nostre Zoo disposem dels seguents recintes d'animals:\n";
                cout <<"\tRecinte 1\n";
                cout <<"\tRecinte 2\n";
                cout <<"\tRecinte 3\n";
                cout <<"\tRecinte 4\n";
        cout <<"Si desitja marxar del Zoo introdueixi un 5. Sino\n";
        cout <<"Introdueixi el numero del recinte al qual vol accedir per veure els seus animals:\n";

        while (true) {
            getline(cin, input);
            // This code converts from string to number safely.
            stringstream myStream(input);
            if (myStream >> opt)
                break;
            cout << "Numero invalid, si us plau torni a intentar-ho:" << endl;
        }
        
        switch(opt){
            case 1:
                for (Animals::iterator it=Recinte_1.begin(); it!=Recinte_1.end(); it++){
                        std::cout << "l'animal anomenat " << (*it)->nom() << " es de l'especie ";
                        (*it)->escriuEspecie();
                }
                break;
                
            case 2:
                for (Animals::iterator it=Recinte_2.begin(); it!=Recinte_2.end(); it++){
                        std::cout << "l'animal anomenat " << (*it)->nom() << " es de l'especie ";
                        (*it)->escriuEspecie();
                }
                break;
                
            case 3:
                for (Animals::iterator it=Recinte_3.begin(); it!=Recinte_3.end(); it++){
                        std::cout << "l'animal anomenat " << (*it)->nom() << " es de l'especie ";
                        (*it)->escriuEspecie();
                }
                break;
                
            case 4:
                for (Animals::iterator it=Recinte_4.begin(); it!=Recinte_4.end(); it++){
                        std::cout << "l'animal anomenat " << (*it)->nom() << " es de l'especie ";
                        (*it)->escriuEspecie();
                }
                break;
                
            case 5: 
                cout << "Gràcies per la seva visita. Fins un altre!" << endl;
                break;
                
            default: 
                cout << "Numero invalid, si us plau torni a intentar-ho:" << endl;
                break;
        }

    }

    return 0;
}

