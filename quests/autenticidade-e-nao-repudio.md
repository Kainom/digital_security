# Questões: Autenticidade, Responsabilização e Não Repúdio

> [!info] Como usar
> Escreva sua resposta no espaço **Sua resposta**. O gabarito fica **oculto**: clique em **Gabarito** para expandir **só depois de responder**. Depois peça ao agente para corrigir.
> Resumo de apoio: [[06-autenticidade-e-nao-repudio]]

---

## Questão 1 (Discursiva)
Defina **autenticidade** e **responsabilização (*accountability*)** segundo Stallings. Qual a relação entre responsabilização e não repúdio?

**Sua resposta:**


> [!success]- Gabarito
> - **Autenticidade:** propriedade de ser **genuíno** e de poder ser **verificado e confiável**; confiança na validade de uma transmissão, mensagem ou originador. Verificar que os usuários são quem dizem ser e que cada entrada vem de fonte confiável.
> - **Responsabilização:** objetivo que exige que as **ações de uma entidade sejam rastreadas unicamente até ela**. Os sistemas devem manter **registros** para análise forense e disputas.
> - **Relação:** a responsabilização **dá suporte ao não repúdio** (e também à dissuasão, ao isolamento de falhas, à detecção de intrusão e à ação legal).
> 📚 *Fonte: [STA] §1.1*

---

## Questão 2 (Discursiva)
O que é **repúdio**? Diferencie **repúdio de origem** e **negação de recebimento** (Bishop), com exemplos.

**Sua resposta:**


> [!success]- Gabarito
> **Repúdio** (RFC 4949): uma entidade engana outra **negando falsamente a responsabilidade** por um ato. É uma ação de **engano**, ameaça à **integridade** [STA].
> - **Repúdio de origem:** negar falsamente ter **enviado/criado** algo. Ex.: o cliente envia uma carta concordando em pagar, recebe o produto e depois **nega ter feito o pedido**. Se o vendedor não provar a origem, o ataque funciona. Combatido por **mecanismos de integridade**.
> - **Negação de recebimento:** negar falsamente ter **recebido** algo. Ex.: o cliente paga, recebe o produto e pergunta quando vai recebê-lo. Combatida por mecanismos de **integridade e disponibilidade**.
> 📚 *Fonte: [BIS] §1.2 · [STA] Tab. 1.2*

---

## Questão 3 (Múltipla escolha)
Segundo a FIPS 186-4, a assinatura digital fornece:

a) confidencialidade, integridade e disponibilidade
b) autenticação de origem, integridade dos dados e não repúdio do signatário
c) confidencialidade e não repúdio
d) autenticação de origem e confidencialidade
e) integridade e disponibilidade

**Sua resposta:**


> [!success]- Gabarito
> **b)** A FIPS 186-4 define a assinatura digital como o resultado de uma transformação criptográfica que fornece mecanismo para verificar **autenticação de origem, integridade dos dados e não repúdio do signatário**. Ela **não** fornece confidencialidade.
> 📚 *Fonte: [STA] §2.4*

---

## Questão 4 (Discursiva)
Descreva o processo de **gerar** e **verificar** uma assinatura digital (Bob envia para Alice), indicando **qual chave** é usada em cada etapa.

**Sua resposta:**


> [!success]- Gabarito
> **Geração (Bob):** (1) calcula o **hash** da mensagem com uma função segura (ex.: SHA-512); (2) o hash e a **chave privada de Bob** entram no algoritmo de geração de assinatura, que produz um bloco curto (a assinatura); (3) envia a mensagem com a assinatura.
> **Verificação (Alice):** (1) calcula o **hash** da mensagem recebida; (2) passa o hash, a assinatura e a **chave pública de Bob** ao algoritmo de verificação; (3) se "válida", a mensagem foi assinada por Bob (só ele tem a chave privada) e **não foi alterada**.
> 📚 *Fonte: [STA] §2.4 (Fig. 2.7)*

---

## Questão 5 (Discursiva)
Alice e Bob compartilham uma chave secreta k. Alice envia a Bob uma mensagem e sua cifragem com k (ou um MAC). Isso é uma **assinatura digital**? Justifique com o conceito de não repúdio.

**Sua resposta:**


> [!success]- Gabarito
> **Não.** Bob consegue autenticar a origem e o conteúdo: só ele e Alice conhecem k e ele sabe que não enviou a mensagem. Mas **não consegue provar a uma terceira parte (um juiz)** que não foi ele quem criou a mensagem, porque **ele também conhece a chave**. Pela Def. 10-7 de Bishop, a assinatura digital precisa autenticar origem e conteúdo **de forma comprovável a uma terceira parte desinteressada**. Com chave compartilhada **não há não repúdio**. A criptografia de chave pública resolve isso: só Alice conhece a chave privada dela.
> 📚 *Fonte: [BIS] §10.5 · [STA] §2.2*

---

## Questão 6 (Múltipla escolha)
Sobre o **MAC (código de autenticação de mensagem)**, é **incorreto** afirmar:

a) Usa uma chave secreta compartilhada entre emissor e receptor.
b) Garante ao receptor que a mensagem não foi alterada.
c) Garante ao receptor que a mensagem veio do emissor alegado.
d) Fornece não repúdio, pois só o emissor conhece a chave.
e) Não fornece confidencialidade, pois a mensagem pode seguir em claro.

