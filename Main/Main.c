#include <stdio.h>

struct Sessao {
    int id;
    int bateria_atual;
    int tempo_recarga;
    float preco_total;
    int cabo_conectado;
    int status;
    float potencia;
};

struct Sessao sessoes[3]; 

void menu() {
    printf("Menu de Opções:\n");
    printf("1. Iniciar Sessão\n");
    printf("2. Encerrar Sessão\n");
    printf("3. Verificar Status\n");
    printf("4. Sair\n");
}

void controle_de_energia() {
    float potencia_total = 0;
    for (int i = 0; i < 3; i++) {
    if (sessoes[i].status == 1) {
        potencia_total += sessoes[i].potencia;
        }
    }
    if (potencia_total > 50.0) {
        printf("A potência total excede a capacidade máxima. Reduzindo potência...\n");
        for (int i = 0; i < 3; i++) {
            if (sessoes[i].status == 1) {
                sessoes[i].potencia *= 0.8; // Reduz a potência em 20%
                printf("Sessão %d - Nova Potência: %.1f kW\n", sessoes[i].id, sessoes[i].potencia);
            }
        }
    } else {
        printf("A potência total está dentro da capacidade máxima.\n");
    }
}

void tarifacao_dinamica() {
    int hora;
    int bandeira = 0;

    }

int main() {

    int opcao;
    sessoes[0].id = 1;
    sessoes[0].bateria_atual = 20;
    sessoes[0].tempo_recarga = 30;
    sessoes[0].preco_total = 5.0;
    sessoes[0].cabo_conectado = 1;
    sessoes[0].status = 1;
    sessoes[0].potencia = 12.0;

    sessoes[1].id = 2;
    sessoes[1].bateria_atual = 50;
    sessoes[1].tempo_recarga = 20;
    sessoes[1].preco_total = 10.0;
    sessoes[1].cabo_conectado = 1;
    sessoes[1].status = 1;
    sessoes[1].potencia = 15.0;

    sessoes[2].id = 3;
    sessoes[2].bateria_atual = 80;
    sessoes[2].tempo_recarga = 10;
    sessoes[2].preco_total = 15.0;
    sessoes[2].cabo_conectado = 1;
    sessoes[2].status = 1;
    sessoes[2].potencia = 18.0;

    do {
        menu();
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("Iniciando sessão...\n");
            printf("Por favor, conecte o cabo para iniciar a recarga.\n");
            for (int i = 0; i < 3; i++) {
                if (sessoes[i].cabo_conectado == 1) {
                    printf("Cabo conectado. Iniciando recarga...\n");
                    if (sessoes[i].status == 0) {
                        sessoes[i].status = 1;
                        printf("Sessão %d iniciada com sucesso.\n", sessoes[i].id);
                    } else {
                        printf("Sessão %d já está ativa.\n", sessoes[i].id);
                    }
                } else {
                    printf("Cabo não conectado. Não é possível iniciar a recarga.\n");
                }

                printf("Sessão %d - Bateria: %d%%, Tempo de Recarga: %d min, Preço Total: R$%.2f, Potência: %.1f kW\n", sessoes[i].id, sessoes[i].bateria_atual, sessoes[i].tempo_recarga, sessoes[i].preco_total, sessoes[i].potencia);
            }
            break;
        case 2:
            printf("Encerrando sessão...\n");
            printf("Por favor, desconecte o cabo para finalizar a sessão.\n");
            for (int i = 0; i < 3; i++) {
                if (sessoes[i].status == 1) {
                    sessoes[i].status = 0;
                    printf("Sessão %d encerrada com sucesso.\n", sessoes[i].id);
                } else {
                    printf("Sessão %d não está mais ativa.\n", sessoes[i].id);
                }
                printf("Sessão %d - Bateria: %d%%, Tempo de Recarga: %d min, Preço Total: R$%.2f, Potência: %.1f kW\n", sessoes[i].id, sessoes[i].bateria_atual, sessoes[i].tempo_recarga, sessoes[i].preco_total, sessoes[i].potencia);
            }
            break;
        case 3:
            controle_de_energia();
            printf("Verificando status...\n");
            for (int i = 0; i < 3; i++) {
                if (sessoes[i].cabo_conectado == 1) {
                    printf("Cabo conectado.\n");
                } else {
                    printf("Cabo não conectado.\n");
                }if (sessoes[i].status == 1) {
                    printf("Sessão %d está ativa.\n", sessoes[i].id);
                } else {
                    printf("Sessão %d não está ativa.\n", sessoes[i].id);
                }
                printf("Sessão %d - Bateria: %d%%, Tempo de Recarga: %d min, Preço Total: R$%.2f, Potência: %.1f kW\n", sessoes[i].id, sessoes[i].bateria_atual, sessoes[i].tempo_recarga, sessoes[i].preco_total, sessoes[i].potencia);
            }
            break;
        case 4:
            printf("Saindo...\n");
            printf("Obrigado por usar o sistema de recarga de veículos elétricos!\n");
            break;
        default:
            printf("Opção inválida. Tente novamente.\n");
            break;
        }
    } while (opcao != 4);

    return 0;
}



