#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Entrega {
    int inicio;
    int fim;
    int indice_original;
};

bool ordenarPorFim(const Entrega &a, const Entrega &b) {
    return a.fim < b.fim;
}

int encontrarEntregaCompativel(const vector<Entrega> &lista_entregas, int indice_atual) {
    int esquerda = 0;
    int direita = indice_atual - 1;

    while (esquerda <= direita) {
        int meio = (esquerda + direita) / 2;

        if (lista_entregas[meio].fim <= lista_entregas[indice_atual].inicio) {
            if (meio + 1 < indice_atual &&
                lista_entregas[meio + 1].fim <= lista_entregas[indice_atual].inicio)
                esquerda = meio + 1;
            else
                return meio;
        } else {
            direita = meio - 1;
        }
    }
    return -1;
}

pair<int, vector<int>> calcularMaximoAtendimentosComReconstrucao(vector<Entrega> &lista_entregas) {
    int total = lista_entregas.size();
    sort(lista_entregas.begin(), lista_entregas.end(), ordenarPorFim);

    vector<int> tabela_dinamica(total, 0);
    tabela_dinamica[0] = 1;

    // Preenchimento DP
    for (int i = 1; i < total; i++) {
        int incluir = 1;
        int indice_compativel = encontrarEntregaCompativel(lista_entregas, i);
        if (indice_compativel != -1) {
            incluir += tabela_dinamica[indice_compativel];
        }

        int excluir = tabela_dinamica[i - 1];

        tabela_dinamica[i] = max(incluir, excluir);
    }

    // RECONSTRUÇÃO CORRETA
    vector<int> entregas_escolhidas;

    int i = total - 1;
    while (i >= 0) {
        int incluir = 1;
        int indice_compativel = encontrarEntregaCompativel(lista_entregas, i);
        if (indice_compativel != -1) {
            incluir += tabela_dinamica[indice_compativel];
        }

        int excluir = (i == 0 ? 0 : tabela_dinamica[i - 1]);

        // Verificar se a entrega i foi realmente incluída na melhor solução
        if (incluir >= excluir) {
            entregas_escolhidas.push_back(lista_entregas[i].indice_original);
            i = indice_compativel; // pular para entrega compatível
        } else {
            i--; // excluir entrega
        }
    }

    reverse(entregas_escolhidas.begin(), entregas_escolhidas.end());
    return {tabela_dinamica[total - 1], entregas_escolhidas};
}

int main() {
    int quantidade_entregas;
    cout << "Digite a quantidade de entregas do dia: ";
    cin >> quantidade_entregas;

    vector<Entrega> lista_entregas(quantidade_entregas);

    cout << "\nDigite o horario de inicio e fim de cada entrega:\n";
    for (int i = 0; i < quantidade_entregas; i++) {
        cout << "Entrega " << i + 1 << " - Inicio: ";
        cin >> lista_entregas[i].inicio;
        cout << "Entrega " << i + 1 << " - Fim: ";
        cin >> lista_entregas[i].fim;
        lista_entregas[i].indice_original = i + 1;
    }

    auto resultado = calcularMaximoAtendimentosComReconstrucao(lista_entregas);

    cout << "\n===== RESULTADO FINAL =====\n";
    cout << "Maximo de entregas atendidas no dia: " << resultado.first << "\n";

    cout << "\nEntregas selecionadas (na ordem cronologica):\n";
    for (int id : resultado.second) {
        cout << "Entrega " << id << endl;
    }

    return 0;
}