**Sua resposta:**


> [!success]- Gabarito
> **d)** está incorreta: a chave é conhecida **pelos dois** (emissor e receptor), então o receptor também poderia ter gerado o MAC e não há não repúdio. As demais estão de acordo com Stallings.
> 📚 *Fonte: [STA] §2.2 · [BIS] §10.5*

---

## Questão 7 (Discursiva)
Bishop diz que o não repúdio da assinatura digital é **"estritamente técnico"**. O que isso significa?

**Sua resposta:**


> [!success]- Gabarito
> O não repúdio considerado é a **impossibilidade de negar que a sua chave criptográfica foi usada** para produzir a assinatura. Ele não prova, por si só, que a **pessoa** assinou: Alice pode alegar que sua **chave privada foi roubada** ou que sua identidade foi **vinculada incorretamente no certificado**. Essas alegações exigem **evidências adicionais** e cabem a um tribunal ou autoridade legal.
> 📚 *Fonte: [BIS] §10.5*

---

## Questão 8 (Discursiva)
A assinatura digital fornece **confidencialidade**? Justifique.

**Sua resposta:**


> [!success]- Gabarito
> **Não.** A mensagem fica protegida contra **alteração**, mas **não contra escuta**. Se só uma parte for assinada, o resto segue em claro; e mesmo que tudo seja "cifrado" com a chave privada do emissor, **qualquer observador decifra usando a chave pública** dele. Para ter confidencialidade é preciso também cifrar (ex.: com a chave pública do destinatário ou um envelope digital).
> 📚 *Fonte: [STA] §2.4 · [STA] §2.3*

---

## Questão 9 (Discursiva)
Por que Bishop recomenda **nunca assinar o documento em si**, e sim um **hash** dele? E por que esse hash precisa ser **resistente a colisões**?

**Sua resposta:**


> [!success]- Gabarito
> - **Assinar o hash:** com RSA "cru", Alice pode fazer Bob assinar duas mensagens m1 e m2 com m1·m2 mod n = m e **multiplicar as assinaturas**, obtendo a assinatura de Bob sobre m (um contrato que ele nunca assinou). Bishop mostra isso com o contrato "NAY". **Defesa:** não assinar documentos aleatórios e **assinar um hash criptográfico** do documento.
> - **Resistência a colisões:** como se assina o hash, se o atacante achar duas mensagens com o **mesmo hash**, a assinatura de uma vale para a outra (exemplo do vale de Stallings: valor pequeno × valor grande).
> 📚 *Fonte: [BIS] §10.5.2 · [STA] §2.2 · [AT03] Q1.3*

---

## Questão 10 (Discursiva)
Segundo Anderson, o que significa **autenticidade** na literatura de protocolos, e como ela difere da simples integridade? Dê o exemplo do cheque.

**Sua resposta:**


> [!success]- Gabarito
> Em protocolos, **autenticidade = integridade + frescor (*freshness*)**: estabeleceu-se que se está falando com um principal genuíno, e **não com uma reprodução (replay)** de mensagens antigas. **Exemplo:** se a lei diz que cheques valem por seis meses, um cheque de **sete meses** não alterado **tem integridade**, mas **não é mais válido**.
> 📚 *Fonte: [AND] §1.7*

---

## Questão 11 (Múltipla escolha)
Associe o mecanismo ao conjunto de serviços que ele fornece:
I. Hash sem chave  II. MAC/HMAC  III. Assinatura digital

a) I: integridade contra alterações acidentais; II: integridade + autenticação de origem; III: integridade + autenticação de origem + não repúdio
b) I: não repúdio; II: confidencialidade; III: integridade
c) I: confidencialidade; II: não repúdio; III: disponibilidade
d) I: integridade + não repúdio; II: autenticação; III: confidencialidade
e) I: autenticação de origem; II: não repúdio; III: confidencialidade

**Sua resposta:**


> [!success]- Gabarito
> **a)**
> - **Hash sem chave:** detecta alterações **acidentais** (um adversário ativo pode alterar a mensagem e recalcular o hash).
> - **MAC:** integridade e autenticação de origem, **sem** não repúdio (a chave é compartilhada).
> - **Assinatura digital:** integridade, autenticação de origem e **não repúdio** (sem confidencialidade).
> 📚 *Fonte: [STA] §2.2, §2.4 · [BIS] §10.4, §10.5*

---

## Questão 12 (Discursiva)
Como funcionam as **assinaturas com chave simétrica** (esquema de Merkle) e qual a exigência adicional delas?

**Sua resposta:**


> [!success]- Gabarito
> Todos os esquemas de assinatura com chave secreta **dependem de uma terceira parte confiável**, e o juiz precisa confiar nela. No esquema de Merkle, **Cathy** compartilha k_Alice com Alice e k_Bob com Bob. Alice cifra o contrato com k_Alice e envia a Bob; Bob o repassa a Cathy, que decifra com k_Alice, recifra com k_Bob e devolve a Bob. Para verificar, o juiz pede a Cathy que decifre as duas mensagens (com as chaves de Alice e de Bob): se coincidirem, o envio está verificado; se não, uma delas é falsificação.
> 📚 *Fonte: [BIS] §10.5.1*
