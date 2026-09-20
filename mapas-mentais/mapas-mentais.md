# Mapas mentais: Segurança Digital

> Feitos a partir dos resumos em `resumos/` (fontes: [STA], [BIS], [AND], [AT01], [AT03]). O Obsidian desenha os blocos `mermaid` como mapa mental no modo leitura.

---

## 0. Visão geral da prova

```mermaid
mindmap
  root((Segurança Digital))
    Tríade CIA
      Confidencialidade
      Integridade
      Disponibilidade
      Extras: autenticidade e responsabilização
    Criptografia
      Princípios
        Kerckhoffs
        Confusão e difusão
        Simétrica
        Assimétrica
      Cifra de César
        Deslocamento k
        26 chaves
        Monoalfabética
      Hashing
        Tamanho fixo
        Pré-imagem
        Colisões
        Salt
    Identidade e acesso
      Identificação
      Autenticação
        Sabe
        Tem
        É
        Faz ou onde está
        MFA
      Autorização
        DAC MAC RBAC ABAC
        Menor privilégio
    Confiança
      Não repúdio
        Assinatura digital
        MAC não serve
      Certificados
        CA e RA
        X.509
        CRL e OCSP
```

---

## 1. Tríade CIA

```mermaid
mindmap
  root((CIA))
    Confidencialidade
      Def STA: não revelar a não autorizados
      Def BIS: ocultação de informação e recursos
      Subconceitos STA
        Confidencialidade de dados
        Privacidade
      Perda: divulgação não autorizada
      Need to know
      Existência do dado e ocultação de recursos
      Mecanismos: controle de acesso e criptografia
      Anderson
        Sigilo: efeito dos mecanismos
        Confidencialidade: obrigação
        Privacidade: direito
    Integridade
      Def STA
        Integridade de dados
        Integridade de sistema
      Def BIS: confiabilidade
        Integridade de dados: conteúdo
        Integridade de origem: autenticação
      Perda: modificação ou destruição não autorizada
      Mecanismos
        Prevenção
        Detecção
      FIPS 199 inclui não repúdio e autenticidade
      Autenticidade é integridade mais frescor
    Disponibilidade
      Def STA: serviço não negado a autorizados
      Def BIS: capacidade de usar
      Perda: interrupção do acesso
      Ataque típico: DoS
      Difícil de detectar: modelo estatístico
    Impacto FIPS 199
      Baixo: limitado
      Moderado: sério
      Alto: severo ou catastrófico
    Ameaças RFC 4949
      Divulgação: confidencialidade
      Engano: integridade
      Interrupção: disponibilidade
      Usurpação: integridade do sistema
```

---

## 2. Hashing

```mermaid
mindmap
  root((Hashing))
    Definição
      Entrada de tamanho variável
      Saída de tamanho fixo
      Impressão digital dos dados
      Sem chave secreta
    Propriedades STA
      Qualquer tamanho de entrada
      Saída fixa
      Fácil de calcular
      Pré-imagem: unidirecional
      Segunda pré-imagem: colisão fraca
      Colisão: colisão forte
      1 a 5: hash fraco
      1 a 6: hash forte
    Colisões
      Sempre existem: casa dos pombos
      Segurança: inviável encontrar
      Esforço 2 elevado a n sobre 2
      Paradoxo do aniversário
    Algoritmos
      MD4 e MD5: 128 bits, quebrados
      SHA-1: 160 bits, colisão 2017
      SHA-2: 256 384 512
      SHA-3: Keccak
    Aplicações
      Autenticação de mensagem
      HMAC
      Assinatura digital
      Senhas
      Detecção de intrusão
      Merkle, Git, PoW
    Senhas
      Salt aleatório em claro
        Senhas iguais geram hashes diferentes
        Dicionário offline mais caro
        Esconde reuso entre sistemas
      Hash lento: bcrypt, Argon2
      Ataques
        Força bruta
        Dicionário offline e online
        Rainbow table
    Hash vs cifra
      Hash: unidirecional sem chave
      Cifra: bidirecional com chave
```

---

## 3. Cifra de César

```mermaid
mindmap
  root((Cifra de César))
    História
      Júlio César: deslocamento 3, A vira D
      Augusto: deslocamento 2, A vira C
      Provenzano preso em 2006
      Worm de Morris 1988
    Fórmulas
      A=0 até Z=25
      Cifrar: m mais k mod 26
      Decifrar: c menos k mod 26
      Chave inversa: 26 menos k
      K vai de 0 a 25
    Classificação
      Simétrica
      Substituição
      Monoalfabética
      Vigenère com chave de 1 letra
    Fraquezas
      Só 26 chaves
      Força bruta: cerca de 13 tentativas
      Preserva frequência das letras
      Texto claro conhecido: 1 letra dá k
      Não protege integridade
    Não é chave pública
      26 menos k sai direto de k
      As duas chaves precisam ser secretas
    Exemplos
      HELLO vira KHOOR
      XYZ vira ABC
      KHOOR ZRUOG vira HELLO WORLD
```

