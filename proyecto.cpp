#include <iostream>
#include <locale.h>
#include <windows.h>
#include <string.h>
#include <math.h>
#include <limits>
using namespace std;

#define color SetConsoleTextAtribute

//Clase de conversiones

class Conversiones {
	private:
		int numero;
	public:
		Conversiones(int);//Se inicializa el constructor
		decimalMaya();
		decimalBinario();					//
		decimalOctal();						//	
		decimalHexadecimal();				//M�todos de la clase conversiones
		binarioDecimal();					//
		binarioOctal();						//
		binarioHexadecimal();
};
Conversiones::Conversiones(int _numero){//Constructor
	numero = _numero;
}

//M�todos de la clase conversiones

Conversiones::decimalMaya(){
	//proceso para convertir a maya
	int cociente, residuo, vectorMaya[50], i = 0;
	int numOriginal = numero;
	if(numero < 0){
		cout<<"\n\n\tN�mero no v�lido";
	}else{
		do{
			cociente = numero / 20;
			residuo = numero % 20;
			vectorMaya[i] = residuo;
			numero = cociente;
			i++;
		}while(cociente >= 20);
		vectorMaya[i] = cociente;
		cout<<"\n\n\t\tEl n�mero "<<numOriginal<<" en maya es: \n\n";
		for(int j = i; j >= 0; j--){
			if(vectorMaya[j] >= 5){
				cociente = vectorMaya[j] / 5;
				residuo = vectorMaya[j] % 5;
				cout<<"\t\t"<<vectorMaya[j]<<endl;
				cout<<"\t\t";
				for(int a = 1; a <= residuo; a++){
					cout<<".";
				}
				cout<<endl;
				for(int a = 1; a <= cociente; a++){
					cout<<"\t\t____\n";
				}
			}else if(vectorMaya[j] == 0){
				cout<<"\t\t0\n\t\t(0)\n";
			}else{
				cout<<"\t\t"<<vectorMaya[j]<<endl;
				cout<<"\t\t";
				for(int a = 1; a <= vectorMaya[j]; a++){
					cout<<".";
				}
				cout<<endl;
			}
			cout<<endl;
		}	
	}
}

//funci�n para convertir de decimal a hexadecimal y a octal 
funcionConvertir(int base, int numero){
	int cociente, residuo;
	int i = 0, numOriginal = numero;
	string valores[] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "a", "b", "c", "d", "e", "f"}, resultado[30];
	if(numero < 0){
		numero *= -1;	
	}
	do{
		cociente = numero / base;
		residuo = numero % base;
		resultado[i] = valores[residuo];
		numero = cociente;
		i++;
	}while(cociente >= base);
	
	resultado[i] = valores[cociente];
	if(numOriginal < 0){
		i++;
		resultado[i] = "-";
	}
	for(int j = i; j >= 0; j--){
		cout<<resultado[j];
	}
}

Conversiones::decimalBinario(){
	//proceso para convertir a binario
	cout<<"\n\n\tEl n�mero "<<numero<<" en binario es: ";
	funcionConvertir(2, numero);
}

Conversiones::decimalOctal(){
	//proceso para convertir a octal
	cout<<"\n\n\tEl n�mero "<<numero<<" en octal es: ";
	funcionConvertir(8, numero);
	//falta validar decimales
}

Conversiones::decimalHexadecimal(){
	//proceso para convertir a hexadecimal
	cout<<"\n\n\tEl n�mero "<<numero<<" en hexadecimal es: ";
	funcionConvertir(16, numero);
	//falta validar decimales
}

