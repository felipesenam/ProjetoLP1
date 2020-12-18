
## Discentes
Equipe: Lobos Guaraná\
Integrantes: Charles Vitor e Felipe Sena

## Vídeo da apresentação
 * [Parte I - YouTube](https://youtu.be/LB74aCdCHhw)
 * [Parte II - YouTube](https://youtu.be/)

## O que foi implementado
 * A remoção e o cadastro de um animal levando em conta a sua classe (anfíbio, ave, mamífero ou réptil), classificação (doméstico, exótico ou nativo), entre outros dados específicos;
 * A remoção e o cadastro de veterinários e tratadores e suas particularidades;
 * *"Errei o cadastro"* - Na nossa implementação é possível alterar todos os dados possíveis relacionados tanto para funcionários quanto para animais!;
 * *"Não quero continuar o cadastro"* - Digite *0* (zero) em para cancelar qualquer operação (não é válido em menus);
 * Interface **colorida**!;
 * *"Não lembro do ID"* - Sem problemas, também é reconhecido o nome ou espécie;
 * *"E as leis?"*
 	- **Garantimos** que todos os animais cadastrados terão **obrigatoriamente** algum vínculo com um veterinário e um tratador apto;
 	- Aqui todo veterinário tem que estar associado a um número de **CRMV**;
 	- Animais nativos só com **licença de transporte**.
 * Liste os animais por classe e classificação e também por responsável (veterinário ou tratador);
 * *"Livre de asteríscos!"* - Implementação feita *integralmente* sob **ponteiros inteligentes**;
 * Salvamento e carregamento completamente **automático**;
 * *"100% Valgrind"* - Não há erros conhecidos e não existem possíveis vazamentos de memória.

## Como compilar, rodar e testar o programa
### Versão final:
```
$ make
$ ./Pet_Fera
```
*ou*
```
$ make release
$ ./Pet_Fera
```
### Versão de depuração:
```
$ make debug
$ valgrind ./prog
```
Para esta versão do programa os comandos para limpar tela estão **desabilitados** e os ecos de chamada de construtores e destrutores **ativados**.

## O que não foi feito
### Referente ao pedido no projeto:
 - Devido ao curto tempo, não foi possível **concluir** a documentação para esta segunda parte do projeto;
 - Embora fosse possível, particularidades restritas às classes não puderam ser melhor exploradas.

### Ideias que não foram postas em prática:
 - Embora seja possível fazê-lo um a um, não foi implementado o sistema de transferência de responsabilidade entre os funcionários (caso estes deixassem de ter vínculo com a loja isso seria muito útil);
 - Não foi implementada a **exportação** dos dados dos animais ou funcionários de maneira **legível** para um arquivo de texto;
 - Não foi implementado o sistema de busca de funcionários e animais com base no algoritmo de **Levenshtein** (distância de edição).

## Informações extras
 - **Total de classes**: 24;
 - **Total de arquivos (.cpp, .hpp)**: 51 (120 Kb);
 - **Versão do makefile**: 3.1;
 - **Conceitos aplicados**: classes, herança de classes (simples e múltipla), template, namespace, macros de pré-processamento, ponteiros inteligentes, manipulação de arquivos, classe abstrata, método virtual puro, sobrecarga de operadores, dynamic_cast, dynamic_pointer_cast, enums, [...];
 - **Tipos e estruturas utilizadas**: vector, map, string, stringstream, fstream, unique_ptr, shared_ptr, [...].

## Repositório GitHub
 * [ProjetoLP1](https://github.com/Birdou/ProjetoLP1)
