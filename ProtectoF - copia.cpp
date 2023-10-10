#include <iostream>
#include <locale.h>
#include <windows.h>
#include <string.h>
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
		decimalHexadecimal();				//Métodos de la clase conversiones
		binarioDecimal();					//
		binarioOctal();						//
		binarioHexadecimal();
};
Conversiones::Conversiones(int _numero){//Constructor
	numero = _numero;
}

//Métodos de la clase conversiones

Conversiones::decimalMaya(){
	//proceso para convertir a maya
	int cociente, residuo, vectorMaya[50], i = 0;
	int numOriginal = numero;
	do{
		cociente = numero / 20;
		residuo = numero % 20;
		vectorMaya[i] = residuo;
		numero = cociente;
		i++;
	}while(cociente >= 20);
	vectorMaya[i] = cociente;
	cout<<"\n\n\t\tEl número "<<numOriginal<<" en maya es: \n\n";
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
			cout<<"\t\t0\n(0)\n";
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

//función para convertir de decimal a hexadecimal y a octal 
funcionConvertir(int base, int numero){
	int cociente, residuo;
	int i = 0, numOriginal = numero;
	string valores[] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "a", "b", "c", "d", "e", "f"}, resultado[30];
	do{
		cociente = numero / base;
		residuo = numero % base;
		resultado[i] = valores[residuo];
		numero = cociente;
		i++;
	}while(cociente > base);
	
	resultado[i] = valores[cociente];
	
	if(base == 8){
		cout<<"El número "<<numOriginal<<" en octal es: \n";
	}else if(base == 16){
		cout<<"El número "<<numOriginal<<" en hexadecimal es: \n";
	}else if(base == 2){
		cout<<"El número "<<numOriginal<<" en binario es: \n";
	}
	
	for(int j = i; j >= 0; j--){
		cout<<resultado[j];
	}
}

Conversiones::decimalBinario(){
	//proceso para convertir a binario
	funcionConvertir(2, numero);
}

Conversiones::decimalOctal(){
	//proceso para convertir a octal
	funcionConvertir(8, numero);
	//falta validar decimales
}

Conversiones::decimalHexadecimal(){
	//proceso para convertir a hexadecimal
	funcionConvertir(16, numero);
	//falta validar decimales
}

Conversiones::binarioDecimal(){
	//proceso para convertir binario a decimal
	
	cout<<"binario a decimal "<<numero;
}

Conversiones::binarioOctal(){
	//proceso para convertir binario a octal
	cout<<"binario a octal "<<numero;
}

Conversiones::binarioHexadecimal(){
	//proceso para convertir binario a hexadecimal
	cout<<"binario a hexadecimal "<<numero;
}

//Clase de combinatoria

class Combinatoria{
	private:
		int n, r;
	public:
		Combinatoria(int, int);//Se inicializa el constructor
		permutacionOrdinaria();				//
		permutacionDosAspectos();			//
		palomar();							//Métodos de la clase combinatoria
		combinacion();						//
};

Combinatoria::Combinatoria(int _n, int _r){//Constructor
	n = _n;
	r = _r;
}

//Métodos de la clase combinatoria
//función para obtener el factorial
unsigned long factorial(int n){
	if(n < 1){
		return 1;
	}
	return n * factorial(n - 1);
}
Combinatoria::permutacionOrdinaria(){
	//proceso para obtener la permutación ordinaria 
	cout<<"permutacionordinaria n: "<<n<<"r: "<<r;
}

Combinatoria::permutacionDosAspectos(){
	//proceso para obtener la permutación con dos aspectos
	cout<<"permutaciondosaspectos n: "<<n<<"r: "<<r;
}

Combinatoria::palomar(){
	//proceso para el pricipio del palomar
	cout<<"palomar n: "<<n<<"r: "<<r;
}

Combinatoria::combinacion(){
	//proceso para obtener la combinación
	unsigned long combinacion = factorial(n) / (factorial(r) * factorial(n - r));
	cout<<n<<"C"<<r<<" = "<<n<<"!/("<<r<<"!("<<n<<" - "<<r<<")!)\n";
	cout<<n<<"C"<<r<<" = "<<combinacion;
}

//Clase para hacer el triángulo de Pascal

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

//Funciones para imprimir los menús

//Pantalla de inicio
menu1(){
	cout<<"\n\t\t| __ )  |_ _| | ____| | \\ | | \\ \\   / / | ____| | \\ | | |_ _| |  _ \\   / _ \\ \n";
 	cout<<"\t\t|  _ \\   | |  |  _|   |  \\| |  \\ \\ / /  |  _|   |  \\| |  | |  | | | | | | | |\n";
 	cout<<"\t\t| |_) |  | |  | |___  | |\\  |   \\ V /   | |___  | |\\  |  | |  | |_| | | |_| |\n";
 	cout<<"\t\t|____/  |___| |_____| |_| \\_|    \\_/    |_____| |_| \\_| |___| |____/   \\___/ \n";
 	cout<<"\n\n\n\t(1) Conversiones\n";
 	cout<<"\t(2) Combinatoria\n";
 	cout<<"\t(3) Triángulo de Pascal\n";
 	cout<<"\t(4) Salir\n";
 	
}

