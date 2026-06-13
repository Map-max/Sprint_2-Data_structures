# SPRINT2 — Sistema Inteligente de Gerenciamento de Recarga

**Aluno:** Matheus  
**RM:** 567261  
**Turma:** 1CCPF  
**Disciplina:** Estrutura de Dados em C  
**Instituição:** FIAP  

---

## Descrição do Projeto

O SPRINT2 é um sistema terminal em linguagem C capaz de gerenciar múltiplas sessões de recarga de veículos elétricos simultaneamente. O sistema aplica regras de controle de potência, simula integração com plataformas externas via protocolo OCPP e calcula tarifação dinâmica com base em horário e bandeira tarifária.

---

## Funcionalidades

### 1. Gerenciamento de Múltiplas Sessões
O sistema inicializa 3 sessões de recarga pré-configuradas, cada uma com as seguintes informações:

- `id` — identificador da sessão
- `bateria_atual` — percentual de bateria do veículo (%)
- `tempo_recarga` — tempo estimado para completar a carga (minutos)
- `preco_total` — valor total a pagar pela recarga (R$)
- `cabo_conectado` — indica se o cabo está conectado ao veículo (1 = sim, 0 = não)
- `status` — indica se a sessão está ativa (1 = ativa, 0 = inativa)
- `potencia` — potência fornecida ao veículo (kW)

### 2. Controle de Demanda de Energia
O sistema monitora a potência total de todas as sessões ativas. Caso a soma ultrapasse **50 kW**, a potência de cada sessão ativa é reduzida automaticamente em **20%** para evitar sobrecarga.

### 3. Tarifação Dinâmica
O sistema calcula o preço final da recarga com base em dois fatores:

- **Horário de pico (18h–21h):** acréscimo de 20% sobre o preço base
- **Bandeira tarifária:**
  - Bandeira Verde — tarifa R$ 0,50/kWh
  - Bandeira Amarela — tarifa R$ 0,65/kWh
  - Bandeira Vermelha — tarifa R$ 0,80/kWh

### 4. Simulação de Comunicação OCPP
O sistema simula o envio de dados de cada sessão para uma plataforma externa, exibindo mensagens de envio e confirmação de recebimento para cada sessão, imitando o comportamento do protocolo OCPP.

---

## Como Executar

### Requisitos
- Compilador C (GCC recomendado)
- Terminal (Windows, Linux ou macOS)

### Compilação
```bash
gcc sprint2.c -o sprint2
```

### Execução
```bash
./sprint2
```
No Windows:
```bash
sprint2.exe
```

---

## Menu do Sistema

Ao executar o programa, o seguinte menu será exibido:

```
Menu de Opções:
1. Iniciar Sessão
2. Encerrar Sessão
3. Verificar Status
4. Tarifação Dinâmica
5. Simular Comunicação OCPP
6. Sair
```

### Opção 1 — Iniciar Sessão
Verifica se o cabo está conectado em cada sessão. Se conectado e a sessão estiver inativa, inicia a recarga. Exibe os dados de cada sessão.

### Opção 2 — Encerrar Sessão
Encerra todas as sessões ativas, atualizando o status para inativo. Exibe os dados finais de cada sessão.

### Opção 3 — Verificar Status
Executa o controle de demanda de energia automaticamente e exibe o status atual de todas as sessões, incluindo cabo conectado, status ativo/inativo e dados de recarga.

### Opção 4 — Tarifação Dinâmica
Solicita ao usuário o horário atual e a bandeira tarifária, e aplica os acréscimos correspondentes ao preço de cada sessão. Exibe o preço final de cada sessão.

### Opção 5 — Simular Comunicação OCPP
Simula o envio dos dados de cada sessão para uma plataforma externa, exibindo mensagens de envio e confirmação por sessão.

### Opção 6 — Sair
Encerra o programa.

---

## Estrutura do Código

```
sprint2.c
│
├── struct Sessao          → estrutura de dados de cada sessão
├── sessoes[3]             → array global com 3 sessões
│
├── menu()                 → exibe o menu de opções
├── controle_de_energia()  → verifica e ajusta a potência total
├── tarifacao_dinamica()   → aplica tarifação por horário e bandeira
├── simulacao_ocpp()       → simula comunicação com plataforma externa
│
└── main()                 → inicializa sessões e executa o loop do menu
```

---

## Exemplo de Uso

**Cenário: verificar status com controle de energia**

1. Execute o programa
2. Selecione a opção `3`
3. O sistema verifica automaticamente se a potência total (45 kW) está dentro do limite
4. Exibe o status de cada sessão com seus dados atuais

**Cenário: aplicar tarifação em horário de pico com bandeira vermelha**

1. Selecione a opção `4`
2. Insira o horário `19` (horário de pico)
3. Selecione a bandeira `3` (vermelha)
4. O sistema aplica 20% de acréscimo por pico + tarifa vermelha em cada sessão

---

## Conceitos de C Utilizados

- `struct` — estrutura de dados para representar cada sessão
- `array` — armazenamento das múltiplas sessões
- `for` — iteração sobre as sessões
- `if / else` — lógica condicional
- `switch` — seleção de opções do menu e bandeiras
- `do-while` — loop principal do menu
- `void` / `int` / `float` — tipos de funções e variáveis
- `printf` / `scanf` — entrada e saída de dados
