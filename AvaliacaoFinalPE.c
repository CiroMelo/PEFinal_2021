#include <stdio.h>
#include <string.h>
#define TAM 999

/*
constantes -
TAM: constante que define o tamanho do banco de dados

variáveis utilizadas:

relacionadas aos registros -
cliente[TAM]: vetor do tipo registro que armazena todos os dados de uma entrada no banco de dados
cliente[TAM].gasto_total: variável que armazena o somatório do valor de todo o dinheiro gasto nas compras associadas a um cliente
cliente[TAM].bonus: variável do tipo int que armazena a quantidade de pontos bônus
cliente[TAM].nome[50]: vetor do tipo char que acumula dados de uma entrada no banco de dados
cliente[TAM].cpf[12]: vetor do tipo char que acumula dados de uma entrada no banco de dados
cliente[TAM].telefone[15]: vetor do tipo char que acumula dados de uma entrada no banco de dados
cliente[TAM].email[30]: vetor do tipo char que acumula dados de uma entrada no banco de dados
cliente[TAM].ult_compra: variável do tipo registro que armazena informações relacionadas a última compra de uma entrada no banco de dados e o registro relacionado ao bônus
cliente[TAM].ult_compra.compra_cancelada: variável do tipo int que verifica se a última compra relacionada aquela entrada já foi cancelada
cliente[TAM].ult_compra.bonus_anterior: variavel do tipo int que armazena o valor de bonus antes da última compra, para restituir o cliente em caso de cancelamento de compra
cliente[TAM].ult_compra.outra_cancelada: variável do tipo int que verifica se outra compra foi cancelada antes da última compra ser cancelada/outra compra ser realizada
cliente[TAM].ult_compra.outra_valor: variável do tipo int que acumula a quantidade de pontos retirados a partir do cancelamento de outras compras antes da última compra ser cancelada/outra compra ser realizada
cliente[TAM].ult_compra.valor_compra: variável do tipo float que armazena o valor da última compra realizada
cliente[TAM].ult_compra.gasto_compra: variável do tipo float que armazena o valor que o cliente pagou em dinheiro na última compra realizada
cliente[TAM].ult_compra.cbonus: variável do tipo registro que armazena informações relacionadas ao bônus
cliente[TAM].ult_compra.cbonus.teto: variável do tipo int que limita a quantidade de pontos bônus durante a última compra do cliente
cliente[TAM].ult_compra.cbonus.valor: variável do tipo float que indica o valor em R$ de cada ponto bônus durante a última compra do cliente
cliente[TAM].ult_compra.cbonus.valorBonificar: variável do tipo float que indica o valor mínimo de compra para que pontos de bônus sejam adquiridos durante a última compra do cliente
regBonus: variável do tipo registro que armazena informações globais relacionadas ao bônus
regBonus.teto: variável do tipo int que limita a quantidade de pontos bônus
regBonus.valor: variável do tipo float que indica o valor em R$ de cada ponto bônus
regBonus.valorBonificar: variável do tipo float que indica o valor mínimo de compra para que pontos de bônus sejam adquiridos

outras -
conta_clientes: variável do tipo int que armazena o valor relativo quantidade de entradas no banco de dados
cpf[12]: variável do tipo char que é utilizada para realizar verificações ao longo do código
menu/submenu: variável do tipo int que é utilizada para manter o comando de repetição dos menus enquanto for necessário
espaco: variável utilizada para imprimir parte do cabeçalho do menu principal depois da sua primeira repetição
*pont: ponteiro que altera o valor de conta_clientes no menu principal. também altera os valores da struct tBonus
repet: variável do tipo int que é utilizada em comandos de repetição, armazenando o valor de cada ciclo
valor: variável do tipo float que armazena um valor em R$ para ser utilizado dentro de uma função
pgt: variável do tipo float que armazena um valor em R$ correspondente ao quanto um cliente gasta em uma compra
adicional: variável do tipo int que soma valores ao pgt caso este possua um valor inferior ao da compra
neoVariavel/auxVariavel: variáveis que armazenam um valor provisório da variável de nome semelhante
opcao: variável do tipo char utilizada para definir o que o código faz em áreas específicas
*/


//estruturas
typedef struct{
	int teto;
	float valor, valorBonificar;
}tBonus;

typedef struct{
	int compra_cancelada, bonus_anterior, outra_cancelada, outra_valor;
	float valor_compra, gasto_compra;
	tBonus cbonus;
}tCompra;

typedef struct{
	int bonus;
	float gasto_total;
	char nome[50], cpf[12], telefone[15], email[30];
	tCompra ult_compra;
}tCliente;


//protótipos
int busca(tCliente cliente[TAM], char cpf[12], int conta_clientes);
int compara(tCliente cliente[TAM], char cpf[12], int conta_clientes);
int imprimePerfil(tCliente cliente[TAM], int conta_clientes);
char opcaoMenu();
void limparTela();
void agrad();

int menuPrincipal(tCliente cliente[TAM]);

