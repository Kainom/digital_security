# Questões: Princípios e Fundamentos da Criptografia

> [!info] Como usar
> Escreva sua resposta no espaço **Sua resposta**. O gabarito fica **oculto**: clique em **Gabarito** para expandir **só depois de responder**. Depois peça ao agente para corrigir.
> Resumo de apoio: [[04-principios-da-criptografia]]

---

## Questão 1 (Discursiva)
Diferencie **criptografia**, **criptoanálise** e **criptologia**.

**Sua resposta:**


> [!success]- Gabarito
> - **Criptografia:** do grego "escrita secreta", a arte e ciência de **ocultar significado** [BIS], ou de **projetar cifras** [AND].
> - **Criptoanálise:** a **quebra** de códigos/cifras [BIS][AND].
> - **Criptologia:** o **estudo de ambas** [AND].
> 📚 *Fonte: [BIS] §10.1 · [AND] §5.1*

---

## Questão 2 (Discursiva)
Segundo Bishop, quais **serviços** a criptografia fornece e quais **ameaças** cada um combate?

**Sua resposta:**


> [!success]- Gabarito
> - **Sigilo** (objetivo principal: manter a informação cifrada secreta) → combate a **divulgação**.
> - **Integridade de dados e de origem** → combate a **modificação** e o **mascaramento**.
> - **Não repúdio** → combate o **repúdio de origem**.
> 📚 *Fonte: [BIS] §10.1*

---

## Questão 3 (Discursiva)
Enuncie o **princípio de Kerckhoffs** e relacione-o com o princípio de projeto **"projeto aberto" (*open design*)** de Stallings.

**Sua resposta:**


> [!success]- Gabarito
> - **Kerckhoffs:** a segurança de um criptossistema **não pode depender de o adversário desconhecer os algoritmos** de cifragem e decifragem. Supõe-se que o adversário conhece **E, D e o conjunto de chaves K**, mas **não a chave específica** [BIS].
> - **Projeto aberto:** o projeto de um mecanismo de segurança deve ser **aberto, e não secreto**. As **chaves** devem ser secretas, mas os **algoritmos** devem estar abertos ao escrutínio público, para que muitos especialistas os revisem e os usuários confiem neles. É a filosofia da padronização do NIST [STA].
> - **Relação:** os dois dizem que **o segredo deve estar na chave, não no algoritmo**.
> 📚 *Fonte: [BIS] §10.1.1 · [STA] §1.4*

---

## Questão 4 (Múltipla escolha)
Um adversário consegue que o sistema cifre mensagens que **ele mesmo escolhe** e recebe os textos cifrados, tentando descobrir a chave. Esse é o ataque de:

a) só texto cifrado
b) texto claro conhecido
c) texto claro escolhido
d) força bruta
e) dicionário

**Sua resposta:**


> [!success]- Gabarito
> **c) Texto claro escolhido.** Os três tipos de Bishop:
> - **só texto cifrado:** tem só o texto cifrado;
> - **texto claro conhecido:** tem o texto cifrado e o texto claro correspondente;
> - **texto claro escolhido:** pode pedir a cifragem de textos específicos.
>
> "Um bom criptossistema protege contra os três."
> 📚 *Fonte: [BIS] §10.1.1*

---

## Questão 5 (Discursiva)
Explique os conceitos de **confusão** e **difusão**.

**Sua resposta:**


> [!success]- Gabarito
> - **Confusão:** **substitui** partes do texto claro por outros dados, para esconder o conteúdo original.
> - **Difusão:** **embaralha** o texto claro para que o conteúdo original se **espalhe** por toda a mensagem.
>
> As duas aumentam a dificuldade de recuperar o texto claro. Bishop resume que todos os criptossistemas se baseiam em **substituição e permutação**.
> 📚 *Fonte: [BIS] §10.1 e §10.6*

---

## Questão 6 (Discursiva)
Quais são os **cinco ingredientes** de um esquema de cifragem simétrica e os **dois requisitos** para seu uso seguro?

**Sua resposta:**


> [!success]- Gabarito
> **Ingredientes:** (1) texto claro; (2) algoritmo de cifragem (substituições e transformações); (3) **chave secreta**; (4) texto cifrado (depende do texto claro e da chave); (5) algoritmo de decifragem (a cifragem "ao contrário").
> **Requisitos:** (1) **algoritmo forte**, de modo que o oponente que conhece o algoritmo e tem textos cifrados (até pares claro-cifrado) não consiga decifrar nem achar a chave; (2) emissor e receptor devem **obter a chave de forma segura e mantê-la segura**.
> 📚 *Fonte: [STA] §2.1*

---

## Questão 7 (Discursiva)
Diferencie **criptoanálise** e **força bruta** como abordagens de ataque a cifras simétricas. Em média, quantas chaves a força bruta precisa testar?

**Sua resposta:**


> [!success]- Gabarito
> - **Criptoanálise:** explora a **natureza do algoritmo** e algum conhecimento sobre o texto claro (ou pares claro-cifrado) para deduzir o texto ou a chave. Se deduzir a chave, **todas as mensagens passadas e futuras** cifradas com ela ficam comprometidas.
> - **Força bruta:** testa **todas as chaves possíveis** até obter texto inteligível. Em média, **metade das chaves** (x/2 para x chaves). É preciso saber **reconhecer o texto claro**, o que fica difícil se ele estiver comprimido.
> 📚 *Fonte: [STA] §2.1*

---

## Questão 8 (Múltipla escolha)
Sobre **cifras de transposição** e **de substituição**, é correto afirmar:

