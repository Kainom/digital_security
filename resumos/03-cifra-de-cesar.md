# Cifra de César (cifra de deslocamento)

> Fontes: [BIS] §10.1, §10.1.1, §10.2, §10.2.2, §10.9 (exercícios) · [AND] §5.2, §5.2.1 · [STA] §2.1

## 1. Histórico

- **Júlio César** cifrava seus despachos escrevendo **'D' no lugar de 'A'**, 'E' no lugar de 'B', e assim por diante, ou seja, **deslocamento de 3** (relato de Suetônio) [AND §5.2].
- Bishop: no fim da República Romana, César usou a cifra para se comunicar com aliados secretos em Roma. As letras são deslocadas em 3, por isso ela se chama **cifra de deslocamento (*shift cipher*) ou cifra de César** [BIS §10.1].
- **Augusto César** mudou o sistema: **'C' no lugar de 'A'** (deslocamento de 2). Em termos modernos, ele **trocou a chave de 'D' para 'C'** [AND].
- **Bernardo Provenzano** (suposto chefe da máfia siciliana) usava um código parecido ('4' para 'a', '5' para 'b'...). As mensagens foram interceptadas e decifradas, e ele foi **preso em 2006** [AND].
- O **worm da Internet (Morris, 1988)** cifrava suas strings de dados com uma cifra de César [AND].
- Stallings cita Júlio César como exemplo de uso histórico de **cifragem simétrica** [STA §2.1].

---

## 2. Formalização (Bishop, criptossistema de 5 elementos)

Numeramos as letras: **A = 0, B = 1, …, Z = 25**.

| Elemento | Na cifra de César |
|---|---|
| **M** (textos claros) | todas as sequências de letras romanas |
| **K** (chaves) | { i : i inteiro, **0 ≤ i ≤ 25** }, ou seja, **26 chaves** |
| **E** (cifrar) | **E_k(m) = (m + k) mod 26** |
| **D** (decifrar) | **D_k(c) = (c − k) mod 26** = (26 + c − k) mod 26 |
| **C** (textos cifrados) | **C = M** (E é uma função sobrejetora) |

- Cada D_k simplesmente **inverte** o E_k correspondente [BIS].
- A **chave de decifragem** também pode ser vista como **26 − k** (aplicar deslocamento 26 − k "para frente" desfaz o deslocamento k) [BIS §10.9, ex. 5].

### Tabela de apoio (para fazer à mão)

| A | B | C | D | E | F | G | H | I | J | K | L | M |
|---|---|---|---|---|---|---|---|---|---|---|---|---|
| 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 |

| N | O | P | Q | R | S | T | U | V | W | X | Y | Z |
|---|---|---|---|---|---|---|---|---|---|---|---|---|
| 13 | 14 | 15 | 16 | 17 | 18 | 19 | 20 | 21 | 22 | 23 | 24 | 25 |

**Alfabeto com k = 3** (o de Júlio César):
```
Claro : A B C D E F G H I J K L M N O P Q R S T U V W X Y Z
Cifra : D E F G H I J K L M N O P Q R S T U V W X Y Z A B C
```

---

## 3. Passo a passo

### Cifrar "HELLO" com k = 3 (exemplo do [BIS])
| Letra | H | E | L | L | O |
|---|---|---|---|---|---|
| m | 7 | 4 | 11 | 11 | 14 |
| m + 3 | 10 | 7 | 14 | 14 | 17 |
| mod 26 | 10 | 7 | 14 | 14 | 17 |
| Cifra | **K** | **H** | **O** | **O** | **R** |

→ **HELLO → KHOOR**

### "Dar a volta" no alfabeto (mod 26)
- **X Y Z** com k = 3: 23+3 = 26 → 0 = **A**; 24+3 = 27 → 1 = **B**; 25+3 = 28 → 2 = **C** → **ABC**.
- Bishop: *"…terminando com 'Z' virando 'C'"*.

### Decifrar "KHOOR ZRUOG" com k = 3
- K(10) − 3 = 7 = H; H(7) − 3 = 4 = E; O(14) − 3 = 11 = L …
- **KHOOR ZRUOG → HELLO WORLD** [BIS]
- Se o resultado for negativo, some 26. Ex.: **A** (0) − 3 = −3 → −3 + 26 = 23 = **X**.

### Convenções para mensagens em português
Os livros usam o alfabeto de **26 letras**. Então **remova acentos e o Ç** (Ç → C, Ã → A), mantenha os **espaços** como estão (como em "KHOOR ZRUOG") e trabalhe em **maiúsculas**.

Exemplos (k = 3):
- `SEGURANCA DIGITAL` → `VHJXUDQFD GLJLWDO`
- `ATAQUE AO AMANHECER` → `DWDTXH DR DPDQKHFHU`
- `CESAR` → `FHVDU`

---

## 4. Classificação da cifra de César