cifras(int numero, int base){
	int i = 0, numO = numero, suma = 0, cifras[30], verif = 1;
	if(numero < 0){
		numero *= -1;
	}
	while(numero > 0){
		cifras[i] = numero % 10;
		if(cifras[i] >= 2){
			cout<<"\n\n\tEl n�mero que se ingres� no es v�lido\n";
			verif = 0;
			break;
		}
		numero /= 10;
		i++; 
	}
	if(verif == 1){
		for(int j = 0; j < i; j++){
			suma += pow(2, j) * cifras[j];
		}
		if(base == 8){
			cout<<"\n\n\tEl n�mero "<<numO<<" en octal es: ";
			if(numO < 0){
				cout<<"-";
			}
			funcionConvertir(8, suma);
		}else if(base == 16){
			cout<<"\n\n\tEl n�mero "<<numO<<" en hexadecimal es: ";
			if(numO < 0){
				cout<<"-";
			}
			funcionConvertir(16, suma);
		}else if(base == 2){
			cout<<"\n\n\tEl n�mero "<<numO<<" en decimal es: ";
			if(numO < 0){
				cout<<"-";
			}	
			cout<<suma;
		}	
	}
}

Conversiones::binarioDecimal(){
	//proceso para convertir binario a decimal
	cifras(numero, 2);
}

Conversiones::binarioOctal(){
	//proceso para convertir binario a octal
	cifras(numero, 8);
}

Conversiones::binarioHexadecimal(){
	//proceso para convertir binario a hexadecimal
	cifras(numero, 16);
}

//Clase de combinatoria

class Combinatoria{
	private:
		int n, r;
	public:
		Combinatoria(int, int);//Se inicializa el constructor
		permutacionOrdinaria();				//
		permutacionDosAspectos();			//
		palomar();							//M�todos de la clase combinatoria
		combinacion();						//
};

Combinatoria::Combinatoria(int _n, int _r){//Constructor
	n = _n;
	r = _r;
}
//funci�n para obtener el factorial
unsigned long factorial(int n){
	if(n < 1){
		return 1;
	}
	return n * factorial(n - 1);
}
//FUNCION PALOMAR
void funcionPalomar(int numero, int numero1){

	if(numero < 1 || numero1 < 1){
		cout << "\n\n\tERROR, el n�mero 0 y negativos no son v�lidos, vuelve a intentarlo.";
	}else if (numero > numero1){ 
		int sobrante = numero / numero1;
        cout << "\n\nEl principio del palomar se cumple. Hay " << sobrante << " elementos sobrantes, por lo que al menos un palomar tendr� m�s elementos (elemento repetido) que el resto.\n";
    } else if (numero == numero1){
        cout << "\n\n\tEl principio del palomar no se cumple, ya que todos los palomares contienen solo un elemento.\n";
    } else if (numero1 > numero){
        cout << "\n\n\tEl principio del palomar no se cumple, hay menos palomas que palomares\n"; 
    }
}
// Funci�n para calcular el n�mero de combinaciones C(n, r)
unsigned long long calcularCombinaciones(int numero, int numero1) {
    if (numero1 < 0 || numero1 > numero) {
		return 0;  // Combinaci�n no v�lida
    }else{
    	return factorial(numero) / (factorial(numero1) * factorial(numero - numero1));
    }
}
//PERMUTACION ORDINARIA

//FUNCION IMORIMIR NUMEROS ASI 5x4x3x2x1
void imprimirFactorialConMultiplicacion(int num) {
    if (num < 0) {
        cout << "\tFactorial no definido para n�meros negativos." << std::endl;
        return;
    }
	cout << "\n\n\tLa permutaci�n ordinaria es de: \n";
    cout << "\n\n\t"<< num << "! = ";
    for (int i = num; i > 0; --i) {
        cout << i;
        if (i > 1) {
            cout << " x ";
        }
    }
    cout << " = " << factorial(num) << endl;
}

//FUNCION PARA CALCULAR EL NUMERO DE PERMUTACIONES DOS ASPECTOS
unsigned long long calcularPermutaciones(int numero, int numero1) {
    if (numero1 < 0 || numero1 > numero) {
		return 0;  // Combinaci�n no v�lida
    }else{
    	return factorial(numero) / factorial(numero - numero1);
    }
}

//M�todos de la clase combinatoria

Combinatoria::permutacionOrdinaria(){
	//proceso para obtener la permutaci�n ordinaria 
	imprimirFactorialConMultiplicacion(n);
}