---

## 4. Princípios da criptografia

```mermaid
mindmap
  root((Criptografia))
    Termos
      Criptografia: escrita secreta
      Criptoanálise: quebrar
      Criptologia: ambas
      Criptossistema E D M K C
    Serviços BIS
      Sigilo contra divulgação
      Integridade contra modificação e mascaramento
      Não repúdio contra repúdio de origem
    Princípios
      Kerckhoffs: algoritmo conhecido
      Projeto aberto: chave secreta
      Confusão: substituir
      Difusão: espalhar
    Ataques
      Criptoanálise
      Força bruta: metade das chaves
      Só texto cifrado
      Texto claro conhecido
      Texto claro escolhido
    Simétrica
      Mesma chave
      5 ingredientes
      Bloco: DES 3DES AES
      Fluxo: keystream XOR
      Clássicas
        Transposição
        Substituição
    Assimétrica
      Diffie e Hellman 1976
      Par de chaves pública e privada
      Pública do destinatário: sigilo
      Privada do emissor: autenticação
      RSA DH DSS ECC
      Envelope digital
```

---

## 5. Identificação, Autenticação e Autorização

```mermaid
mindmap
  root((IAA))
    Identificação
      Quem você diz que é
      Identidade: representação da entidade
      Principal: entidade única
      Usos: responsabilização e controle de acesso
    Autenticação
      NIST: estabelecer confiança na identidade
      STA: verificar que credenciais são válidas
      BIS: vincular identidade a sujeito
      Fatores
        Sabe: senha e PIN
        Possui: token e cartão
        É: biometria estática
        Faz: biometria dinâmica
        Onde está: localização
      MFA
        Fatores de tipos diferentes
        Senha mais pergunta não é MFA
        Separação de privilégio
      Modelo NIST
        RA CSP
        Assinante e credencial
        Reclamante e verificador
        Parte confiante
    Autorização
      Conceder direito de acesso
      Vem depois da autenticação
      Controle de acesso impõe política
      Políticas
        DAC: identidade
        MAC: rótulos e habilitações
        RBAC: papéis
        ABAC: atributos
      Sujeito, objeto, direito
      Menor privilégio
      Fail-safe defaults
      Mediação completa
    Auditoria
      Registros e rastreabilidade
```

---

## 6. Autenticidade e Não Repúdio

```mermaid
mindmap
  root((Não repúdio))
    Autenticidade
      Genuíno e verificável
      Integridade de origem
      Integridade mais frescor
    Responsabilização
      Rastrear ação até a entidade
      Suporta não repúdio
      Logs e forense
    Repúdio: ameaça
      Negar ter enviado
      Negar ter recebido
      Classe engano: integridade
    MAC
      Chave compartilhada
      Dá integridade e origem
      Não dá não repúdio
      Sem confidencialidade
    Assinatura digital
      FIPS 186-4
        Autenticação de origem
        Integridade
        Não repúdio do signatário
      Comprovável a um juiz
      Assina com chave privada
      Verifica com chave pública
      Assina o hash
      Sem confidencialidade
      DSA RSA ECDSA
    Limite
      Técnico: prova que a chave foi usada
      Chave roubada exige evidência extra
```

---

## 7. Certificados digitais

```mermaid
mindmap
  root((Certificados))
    Problema
      Chave pública forjada
      Falsário lê mensagens e se passa por Bob
    Definição
      Chave pública mais ID do dono
      Assinado por terceira parte confiável
      Validade e dados do emissor
      Vincula identidade a chave
    Emissão
      Cliente gera par de chaves
      Envia certificado não assinado
      CA faz hash e assina com chave privada
    Verificação
      Hash do certificado
      Verifica com chave pública da CA
      Checa validade
    X.509
      Usado em TLS IPsec SSH S/MIME
      v3: 11 campos
      Nome distinto DN
    PKI
      CA emite
      RA verifica identidade
      Cadeia de certificados
      Certificação cruzada
      Autoassinado: âncora de confiança
    Fim de vida
      Expirado: prazo acabou
      Revogado: chave comprometida
      CRL: lista assinada
      OCSP: good revoked unknown
    Confiança
      Depende da política da CA
      Verisign e Microsoft 2001
      RA da Comodo comprometida
```
