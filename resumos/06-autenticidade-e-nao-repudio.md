# Autenticidade, Responsabilização e Não Repúdio (e Assinatura Digital)

> Fontes: [STA] §1.1, §1.2, §2.2, §2.4 · [BIS] §1.2, §10.1, §10.5 · [AND] §1.7, §5.6 · [AT03] Q1.3

## 1. Os conceitos "além da tríade" ([STA] §1.1, Fig. 1.1)

### Autenticidade
- **Stallings:** propriedade de ser **genuíno** e de poder ser **verificado e confiável**; confiança na validade de uma transmissão, de uma mensagem ou do seu originador. Significa **verificar que os usuários são quem dizem ser** e que **cada entrada vem de uma fonte confiável**.
- **Bishop:** a autenticidade corresponde à **integridade de origem** ("a fonte dos dados, muitas vezes chamada de **autenticação**").
- **Anderson:** em protocolos, **autenticidade = integridade + frescor**: você fala com um principal genuíno, e **não com um replay** de mensagens antigas.
- **FIPS 199 inclui a autenticidade dentro da integridade.**

### Responsabilização (*accountability*)
- **Stallings:** objetivo que exige que **as ações de uma entidade sejam rastreadas unicamente até ela**.
- **Dá suporte a:** **não repúdio**, dissuasão, isolamento de falhas, detecção e prevenção de intrusão, recuperação pós-incidente e **ação legal**.
- Como sistemas perfeitamente seguros ainda não existem, é preciso **rastrear a violação até um responsável**. Os sistemas devem **manter registros** (logs) para **análise forense** e **disputas de transação**.
- FIPS 200, **"Auditoria e Responsabilização"**: criar, proteger e reter registros de auditoria, e garantir que as ações de cada usuário possam ser **rastreadas até ele** [STA §1.3].
- Bishop: a responsabilização é um dos **dois usos principais da identidade** (o outro é o controle de acesso) [BIS §15.1].

---

## 2. Repúdio: a ameaça

| Fonte | Definição |
|---|---|
| RFC 4949 [STA Tab. 1.2] | **Repúdio**: uma entidade engana outra **negando falsamente a responsabilidade** por um ato. É uma ação de **engano (*deception*)**, ou seja, ameaça à **integridade**. |
| [STA] | O usuário **nega ter enviado** dados, ou **nega ter recebido/possuir** os dados. |
| [BIS] **Repúdio de origem** | **Negação falsa** de que uma entidade **enviou ou criou** algo. Ex.: o cliente manda carta aceitando pagar, recebe o produto e nega ter pedido. Se o vendedor não provar a origem, o ataque funciona. **Mecanismos de integridade** tentam lidar com isso. |
| [BIS] **Negação de recebimento** | **Negação falsa** de que **recebeu** uma informação ou mensagem. Combatida por mecanismos de **integridade e disponibilidade**. |

## 3. Não repúdio: o serviço

- **Não repúdio** = impedir que alguém **negue com sucesso** a autoria ou o envio.
- A **criptografia pode prover não repúdio**, combatendo a ameaça de **repúdio de origem** [BIS §10.1].
- **FIPS 199**: a integridade inclui **garantir o não repúdio** [STA].
- Bishop: o não repúdio da assinatura digital é **estritamente técnico**: a **impossibilidade de negar que a SUA chave criptográfica foi usada** para produzir a assinatura. Alice ainda pode alegar que a chave foi **roubada** ou que a identidade foi vinculada errado no **certificado**. Essa disputa exige **evidências adicionais** e cabe a um tribunal [BIS §10.5].

---

## 4. MAC: autentica, mas NÃO dá não repúdio

**Código de autenticação de mensagem (MAC)** [STA §2.2]: A e B compartilham a chave secreta K_AB. A calcula **MAC_M = F(K_AB, M)** e envia M + MAC. B recalcula e compara. Se bater:
1. a mensagem **não foi alterada** (**integridade**);
2. a mensagem **veio do emissor alegado** (**autenticação de origem**), já que só ele conhece a chave;
3. com número de sequência, a **ordem** está correta.

- O MAC **não fornece confidencialidade** (a mensagem vai em claro) [STA].
- A função de autenticação **não precisa ser reversível** (diferente da cifragem) e por isso é menos vulnerável [STA].

**Por que MAC ou cifra simétrica não é assinatura digital (Bishop §10.5):**
Alice e Bob compartilham k. Bob recebe a mensagem cifrada com k e sabe que veio de Alice (porque ele não a enviou). **Mas não consegue PROVAR a um terceiro** que não foi ele mesmo que a criou, porque **ele também conhece a chave**. Logo, **não há não repúdio**.

