# Diretrizes de Estudo — Segurança Digital

## 1. Objetivo

Este documento define as regras e orientações para os estudos da disciplina **Segurança Digital**, do curso de **Engenharia de Software**.

O objetivo é auxiliar na **compreensão, revisão e retenção do conteúdo**, utilizando exclusivamente os materiais disponibilizados na estrutura de estudos definida neste documento.

Todo conteúdo produzido durante os estudos deve ser fundamentado nos materiais presentes em `study-content`.

---

## 2. Estrutura dos Materiais

Todos os materiais utilizados nos estudos estarão organizados dentro do diretório `study-content`.

A estrutura é:

```text
study-content/
├── books/       # Livros e bibliografia principal da disciplina
├── exercises/   # Exercícios propostos pelo professor e respostas
└── others/      # Outros materiais disponibilizados para estudo
```

### 2.1. `books`

Contém os **livros e materiais bibliográficos principais** utilizados na disciplina.

Esses materiais possuem **maior prioridade** como fonte de conhecimento.

Sempre que houver informações disponíveis em `books`, elas devem ter preferência sobre informações provenientes de `others`.

### 2.2. `exercises`

Contém exercícios propostos pelo professor e suas respectivas respostas.

Esses arquivos podem ser utilizados para:

- identificar os conteúdos cobrados na disciplina;
    
- compreender o estilo das questões;
    
- criar novas questões baseadas nos mesmos conteúdos;
    
- criar simulados;
    
- identificar possíveis pontos de dificuldade;
    
- revisar conceitos já trabalhados.
    

Os exercícios **não devem ser tratados como uma fonte independente de conhecimento quando a resposta depender de uma explicação que esteja disponível nos livros**. Sempre que possível, deve-se relacionar a questão ao conteúdo correspondente em `books`.

### 2.3. `others`

Contém materiais complementares disponibilizados para auxiliar nos estudos.

Esses materiais podem ser utilizados quando o conteúdo necessário não estiver suficientemente desenvolvido em `books` ou `exercises`.

---

# 3. Regra Fundamental de Fontes

Todo conhecimento utilizado para produzir conteúdo de estudo deve estar presente em pelo menos um dos diretórios:

```text
books/
exercises/
others/
```

**Não devem ser utilizados conhecimentos externos aos materiais disponibilizados.**

Isso significa que:

- não utilizar conhecimento próprio do modelo para complementar uma explicação;
    
- não realizar pesquisas externas para preencher lacunas;
    
- não utilizar sites, artigos, vídeos ou outras fontes que não estejam presentes em `study-content`;
    
- não introduzir informações que não possam ser relacionadas ao material disponibilizado.
    

Quando determinado conteúdo **não estiver presente nos materiais**, deve-se informar que ele não pode ser abordado com base no conjunto de estudos disponível.

---

# 4. Hierarquia das Fontes

Quando houver informações sobre o mesmo assunto em diferentes diretórios, deve ser utilizada a seguinte prioridade:

```text
1. books
2. exercises
3. others
```

`books` possui prioridade por representar a bibliografia principal da disciplina.

Os `exercises` devem ser utilizados principalmente para compreender **como o conteúdo é cobrado**.

`others` deve ser utilizado como material complementar.

Quando houver divergência entre materiais, a divergência deve ser explicitada em vez de escolher silenciosamente uma das versões.

---

# 5. Criação de Conteúdo

Podem ser criados, entre outros:

- resumos;
    
- mapas mentais;
    
- flashcards;
    
- questões;
    
- simulados;
    
- explicações;
    
- revisões;
    
- listas de exercícios;
    
- tabelas comparativas.
    

Todo conteúdo novo deve ser construído **exclusivamente a partir de `study-content`**.

A criação de conteúdo novo não significa a criação de conhecimento novo.

Por exemplo, ao solicitar um resumo sobre determinado assunto, o resumo deve reorganizar e sintetizar as informações existentes nos materiais, sem acrescentar informações externas.

---

# 6. Resumos

Os resumos devem priorizar:

- conceitos fundamentais;
    
- definições;
    
- características;
    
- classificações;
    
- diferenças entre conceitos;
    
- exemplos presentes nos materiais;
    
- fórmulas, quando existentes;
    
- procedimentos e etapas;
    
- informações que possam ser cobradas em avaliações.
    

O resumo deve ser **objetivo e voltado para revisão**, evitando informações que não estejam presentes nas fontes.

Quando possível, conceitos relacionados devem ser apresentados em conjunto para facilitar a comparação e a retenção.

---

# 7. Mapas Mentais

Os mapas mentais devem representar a organização conceitual encontrada nos materiais.

Devem priorizar:

```text
Tema
├── Conceito
├── Características
├── Classificações
├── Componentes
├── Exemplos
└── Relações com outros conceitos
```

Não devem ser adicionados conceitos externos apenas para tornar o mapa mental mais completo.

