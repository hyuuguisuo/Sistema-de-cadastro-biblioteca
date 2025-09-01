#include <iostream>
#include <vector>


struct cliente {    
    // int id;   

    std::string nome;
    std::string endereco;
    std::string cpf;
};

struct livro{
    // int id;

    std::string nome;
    std::string editora;
    std::string dt_lancamento;
    bool emprestado = false;
};

struct emprestimo{
    // int id;

    cliente cli;
    livro livro;
};

void cadastrarLivro(std::vector<livro>& livros) 
{
    std::cin.ignore();

    livro novo_livro;

    std::cout << "* Qual é o nome do Livro?" << std::endl;

    std::getline(std::cin, novo_livro.nome );
        
    std::cout << "* Qual é a editora?" << std::endl;
    
    std::getline(std::cin, novo_livro.editora);
    
    std::cout << "* Qual é o data de lancamento?" << std::endl;
    
    std::getline(std::cin, novo_livro.dt_lancamento);
    
    livros.push_back(novo_livro);
}

void editarLivro(std::vector<livro>& livros, int id)
{

}

void excluirLivro(std::vector<livro>& livros, int id)
{

}

void listarLivros(std::vector<livro>& livros)
{
    int i = 0;
    for (const auto& li : livros) {
        std::cout << "ID: " << i << " | " << li.nome;

        if (li.emprestado == true){
            std::cout << " [Foi emprestado]";
        }
        
        std::cout << "\n";
        i++;
    }
    std::cout << "-----------------------" << std::endl;
}

//

void cadastrarCliente(std::vector<cliente>& clientes) 
{
    std::cin.ignore();

    cliente cli;
    std::cout << "* Qual é o nome do cliente?" << std::endl;

    std::getline(std::cin, cli.nome );
        
    std::cout << "* Qual é o endereço?" << std::endl;
    
    std::getline(std::cin, cli.endereco);
    
    std::cout << "* Qual é o cpf?" << std::endl;
    
    std::getline(std::cin, cli.cpf);

    clientes.push_back(cli);
}

void editarCliente(cliente& cli)
{
    std::cout << "------DADOS ATUAIS-----" << std::endl;
    std::cout << "| " << cli.nome << "\n";
    std::cout << "| " << cli.endereco << "\n";
    std::cout << "| " << cli.cpf << "\n";
    std::cout << "-----------------------" << std::endl;

    std::cout << "Se deseja manter coloque [0]" << "\n\n";

    std::cin.ignore();

    std::string nome, endereco, cpf;

    std::cout << "Novo nome:\n- ";
    std::getline(std::cin, nome );

    std::cout << "Novo endereço:\n- ";
    std::getline(std::cin, endereco );

    std::cout << "Novo cpf:\n- ";
    std::getline(std::cin, cpf );

    if (nome != "0"){
        cli.nome = nome;
    }
    if (endereco != "0"){
        cli.endereco = endereco;
    }
    if (cpf != "0"){
        cli.cpf = cpf;
    }
    std::cout << "-----------------------" << std::endl;
}

void excluirCliente(std::vector<cliente>& clientes, int id)
{

}

void listarClientes(std::vector<cliente>& clientes)
{
    int i = 0;
    for (const auto& cli : clientes) {
        std::cout << "ID: " << i << " | " << cli.nome << "\n";
        i++;
    }
    std::cout << "-----------------------" << std::endl;
}

//

void criarEmprestimo(std::vector<emprestimo>& emprestimos, livro& liv, cliente& cli)
{
    if (liv.emprestado){
        std::cout << "entao ne, ta emprestado o livro já" << std::endl;
    } else{   
        emprestimo empres; 

        empres.cli = cli;
        empres.livro = liv;
        
        emprestimos.push_back(empres);
        liv.emprestado = true;
    }
}
void editarEmprestimo(std::vector<emprestimo>& emprestimos, int id)
{
    
}
void excluirEmprestimo(std::vector<emprestimo>& emprestimos, int id)
{

}
void listarEmprestimos(std::vector<emprestimo>& emprestimos)
{
    int i = 0;
    for (const auto& emp : emprestimos) {
        std::cout << "ID: " << i << " | O cliente: " << emp.cli.nome << "\nLevou o livro: " << emp.livro.nome << "\n";
        i++;
    }
    std::cout << "-----------------------" << std::endl;
}

