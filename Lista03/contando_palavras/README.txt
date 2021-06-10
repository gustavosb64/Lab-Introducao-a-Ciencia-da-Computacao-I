Descrição
Escreva um programa em c que conte o número de caracteres, palavras e linhas de um arquivo e imprima esses valores no seguinte formato:

printf("Linhas\tPalav.\tCarac.\n");
printf("%d\t%d\t%d", n_linhas, n_palavras, n_chars);
Uma palavra é definida como uma sequência de caracteres quaisquer (ASCII) que não sejam ' ', '\t', '\n' nem '\r'. Ou seja, a frase "hello, world\n" é composta de duas palavras e a frase "h e l l o" seria composta de 5 palavras. Como um outro exemplo, também é possível ter uma sequência de caracteres que não compões palavra alguma: "\t\n \r\n \n\n" . Além disso seu programa deverá tolerar tipos diferentes de indicadores de pula linha. Existem 3 possibilidades de formatos de pula linha: '\n', "\r\n" e somente '\r'. Cada um desses formados pode ser usado para indicar uma nova linha.

Esse programa se assemelha do utilitário wc do sistema operacional Linux e é muito utilizado, as vezes diariamente, por usuários do sistema.

Atenção: Ao final de todas as linhas, um caractere especial será lido: o End Of File, ouEOF. Esse caractere indica que não há mais entrada e seu programa deverá parar a leitura.

Exemplo 1:

Entrada: Hello, World!
Saída:
Linhas  Palav.  Carac.
1       2       14
Exemplo 2:

Entrada:
Lorem ipsum dolor sit amet consectetur adipisicing elit. Maxime mollitia,
molestiae quas vel sint commodi repudiandae consequuntur voluptatum laborum
numquam blanditiis harum quisquam eius sed odit fugiat iusto fuga praesentium
optio, eaque rerum! Provident similique accusantium nemo autem. Veritatis
obcaecati tenetur iure eius earum ut molestias architecto voluptate aliquam
nihil, eveniet aliquid culpa officia aut! Impedit sit sunt quaerat, odit,
tenetur error, harum nesciunt ipsum debitis quas aliquid.
Saída:
Linhas  Palav.  Carac.
7       68      510
Dica de implementação
Pesquise um pouco sobre a função ungetc e veja se ela lhe pode ser útil.

Desafio adicional
Note: Desafios adicionais não devem ser entregues em lugar algum. Eles são propostas para pessoas com interesse de ir um pouco além do exercício proposto e, com sorte, se divertir no processo.

A implementação original do wc também consegue abrir e ler arquivos. Implemente essa funcionalidade, passando o nome do arquivo a ser aberto por argumento.
