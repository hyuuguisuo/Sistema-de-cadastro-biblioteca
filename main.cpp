/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void pedrapapeltesoura()
{

	cout << "Os deuses do pedra papel e tesoura se revelam sobre ti." << endl;
	cout << "press  [1]  para Pedra." << endl;
	cout << "press  [2]  para Tesoura." << endl;
	cout << "press  [3]  para Papel." << endl;
	cout << "---  O que Mateus fará? ---" << endl;

	int escolhaMaquina = -1, escolhaPlayer = -1;

	cin >> escolhaPlayer;

	srand(time(0));

	escolhaMaquina = 1 + (rand() % 3);

	if (escolhaPlayer == escolhaMaquina) {
		cout << "Uma luta ardua. Empate.";

	} else if (escolhaMaquina == 1) {
		if (escolhaPlayer == 2) {
			cout << "Você morreu..." << endl << "sua historia nao pode acabar aqui." << endl;
			     cout << "Mateus! Tenha determinacao!";

		} else {
			cout << "Numa jogada suja os deuses da pedra foram cobertos por um montante de papel celofane." << endl;
			cout << "Metade das Arvores do mundo foram consumidas nesse ato." << endl;
		}
		
	} else if (escolhaMaquina == 2) {
		if (escolhaPlayer == 1) {
			cout << "Nem as mais afiadas das tesouras foram capazes de perfurar a pedra real" << endl;
            cout << "Voce pulveriza todas as montanhas do mundo e ataca eles." << endl <<"Mateus Win" << endl;
		} else {
			cout << "Um corte de papel, seu pior inimigo." << endl;
		}
	} else if (escolhaMaquina == 3) {
		if (escolhaPlayer == 1) {
			cout << "O mundo foi engulido por papel-filme... Ate onde ira essa insanidade?";
		} else {
			cout << "TESOURA AFIADA ---- corte seco tramontina --- estilhete --- faquinha de brincar --- " << endl << "Avante!!" << endl;
		}
	} else {
	    cout << "Não valeu";
	}

}



int main()
{
	std::cout<<"Hello World";
	pedrapapeltesoura();
	return 0;
}