/* filename:	Hausaufgabe Semester 2
 *  
 * author:		Lukas Brand									
 * date:		18.06.22						
 * purpose:		mit dem Code / Funktion von Sascha mit fehler nach meinen verbesserungen
 * 				- Winkel Variable zu einem vereint
 * 				- Striche entfernt
 * 				- Debug ausgaben entfernt
 * 				-> zufallszahlen noch bearbeiten und fragen wie diese Progammiert werden sollen
 * 				- eingabe wurde erfolgreich eingefügt, funktion überprüft
 * 				- FEHLER: bei unsymmetrischem Baum!
 */

//Bibiliotheken einbinden
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

//Variable für Hypothennusenlänge
#define basislang 5

//maximaler Wertebereich von 2147483647
#define minzz 0.0
#define maxzz RAND_MAX
//Auflösung des Wertebereichs von 26,565° - 63,435°
double minf = (atan(0.5/1)*180/M_PI);
double maxf = (atan(2/1)*180/M_PI);
double kathetenverhaltnis;

//Laufvariable für Nummerierte Zählung
int n = 0;	

//Zeiger für pythagorasBaum_Koord.txt Ausgabe
FILE *fileOut;

void Quader (double X1, double Y1, double X2, double Y2,double c, double Alpha, int Tiefe1);
void Dreieck (double X1,double Y1,double X2,double Y2,double c,double Alpha,int Tiefe1);

int main ()
{
	//Öffnen einder Datei, damit generierte Daten darin gespeichert werden können
	fileOut = fopen("pythagorasBaum_Koord.txt","w");
	
	if(fileOut == NULL) {
      printf("Konnte Datei \"pythagorasBaum_Koord.txt\" nicht öffnen!\n");
      return EXIT_FAILURE;
	}
	//Generieren der Zufallszahl
	srand (time (NULL));
	
	kathetenverhaltnis  = ((1.0 * rand() - minzz) / (maxzz - minzz) * (maxf - minf) + minf);
		
	printf("DEG-kathetenverhaltnis: %lf\n", kathetenverhaltnis);
	
	kathetenverhaltnis = kathetenverhaltnis*M_PI/180;
	
	printf("RAD-kathetenverhaltnis: %lf\n", kathetenverhaltnis);
	
	//Eingabe der Schachteltiefe
	printf("Eingaben der Wiederholungen/Schachteltiefe:\n");
	int ergs;
	int iter_count;
	do
	{
		ergs = scanf("%d",&iter_count);
		while (getchar () != '\n');
	} while ((ergs != 1) || (iter_count <= 1) || (iter_count >= 25));
	//Bereich der Eingabe liegt von 1 bis 25
	
	//Beginnen mit der Anfangsbedingung
	Quader(0, 0, 0, basislang, basislang, 90, iter_count);
	
	fclose(fileOut);

	return 0;
}

void Quader (double X1, double Y1, double X2, double Y2,double c, double Alpha, int Tiefe1)
{
	double XH1, YH1, YHilf, XHilf;
	XH1 = X1;
	YH1 = Y1;
	
	X1 = X1 + (c * sin(Alpha*M_PI/180));
	Y1 = Y1 + (c * sin((90-Alpha)*M_PI/180));
	XHilf = X1 - (c * sin((90-Alpha)*M_PI/180));
	YHilf = Y1 + (c * sin(Alpha*M_PI/180));
	X2 = XH1 + (YH1 - Y1);
	Y2 = YH1 + (X1 - XH1);
	
	fprintf(fileOut,"%lf %lf %i\n%lf %lf %i\n%lf %lf %i\n%lf %lf %i\n%lf %lf %i\n\n",
			XH1,YH1,n+1,X1,Y1,n+2,XHilf,YHilf,n+3,X2,Y2,n+4, XH1,YH1,n+5);
				
		n += 5;
	if (Tiefe1 > 0)
	{
		Dreieck (X2 ,Y2, XHilf, YHilf, c, Alpha, Tiefe1);
	}
}

void Dreieck (double X1,double Y1,double X2,double Y2,double c,double Alpha,int Tiefe1)
{
	double YHilf, XHilf, b;
	b = c * sin(atan(kathetenverhaltnis));	//gegenkatethe berechen
	Alpha = Alpha + (asin(b/c)*180/M_PI); 	//hier wieder im Gradmaß
	
	c = sqrt (c*c - b*b); //berechnung ankatethe
	
	XHilf = X1 - (c * sin(((90-Alpha)*M_PI)/180));
	YHilf = Y1 + (c * sin((Alpha*M_PI)/180));
	

	fprintf(fileOut,"%lf %lf %i\n%lf %lf %i\n%lf %lf %i\n\n",
			X1,Y1,n+1,XHilf,YHilf,n+2,X2,Y2,n+3);
	n += 3;
		
	//Quader (X1, Y1, XHilf, YHilf, c, Alpha-90, Tiefe1-1);
	Quader (XHilf, YHilf, X2, Y2, b, Alpha, Tiefe1-1);
	Quader (X1, Y1, XHilf, YHilf, c, Alpha-90, Tiefe1-1);
}
