#include <mysql.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
int main(int argc, char **argv)
{
	MYSQL *conn;
	int err;
	// Estructura especial para almacenar resultados de consultas 
	MYSQL_RES *resultado;
	MYSQL_ROW row;
	int numpartida;
	char color[10];
	char consulta[100];
	
	//Creamos una conexion al servidor MYSQL 
	conn = mysql_init(NULL);
	if (conn==NULL) {
		printf ("Error al crear la conexion: %u %s\n", 
				mysql_errno(conn), mysql_error(conn));
		exit (1);
	}
	
	//inicializar la conexion
	conn = mysql_real_connect (conn, "localhost","root", "mysql", "LaserTails",0, NULL, 0);
	if (conn==NULL) {
		printf ("Error al inicializar la conexion: %u %s\n", 
				mysql_errno(conn), mysql_error(conn));
		exit (1);
	}
	
	
	char consulta [80];
	strcpy (consulta,"SELECT Partidas.tiempo FROM Partidas, Participaciones, Jugadores WHERE Partidas.id = Participaciones.idP AND Participaciones.idj = Jugadores.id AND Jugadores.nombre = 'Juan'");
	
	err=mysql_query (conn, consulta);
	if (err!=0) {
		printf ("Error al consultar datos de la base %u %s\n",
				mysql_errno(conn), mysql_error(conn));
		exit (1);
	}
	
	row = mysql_fetch_row (resultado);
	
	
	if (row == NULL)
		printf ("No se han obtenido datos en la consulta\n");
	else
		printf ("El tiempo de partida és: %d\n", row [0] );
	
	mysql_close (conn);
	exit(0);
	
	
}
