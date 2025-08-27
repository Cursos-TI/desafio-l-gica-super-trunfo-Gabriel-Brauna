#include <stdio.h>  
#include <locale.h>  
// função definida para as viriáveis das cartas
typedef struct {
    char estado[50]; 
    char estado2[50];         
    char codigo_carta[5];     
    char cidade[100];
    char cidade2[100];
    int escolha, escolha2, escolha3, escolha4;
    int escolhaPLayer;         
    int populacao, populacao2;            
    int pontos_turisticos, pontos_turisticos2; 
    float soma1, soma2;   
    float pib, pib2;                
    float area, area2; 
    float densidade1, densidade2;
    float percapta1, percapta2; 
    float resultado1, resultado2;             
} CartaDoJogo;

int main() {
    //estrtura para aceitar acentuação em português brasiliero
    setlocale(LC_ALL, "Portuguese"); 

    CartaDoJogo carta; // Puxa as variáveis declaradas na outra função

    //inicio da coleta dos dados das carta 1
    printf("--- Cadastro de Carta de Jogo ---\n\n");

 
    printf("Digite o Estado Brasileiro (ex: SaoPaulo): ");
    scanf("%s", carta.estado);

    printf("Digite o Código da Carta (ex: a01, h04): ");
    scanf("%s", carta.codigo_carta);

    printf("Digite o Nome da Cidade (sem espacos): ");
    scanf("%s", carta.cidade);

    printf("Digite a Quantidade de População (apenas numeros inteiros): ");
    scanf("%d%*c", &carta.populacao);

    printf("Digite a Quantidade de Pontos Turísticos (apenas numeros inteiros): ");
    scanf("%d%*c", &carta.pontos_turisticos);
 
    printf("Digite o PIB da Cidade (ex: 12345.67): "); 
    scanf("%f%*c", &carta.pib);
  
    printf("Digite a Área da Cidade em km² (ex: 500.25): ");
    scanf("%f%*c", &carta.area);

    //Impressão dos dados da carta 1
    printf("\n--- Informacoes da Carta Cadastrada ---\n");
    printf("Estado Brasileiro: %s\n", carta.estado);
    printf("Codigo da Carta: %s\n", carta.codigo_carta);
    printf("Cidade: %s\n", carta.cidade);
    printf("Populacao: %d habitantes\n", carta.populacao);
    printf("Pontos Turisticos: %d\n", carta.pontos_turisticos);
    printf("PIB da Cidade: R$ %.2f\n", carta.pib); 
    printf("Area da Cidade: %.2f km²\n", carta.area); 

    carta.densidade1 = carta.populacao/carta.area;
    carta.percapta1 = carta.pib/carta.populacao;

    printf("Densidade populacional: %.2f\n",carta.densidade1);
    printf("Pib per capta: %.2f\n", carta.percapta1);

    //coleta de dados da carta 2
    printf("--Cadastre a segunda carta--\n");

    printf("Digite o Estado Brasileiro (ex: SaoPaulo): ");
    scanf("%s", carta.estado2);

    printf("Digite o Código da Carta (ex: a01, h04): ");
    scanf("%s", carta.codigo_carta);

    printf("Digite o Nome da Cidade (sem espacos): ");
    scanf("%s", carta.cidade2);

    printf("Digite a Quantidade de População (apenas numeros inteiros): ");
    scanf("%d%*c", &carta.populacao2);

    printf("Digite a Quantidade de Pontos Turísticos (apenas numeros inteiros): ");
    scanf("%d%*c", &carta.pontos_turisticos2);

    printf("Digite o PIB da Cidade (ex: 12345.67): "); 
    scanf("%f%*c", &carta.pib2);
  
    printf("Digite a Área da Cidade em km² (ex: 500.25): ");
    scanf("%f%*c", &carta.area2);

    //dados da carta 2 imprimidas
    printf("\n--- Informacoes da Carta Cadastrada ---\n");
    printf("Estado Brasileiro: %s\n", carta.estado);
    printf("Codigo da Carta: %s\n", carta.codigo_carta);
    printf("Cidade: %s\n", carta.cidade);
    printf("Populacao: %d habitantes\n", carta.populacao);
    printf("Pontos Turisticos: %d\n", carta.pontos_turisticos);
    printf("PIB da Cidade: R$ %.2f\n", carta.pib); 
    printf("Area da Cidade: %.2f km²\n", carta.area); 

    //calculo de densidade populacional e pib per capta carta 2
    carta.densidade2 = carta.populacao2/carta.area2;
    carta.percapta2 = carta.pib2/carta.populacao2;

    //amostragem da densidade e pib percapta da carta 2
    printf("Densidade populacional: %.2f\n",carta.densidade2);
    printf("Pib per capta: %.2f\n", carta.percapta2);

    //menu interativo
    printf("--Vamos ver qual a melhor carta--\n");
    printf("Escolha o tipo de comparação que quer fazer:\n");
    printf("1. Nome do Estado e Cidade (Este apenas exibirá os nomes).\n"); 
    printf("2.Você escolhe dois desses atributos de cada carta (População, Área, Pib, Pontos Turísticos)\n");                                                                                                                             
    printf("3.Comparação da densidade demográfica\n"); 
    scanf("%d", &carta.escolhaPLayer);
       
   
    //lógica para carta vencedora
    switch (carta.escolhaPLayer)
    {
    case 1:
        printf("%s\n", carta.estado);
        printf("%s\n", carta.estado2);
        printf("-----------------------------------");
        printf("%s\n", carta.cidade);
        printf("%s\n", carta.cidade2);
    break;
    case 2:   
        //na segunda opção o usuário vai escolher atributo por atributo das duas cartas até escolher dois de cada
        printf("Escolha qual primeiro atributo da primeira carta\n");
        printf("1.População\n");
        printf("2.Área\n");
        printf("3.PIB\n");
        printf("4.Pontos Turísticos\n");
        scanf("%d", &carta.escolha);

        if (carta.escolha == 1){
            carta.escolha = carta.populacao;
            printf("Você escolheu a população da cidade: %s\n", carta.cidade);
        }else if (carta.escolha == 2){
            carta.escolha = carta.area;
            printf("Você escolheu a área da cidade: %s\n", carta.cidade);
        }else if(carta.escolha == 3){
            carta.escolha = carta.pib;
            printf("Você escolheu o PIB da cidade: %s\n", carta.cidade);
        }else if(carta.escolha == 4){
            carta.escolha = carta.pontos_turisticos;
            printf("Você escolheu os pontos turísticos da cidade: %s\n", carta.cidade);    
        }

        printf("Escolha qual segundo atributo da primeira carta\n");
        printf("1.População\n");
        printf("2.Área\n");
        printf("3.PIB\n");
        printf("4.Pontos Turísticos\n");
        scanf("%d", &carta.escolha2);

        //esse if começa com opção inválida caso o usuário escolha a mesma opção que a primira
        if (carta.escolha2 == carta.escolha){
            printf("Opção inválida!!");
        } 
        else if (carta.escolha2 == 1){
            carta.escolha2 = carta.populacao;
            printf("Você escolheu a população da cidade: %s\n", carta.cidade);    
        }
        else if (carta.escolha2 == 2){
            carta.escolha2 = carta.area;
            printf("Você escolheu a área da cidade: %s\n", carta.cidade);    
        }
        else if(carta.escolha2 == 3){
            carta.escolha2 = carta.pib;
            printf("Você escolheu o PIB da cidade: %s\n", carta.cidade); 
        }
        else if(carta.escolha2 == 4){
            carta.escolha2 = carta.pontos_turisticos; 
            printf("Você escolheu os pontos turísticos da cidade: %s\n", carta.cidade);     
        }

        printf("Escolha qual primeiro atributo da segunda carta\n");
        printf("1.População\n");
        printf("2.Área\n");
        printf("3.PIB\n");
        printf("4.Pontos Turísticos\n");
        scanf("%d", &carta.escolha3);

        if (carta.escolha3 == 1){
            carta.escolha3 = carta.populacao2;
            printf("Você escolheu a população da cidade: %s\n", carta.cidade2);
        }else if (carta.escolha3 == 2){
            carta.escolha3 = carta.area2;
            printf("Você escolheu a área da cidade: %s\n", carta.cidade2);
        }else if(carta.escolha3 == 3){
            carta.escolha3 = carta.pib2;
            printf("Você escolheu o PIB da cidade: %s\n", carta.cidade2);
        }else if(carta.escolha3 == 4){
            carta.escolha3 = carta.pontos_turisticos2;
            printf("Você escolheu os pontos turísticos da cidade: %s\n", carta.cidade2);    
        }

        printf("Escolha qual segundo atributo da segunda carta\n");
        printf("1.População\n");
        printf("2.Área\n");
        printf("3.PIB\n");
        printf("4.Pontos Turísticos\n;");
        scanf("%d", &carta.escolha4);

        //esse if começa com opção inválida caso o usuário escolha a mesma opção que a primira
        if (carta.escolha4 == carta.escolha3){
            printf("Opção inválida!");
        }
         else if (carta.escolha4 == 1){
            carta.escolha4 = carta.populacao2;
            printf("Você escolheu a população da cidade: %s\n", carta.cidade2);
        }else if (carta.escolha4 == 2){
            carta.escolha4 = carta.area2;
            printf("Você escolheu a área da cidade: %s\n", carta.cidade2);
        }else if(carta.escolha4 == 3){
            carta.escolha4 = carta.pib2;
            printf("Você escolheu o PIB da cidade: %s\n", carta.cidade2);
        }else if(carta.escolha4 == 4){
            carta.escolha4 = carta.pontos_turisticos2;
            printf("Você escolheu os pontos turísticos da cidade: %s\n", carta.cidade2);    
        }

        //variavel da soma dos atributos escolhidos
        carta.soma1 = carta.escolha + carta.escolha2;
        carta.soma2 = carta.escolha3 + carta.escolha4;

        //amostragem do resultado na tela
        if (carta.soma1 > carta.soma2){
            printf("---------------------------------------\n");
            printf("O valor dos atributos escolhidos da primeira carta é: %2.f\n", carta.soma1);
            printf("O valor dos atributos escolhidos da segunda carta é: %2.f\n", carta.soma2);
            printf("---------------------------------------\n");
            printf("A carta da cidade: %s -->É a vencedora!\n", carta.cidade);
            printf("---------------------------------------\n");    
        }else if(carta.soma1 < carta.soma2){
            printf("---------------------------------------\n");
            printf("O valor dos atributos escolhidos da primeira carta é: %2.f\n", carta.soma1);
            printf("O valor dos atributos escolhidos da segunda carta é: %2.f\n", carta.soma2);
            printf("---------------------------------------\n");
            printf("A carta da cidade: %s -->É a vencedora!\n", carta.cidade2);
            printf("---------------------------------------\n"); 
        }else{
            printf("---------------------------------------\n");
            printf("O valor dos atributos escolhidos da primeira carta é: %2.f\n", carta.soma1);
            printf("O valor dos atributos escolhidos da segunda carta é: %2.f\n", carta.soma2);
            printf("---------------------------------------\n");
            printf("As cartas deram o mesmo resultado: -->Empate!\n"); 
            printf("---------------------------------------\n");
        }
    break;
    case 3:
        if (carta.densidade1 > carta.densidade2){
            printf("---------------------------------------\n");
            printf("A densidade demográfica da cidade: %s é: %f\n", carta.cidade, carta.densidade1);
            printf("A densidade demográfica da cidade: %s é: %f\n", carta.cidade2, carta.densidade2);
            printf("---------------------------------------\n");
            printf("Vencedor é cidade: %s\n", carta.cidade2);
            printf("---------------------------------------\n");
        }else if (carta.densidade1 < carta.densidade2)
        {
            printf("---------------------------------------\n");
            printf("A densidade demográfica da cidade: %s é: %f\n", carta.cidade, carta.densidade1);
            printf("A densidade demográfica da cidade: %s é: %f\n", carta.cidade2, carta.densidade2);
            printf("---------------------------------------\n");
            printf("Vencedor é cidade: %s\n", carta.cidade);
            printf("---------------------------------------\n");
        }else{
            printf("---------------------------------------\n");
            printf("A densidade demográfica da cidade: %s é: %f\n", carta.cidade, carta.densidade1);
            printf("A densidade demográfica da cidade: %s é: %f\n", carta.cidade2, carta.densidade2);
            printf("---------------------------------------\n");
            printf("Houve um empate!\n");
            printf("---------------------------------------\n");
        }     
    break;
    //caso o usuário não escolha nenhuma das opções de comparação das cartas
    default:
        printf("Opção Inválida");
    break;
    }
    return 0;
}
