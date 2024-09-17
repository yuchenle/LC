// 2191.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include "2191Solution.cpp"
#include <chrono>   // For std::chrono::seconds
#include <thread>   // For std::this_thread::sleep_for

int main()
{
    std::cout << "Hello World!\n";
    Solution s = Solution();
    vector<int> mapping = {8,9,4,0,2,1,3,5,7,6};
    vector<int> nums = { 991,338,38 };
    auto ret = s.sortJumbled(mapping, nums);

    cout << "================" << endl;
    
    for (auto num : ret) {
        cout << num << endl;
    }

    return 0;
}

// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