int menuCliente(tCliente cliente[TAM], char cpf[12], int *pont, int submenu);
    int cadastraCliente(tCliente cliente[TAM], int conta_clientes);
    int menuAlterCliente(tCliente cliente[TAM], char cpf[12], int conta_clientes, int submenu);
        int substituiCPF(tCliente cliente[TAM], char cpf[12], int conta_clientes);
    int imprimePerfil2(tCliente cliente[TAM], int conta_clientes);
    int removeCliente(tCliente cliente[TAM], char cpf[12], int conta_clientes);

int menuCompra(tCliente cliente[TAM], char cpf[12], int conta_clientes, int submenu, tBonus regBonus);
    int realizaCompra(tCliente cliente[TAM], char cpf[12], int conta_clientes, tBonus regBonus);
    int cancelaCompra(tCliente cliente[TAM], char cpf[12], int conta_clientes, tBonus regBonus);

int menuBonus(tCliente cliente[TAM], char cpf[12], int conta_clientes, int submenu, tBonus *pont);
    int menuConfigBonus(int submenu, tBonus *pont);
        int alteraTeto(tBonus *pont);
        int alteraValordBonus(tBonus *pont);
        int alteraValorpBonus(tBonus *pont);
    int consultaBonus(tCliente cliente[TAM], char cpf[12], int conta_clientes, tBonus regBonus);
        int imprimeBonus(tCliente cliente[TAM], int conta_clientes, tBonus regBonus);
    int imprimeregBonus(tBonus regBonus);

int menuRelat(tCliente cliente[TAM], int conta_clientes, int submenu, tBonus regBonus);
    int listarClientes(tCliente cliente[TAM], int conta_clientes);
    int listarBonus(tCliente cliente[TAM], int conta_clientes, tBonus regBonus);
    int listarpCompra(tCliente cliente[TAM], int conta_clientes);

	
//funções

/*
função principal do código
chama o menu principal
*/
int main(){
	tCliente cliente[TAM];
	
	menuPrincipal(cliente);
	
	return 0;
}

/*
função de verificação
verifica se o cpf inserido já consta no banco de dados
retorna o número do perfil caso conste
retorno utilizado no código para encontrar perfis específicos dentro do banco de dados
*/
int compara(tCliente cliente[TAM], char cpf[12], int conta_clientes){
	int repet, verif=-1;
	
	for(repet=0;repet<conta_clientes;repet+=1){
		if(strcmp(cpf, cliente[repet].cpf)==0){
			verif=repet;
			break;
		}
	}
	return verif;
}

/*
função de verificação
verifica se o cpf inserido já consta no banco de dados
vem junto com um conjunto de impressões
muito utilizada ao longo de todo o código para fazer verificações de outras funções
retorno utilizado para identificar se o cpf já está presente dentro do banco de dados
*/
int busca(tCliente cliente[TAM], char cpf[12], int conta_clientes){
	printf("Qual o CPF do cliente?\n");
	scanf(" %s", cpf);
	
	if(compara(cliente, cpf, conta_clientes)==-1){
		printf("ERRO: CPF nao cadastrado\n");
		return -1;
	}
	return 0;
}

/*
função de impressão
imprime os dados relacionados a um perfil específico
não inclui os dados da última compra
*/
int imprimePerfil(tCliente cliente[TAM], int conta_clientes){
	printf("\n-------------------------------------\n");
	printf("Cliente Numero - %d\n", conta_clientes+1);
	
	printf("\nDADOS CADASTRAIS:\n");
	printf("Nome - %s\n", cliente[conta_clientes].nome);
	printf("CPF - %s\n", cliente[conta_clientes].cpf);
	printf("Telefone - %s\n", cliente[conta_clientes].telefone);
	printf("Email - %s\n", cliente[conta_clientes].email);
	
	printf("\nDADOS DE COMPRAS:\n");
	printf("Bonus atual - %d\n", cliente[conta_clientes].bonus);
	printf("Valor total de dinheiro gasto na loja - R$: %.2f\n", cliente[conta_clientes].gasto_total);
	
	return 0;
}

/*
função experimental
utilizada para pegar o valor char que vai ser usada para acessar diferentes funções dentro dos menus
retorno utilizado nos comandos switch dos menus
*/
char opcaoMenu(){
	char opcao_menu;
	printf("\nEscolha qual operacao realizar: ");
	scanf(" %c", &opcao_menu);
	
	return opcao_menu;
}

/*
função de impressão
imprime quebras de linha para "limpar" a tela
*/
void limparTela(){
 printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
}

/*
menu principal da função
funciona como hub para todos os outros menus
também repassa várias variáveis para eles (menu, cpf, conta_clientes e cliente)
*/
int menuPrincipal(tCliente cliente[TAM]){
	int menu=1, espaco=0, conta_clientes=0;
	char cpf[12];
	tBonus regBonus;
	
	regBonus.teto=100;
	regBonus.valor=0.5;
	regBonus.valorBonificar=100;
	
	do{
		if(espaco==1)
			printf("\n-------------------------------------\n");
		espaco=1;
		printf("MENU PRINCIPAL\n");
		printf("\n(1) - Cliente\n(2) - Compra\n(3) - Bonus\n(4) - Relatorios\n(9) - Limpar Tela\n(0) - Sair\n");
		
		switch(opcaoMenu()){
			case '1':
				menuCliente(cliente, cpf, &conta_clientes, menu);
				break;
			
			case '2':
				menuCompra(cliente, cpf, conta_clientes, menu, regBonus);
				break;
			
			case '3':
				menuBonus(cliente, cpf, conta_clientes, menu, &regBonus);
				break;
			
			case '4':
				menuRelat(cliente, conta_clientes, menu, regBonus);
				break;
			
			case '9':
				limparTela();
				break;
			
			case '0':
				menu=0;
				break;
			
			default:
				printf("ERRO: entrada invalida\n");
		}
	}while(menu==1);
	agrad();	
	return 0;
}