//Menú de conversiones
conversionesMenu(){
    cout<<"\n\t\t _____                                               _\n";                              
    cout<<"\t\t/ ____|                                             (_)\n";                             
    cout<<"\t\t| |        ___    _ __   __   __   ___   _ __   ___   _    ___    _ __     ___   ___ \n";
    cout<<"\t\t| |       / _ \\  | '_ \\  \\ \\ / /  / _ \\ | '__| / __| | |  / _ \\  | '_ \\   / _ \\ / __|\n";
    cout<<"\t\t| |____  | (_) | | | | |  \\ V /  |  __/ | |    \\__ \\ | | | (_) | | | | | |  __/ \\__ \\\n";
    cout<<"\t\t\\_____|   \\___/  |_| |_|   \\_/    \\___| |_|    |___/ |_|  \\___/  |_| |_|  \\___| |___/\n";
    
	cout<<"\n\n\tMENÚ: \n";                                                                                                                                                            
	cout<<"\n\t(1) Conversión de decimal a maya\n";
	cout<<"\n\t(2) Conversión de decimal a binario\n";
	cout<<"\n\t(3) Conversión de decimal a octal\n";
	cout<<"\n\t(4) Conversión de decimal a hexadecimal\n";
	cout<<"\n\t(5) Conversión de binario a decimal\n";
	cout<<"\n\t(6) Conversión de binario a octal\n";
	cout<<"\n\t(7) Conversión de binario a hexadecimal\n";
	cout<<"\n\n\t(8) Regresar\n";
}

//Menú de combinatoria
combinatoriaMenu(){
	cout<<"\n\t\t  _____                       _       _                   _                    _\n";        
  	cout<<"\t\t / ____|                     | |     (_)                 | |                  (_)\n";        
 	cout<<"\t\t| |        ___    _ __ ___   | |__    _   _ __     __ _  | |_    ___    _ __   _    __ _\n"; 
 	cout<<"\t\t| |       / _ \\  | '_ ` _ \\  | '_ \\  | | | '_ \\   / _` | | __|  / _ \\  | '__| | |  / _` |\n";
 	cout<<"\t\t| |____  | (_) | | | | | | | | |_) | | | | | | | | (_| | | |_  | (_) | | |    | | | (_| |\n";
  	cout<<"\t\t \\_____|  \\___/  |_| |_| |_| |_.__/  |_| |_| |_|  \\__,_|  \\__|  \\___/  |_|    |_|  \\__,_|\n";
                                                                                          
    cout<<"\n\n\tMENÚ: \n";                                                                        
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
			cout<<"\n\n\tIngresa el número para convertir a Maya: ";
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
			cout<<"Ingresa un numero ";
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
			cout<<"\n\n\tIngresa el número para convertir a ocatal: ";
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
			cout<<"\n\n\tIngresa el número para convertir a hexadecimal: ";
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
			cout<<"Ingresa un numero ";
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
			cout<<"Ingresa un numero ";
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
			cout<<"Ingresa un numero ";
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
			cout<<"\n\tOpción no válida ";
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
			cout<<"Ingresa un numero ";
			cin>>numero;
			cout<<"Ingresa otro numero";
			cin>>numero1;
			Combinatoria opcion(numero, numero1);			
			opcion.permutacionOrdinaria();
			cout<<endl;
			system("pause");			
		break;
		}
		case 2:{
			system("cls");
			titulos(9);
			cout<<"Ingresa un numero ";
			cin>>numero;
			cout<<"Ingresa otro numero";
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
			cout<<"Ingresa un numero ";
			cin>>numero;
			cout<<"Ingresa otro numero";
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
			cout<<"Ingresa un numero ";
			cin>>numero;
			cout<<"Ingresa otro numero";
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
			cout<<"\n\tOpción no válida ";
			system("pause");
			system("cls");
	}
}

//Función principal
main(){
	system("mode con: cols=150 lines=30"); //Se define el tamaño de la consola 
	system("color 70");
	setlocale(LC_ALL, "");
	int op;
	do{
		system("cls");
		menu1();
		cout<<"\n\tIngrese una opción: ";
 		cin>>op;
 		switch(op){
 			case 1:
 				do{
 					system("cls");
 					conversionesMenu();
 					cout<<"\n\tIngrese una opción: ";
 					cin>>op;
 					opcionesConversion(op);
				 }while(op != 8);
 			break;
 			case 2:
 				do{
 					system("cls");
 					combinatoriaMenu();
 					cout<<"\n\tIngrese una opción: ";
 					cin>>op;
 					opcionesCombinatoria(op);
				 }while(op != 5);
 			break;
 			case 3:{
 				system("cls");
 				int tam;
 				titulos(12);
 				cout<<"\nIngresa el tamaño del triángulo: ";
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
				cout<<"\n\tOpción no válida ";
				system("pause");
				system("cls");
			break;
	 	}
	}while(op != 4);	
}