Combinatoria::permutacionDosAspectos(){
	//proceso para obtener la permutaci�n con dos aspectos
	if(calcularPermutaciones(n, r) == 0){
		cout << "\n\n\tERROR, VALORES NO V�LIDOS n debe ser mayor a r. Vuelve a intentarlo";
	}else{
		cout<<"\n\n\t"<<n<<"P"<<r<<" = "<<n<<"!/"<<"("<<n<<" - "<<r<<")!\n";
		cout << "\n\n\tLas permutaciones posibles son de: "<< calcularPermutaciones(n, r);
	}
}

Combinatoria::palomar(){
	//proceso para el pricipio del palomar
	funcionPalomar(n, r);
}

Combinatoria::combinacion(){
	//proceso para obtener la combinaci�n
	if(r > n || n < 1 || r < 1){
		cout<<"\n\n\tLos ingresados no son correctos";
	}else{
		unsigned long combinacion = factorial(n) / (factorial(r) * factorial(n - r));
		cout<<n<<"C"<<r<<" = "<<n<<"!/("<<r<<"!("<<n<<" - "<<r<<")!)\n";
		cout<<n<<"C"<<r<<" = "<<combinacion;	
	}
}

//Clase para hacer el tri�ngulo de Pascal

class TrianguloPascal{
	private:
		int cant;
	public:
		TrianguloPascal(int);
		hacerTriangulo();
};
TrianguloPascal::TrianguloPascal(int _cant){
	cant = _cant;
}
TrianguloPascal::hacerTriangulo(){
	unsigned long c;
	if(cant < 0){
		cout<<"\n\n\tEl n�mero ingresado no es correcto ";
	}else{
		for(int i = 0; i <= cant; i++){
			for(int j = cant - i; j >= 0; j--){
				cout<<" ";
			}
			for(int j = 0; j <= i; j++){
				c = factorial(i)/(factorial(j)*factorial(i - j));
				cout<<c<<" ";
			}
			cout<<endl;
		}	
	}
}

//Funciones para imprimir los men�s

//Pantalla de inicio
menu1(){
	cout<<"\n\t\t| __ )  |_ _| | ____| | \\ | | \\ \\   / / | ____| | \\ | | |_ _| |  _ \\   / _ \\ \n";
 	cout<<"\t\t|  _ \\   | |  |  _|   |  \\| |  \\ \\ / /  |  _|   |  \\| |  | |  | | | | | | | |\n";
 	cout<<"\t\t| |_) |  | |  | |___  | |\\  |   \\ V /   | |___  | |\\  |  | |  | |_| | | |_| |\n";
 	cout<<"\t\t|____/  |___| |_____| |_| \\_|    \\_/    |_____| |_| \\_| |___| |____/   \\___/ \n";
 	cout<<"\n\n\n\n\t(1) Conversiones\n\n";
 	cout<<"\t(2) Combinatoria\n\n";
 	cout<<"\t(3) Tri�ngulo de Pascal\n\n";
 	cout<<"\t(4) Salir\n\n";
 	
}

//Men� de conversiones
conversionesMenu(){
    cout<<"\n\t\t _____                                               _\n";                              
    cout<<"\t\t/ ____|                                             (_)\n";                             
    cout<<"\t\t| |        ___    _ __   __   __   ___   _ __   ___   _    ___    _ __     ___   ___ \n";
    cout<<"\t\t| |       / _ \\  | '_ \\  \\ \\ / /  / _ \\ | '__| / __| | |  / _ \\  | '_ \\   / _ \\ / __|\n";
    cout<<"\t\t| |____  | (_) | | | | |  \\ V /  |  __/ | |    \\__ \\ | | | (_) | | | | | |  __/ \\__ \\\n";
    cout<<"\t\t\\_____|   \\___/  |_| |_|   \\_/    \\___| |_|    |___/ |_|  \\___/  |_| |_|  \\___| |___/\n";
    
	cout<<"\n\n\tMEN�: \n";                                                                                                                                                            
	cout<<"\n\t(1) Conversi�n de decimal a maya\n";
	cout<<"\n\t(2) Conversi�n de decimal a binario\n";
	cout<<"\n\t(3) Conversi�n de decimal a octal\n";
	cout<<"\n\t(4) Conversi�n de decimal a hexadecimal\n";
	cout<<"\n\t(5) Conversi�n de binario a decimal\n";
	cout<<"\n\t(6) Conversi�n de binario a octal\n";
	cout<<"\n\t(7) Conversi�n de binario a hexadecimal\n";
	cout<<"\n\n\t(8) Regresar\n";
}

