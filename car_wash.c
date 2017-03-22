#include <stdio.h>
#include <stdlib.h>

#define OUTPUT_FILENAME "output.txt"

void sim(unsigned int numero_clientes,FILE *fout){
	int cliente;
	float delay_chegada, chegada_tempo, tempo_chegada, tempo_servico, inicio_servico, fila, final_servico, delay_total, operador_oicioso;
	float sum_servico, sum_fila, sum_sistema, sum_operador_ocioso;
	
	for(cliente=1;cliente <= numero_clientes;cliente++){
		// SIMULAÇÃO
	}
	
}

int main(){
	
	unsigned int numero_clientes;
	FILE *fout;
	
	printf("Número de clientes para simulação: ");
	scanf("%d",&numero_clientes);
	
	fout = fopen(OUTPUT_FILENAME,"w");
	
	sim(numero_clientes,fout);
	
	return 0;
}