//MENU CLIENTE

/*
submenu do menu principal
realiza funções relacionadas as entradas do banco de dados
capaz de alterar o valor de conta_clientes do menu principal
possui um submenu
*/
int menuCliente(tCliente cliente[TAM], char cpf[12], int *pont, int submenu){
	int conta_clientes=*pont;
	
	do{
		printf("\n-------------------------------------\n");
		printf("MENU CLIENTE\n");
		printf("%d perfis registrados\n", conta_clientes);
		if(conta_clientes==TAM)
			printf("\nALERTA: Banco de dados cheio. Contate o suporte caso queira adicionar novos perfis!\n");
		printf("\n(1) - Cadastrar\n(2) - Alterar\n(3) - Consultar\n(4) - Remover\n(9) - Limpar tela\n(0) - Sair\n");

		switch(opcaoMenu()){
			case '1':
				if(conta_clientes>=0 && conta_clientes<TAM)
					conta_clientes += cadastraCliente(cliente, conta_clientes);
				else if(conta_clientes==TAM)
					printf("O banco de dados esta cheio. Contate o suporte para realizar alterações.\n");
				else{
					printf("Ocorreu um erro inesperado. Contate o suporte para a manutenção do sistema.\n");
					return 0;
				}
				break;
			
			case '2':
				if(busca(cliente, cpf, conta_clientes)!=-1){
					menuAlterCliente(cliente, cpf, conta_clientes, submenu);
				}
				break;
			
			case '3':
				if(busca(cliente, cpf, conta_clientes)!=-1)
					imprimePerfil2(cliente, compara(cliente, cpf, conta_clientes));
				break;
			
			case '4':
				if(busca(cliente, cpf, conta_clientes)!=-1)
					conta_clientes -= removeCliente(cliente, cpf, conta_clientes);
				break;
			
			case '9':
				limparTela();
				break;
			
			case '0':
				submenu=0;
				break;
			
			default:
				printf("ERRO: entrada invalida\n");
		}
		*pont=conta_clientes;
		
	}while(submenu==1);
	return 0;
}

/*
função de inserção de dados
cadastra um novo perfil no banco de dados
afeta o valor de conta_clientes do menu principal
*/
int cadastraCliente(tCliente cliente[TAM], int conta_clientes){
	printf("\nCliente Numero - %d\n", conta_clientes+1);
	
	printf("Qual o CPF?\n");
	scanf(" %s", cliente[conta_clientes].cpf);
	if(compara(cliente, cliente[conta_clientes].cpf, conta_clientes)!=-1){
		printf("ERRO: CPF ja cadastrado!\n");
		return 0;
	}
	printf("Qual o nome?\n");
	scanf(" %[^\n]", cliente[conta_clientes].nome);
	
	printf("Qual o telefone?\n");
	scanf(" %s", cliente[conta_clientes].telefone);
	
	printf("Qual o email?\n");
	scanf(" %s", cliente[conta_clientes].email);
	
	cliente[conta_clientes].gasto_total=0;
	cliente[conta_clientes].ult_compra.valor_compra=0;
	cliente[conta_clientes].ult_compra.compra_cancelada=2;
	cliente[conta_clientes].bonus=0;
	printf("\nCliente cadastrado com sucesso!\n");
	
	return 1;
}

/*
função de submenu do menu cliente
altera dados de um perfil já cadastrado no banco de dados
*/
int menuAlterCliente(tCliente cliente[TAM], char cpf[12], int conta_clientes, int submenu){
	do{
		printf("\n-------------------------------------\n");
		printf("MENU ALTERAR DADOS DO CLIENTE\n");
		printf("\n(1) - Alterar CPF\n(2) - Alterar nome\n(3) - Alterar telefone\n(4) - Alterar email\n(9) - Limpar tela\n(0) - Voltar ao menu principal\n");

		switch(opcaoMenu()){
			case '1':
				printf("Qual o novo CPF?\n");
   	   	   	   	substituiCPF(cliente, cpf, conta_clientes);
				break;
			
			case '2':
				printf("Qual o novo nome?\n");
				scanf(" %[^\n]", cliente[compara(cliente, cpf, conta_clientes)].nome);
    			printf("\nNome alterado com sucesso!\n");
				break;
			
			case '3':
				printf("Qual o novo telefone?\n");
				scanf(" %s", cliente[compara(cliente, cpf, conta_clientes)].telefone);
				printf("\nTelefone alterado com sucesso!\n");
				break;
			
			case '4':
				printf("Qual o novo email?\n");
				scanf(" %s", cliente[compara(cliente, cpf, conta_clientes)].email);
    			printf("\nEmail alterado com sucesso!\n");
				break;
			
			case '9':
				limparTela();
				break;
			
			case '0':
				submenu=0;
				break;
			
			default:
				printf("ERRO: entrada invalida\n");
		}
	}while(submenu==1);
	return 0;
}