a) A transposição altera as letras, mas mantém a ordem.
b) A cifra de César é uma cifra de transposição.
c) A transposição reordena os caracteres sem alterá-los e, por isso, preserva a frequência das letras.
d) A substituição monoalfabética esconde as estatísticas do texto claro.
e) A cifra *rail fence* é uma cifra de substituição.

**Sua resposta:**


> [!success]- Gabarito
> **c)** A transposição **rearranja** os caracteres (as letras não mudam), então a frequência das letras (1-grama) se mantém, o que ajuda a detectá-la. César é **substituição**; a substituição monoalfabética **preserva** as estatísticas; *rail fence* é **transposição**.
> 📚 *Fonte: [BIS] §10.2.1, §10.2.2*

---

## Questão 9 (Discursiva)
Na criptografia de chave pública, explique os **dois modos de uso** do par de chaves e qual serviço cada um fornece.

**Sua resposta:**


> [!success]- Gabarito
> 1. **Cifrar com a chave pública do destinatário** (Bob cifra com a pública de Alice; só Alice decifra com a privada dela) → **confidencialidade**.
> 2. **Cifrar com a própria chave privada** (qualquer um decifra com a pública do emissor) → **autenticação e/ou integridade**: só o dono da privada poderia ter cifrado e ninguém mais pode modificar. **Não dá sigilo.**
> 📚 *Fonte: [STA] §2.3 (Fig. 2.6)*

---

## Questão 10 (Discursiva)
Stallings aponta **três equívocos comuns** sobre criptografia de chave pública. Quais são e por que são falsos?

**Sua resposta:**


> [!success]- Gabarito
> 1. **"É mais segura contra criptoanálise que a simétrica."** Falso: a segurança depende do **tamanho da chave** e do **trabalho computacional** para quebrar, não do tipo de cifra.
> 2. **"Tornou a simétrica obsoleta."** Falso: pelo **custo computacional** da chave pública, a simétrica não será abandonada.
> 3. **"A distribuição de chaves é trivial."** Falso: ainda exige **protocolo**, muitas vezes com um **agente central**, e não é mais simples nem mais eficiente.
> 📚 *Fonte: [STA] §2.3*

---

## Questão 11 (Discursiva)
Quais condições um criptossistema de chave pública precisa cumprir, segundo Bishop?

**Sua resposta:**


> [!success]- Gabarito
> 1. Ser **computacionalmente fácil** cifrar ou decifrar com a chave apropriada.
> 2. Ser **computacionalmente inviável derivar a chave privada a partir da pública**.
> 3. Ser **computacionalmente inviável determinar a chave privada por meio de um ataque de texto claro escolhido**.
> 📚 *Fonte: [BIS] §10.3*

---

## Questão 12 (Múltipla escolha)
Segundo a Tabela 2.3 de Stallings, qual algoritmo serve **apenas** para troca/acordo de chaves simétricas?

a) RSA
b) DSS
c) Diffie-Hellman
d) Curvas elípticas
e) AES

**Sua resposta:**


> [!success]- Gabarito
> **c) Diffie-Hellman.** Seu propósito é permitir que duas partes **concordem sobre um segredo compartilhado**. O **DSS** serve só para **assinatura**. **RSA** e **ECC** servem para os três usos. O AES é simétrico.
> 📚 *Fonte: [STA] §2.3 (Tab. 2.3)*

---

## Questão 13 (Discursiva)
Explique o **envelope digital**: qual problema ele resolve e como funciona?

**Sua resposta:**


> [!success]- Gabarito
> **Problema:** mandar uma mensagem confidencial **sem que emissor e receptor já compartilhem uma chave simétrica**.
> **Funcionamento:** (1) prepara-se a mensagem; (2) gera-se uma **chave simétrica aleatória de uso único**; (3) cifra-se a mensagem com essa chave; (4) cifra-se a chave com a **chave pública do destinatário**; (5) envia-se a chave cifrada junto com a mensagem cifrada. Só o destinatário recupera a chave e, com ela, a mensagem. Se a chave pública veio de um **certificado**, há garantia de que é válida.
> 📚 *Fonte: [STA] §2.4*

---

## Questão 14 (Discursiva)
Por que o *one-time pad* tem **sigilo perfeito**? Qual é o "preço" desse sigilo?

**Sua resposta:**


> [!success]- Gabarito
> A chave é **tão longa quanto a mensagem e nunca se repete**. Para qualquer texto cifrado e qualquer texto claro de mesmo tamanho existe uma chave que leva de um ao outro, então **todos os textos claros são igualmente prováveis** e o oponente não ganha nada, qualquer que seja seu poder computacional. **Preço:** ele **falha completamente em proteger a integridade** da mensagem (o texto cifrado pode ser alterado para mudar o significado).
> 📚 *Fonte: [AND] §5.2.2*

---

## Questão 15 (Discursiva)
Um criptógrafo afirmou que a criptografia pode fornecer **segurança completa**, dispensando qualquer outro controle. Por que ele está errado?

**Sua resposta:**


> [!success]- Gabarito
> A criptografia depende de uma **chave**, que **vira mais um dado a ser protegido**. Se alguém ler a chave quando ela é digitada, ou tiver acesso ao local onde está guardada, a proteção cai, e a criptografia **não protege a própria implementação** (armazenamento, entrada e gestão das chaves). Além disso, os mecanismos dependem de **serviços de suporte do sistema** (kernel etc.). Por isso é preciso combinar criptografia com outros controles (controle de acesso, proteção física etc.).
> 📚 *Fonte: [BIS] §1.1.1 e §10.9 (exercício 1)*
