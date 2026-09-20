# Princípios e fundamentos da criptografia

> Fontes: [STA] §1.4, §2.1, §2.3, §2.4 · [BIS] §1.1.1, §10.1, §10.2, §10.3, §10.6 · [AND] §5.1, §5.2

## 1. Vocabulário básico

| Termo | Definição |
|---|---|
| **Criptografia** | Do grego **"escrita secreta"**: a arte e a ciência de **ocultar significado** [BIS]. Ciência e arte de **projetar** cifras [AND]. |
| **Criptoanálise** | A **quebra** de códigos [BIS]. Ciência e arte de **quebrar** cifras [AND]. |
| **Criptologia** ("crypto") | Estudo de **ambas** [AND]. |
| **Texto claro** (*plaintext/cleartext*) | Entrada do processo de cifragem [AND]. |
| **Texto cifrado** (*ciphertext*) | Saída embaralhada [AND][STA]. |
| **Criptossistema** | Componente básico da criptografia [BIS]. |

### Criptossistema como quíntupla (Bishop, Def. 10-1)
**(E, D, M, K, C)**, onde:
- **M** = conjunto de textos claros; **K** = conjunto de chaves; **C** = conjunto de textos cifrados;
- **E: M × K → C** = funções de cifragem; **D: C × K → M** = funções de decifragem.

---

## 2. O que a criptografia protege (Bishop §10.1)
| Serviço | Ameaça combatida |
|---|---|
| **Sigilo** (manter a informação cifrada secreta), que é o **objetivo principal** | **Divulgação** |
| **Integridade dos dados e da origem** | **Modificação** e **mascaramento** |
| **Não repúdio** | **Repúdio de origem** |

> *"É um mecanismo notavelmente poderoso, no qual as técnicas de segurança computacional se apoiam fortemente."* [BIS]
> Mas **a chave vira mais um dado a proteger** [BIS §1.1.1]. A criptografia **sozinha não dá segurança completa**: se alguém ler a chave quando ela é digitada, a proteção cai.

---

## 3. Confusão e difusão (Bishop §10.1)
- **Confusão**: **substitui** partes do texto claro por outros dados para esconder o conteúdo original.
- **Difusão**: **embaralha** o texto claro para que o conteúdo original se espalhe pela mensagem.
- *"Todos os criptossistemas se baseiam em **substituição** e **permutação**"* [BIS §10.6].

---

## 4. Princípio de Kerckhoffs × Projeto aberto

- **Princípio de Kerckhoffs** [BIS §10.1.1]: a segurança de um criptossistema **não pode depender de o adversário desconhecer os algoritmos** de cifragem e decifragem.
  - Prática padrão: supor que o adversário **conhece E, D e o conjunto de chaves K**, mas **não a chave específica**.
- **Projeto aberto (*open design*)**, um dos princípios fundamentais de projeto seguro [STA §1.4]: o projeto do mecanismo deve ser **aberto, e não secreto**. *"As chaves devem ser secretas, mas os algoritmos devem estar abertos ao escrutínio público"*: muitos especialistas revisam e os usuários ganham confiança. É a filosofia por trás da padronização do NIST.
- Stallings, requisito de cifragem forte: o oponente que **conhece o algoritmo** e tem textos cifrados (até pares claro-cifrado) **não deve conseguir decifrar nem descobrir a chave** [STA §2.1].

---

## 5. Ataques a criptossistemas

### Duas abordagens gerais [STA §2.1]
| | Criptoanálise | Força bruta |
|---|---|---|
| Como | Explora a **natureza do algoritmo** e características do texto claro, ou pares claro-cifrado | **Testa todas as chaves** até obter texto inteligível |
| Esforço | Depende da fraqueza encontrada | **Em média metade** das chaves (x/2) |
| Consequência | Se deduzir a chave, **todas as mensagens passadas e futuras** com ela ficam comprometidas | Precisa **reconhecer o texto claro** (difícil se estiver comprimido) |

