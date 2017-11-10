#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED

#endif // UTN_H_INCLUDED

int getInt(char* mensaje);
float getFloat(char* mensaje);
char getChar(char* mensaje);
void getString(char mensaje[],char input[]);

int esSoloNumerico(char *datos);
int esNumericoFlotante(char dato[]);
int esSoloLetras(char *datos);
int esSoloLetrasYNumeros(char *datos) ;


int getStringLetras(char mensaje[],char input[]);
int getStringNumeros(char mensaje[],char input[]);
int getStringNumerosFlotantes(char mensaje[],char input[]);

int getIntValidado(char mensaje[],char errorMensajeTipo[], char errorMensajeRango[], int* input,int cotaInferior, int cotaSuperior);
int getFloatValidado(char mensaje[],char errorMensajeTipo[], char errorMensajeRango[], float* input,float cotaInferior, float cotaSuperior);
int getStringValidado(char mensaje[],char errorMensajeTipo[], char errorMensajeLargo[],char input[], int largoMaximo);
