/*
 * File:   main.c
 * Author: Luke S. A. Castro & Victor Pius
 *
 * Created on 22 de Março de 2017, 14:01
 */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define OUTPUT_FILENAME "output.txt"



void sim(unsigned numero_clientes, FILE *fout);


/**
 **  Function main(); descobre o número de clientes, abre o arquivo e inicia a simulação. Fecha-o
 ** despois, para retornar 0.
 **/
int main() {
	unsigned int numero_clientes;
	FILE *fout;

	setlocale(LC_ALL, "Portuguese");

	printf("Número de clientes para simulação: ");
	scanf("%d",&numero_clientes);

	fout = fopen(OUTPUT_FILENAME,"w");

	sim(numero_clientes,fout);

	fclose(fout);

	return 0;
}


void sim(unsigned int numero_clientes, FILE *fout) {
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
		unsigned fila, total, queue_count;
		unsigned sum_fila, sum_totais;
	} tempo_cliente;
	struct {
		unsigned instance, sum;
	} ocio_operador;
	struct {
        	float tempo_fila, prob_fila, prob_opLivre, tempo_serv, tempo_syst;
	} stat;

    	/* Inicialização das variáveis da simulação: */
    	chegada.relogio=servico.fim=servico.sum_duracao=tempo_cliente.sum_fila =
    	tempo_cliente.sum_totais=ocio_operador.sum=tempo_cliente.queue_count = 0;

	for(cliente=1; cliente<=numero_clientes; cliente++) {
		/* Cálculo das estatísticas para este cliente: */
		srand(rand());
		chegada.delay = (rand()%3)+10;
		servico.duracao = (rand()%3)+9;
		chegada.relogio += chegada.delay;
		servico.fim>chegada.relogio ? servico.inicio=servico.fim : servico.inicio=chegada.relogio;
		tempo_cliente.fila = servico.inicio-chegada.relogio;
		ocio_operador.instance;
		servico.fim = servico.inicio+servico.duracao;
		tempo_cliente.total = servico.duracao+tempo_cliente.fila;

		/* Houve fila? */
		if(tempo_cliente.fila>0) tempo_cliente.queue_count++;

		/* Actualizando-se as quattro somas: */
		servico.sum_duracao      += servico.duracao;
		tempo_cliente.sum_fila   += tempo_cliente.fila;
		tempo_cliente.sum_totais += tempo_cliente.total;
		ocio_operador.sum        += ocio_operador.instance;

		/* INSIRA AQUI A IMPRESSÃO AO ARQUIVO... */
    }

    /* Equações finais: */
    stat.tempo_fila   = tempo_cliente.sum_fila/numero_clientes;
    stat.prob_fila    = tempo_cliente.queue_count/numero_clientes;
    stat.prob_opLivre = ocio_operador.sum/servico.fim;  /* Dividindo-se polo fim do último servico, que foy o fim da simulação em si.*/
    stat.tempo_serv   = servico.sum_duracao/numero_clientes;
    stat.tempo_syst   = tempo_cliente.sum_totais/numero_clientes;

    /* INSIRA IMPRESSÃO DAS EQUAÇÕES FINAIS! */
}