> Esquemas de assinatura com **chave simétrica** exigem uma **terceira parte confiável** (ex.: esquema de Merkle com "Cathy"), e o juiz precisa confiar nela [BIS §10.5.1].

---

## 5. Assinatura digital

### Definições
| Fonte | Definição |
|---|---|
| **FIPS 186-4** [STA §2.4] | Resultado de uma transformação criptográfica sobre dados que, bem implementada, fornece mecanismo para verificar **autenticação de origem, integridade dos dados e não repúdio do signatário**. |
| **[BIS] Def. 10-7** | Construção que **autentica tanto a origem quanto o conteúdo** de uma mensagem de forma **comprovável a uma terceira parte desinteressada** (o **"juiz"**). |
| **[STA]** | Padrão de bits **dependente dos dados**, gerado por um agente em função de um arquivo ou mensagem. Permite verificar que (1) o bloco foi assinado pelo **signatário alegado** e (2) **não foi alterado** desde a assinatura. **O signatário não pode repudiar a assinatura.** |
| **[AND]** | Um **tipo especial de primitiva assimétrica**. |

### Processo ([STA] Fig. 2.7, Bob → Alice)
**Assinar (Bob):**
1. calcula o **hash** da mensagem (ex.: **SHA-512**);
2. hash + **chave PRIVADA de Bob** → algoritmo de geração de assinatura → **assinatura**;
3. envia **mensagem + assinatura**.

**Verificar (Alice):**
1. calcula o **hash** da mensagem recebida;
2. hash + assinatura + **chave PÚBLICA de Bob** → algoritmo de verificação → **válida ou inválida**.

Resultado: **ninguém mais tem a chave privada de Bob** (autenticação de origem + não repúdio), e **não é possível alterar a mensagem sem a chave privada** (integridade).

### O que a assinatura NÃO faz
- **Não fornece confidencialidade** [STA]. A mensagem está protegida contra **alteração**, mas **não contra escuta**. Mesmo cifrando tudo com a chave privada, qualquer um decifra com a chave pública.

### Algoritmos (FIPS 186-4) [STA]
- **DSA** (logaritmo discreto; o DSS **só faz assinatura**, não cifra nem troca chaves);
- **RSA** (assinatura digital RSA);
- **ECDSA** (curvas elípticas).

### Por que assinar o HASH (e por que a resistência a colisões é crítica)
- Bishop: nunca assine **documentos aleatórios** nem **o documento em si**. **Assine um hash criptográfico do documento.** (Com RSA "cru", Alice combinou duas assinaturas legítimas de Bob para forjar a assinatura dele num contrato "NAY".)
- Stallings (exemplo do vale/IOU): se Bob acha **duas mensagens com o mesmo hash** (uma de valor pequeno e outra de valor grande), Alice assina a pequena e Bob apresenta a grande. Por isso a assinatura precisa de um **hash forte (resistente a colisões)**.
- [AT03 Q1.3]: como a assinatura **assina o hash e não a mensagem inteira**, uma função **sem resistência a colisões** permite achar x1 ≠ x2 com H(x1) = H(x2), e a assinatura de um vale para o outro.
- Anderson: o ataque de **prefixo escolhido** contra o SHA-1 (2020) permitiu **forjar certificados** (que também são assinaturas).

---

## 6. Quadro comparativo final

| Mecanismo | Integridade | Autenticação de origem | Não repúdio | Confidencialidade | Quem pode verificar |
|---|---|---|---|---|---|
| Hash puro | só erros acidentais | ❌ | ❌ | ❌ | qualquer um |
| **MAC / HMAC** | ✅ | ✅ | ❌ | ❌ | só quem tem a chave compartilhada |
| **Assinatura digital** | ✅ | ✅ | ✅ | ❌ | **qualquer um** com a chave pública (inclusive um juiz) |
| Assinatura + cifra | ✅ | ✅ | ✅ | ✅ | destinatário |

---

## ⚠️ Pegadinhas de prova
- **Não repúdio exige assimetria**: só o signatário tem a chave privada. Com chave compartilhada (MAC), qualquer uma das partes poderia ter gerado o código.
- **Assina-se com a chave PRIVADA e verifica-se com a chave PÚBLICA** (do signatário). Para **sigilo** é o contrário: cifra-se com a **pública do destinatário**.
- **Assinatura digital ≠ confidencialidade.**
- **Repúdio** está na categoria **engano (*deception*)** e ameaça a **integridade** [STA]; **responsabilização (*accountability*)** dá suporte ao **não repúdio**.
- O não repúdio é **técnico**: prova que a **chave** foi usada, não necessariamente que a **pessoa** a usou (chave roubada) [BIS].
