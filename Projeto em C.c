
// Definição da estrutura para representar uma conta bancária

typedef struct {
    char tipo[20]; // Tipo da conta (corrente, salário, poupança, investimento)
    double saldo;  // Saldo disponível na conta
} ContaBancaria;

// Função para realizar um saque em uma conta
void realizarSaque(ContaBancaria *conta, double valor) {
    if (conta->saldo >= valor) {
        conta->saldo -= valor;
        printf("Saque de %.2f realizado com sucesso na conta %s.\n", valor, conta->tipo);
    } else {
        printf("Saldo insuficiente na conta %s para realizar o saque de %.2f.\n", conta->tipo, valor);
    }
}

// Aspecto para a verificação de saldo em todas as contas antes de realizar o saque
#define VERIFICAR_SALDO(conta, valor) \
    if (conta->saldo < valor) {        \
        printf("Saldo insuficiente na conta %s para realizar o saque de %.2f.\n", conta->tipo, valor); \
        return; \
    }

int main() {
    // Criando instâncias de contas bancárias
    ContaBancaria contaCorrente = {"Corrente", 1000.0};
    ContaBancaria contaSalario = {"Salário", 1500.0};
    ContaBancaria contaPoupanca = {"Poupança", 2000.0};
    ContaBancaria contaInvestimento = {"Investimento", 5000.0};

    // Realizando saques nas contas
    realizarSaque(&contaCorrente, 800.0);
    realizarSaque(&contaSalario, 2000.0);
    realizarSaque(&contaPoupanca, 1500.0);
    realizarSaque(&contaInvestimento, 7000.0);

    return 0;
}