---

# 8. Flashcards

Os flashcards devem ser construídos a partir dos conteúdos presentes em `study-content`.

Cada card deve trabalhar, preferencialmente, **um único conceito ou relação**.

Exemplo de estrutura:

```text
Pergunta:
O que é X?

Resposta:
Definição de X conforme o material.
```

As respostas devem permanecer ocultas quando os cards forem utilizados como material interativo.

---

# 9. Simulados

Os simulados devem ser armazenados no diretório:

```text
exams/
```

Cada arquivo de simulado deve conter **exatamente 10 questões**.

As questões devem ser elaboradas exclusivamente a partir dos conteúdos solicitados no prompt e encontrados em:

```text
study-content/
```

Os exercícios presentes em `exercises/` podem ser utilizados como referência para:

- formato das questões;
    
- nível de dificuldade;
    
- assuntos recorrentes;
    
- estilo de cobrança;
    
- construção de alternativas.
    

As questões do simulado não devem simplesmente copiar os exercícios existentes. Devem testar o conhecimento de forma equivalente, quando possível, preservando a fidelidade ao conteúdo estudado.

---

# 10. Questões por Tema

As questões individuais devem ser armazenadas no diretório:

```text
quests/
```

Deve existir **um arquivo para cada tema solicitado no prompt**.

Por exemplo:

```text
quests/
├── criptografia.md
├── funcoes-hash.md
├── assinaturas-digitais.md
└── autenticacao.md
```

Cada arquivo pode conter uma quantidade ilimitada de questões relacionadas ao respectivo tema.

As questões devem ser baseadas exclusivamente nos materiais disponíveis em `study-content`.

---

# 11. Respostas das Questões

Quando uma questão for apresentada para ser respondida pelo estudante, a resposta correta **não deve ficar imediatamente visível**.

A resposta deve permanecer ocultada e ser apresentada somente após sua expansão por meio de um mecanismo de **toggle**.

Exemplo:

```html
<details>
<summary>Ver resposta</summary>

Resposta correta: ...

Explicação: ...

</details>
```

Quando necessário, a resposta deve conter também uma explicação fundamentada no material de estudo.

---

# 12. Correção das Respostas

Quando o estudante responder uma questão, a correção deve:

1. verificar a resposta fornecida;
    
2. indicar se está correta ou incorreta;
    
3. apresentar a resposta correta, quando necessário;
    
4. explicar o motivo;
    
5. utilizar exclusivamente os materiais de `study-content`;
    
6. apontar o conceito do material relacionado à questão.
    

A correção não deve introduzir conhecimentos externos apenas para justificar a resposta.

Quando a resposta do estudante estiver parcialmente correta, deve ser indicado **qual parte está correta e qual parte precisa ser corrigida**.

---

# 13. Simulados a partir dos Exercícios

Os exercícios de `exercises/` podem ser utilizados como base para gerar novos simulados.

Entretanto, deve-se evitar simplesmente reproduzir as questões existentes.

É permitido:

- alterar o contexto da questão;
    
- modificar valores numéricos;
    
- inverter alternativas;
    
- combinar conceitos presentes nos materiais;
    
- criar uma questão conceitualmente equivalente;
    
- aumentar ou reduzir a dificuldade, desde que isso não exija conhecimento externo.
    

Não é permitido adicionar um conceito que não esteja presente em `study-content`.

---

# 14. Controle de Escopo

Sempre que o prompt especificar um ou mais temas, o conteúdo produzido deve permanecer dentro desses temas.

Por exemplo, se for solicitado:

```text
Crie um simulado sobre funções hash.
```

O simulado deve abordar somente os conteúdos relacionados a funções hash que estejam presentes nos materiais.

Não devem ser adicionados assuntos externos apenas porque possuem relação com o tema.

---

# 15. Ausência de Conteúdo

Caso seja solicitado um assunto que não esteja presente em:

```text
books/
exercises/
others/
```

não deve ser criado conteúdo baseado em conhecimento externo.

Nesse caso, informar claramente:

> "Esse conteúdo não foi encontrado nos materiais disponíveis em `study-content`."

Se houver apenas informações parciais, informar a limitação e utilizar somente aquilo que estiver disponível.

---

# 16. Princípio Geral

A regra principal deste sistema de estudos é:

> **O material disponibilizado em `study-content` é a fonte de verdade para os estudos.**

Todo resumo, questão, simulado, flashcard, explicação ou outro material produzido deve poder ser rastreado aos conteúdos presentes nesses arquivos.

A prioridade é:

```text
Fidelidade ao material
        ↓
Compreensão
        ↓
Revisão
        ↓
Retenção
        ↓
Preparação para avaliações
```

O objetivo não é adicionar o máximo possível de informação, mas **extrair, organizar e praticar o máximo possível do conhecimento presente nos materiais da disciplina**.