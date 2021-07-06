#include <stdio.h>
#include <locale.h>
#include <conio.h>
#include <string.h>
#define QUANT 5
#define QUANT2 100
#define MAX_CPF
#define MAX_VA

int main(){
    
    setlocale(LC_ALL,"portuguese");
 
    struct cadastro{
        char Nome[QUANT2];
        char Nascimento[12];
        char CPF[11];
        char Sexo;
        int Idade;
        char Internado;
    };

    int uti=0, enf=0, contCad=0, internadosUti=0, internadosEnf=0, dead=0, alta=0, x=1, repetido=0, confirmacao=0, i, j, menu, subMenu;
    char aux[10];
    
    //criando struct para cadastro de pacientes.
    struct cadastro paciente [QUANT];
    do{

        printf ("\t\tSISTEMA HOSPITALAR\n");
        printf ("\t\t Escolha a opção:\n");
        printf ("    [1]Primeiro Atendimento   [2]Internar Paciente (apenas para pacientes já cadastrados)\n");
        printf ("    [3]Liberar Paciente       [4]Fechar Plantão\n");
        
        fflush(stdin);
        scanf ("%d", &menu);

        //OPÇÃO 1= inciando menu do primeiro internamento
        if (menu==1){
            //SUBMENU
            printf ("\t\tEscolha a opção:\n");
            printf("    [1]UTI\n    [2]Enfermaria\n");
            scanf("%d",&subMenu);
            
            //verificando se a uti está com a capacidade máxima
            if(subMenu==1 && uti<5){
                printf("\tIniciando Cadastro:\n CPF(Apenas Números): ");
                fflush(stdin);
                gets(paciente[contCad].CPF);
                printf ("Vagasj: %d\n", uti);

                for(i=0; i<contCad; i++){
                    for (j = 0; j <= 11; j++){
                        if (paciente[i].CPF[j] == paciente[contCad].CPF[j]){ //verificando se o cad já existe
                        repetido++;
                        }
                    }
                    if (repetido == 11){
                        printf ("Paciente Já Cadastrado. Número do Cadastro: %0d\n", (i+1));
                        confirmacao= 1;
                        contCad--;
                        repetido= 0; 
                        break;        
                    }
                    repetido= 0;
                }
                if (!confirmacao){
                //iniciando cadastro
                printf("Nome Completo: ");
                fflush(stdin);
                gets(paciente[contCad].Nome);
                printf("Data de Nascimento (Inserir com números e barras, ex: 11/02/1999): ");
                fflush(stdin);
                gets(paciente[contCad].Nascimento);
                printf("Sexo (Inserir F ou M): ");
                scanf ("%c", &paciente[contCad].Sexo);
                printf("Idade: ");
                scanf("%d", &paciente[contCad].Idade);
                
                paciente[contCad].Internado = 'S'; //verificação de internamento
                contCad++; //cad completo, a contadora já passa pro proximo cad.
                uti++; //contando até a capacidade maxima
                internadosUti++; // contando o num de internamentos do dia
                repetido=0; //zerando repetidos
                confirmacao=0; // zerando confirmação
                printf ("Vagas: %d\n", uti);
                }
                confirmacao=0;

                printf ("veio aqui");

            } else if (subMenu==2 && enf<=5){ //submenu ainda

                    //mesma verificação de dados para a enf
                    printf("\tIniciando Cadastro:\n CPF(Apenas Números): ");
                    fflush(stdin);
                    gets(paciente[contCad].CPF);

                for(i=0; i<contCad; i++){
                    for (j = 0; j <= 10; j++){
                        if (paciente[i].CPF[j] == paciente[contCad].CPF[j]){ //verificando se o cad já existe
                        repetido++;
                        }
                    }
                    if (repetido == 11){
                        printf ("Paciente Já Cadastrado. Número do Cadastro: %0d\n", (i+1));
                        confirmacao= 1;
                        contCad--;
                        repetido= 0; 
                        break;        
                    }
                    repetido= 0;
                }

                if (!confirmacao){
                //iniciando cadastro
                printf("Nome Completo: ");
                fflush(stdin);
                gets(paciente[contCad].Nome);
                printf("Data de Nascimento (Inserir com números e barras, ex: 11/02/1999): ");
                fflush(stdin);
                gets(paciente[contCad].Nascimento);
                printf("Sexo (Inserir F ou M): ");
                scanf ("%c", &paciente[contCad].Sexo);
                printf("Idade: ");
                scanf("%d", &paciente[contCad].Idade);
                
                paciente[contCad].Internado = 'S'; //verificação de internamento

                contCad++; //cad completo, a contadora já passa pro proximo cad.
                enf++; //contando até a capacidade maxima
                internadosEnf++; // contando o num de internamentos do dia
                repetido=0; //zerando repetidos
                confirmacao=0; // zerando confirmação 

                } 
            }
            else if (uti==5 || enf == 5){//caso a uti ou a enfermaria estejam lotadas.
                printf ("Capacidade maxíma preenchida.\n");
            }
        }
            //OPÇÃO 2= iniciando menu do internamento
            if(menu==2){
                //SUBMENU
                printf ("\t\tEscolha a opção:\n");
                printf("    [1]UTI\n    [2]Enfermaria\n"); //verificando onde o paciente será internado
                scanf("%d",&subMenu);

                if (subMenu==1 && uti<=5){
                    
                    printf(" CPF(Apenas Números): "); //verificando se o paciente ja tem cadastro
                    fflush(stdin);
                    gets(aux);
                    
                    for(i=0; i<contCad; i++){
                    for (j = 0; j <= 10; j++){
                        if (paciente[i].CPF[j] == aux[j]){ //verificando se o cad já existe
                        repetido++;
                        }
                    }
                    if (repetido == 10 && paciente[i].Internado=='S'){ // verificando se o cad já existe e se o paciente já está internado
                        printf ("Paciente Já Internado\n");
                        repetido= 0; 
                        break;

                    } else if (repetido == 10 && paciente[i].Internado == 'N'){
                        printf ("Internando Paciente....\n");
                        printf ("Paciente Internado.\n");

                        repetido= 0; //zerando o contador do CPF
                        internadosUti++; // contando o num de internamentos do dia
                        uti++; //contador da uti
                        confirmacao= 1; 
                        break;
                    }
                    repetido= 0;
                    }
                    if(!confirmacao){
                        printf("Paciente não encontrado");
                        confirmacao= 0; //zerando confirmação novamente
                    }
                
                    if(subMenu==2 && enf<=5){ //ainda submenu
                        printf(" CPF(Apenas Números): "); //verificando se o paciente ja tem cadastro
                        fflush(stdin);
                        gets(aux);
                        
                        for(i=0; i<contCad; i++){
                            for (j = 0; j <= 10; j++){
                                if (paciente[i].CPF[j] == aux[j]){ //verificando se o cad já existe
                                    repetido++;
                                }
                            }
                            if (repetido == 10 && paciente[i].Internado=='S'){ // verificando se o cad já existe e se o paciente já está internado
                                printf ("Paciente Já Internado\n");
                                repetido= 0; 
                                break;
                                } else if(repetido == 10 && paciente[i].Internado == 'N'){
                                    printf ("Internando Paciente....\n");
                                    printf ("Paciente Internado.\n");

                                    repetido= 0; //zerando o contador do CPF
                                    internadosEnf++; // contando o num de internamentos do dia
                                    enf++; //contador da uti
                                    confirmacao= 1; 
                                    break;
                        }
                        repetido= 0;
                        }
                        if(!confirmacao){
                            printf("Paciente não encontrado");
                            confirmacao=0;
                        }
                            if(uti==5 || enf ==5){
                                printf ("Capacidade maxima preenchida.\n Não foi possível internar o paciente!\n");
                            }
                    }
                }
            }
                //Opção 3= Liberar paciente
                if(menu==3){
                    
                    printf(" CPF(Apenas Números): "); //verificando o cadastro do paciente
                    fflush(stdin);
                    gets(aux);
                    
                    for(i=0; i<contCad; i++){
                        for (j = 0; j <= 10; j++){
                            if (paciente[i].CPF[j] == aux[j]){ //verificando se o cad já existe
                                repetido++;
                            }
                        }
                        if (repetido == 10 && paciente[i].Internado=='S'){ // verificando se o cad já existe e se o paciente já está internado
                            //SUBMENU
                            printf ("\t\tEscolha a opção:\n");
                            printf("    [1]UTI\n    [2]Enfermaria\n"); //verificando onde o paciente será internado
                            scanf("%d",&subMenu);

                            if (subMenu==1){ //uti
                              
                                printf ("\t\tLiberado por:\n");
                                printf("    [1]Alta\n    [2]Falecimento\n"); //verificando se o paciente (voz do tiririca aqui) "Morreeeeeu" kkk
                                scanf("%d",&subMenu);

                                if(subMenu==1){ //submenu liberação
                                printf ("Liberando Paciente...\n");
                                printf("Paciente Liberado\n");
                                paciente[i].Internado = 'N';
                                uti--;
                                alta++;
                                }

                                if(subMenu==2){ //submenu liberação
                                printf ("Liberando Paciente...\n");
                                printf("Paciente Liberado\n");
                                paciente[i].Internado = 'N';
                                uti--;
                                dead++;
                                }  
                            }
                            
                            if (subMenu==2){ //enfermaria
                                
                                printf ("\t\tLiberado por:\n");
                                printf("    [1]Alta\n    [2]Falecimento\n"); //verificando se o paciente (voz do tiririca aqui) "Morreeeeeu" kkk
                                scanf("%d",&subMenu);

                                if(subMenu==1){ //submenu liberação
                                    printf ("Liberando Paciente...\n");
                                    printf("Paciente Liberado\n");
                                    paciente[i].Internado = 'N';
                                    enf--;
                                    alta++;
                                }

                                if(subMenu==2){ //submenu liberação
                                    printf ("Liberando Paciente...\n");
                                    printf("Paciente Liberado\n");
                                    paciente[i].Internado = 'N';
                                    enf--;
                                    dead++;
                                }
                            }   
                        }
                    } 
                    repetido= 0;
                }            
                if(menu==4){ //fechar plantão
                    printf ("Total de internações: %d \n", (internadosUti+internadosEnf));
                    printf ("Fluxo de internações - UTI: %d | Enfermaria: %d", internadosUti, internadosEnf);
                    printf ("Liberações - Altas %d | Falecimentos: %d ", alta, dead);
                }
    }while(x==1);
    return 0;
}

