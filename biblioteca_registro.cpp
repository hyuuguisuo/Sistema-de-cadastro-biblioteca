#include <iostream>
using namespace std;

class Cliente {       
  public:
    string nome;
    string endereco;
    string cpf;
};

class Livro{
  public:
    string nome;
    string editora;
    string dt_lancamento;
    bool alugado = false;
};

void print (Livro livro){
    cout <<"\nnome: " << livro.nome;
    cout <<"\neditora: "<< livro.editora;
    cout <<"\ndata de Lançamento: " << livro.dt_lancamento << endl;
}

void print (Cliente cliente){
    cout << "\nnome: " << cliente.nome;
    cout << "\ncpf: " << cliente.cpf;
    cout << "\nendereço: " << cliente.endereco << endl;
}

int main()
{
    int i = -1;
    Cliente cli;
    Livro livro;

    while (i != 0) {
        cout << "====== biblioteca =====" << endl;
        cout << "[0] - SAIR\n" << "[1] - Cadastrar Cliente\n" << "[2] - Cadastrar Livro\n";
        cout << "[3] - Alugar Livro\n" << "[4] - Devolver Livro\n";
        
        cout << "Digite a opção desejada: " << endl;
        cin >> i;
        
        cout << "-----------------------" << endl;

        if ( i == 1){
            cout << "* Qual é o nome do cliente?" << endl;
            cin.ignore();
            getline(cin, cli.nome );
            cout << "* Qual é o endereço do cliente?" << endl;
            getline(cin, cli.endereco);
            cout << "* Qual é o cpf do cliente?" << endl;
            getline(cin, cli.cpf);

            print(cli);

        } else if ( i == 2){
            cout << "* Qual é o nome do livro?" << endl;
            cin.ignore();
            getline(cin, livro.nome );
            cout << "* Qual é a editora do livro?" << endl;
            getline(cin, livro.editora);
            cout << "* Quando foi lançado?" << endl;
            getline(cin, livro.dt_lancamento);

            print(livro);
        } else if ( i == 3 ){
            if (livro.alugado == false) {
                livro.alugado = true;
                cout << "O livro [ " << livro.nome << " ] foi alugado.";
            } else {
                cout << "Este livro não está dispovível." << endl;
            }
        } else if ( i == 4){
            if (livro.alugado == true) {
                livro.alugado = false;
                cout << "O livro [ " << livro.nome << " ] foi devolvido.";
            } else {
                cout << "Este livro não foi alugado." << endl;
                // apesar dessa opção provavelmente só aparecer caso o livro tenha sido alugado em um programa hipotetico
            }
        } else {
            break;
        }
        cout << "-----------------------" << endl;
    }
    cout << "fim";
    return 0;
}