//Men� de combinatoria
combinatoriaMenu(){
	cout<<"\n\t\t  _____                       _       _                   _                    _\n";        
  	cout<<"\t\t / ____|                     | |     (_)                 | |                  (_)\n";        
 	cout<<"\t\t| |        ___    _ __ ___   | |__    _   _ __     __ _  | |_    ___    _ __   _    __ _\n"; 
 	cout<<"\t\t| |       / _ \\  | '_ ` _ \\  | '_ \\  | | | '_ \\   / _` | | __|  / _ \\  | '__| | |  / _` |\n";
 	cout<<"\t\t| |____  | (_) | | | | | | | | |_) | | | | | | | | (_| | | |_  | (_) | | |    | | | (_| |\n";
  	cout<<"\t\t \\_____|  \\___/  |_| |_| |_| |_.__/  |_| |_| |_|  \\__,_|  \\__|  \\___/  |_|    |_|  \\__,_|\n";
                                                                                          
    cout<<"\n\n\tMEN�: \n";                                                                        
	cout<<"\n\t(1) Permutaciones ordinarias\n";
	cout<<"\n\t(2) Permutaciones con dos aspectos\n";
	cout<<"\n\t(3) Principio del palomar\n";
	cout<<"\n\t(4) Combinaciones\n";
	cout<<"\n\n\t(5) Regresar\n";
}

