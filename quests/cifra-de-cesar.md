# Questões: Cifra de César (teoria + prática)

> [!info] Como usar
> Escreva sua resposta no espaço **Sua resposta**. O gabarito fica **oculto**: clique em **Gabarito** para expandir **só depois de responder**. Depois peça ao agente para corrigir.
> Resumo de apoio: [[03-cifra-de-cesar]]
>
> **Convenção das questões práticas:** alfabeto de 26 letras, **A = 0 … Z = 25**, sem acentos nem Ç, **espaços mantidos**.
> **Cifrar:** c = (m + k) mod 26 · **Decifrar:** m = (c − k) mod 26

**Tabela de apoio**

| A | B | C | D | E | F | G | H | I | J | K | L | M | N | O | P | Q | R | S | T | U | V | W | X | Y | Z |
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
| 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15 | 16 | 17 | 18 | 19 | 20 | 21 | 22 | 23 | 24 | 25 |

---

## Parte A: Teoria

## Questão 1 (Discursiva)
Descreva a origem histórica da cifra de César e explique por que ela também é chamada de **cifra de deslocamento**. O que Augusto César mudou no sistema?

**Sua resposta:**


> [!success]- Gabarito
> Júlio César cifrava suas comunicações confidenciais (despachos para aliados em Roma) **deslocando cada letra 3 posições**: 'A' virava 'D', 'B' virava 'E'… e 'Z' virava 'C'. Como a cifragem é um **deslocamento** fixo do alfabeto, ela se chama cifra de deslocamento (*shift cipher*). **Augusto** passou a escrever **'C' no lugar de 'A'** (deslocamento 2). Em termos modernos, ele **trocou a chave de 'D' para 'C'**.
> 📚 *Fonte: [BIS] §10.1 · [AND] §5.2*

---

## Questão 2 (Discursiva)
Usando a definição de criptossistema de Bishop (quíntupla E, D, M, K, C), formalize a cifra de César.

**Sua resposta:**


> [!success]- Gabarito
> - **M** = todas as sequências de letras (romanas);
> - **K** = { i : i inteiro, 0 ≤ i ≤ 25 }, ou seja, 26 chaves;
> - **E** = { E_k : E_k(mᵢ) = (mᵢ + k) mod 26 };
> - **D** = { D_k : D_k(cᵢ) = (cᵢ − k) mod 26 }, pois cada D_k inverte E_k;
> - **C = M**, porque E é formado por funções sobrejetoras.
> 📚 *Fonte: [BIS] §10.1*

---

## Questão 3 (Múltipla escolha)
A cifra de César é classificada como:

a) assimétrica, de transposição e polialfabética
b) simétrica, de substituição e monoalfabética
c) simétrica, de transposição e monoalfabética
d) assimétrica, de substituição e monoalfabética
e) simétrica, de substituição e polialfabética

**Sua resposta:**


> [!success]- Gabarito
> **b)**
> - **Simétrica:** a mesma chave (ex.: 3) cifra (E₃) e decifra (D₃).
> - **Substituição:** troca letras, não apenas as reordena.
> - **Monoalfabética:** usa um único alfabeto de substituição.
> 📚 *Fonte: [BIS] §10.2, §10.2.2, §10.2.2.1*

---

## Questão 4 (Discursiva)
Em uma cifra de César com chave k, a chave de decifragem pode ser vista como **26 − k**, diferente da de cifragem. Uma característica dos sistemas de chave pública é ter chaves de cifrar e decifrar diferentes. **Por que, então, a César é um criptossistema clássico e não de chave pública?** Seja específico.

**Sua resposta:**


> [!success]- Gabarito
> Em chave pública, é preciso que seja **computacionalmente inviável derivar a chave privada da chave pública**. Na César, quem conhece k calcula **26 − k imediatamente**: as duas chaves são **equivalentes**. Se uma fosse "pública", a outra estaria automaticamente revelada. Por isso **ambas precisam ser mantidas secretas**, e o sistema é simétrico (clássico).
> 📚 *Fonte: [BIS] §10.9 (exercício 5) e §10.3 · [STA] §2.3*

