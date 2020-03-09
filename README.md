# PRÁCTICA 1 - PROCESOS #

## 1. Objetivos ##
1. Familiarizarse con las diferentes estructuras y funciones relacionadas con el manejo de procesos en linux.
2. Codificar programas que hagan uso del API de procesos.

## 2. Actividades en el laboratorio ##

Realizar los siguientes ejercicios:

1. Escriba un programa que llame un ```fork()```. Antes del llamado del ```fork()```, declare una variable de acceso (por ejemplo, ```x```) y asígnele un valor (por ejemplo, ```100```). Responda las siguientes preguntas:
  * ¿Cuál es el valor de la variable en el proceso hijo?
    
    R: El valor de la varible en el proceso hijo es el mismo, ya que el hijo tiene la misma imagen/contexto del proceso padre.
  * ¿Qué sucede con la variable cuando el proceso hijo y el padre cambian el valor de ```x```?
  
    R: El valor en ambos contextos (padre e hijo) es se ve modificado de manera independiente tanto en el padre como en el hijo.
2. Escriba un programa que abra un archivo (con la llamada ```open()```) y entonces llame a ```fork()```. **Nota**: El siguiente [enlace](https://www.geeksforgeeks.org/input-output-system-calls-c-create-open-close-read-write/) puede ser de utilidad para entender la llamada ```open()```.
  * ¿Pueden el padre y el hijo acceder al file descriptor retornado por ```open()```?
  
    R: Sí, tanto el padre como el hijo pueden acceder al file descriptor
  
  * ¿Qué pasa si ellos empiezan a escribir el archivo de manera concurrente, es decir, a la misma vez?
  
    R: Ambos procesos heredan el descriptor de archivo y por ende pueden escribir el archivo al mismo tiempo.
3. Escriba un programa usando ```fork()```. El proceso hijo imprimirá ```"Hello"```; el proceso padre imprimirá ```"goodbye"```. Usted deberá asegurar que el proceso hijo imprima en primer lugar; ¿usted podría hacer esto sin llamar ```wait()``` en el padre?

   R: Sí es posible, lo podemos hacer realizando otra llamada sistema en el proceso padre, en este caso haciendo uso de la función sleep(1), el hijo se ejecutará primero que el padre.
4. Escriba un programa que llame ```fork()``` y entonces llame alguna forma de ```exec()``` para correr el programa ```/bin/ls```. Intente probar todas las variaciones de la familia de funciones ```exec()``` incluyendo (en linux) ```execl()```, ```execle()```, ```execlp()```, ```execv()```, ```execvp()``` y ```execvpe()```. ¿Por qué piensa usted que existen tantas variaciones para la misma llamada básica?

  R: La diversidad en las llamadas a la misma función básica atienden a necesidades especiales tanto en la manera de pasar los argumentos al fichero que se va a ejecutar, como en la manera en que el sistema encuentra el nombre del archivo a ejecuta. Para las funciones execl, execle, execlp los argumentos son pasados individualmente a la función del fichero. Para las funciones execv, execve, execvp los argumentos son pasados como un array de apuntadores, para las funciones execle, execve, se pasa además de los argumentos un array de apuntadores a las variables de entorno, mientras que en las funciones execvp y execlp utiliza el valor de la variable de entorno PATH para encontrar el nombre del archivo del path pasado como argumento.

5. Escriba ahora un programa que use ```wait()``` para esperar que el proceso hijo finalice su ejecución. ¿Cuál es el valor de retorno de la función ```wait()```?, ¿Qué pasa si usted usa la función ```wait``` en el hijo?

  R: Retorna el PID del proceso hijo que se ejecutó, o -1 si no hubo hijos para esperar o si no se crearon procesos hijos. Cuando se usa el wait en el hijo el wait() retorna -1 según lo mencionado anteriormente, ya que el proceso hijo no ha creado más hijos.
  
6. Haga un programa, como el del ejercicio anterior, con una breve modificación, la cual consiste en usar ```waitpid()``` en lugar de ```wait()```. ¿Cuándo podría ser ```waitpid()``` útil?

  R: Cuando se desea esperar por un proceso en específico del cual se tiene el PID, o bien para esperar hasta que cualquiera de los hijos termine, en general waitpid() nos da más felixibilidad a la hora de esperar por la ejecución de cualquier otro proceso que estemos ejecutando.
  
7. Escriba un programa que cree un proceso hijo y entonces en el proceso hijo cierre la salida estandar (```STDOUT FILENO```). ¿Qué pasa si el hijo llama ```printf()``` para imprimir alguna salida después de cerrar el descriptor?

  R: El hijo es incapaz de producir salidas y cualquier llamado a printf() no surte efecto en el hijo.
  
8. Escriba un programa que cree dos hijos y conecte la salida estándar de un hijo a la entrada estándar del otro usando la llamada a sistema ```pipe()```

  R: 

## 3. Entregable ##

Los entregables para esta practica incluiran:
1. Codigo de los ejercicos propuestos.
2. Solución a las preguntas planteadas. apoyar la explicación con graficas donde lo vea necesario.
