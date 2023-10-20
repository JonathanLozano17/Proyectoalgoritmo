// clientes, artículos y pedidos.Hasta el momento se registran los siguientes datos en documentos varios :
//• Para cada cliente : Número de cliente(único), Direcciones de envío(varias por cliente), Saldo, Límite de crédito(depende del cliente, pero en ningún caso debe superar los 3.000.000 pts), Descuento.
//• Para cada artículo : Número de artículo(único), Fábricas que lo distribuyen, Existencias de ese artículo en cada fábrica, Descripción del artículo.
//• Para cada pedido : Cada pedido tiene una cabecera y el cuerpo del pedido.La cabecera está formada por el número de cliente, dirección de envío y fecha
//del pedido.El cuerpo del pedido son varias líneas, en cada línea se especifican el número del artículo pedido y la cantidad.
//Además, se ha determinado que se debe almacenar la información de las fábricas.Sin embargo, dado el uso de distribuidores, se usará : Número de la fábrica
//(único) y Teléfono de contacto.Y se desean ver cuántos artículos(en total) provee la fábrica.También, por información estratégica, se podría incluir
//información de fábricas alternativas respecto de las que ya fabrican artículos para esta empresa.
//Nota : Una dirección se entenderá como Nº, Calle, Comuna y Ciudad.Una fecha incluye hora.
//Nota0 : escoger los almacenes = 3
//Nota 1 : ingresar el cliente con sus datos personales
//Nota2 : límite de crédito = 3000.000
//Nota 3 : mínimo 20 artículos con su stock descripción y precio
//Nota 4 : proveedor de los artículos
// 
//No superar el valor de precio de 3.000.000 y el usuario debe ingresar el nombre y debe comprar y se tiene un inventario y un stock
//y se va decrementando del stock, y diga cuanto saldo quedo y exista algun articulo que tenga descuento, y diga que cosas se comrparon 
// y el valor que quedo restante 

//
//Objetivo: Crear un programa que gestione los clientes, artículos y pedidos de una empresa.
//
//Datos :
//
//    Cliente : Cada cliente tiene un número único, una o más direcciones de envío, un saldo, un límite de crédito y un descuento.El límite de crédito no puede superar los 3.000.000 pts.
//    Artículo : Cada artículo tiene un número único, una descripción, un precio y una o más fábricas que lo distribuyen.Cada fábrica tiene un número único, un teléfono de contacto y un stock de cada artículo que provee.Se debe almacenar la información de las fábricas y sus artículos, incluyendo las fábricas alternativas si existen.
//    Pedido : Cada pedido tiene una cabecera y un cuerpo.La cabecera contiene el número de cliente, la dirección de envío y la fecha(con hora) del pedido.El cuerpo contiene varias líneas, cada una con el número y la cantidad del artículo pedido.
//    Requisitos :
//
//    El programa debe permitir al usuario ingresar su nombre y seleccionar uno de los tres almacenes disponibles.
//    El programa debe mostrar al usuario los artículos disponibles en el almacén seleccionado, con su descripción, precio y stock.
//    El programa debe permitir al usuario comprar uno o más artículos, siempre que no se supere el límite de crédito ni el stock del almacén.
//    El programa debe aplicar el descuento correspondiente al cliente si existe.
//    El programa debe actualizar el saldo del cliente y el stock del almacén después de cada compra.
//    El programa debe mostrar al usuario el resumen del pedido, con los artículos comprados, sus precios, el total a pagar y el saldo restante.
//    El programa debe guardar el pedido en un archivo con la información de la cabecera y el cuerpo.

#include <iostream>
#include <string>
#include <vector>
//#define CP_UTF8 65001 

using namespace std;


//Generacion de las clases necesarias y sus respectivos procedimientos

// Clase cliente
class Cliente {
public:
    int id;
    string nombre;
    string apellido;
    string direccion;
    string telefono;
    float saldo;
    float limite_credito;
    float descuento;

    Cliente(int id, string nombre, string apellido, string direccion, string telefono, float saldo, float limite_credito, float descuento) {
        this->id = id;
        this->nombre = nombre;
        this->apellido = apellido;
        this->direccion = direccion;
        this->telefono = telefono;
        this->saldo = saldo;
        this->limite_credito = limite_credito;
        this->descuento = descuento;
    }