//Titulos para las opciones
titulos(int figura){
	switch(figura){
		case 1:
			cout<<"\n\t\t ___               _                  _\n";                                         
 			cout<<"\t\t|   \\   ___   __  (_)  _ __    __ _  | |    __ _     _ __    __ _   _  _   __ _\n";
 			cout<<"\t\t| |) | / -_) / _| | | | '  \\  / _` | | |   / _` |   | '  \\  / _` | | || | / _` |\n";
 			cout<<"\t\t|___/  \\___| \\__| |_| |_|_|_| \\__,_| |_|   \\__,_|   |_|_|_| \\__,_|  \\_, | \\__,_|\n";
			cout<<"\t\t                                                                    |__/\n";       
		break;
		case 2:
			cout<<"\n\t\t ___               _                  _              _      _                       _\n";       
 			cout<<"\t\t|   \\   ___   __  (_)  _ __    __ _  | |    __ _    | |__  (_)  _ _    __ _   _ _  (_)  ___\n";
 			cout<<"\t\t| |) | / -_) / _| | | | '  \\  / _` | | |   / _` |   | '_ \\ | | | ' \\  / _` | | '_| | | / _ \\ \n";
 			cout<<"\t\t|___/  \\___| \\__| |_| |_|_|_| \\__,_| |_|   \\__,_|   |_.__/ |_| |_||_| \\__,_| |_|   |_| \\___/ \n";
		break;
		case 3:
			cout<<"\n\t\t ___               _                  _                         _            _ \n";
 			cout<<"\t\t|   \\   ___   __  (_)  _ __    __ _  | |    __ _     ___   __  | |_   __ _  | |\n";
 			cout<<"\t\t| |) | / -_) / _| | | | '  \\  / _` | | |   / _` |   / _ \\ / _| |  _| / _` | | |\n";
 			cout<<"\t\t|___/  \\___| \\__| |_| |_|_|_| \\__,_| |_|   \\__,_|   \\___/ \\__|  \\__| \\__,_| |_|\n";                                                                 
		break;
		case 4:
			cout<<"\n ___               _                  _              _                            _              _                  _\n";
			cout<<"|   \\   ___   __  (_)  _ __    __ _  | |    __ _    | |_    ___  __ __  __ _   __| |  ___   __  (_)  _ __    __ _  | |\n";
			cout<<"| |) | / -_) / _| | | | '  \\  / _` | | |   / _` |   | ' \\  / -_) \\ \\ / / _` | / _` | / -_) / _| | | | '  \\  / _` | | |\n";
			cout<<"|___/  \\___| \\__| |_| |_|_|_| \\__,_| |_|   \\__,_|   |_||_| \\___| /_\\_\\ \\__,_| \\__,_| \\___| \\__| |_| |_|_|_| \\__,_| |_|\n";                                                                                           
		break;
		case 5:
			cout<<"\n\t\t ___   _                       _                    ___               _                  _ \n";
			cout<<"\t\t| _ ) (_)  _ _    __ _   _ _  (_)  ___     __ _    |   \\   ___   __  (_)  _ __    __ _  | |\n";
			cout<<"\t\t| _ \\ | | | ' \\  / _` | | '_| | | / _ \\   / _` |   | |) | / -_) / _| | | | '  \\  / _` | | |\n";
			cout<<"\t\t|___/ |_| |_||_| \\__,_| |_|   |_| \\___/   \\__,_|   |___/  \\___| \\__| |_| |_|_|_| \\__,_| |_|\n";                                                                                                                
		break;
		case 6:
			cout<<"\n\t\t ___   _                       _                               _            _\n";
			cout<<"\t\t| _ ) (_)  _ _    __ _   _ _  (_)  ___     __ _     ___   __  | |_   __ _  | |\n";
			cout<<"\t\t| _ \\ | | | ' \\  / _` | | '_| | | / _ \\   / _` |   / _ \\ / _| |  _| / _` | | |\n";
			cout<<"\t\t|___/ |_| |_||_| \\__,_| |_|   |_| \\___/   \\__,_|   \\___/ \\__|  \\__| \\__,_| |_|\n"; 
                                                                               
		break;
		case 7:
			cout<<"\n ___   _                       _                    _                            _              _                  _\n";
			cout<<"| _ ) (_)  _ _    __ _   _ _  (_)  ___     __ _    | |_    ___  __ __  __ _   __| |  ___   __  (_)  _ __    __ _  | |\n";
			cout<<"| _ \\ | | | ' \\  / _` | | '_| | | / _ \\   / _` |   | ' \\  / -_) \\ \\ / / _` | / _` | / -_) / _| | | | '  \\  / _` | | |\n";
			cout<<"|___/ |_| |_||_| \\__,_| |_|   |_| \\___/   \\__,_|   |_||_| \\___| /_\\_\\ \\__,_| \\__,_| \\___| \\__| |_| |_|_|_| \\__,_| |_|\n";
		break;
		case 8:
			cout<<"\n\t\t ___                              _                 _                  \n";
			cout<<"\t\t| _ \\  ___   _ _   _ __    _  _  | |_   __ _   __  (_)  ___   _ _       \n";
			cout<<"\t\t|  _/ / -_) | '_| | '  \\  | || | |  _| / _` | / _| | | / _ \\ | ' \\    \n";
			cout<<"\t\t|_|   \\___| |_|   |_|_|_|  \\_,_|  \\__| \\__,_| \\__| |_| \\___/ |_||_|\n";
			cout<<"\t\t  	        _   _                       _\n";
			cout<<"\t\t ___   _ _   __| | (_)  _ _    __ _   _ _  (_)  __ _\n";
			cout<<"\t\t/ _ \\ | '_| / _` | | | | ' \\  / _` | | '_| | | / _` |\n";
			cout<<"\t\t\\___/ |_|   \\__,_| |_| |_||_| \\__,_| |_|   |_| \\__,_|\n";                                    
		break;
		case 9:
			cout<<"\n\t\t ___                              _                 _                  \n";
			cout<<"\t\t| _ \\  ___   _ _   _ __    _  _  | |_   __ _   __  (_)  ___   _ _       \n";
			cout<<"\t\t|  _/ / -_) | '_| | '  \\  | || | |  _| / _` | / _| | | / _ \\ | ' \\    \n";
			cout<<"\t\t|_|   \\___| |_|   |_|_|_|  \\_,_|  \\__| \\__,_| \\__| |_| \\___/ |_||_|\n";
			cout<<"\t\t    _                                              _\n";
			cout<<"\t\t __| |  ___   ___    __ _   ___  _ __   ___   __  | |_   ___   ___\n";
			cout<<"\t\t/ _` | / _ \\ (_-<   / _` | (_-< | '_ \\ / -_) / _| |  _| / _ \\ (_-<\n";
			cout<<"\t\t\\__,_| \\___/ /__/   \\__,_| /__/ | .__/ \\___| \\__|  \\__| \\___/ /__/\n";
            cout<<"\t\t                                |_|\n";                               
		break;
		case 10:
			cout<<"\n\t\t ___          _\n";
			cout<<"\t\t| _ \\  __ _  | |  ___   _ __    __ _   _ _ \n";
			cout<<"\t\t|  _/ / _` | | | / _ \\ | '  \\  / _` | | '_|\n";
			cout<<"\t\t|_|   \\__,_| |_| \\___/ |_|_|_| \\__,_| |_|  \n";
		break;
		case 11:
			cout<<"\n\t\t  ___                 _      _                      _\n";
			cout<<"\t\t / __|  ___   _ __   | |__  (_)  _ _    __ _   __  (_)  ___   _ _\n";
			cout<<"\t\t| (__  / _ \\ | '  \\  | '_ \\ | | | ' \\  / _` | / _| | | / _ \\ | ' \\\n";
			cout<<"\t\t \\___| \\___/ |_|_|_| |_.__/ |_| |_||_| \\__,_| \\__| |_| \\___/ |_||_|\n";
		break;
		case 12:
			cout<<"\n\t\t _____         _                               _\n";       
 			cout<<"\t\t|_   _|  _ _  (_)  __ _   _ _    __ _   _  _  | |  ___\n"; 
            cout<<"\t\t  | |   | '_| | | / _` | | ' \\  / _` | | || | | | / _ \\\n";
   			cout<<"\t\t  |_|   |_|   |_| \\__,_| |_||_| \\__, |  \\_,_| |_| \\___/\n";
            cout<<"\t\t                   		 |___/\n\n";
			cout<<"\t\t    _                                          _\n"; 
  			cout<<"\t\t __| |  ___     _ __   __ _   ___  __   __ _  | |\n";
 			cout<<"\t\t/ _` | / -_)   | '_ \\ / _` | (_-< / _| / _` | | |\n";
 			cout<<"\t\t\\__,_| \\___|   | .__/ \\__,_| /__/ \\__| \\__,_| |_|\n";
            cout<<"\t\t               |_|\t";                                                
		break;
	}
}
//Funciones para seleccionar opciones

