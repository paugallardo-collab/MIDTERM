Un estudiante quiere que su clase Calculadora tenga dos
versiones de calcularArea():
  - Una que recibe el lado de un cuadrado
  - Una que recibe la base y la altura de un rectángulo

Escribe este código y lo sube convencido de que funciona:

  class Calculadora {
  public:
      double calcularArea(double lado) {
          return lado * lado;
      }
      double calcularArea(double lado) {
          return lado * 2;
      }
  };

El compilador rechaza el código. El estudiante no entiende
por qué — dice: "las dos funciones hacen cosas distintas,
¿por qué el compilador no las distingue?"

  a) (3 pts) Explica exactamente por qué el compilador
     no puede distinguir estas dos funciones.
     No basta decir "tienen el mismo nombre" — explica
     el mecanismo técnico que usa el compilador para
     distinguir funciones sobrecargadas y por qué ese
     mecanismo falla aquí.
     El problema no es realmente el que "tengan el mismo nombre", sino que tienen los mismos atributos por lo que el compilador no sabe a que function llamar.

  b) (3 pts) El estudiante quería implementar lo que
     describió: área de cuadrado y área de rectángulo.
     Escribe la versión CORRECTA de la clase que logra
     exactamente eso usando sobrecarga válida.

     class Calculadora {
     public:
double calcularArea(double lado, double altura) {
          return lado * altura;
      }
      double calcularArea(double lado) {
          return lado * 2;
      }
  };
c) (2 pts) Hay un segundo error lógico en la segunda
     función, independientemente del problema de sobrecarga.
     Incluso si el compilador la aceptara, no calcula el
     área de un rectángulo correctamente.
     ¿Cuál es ese error? ¿Qué debería retornar?
     ________________________________________________________
     ________________________________________________________

  d) (2 pts) El tipo de retorno de las dos funciones es
     double en ambos casos. ¿Podría el compilador usar el
     tipo de retorno para distinguirlas si fuera diferente
     — por ejemplo una retorna double y la otra int?
     Justifica.
     Claro, ahi seria hasta mas claro para el compilador porque 


     
