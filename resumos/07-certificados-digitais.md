# Certificados Digitais e PKI

> Fontes: [STA] §2.4, §4.7 · [BIS] §11.4.2, §11.4.3, §11.5.2, §15.5 · [AND] §5.6.1

## 1. O problema que o certificado resolve ([STA] §2.4)

- Na criptografia de chave pública, a chave **é pública**: qualquer participante pode enviar ou divulgar a sua.
- **Fraqueza grave:** *qualquer um pode forjar esse anúncio público*. Um usuário pode **fingir ser Bob** e divulgar uma chave pública como se fosse de Bob.
- Até Bob perceber, o falsificador consegue **ler todas as mensagens cifradas destinadas a Bob** e **usar as chaves forjadas para se autenticar** como Bob.
- **Solução: o certificado de chave pública.**

> Bishop: *"O objetivo dos certificados é **vincular a identidade correta à chave pública**."* [BIS §15.5.3]
> Os certificados são o mecanismo para **vincular chaves criptográficas a identificadores**, e o identificador precisa ser **único** [BIS §15.5].

---

## 2. O que é um certificado

- **Stallings:** consiste em uma **chave pública + o ID do dono da chave**, com **o bloco inteiro assinado por uma terceira parte confiável**. Inclui também informações sobre a **terceira parte** e o **período de validade**.
- **Bishop:** o emissor **cifra, com sua chave privada, um hash** da identidade do sujeito, da chave pública e de informações como data de emissão e expiração.
- A terceira parte confiável costuma ser uma **Autoridade Certificadora (CA)**, confiável para a comunidade (ex.: agência governamental, instituição financeira) [STA].
- **CA**: *"entidade que emite certificados"* [BIS Def. 11-6].
- **Certificados digitais são exemplos de credenciais** (vinculam identidade a um token/chave) [STA §4.7].

---

## 3. Emissão e verificação ([STA] Fig. 2.8)

**Emissão:**
1. O software do cliente **gera o par de chaves** (pública e privada).
2. O cliente monta um **certificado não assinado** com o **ID do usuário** e a **chave pública**.
3. Entrega à CA **de forma segura** (presencialmente, e-mail registrado, formulário web com verificação de e-mail).
4. A CA **assina**:
   - calcula o **hash** do certificado não assinado;
   - gera a **assinatura digital** com a **chave PRIVADA da CA**;
   - anexa a assinatura, formando o **certificado assinado**.
5. A CA devolve o certificado ao cliente, que pode distribuí-lo a qualquer um.

**Verificação (qualquer usuário):**
1. calcula o **hash** do certificado (sem a assinatura);
2. verifica a assinatura com a **chave PÚBLICA da CA**, obtendo **válida ou inválida**.

Bishop acrescenta: depois de validar a assinatura, **conferir o período de validade** para ver se o certificado está **vigente** [BIS §11.4.2.1].

---

## 4. Padrão X.509

- Formato **universalmente aceito** de certificados de chave pública, usado em **IPsec, TLS, SSH e S/MIME** [STA].
- Padrão da ITU, base de muitos protocolos. Problemas da versão de 1988 foram corrigidos em **1993 (X.509v3)** [BIS].

### Campos do certificado X.509v3 [BIS §11.4.2.1]
1. **Versão**
2. **Número de série**: único por emissor; o par (DN do emissor, nº de série) é único
3. **Identificador do algoritmo de assinatura**
4. **Nome distinto (DN) do emissor**
5. **Intervalo de validade** (início e expiração)
6. **Nome distinto (DN) do sujeito**
7. **Informações da chave pública do sujeito** (algoritmo, parâmetros, chave)
8. Identificador único do emissor
9. Identificador único do sujeito
10. **Extensões** (chave, política, restrições de caminho…)
11. **Assinatura**: um **hash cifrado dos campos 1 a 10**

- **Distinguished Name (DN)**: identificador formado por pares chave=valor, para distinguir pessoas com o mesmo nome. Ex.: `/O=University of California/OU=Davis campus/OU=Department of Computer Science/CN=Matt Bishop/` [BIS §15.5].

---

## 5. Cadeias de certificados e PKI

- **Problema recursivo:** para validar um certificado é preciso a **chave pública do emissor**. Se ela vem de outro certificado, como validar **esse**? [BIS]
- **Duas abordagens:** (1) **hierarquia em árvore** com a chave da **raiz conhecida por fora (*out of band*)** (X.509); (2) arranjo livre baseado no **conhecimento de cada um** sobre os certificadores (PGP) [BIS].
- **Notação** X≪Y≫ = certificado que a CA **X** emitiu para o sujeito **Y**.
- **Certificação cruzada**: duas CAs são certificadas cruzadamente se **cada uma emitiu um certificado para a outra** [BIS Def. 11-7].
- **Cadeia de assinaturas:** Alice (cuja CA é Cathy) valida Bob (cuja CA é Dan) com **Cathy≪Dan≫ Dan≪Bob≫**. Cada certificado precisa ser validável pelo **anterior** na cadeia.
- **PKI (Infraestrutura de Chaves Públicas)**: infraestrutura que **gerencia chaves públicas e autoridades certificadoras** [BIS Def. 11-8].