    void mostrar() {
        cout << "ID: " << id << endl;
        cout << "Nombre: " << nombre << endl;
        cout << "Apellido: " << apellido << endl;
        cout << "Dirección: " << direccion << endl;
        cout << "Teléfono: " << telefono << endl;
        cout << "Saldo: " << saldo << endl;
        cout << "Límite de crédito: " << limite_credito << endl;
        cout << "Descuento: " << descuento << endl;
    }

    // Operación crear cliente
    Cliente* crearCliente(int id, string nombre, string apellido, string direccion, string telefono, float saldo, float limite_credito, float descuento) {
        // Crea un nuevo objeto de la clase Cliente con los datos especificados.
        Cliente* cliente = new Cliente(id, nombre, apellido, direccion, telefono, saldo, limite_credito, descuento);

        return cliente;
    }

    // Operación actualizar cliente
    void actualizarCliente(Cliente* cliente, int id, string nombre, string apellido, string direccion, string telefono, float saldo, float limite_credito, float descuento) {
        // Asigna los nuevos datos al objeto cliente.
        cliente->id = id;
        cliente->nombre = nombre;
        cliente->apellido = apellido;
        cliente->direccion = direccion;
        cliente->telefono = telefono;
        cliente->saldo = saldo;
        cliente->limite_credito = limite_credito;
        cliente->descuento = descuento;
    }


    // Operación eliminar cliente
    void eliminarCliente(Cliente* cliente) {
        // Elimina el objeto cliente.
        delete cliente;
    }





};

// Clase artículo
class Articulo {
public:
    int id;
    vector<int> fabricas;
    vector<int> existencias;
    string descripcion;
    float precio;

    Articulo(int id, vector<int> fabricas, vector<int> existencias, string descripcion, float precio) {
        this->id = id;
        this->fabricas = fabricas;
        this->existencias = existencias;
        this->descripcion = descripcion;
        this->precio = precio;
    }

    void mostrar() {
        cout << "ID: " << id << endl;
        cout << "Fabricas: " << endl;
        for (int i = 0; i < fabricas.size(); i++) {
            cout << fabricas[i] << " ";
        }
        cout << endl;
        cout << "Existencias: " << endl;
        for (int i = 0; i < existencias.size(); i++) {
            cout << existencias[i] << " ";
        }
        cout << endl;
        cout << "Descripción: " << descripcion << endl;
        cout << "Precio: " << precio << endl;
    }

    // Operación crear artículo
    Articulo* crearArticulo(int id, vector<int> fabricas, vector<int> existencias, string descripcion, float precio) {
        // Crea un nuevo objeto de la clase Articulo con los datos especificados.
        Articulo* articulo = new Articulo(id, fabricas, existencias, descripcion, precio);

        return articulo;
    }


    // Operación actualizar artículo
    void actualizarArticulo(Articulo* articulo, int id, vector<int> fabricas, vector<int> existencias, string descripcion, float precio) {
        // Asigna los nuevos datos al objeto artículo.
        articulo->id = id;
        articulo->fabricas = fabricas;
        articulo->existencias = existencias;
        articulo->descripcion = descripcion;
        articulo->precio = precio;
    }


    // Operación eliminar artículo
    void eliminarArticulo(Articulo* articulo) {
        // Elimina el objeto artículo.
        delete articulo;
    }


};

// Clase pedido
class Pedido {
public:
    int id;
    int cliente_id;
    string direccion_envio;
    //Revisar el tipo de dato date 
    string fecha;
    vector<int> articulos;
    vector<int> cantidades;

    Pedido(int id, int cliente_id, string direccion_envio, string fecha, vector<int> articulos, vector<int> cantidades) {
        this->id = id;
        this->cliente_id = cliente_id;
        this->direccion_envio = direccion_envio;
        this->fecha = fecha;
        this->articulos = articulos;
        this->cantidades = cantidades;
    }

    void mostrar() {
        cout << "ID: " << id << endl;
        cout << "Cliente ID: " << cliente_id << endl;
        cout << "Dirección de envío: " << direccion_envio << endl;
        cout << "Fecha: " << fecha << endl;
        cout << "Artículos: " << endl;
        for (int i = 0; i < articulos.size(); i++) {
            cout << articulos[i] << " ";
        }
        cout << endl;
        cout << "Cantidades: " << endl;
        for (int i = 0; i < cantidades.size(); i++) {
            cout << cantidades[i] << " ";
        }
    }

