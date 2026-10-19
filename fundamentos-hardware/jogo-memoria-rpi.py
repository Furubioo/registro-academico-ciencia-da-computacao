import RPi.GPIO as GPIO            # Biblioteca para controle das portas GPIO da Raspberry Pi
import time                        # Biblioteca para controle de tempo (delays)
import random                      # Biblioteca para gerar escolhas aleatórias

# Função principal do jogo
def jogo_memoria():
    GPIO.setmode(GPIO.BCM) # Define o modo de numeração das GPIOs como BCM (número da GPIO)
    time.sleep(3) # Define 3 segundos como espera para iniciar o jogo

    # Configura os pinos dos botões como entrada com resistor de pull-down
    GPIO.setup(17, GPIO.IN, pull_up_down=GPIO.PUD_DOWN)
    GPIO.setup(27, GPIO.IN, pull_up_down=GPIO.PUD_DOWN)
    GPIO.setup(22, GPIO.IN, pull_up_down=GPIO.PUD_DOWN)

    # Define variáveis para os botões
    botaoamarelo = 17
    botaovermelho = 27
    botaoazul = 22

    # Define variáveis para os LEDs de cores e LEDs de feedback (certo/errado)
    vermelho = 18
    amarelo = 23
    azul = 24
    certo = 15
    errado = 14

    # Configura os pinos dos LEDs como saída
    GPIO.setup(vermelho, GPIO.OUT)
    GPIO.setup(amarelo, GPIO.OUT)
    GPIO.setup(azul, GPIO.OUT)
    GPIO.setup(certo, GPIO.OUT)
    GPIO.setup(errado, GPIO.OUT)

    # Gera três cores aleatórias (a sequência do jogo)
    escolha = random.choice([vermelho, amarelo, azul])
    escolha1 = random.choice([vermelho, amarelo, azul])
    escolha2 = random.choice([vermelho, amarelo, azul])

    # Garante que os LEDs de feedback estejam inicialmente apagados
    GPIO.output(errado, GPIO.LOW)
    GPIO.output(certo, GPIO.LOW)

    # Mostra a sequência gerada para o jogador, um LED por vez
    GPIO.output(escolha, GPIO.HIGH)
    time.sleep(0.5)
    GPIO.output(escolha, GPIO.LOW)
    time.sleep(0.3)

    GPIO.output(escolha1, GPIO.HIGH)
    time.sleep(0.5)
    GPIO.output(escolha1, GPIO.LOW)
    time.sleep(0.3)

    GPIO.output(escolha2, GPIO.HIGH)
    time.sleep(0.5)
    GPIO.output(escolha2, GPIO.LOW)
    time.sleep(0.3)

    cont = 0  # Contador de acertos do jogador

    # Verifica se o primeiro botão pressionado corresponde à primeira cor da sequência
    while True:
        if GPIO.input(botaoamarelo) == GPIO.HIGH:
            if escolha == amarelo:
                GPIO.output(amarelo, GPIO.HIGH)
                time.sleep(0.5)
                GPIO.output(amarelo, GPIO.LOW)
                cont += 1
            while GPIO.input(botaoamarelo) == GPIO.HIGH:
                time.sleep(0.5)
            break
        elif GPIO.input(botaovermelho) == GPIO.HIGH:
            if escolha == vermelho:
                GPIO.output(vermelho, GPIO.HIGH)
                time.sleep(0.5)
                GPIO.output(vermelho, GPIO.LOW)
                cont += 1
            while GPIO.input(botaovermelho) == GPIO.HIGH:
                time.sleep(0.5)
            break
        elif GPIO.input(botaoazul) == GPIO.HIGH:
            if escolha == azul:
                GPIO.output(azul, GPIO.HIGH)
                time.sleep(0.5)
                GPIO.output(azul, GPIO.LOW)
                cont += 1
            while GPIO.input(botaoazul) == GPIO.HIGH:
                time.sleep(0.5)
            break

    # Se acertou a primeira cor, verifica a segunda entrada do jogador
    if cont == 1:
        while True:
            if GPIO.input(botaoamarelo) == GPIO.HIGH:
                if escolha1 == amarelo:
                    GPIO.output(amarelo, GPIO.HIGH)
                    time.sleep(0.5)
                    GPIO.output(amarelo, GPIO.LOW)
                    cont += 1
                while GPIO.input(botaoamarelo) == GPIO.HIGH:
                    time.sleep(0.5)
                break
            elif GPIO.input(botaovermelho) == GPIO.HIGH:
                if escolha1 == vermelho:
                    GPIO.output(vermelho, GPIO.HIGH)
                    time.sleep(0.5)
                    GPIO.output(vermelho, GPIO.LOW)
                    cont += 1
                while GPIO.input(botaovermelho) == GPIO.HIGH:
                    time.sleep(0.5)
                break
            elif GPIO.input(botaoazul) == GPIO.HIGH:
                if escolha1 == azul:
                    GPIO.output(azul, GPIO.HIGH)
                    time.sleep(0.5)
                    GPIO.output(azul, GPIO.LOW)
                    cont += 1
                while GPIO.input(botaoazul) == GPIO.HIGH:
                    time.sleep(0.5)
                break

    # Se acertou as duas primeiras cores, verifica a terceira entrada do jogador
    if cont == 2:
        while True:
            if GPIO.input(botaoamarelo) == GPIO.HIGH:
                if escolha2 == amarelo:
                    GPIO.output(amarelo, GPIO.HIGH)
                    time.sleep(0.5)
                    GPIO.output(amarelo, GPIO.LOW)
                    cont += 1
                while GPIO.input(botaoamarelo) == GPIO.HIGH:
                    time.sleep(0.5)
                break
            elif GPIO.input(botaovermelho) == GPIO.HIGH:
                if escolha2 == vermelho:
                    GPIO.output(vermelho, GPIO.HIGH)
                    time.sleep(0.5)
                    GPIO.output(vermelho, GPIO.LOW)
                    cont += 1
                while GPIO.input(botaovermelho) == GPIO.HIGH:
                    time.sleep(0.5)
                break
            elif GPIO.input(botaoazul) == GPIO.HIGH:
                if escolha2 == azul:
                    GPIO.output(azul, GPIO.HIGH)
                    time.sleep(0.5)
                    GPIO.output(azul, GPIO.LOW)
                    cont += 1
                while GPIO.input(botaoazul) == GPIO.HIGH:
                    time.sleep(0.5)
                break

    # Verifica o número total de acertos para decidir qual LED de feedback acender
    if cont == 3:
        GPIO.output(certo, GPIO.HIGH)  # Todos os botões corretos
    else:
        GPIO.output(errado, GPIO.HIGH)  # Houve erro em alguma etapa

    time.sleep(2)  # Espera 2 segundos para o jogador visualizar o resultado
    GPIO.cleanup()  # Limpa a configuração dos pinos GPIO

# Loop principal: reinicia o jogo continuamente
while True:
    jogo_memoria()