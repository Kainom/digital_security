# Questões: Certificados Digitais e PKI

> [!info] Como usar
> Escreva sua resposta no espaço **Sua resposta**. O gabarito fica **oculto**: clique em **Gabarito** para expandir **só depois de responder**. Depois peça ao agente para corrigir.
> Resumo de apoio: [[07-certificados-digitais]]

---

## Questão 1 (Discursiva)
Qual **fraqueza** da distribuição de chaves públicas o certificado digital resolve? O que um falsificador conseguiria fazer sem certificados?

**Sua resposta:**


> [!success]- Gabarito
> Como a chave pública é pública, qualquer participante pode enviá-la ou divulgá-la, mas **qualquer um pode forjar esse anúncio**: alguém pode **fingir ser Bob** e divulgar uma chave como se fosse dele. Até Bob perceber e alertar os outros, o falsificador consegue **ler todas as mensagens cifradas destinadas a Bob** e **usar as chaves forjadas para se autenticar** como ele. A solução é o **certificado de chave pública**.
> 📚 *Fonte: [STA] §2.4*

---

## Questão 2 (Discursiva)
Defina **certificado de chave pública** e **autoridade certificadora (CA)**.

**Sua resposta:**


> [!success]- Gabarito
> - **Certificado:** **chave pública + ID do dono**, com o **bloco inteiro assinado por uma terceira parte confiável**. Inclui informações sobre a terceira parte e o **período de validade** [STA]. Bishop: o emissor cifra, com sua **chave privada**, um **hash** da identidade do sujeito, da chave pública e de dados como datas de emissão e expiração.
> - **CA:** *"entidade que emite certificados"* [BIS Def. 11-6], confiável para a comunidade de usuários (ex.: agência governamental, instituição financeira) [STA].
> - Objetivo: **vincular a identidade correta à chave pública** [BIS §15.5.3].
> 📚 *Fonte: [STA] §2.4 · [BIS] §11.4.2, §15.5.3*

---

## Questão 3 (Discursiva)
Descreva as etapas de **emissão** de um certificado e como **qualquer usuário** verifica sua validade.

**Sua resposta:**


> [!success]- Gabarito
> **Emissão:**
> 1. O software do cliente gera o **par de chaves** (pública e privada).
> 2. O cliente prepara um **certificado não assinado** com seu ID e sua chave pública.
> 3. Entrega à CA de forma segura (presencialmente, e-mail registrado, formulário web com verificação por e-mail).
> 4. A CA calcula o **hash** do certificado não assinado, gera a **assinatura** com a **chave privada da CA** e a anexa, formando o certificado assinado.
> 5. A CA devolve o certificado, e o cliente pode distribuí-lo.
>
> **Verificação:** o usuário calcula o **hash** do certificado (sem a assinatura) e verifica a assinatura com a **chave pública da CA**. O resultado é válida ou inválida. Bishop acrescenta: conferir o **período de validade**.
> 📚 *Fonte: [STA] §2.4 (Fig. 2.8) · [BIS] §11.4.2.1*

---

## Questão 4 (Múltipla escolha)
Para assinar um certificado, a CA usa:

a) a chave privada do usuário
b) a chave pública do usuário
c) a chave privada da CA
d) a chave pública da CA
e) uma chave simétrica compartilhada com o usuário

**Sua resposta:**


> [!success]- Gabarito
> **c)** A CA assina com **sua chave privada**, e qualquer usuário verifica com a **chave pública da CA**. O certificado **não contém** a chave privada do usuário.
> 📚 *Fonte: [STA] §2.4*

---

## Questão 5 (Discursiva)
Cite o padrão universalmente aceito para certificados, onde ele é usado, e liste **pelo menos cinco** campos do certificado X.509v3.

**Sua resposta:**


> [!success]- Gabarito
> **X.509**, usado em **IPsec, TLS, SSH e S/MIME** [STA].
> Campos do X.509v3 [BIS] (quaisquer cinco): (1) versão; (2) **número de série**; (3) identificador do algoritmo de assinatura; (4) **nome distinto (DN) do emissor**; (5) **intervalo de validade**; (6) **DN do sujeito**; (7) **informações da chave pública do sujeito**; (8) identificador único do emissor; (9) identificador único do sujeito; (10) extensões; (11) **assinatura** (hash cifrado dos campos 1 a 10).
> 📚 *Fonte: [STA] §2.4 · [BIS] §11.4.2.1*

---

## Questão 6 (Discursiva)
Explique o **problema recursivo** da validação de certificados e como as **cadeias de certificados** e a **certificação cruzada** o resolvem. Use a notação X≪Y≫.

**Sua resposta:**