/*
função de modificação
utilizada para alterar os dados de um perfil cliente
elaborada para não causar conflitos com os dados do resto do banco
*/
int substituiCPF(tCliente cliente[TAM], char cpf[12], int conta_clientes){
	int repet;
	char neocpf[12];
	
	for(repet=0;repet<conta_clientes;repet+=1){
		if(strcmp(cpf, cliente[repet].cpf)==0){
			scanf(" %s", neocpf);
			if(compara(cliente, neocpf, conta_clientes)!=-1){
				printf("ERRO: CPF ja cadastrado.\n");
				return 0;
			}
			else
				strcpy(cliente[repet].cpf, neocpf);
			strcpy(cpf, neocpf);
			printf("\nCPF alterado com sucesso!\n");
		}
		break;
	}
	return 0;
}

/*
função de impressão
imprime todos os dados relacionados a um perfil específico
impressão completa
*/
int imprimePerfil2(tCliente cliente[TAM], int conta_clientes){
	imprimePerfil(cliente, conta_clientes);
	printf("\nDADOS DA ULTIMA COMPRA:\n");
	if(cliente[conta_clientes].ult_compra.compra_cancelada==2)
		printf("Nenhuma compra realizada\n");
	else{
		printf("Valor total da ultima compra - R$: %.2f\n", cliente[conta_clientes].ult_compra.valor_compra);
		printf("Valor pago em dinheiro da ultima compra - R$: %.2f\n", cliente[conta_clientes].ult_compra.gasto_compra);
		printf("Ultima compra cancelada: ");
		if(cliente[conta_clientes].ult_compra.compra_cancelada==1)
			printf("Sim\n");
		else
			printf("Nao\n");
	}
	return 0;
}

/*
função de remoção de dados
elimina o perfil relacionado ao CPF informado do banco de dados
retorno afeta o valor de conta_clientes do menu principal
*/
int removeCliente(tCliente cliente[TAM], char cpf[12], int conta_clientes){
	int repet;
	char opcao;
	
	for(repet=0;repet<conta_clientes;repet+=1){
		if(strcmp(cpf, cliente[repet].cpf)==0){
			imprimePerfil(cliente, repet);
			
			printf("Tem certeza que deseja excluir o perfil desse cliente do sistema?\n(Aperte '1' para aceitar ou qualquer outra tecla para declinar) -");
			scanf(" %c", &opcao);
			
			if(opcao=='1'){
				while(repet<conta_clientes){
					cliente[repet] = cliente[repet+1];
					repet+=1;
				}
				printf("\nPerfil de cliente removido com sucesso do banco de dados\n");
				return 1;
			}
			printf("\nPerfil de cliente nao foi removido\n");
			break;
		}
	}
	return 0;
}


//MENU COMPRA

/*
submenu do menu principal
altera os valores de gasto_total, ultima_compra, compra_cancelada e de pontos bônus de perfis cadastrados
*/
int menuCompra(tCliente cliente[TAM], char cpf[12], int conta_clientes, int submenu, tBonus regBonus){
	do{
		printf("\n-------------------------------------\n");
		printf("MENU COMPRA\n");
		printf("\n(1) - Efetivar\n(2) - Cancelar\n(9) - Limpar tela\n(0) - Sair\n");

		switch(opcaoMenu()){
			case '1':
				if(busca(cliente, cpf, conta_clientes)!=-1)
					realizaCompra(cliente, cpf, conta_clientes, regBonus);
				break;
			
			case '2':
				if(busca(cliente, cpf, conta_clientes)!=-1)
					cancelaCompra(cliente, cpf, conta_clientes, regBonus);
				break;

			case '9':
				limparTela();
				break;
			
			case '0':
				submenu=0;
				break;
			
			default:
				printf("ERRO: entrada invalida\n");
		}
	}while(submenu==1);
	return 0;
}

