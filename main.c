/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/10 11:25:44 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2018/04/23 17:34:42 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "rendu/inc/ft_printf.h"

#include <stdio.h>
#include <stdlib.h>



int main (int argc, char **argv)
{
/*	if (argc != 2)
	{
		printf("Usage : %s format", argv[0]);
	}
	
*/	//setlocale(LC_ALL, "");
	(void)argc;
	(void)argv;
// a faire :
// %010p
// %c = 0

ft_printf("%S\n", L"ݗݜशব");
ft_printf("%C\n", 15000);

	return (0);
}