//seleccionar opciones de conversiones
opcionesConversion(int op){
	int numero;
	switch(op){
		case 1:{
			system("cls");
			titulos(1);
			cout<<"\n\n\tIngresa el n�mero para convertir a Maya: ";
			cin>>numero;
			Conversiones opcion(numero);			
			opcion.decimalMaya();
			cout<<endl;
			system("pause");
		break;
		}
		case 2:{
			system("cls");
			titulos(2);
			cout<<"\n\n\tIngresa el n�mero para convertir a Binario: ";
			cin>>numero;
			Conversiones opcion(numero);			
			opcion.decimalBinario();
			cout<<endl;
			system("pause");
		break;
		}
		case 3:{
			system("cls");
			titulos(3);
			cout<<"\n\n\tIngresa el n�mero para convertir a octal: ";
			cin>>numero;
			Conversiones opcion(numero);			
			opcion.decimalOctal();
			cout<<endl;
			system("pause");
		break;
		}
		case 4:{
			system("cls");
			titulos(4);
			cout<<"\n\n\tIngresa el n�mero para convertir a hexadecimal: ";
			cin>>numero;
			Conversiones opcion(numero);			
			opcion.decimalHexadecimal();
			cout<<endl;
			system("pause");
		break;
		}
		case 5:{
			system("cls");
			titulos(5);
			cout<<"\n\n\tIngresa un n�mero en binario para convertir a decimal: ";
			cin>>numero;
			Conversiones opcion(numero);			
			opcion.binarioDecimal();
			cout<<endl;
			system("pause");			
		break;
		}
		case 6:{
			system("cls");
			titulos(6);
			cout<<"\n\n\tIngresa un n�mero para convertir a Octal: ";
			cin>>numero;
			Conversiones opcion(numero);			
			opcion.binarioOctal();
			cout<<endl;
			system("pause");			
		break;
		}
		case 7:{
			system("cls");
			titulos(7);
			cout<<"\n\n\tIngresa un n�mero para convertir a hexadecimal: ";
			cin>>numero;
			Conversiones opcion(numero);			
			opcion.binarioHexadecimal();
			cout<<endl;
			system("pause");			
		break;
		}
		case 8:
			menu1();
		break;
		default:
			cout<<"\n\tOpci�n no v�lida ";
			system("pause");
			system("cls");
		break;
	}
}
//seleccionar opciones de combinatoria
opcionesCombinatoria(int op){
	int numero, numero1;
	switch(op){
		case 1:{
			system("cls");
			titulos(8);
			cout<<"\n\n\tIngresa el valor de n: ";
			cin>>numero;
			//cout<<"\n\n\tIngresa el valor de r: \n";
			//cin>>numero1;
			Combinatoria opcion(numero, numero1);			
			opcion.permutacionOrdinaria();
			cout<<endl;
			system("pause");			
		break;
		}
		case 2:{
			system("cls");
			titulos(9);
			cout<<"\n\n\tIngresa un el valor de n: ";
			cin>>numero;
			cout<<"\n\n\tIngresa el valor de r: ";
			cin>>numero1;
			Combinatoria opcion(numero, numero1);			
			opcion.permutacionDosAspectos();
			cout<<endl;
			system("pause");			
		break;
		}
		case 3:{
			system("cls");
			titulos(10);
			cout<<"\n\n\tIngresa el n�mero de palomas: ";
			cin>>numero;
			cout<<"\n\n\tIngresa el n�mero de palomares: ";
			cin>>numero1;
			Combinatoria opcion(numero, numero1);			
			opcion.palomar();
			cout<<endl;
			system("pause");			
		break;
		}
		case 4:{
			system("cls");
			titulos(11);
			cout<<"\n\n\tIngresa el valor de n: ";
			cin>>numero;
			cout<<"\n\n\tIngresa el valor de r: ";
			cin>>numero1;
			Combinatoria opcion(numero, numero1);			
			opcion.combinacion();
			cout<<endl;
			system("pause");			
			break;
		}
		case 5:
			menu1();
		break;
		default:
			cout<<"\n\tOpci�n no v�lida ";
			system("pause");
			system("cls");
	}
}
template <class TIPOD>
validarInput(TIPOD op){
	while( true ){
    		if(!cin.good()){
      			cin.clear();
      			cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
      			op = 20;
      			break;
    		}else
      			break;
  		}
}