| Característica | Por quê |
|---|---|
| **Simétrica** (clássica, de chave secreta) | A mesma chave (3) cifra (E₃) e decifra (D₃) [BIS §10.2] |
| **De substituição** | Troca cada letra por outra. Não é de **transposição**, que só reordena [BIS §10.2.2] |
| **Monoalfabética** | Usa **um único alfabeto** de substituição e **preserva a estatística** do texto claro [BIS §10.2.2.1] |
| Caso particular da **Vigenère** | Vigenère = chave repetida. César = chave fixa de uma letra ('D' para Júlio, 'C' para Augusto) [AND §5.2.1] |

### Por que NÃO é criptografia de chave pública? ([BIS] exercício 5)
Mesmo que a chave de decifragem (26 − k) seja "diferente" da de cifragem (k):
- em chave pública, precisa ser **computacionalmente inviável derivar a chave privada da pública** [BIS §10.3][STA §2.3];
- na César, quem sabe k calcula **26 − k instantaneamente**. As duas chaves são **equivalentes**, então **ambas precisam ser secretas**. Por isso ela é um sistema **clássico (simétrico)**.

---

## 5. Criptoanálise: por que a César é fraca

### 5.1 Força bruta (busca exaustiva de chave)
- Existem só **26 chaves** (na prática 25 úteis, porque k = 0 não altera nada).
- Stallings: na força bruta, **em média metade das chaves** precisa ser testada (com *x* chaves, ~*x/2* tentativas). Para a César, isso dá cerca de **13** tentativas, número que Bishop também cita.
- Para a força bruta funcionar, o analista precisa **reconhecer o texto claro** quando ele aparece [STA].

### 5.2 Ataque estatístico (frequência), só com o texto cifrado
- *"A cifra de deslocamento é suscetível a um ataque estatístico usando apenas o texto cifrado"* [BIS].
- Por ser **monoalfabética**, a César **preserva a frequência** das letras. Em inglês as mais comuns são **e, t, a, i, o, n, s, h, r, d, l, u** [AND].
- Exemplo de Bishop com "KHOOR ZRUOG": correlacionando as frequências do texto cifrado com o modelo de inglês (1-grama), as chaves mais prováveis foram **6, 10, 3, 14**. A chave certa (3) veio **na 3ª tentativa**, contra ~13 testando em ordem.
- **A estatística não dá a resposta direto, ela reduz o número de tentativas.** O atacante ainda precisa **testar** os resultados [BIS].

### 5.3 Texto claro conhecido
- Se o atacante sabe **um único par letra clara → letra cifrada**, ele descobre k (k = c − m mod 26).
- Ex.: sabe-se que a mensagem começa com "PROVA" e o texto cifrado começa com "VXUBG". P(15) → V(21) ⇒ **k = 6**.

### Tipos de ataque (Bishop) aplicados à César
| Ataque | O atacante tem… | Na César |
|---|---|---|
| **Só texto cifrado** | apenas o texto cifrado | força bruta com 26 chaves ou análise de frequência |
| **Texto claro conhecido** | texto cifrado + texto claro correspondente | 1 letra basta para achar k |
| **Texto claro escolhido** | pode pedir a cifragem de textos escolhidos | cifra "A", e o resultado é a própria chave |

---

## 6. Variações e evolução (contexto)
- **Cifra afim**: c = (a·m + b) mod n, um deslocamento com multiplicador [BIS §10.2.2, ex. 4].
- **Substituição monoalfabética com palavra-chave**: generalização dos árabes. A palavra-chave permuta o alfabeto. Quebra-se com frequência de letras e digramas (~600 letras; ~150 adivinhando palavras prováveis) [AND].
- **Vigenère** (polialfabética): chave de várias letras repetida; o tamanho da chave é o **período**. Foi considerada inquebrável até **Kasiski** (1863) notar que repetições aparecem a **múltiplos do tamanho da chave** [BIS][AND].
- **One-time pad** (Vernam): chave **tão longa quanto a mensagem e nunca repetida** dá **sigilo perfeito**, mas **não protege a integridade** [AND §5.2.2].

---

## 7. Roteiro para a prova prática
1. Converta cada letra em número (A = 0 … Z = 25).
2. **Cifrar:** some k. Se passar de 25, subtraia 26.
3. **Decifrar:** subtraia k. Se ficar negativo, some 26.
4. Converta de volta para letra e **mantenha espaços**.
5. **Sem a chave:** teste as chaves (força bruta) até aparecer texto legível, ou use uma palavra conhecida para calcular k = c − m.
6. **Confira** cifrando o resultado de novo.

---

## ⚠️ Pegadinhas de prova
- Chave de César = **deslocamento**, e só existem **26** (0 a 25).
- Deslocar **para trás 3** é o mesmo que usar **k = 23** (26 − 3). O exercício de Bishop `TEBKFKQEBZLROPBLCERJXKBSBKQP` foi cifrado com **k = 23**: decifrando dá **WHENINTHECOURSEOFHUMANEVENTS** ("When in the course of human events").
- É **substituição** (não transposição), **monoalfabética** (não polialfabética) e **simétrica** (não de chave pública).
- A César **não garante integridade**: o atacante pode trocar letras do texto cifrado sem ser detectado.
- **Princípio de Kerckhoffs**: o atacante **conhece o algoritmo** (deslocamento) e o **conjunto de chaves** (0 a 25). O único segredo é k, e ele é trivial de achar por força bruta [BIS §10.1.1].