/*
função de inserção de dados
realiza uma nova compra em um perfil de cliente
modifica valores de gasto_total, ultima_compra, pontos bônus e compra_cancelada
*/
int realizaCompra(tCliente cliente[TAM], char cpf[12], int conta_clientes, tBonus regBonus){
	int auxbonus = cliente[compara(cliente, cpf, conta_clientes)].bonus, auxbonusante = cliente[compara(cliente, cpf, conta_clientes)].bonus, check = 0;
	float valor, neovalor, pgt, adicional;
	char verif;
	
	printf("\nBonus - %d\nValor Correspondente - R$ %.2f\n", cliente[compara(cliente, cpf, conta_clientes)].bonus, regBonus.valor*cliente[compara(cliente, cpf, conta_clientes)].bonus);
	printf("Valor da compra: ");
	scanf("%f", &valor);
	
	if(valor<0){
		do{
			printf("ERRO: Valor negativo. Digite novamente: ");
			scanf("%f", &valor);
		}while(valor<0);
	}
	neovalor=valor;
	
	if(cliente[compara(cliente, cpf, conta_clientes)].bonus>0){
		printf("Gostaria de utilizar seu bonus?\n(Aperte '1' para aceitar ou qualquer outra tecla para declinar) -");
		scanf(" %c", &verif);
		
		if(verif=='1'){
			if(regBonus.valor*cliente[compara(cliente, cpf, conta_clientes)].bonus>=valor){
				auxbonus = (int)(regBonus.valor*cliente[compara(cliente, cpf, conta_clientes)].bonus-valor)/regBonus.valor;
				neovalor=0;
			}
			else if(regBonus.valor*cliente[compara(cliente, cpf, conta_clientes)].bonus<valor){
				neovalor = valor-regBonus.valor*cliente[compara(cliente, cpf, conta_clientes)].bonus;
				auxbonus=0;
			}
			printf("Bonus atual - %d\nValor da compra atualizado - R$ %.2f\n", auxbonus, neovalor);
		}
		else
			check=3;
	}
	printf("Valor do pagamento: ");
	scanf("%f", &pgt);
	if(pgt<0){
		do{
			printf("ERRO: Valor negativo. Digite novamente: ");
			scanf("%f", &pgt);
		}while(pgt<0);
	}
	if(pgt<neovalor){
		do{
			printf("ERRO: Valor do pagamento inferior ao valor da compra.\n\nDeseja fornecer mais dinheiro? \n(Aperte '1' para aceitar ou qualquer outra tecla para declinar) -");
			scanf(" %c", &verif);
			
			if(verif=='1'){
				printf("Valor do pagamento: ");
				scanf("%f", &adicional);
				if(adicional<0){
					do{
						printf("ERRO: Valor negativo. Digite novamente: ");
						scanf("%f", &adicional);
					}while(adicional<0);
				}
				pgt+=adicional;
			}
			else{
				printf("\nCOMPRA NAO EFETIVADA.\nValor retornado ao cliente - R$ %.2f\n", pgt);
				return 0;
			}
		}while(pgt<neovalor);
	}
	cliente[compara(cliente, cpf, conta_clientes)].ult_compra.cbonus = regBonus;
	if(auxbonus<regBonus.teto){
		auxbonus += (int)(neovalor/regBonus.valorBonificar);
		if(auxbonus>regBonus.teto)
			auxbonus = regBonus.teto;
	}
	cliente[compara(cliente, cpf, conta_clientes)].bonus = auxbonus;
	cliente[compara(cliente, cpf, conta_clientes)].gasto_total += neovalor;
	cliente[compara(cliente, cpf, conta_clientes)].ult_compra.gasto_compra = neovalor;
	cliente[compara(cliente, cpf, conta_clientes)].ult_compra.bonus_anterior = auxbonusante;
	cliente[compara(cliente, cpf, conta_clientes)].ult_compra.valor_compra = valor;
	cliente[compara(cliente, cpf, conta_clientes)].ult_compra.compra_cancelada = check;
	cliente[compara(cliente, cpf, conta_clientes)].ult_compra.outra_cancelada = 1;
	cliente[compara(cliente, cpf, conta_clientes)].ult_compra.outra_valor = 0;
	
	if(pgt>neovalor){
		pgt-=neovalor;
		printf("Troco - R$ %.2f\n", pgt);
		printf("\nObrigado pela compra!\n");
	}
	else if(pgt==neovalor)
		printf("\nObrigado pela compra!\n");
	
	return 0;
}