//Funci�n principal
main(){
	system("mode con: cols=150 lines=50"); //Se define el tama�o de la consola 
	system("color 70");
	setlocale(LC_ALL, "");
	int op;
	do{ 
		system("cls");
		menu1();
		cout<<"\n\tIngrese una opci�n: ";
		cin >> op;
 		validarInput(op);
 		switch(op){
 			case 1:
 				do{
 					system("cls");
 					conversionesMenu();
 					cout<<"\n\tIngrese una opci�n: ";
 					cin>>op;
 					validarInput(op);
 					opcionesConversion(op);
				 }while(op != 8);
 			break;
 			case 2:
 				do{
 					system("cls");
 					combinatoriaMenu();
 					cout<<"\n\tIngrese una opci�n: ";
 					cin>>op;
 					validarInput(op);
 					opcionesCombinatoria(op);
				 }while(op != 5);
 			break;
 			case 3:{
 				system("cls");
 				int tam;
 				titulos(12);
 				cout<<"\n\n\tIngresa el tama�o del tri�ngulo: ";
				cin>>tam;
				TrianguloPascal hacer(tam);
				hacer.hacerTriangulo();
				system("pause");
			break;
			}
 			case 4:
 				cout<<"\n\tFin del programa";
				system("exit");
			break;
			default:
				cout<<"\n\tOpci�n no v�lida ";
				system("pause");
				system("cls");
			break;
	 	}
	}while(op != 4);	
}