### Três tipos de ataque (Bishop §10.1.1)
1. **Só texto cifrado (*ciphertext only*)**: tem só o texto cifrado e quer o texto claro (e, se possível, a chave).
2. **Texto claro conhecido (*known plaintext*)**: tem o texto cifrado e o texto claro correspondente, e quer a chave.
3. **Texto claro escolhido (*chosen plaintext*)**: pode pedir a cifragem de textos escolhidos, e quer a chave.

> *"Um bom criptossistema protege contra os três."* [BIS]

- Os ataques usam **matemática** (examinar as suposições dos problemas em que a cifra se apoia) e **estatística** (modelos da língua: 1-grama, 2-grama, Markov, palavras) [BIS].
- **Tamanho de chave:** com mais poder computacional, a chave precisa crescer. *"Uma chave de 56 bits era considerada segura em 1976; hoje claramente não é"* [BIS §10.6].

---

## 6. Criptografia simétrica (chave secreta / convencional)

- Usa **a mesma chave** para cifrar e decifrar: **D_k(E_k(m)) = m** [BIS §10.2].
- Foi o **único tipo** em uso até a criptografia de chave pública, no fim dos anos 1970. Ainda é **a mais usada** [STA].

### Cinco ingredientes [STA Fig. 2.1]
1. **Texto claro** · 2. **Algoritmo de cifragem** (substituições e transformações) · 3. **Chave secreta** · 4. **Texto cifrado** (duas chaves diferentes geram textos cifrados diferentes) · 5. **Algoritmo de decifragem** (o de cifragem "ao contrário").

### Dois requisitos para uso seguro [STA]
1. **Algoritmo forte**.
2. Emissor e receptor devem **obter a chave de forma segura** e **mantê-la segura**.

### Clássicas (Bishop §10.2)
| Tipo | O que faz | Exemplo |
|---|---|---|
| **Transposição** | **Reordena** os caracteres (letras não mudam). **Preserva a frequência** das letras | *Rail fence*: "HELLO, WORLD" → "HLOOLELWRD" |
| **Substituição** | **Troca** caracteres | **César**, Vigenère |
| ↳ Monoalfabética | Um único alfabeto, **preserva estatísticas** | César |
| ↳ Polialfabética | Vários alfabetos, **esconde estatísticas** | Vigenère |

- **One-time pad** [AND §5.2.2]: chave aleatória do tamanho da mensagem e nunca repetida, o que dá **sigilo perfeito**. O preço é que **falha totalmente em proteger a integridade**.

### Modernas [STA §2.1]
- **Cifra de bloco**: processa blocos de tamanho fixo (64 ou 128 bits). Ex.: **DES, 3DES, AES**.
  - **ECB** (*electronic codebook*): cada bloco cifrado com a mesma chave. Para mensagens longas **pode ser inseguro**, porque regularidades do texto claro aparecem. Por isso existem outros **modos de operação**.
- **Cifra de fluxo**: processa **elemento a elemento** (tipicamente byte a byte), combinando o texto com um **keystream** pseudoaleatório via **XOR**. Geralmente é **mais rápida e usa menos código**. A cifra de bloco tem a vantagem de **reutilizar chaves**.

---

## 7. Criptografia assimétrica (chave pública)

- Proposta publicamente por **Diffie e Hellman em 1976**, *"o primeiro avanço verdadeiramente revolucionário em cifragem em milhares de anos"* [STA]. **James Ellis** (governo britânico) já tinha o conceito em **1970**, mas o trabalho ficou classificado até 1997 [BIS].
- Baseia-se em **funções matemáticas**, não em operações sobre padrões de bits. Usa **duas chaves**: uma **pública** e uma **privada** [STA].
- Baseia-se em **problemas difíceis**, como fatoração de números grandes (RSA) [BIS].