---

## Questão 5 (Discursiva)
Por que a cifra de César é **insegura**? Explique pelo menos **dois** ataques possíveis.

**Sua resposta:**


> [!success]- Gabarito
> 1. **Força bruta:** existem apenas **26 chaves** (0 a 25). Em média testa-se **metade das chaves**, cerca de **13** tentativas, até aparecer um texto legível [STA][BIS].
> 2. **Análise estatística/frequência (só texto cifrado):** por ser **monoalfabética**, a César **preserva as estatísticas** do texto claro. Comparando as frequências das letras do texto cifrado com um modelo da língua, as chaves mais prováveis aparecem primeiro. No exemplo "KHOOR ZRUOG", a chave correta (3) apareceu na **3ª tentativa** [BIS].
> 3. **Texto claro conhecido:** basta **um par** letra clara/cifrada para obter k = (c − m) mod 26.
> 📚 *Fonte: [BIS] §10.2.2 · [STA] §2.1*

---

## Questão 6 (Discursiva)
No exemplo de Bishop, a análise de frequência de "KHOOR ZRUOG" indicou as chaves na ordem **6, 10, 3, 14**, mas a chave correta era 3. O que isso ensina sobre o ataque estatístico?

**Sua resposta:**


> [!success]- Gabarito
> O ataque é **estatístico**: ele não entrega a resposta certa diretamente, apenas **ordena as chaves por probabilidade** e **reduz o número de tentativas**. O atacante ainda precisa **testar** cada chave e verificar se o resultado é legível. Aqui foram **3 tentativas**, contra as ~13 esperadas testando em ordem. (Textos curtos distorcem a estatística.)
> 📚 *Fonte: [BIS] §10.2.2*

---

## Questão 7 (Discursiva)
Explique como um atacante com um ataque de **texto claro escolhido** descobre a chave de uma cifra de César com **uma única letra**.

**Sua resposta:**


> [!success]- Gabarito
> No ataque de texto claro escolhido, o adversário pode pedir a cifragem de textos que ele escolhe. Se ele pedir a cifragem de **"A" (m = 0)**, recebe c = (0 + k) mod 26 = **k**: a letra devolvida **é a própria chave**. Ex.: devolveu "D" → k = 3.
> 📚 *Fonte: [BIS] §10.1.1 (tipos de ataque) · [BIS] §10.1 (fórmula)*

---

## Questão 8 (Discursiva)
Para que valores de k a chave de **cifrar** é igual à de **decifrar** (ou seja, k = 26 − k mod 26)? O que acontece se cifrarmos duas vezes com esse k?

**Sua resposta:**


> [!success]- Gabarito
> k = 26 − k ⇒ 2k = 26 ⇒ **k = 13** (além do caso trivial k = 0, que não altera nada). Com k = 13, **cifrar duas vezes devolve o texto original**, porque 13 + 13 = 26 ≡ 0 (mod 26).
> Ex.: `CHAVE SECRETA` → `PUNIR FRPERGN` → `CHAVE SECRETA`.
> 📚 *Fonte: dedução a partir de [BIS] §10.1 e §10.9 (chave de decifragem 26 − k)*

---

## Parte B: Prática (cifrar)

## Questão 9 (Prática)
Cifre **`SEGURANCA DIGITAL`** com **k = 3**.

**Sua resposta:**


> [!success]- Gabarito
> | S | E | G | U | R | A | N | C | A | | D | I | G | I | T | A | L |
> |---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
> | 18 | 4 | 6 | 20 | 17 | 0 | 13 | 2 | 0 | | 3 | 8 | 6 | 8 | 19 | 0 | 11 |
> | 21 | 7 | 9 | 23 | 20 | 3 | 16 | 5 | 3 | | 6 | 11 | 9 | 11 | 22 | 3 | 14 |
> | V | H | J | X | U | D | Q | F | D | | G | L | J | L | W | D | O |
>
> **Resposta: `VHJXUDQFD GLJLWDO`**
> 📚 *Fonte: método de [BIS] §10.1*

