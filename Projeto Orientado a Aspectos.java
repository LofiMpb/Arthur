public class Main {
    public static void main(String[] args) {
        Conta contaCorrente = new Conta("Corrente", 1000.0);
        Conta contaSalario = new Conta("Salário", 2000.0);

        try {
            contaCorrente.realizarSaque(1200.0);
            contaSalario.realizarSaque(3000.0);
        } catch (SaldoInsuficienteException e) {
            System.out.println("Erro: " + e.getMessage());
        }
    }
}
public class Conta {
    private String tipo;
    private double saldo;

    public Conta(String tipo, double saldo) {
        this.tipo = tipo;
        this.saldo = saldo;
    }

    public double getSaldo() {
        return saldo;
    }

    public void realizarSaque(double valor) {
        if (valor > saldo) {
            throw new SaldoInsuficienteException("Saldo insuficiente na conta " + tipo);
        }
        saldo -= valor;
        System.out.println("Saque de " + valor + " realizado na conta " + tipo);
    }
}
public class SaldoInsuficienteException extends RuntimeException {
    public SaldoInsuficienteException(String mensagem) {
        super(mensagem);
    }
}
public aspect VerificacaoSaldoAspect {
    pointcut realizarSaquePointcut(Conta conta, double valor):
        execution(void Conta.realizarSaque(double)) && target(conta) && args(valor);

    before(Conta conta, double valor): realizarSaquePointcut(conta, valor) {
        if (valor > conta.getSaldo()) {
            throw new SaldoInsuficienteException("Saldo insuficiente na conta " + conta.getTipo());
        }
    }
}