    // Operación crear pedido
    Pedido* crearPedido(int id, int cliente_id, string direccion_envio, string fecha, vector<int> articulos, vector<int> cantidades) {
        // Crea un nuevo objeto de la clase Pedido con los datos especificados.
        Pedido* pedido = new Pedido(id, cliente_id, direccion_envio, fecha, articulos, cantidades);

        return pedido;
    }


    // Operación actualizar pedido
    void actualizarPedido(Pedido* pedido, int id, int cliente_id, string direccion_envio, string fecha, vector<int> articulos, vector<int> cantidades) {
        // Asigna los nuevos datos al objeto pedido.
        pedido->id = id;
        pedido->cliente_id = cliente_id;
        pedido->direccion_envio = direccion_envio;
        pedido->fecha = fecha;
        pedido->articulos = articulos;
        pedido->cantidades = cantidades;
    }


    // Operación eliminar pedido
    void eliminarPedido(Pedido* pedido) {
        // Elimina el objeto pedido.
        delete pedido;
    }


};


// Clase fábrica
class Fabrica {
public:
    int id;
    string nombre;
    string telefono;
    int cantidadArticulosProveidos;
    vector<int> articulos;

    Fabrica(int id, string nombre, string telefono) {
        this->id = id;
        this->nombre = nombre;
        this->telefono = telefono;
        this->cantidadArticulosProveidos = 0;  // Inicializa en 0
    }

    void mostrar() {
        cout << "ID: " << id << endl;
        cout << "Nombre: " << nombre << endl;
        cout << "Teléfono: " << telefono << endl;
        cout << "Artículos: " << endl;
        for (int i = 0; i < articulos.size(); i++) {
            cout << articulos[i] << " ";
        }
        cout << endl;

        // Agregar la siguiente línea para mostrar la cantidad total de artículos proveídos
        cout << "Cantidad total de artículos proveídos: " << cantidadArticulosProveidos << endl;

    }



    // Método para agregar artículos
    void agregarArticulos(vector<int> nuevosArticulos) {
        articulos = nuevosArticulos;
        cantidadArticulosProveidos += nuevosArticulos.size();  // Incrementa la cantidad total

        // Imprimir la lista de artículos relacionados para verificar
        cout << "Artículos relacionados actualizados: ";
        for (int i = 0; i < articulos.size(); i++) {
            cout << articulos[i] << " ";
        }
        cout << endl;
    }


    // Operación crear fábrica
    Fabrica* crearFabrica(int id, string nombre, string telefono, vector<int> articulos) {
        // Crea un nuevo objeto de la clase Fabrica con los datos especificados.
        Fabrica* fabrica = new Fabrica(id, nombre, telefono);
        fabrica->agregarArticulos(articulos);

        return fabrica;
    }


    // Operación actualizar fábrica
    void actualizarFabrica(Fabrica* fabrica, int id, string nombre, string telefono, vector<int> articulos) {
        // Asigna los nuevos datos al objeto fábrica.
        fabrica->id = id;
        fabrica->nombre = nombre;
        fabrica->telefono = telefono;
        fabrica->articulos = articulos;
    }


    // Operación eliminar fábrica
    void eliminarFabrica(Fabrica* fabrica) {
        // Elimina el objeto fábrica.
        delete fabrica;
    }



};