### Tipos de certificado na PKI X.509 da Internet [BIS §11.4.3]
| Tipo | Descrição |
|---|---|
| **Entidade final** | emitido para quem **não pode** emitir certificados |
| **Certificado de CA** | emitido para uma CA |
| **Autoemitido** | emissor = sujeito |
| **Autoassinado** | autoemitido cuja chave pública valida a própria assinatura. Começa uma cadeia; essa CA é a **âncora de confiança (*trust anchor*)** |
| **Certificado cruzado** | emitido por uma CA para outra, descrevendo relação de confiança |

- **Autoridade de Registro (RA):** a CA pode **delegar** o registro, ou seja, a **verificação da identidade** do usuário conforme a política da CA [BIS]. **A CA continua responsável** pelos certificados [BIS §15.5.3].

### PGP (contraste)
- Estrutura de certificados **diferente** do X.509, sem hierarquia obrigatória [BIS].
- As assinaturas no certificado trazem **nível de confiança** na identidade: **genérico** (sem afirmação), **persona** (sem verificação), **casual** (alguma verificação), **positivo** (verificação substancial) [BIS §15.5.3].

---

## 6. Expiração × revogação ([BIS] §11.5.2)

| | **Expirado** | **Revogado** |
|---|---|---|
| Motivo | **Único motivo:** passou o período de validade predefinido | Cancelado **antes** do prazo, a pedido do **dono** ou do **emissor**, por outro motivo |
| Exemplos | fim da validade | **chave comprometida**; **mudou a vinculação** sujeito-chave |

**Dois problemas da revogação:** (1) garantir que **quem revoga está autorizado**; (2) garantir a **rapidez da propagação** pela infraestrutura (sempre há atraso).

### Mecanismos
- **CRL (Lista de Certificados Revogados)** [BIS Def. 11-10]: lista de certificados que **não são mais válidos**. Contém os **números de série** e as **datas de revogação**, o **nome do emissor**, a data de emissão da lista e a **data da próxima**. **O emissor assina a lista.** No X.509, **só o emissor** de um certificado pode revogá-lo.
- **OCSP (*Online Certificate Status Protocol*)**: verificação **online**, para reduzir o atraso. A requisição leva o nº de série, o hash do nome do emissor e o hash da chave pública do emissor. A resposta é **"good"**, **"revoked"** ou **"unknown"**. É útil quando o tempo é crítico (ex.: negociação de ações).

---

## 7. Confiança: o limite do certificado ([BIS] §15.5.3)

- A CA **atesta, com algum grau de certeza**, que a identidade corresponde ao dono da chave. **O grau de confiança não é quantificável**: depende da **política da CA**, do **rigor** com que é seguida e das **suposições** dela (ex.: exigir passaporte dá mais certeza que uma declaração, mas passaportes podem ser roubados ou falsificados).
- **Incidentes:**
  - **2001:** a **Verisign** emitiu **dois certificados** para alguém que **se passou por representante da Microsoft**.
  - **Comodo:** uma **conta de uma RA** foi comprometida e o atacante gerou certificados falsos para **Google, Yahoo, Skype**… Foram **revogados** em horas.
- **Colisões de hash atacam certificados:** colisões de MD5 podem ser achadas até em strings que seguem **formatos de certificados digitais**; o ataque de **prefixo escolhido** ao SHA-1 (2020) permite **forjar certificados** [AND §5.6.1]. A CA assina um **hash** do certificado.

---

## 8. Onde o certificado aparece
- **Envelope digital:** se Bob obteve a chave pública de Alice **por meio do certificado dela**, tem **garantia de que a chave é válida** [STA §2.4].
- **Não repúdio:** Alice pode alegar que sua identidade foi **vinculada incorretamente no certificado** [BIS §10.5].
- **TLS, IPsec, SSH, S/MIME** usam X.509 [STA].

---

## ⚠️ Pegadinhas de prova
- A CA assina com a **chave PRIVADA da CA**; qualquer um verifica com a **chave PÚBLICA da CA**.
- O certificado **não contém a chave privada** do usuário, só a **pública** + identidade + validade + assinatura da CA.
- O certificado **não cifra dados**: ele **vincula** uma chave pública a uma identidade.
- **Expirado ≠ revogado.**
- **Autoassinado** = âncora de confiança (raiz). Sua confiança vem de fora da cadeia (*out of band*).
- A **RA verifica a identidade**, a **CA emite e assina**.
