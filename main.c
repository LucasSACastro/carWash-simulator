/*
 * File:   main.c
 * Author: Luke S. A. Castro / Victor Pius
 *
 * Created on 22 de Março de 2017, 14:01
 */

#include <stdio.h>

#define OUTPUT_FILENAME "output.txt"



void sim(unsigned numero_clientes, FILE *fout);


/**
 **  Function main(); descobre o número de clientes, abre o arquivo e inicia a simulação. Fecha-o
 ** despois, para retornar 0.
 **/
int main(){

	unsigned int numero_clientes;
	FILE *fout;

	printf("Número de clientes para simulação: ");
	scanf("%d",&numero_clientes);

	fout = fopen(OUTPUT_FILENAME,"w");

	sim(numero_clientes,fout);

	fclose(fout);

	return 0;
}


void sim(unsigned int numero_clientes,FILE *fout){
	register int cliente; /* Cliente sendo atendido no momento; começa como lixo. */

	/*Variáveis da tabela:*/
	struct {
		unsigned delay, relogio;
	} chegada;
	struct {
		unsigned duracao, inicio, fim;
		unsigned sum_duracao;
	} servico;
	struct {
		unsigned fila, total;
		unsigned sum_fila, sum_totais;
	} tempo_cliente;
	struct {
		unsigned instance, sum;
	} ocio_operador;

	for(cliente=0; cliente<numero_clientes; cliente++){
		/* Simulação. */
	}

}