---

## Questão 10 (Prática)
Cifre **`ROMA`** usando a chave de **Augusto César**.

**Sua resposta:**


> [!success]- Gabarito
> Chave de Augusto: 'C' no lugar de 'A', ou seja, **k = 2**.
> R(17) → 19 = T · O(14) → 16 = Q · M(12) → 14 = O · A(0) → 2 = C
> **Resposta: `TQOC`**
> 📚 *Fonte: [AND] §5.2 · [BIS] §10.1*

---

## Questão 11 (Prática, "volta" no alfabeto)
Cifre **`ZEBRA`** com **k = 1** e **`XYZ`** com **k = 3**.

**Sua resposta:**


> [!success]- Gabarito
> - `ZEBRA`, k = 1: Z(25) + 1 = 26 → 26 mod 26 = **0 = A**; E→F; B→C; R→S; A→B → **`AFCSB`**
> - `XYZ`, k = 3: 23+3 = 26 → 0 = A; 24+3 = 27 → 1 = B; 25+3 = 28 → 2 = C → **`ABC`**
> 📚 *Fonte: [BIS] §10.1 ("ending with 'Z' becoming 'C'")*

---

## Questão 12 (Prática)
Cifre **`CONFIDENCIALIDADE`** com **k = 5**.

**Sua resposta:**


> [!success]- Gabarito
> C→H, O→T, N→S, F→K, I→N, D→I, E→J, N→S, C→H, I→N, A→F, L→Q, I→N, D→I, A→F, D→I, E→J
> **Resposta: `HTSKNIJSHNFQNIFIJ`**
> 📚 *Fonte: método de [BIS] §10.1*

---

## Parte C: Prática (decifrar com chave)

## Questão 13 (Prática)
Decifre **`KHOOR ZRUOG`** sabendo que **k = 3**.

**Sua resposta:**


> [!success]- Gabarito
> K(10)−3 = 7 H · H(7)−3 = 4 E · O(14)−3 = 11 L · O → L · R(17)−3 = 14 O · Z(25)−3 = 22 W · R → O · U(20)−3 = 17 R · O → L · G(6)−3 = 3 D
> **Resposta: `HELLO WORLD`**
> 📚 *Fonte: [BIS] §10.1 e §10.2.2*

---

## Questão 14 (Prática)
Decifre **`DWDTXH DR DPDQKHFHU`** com **k = 3**.

**Sua resposta:**


> [!success]- Gabarito
> D→A, W→T, D→A, T→Q, X→U, H→E · D→A, R→O · D→A, P→M, D→A, Q→N, K→H, H→E, F→C, H→E, U→R
> **Resposta: `ATAQUE AO AMANHECER`**
> 📚 *Fonte: método de [BIS] §10.1*

---

## Questão 15 (Prática, atenção a negativos)
Decifre **`PUALNYPKHKL`** com **k = 7**.

**Sua resposta:**


> [!success]- Gabarito
> | P | U | A | L | N | Y | P | K | H | K | L |
> |---|---|---|---|---|---|---|---|---|---|---|
> | 15 | 20 | 0 | 11 | 13 | 24 | 15 | 10 | 7 | 10 | 11 |
> | 8 | 13 | **−7 → 19** | 4 | 6 | 17 | 8 | 3 | 0 | 3 | 4 |
> | I | N | T | E | G | R | I | D | A | D | E |
>
> Em A(0) − 7 = −7, soma-se 26: −7 + 26 = 19 = T.
> **Resposta: `INTEGRIDADE`**
> 📚 *Fonte: [BIS] §10.1 (D_k(c) = (26 + c − k) mod 26)*

