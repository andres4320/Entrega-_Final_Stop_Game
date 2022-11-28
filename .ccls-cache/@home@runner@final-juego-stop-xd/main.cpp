#include <ctime> // conversion del tiempo 
#include <iomanip> // especificar el formato de hora (tiempo)
#include <iostream> // salida de datos
#include <stdlib.h>
#include <string.h>
#include <string>
using namespace std;

int partidas;

//funcion vacia mostrar_tabla
void mostrarTabla(string categorias[], string tabla[][10]);

int main() {
  string respuesta1, respuesta2;
  int letras;
  string nombre_jugador;
  srand(time(NULL));
  
cout << "\n*************BIENVENIDOS A STOP GAME***************\n\n";
  cout << "¿Como te llamas? ";
  cin >> nombre_jugador;
  cout << "\n";
  cout << "Hola " << nombre_jugador <<", bienvenido a Stopa Game, a continuacion veras las reglas del juego\n\n";
  cout << "¿Estas de acuerdo? (S/N): ";
  cin >> respuesta1;
  cout << "\n";
  
  if (respuesta1 == "s" || respuesta1 == "S") {
    cout <<"************* REGLAS DE JUEGO ***************\n\nEl juego te proporciona 10 letras del abecedario de manera aleatoria.\n";
    cout << "Por cada letra debes escribir una palabra segun los siguientes criterios:\n\n Nombre - Apellido - Ciudad - Animal - Fruta - Color - Objeto\n\n";
    cout << "1. Las respuestas deben estar escritas en ¡MAYUSCULAS!.\n2. Por cada palabra correcta se te asignará 100 puntos.\n3. Por cada palabra incorrecta se te quitarán 100 puntos.\n4. Si, no te sabes las respuestas, escribe un punto '.' no te preocupes, no se quitarán ni se agregarán puntos.\n\n*********************************************\n\n";
    // Condicional para que acepte las reglas del juego
    cout << "¿Tienes claras las reglas del juego? (S/N): ";
    cin >> respuesta2;
    cout<<"\n";
  }  
  else{
    return (0);
  }

 // Nùmero de partidas y letra aleatoria
cout<<"¿Cuantas rondas vas a jugar?\n";
cin>>partidas;
cout<<"\n";
  
 if (respuesta2 == "s" || respuesta2 == "S"){
    cout << "**************** EMPIEZA EL JUEGO *******************\n\n";
  }  
  else if (respuesta2 == "n" || respuesta2 == "N" ) {
    cout << "!Has decidido no jugar, hasta luego¡\n";
    return 0;
  } else {
    cout << "Has seleccionado una opcion invalida\n";
    return 0;
  }

string categorias[10] = {"Letra", "Nombre", "Apellido", "Ciudad", "Animal", "Fruta", "Color", "Objeto", "TIEMPO", "TOTAL"};



   string tabla[partidas][10];
   int puntajeFila = 0, PuntajeTotal = 0;
  
   for (int fila = 0; fila < partidas; fila++) {
   char letra[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I','J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R','S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
   char abecedario = letra[rand() % 26];
   tabla[fila][0] = char(abecedario);
    
    // ctime 1 
  float tiempo;
   tiempo = clock(); // Inicial el tiempo
     
    // Inicio del juego 
    for (int columna2 = 0; columna2 < 1; columna2++) {
      cout << "(Letra " << char(abecedario)<<")\n";    
      for (int columna = 1; columna < 8; columna++) {
      cout << "Ingresa un(a) " << categorias[columna]<<": "; 
      cin >> tabla[fila][columna];
        if (tabla[fila][columna].front() == char(abecedario)) {
          puntajeFila += 100;
        } else if (tabla[fila][columna] == ".") {
          puntajeFila += 0;
        } else {
          puntajeFila -= 100;
        }
      }
    }  
     
      // ctime 2
      tiempo = clock() - tiempo; // finaliza el tiempo
      cout << "\nTiempo por ronda: "<<(float)tiempo << "\n\n";
      tabla[fila][8] = to_string((float)tiempo);
      tabla[fila][9] = to_string(puntajeFila);
     cout<<PuntajeTotal;
      puntajeFila = 0;
    }
  
  cout <<"\n--------------------------------------------------------------RESULTADOS----------------------------------------------------------------------------\n" << endl;
  
  mostrarTabla(categorias, tabla);
  }


//Mostrar la tabla con las categorias como encabezado
void mostrarTabla(string categorias[], string tabla[][10]) {
  for (int i = 0; i <= 9; i++) {
    cout << setw(15) << categorias[i];
  }

  
//Mostrar las palabras que ingreso el jugador dentro de la tabla
  cout << endl;
  for (int i = 0; i < partidas; i++) {
    for (int j = 0; j <= 9; j++) {
      cout << setw(15) << tabla[i][j];
    }
    cout << endl;
  }
  cout <<"\n----------------------------------------------------------TOTALES------------------------------------------------------------------------------------\n\n";
  
}