/*
funcao de inserção de dados
cancela compras dentro do perfil de um cliente
modifica valores de compra_cancelada, gasto_total e de pontos bônus
*/
int cancelaCompra(tCliente cliente[TAM], char cpf[12], int conta_clientes, tBonus regBonus){
	char opcao;
	float valor;
	int neobonus;
	
	do{
		printf("Qual compra deseja cancelar?\n(1) - Ultima compra\n(2) - Outra compra\n");
		scanf(" %c", &opcao);
	}while(opcao!='1' && opcao!='2');
	
	if(opcao=='1'){
		if(cliente[compara(cliente, cpf, conta_clientes)].ult_compra.compra_cancelada==3){
			printf("Valor pago - R$ %.2f\nBonus usados - %d\nBonus ganhos - %d\n\nTem certeza que deseja cancelar essa compra?\n(Aperte '1' para aceitar ou qualquer outra tecla para declinar) -",  cliente[compara(cliente, cpf, conta_clientes)].ult_compra.gasto_compra, (int)((cliente[compara(cliente, cpf, conta_clientes)].ult_compra.valor_compra - cliente[compara(cliente, cpf, conta_clientes)].ult_compra.gasto_compra) / cliente[compara(cliente, cpf, conta_clientes)].ult_compra.cbonus.valor), (int)(cliente[compara(cliente, cpf, conta_clientes)].ult_compra.gasto_compra / cliente[compara(cliente, cpf, conta_clientes)].ult_compra.cbonus.valorBonificar));
			scanf(" %c", &opcao);
			
			if(opcao=='1'){
				cliente[compara(cliente, cpf, conta_clientes)].bonus = cliente[compara(cliente, cpf, conta_clientes)].ult_compra.bonus_anterior;
				cliente[compara(cliente, cpf, conta_clientes)].ult_compra.compra_cancelada=1;
				if(cliente[compara(cliente, cpf, conta_clientes)].ult_compra.outra_cancelada==0){
					cliente[compara(cliente, cpf, conta_clientes)].bonus -= cliente[compara(cliente, cpf, conta_clientes)].ult_compra.outra_valor;
					cliente[compara(cliente, cpf, conta_clientes)].ult_compra.outra_cancelada = 1;
					cliente[compara(cliente, cpf, conta_clientes)].ult_compra.outra_valor = 0;
					if(cliente[compara(cliente, cpf, conta_clientes)].bonus<0)
						cliente[compara(cliente, cpf, conta_clientes)].bonus=0;
				}
				printf("\nCOMPRA CANCELADA\n");
			}
			else{
				printf("\nCOMPRA NAO CANCELADA\n");
				return 0;
			}
		}
		else if(cliente[compara(cliente, cpf, conta_clientes)].ult_compra.compra_cancelada==2){
			printf("ERRO: nenhuma compra realizada\n");
			return 0;
		}
		else if(cliente[compara(cliente, cpf, conta_clientes)].ult_compra.compra_cancelada==1){
			printf("ERRO: ultima compra ja cancelada\n");
			return 0;
		}
		else if(cliente[compara(cliente, cpf, conta_clientes)].ult_compra.compra_cancelada==0){
			printf("Valor pago - R$ %.2f\nBonus usados - %d\nBonus ganhos - %d\n\nTem certeza que deseja cancelar essa compra?\n(Aperte '1' para aceitar ou qualquer outra tecla para declinar) -",  cliente[compara(cliente, cpf, conta_clientes)].ult_compra.gasto_compra, (int)((cliente[compara(cliente, cpf, conta_clientes)].ult_compra.valor_compra - cliente[compara(cliente, cpf, conta_clientes)].ult_compra.gasto_compra) / cliente[compara(cliente, cpf, conta_clientes)].ult_compra.cbonus.valor), (int)(cliente[compara(cliente, cpf, conta_clientes)].ult_compra.gasto_compra / cliente[compara(cliente, cpf, conta_clientes)].ult_compra.cbonus.valorBonificar));
			scanf(" %c", &opcao);
			
			if(opcao=='1'){
				cliente[compara(cliente, cpf, conta_clientes)].gasto_total -= cliente[compara(cliente, cpf, conta_clientes)].ult_compra.gasto_compra;
				cliente[compara(cliente, cpf, conta_clientes)].bonus -= (int)(cliente[compara(cliente, cpf, conta_clientes)].ult_compra.gasto_compra / cliente[compara(cliente, cpf, conta_clientes)].ult_compra.cbonus.valorBonificar);
				if(cliente[compara(cliente, cpf, conta_clientes)].bonus<0)
					cliente[compara(cliente, cpf, conta_clientes)].bonus=0;
				cliente[compara(cliente, cpf, conta_clientes)].bonus += (int)((cliente[compara(cliente, cpf, conta_clientes)].ult_compra.valor_compra - cliente[compara(cliente, cpf, conta_clientes)].ult_compra.gasto_compra) / cliente[compara(cliente, cpf, conta_clientes)].ult_compra.cbonus.valor);
				if(cliente[compara(cliente, cpf, conta_clientes)].ult_compra.outra_cancelada==0){
					cliente[compara(cliente, cpf, conta_clientes)].bonus -= cliente[compara(cliente, cpf, conta_clientes)].ult_compra.outra_valor;
					cliente[compara(cliente, cpf, conta_clientes)].ult_compra.outra_cancelada = 1;
					cliente[compara(cliente, cpf, conta_clientes)].ult_compra.outra_valor = 0;
					if(cliente[compara(cliente, cpf, conta_clientes)].bonus<0)
						cliente[compara(cliente, cpf, conta_clientes)].bonus=0;
				}
				cliente[compara(cliente, cpf, conta_clientes)].ult_compra.compra_cancelada=1;
				printf("\nCOMPRA CANCELADA\n");
			}
			else{
				printf("\nCOMPRA NAO CANCELADA\n");
				return 0;
			}
		}
	}
	else if(opcao=='2'){
		printf("Qual o valor da compra a ser cancelada?");
		scanf("%f", &valor);
		neobonus = (int)(valor/regBonus.valorBonificar);
		
		if((cliente[compara(cliente, cpf, conta_clientes)].ult_compra.compra_cancelada==1 && valor>cliente[compara(cliente, cpf, conta_clientes)].gasto_total) || (((cliente[compara(cliente, cpf, conta_clientes)].ult_compra.compra_cancelada==0)||(cliente[compara(cliente, cpf, conta_clientes)].ult_compra.compra_cancelada==3))&& ((cliente[compara(cliente, cpf, conta_clientes)].gasto_total - cliente[compara(cliente, cpf, conta_clientes)].ult_compra.gasto_compra)<valor))){
			printf("ERRO: essa compra não corresponde aos valores no perfil do cliente\n");
			return 0;
		}
		else{
			printf("Valor da compra - R$ %.2f\nBonus - %d\n\nVendedor, deseja informar um valor menor de bonus?\n(Aperte '1' para aceitar ou qualquer outra tecla para declinar) -", valor, neobonus);
			scanf(" %c", &opcao);
			if(opcao=='1'){
				do{
					printf("Digite o valor do bonus a ser retirado do cliente (menor ou igual a %d): ", (int)(valor/regBonus.valorBonificar));
					scanf("%d", &neobonus);
				}while(neobonus>(int)(valor/regBonus.valorBonificar) || neobonus<0);
			}
			
			printf("Valor da compra - R$ %.2f\nBonus - %d\n\nTem certeza que deseja cancelar essa compra?\n(Aperte '1' para aceitar ou qualquer outra tecla para declinar) -", valor, neobonus);
			scanf(" %c", &opcao);
			
			if(opcao=='1'){
				cliente[compara(cliente, cpf, conta_clientes)].ult_compra.outra_cancelada = 0;
				cliente[compara(cliente, cpf, conta_clientes)].ult_compra.outra_valor += neobonus;
				cliente[compara(cliente, cpf, conta_clientes)].gasto_total -= valor;
				cliente[compara(cliente, cpf, conta_clientes)].bonus -= neobonus;
				if(cliente[compara(cliente, cpf, conta_clientes)].bonus<0)
					cliente[compara(cliente, cpf, conta_clientes)].bonus=0;
				printf("\nCOMPRA CANCELADA\n");
			}
			else{
				printf("\nCOMPRA NAO CANCELADA\n");
				return 0;
			}
		}
	}
	return 1;
}