---

## Questão 16 (Prática)
Decifre **`NSCZYXSLSVSNKNO`** com **k = 10**.

**Sua resposta:**


> [!success]- Gabarito
> N(13)→3 D · S(18)→8 I · C(2)→−8+26 = 18 S · Z(25)→15 P · Y(24)→14 O · X(23)→13 N · S→I · L(11)→1 B · S→I · V(21)→11 L · S→I · N→D · K(10)→0 A · N→D · O(14)→4 E
> **Resposta: `DISPONIBILIDADE`**
> 📚 *Fonte: método de [BIS] §10.1*

---

## Parte D: Prática (sem a chave, criptoanálise)

## Questão 17 (Prática, texto claro conhecido)
Você interceptou **`VXUBG ZKUXOIG`** e sabe que a mensagem começa com a palavra **PROVA**. Descubra a chave e decifre a mensagem inteira. Que tipo de ataque é este?

**Sua resposta:**


> [!success]- Gabarito
> P(15) → V(21) ⇒ k = 21 − 15 = **6** (confira: R(17) → X(23), 23 − 17 = 6 ✓).
> Decifrando com k = 6: **`PROVA TEORICA`**.
> É um ataque de **texto claro conhecido**: o adversário tem texto cifrado e o texto claro correspondente, e quer a chave.
> 📚 *Fonte: [BIS] §10.1.1*

---

## Questão 18 (Prática, força bruta)
Decifre **`WIRLE JSVXI`** sem conhecer a chave, testando as chaves em ordem (k = 1, 2, 3…). Mostre as tentativas até achar o texto legível.

**Sua resposta:**


> [!success]- Gabarito
> | k | Resultado |
> |---|---|
> | 1 | VHQKD IRUWH |
> | 2 | UGPJC HQTVG |
> | 3 | TFOIB GPSUF |
> | **4** | **SENHA FORTE** ✅ |
>
> **Chave k = 4 → `SENHA FORTE`.** Isso é **força bruta**: testar chaves até obter um texto claro reconhecível. O analista precisa **reconhecer** o texto claro [STA].
> 📚 *Fonte: [STA] §2.1 · [BIS] §10.2.2*

---

## Questão 19 (Prática, exercício do livro de Bishop)
Decifre o texto abaixo, cifrado com uma cifra de César (exercício 2 do cap. 10 de Bishop):
**`TEBKFKQEBZLROPBLCERJXKBSBKQP`**

**Sua resposta:**


> [!success]- Gabarito
> Testando as chaves, a legível é **k = 23** (equivale a deslocar cada letra **3 posições para trás** na cifragem). Para decifrar, desloca-se **3 para frente**: T→W, E→H, B→E, K→N…
> **Resposta: `WHENINTHECOURSEOFHUMANEVENTS`**, "When in the course of human events".
> Lição: **k = 23 é equivalente a um deslocamento de −3**. Deslocar para trás também é uma cifra de César.
> 📚 *Fonte: [BIS] §10.9 (exercício 2)*

---

## Questão 20 (Prática, ida e volta)
a) Cifre **`CRIPTOGRAFIA`** com **k = 8**.
b) Qual chave, aplicada **como cifragem** (somando), desfaz o resultado? Mostre que funciona.

**Sua resposta:**


> [!success]- Gabarito
> a) C→K, R→Z, I→Q, P→X, T→B, O→W, G→O, R→Z, A→I, F→N, I→Q, A→I → **`KZQXBWOZINQI`**
> b) **26 − 8 = 18.** Somar 18 é o mesmo que subtrair 8 (mod 26). Ex.: K(10) + 18 = 28 → 2 = C ✓; Z(25) + 18 = 43 → 17 = R ✓. Resultado: **`CRIPTOGRAFIA`**.
> 📚 *Fonte: [BIS] §10.1 e §10.9 (chave de decifragem 26 − k)*
