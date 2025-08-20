#include <stdio.h>  
#include <locale.h>  
// função definida para as viriáveis das cartas
typedef struct {
    char estado[50];          
    char codigo_carta[5];     
    char cidade[100];
    char cidade2[100];
    int escolhaPlayer;         
    int populacao, populacao2;            
    int pontos_turisticos, pontos_turisticos2;    
    float pib, pib2;                
    float area, area2; 
    float densidade1, densidade2;
    float percapta1, percapta2;              
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
    scanf("%s", carta.estado);

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
    carta.densidade2 = carta.populacao/carta.area;
    carta.percapta2 = carta.pib/carta.populacao;

    //amostragem da densidade e pib percapta da carta 2
    printf("Densidade populacional: %.2f\n",carta.densidade2);
    printf("Pib per capta: %.2f\n", carta.percapta2);

    //menu interativo
    printf("--Vamos ver qual a melhor carta--\n");
    printf("Escolha abaixo o atributo que deve ser comparado\n");
    printf("1. Nome da Cidade.\n"); 
    printf("2.População\n");  
    printf("3.Área\n"); 
    printf("4.PIB\n"); 
    printf("5.Pontos Turísticos\n"); 
    printf("6.Densidade demográfica\n");
    scanf("%i", &carta.escolhaPlayer);
    
    //lógica para carta vencedora
    switch (carta.escolhaPlayer)
    {
    case 1:
        printf("%s\n", carta.cidade);
        printf("%s", carta.cidade2);
    break;
    case 2:
        if (carta.populacao > carta.populacao2){
            printf("A carta 1 venceu!\n");
            printf("A cidade %s tem a população de: %i", carta.cidade, carta.populacao);
        }else{
            printf("A carta 3 venceu!\n");
            printf("A cidade %s tem a população de: %i", carta.cidade2, carta.populacao2);
        }        
    break;
    case 3:
        if (carta.area > carta.area2)
        {
            printf("Carta 1 venceu!\n");
            printf("A Área da cidade %s é de %f", carta.cidade, carta.area);
        }else{
            printf("Carta 2 venceu!\n");
            printf("A Área da cidade %s é de %f", carta.cidade2, carta.area2);
        }
        
    break;
    case 4:
           if (carta.pib > carta.pib2)
        {
            printf("Carta 1 venceu! \n");
            printf("O PIB da cidade %s é de %f", carta.cidade, carta.pib2);
        }else{
            printf("Carta 2 venceu! \n");
            printf("O PIB Área da cidade %s é de %f", carta.cidade2, carta.pib2);
        }

    break;
    case 5:
           if (carta.pontos_turisticos > carta.pontos_turisticos2)
        {
            printf("Carta 1 venceu!\n");
            printf("O número de pontos da cidade %s é de %i", carta.cidade, carta.pontos_turisticos);
        }else{
            printf("Carta 2 venceu!\n");
            printf("O número de pontos da cidade %s é de %i", carta.cidade2, carta.pontos_turisticos2);
        }
    break;
    case 6:
           if (carta.densidade1 > carta.densidade2)
        {
            printf("Carta 1 venceu!\n");
            printf("A Densidade da cidade %s é de %f", carta.cidade, carta.densidade1);
        }else{
            printf("Carta 2 venceu!\n");
            printf("A Densidade da cidade %s é de %f", carta.cidade2, carta.densidade2);
        }
    break;
    default:
        printf("Opção Inválida");
    break;
    }
    return 0;
}
