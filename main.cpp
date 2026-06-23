#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// 1. Criar uma estrutura de dados para inserir as informações
struct Departamento
{
  string codigo;
  string nome;
  string palavrasChave[5];
};

int main()
{
  vector<Departamento> departamentos;

  ifstream arquivo("arquivo.txt");

  if (!arquivo.is_open())
  {
    cout << "Erro ao abrir o arquivo 'arquivo.txt'." << endl;
    cout << "Certifique-se de que ele esta na mesma pasta do executavel." << endl;
    return 1;
  }

  Departamento dep_temp;

  while (arquivo >> dep_temp.codigo >> dep_temp.nome >>
         dep_temp.palavrasChave[0] >> dep_temp.palavrasChave[1] >>
         dep_temp.palavrasChave[2] >> dep_temp.palavrasChave[3] >>
         dep_temp.palavrasChave[4])
  {

    departamentos.push_back(dep_temp);
  }

  arquivo.close();

  int opcao = -1;

  while (opcao != 0)
  {
    cout << "\n================ MENU ================\n";
    cout << "1. Pesquisar por palavra-chave\n";
    cout << "2. Pesquisar por departamento\n";
    cout << "0. Sair\n";
    cout << "Escolha uma opcao: ";
    cin >> opcao;

    if (opcao == 1)
    {
      string busca;
      cout << "Digite a palavra-chave (exatamente como esta no arquivo): ";
      cin >> busca;

      bool encontrou = false;
      for (const auto &dep : departamentos)
      {
        for (int i = 0; i < 5; i++)
        {
          if (dep.palavrasChave[i] == busca)
          {
            cout << "\n-> A palavra-chave '" << busca << "' representa o departamento: " << dep.nome << endl;
            encontrou = true;
            break; // Achou a palavra neste departamento, pode parar o laço interno
          }
        }
      }
      if (!encontrou)
      {
        cout << "\n-> Palavra-chave nao encontrada." << endl;
      }
    }
    else if (opcao == 2)
    {
      string busca;
      cout << "Digite o nome do departamento (letras maiusculas, ex: FINANCEIRO): ";
      cin >> busca;

      bool encontrou = false;
      for (const auto &dep : departamentos)
      {
        if (dep.nome == busca)
        {
          cout << "\n-> Departamento encontrado!\n";
          cout << "Codigo: " << dep.codigo << "\n";
          cout << "Palavras-chave: ";
          for (int i = 0; i < 5; i++)
          {
            cout << dep.palavrasChave[i] << " ";
          }
          cout << endl;
          encontrou = true;
          break;
        }
      }
      if (!encontrou)
      {
        cout << "\n-> Departamento nao encontrado." << endl;
      }
    }
    else if (opcao != 0)
    {
      cout << "\n-> Opcao invalida. Tente novamente." << endl;
    }
  }

  return 0;
}