int main()
{
    int op = -1;

    std::vector<cliente> clientes;
    std::vector<livro> livros;
    std::vector<emprestimo> emprestimos;

    while (op != 0) {
        std::cout << "============= BIBLIOTECA =============" << std::endl;
        std::cout << "[0] - SAIR\n" << "[1] - Cliente\n" << "[2] - Livro\n" << "[3] - Empréstimo\n";;
        std::cout << "Digite a opção desejada: " << std::endl;
        std::cin >> op;
        std::cout << "-----------------------" << std::endl;

        switch (op){
            case 0:{
                std::cout << "\n\n";
                break;
            }
            case 1:{
                int op2 = -1;
                while (op2 != 0) {
                    std::cout << "Caso 1 - Cliente Menu" << std::endl;
                    std::cout << "[0] - RETORNAR\n" << "[1] - Cadastrar\n" << "[2] - Editar\n" << "[3] - Excluir\n" << "[4] - Listar\n";
                    std::cout << "Digite a opção desejada: " << std::endl;
                    std::cin >> op2;
                    std::cout << "-----------------------" << std::endl;

                    switch (op2){
                        case 0:{
                            std::cout << "\n\n";
                            break;
                        }
                        case 1:{
                            std::cout << "Opção 1 Clientes\n" << std::endl;
                            cadastrarCliente(clientes);
                            break;
                        }
                        case 2:{
                            std::cout << "Opção 2 Clientes\n" << std::endl;
                            int id;
                            std::cout << "Informe o ID do cliente que irá ser editado: " << std::endl;
                            std::cin >> id;
                            editarCliente(clientes[id]);
                            break;
                        }
                        case 3:{
                            std::cout << "Opção 3 Clientes\n" << std::endl;
                            int id;
                            excluirCliente(clientes, id);
                            break;
                        }
                        case 4:{
                            std::cout << "Opção 4 Clientes\n" << std::endl;
                            listarClientes(clientes);
                            break;
                        }
                        default:{
                            std::cout << "Opção Inválida\n" << std::endl;
                        }

                    }
                }
                break;
            }
            case 2:{    
                int op2 = -1;
                while (op2 != 0) {
                    std::cout << "Caso 2 - Livros Menu" << std::endl;
                    std::cout << "[0] - RETORNAR\n" << "[1] - Cadastrar\n" << "[2] - Editar\n" << "[3] - Excluir\n" << "[4] - Listar\n";
                    std::cout << "Digite a opção desejada: " << std::endl;
                    std::cin >> op2;
                    std::cout << "-----------------------" << std::endl;

                    switch (op2){
                        case 0:{
                            std::cout << "\n\n";
                            break;
                        }
                        case 1:{
                            std::cout << "Opção 1 Livros\n" << std::endl;
                            cadastrarLivro(livros);
                            break;
                        }
                        case 2:{
                            std::cout << "Opção 2 Livros\n" << std::endl;
                            int id;
                            editarLivro(livros, id);
                            break;
                        }
                        case 3:{
                            std::cout << "Opção 3 Livros\n" << std::endl;
                            int id;
                            excluirLivro(livros, id);
                            break;
                        }
                        case 4:{
                            std::cout << "Opção 4 Livros\n" << std::endl;
                            listarLivros(livros);
                            break;
                        }
                        default:{
                            std::cout << "Opção Inválida\n" << std::endl;
                        }
                    }
                }
                break;
            }
            case 3:
            {
                int op2 = -1;
                while(op2 != 0) {
                    std::cout << "Caso 3 - Empréstimos Menu" << std::endl;
                    std::cout << "[0] - RETORNAR\n" << "[1] - Emprestar\n" << "[2] - Devolver\n" << "[3] - Editar\n" << "[4] - Excluir\n" << "[5] - Listar\n";
                    std::cout << "Digite a opção desejada: " << std::endl;
                    std::cin >> op2;
                    std::cout << "-----------------------" << std::endl;
                    
                    switch (op2) {
                        case 0:{
                            std::cout << "\n\n";
                            break;
                        }
                        case 1:{                              
                            int x, y;
                            std::cout << "Informe o ID do livro que será emprestado: \n";
                            std::cin >> x;
                            
                            std::cout << "Informe o ID do cliente que irá levá-lo: \n";
                            std::cin >> y;

                            criarEmprestimo(emprestimos, livros[x], clientes[y]);
                            break;
                        }
                        case 5:{
                            listarEmprestimos(emprestimos);
                            break;
                        }
                        default:{
                            std::cout << "Opção Inválida\n" << std::endl;
                        }
                    }
                }
            }
            default:{
                std::cout << "Opção Inválida\n" << std::endl;
            }
        }
    }
}