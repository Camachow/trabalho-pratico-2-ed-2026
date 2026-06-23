# Sistema de Pesquisa de Departamentos

Este projeto é um programa em C++ que lê uma lista de departamentos a partir de um arquivo texto e permite realizar pesquisas por palavra-chave ou pelo nome do departamento.

## Objetivo

O programa tem como objetivo associar departamentos a palavras-chave. A partir dos dados carregados do arquivo `arquivo.txt`, o usuário pode:

- Pesquisar uma palavra-chave e descobrir qual departamento ela representa.
- Pesquisar um departamento e visualizar seu código e suas palavras-chave associadas.

## Arquivos do projeto

- `main.cpp`: código-fonte principal do programa.
- `arquivo.txt`: arquivo de entrada com os dados dos departamentos.
- `README.md`: documentação do projeto.

## Formato do arquivo de entrada

O arquivo `arquivo.txt` deve estar na mesma pasta do executável e deve seguir o seguinte formato:

```txt
CODIGO NOME_DO_DEPARTAMENTO PALAVRA1 PALAVRA2 PALAVRA3 PALAVRA4 PALAVRA5
```

Cada linha representa um departamento. O programa espera exatamente:

- 1 código do departamento.
- 1 nome do departamento.
- 5 palavras-chave associadas ao departamento.

Exemplo:

```txt
001 FINANCEIRO INVESTIMENTO RENDA GASTOS DESPESAS LUCRO
002 CONTABILIDADE BALANÇO BALANCETE RAZÃO ENTRADA SAÍDA
003 PESSOAL SALÁRIO VAGAS CONTRATAÇÃO DESLIGAMENTO PROMOÇÃO
```

## Estrutura usada no programa

O programa utiliza uma estrutura chamada `Departamento` para armazenar os dados lidos do arquivo:

```cpp
struct Departamento
{
  string codigo;
  string nome;
  string palavrasChave[5];
};
```

Os departamentos são armazenados em um `vector`, permitindo guardar várias linhas do arquivo em memória para realizar as buscas.

## Como compilar

No terminal, acesse a pasta do projeto:

```bash
cd /home/camacho/Documents/UFMG/tp2-ed-2026
```

Depois, compile o programa com `g++`:

```bash
g++ main.cpp -o main
```

Esse comando gera um executável chamado `main`.

## Como executar

Com o arquivo `arquivo.txt` na mesma pasta do executável, execute:

```bash
./main
```

O programa exibirá o menu:

```txt
================ MENU ================
1. Pesquisar por palavra-chave
2. Pesquisar por departamento
0. Sair
Escolha uma opcao:
```

## Exemplos de uso

### Pesquisar por palavra-chave

Entrada:

```txt
1
INVESTIMENTO
```

Saída esperada:

```txt
-> A palavra-chave 'INVESTIMENTO' representa o departamento: FINANCEIRO
```

### Pesquisar por departamento

Entrada:

```txt
2
FINANCEIRO
```

Saída esperada:

```txt
-> Departamento encontrado!
Codigo: 001
Palavras-chave: INVESTIMENTO RENDA GASTOS DESPESAS LUCRO
```

### Encerrar o programa

Para sair, escolha a opção:

```txt
0
```

## Observações importantes

- As buscas devem ser digitadas exatamente como aparecem no arquivo.
- O programa diferencia letras maiúsculas e minúsculas.
- Palavras com acento também precisam ser digitadas com o acento correto.
- O arquivo `arquivo.txt` precisa estar no mesmo diretório em que o programa é executado.
- O nome do departamento não pode conter espaços, pois a leitura é feita usando o operador `>>`.

## Possíveis melhorias futuras

- Permitir busca sem diferenciar letras maiúsculas e minúsculas.
- Permitir nomes de departamentos com espaços.
- Ler uma quantidade variável de palavras-chave por departamento.
- Melhorar o tratamento de entradas inválidas no menu.
- Permitir informar o nome do arquivo pela linha de comando.