//MENU BONUS

/*
submenu do menu principal
realiza funções associadas aos valores de tBonus
possui um submenu
*/
int menuBonus(tCliente cliente[TAM], char cpf[12], int conta_clientes, int submenu, tBonus *pont){
	tBonus regBonus=*pont;
	
	do{
		printf("\n-------------------------------------\n");
		printf("MENU BONUS\n");
		printf("\n(1) - Configurar\n(2) - Exibir\n(3) - Regras atuais\n(9) - Limpar tela\n(0) - Sair\n");

		switch(opcaoMenu()){
			case '1':
				menuConfigBonus(submenu, &regBonus);
				*pont=regBonus;
				break;
			
			case '2':
				consultaBonus(cliente, cpf, conta_clientes, regBonus);
				break;
			
			case '3':
				imprimeregBonus(regBonus);
				break;

			case '9':
				limparTela();
				break;
			
			case '0':
				submenu=0;
				break;
			
			default:
				printf("ERRO: entrada invalida\n");
		}
	}while(submenu==1);
	return 0;
}

/*
submenu do menu bonus
realiza funções que alteram os valores de tBonus que são únicos para todo o banco de dados
*/
int menuConfigBonus(int submenu, tBonus *pont){
	tBonus regBonus=*pont;
	
	do{
		printf("\n-------------------------------------\n");
		printf("MENU DE CONFIGURACAO DE BONUS\n");
		printf("\n(1) - Alterar teto\n(2) - Alterar valor do bonus\n(3) - Alterar valor para receber bonus\n(0) - Sair\n");

		switch(opcaoMenu()){
			case '1':
				alteraTeto(&regBonus);
				break;
			
			case '2':
				alteraValordBonus(&regBonus);
				break;
			
			case '3':
				alteraValorpBonus(&regBonus);
				break;
			
			case '0':
				submenu=0;
				break;
			
			default:
				printf("ERRO: entrada invalida\n");
		}
		
		*pont=regBonus;
	}while(submenu==1);
	return 0;
}

/*
função de modificação
altera o limite de pontos de bônus do banco de dados
afeta todos os perfis já registrados
*/
int alteraTeto(tBonus *pont){
	int neoteto;
	
	printf("Qual o novo valor do limite de bonus?\n");
	scanf("%d", &neoteto);
	
	if(neoteto<0){
		do{
			printf("ERRO: Valor negativo. Digite novamente: ");
			scanf("%d", &neoteto);
		}while(neoteto<0);
	}
	(*pont).teto=neoteto;
	printf("\nLimite de bonus atualizado com sucesso!\n");
	
	return 0;
}

/*
função de modificação
altera o valor em R$ correspondente a cada ponto de bônus
afeta todos os perfis já registrados
*/
int alteraValordBonus(tBonus *pont){
	float neobonus;
	
	printf("Qual o novo valor de cada ponto de bonus?\n");
	scanf("%f", &neobonus);
	
	if(neobonus<0){
		do{
			printf("ERRO: Valor negativo. Digite novamente: ");
			scanf("%f", &neobonus);
		}while(neobonus<0);
	}
	(*pont).valor=neobonus;
	printf("\nValor de cada ponto de bonus atualizado com sucesso!\n");
	
	return 0;
}

/*
função de modificação
altera o valor em R$ necessário para se adquirir pontos de bônus
afeta todos os perfis já registrados
*/
int alteraValorpBonus(tBonus *pont){
	float neovpbonus;
	
	printf("Qual o novo valor necessario para receber um ponto de bonus?\n");
	scanf("%f", &neovpbonus);
	
	if(neovpbonus<0){
		do{
			printf("ERRO: Valor negativo. Digite novamente: ");
			scanf("%f", &neovpbonus);
		}while(neovpbonus<0);
	}
	(*pont).valorBonificar=neovpbonus;
	printf("\nValor necessario para receber um ponto de bonus atualizado com sucesso!\n");
	
	return 0;
}