> [!success]- Gabarito
> Para validar um certificado é preciso a **chave pública do emissor**. Se ela vem do certificado do próprio emissor, surge a pergunta: **como validar esse outro certificado?** Soluções: uma **hierarquia em árvore** com a chave da **raiz conhecida por fora** (*out of band*), ou um arranjo livre baseado no conhecimento de cada um (PGP).
> - **X≪Y≫** = certificado emitido pela CA X para o sujeito Y.
> - **Certificação cruzada:** duas CAs emitem certificados **uma para a outra**.
> - **Exemplo:** Alice (CA Cathy) quer validar Bob (CA Dan). Se Cathy e Dan são cruzados, Alice forma a cadeia **Cathy≪Dan≫ Dan≪Bob≫**: com a chave confiável de Cathy valida o certificado de Dan, e com a chave de Dan valida o de Bob. Cada certificado precisa ser validável **pelo anterior** na cadeia.
> 📚 *Fonte: [BIS] §11.4.2*

---

## Questão 7 (Múltipla escolha)
Um certificado **autoassinado**, cuja chave pública valida a própria assinatura e que inicia uma cadeia de certificados, corresponde a:

a) um certificado de entidade final
b) um certificado cruzado
c) uma âncora de confiança (*trust anchor*)
d) uma CRL
e) uma autoridade de registro

**Sua resposta:**


> [!success]- Gabarito
> **c)** Um certificado **autoassinado** é autoemitido (emissor = sujeito) e sua chave pública valida a própria assinatura. É útil para fornecer a chave pública que **inicia a cadeia**; essa CA é a **âncora de confiança**.
> 📚 *Fonte: [BIS] §11.4.3*

---

## Questão 8 (Discursiva)
Diferencie **CA** e **RA** e defina **PKI**.

**Sua resposta:**


> [!success]- Gabarito
> - **CA:** **emite** os certificados (assina com sua chave privada).
> - **RA:** entidade a quem a CA **delega o registro**, isto é, a **verificação da identidade** do usuário conforme a política da CA. **A CA continua responsável** pelos certificados que emite.
> - **PKI:** *"infraestrutura que gerencia chaves públicas e autoridades certificadoras"* (Def. 11-8).
> 📚 *Fonte: [BIS] §11.4.3, §15.5.3*

---

## Questão 9 (Discursiva)
Diferencie um certificado **expirado** de um certificado **revogado**. Quais são os dois problemas da revogação?

**Sua resposta:**


> [!success]- Gabarito
> - **Expirado:** chegou ao fim do período predefinido de validade, e esse é o **único motivo**.
> - **Revogado:** **cancelado antes do prazo**, a pedido do dono ou do emissor, por outro motivo (tipicamente **chave comprometida** ou **mudança da vinculação** entre sujeito e chave).
> - **Problemas da revogação:** (1) garantir que **quem revoga está autorizado**; (2) garantir a **rapidez da propagação** pela infraestrutura, porque sempre há algum atraso.
> 📚 *Fonte: [BIS] §11.5.2*

---

## Questão 10 (Discursiva)
Explique o que é uma **CRL** e o que é o **OCSP**, e quando o OCSP é especialmente útil.

**Sua resposta:**


> [!success]- Gabarito
> - **CRL (lista de certificados revogados):** lista de certificados que não são mais válidos. Contém **números de série e datas de revogação**, o **nome do emissor**, a data da lista e a data prevista da próxima. **É assinada pelo emissor.** No X.509, **só o emissor** pode revogar um certificado.
> - **OCSP (*Online Certificate Status Protocol*):** consulta **online** do status. A requisição leva o nº de série, o hash do nome do emissor e o hash da chave pública do emissor. A resposta é **"good"**, **"revoked"** ou **"unknown"**. Reduz o atraso da CRL e é útil quando **o tempo é crítico** (ex.: negociação de ações).
> 📚 *Fonte: [BIS] §11.5.2*

---

## Questão 11 (Discursiva)
Por que Bishop afirma que o **nível de confiança** de um certificado **não é quantificável**? Cite um incidente real mencionado no livro.

**Sua resposta:**


> [!success]- Gabarito
> A CA atesta, **com algum grau de certeza**, que a identidade corresponde ao dono da chave, e esse grau depende da **política da CA**, do **rigor** com que ela é seguida e das **suposições** feitas (ex.: exigir passaporte dá mais certeza, mas passaportes podem ser roubados ou falsificados, e a foto pode não bater). Mesmo CAs de alta garantia podem ser enganadas.
> **Incidentes:** em **2001**, a **Verisign** emitiu dois certificados para alguém que **se passou por representante da Microsoft**; e uma conta de uma **RA da Comodo** foi comprometida para emitir certificados falsos de **Google, Yahoo e Skype**, revogados em horas.
> 📚 *Fonte: [BIS] §15.5.3*

---

## Questão 12 (Discursiva)
Qual a relação entre **colisões de hash** e a **segurança de certificados**?

**Sua resposta:**


> [!success]- Gabarito
> A CA **assina um hash** do certificado. Se o hash não for resistente a colisões, um atacante pode produzir **dois certificados com o mesmo hash**, obter a assinatura da CA em um deles e usá-la no outro. Anderson relata que colisões de **MD5** podem ser achadas até em strings que seguem **formatos de certificados digitais**, e que o ataque de **prefixo escolhido contra o SHA-1 (2020)** permitiu **forjar certificados** por algumas dezenas de milhares de dólares.
> 📚 *Fonte: [STA] §2.4 · [AND] §5.6.1*
