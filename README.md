EntregaComJanelas — Seleção Ótima de Entregas com Janela de Tempo

Este programa implementa uma solução baseada em **Programação Dinâmica** para selecionar o maior número possível de entregas dentro de suas respectivas janelas de tempo, garantindo que **nenhuma entrega se sobreponha**.

Ele também realiza a **reconstrução da solução**, mostrando quais entregas foram escolhidas e em qual ordem.


Ideia Principal

Dado um conjunto de entregas, cada uma com:

**Início**
**Fim**

Queremos escolher o maior número de entregas possíveis sem sobreposição.

Isso é um clássico problema de:

*Weighted Interval Scheduling* (versão sem pesos, onde cada entrega vale 1)

A solução:

1. **Ordena** as entregas pelo horário de fim.
2. Para cada entrega, encontra a última que **não conflita** com ela (busca binária).
3. Usa **programação dinâmica (DP)** para calcular o máximo de entregas atendidas.
4. **Reconstrói** a lista final de entregas selecionadas.


Como funciona o código

1. Struct `Entrega`

Representa uma entrega com:

* `inicio`
* `fim`
* `indice_original` (para manter o número original antes da ordenação)

2. Ordenação

As entregas são ordenadas pelo horário de término para permitir decisão ótima.

3. Busca binária para encontrar entrega compatível

A função:

int encontrarEntregaCompativel(...)

Retorna o índice da entrega mais próxima (antes da atual) que termina **antes do início** da entrega atual.

4. DP para calcular o máximo de entregas

A tabela `tabela_dinamica[i]` armazena:

> O máximo de entregas atendidas considerando as entregas até `i`.

5. Reconstrução da solução

O programa volta “de trás para frente” e descobre quais entregas realmente foram incluídas.


Execução

O programa solicita ao usuário:

Quantidade de entregas
Para cada entrega:
  Horário de início
  Horário de fim

Exemplo de entrada:

Digite a quantidade de entregas do dia: 4

Entrega 1 - Inicio: 1
Entrega 1 - Fim: 3

Entrega 2 - Inicio: 2
Entrega 2 - Fim: 5

Entrega 3 - Inicio: 4
Entrega 3 - Fim: 6

Entrega 4 - Inicio: 6
Entrega 4 - Fim: 8

Saída:

===== RESULTADO FINAL =====
Maximo de entregas atendidas no dia: 3

Entregas selecionadas (na ordem cronologica):
Entrega 1
Entrega 3
Entrega 4

Como compilar

Use um compilador C++ moderno (g++, clang, etc).

Linux / WSL / Mac:

g++ EntregaComJanelas.cpp -o entregas
./entregas

Windows (MinGW):

g++ EntregaComJanelas.cpp -o entregas.exe
entregas.exe

Técnicas utilizadas

Ordenação de intervalos
Busca binária
Programação Dinâmica (DP)
Reconstrução da solução ótima
Estrutura de dados `vector`

Estrutura do Código

EntregaComJanelas.cpp
├── struct Entrega
├── ordenarPorFim()
├── encontrarEntregaCompativel()
├── calcularMaximoAtendimentosComReconstrucao()
└── main()

Só pedir!
