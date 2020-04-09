#define TRUE 1
#define FALSE 0
#define ESQUERDA 1
#define DIREITA 0

typedef int** TabelaSomas;
typedef int** TPiramide;

TPiramide recebe_piramide(int *Nlinhas);//recebe a pirâmide do arquivo texto e aloca a matriz dinâmicamente
TabelaSomas recebe_tabela(TPiramide piramide, int Nlinhas);//Calcula a maior distancia entre os números da matriz (resolução dos subproblemas)
void imprime_caminho(TPiramide piramide, TabelaSomas tabela, int i, int j, int Nlinhas);//imprime caminho de maior soma
int Max(TPiramide piramide, int i, int j, int Nlinhas);//Algoritmo recursivo exponencial para a resolução do problema da pirâmide
