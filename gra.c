#include <stdlib.h>#include <stdio.h>#include <conio.h>#include <windows.h>#include <unistd.h>void start(){	system("cls");	printf("\n		Witamy w grze a'la Space Invators\n\n");	printf("		Gra kultowa, zasady raczej kazdy zna\n\n");	printf("		Sterowanie:\n");	printf("		Poruszanie sie: 'A' i 'D'\n");	printf("		strzelanie: 'W'\n\n");	printf("		Wcisnij dowolny przycisk by rozpoczac");	getch();}void koniec(int wynik, int wygrana){	system("cls");	if (wygrana>0)printf("		WYGRANA!\n\n");	else printf("		Przegrales :(\n\n");	printf("	Twoj wynik to:		%d",wynik);}void rozgrywka(){	int wysokosc=20;	int szerokosc=31;	char tab[szerokosc][wysokosc];	int wygrana=0;	char przycisk;	int wrog=0;	int punkty=0;	int znak=1;	int czas=0;			for(int x=0;x<szerokosc;x++){			//czyszczenie tablicy		for(int y=0;y<wysokosc;y++){			tab[x][y]=' ';		}	}		tab[(szerokosc/2)-2][wysokosc-1]='<';	//rysowanie gracza	tab[(szerokosc/2)-1][wysokosc-1]='-';	tab[szerokosc/2][wysokosc-1]='I';	tab[(szerokosc/2)+1][wysokosc-1]='-';	tab[(szerokosc/2)+2][wysokosc-1]='>';		for(int x=2;x<(szerokosc*2)/3;x=x+2){	//rysowanie wrogow		for(int y=1;y<wysokosc/2;y=y+2){			tab[x][y]='O';			wrog++;		}	}		while(wygrana==0){			system("cls");					//wypisanie menu z wynikiem		printf("|  Wynik:%4.i          wrogow:%2.i|\n|",punkty,wrog);		for(int x=0;x<szerokosc;x++){			printf("-");		}		printf("|\n");				for(int y=0;y<wysokosc;y++){			//wyswietlanie tablicy			printf("|");			for(int x=0;x<szerokosc;x++){				printf("%c",tab[x][y]);			}			printf("|\n");		}				if (czas==20){							//ruch			if(znak<0){							//w lewo				for(int x=0;x<szerokosc-1;x++){					for(int y=0;y<wysokosc-1;y++){						if (tab[x][y]=='O'){							tab[x-1][y]=tab[x][y];							tab[x][y]=' ';						}					}				}			}else{								//w prawo				for(int x=szerokosc-1;x>=0;x--){					for(int y=wysokosc-1;y>=0;y--){						if (tab[x][y]=='O'){							tab[x+1][y]=tab[x][y];							tab[x][y]=' ';						}					}				}			}			for(int y=wysokosc-1;y>=0;y--){		//w dół				if(tab[szerokosc-3][y]=='O' || tab[2][y]=='O'){					for(int x=0;x<szerokosc;x++){						tab[x][y+1]=tab[x][y];						tab[x][y]=' ';					}					znak*=-1;				}			}			for(int x=0;x<szerokosc;x++){				if(tab[x][wysokosc-2]=='O')					wygrana=-1;			}			czas=0;		}				for(int x=0;x<szerokosc;x++){			//animacja trafienia			for(int y=1;y<wysokosc-1;y++){				if((tab[x][y]=='|')&&(tab[x][y-1]=='O')){					tab[x][y-1]='X';					tab[x][y]=' ';					wrog--;					punkty+=100;				}				if(tab[x][y]=='X'){					tab[x][y]=' ';				}			}		}				for(int x=0;x<szerokosc;x++){			//animacja strzalu			for(int y=1;y<wysokosc;y++){				if(tab[x][0]=='|')					tab[x][0]=' ';				if(tab[x][y]=='|' && tab[x][y-1]!='|'){					tab[x][y-1]='|';					tab[x][y]=' ';				}			}		}				if(kbhit()) przycisk = getch();			//pobieranie znaku z klawiatury        else przycisk=' ';				if(przycisk=='w'){						//strzal			for(int x=0;x<szerokosc;x++){				if((tab[x][wysokosc-1]=='I') && ((tab[x][wysokosc-2]!='|')) && (tab[x][wysokosc-3]!='|')){					tab[x][wysokosc-2]='|';				}			}		}				if(przycisk=='a'){						//sterowanie w lewo			for(int x=0;x<szerokosc;x++){				if(tab[x+1][wysokosc-1]=='<'){					tab[x][wysokosc-1]=tab[x+1][wysokosc-1];					tab[x+1][wysokosc-1]=tab[x+2][wysokosc-1];					tab[x+2][wysokosc-1]=tab[x+3][wysokosc-1];					tab[x+3][wysokosc-1]=tab[x+4][wysokosc-1];					tab[x+4][wysokosc-1]=tab[x+5][wysokosc-1];					tab[x+5][wysokosc-1]=' ';				}			}		}				if(przycisk=='d'){						//sterowanie w prawo			for(int x=szerokosc-1;x>0;x--){				if(tab[x-1][wysokosc-1]=='>'){					tab[x][wysokosc-1]=tab[x-1][wysokosc-1];					tab[x-1][wysokosc-1]=tab[x-2][wysokosc-1];					tab[x-2][wysokosc-1]=tab[x-3][wysokosc-1];					tab[x-3][wysokosc-1]=tab[x-4][wysokosc-1];					tab[x-4][wysokosc-1]=tab[x-5][wysokosc-1];					tab[x-5][wysokosc-1]=' ';				}			}		}		if (wrog==0) wygrana=1;		czas++;		Sleep(17);	}	koniec(punkty,wygrana);}int main(){		HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);		//linijki usuwajace kursor	CONSOLE_CURSOR_INFO ccur;	ccur.dwSize = sizeof(CONSOLE_CURSOR_INFO);	ccur.bVisible = 0;	SetConsoleCursorInfo(hStdOut, &ccur);		start();	rozgrywka();			return 0;}