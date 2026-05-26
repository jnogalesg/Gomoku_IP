
# Gomoku — Proyecto de Introducción a la Programación (Curso 23/24)

Este repositorio contiene la implementación en C++ del juego Gomoku (cinco en raya) desarrollada para la asignatura de Introducción a la Programación, curso 2023/2024.

## 📝 Resumen
- **Proyecto:** Implementación del juego **Gomoku** con una interfaz gráfica basada en *Allegro 5*.
- **Idioma:** C++
- **Autor:** Jose Nogales Gallardo
- **Curso:** Introducción a la Programación (23/24) EPCC UEx

### 📃 Enunciado 
El enunciado del proyecto está incluido en este repositorio: [IP2324_Proyecto_Gomoku.pdf](IP2324_Proyecto_Gomoku.pdf).

## 📂 Contenido del repositorio

- `GomokuBase/` : Versión base del proyecto con el juego funcional.
- `GomokuAmpliaciones/` : Versión con ampliaciones opcionales (mismas interfaces, código adicional).
- `README.md` : Este fichero.

### Estructura del código principal:

- `Gomoku.cpp` : Módulo principal con `main()` que inicia el juego.
- `TADJuego.*` : Lógica del flujo de juego (iniciar, jugar, terminar, condiciones de victoria).
- `TADTablero.*` : Representación y operaciones del tablero (iniciar, comprobar líneas, color, etc.).
- `TADCasilla.*` : Tipo abstracto para las casillas (vacía / color).
- `entorno.h` y `entorno.cpp` (proporcionados por la asignatura) : Interfaz con la biblioteca gráfica (*Allegro*).

## 🎲 Características principales

- Juego para dos jugadores alternando turnos (negro / blanco).
- Configuración cargada desde `gomoku.cnf` (tamaño de tablero, número de piezas en línea para ganar, jugador que comienza, etc.).
- Control mediante teclado (cursor para moverse y tecla Enter para colocar pieza).
- Detección de victoria en vertical, horizontal y diagonales.

## 🧰 Requisitos

- Compilador C++ compatible (g++ recomendado).
- Biblioteca Allegro 5 (se usan los módulos: `allegro`, `allegro_color`, `allegro_font`, `allegro_image`, `allegro_primitives`, `allegro_ttf`).

## 🛠️ Compilar y ejecutar

Este proyecto se ha desarrollado, compilado y ejecutado principalmente usando **Eclipse para C/C++ (CDT)**. A continuación se indican la opción recomendada:

Usando Eclipse (recomendado):

- Abre Eclipse (con el plugin C/C++ Development Tools instalado).
- Importa el proyecto: `File → Import → Existing Projects into Workspace` y selecciona la raíz del proyecto.
- Construye el proyecto: `Project → Build All`.
- Ejecuta: `Run → Run Configurations... → C/C++ Application` → crea una nueva configuración apuntando al ejecutable generado (por ejemplo `GomokuBase`) o usa el botón verde `Run` en la barra de herramientas.

## ⚙️ Archivo de configuración

- `gomoku.cnf` (en la raíz de cada proyecto) contiene los parámetros por defecto: tamaño del tablero, jugador que inicia, número de piezas en línea necesarias para ganar y número de piezas iniciales.

## 🎮 Controles

- **Movimiento del cursor**: flechas (arriba / abajo / izquierda / derecha).
- **Colocar pieza**: tecla Enter.
- **Salir del juego**: tecla de salida definida en el entorno (ver `entorno.h`).

## 📝 Notas sobre las ampliaciones

La carpeta `GomokuAmpliaciones` contiene código que extiende la versión base con funcionalidades adicionales (por ejemplo, ayudas visuales, borrado de piezas, marcadores de línea). Estas ampliaciones usan las mismas interfaces y sirven como ejemplo de cómo ampliar la base.

## Licencia

El proyecto fue desarrollado como trabajo para la asignatura de Introducción a la Programación en la Universidad de Extremadura. El código es propiedad del autor y se proporciona únicamente con fines educativos. No se permite su uso comercial ni su distribución sin permiso explícito del autor.

