# AP2-Trab4
4º trabalho da matéria de Algoritmos e Programação 2 da faculdade

## Integrantes
<ul>
    <li>Marco Antonio Batista de Souza</li>
    <li>Rafael Romancini</li>
    <li>Guilherme França Soares</li>
</ul>

## Enunciado
<h3>Analista de reviews</h3>
<p>Uma tarefa muito comum no mundo dos dados é fazer análise de textos. Uma das formas de analisar descritivamente um texto é indicar estatísticas relacionadas às palavras e parágrafos nele contidas. Sua tarefa é criar um programa capaz de analisar descritivamente um conjunto de textos de reviews.
<p>Reviews são avaliações realizadas por usuários em relação a determinados produtos ou serviços. Por exemplo, no site TripAdvisor é possível encontrar as reviews feitas por usuários, referentes a lugares turísticos e hotéis. No site IMDB é possível encontrar as reviews feitas por usuários em relação aos filmes.
<p>Para a construção do programa, considere que dentro de um diretório chamado trabalho4 estão diversos arquivos binários. Cada arquivo contém uma review extraída de um site de viagens, que só autorizou a utilização dos dados no modo binário para respeitar a legislação geral de proteção de dados. Os arquivos são nomeados seguindo o padrão: rev1.bin, rev2.bin, rev3.bin, …
<p>As seguintes estatísticas serão consideradas na análise dos textos:

<ol>
    <li>Média do número de parágrafos por review.</li>
    <li>Maior palavra: exibir a maior palavra considerando todos os arquivos. Caso exista mais de uma, escolha a primeira encontrada para exibir.</li>
    <li>Menor palavra: exibir a menor palavra considerando todos os arquivos. Caso exista mais de uma, escolha a primeira encontrada para exibir.</li>
</ol>
<p>Uma palavra é definida como uma sequência de caracteres alfanuméricos (A-Za-z0-9). Um parágrafo ocorre quando: (i) existe um ‘\n’ seguido por um ‘\t’ ou (ii) é encontrada a indicação de EOF.
<p>O objetivo do programa é produzir um relatório contendo a análise realizada sobre as reviews. Exemplo de um relatório produzido pelo programa:
<p>1) Média do número de palavras por review: 34.1
<p>2) Média do número de parágrafos por review: 2.1
<p>3) Maior palavra: paralelepípedo
<p>4) Menor palavra: a
<p>
<p>O relatório deve ser escrito em um arquivo de saída, no formato texto, chamado relatorio.out, obedecendo a formatação fornecida pelo exemplo acima.
<p>Você também deve produzir, em um novo diretório chamado trabalho4texto, uma cópia dos arquivos de reviews, agora em formato texto, para efeitos de conferência do relatório produzido pelo programa. Os arquivos devem ser nomeados seguindo o padrão: rev1.txt, rev2.txt, rev3.txt, …