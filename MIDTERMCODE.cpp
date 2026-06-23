#include <iostream>
#include <iomanip>

using namespace std;

class RegistroTemperaturas {
private:
    double* lecturas;
    int capacidad;
    int cantidad;

public:
  
    RegistroTemperaturas(int cap) : capacidad(cap), cantidad(0) {
        lecturas = new double[capacidad];
    }


    ~RegistroTemperaturas() {
        delete[] lecturas;
        lecturas = nullptr;
    }
    void agregar(double temp) {

        if (temp < -50.0 || temp > 60.0) {
            cout << "Temperatura invalida." << endl;
            return;
        }

        if (cantidad >= capacidad) {
            cout << "Registro lleno." << endl;
            return;
        }

        lecturas[cantidad] = temp;
        cantidad++;
    }

    double promedio() const {
        if (cantidad == 0) return 0.0;
        
        double suma = 0.0;
        for (int i = 0; i < cantidad; i++) {
            suma += lecturas[i];
        }
        return suma / cantidad;
    }


    double maxima() const {
        if (cantidad == 0) return 0.0;
        
        double max_val = lecturas[0];
        for (int i = 1; i < cantidad; i++) {
            if (lecturas[i] > max_val) {
                max_val = lecturas[i];
            }
        }
        return max_val;
    }

    double minima() const {
        if (cantidad == 0) return 0.0;
        
        double min_val = lecturas[0];
        for (int i = 1; i < cantidad; i++) {
            if (lecturas[i] < min_val) {
                min_val = lecturas[i];
            }
        }
        return min_val;
    }

    void imprimir() const {
        cout << "Temperaturas: ";
        for (int i = 0; i < cantidad; i++) {
            cout << fixed << setprecision(1) << lecturas[i];
            if (i < cantidad - 1) {
                cout << " ";
            }
        }
        cout << endl;
    }
};

void resumen(const RegistroTemperaturas& reg) {
    reg.imprimir();
    
    cout << fixed << setprecision(2);
    cout << "Promedio : " << reg.promedio() << endl;
    cout << "Maxima   : " << reg.maxima() << endl;
    cout << "Minima   : " << reg.minima() << endl;
}

int main() {
    int n;
    
    if (cin >> n) {

        RegistroTemperaturas registro(n);
        
       
        for (int i = 0; i < n; i++) {
            double temp;
            if (cin >> temp) {
                registro.agregar(temp);
            }
        }
        
        
        resumen(registro);
    }
    

    return 0;
}