int main() {



    //Realizar el ingreso de datos a cada una de las clases

        // 3 clientes

        //Se agrega la informacion a un vector para poder usarlo con un for
    vector<Cliente*> clientes;
    
    clientes.push_back(new Cliente(1, "Juan", "Pérez", "Calle 123, Ciudad de México", "555-555-5555", 10000, 20000, 10));
    clientes.push_back(new Cliente(2, "Ana", "García", "Calle 456, Bogotá", "333-333-3333", 5000, 10000, 5));
    clientes.push_back(new Cliente(3, "María", "Rodríguez", "Calle 789, Buenos Aires", "222-222-2222", 2000, 5000, 2));



    // 20 artículos

        // Crear un vector de objetos de la clase Articulo
    vector<Articulo*> articulos;

    // Agregar artículos al vector
    articulos.push_back(new Articulo(1, { 1, 2 }, { 100, 200 }, "Teléfono", 1000));
    articulos.push_back(new Articulo(2, { 1, 3 }, { 50, 100 }, "Computadora", 2000));
    articulos.push_back(new Articulo(3, { 2, 3 }, { 20, 40 }, "Televisor", 3000));
    articulos.push_back(new Articulo(4, { 1, 2, 3 }, { 30, 60 }, "Tablet", 1500));
    articulos.push_back(new Articulo(5, { 1, 2, 3 }, { 20, 40 }, "Laptop", 4000));
    articulos.push_back(new Articulo(6, { 1, 2, 3 }, { 10, 20 }, "Impresora", 500));
    articulos.push_back(new Articulo(7, { 1, 2, 3 }, { 20, 40 }, "Escritorio", 1000));
    articulos.push_back(new Articulo(8, { 1, 2, 3 }, { 15, 30 }, "Silla", 250));
    articulos.push_back(new Articulo(9, { 1, 2, 3 }, { 10, 20 }, "Mesa", 500));
    articulos.push_back(new Articulo(10, { 1, 2, 3 }, { 20, 40 }, "Cama", 1500));
    articulos.push_back(new Articulo(11, { 1, 2, 3 }, { 10, 20 }, "Refrigerador", 3000));
    articulos.push_back(new Articulo(12, { 1, 2, 3 }, { 20, 40 }, "Lavadora", 2000));
    articulos.push_back(new Articulo(13, { 1, 2, 3 }, { 10, 20 }, "Televisión inteligente", 5000));
    articulos.push_back(new Articulo(14, { 1, 2, 3 }, { 20, 40, 17 }, "Horno", 1000));
    articulos.push_back(new Articulo(15, { 1, 2, 3 }, { 10, 20 }, "Microondas", 500));
    articulos.push_back(new Articulo(16, { 1, 2, 3 }, { 20, 40 }, "Vacuum cleaner", 200));
    articulos.push_back(new Articulo(17, { 1, 2, 3 }, { 10, 20 }, "Tostadora", 100));
    articulos.push_back(new Articulo(18, { 1, 2, 3 }, { 20, 40 }, "Cafetera", 500));
    articulos.push_back(new Articulo(19, { 1, 2, 3 }, { 20, 40 }, "Reloj", 500));
    articulos.push_back(new Articulo(20, { 1, 2, 3 }, { 10, 20 }, "Celular", 1500));



    // 10 pedidos


    vector<Pedido*> pedidos;


    pedidos.push_back(new Pedido(1, 1, "Calle 123, Ciudad de México", "2023-07-20", { 1, 2 }, { 10, 20 }));
    pedidos.push_back(new Pedido(2, 2, "Calle 456, Bogotá", "2023-07-21", { 3, 4 }, { 15, 25 }));
    pedidos.push_back(new Pedido(3, 3, "Calle 789, Buenos Aires", "2023-07-22", { 1, 3 }, { 20, 30 }));
    pedidos.push_back(new Pedido(4, 1, "Calle 123, Ciudad de México", "2023-07-23", { 1, 2, 3 }, { 10, 20, 30 }));
    pedidos.push_back(new Pedido(5, 2, "Calle 456, Bogotá", "2023-07-24", { 1, 2, 3 }, { 20, 40, 60 }));
    pedidos.push_back(new Pedido(6, 3, "Calle 789, Buenos Aires", "2023-07-25", { 1, 2, 3 }, { 10, 20, 30 }));
    pedidos.push_back(new Pedido(7, 1, "Calle 123, Ciudad de México", "2023-07-26", { 1, 2, 3 }, { 20, 40, 60 }));
    pedidos.push_back(new Pedido(8, 2, "Calle 456, Bogotá", "2023-07-27", { 1, 2, 3 }, { 10, 20, 30 }));
    pedidos.push_back(new Pedido(9, 3, "Calle 789, Buenos Aires", "2023-07-28", { 1, 2, 3 }, { 20, 40, 60 }));
    pedidos.push_back(new Pedido(10, 1, "Calle 123, Ciudad de México", "2023-07-29", { 1, 2, 3 }, { 10, 20, 30 }));


    // 3 fábricas

    vector<Fabrica*> fabricas;

    Fabrica* fabrica1 = new Fabrica(1, "Fábrica 1", "555-555-5555");
    fabrica1->agregarArticulos({ 7 });
    fabricas.push_back(fabrica1);

    Fabrica* fabrica2 = new Fabrica(2, "Fábrica 2", "666-666-6666");
    fabrica2->agregarArticulos({ 17 });
    fabricas.push_back(fabrica2);

    Fabrica* fabrica3 = new Fabrica(3, "Fábrica 3", "777-777-7777");
    fabrica3->agregarArticulos({ 14 });
    fabricas.push_back(fabrica3);



    //***********************Mostrar informacion ingresada*****************************************************+
        // Mostrar la información de los clientes en un bucle
    for (size_t i = 0; i < clientes.size(); i++) {
        cout << "Información del Cliente " << i + 1 << ":\n";
        clientes[i]->mostrar();
        cout << "\n";
    }



    // Mostrar la información de los artículos en un bucle
    for (size_t i = 0; i < articulos.size(); i++) {
        cout << "Información del Artículo " << i + 1 << ":\n";
        articulos[i]->mostrar();
        cout << "\n";
    }



    // Mostrar la información de los pedidos en un bucle
    for (size_t i = 0; i < pedidos.size(); i++) {
        cout << "Información del Pedido " << i + 1 << ":\n";
        pedidos[i]->mostrar();
        cout << "\n";
    }


    // Mostrar la información de las fábricas en un bucle
    for (size_t i = 0; i < fabricas.size(); i++) {
        cout << "Información de la fábrica " << i + 1 << ":\n";
        fabricas[i]->mostrar();
        cout << "\n";
    }


    //***********************Inicializar el programa para realizar el paso a seguir*****************************************************+


    // Crear una instancia de Cliente
    Cliente cliente(5, "", "", "", "", 0, 0, 0);

    // Solicitar al usuario que ingrese el nombre
    cout << "Ingrese el nombre del cliente: ";
    getline(cin, cliente.nombre);

    // Solicitar al usuario que ingrese la dirección
    cout << "Ingrese la dirección del cliente: ";
    getline(cin, cliente.direccion);

    // Asignar valores a otros campos de cliente
    cliente.id = 5;
    cliente.apellido = "Pérez";
    cliente.telefono = "555-555-5555";
    cliente.saldo = 10000;
    cliente.descuento = 0;

    // Calcular y asignar el límite de crédito en función del saldo
    if (cliente.saldo >= 10000) {
        cliente.limite_credito = 3000000; // Límite máximo
    }
    else if (cliente.saldo >= 5000) {
        cliente.limite_credito = 2000000;
    }
    else {
        cliente.limite_credito = 1000000; // Límite mínimo
    }

    //***********************Bucle para Inicializar el programa para realizar el paso a seguir*****************************************************+


    string continuar = "si";
    while (continuar != "n")
    {







        //***********************Inicializar la parte de compra de articulos*****************************************************+







       // ID del cliente que está realizando la compra
        int idCliente = 3; // Puedes cambiar esto según tus necesidades

        

        // Mostrar lista de fábricas y los artículos disponibles en cada fábrica
        for (int i = 0; i < fabricas.size(); i++) {
            cout << "ID Fábrica: " << fabricas[i]->id << ", Nombre: " << fabricas[i]->nombre << ", Teléfono: " << fabricas[i]->telefono << endl;
            cout << "Artículos disponibles: ";
            for (int j = 0; j < fabricas[i]->articulos.size(); j++) {
                int articuloID = fabricas[i]->articulos[j];
                // Buscar el artículo en el vector de artículos
                for (int k = 0; k < articulos.size(); k++) {
                    if (articulos[k]->id == articuloID) {
                        cout << "ID: " << articuloID << ", Descripción: " << articulos[k]->descripcion << ", Precio: " << articulos[k]->precio << ", Existencias: ";
                        for (int l = 0; l < articulos[k]->fabricas.size(); l++) {
                            if (articulos[k]->fabricas[l] == fabricas[i]->id) {
                                cout << "Fábrica " << fabricas[i]->id << ": " << articulos[k]->existencias[l] << " ";
                            }
                        }
                        cout << endl;
                    }
                }
            }
            cout << endl;
        }



        // Solicitar al usuario que ingrese el ID de la fábrica
        int idFabricaSeleccionada;
        bool encontrados = false; // Para comprobar si el artículo está en la fábrica
        cout << "Ingrese el ID de la fábrica deseada: ";
        cin >> idFabricaSeleccionada;

        // Mostrar artículos disponibles en la fábrica seleccionada
        cout << "Artículos disponibles en la fábrica " << idFabricaSeleccionada << ":" << endl;
        for (int i = 0; i < articulos.size(); i++) {
            encontrados = false; // Para comprobar si el artículo está en la fábrica
            for (int j = 0; j < articulos[i]->fabricas.size(); j++) {
                if (articulos[i]->fabricas[j] == idFabricaSeleccionada && articulos[i]->existencias[j] > 0) {
                    encontrados = true;
                    break; // Salir del bucle si el artículo se encuentra en la fábrica
                }
            }
            if (encontrados) {
                cout << "ID: " << articulos[i]->id << ", Descripción: " << articulos[i]->descripcion << ", Precio: " << articulos[i]->precio << endl;
            }
        }

        // Si no se encontraron artículos en la fábrica seleccionada
        if (encontrados == false) {
            cout << "No se encontraron artículos en la fábrica " << idFabricaSeleccionada << "." << endl;
        }



        // Permitir al cliente seleccionar un artículo
        int idArticulo;
        int cantidadComprar;

        cout << "Ingrese el ID del artículo que desea comprar: ";
        cin >> idArticulo;

        cout << "Ingrese la cantidad que desea comprar: ";
        cin >> cantidadComprar;

        // Buscar el artículo seleccionado
        Articulo* articuloComprado = nullptr;
        for (int i = 0; i < articulos.size(); i++) {
            if (articulos[i]->id == idArticulo) {
                articuloComprado = articulos[i];
                break;
            }
        }




        if (articuloComprado) {
            // Verificar si hay suficiente stock del artículo
            int indiceExistencia = -1; // Índice de la existencia en el vector
            for (int i = 0; i < articuloComprado->fabricas.size(); i++) {
                if (articuloComprado->fabricas[i] == idFabricaSeleccionada) {
                    indiceExistencia = i;
                    break;
                }
            }

            if (indiceExistencia != -1) {
                if (articuloComprado->existencias[indiceExistencia] >= cantidadComprar) {
                    // Restar la cantidad comprada de las existencias
                    articuloComprado->existencias[indiceExistencia] -= cantidadComprar;

                    // Calcula el costo total de la compra
                    float costoTotal = cantidadComprar * articuloComprado->precio;

                    // Aplica el descuento si existe
                    costoTotal -= (costoTotal * cliente.descuento / 100);

                    // Restar el costo total al saldo del cliente
                    cliente.saldo -= costoTotal;

                    // Mostrar un mensaje de compra exitosa
                    cout << "Compra exitosa. Costo total: " << costoTotal << " Saldo restante: " << cliente.saldo << endl;
                }
                else {
                    cout << "No hay suficiente stock del artículo seleccionado." << endl;
                }
            }
            else {
                cout << "El artículo seleccionado no está disponible en la fábrica seleccionada." << endl;
            }
        }
        else {
            cout << "El artículo seleccionado no existe." << endl;
        }


        // Mostrar los datos del cliente
        cout << "Datos del cliente:" << endl;
        cout << "Nombre: " << cliente.nombre << endl;
        cout << "Apellido: " << cliente.apellido << endl;
        cout << "Dirección: " << cliente.direccion << endl;
        cout << "Teléfono: " << cliente.telefono << endl;
        cout << "Saldo: " << cliente.saldo << endl;
        cout << "Límite de crédito: " << cliente.limite_credito << endl;
        cout << "Descuento: " << cliente.descuento << endl;




        //Finalizar programa
        cout << "Desea continuar? y/n \n";

        cin >> continuar;

        system("cls");
    }


    //***********************Eliminar el cache*****************************************************+

    // Liberar la memoria de las instancias de clientes
    for (size_t i = 0; i < clientes.size(); i++) {
        delete clientes[i];
    }



    // Liberar la memoria de las instancias de artículos
    for (size_t i = 0; i < articulos.size(); i++) {
        delete articulos[i];
    }


    // Liberar la memoria de las instancias de pedidos
    for (size_t i = 0; i < pedidos.size(); i++) {
        delete pedidos[i];
    }



    // Liberar la memoria de las instancias de fábricas
    for (size_t i = 0; i < fabricas.size(); i++) {
        delete fabricas[i];
    }

    
    return 0;






}