### Seis ingredientes [STA]
texto claro · algoritmo de cifragem · **chave pública** · **chave privada** · texto cifrado · algoritmo de decifragem.

### Dois modos de uso [STA Fig. 2.6]
| Cifra com… | Decifra com… | Serviço |
|---|---|---|
| **Chave pública do destinatário** | Chave privada do destinatário | **Confidencialidade** (só o destinatário lê) |
| **Chave privada do emissor** | Chave pública do emissor | **Autenticação e/ou integridade** (só o emissor poderia ter cifrado) |

### Requisitos (Diffie-Hellman, [STA]; Bishop §10.3)
- Fácil **gerar** o par de chaves, **cifrar** com a pública e **decifrar** com a privada.
- **Inviável derivar a chave privada a partir da pública.**
- Inviável recuperar a mensagem a partir da chave pública e do texto cifrado.
- (Bishop) Inviável determinar a chave privada por **ataque de texto claro escolhido**.

### Três equívocos comuns [STA]
1. ❌ "Chave pública é mais segura contra criptoanálise." A segurança depende do **tamanho da chave** e do **trabalho computacional**, não do tipo.
2. ❌ "Chave pública tornou a simétrica obsoleta." Pelo **custo computacional**, a simétrica não será abandonada.
3. ❌ "Distribuir chaves com chave pública é trivial." Ainda exige **protocolo**, muitas vezes com agente central.

### Algoritmos e aplicações [STA Tab. 2.3]
| Algoritmo | Assinatura digital | Distribuição de chave simétrica | Cifrar chaves secretas |
|---|---|---|---|
| **RSA** | Sim | Sim | Sim |
| **Diffie-Hellman** | Não | **Sim** (só troca de chaves) | Não |
| **DSS** | **Sim** (só assinatura) | Não | Não |
| **Curvas elípticas (ECC)** | Sim | Sim | Sim |

- **ECC**: segurança equivalente ao RSA com **chaves bem menores** [STA].
- **Diffie-Hellman** simples **não autentica** as partes [STA §2.4].

### Envelope digital [STA §2.4]
Para mandar mensagem confidencial **sem chave simétrica combinada**: (1) gera uma **chave simétrica aleatória de uso único**; (2) cifra a mensagem com ela; (3) cifra essa chave com a **chave pública do destinatário**; (4) envia os dois. Só o destinatário recupera a chave e a mensagem. Se a chave pública veio de um **certificado**, há garantia de que é válida.

---

## 8. Quadro-resumo: qual ferramenta dá qual serviço

| Ferramenta | Confidencialidade | Integridade | Autenticação de origem | Não repúdio | Usa chave? |
|---|---|---|---|---|---|
| Cifra simétrica | ✅ | ⚠️ sozinha não basta [STA] | ⚠️ | ❌ | 1 chave compartilhada |
| Hash puro | ❌ | só contra erros acidentais | ❌ | ❌ | não |
| MAC / HMAC | ❌ | ✅ | ✅ | ❌ (chave compartilhada) | chave secreta compartilhada |
| Cifra com chave pública do destinatário | ✅ | — | — | — | par de chaves |
| Assinatura digital | ❌ [STA] | ✅ | ✅ | ✅ | chave privada do signatário |

→ Detalhes em [[02-hashing]] e [[06-autenticidade-e-nao-repudio]].

---

## ⚠️ Pegadinhas de prova
- **O segredo está na chave, não no algoritmo** (Kerckhoffs / projeto aberto).
- Na simétrica, a **mesma** chave cifra e decifra. Na assimétrica, **uma cifra e a outra decifra**.
- **Assimétrica não é "mais segura"** por natureza, e **não substituiu** a simétrica (ela é lenta).
- **Transposição preserva a frequência de cada letra**; a **substituição monoalfabética** preserva a **estatística** (a letra muda, a distribuição continua a mesma).
- Cifrar **com a própria chave privada não dá sigilo**: qualquer um decifra com a chave pública [STA].
