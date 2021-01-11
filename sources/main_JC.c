/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_JC.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcsantos <jcsantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 10:06:46 by juasanto          #+#    #+#             */
/*   Updated: 2021/01/11 18:01:25 by jcsantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	check_ft(int sys_printf, int ft_printf)
{
	if (sys_printf == ft_printf)
	{
		printf(GRN);
		printf("*** OK ***\n");
		printf(RESET);
	}
	else
	{
		printf(RED);
		printf("*** ERROR ***, sys_printf = %i, ft_printf = %i\n", sys_printf, ft_printf);
		printf(RESET);
	}
	return ;
}

int        main(void)
{
    int		cnt_imp;
    int		printf_chars;
	int		cnt;
	int		cnt1;
	int		test_num;
	int		test_error;
	static char	a01;
	static unsigned char a02;
	static short a03;
	static unsigned short a04;
	static int a05;
	static unsigned int a06;
	static long a07;
	static unsigned long a08;
	static long long a09;
	static unsigned long long a10;
	static char *a11;
	static void *a12;
	int		t2;
	char	*s;

	cnt = 0;
	cnt1 = 0;
	test_num = 0;
	test_error = 0;
	t2 = 3;
	s = "abc";

	printf("\n\n********************* CHECK STRING *******************************\n\n");
	printf_chars = printf("%s %s %s %s %s %s %s %s %s %s %s %s\n", "aaa", "bbb", "ccc", "ddd", "eee", "fff", "ggg", "hhh", "iii", "jjj", "kkk", "lll");
	cnt_imp = ft_printf("%s %s %s %s %s %s %s %s %s %s %s %s\n", "aaa", "bbb", "ccc", "ddd", "eee", "fff", "ggg", "hhh", "iii", "jjj", "kkk", "lll");
	check_ft(printf_chars, cnt_imp);
	printf("\n\n********************* CHECK INT **********************************\n\n");
	printf_chars = printf("%i %i %i %i %i %i %i %i %i %i %i %i\n", 1, -2, 3, -4, 5, -6, 7, -8, 9, -10, 11, -12);
	cnt_imp = ft_printf("%i %i %i %i %i %i %i %i %i %i %i %i\n", 1, -2, 3, -4, 5, -6, 7, -8, 9, -10, 11, -12);
	check_ft(printf_chars, cnt_imp);
	printf("\n\n********************* CHAR ***************************************\n\n");
	printf_chars = printf("%c %c %c %c %c %c %c %c %c %c %c %c\n", 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l');
	cnt_imp = ft_printf("%c %c %c %c %c %c %c %c %c %c %c %c\n", 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l');
	check_ft(printf_chars, cnt_imp);
	printf("\n\n********************* MIXX ***************************************\n\n");
	printf_chars = printf("%s %i %c %s %i %c %s %i %c %s %i %c\n", "aaa", 1, 'c', "ddd", -22, 'f', "ggg", 333, 'i', "jjj", -444, 'l');
	cnt_imp = ft_printf("%s %i %c %s %i %c %s %i %c %s %i %c\n", "aaa", 1, 'c', "ddd", -22, 'f', "ggg", 333, 'i', "jjj", -444, 'l');
	check_ft(printf_chars, cnt_imp);
	printf("\n\n********************* TEST with con * y Precision ****************\n\n");
	printf_chars = printf("%i\n", 18);
	cnt_imp = ft_printf("%i\n", 18);
	check_ft(printf_chars, cnt_imp);
	printf_chars = printf("%*i\n", 18, 20);
	cnt_imp = ft_printf("%*i\n", 18, 20);
	check_ft(printf_chars, cnt_imp);
	printf_chars = printf("%.*i\n", 18, 99);
	cnt_imp = ft_printf("%.*i\n", 18, 99);
	check_ft(printf_chars, cnt_imp);
	printf_chars = printf("%*.*i\n", 18, 8, 99);
	cnt_imp = ft_printf("%*.*i\n", 18, 8, 99);
	check_ft(printf_chars, cnt_imp);
	printf_chars = printf("%i\n", 8);
	cnt_imp = ft_printf("%i\n", 8);
	check_ft(printf_chars, cnt_imp);
	printf_chars = printf("%*i\n", 8, 10);
	cnt_imp = ft_printf("%*i\n", 8, 10);
	check_ft(printf_chars, cnt_imp);
	printf_chars = printf("%*.*i\n", 8, 18, 99);
	cnt_imp = ft_printf("%*.*i\n", 8, 18, 99);
	check_ft(printf_chars, cnt_imp);
	printf("\n\n********************* TEST char con - y with **********************\n\n");
	printf_chars = printf("%-*c\n", 10, 'C');
	cnt_imp = ft_printf("%-*c\n", 10, 'C');
	check_ft(printf_chars, cnt_imp);
	printf_chars = printf("%*c\n", 10, 'C');
	cnt_imp = ft_printf("%*c\n", 10, 'C');
	check_ft(printf_chars, cnt_imp);
	printf("\n\n********************* TEST char NULL **********************\n\n");
	printf_chars = printf("%c\n");
	cnt_imp = ft_printf("%c\n");
	check_ft(printf_chars, cnt_imp);
	printf("\n\n********************* TEST 2 x porcentaje *****************\n\n");
	printf_chars = printf("%-05%\n");
	cnt_imp = ft_printf("%-05%\n");
	check_ft(printf_chars, cnt_imp);
	printf_chars = printf("%05%\n");
	cnt_imp = ft_printf("%05%\n");
	check_ft(printf_chars, cnt_imp);
	printf_chars = printf("%-5%\n");
	cnt_imp = ft_printf("%-5%\n");
	check_ft(printf_chars, cnt_imp);
	printf_chars = printf("%5%\n");
	cnt_imp = ft_printf("%5%\n");
	check_ft(printf_chars, cnt_imp);
	printf("\n\n********************* TEST width y prescion *****************\n\n");
	 while (cnt < 5)
	{
		while (cnt1 < 5)
		{
			printf_chars = printf("%*.*i\n", cnt1, cnt, 1111);
			cnt_imp = ft_printf("%*.*i\n", cnt1, cnt, 2222);
			if (printf_chars == cnt_imp)
				test_num++;
			else
				test_error++;

			printf_chars = printf("%-*.*i\n", cnt1, cnt, 3333);
			cnt_imp = ft_printf("%-*.*i\n", cnt1, cnt, 4444);
			if (printf_chars == cnt_imp)
				test_num++;
			else
				test_error++;

			printf_chars = printf("%*.*i\n", cnt1, cnt, -5555);
			cnt_imp = ft_printf("%*.*i\n", cnt1, cnt, -6666);
			if (printf_chars == cnt_imp)
				test_num++;
			else
				test_error++;

			printf_chars = printf("%-*.*i\n", cnt1, cnt, -7777);
			cnt_imp = ft_printf("%-*.*i\n", cnt1, cnt, -8888);
			if (printf_chars == cnt_imp)
				test_num++;
			else
				test_error++;
			cnt1++;
		}
		cnt1 = 0;
		cnt++;
	}
	printf(GRN);
	printf("Test Correctos: %i\n", test_num);
	printf(RED);
	printf("Test con error: %i\n", test_error);
	printf(RESET);

	printf_chars = printf("%7i\n", -14);
	cnt_imp = ft_printf("%7i\n", -14);
	check_ft(printf_chars, cnt_imp);
	printf_chars = printf("%i\n", -14);
	cnt_imp = ft_printf("%i\n", -14);
	check_ft(printf_chars, cnt_imp);
	printf_chars = printf("%7i\n", 14);
	cnt_imp = ft_printf("%7i\n", 14);
	check_ft(printf_chars, cnt_imp);
	printf_chars = printf("%05i\n", 43);
	cnt_imp = ft_printf("%05i\n", 43);
	check_ft(printf_chars, cnt_imp);
	printf_chars = printf("%-7i\n", -43);
	cnt_imp = ft_printf("%-7i\n", -43);
	check_ft(printf_chars, cnt_imp);
	printf_chars = printf("%07i\n", -43);
	cnt_imp = ft_printf("%07i\n", -43);
	check_ft(printf_chars, cnt_imp);
	printf_chars = printf("%08.5i\n", 34);
	cnt_imp = ft_printf("%08.5i\n", 34);
	check_ft(printf_chars, cnt_imp);
	printf_chars = printf("%+08.5i\n", -34);
	cnt_imp = ft_printf("%+08.5i\n", -34);
	check_ft(printf_chars, cnt_imp);
	printf_chars = printf("%-+8.5i\n", 34);
	cnt_imp = ft_printf("%-+8.5i\n", 34);
	check_ft(printf_chars, cnt_imp);
	printf_chars = printf("%8.5i\n", 34);
	cnt_imp = ft_printf("%8.5i\n", 34);
	check_ft(printf_chars, cnt_imp);
	printf_chars = printf("%5.8i\n", 34);
	cnt_imp = ft_printf("%5.8i\n", 34);
	check_ft(printf_chars, cnt_imp);
	printf_chars = printf("%5i\n", 34);
	cnt_imp = ft_printf("%5i\n", 34);
	check_ft(printf_chars, cnt_imp);
	printf_chars = printf("%12.10i\n", 45);
	cnt_imp = ft_printf("%12.10i\n", 45);
	check_ft(printf_chars, cnt_imp);
	printf_chars = printf("%-10i\n", -34);
	cnt_imp = ft_printf("%-10i\n", -34);
	check_ft(printf_chars, cnt_imp);
	printf("\n\n********************* TEST NULL - i **********************\n\n");
	printf_chars = printf("%5.0i\n", 0);
	cnt_imp = ft_printf("%5.0i\n", 0);
	check_ft(printf_chars, cnt_imp);
	printf_chars = printf("%.0i\n", 0);
	cnt_imp = ft_printf("%.0i\n", 0);
	check_ft(printf_chars, cnt_imp);
	printf("\n\n********************* CHAR ***************************************\n\n");
	printf_chars = printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",' ','!','"','#','$','%','&','\'','(',')','*','+',',','-','.','/','0','1','2','3','4','5','6','7','8','9',':',';','<','=','>','?','@','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','[','\\',']','^','_','`','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','{','|','}','~','');
	cnt_imp = ft_printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",' ','!','"','#','$','%','&','\'','(',')','*','+',',','-','.','/','0','1','2','3','4','5','6','7','8','9',':',';','<','=','>','?','@','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','[','\\',']','^','_','`','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','{','|','}','~','');
	check_ft(printf_chars, cnt_imp);
	printf_chars = printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",(char)1,(char)2,(char)3,(char)4,(char)5,(char)6,(char)7,(char)8,(char)9,(char)10,(char)11,(char)12,(char)13,(char)14,(char)15,(char)16,(char)17,(char)18,(char)19,(char)20,(char)21,(char)22,(char)23,(char)24,(char)25,(char)26,(char)27,(char)28,(char)29,(char)30,(char)31);
	cnt_imp = ft_printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",(char)1,(char)2,(char)3,(char)4,(char)5,(char)6,(char)7,(char)8,(char)9,(char)10,(char)11,(char)12,(char)13,(char)14,(char)15,(char)16,(char)17,(char)18,(char)19,(char)20,(char)21,(char)22,(char)23,(char)24,(char)25,(char)26,(char)27,(char)28,(char)29,(char)30,(char)31);
	check_ft(printf_chars, cnt_imp);
	printf_chars = printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",(char)128,(char)129,(char)130,(char)131,(char)132,(char)133,(char)134,(char)135,(char)136,(char)137,(char)138,(char)139,(char)140,(char)141,(char)142,(char)143,(char)144,(char)145,(char)146,(char)147,(char)148,(char)149,(char)150,(char)151,(char)152,(char)153,(char)154,(char)155,(char)156,(char)157,(char)158,(char)159,(char)160,(char)161,(char)162,(char)163,(char)164,(char)165,(char)166,(char)167,(char)168,(char)169,(char)170,(char)171,(char)172,(char)173,(char)174,(char)175,(char)176,(char)177,(char)178,(char)179,(char)180,(char)181,(char)182,(char)183,(char)184,(char)185,(char)186,(char)187,(char)188,(char)189,(char)190,(char)191,(char)192,(char)193,(char)194,(char)195,(char)196,(char)197,(char)198,(char)199,(char)200,(char)201,(char)202,(char)203,(char)204,(char)205,(char)206,(char)207,(char)208,(char)209,(char)210,(char)211,(char)212,(char)213,(char)214,(char)215,(char)216,(char)217,(char)218,(char)219,(char)220,(char)221,(char)222,(char)223,(char)224,(char)225,(char)226,(char)227,(char)228,(char)229,(char)230,(char)231,(char)232,(char)233,(char)234,(char)235,(char)236,(char)237,(char)238,(char)239,(char)240,(char)241,(char)242,(char)243,(char)244,(char)245,(char)246,(char)247,(char)248,(char)249,(char)250,(char)251,(char)252,(char)253,(char)254,(char)255);
	cnt_imp = ft_printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",(char)128,(char)129,(char)130,(char)131,(char)132,(char)133,(char)134,(char)135,(char)136,(char)137,(char)138,(char)139,(char)140,(char)141,(char)142,(char)143,(char)144,(char)145,(char)146,(char)147,(char)148,(char)149,(char)150,(char)151,(char)152,(char)153,(char)154,(char)155,(char)156,(char)157,(char)158,(char)159,(char)160,(char)161,(char)162,(char)163,(char)164,(char)165,(char)166,(char)167,(char)168,(char)169,(char)170,(char)171,(char)172,(char)173,(char)174,(char)175,(char)176,(char)177,(char)178,(char)179,(char)180,(char)181,(char)182,(char)183,(char)184,(char)185,(char)186,(char)187,(char)188,(char)189,(char)190,(char)191,(char)192,(char)193,(char)194,(char)195,(char)196,(char)197,(char)198,(char)199,(char)200,(char)201,(char)202,(char)203,(char)204,(char)205,(char)206,(char)207,(char)208,(char)209,(char)210,(char)211,(char)212,(char)213,(char)214,(char)215,(char)216,(char)217,(char)218,(char)219,(char)220,(char)221,(char)222,(char)223,(char)224,(char)225,(char)226,(char)227,(char)228,(char)229,(char)230,(char)231,(char)232,(char)233,(char)234,(char)235,(char)236,(char)237,(char)238,(char)239,(char)240,(char)241,(char)242,(char)243,(char)244,(char)245,(char)246,(char)247,(char)248,(char)249,(char)250,(char)251,(char)252,(char)253,(char)254,(char)255);
	check_ft(printf_chars, cnt_imp);
	printf_chars = printf("%4c\n", 'a');
	cnt_imp = ft_printf("%4c\n", 'a');
	check_ft(printf_chars, cnt_imp);
	printf_chars = printf("%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c\n",' ','!','"','#','$','%','&','\'','(',')','*','+',',','-','.','/','0','1','2','3','4','5','6','7','8','9',':',';','<','=','>','?','@','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','[','\\',']','^','_','`','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','{','|','}','~','');
	cnt_imp = ft_printf("%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c\n",' ','!','"','#','$','%','&','\'','(',')','*','+',',','-','.','/','0','1','2','3','4','5','6','7','8','9',':',';','<','=','>','?','@','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','[','\\',']','^','_','`','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','{','|','}','~','');
	check_ft(printf_chars, cnt_imp);
	printf_chars = printf("%u\n", 4294967295u);
	cnt_imp = ft_printf("%u\n", 4294967295u);
	check_ft(printf_chars, cnt_imp);
	printf_chars = printf("%%\n");
	cnt_imp = ft_printf("%%\n");
	check_ft(printf_chars, cnt_imp);
	printf_chars = printf("%5c\n", '\0');
	cnt_imp = ft_printf("%5c\n", '\0');
	check_ft(printf_chars, cnt_imp);
	printf_chars = printf("%5c\n", '4');
	cnt_imp = ft_printf("%5c\n", '4');
	check_ft(printf_chars, cnt_imp);
	printf_chars = printf("%-5c\n", '4');
	cnt_imp = ft_printf("%-5c\n", '4');
	check_ft(printf_chars, cnt_imp);
	printf_chars = printf("%05c\n", 'a');
	cnt_imp = ft_printf("%05c\n", 'a');
	check_ft(printf_chars, cnt_imp);
	printf("************************** TEST NOCrash **************************\n");
	printf_chars = printf("%");
	cnt_imp = ft_printf("%");
	check_ft(printf_chars, cnt_imp);
	printf("printf_chars: %i\n", printf_chars);
	printf_chars = printf("%5");
	cnt_imp = ft_printf("%5");
	check_ft(printf_chars, cnt_imp);
	printf("printf_chars: %i\n", printf_chars);
	printf_chars = printf("%05");
	cnt_imp = ft_printf("%05");
	check_ft(printf_chars, cnt_imp);
	printf("printf_chars: %i\n", printf_chars);
	printf_chars = printf("%-05");
	cnt_imp = ft_printf("%-05");
	check_ft(printf_chars, cnt_imp);
	printf("printf_chars: %i\n", printf_chars);
	printf_chars = printf("%-5");
	cnt_imp = ft_printf("%-5");
	check_ft(printf_chars, cnt_imp);
	printf("printf_chars: %i\n", printf_chars);
	printf("************************** TEST arg neg **************************\n");
	printf_chars = printf("%0*i\n", -7, -54);
	cnt_imp = ft_printf("%0*i\n", -7, -54);
	check_ft(printf_chars, cnt_imp);
	printf("************************** TEST Strings **************************\n");
	printf_chars = printf("%32s\n", "abc");
	cnt_imp = ft_printf("%32s\n", "abc");
	check_ft(printf_chars, cnt_imp);
	printf_chars = printf("%.3s\n", "hello");
	cnt_imp = ft_printf("%.3s\n", "hello");
	check_ft(printf_chars, cnt_imp);
	printf_chars = printf("%.s\n", "hello");
	cnt_imp = ft_printf("%.s\n", "hello");
	check_ft(printf_chars, cnt_imp);
	printf_chars = printf("%.0s\n", "hello");
	cnt_imp = ft_printf("%.0s\n", "hello");
	check_ft(printf_chars, cnt_imp);
	printf_chars = printf("%7.5s\n", "hello");
	cnt_imp = ft_printf("%7.5s\n", "hello");
	check_ft(printf_chars, cnt_imp);
	printf_chars = printf("%7.9s\n", "hello");
	cnt_imp = ft_printf("%7.9s\n", "hello");
	check_ft(printf_chars, cnt_imp);
	printf_chars = printf("%3.9s\n", "hello");
	cnt_imp = ft_printf("%3.9s\n", "hello");
	printf_chars = printf("%7.1s\n", "hello");
	cnt_imp = ft_printf("%7.1s\n", "hello");
	check_ft(printf_chars, cnt_imp);
	printf_chars = printf("%7.1s\n", "hello");
	cnt_imp = ft_printf("%7.1s\n", "hello");
	check_ft(printf_chars, cnt_imp);
	printf_chars = printf("%3.1s\n", "hello");
	cnt_imp = ft_printf("%3.1s\n", "hello");
	check_ft(printf_chars, cnt_imp);
	printf_chars = printf("%.s\n", "hello");
	cnt_imp = ft_printf("%.s\n", "hello");
	check_ft(printf_chars, cnt_imp);
	printf_chars = printf("%.0s\n", "hello");
	cnt_imp = ft_printf("%.0s\n", "hello");
	check_ft(printf_chars, cnt_imp);
	printf_chars = printf("hello, %s.\n", NULL);
	cnt_imp = ft_printf("hello, %s.\n", NULL);
	check_ft(printf_chars, cnt_imp);
	printf_chars = printf("%09s\n", "hi low");
	cnt_imp = ft_printf("%09s\n", "hi low");
	check_ft(printf_chars, cnt_imp);
	printf_chars = printf("%%d 0000042 == |%d|\n", 0000042);
	cnt_imp = ft_printf("%%d 0000042 == |%d|\n", 0000042);
	check_ft(printf_chars, cnt_imp);
	printf("************************** TEST x X ****************************\n");
	printf_chars = printf("this %x number\n", 45653);
	cnt_imp = ft_printf("this %x number\n", 45653);
	check_ft(printf_chars, cnt_imp);
	printf_chars = printf("this %X number\n", 456453);
	cnt_imp = ft_printf("this %X number\n", 456453);
	check_ft(printf_chars, cnt_imp);
	printf_chars = printf("this %X number\n", 0);
	cnt_imp = ft_printf("this %X number\n", 0);
	check_ft(printf_chars, cnt_imp);
	printf("************************** TEST p *****************************\n");
	printf_chars = printf("%p\n", "Hola");
	cnt_imp = ft_printf("%p\n", "Hola");
	check_ft(printf_chars, cnt_imp);
	printf_chars = printf("%p\n", NULL);
	cnt_imp = ft_printf("%p\n", NULL);
	check_ft(printf_chars, cnt_imp);
	printf_chars = printf("%p\n", &a01);
	cnt_imp = ft_printf("%p\n", &a01);
	check_ft(printf_chars, cnt_imp);
	printf_chars = printf("%p\n", &a02);
	cnt_imp = ft_printf("%p\n", &a02);
	check_ft(printf_chars, cnt_imp);
	printf_chars = printf("%p\n", &a03);
	cnt_imp = ft_printf("%p\n", &a03);
	check_ft(printf_chars, cnt_imp);
	printf_chars = printf("%p\n", &a04);
	cnt_imp = ft_printf("%p\n", &a04);
	check_ft(printf_chars, cnt_imp);
	printf_chars = printf("%p\n", &a05);
	cnt_imp = ft_printf("%p\n", &a05);
	check_ft(printf_chars, cnt_imp);
	printf_chars = printf("%p\n", &a05);
	cnt_imp = ft_printf("%p\n", &a05);
	check_ft(printf_chars, cnt_imp);
	printf_chars = printf("%p\n", &a06);
	cnt_imp = ft_printf("%p\n", &a06);
	check_ft(printf_chars, cnt_imp);
	printf_chars = printf("%p\n", &a07);
	cnt_imp = ft_printf("%p\n", &a07);
	check_ft(printf_chars, cnt_imp);
	printf_chars = printf("%p\n", &a08);
	cnt_imp = ft_printf("%p\n", &a08);
	check_ft(printf_chars, cnt_imp);
	printf_chars = printf("%p\n", &a09);
	cnt_imp = ft_printf("%p\n", &a09);
	check_ft(printf_chars, cnt_imp);
	printf_chars = printf("%p\n", &a10);
	cnt_imp = ft_printf("%p\n", &a10);
	check_ft(printf_chars, cnt_imp);
	printf_chars = printf("%p\n", &a11);
	cnt_imp = ft_printf("%p\n", &a11);
	check_ft(printf_chars, cnt_imp);
	printf_chars = printf("%p\n", &a12);
	cnt_imp = ft_printf("%p\n", &a12);
	check_ft(printf_chars, cnt_imp);
	printf_chars = printf("%9.2p\n", 1234);
	cnt_imp = ft_printf("%9.2p\n", 1234);
	check_ft(printf_chars, cnt_imp);
	printf_chars = printf("%.5p\n", 0);
	cnt_imp = ft_printf("%.5p\n", 0);
	check_ft(printf_chars, cnt_imp);
	printf_chars = printf("%1.0i\n", 0);
	cnt_imp = ft_printf("%1.0i\n", 0);
	check_ft(printf_chars, cnt_imp);
	printf_chars = printf("%1i\n", 0);
	cnt_imp = ft_printf("%1i\n", 0);
	check_ft(printf_chars, cnt_imp);
	printf_chars = printf("%1.i\n", 0);
	cnt_imp = ft_printf("%1.i\n", 0);
	check_ft(printf_chars, cnt_imp);
	printf("************************** TEST XXXXXXXX *****************************\n");
	printf_chars = printf("%p\n", (void*)-20);
	cnt_imp = ft_printf("%p\n", (void*)-20);
	check_ft(printf_chars, cnt_imp);
	printf_chars = printf("%.s\n", 123000000) ;
	cnt_imp = ft_printf("%.s\n", 123000000) ;
	check_ft(printf_chars, cnt_imp);
	printf_chars = printf("%s\n", 0) ;
	cnt_imp = ft_printf("%s\n", 0) ;
	check_ft(printf_chars, cnt_imp);
	printf_chars = printf("%01.0i\n", 0) ;
	cnt_imp = ft_printf("%01.0i\n", 0) ;
	check_ft(printf_chars, cnt_imp);
	printf_chars = printf("%02.0i\n", 0) ;
	cnt_imp = ft_printf("%02.0i\n", 0) ;
	check_ft(printf_chars, cnt_imp);
	printf_chars = printf("%010.0i\n", 0) ;
	cnt_imp = ft_printf("%010.0i\n", 0) ;
	check_ft(printf_chars, cnt_imp);
	printf_chars = printf("%03.0i\n", -1) ;
	cnt_imp = ft_printf("%03.0i\n", -1) ;
	check_ft(printf_chars, cnt_imp);
	printf_chars = printf("%011.0i\n", INT_MAX);
	cnt_imp = ft_printf("%011.0i\n", INT_MAX) ;
	check_ft(printf_chars, cnt_imp);
	printf_chars = printf("%011i\n", INT_MAX);
	cnt_imp = ft_printf("%011i\n", INT_MAX) ;
	check_ft(printf_chars, cnt_imp);
	printf_chars = printf("%.*d\n", -10, 42);
	cnt_imp = ft_printf("%.*d\n", -10, 42) ;
	check_ft(printf_chars, cnt_imp);
	printf_chars = printf("%.*d\n", -10, 0);
	cnt_imp = ft_printf("%.*d\n", -10, 0) ;
	check_ft(printf_chars, cnt_imp);
	printf_chars = printf("%.*s\n", -3, "Hello");
	cnt_imp = ft_printf("%.*s\n", -3, "Hello") ;
	check_ft(printf_chars, cnt_imp);
	printf_chars = printf("%*.*d\n", 0, -5, 0);
	cnt_imp = ft_printf("%*.*d\n", 0, -5, 0) ;
	check_ft(printf_chars, cnt_imp);
	printf_chars = printf("%*.*s\n", 0, -5, "Hello");
	cnt_imp = ft_printf("%*.*s\n", 0, -5, "Hello") ;
	check_ft(printf_chars, cnt_imp);
	printf_chars = printf("size = %d\n", t2);
	cnt_imp = ft_printf("size = %d\n", t2) ;
	check_ft(printf_chars, cnt_imp);
	printf_chars = printf("-->|%*.*s|<--\n", 3, 2, s);
	cnt_imp = ft_printf("-->|%*.*s|<--\n", 3, 2, s) ;
	check_ft(printf_chars, cnt_imp);
	printf_chars = printf("-->|%*.*s|<--\n", 3, 3, s);
	cnt_imp = ft_printf("-->|%*.*s|<--\n", 3, 3, s) ;
	check_ft(printf_chars, cnt_imp);
	printf_chars = printf("-->|%*.*s|<--\n", 3, 4, s);
	cnt_imp = ft_printf("-->|%*.*s|<--\n", 3, 4, s) ;
	check_ft(printf_chars, cnt_imp);
	printf_chars = printf("-->|%*.*s|<--\n", 4, -4, s);
	cnt_imp = ft_printf("-->|%*.*s|<--\n", 4, -4, s) ;
	check_ft(printf_chars, cnt_imp);
	printf_chars = printf("-->|%*.*s|<--\n", 4, -3, s);
	cnt_imp = ft_printf("-->|%*.*s|<--\n", 4, -3, s) ;
	check_ft(printf_chars, cnt_imp);
	printf_chars = printf("-->|%*.*s|<--\n", 3, 2, s);
	cnt_imp = ft_printf("-->|%*.*s|<--\n", 3, 2, s) ;
	check_ft(printf_chars, cnt_imp);
	printf_chars = printf("%.s", 42);
	cnt_imp = ft_printf("%.s", 42) ;
	check_ft(printf_chars, cnt_imp);


	printf("************************** TEST + Flag *****************************\n");
	printf_chars = printf("%+d\n", 42);
	cnt_imp = ft_printf("%+d\n", 42);
	check_ft(printf_chars, cnt_imp);
	printf_chars = printf("%+d\n", -42);
	cnt_imp = ft_printf("%+d\n", -42) ;
	check_ft(printf_chars, cnt_imp);
	printf_chars = printf("%+10d\n", 42);
	cnt_imp = ft_printf("%+10d\n", 42) ;
	check_ft(printf_chars, cnt_imp);
	printf_chars = printf("%+d\n", 0);
	cnt_imp = ft_printf("%+d\n", 0);
	check_ft(printf_chars, cnt_imp);
	printf_chars = printf("%-+10d\n", 0);
	cnt_imp = ft_printf("%-+10d\n", 0) ;
	check_ft(printf_chars, cnt_imp);
	printf_chars = printf("%+15d\n", 0);
	cnt_imp = ft_printf("%+15d\n", 0) ;
	check_ft(printf_chars, cnt_imp);
	printf("******************************************************************\n");
	system("leaks -q --fullContent ft_printf.out");
	return (0);
}