/*
função de impressão
imprime os dados relacionados ao bônus de um perfil específico com base em um cpf
*/
int consultaBonus(tCliente cliente[TAM], char cpf[12], int conta_clientes, tBonus regBonus){
	if(busca(cliente, cpf, conta_clientes)!=-1)
		imprimeBonus(cliente, compara(cliente, cpf, conta_clientes), regBonus);
	
	return 0;
}

/*
função de impressão
imprime os dados relacionados aos bônus de um perfil específico
*/
int imprimeBonus(tCliente cliente[TAM], int conta_clientes, tBonus regBonus){
	printf("\n-------------------------------------\n");
	printf("Cliente Numero - %d\n", conta_clientes+1);
	
	printf("\nDADOS DO BONUS:\n");
	printf("Bonus atual - %d\n", cliente[conta_clientes].bonus);
	printf("Valor total do bonus - R$: %.2f\n", cliente[conta_clientes].bonus*regBonus.valor);
	
	return 0;
}

/*
função de impressão
imprime as regras atuais de bônus no sistema
*/
int imprimeregBonus(tBonus regBonus){
	printf("\n-------------------------------------\n");
	printf("\nREGRAS DE BONUS\n");
	printf("Limite de bonus - %d\n", regBonus.teto);
	printf("Valor de cada ponto de bonus - R$ %.2f\n", regBonus.valor);
	printf("Valor necessario para receber um ponto de bonus - R$ %.2f\n", regBonus.valorBonificar);
	
	return 0;
}


//MENU RELATORIOS

/*
submenu do menu principal
possui vários comandos de lista(cadeia de impressões) de perfis registrados
*/
int menuRelat(tCliente cliente[TAM], int conta_clientes, int submenu, tBonus regBonus){
	do{
		printf("\n-------------------------------------\n");
		printf("MENU RELATORIOS\n");
		printf("\n(1) - Listar clientes\n(2) - Listar bonus\n(3) - Listar clientes p/ compras\n(9) - Limpar tela\n(0) - Sair\n");
		
		switch(opcaoMenu()){
			case '1':
				listarClientes(cliente, conta_clientes);
				break;
			
			case '2':
				listarBonus(cliente, conta_clientes, regBonus);
				break;
			
			case '3':
				listarpCompra(cliente, conta_clientes);
				break;

			case '9':
				limparTela();
				break;
			
			case '0':
				submenu=0;
				break;
			
			default:
				printf("ERRO: entrada invalida\n");
		}
	}while(submenu==1);
	return 0;
}

/*
função de lista
imprime os dados de todos os perfis do banco de dados
*/
int listarClientes(tCliente cliente[TAM], int conta_clientes){
	int repet;
	
	if(conta_clientes==0)
		printf("ERRO: nao foram realizados cadastros no sistema!\n");
	else{
		for(repet=0;repet<conta_clientes;repet+=1){
			imprimePerfil(cliente, repet);
		}
	}
	return 0;
}

/*
função de lista
imprime os dados relacionados aos bônus de todos os perfis do banco de dados
*/
int listarBonus(tCliente cliente[TAM], int conta_clientes, tBonus regBonus){
	int repet;
	
	if(conta_clientes==0)
		printf("ERRO: nao foram realizados cadastros no sistema!\n");
	else{
		for(repet=0;repet<conta_clientes;repet+=1){
			imprimeBonus(cliente, repet, regBonus);
		}
	}
	return 0;
}

/*
função de lista
lista seletiva que imprime os perfis do banco de dados com dados correspondentes aos valores inseridos
*/
int listarpCompra(tCliente cliente[TAM], int conta_clientes){
	int repet, opcao, verif=0;
	float valor;
	
	printf("Informe o valor que quer procurar: ");
	scanf("%f", &valor);
	
	printf("Deseja procurar por clientes: \n\n(1) - Com valor de compras superior ao valor informado\n(-1) - Com o valor de compras inferior ao valor informado\n(0) - Com o valor de compras igual ao valor informado\n\nEscolha uma opcao: ");
	scanf("%d", &opcao);
	
	if(opcao==1){
		for(repet=0;repet<conta_clientes;repet+=1){
			if(valor<cliente[repet].gasto_total){
				imprimePerfil(cliente, repet);
				verif+=1;
			}
		}
	}
	else if(opcao==-1){
		for(repet=0;repet<conta_clientes;repet+=1){
			if(valor>cliente[repet].gasto_total){
				imprimePerfil(cliente, repet);
				verif+=1;
			}
		}
	}
	else if(opcao==0){
		for(repet=0;repet<conta_clientes;repet+=1){
			if(valor==cliente[repet].gasto_total){
				imprimePerfil(cliente, repet);
				verif+=1;
			}
		}
	}
	if(verif==0)
		printf("ERRO: nenhum usuário encontrado com base no valor digitado!\n");
	return 0;
}

/*
função de agradecimento pelo período
*/
void agrad(){
	printf("\n-------------------------------------\n");
	printf("Obrigado pela disciplina e boas ferias!\n");
	printf("\nDos seus alunos:\n");
	printf("- Ciro Olimpio de Melo\n");
	printf("- Enzo Eduardo Cassiano Ibiapina\n");
	printf("\nEstamos no aguardo da nota 10!!!");
	printf("\n-------------------------------------\n");
}