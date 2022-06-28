void Quader2 (double X1, double Y1, double X2, double Y2,double c, double Alpha, int Tiefe1)
{
	double XH1, YH1, YHilf, XHilf;
	XH1 = X1;
	YH1 = Y1;
	
	X1 = X1 + (c * sin(Alpha*M_PI/180.));
	Y1 = Y1 + (c * sin((90.-Alpha)*M_PI/180.));
	XHilf = X1 - (c * sin((90.-Alpha)*M_PI/180.));
	YHilf = Y1 + (c * sin(Alpha*M_PI/180.));
	
	X2 = XH1 + (YH1 - Y1);
	Y2 = YH1 + (X1 - XH1);
	
	printf("Q2Wert Alpha: %lf \n", Alpha);
	
	fprintf(fileOut,"%lf %lf %i\n%lf %lf %i\n%lf %lf %i\n%lf %lf %i\n%lf %lf %i\n\n",
			XH1,YH1,n+1,X1,Y1,n+2,XHilf,YHilf,n+3,X2,Y2,n+4, XH1,YH1,n+5);
				
		n += 5;
		
	
	if (Tiefe1 > 0)
	{
		Dreieck (X2 ,Y2, XHilf, YHilf, c, Alpha, Tiefe1);
	}
}
