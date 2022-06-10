# proyectoTC1030_sven
This is a project for TC1030 by:
Sven Chávez García A01704151

La intencion de este proyecto es simular un restaurante parecido a uno de comida rapida donde el cliente cree una orden y pueda agregar combos a su orden y cada combo venga con una identificacion para cada persona y que se pueda diferenciar si el combo es para niños o para adultos. De tal manera que se trabaje con herencia y polimorfismo en los atributos del combo. La orden puede llamar a funciones para imprimir los combos o el precio final y trabaja con un arreglo de apuntadores. 


En el archivo header Combo, nosotros creamos 3 clases, la primera que será la clase padre "Combo" y que además será abstracta, por lo que no se podrá generar ningún objeto de esta clase particular. La segunda y tercera, hijas de Combo, son Peques y Grandes que representarían el combo niño y adulto respectivamente. La clase Orden en su respectivo header nos permite crear un arreglo de apuntadores de tipo Combo donde podemos almacenar de manera ordenada los diferentes posibles combos que puede haber en una orden. 


# Bitacora de Cambios

Primeramente, se estaba trabajando con un proyecto de streaming de música el cuál fue descartado para la el avnace del 27 de mayo dado que la complejidad del problema no me iba a permitir entregar un trabajo de calidad

Para el avance del 27 de mayo se decide trabajar con el actual proyecto de simulador de un restaurante, donde planteamos el primer avance de los headers, que nos permitirían armar posteriormente el main, sin embargo, esta entrega no se me calificó porque no existía un archivo cpp que pudiera compilar y checar los avances de herencia, métodos de acceso y sobreescritura. 

Para el avance del 3 de junio se implementa el primer main.cpp en donde incluimos polimorfismo en los métodos imprime_combo() y calcula_precio() de la clase Combo en sus respectivas hijas. Además de tener el arreglo de apuntadores de tipo combo donde generaríamos en el header Orden ejemplos de posibles Combos que podrían ejemplificar un poco el funcionamiento de nuestro programa. 

Para el avance del 10 de junio tenemos el avance e implementación de abstracción de la clase Combo, además de modificar un poco el UML y terminar el README ya que estaba incompleto y faltaba descripción del proyecto

# Qué haría tronar el código?
primeramente, la clase Orden tiene como límite 1000 objetos de tipo combo, si nosotros quisiéramos agregar más o intentar obtener un apuntador fuera de índice arrojaría error. 

El objeto de tipo Combo es abstracto, por lo que la creación de un objeto de este tipo tronaría el programa ya que no se puede generar por el virtual puro que existe en el header

Si por alguna razón se destruye el objeto de tipo Orden, automáticamente todos los Combos quedarían en la memoria, pero al faltar un destructor formal podríamos saturar la memoria. 
