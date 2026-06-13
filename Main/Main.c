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
    printf("Menu de Opcoes:\n");
    printf("1. Iniciar Sessao\n");
    printf("2. Encerrar Sessao\n");
    printf("3. Verificar Status\n");
    printf("4. Tarifacao Dinamica\n");
    printf("5. Simular Comunicacao OCPP\n");
    printf("6. Sair\n");
}

void controle_de_energia() {
    float potencia_total = 0;
    for (int i = 0; i < 3; i++) {
    if (sessoes[i].status == 1) {
        potencia_total += sessoes[i].potencia;
        }
    }
    if (potencia_total > 50.0) {
        printf("A potencia total excede a capacidade maxima. Reduzindo potencia...\n");
        for (int i = 0; i < 3; i++) {
            if (sessoes[i].status == 1) {
                sessoes[i].potencia *= 0.8; // Reduz a potencia em 20%
                printf("Sessao %d - Nova Potencia: %.1f kW\n", sessoes[i].id, sessoes[i].potencia);
            }
        }
    } else {
        printf("A potencia total esta dentro da capacidade maxima.\n");
    }
}

void tarifacao_dinamica() {
    int hora;
    int bandeira = 0;
    float tarifa_pico = 0;
    float tarifa_bandeira = 0;

    printf("\nInsira o horario atual:");
    scanf("%d", &hora);
    printf("Qual bandeira o usuario se encontra(1 para verde, 2 para amarela e 3 para vermelha):");
    scanf("%d", &bandeira);

    for (int i = 0; i < 3; i++) {

        if (hora >= 18 && hora <= 21) {
            printf("\nDevido ao horario de pico sera adicionado uma taxa de 20%% ");
            tarifa_pico = sessoes[i].preco_total * 0.20;
            sessoes[i].preco_total += tarifa_pico;
        }else{
            printf("Horario de funcionamento normal, taxas adicionais nao serao aplicadas");
        }
// Bandeira verde - tarifa normal (ex: R$ 0.50/kWh)
// Bandeira amarela - tarifa moderada (ex: R$ 0.65/kWh)
// Bandeira vermelha - tarifa alta (ex: R$ 0.80/kWh)
    switch (bandeira)
    {
    case 1:
        printf("Bandeira Verde - tarifa R$ 0.50/kWh");
        tarifa_bandeira = sessoes[i].preco_total * 0.50;
        sessoes[i].preco_total += tarifa_bandeira;
        break;
    case 2:
        printf("Bandeira Amarela - tarifa R$ 0.65/kWh");
        tarifa_bandeira = sessoes[i].preco_total * 0.65;
        sessoes[i].preco_total += tarifa_bandeira;
        break;
    case 3:
        printf("Bandeira Vermelha - tarifa R$ 0.80/kWh");
        tarifa_bandeira = sessoes[i].preco_total * 0.80;
        sessoes[i].preco_total += tarifa_bandeira;
        break;
    default:
        printf("Coloque um valor de acordo com o que foi dito!");
        break;
    }
    printf("\nSessao %d - Preco final: R$%.2f\n", sessoes[i].id, sessoes[i].preco_total);
    }
}

void simulacao_ocpp() {
    printf("Simulando comunicacao OCPP...\n");
    // Simulacao de envio de dados para a nuvem
    for (int i = 0; i < 3; i++) {
        printf("Enviando dados da Sessao %d para a nuvem...\n", sessoes[i].id);
        printf("Bateria: %d%%, Tempo de Recarga: %d min, Preco Total: R$%.2f, Potencia: %.1f kW\n", sessoes[i].bateria_atual, sessoes[i].tempo_recarga, sessoes[i].preco_total, sessoes[i].potencia);
        printf("Resposta recebida: Sessao %d confirmada!\n", sessoes[i].id);
    }
    printf("Dados enviados com sucesso!\n");
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
            printf("Iniciando sessao...\n");
            printf("Por favor, conecte o cabo para iniciar a recarga.\n");
            for (int i = 0; i < 3; i++) {
                if (sessoes[i].cabo_conectado == 1) {
                    printf("Cabo conectado. Iniciando recarga...\n");
                    if (sessoes[i].status == 0) {
                        sessoes[i].status = 1;
                        printf("Sessao %d iniciada com sucesso.\n", sessoes[i].id);
                    } else {
                        printf("Sessao %d ja esta ativa.\n", sessoes[i].id);
                    }
                } else {
                    printf("Cabo nao conectado. Nao e possivel iniciar a recarga.\n");
                }

                printf("Sessao %d - Bateria: %d%%, Tempo de Recarga: %d min, Preco Total: R$%.2f, Potencia: %.1f kW\n", sessoes[i].id, sessoes[i].bateria_atual, sessoes[i].tempo_recarga, sessoes[i].preco_total, sessoes[i].potencia);
            }
            break;
        case 2:
            printf("Encerrando sessao...\n");
            printf("Por favor, desconecte o cabo para finalizar a sessao.\n");
            for (int i = 0; i < 3; i++) {
                if (sessoes[i].status == 1) {
                    sessoes[i].status = 0;
                    printf("Sessao %d encerrada com sucesso.\n", sessoes[i].id);
                } else {
                    printf("Sessao %d nao esta mais ativa.\n", sessoes[i].id);
                }
                printf("Sessao %d - Bateria: %d%%, Tempo de Recarga: %d min, Preco Total: R$%.2f, Potencia: %.1f kW\n", sessoes[i].id, sessoes[i].bateria_atual, sessoes[i].tempo_recarga, sessoes[i].preco_total, sessoes[i].potencia);
            }
            break;
        case 3:
            controle_de_energia();
            printf("Verificando status...\n");
            for (int i = 0; i < 3; i++) {
                if (sessoes[i].cabo_conectado == 1) {
                    printf("Cabo conectado.\n");
                } else {
                    printf("Cabo nao conectado.\n");
                }if (sessoes[i].status == 1) {
                    printf("Sessao %d esta ativa.\n", sessoes[i].id);
                } else {
                    printf("Sessao %d nao esta ativa.\n", sessoes[i].id);
                }
                printf("Sessao %d - Bateria: %d%%, Tempo de Recarga: %d min, Preco Total: R$%.2f, Potencia: %.1f kW\n", sessoes[i].id, sessoes[i].bateria_atual, sessoes[i].tempo_recarga, sessoes[i].preco_total, sessoes[i].potencia);
            }
            break;
        case 4:
            tarifacao_dinamica();
            break;     
        case 5:
            simulacao_ocpp();
            break;        
        case 6:
            printf("Saindo...\n");
            printf("Obrigado por usar o sistema de recarga de veiculos eletricos!\n");
            break;
        default:
            printf("Opcao invalida. Tente novamente.\n");
            break;
        }
    } while (opcao != 6);

    return 0;
}