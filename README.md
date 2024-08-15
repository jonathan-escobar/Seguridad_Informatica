# KeyLogger con Captura de Pantalla

Este proyecto es un keylogger que también toma capturas de pantalla periódicas. El keylogger registra las teclas presionadas y guarda la información en un archivo de registro. Además, toma capturas de pantalla cada 60 segundos y las guarda en una carpeta específica.

## Requisitos

- **Sistema Operativo:** Linux (Arch Linux recomendado)
- **Bibliotecas y Herramientas:**
  - `gnome-screenshot` para capturar pantallas.
  - `libc6` para las funciones estándar de C.
  - `linux-input.h` para eventos de entrada.
  - `time.h`, `sys/stat.h`, `sys/types.h` para el manejo de tiempo y directorios.

## Instalación

1. **Instalar `gnome-screenshot`:**

   Asegúrate de tener `gnome-screenshot` instalado. Puedes instalarlo con el siguiente comando:

   ```bash
   sudo pacman -S gnome-screenshot

2. Compilar el Código:

Guarda el código fuente en un archivo llamado keylogger.c. Luego, compílalo usando gcc:
gcc -o keylogger keylogger.c

### Ejecutar el Keylogger:

Ejecuta el keylogger con permisos de superusuario para acceder al dispositivo de entrada:
sudo ./keylogger
El programa comenzará a registrar las teclas presionadas y a tomar capturas de pantalla cada 5 segundos. Los archivos de captura de pantalla se guardarán en la carpeta screenshots dentro del directorio actual.

### Archivos Generados:

Archivo de Registro: keylog.txt - Contiene los eventos de teclas presionadas.
Capturas de Pantalla: Guardadas en la carpeta screenshots con nombres basados en la fecha y hora.
Funcionalidad
Registro de Teclas: El programa detecta eventos de teclas presionadas y liberadas usando /dev/input/event4. Los eventos se registran con información sobre la tecla y su estado (presionada o liberada).

Captura de Pantalla: Cada 5 segundos, el programa toma una captura de pantalla utilizando gnome-screenshot y la guarda en la carpeta screenshots.

# Notas
Permisos:  Necesitas permisos de superusuario para acceder al dispositivo de entrada.
Seguridad: Este software está destinado para fines educativos. Asegúrate de cumplir con las leyes y regulaciones locales al usar herramientas de monitoreo de entrada.

### Problemas Conocidos
Capturas de Pantalla Negras: Si las capturas de pantalla resultan negras, verifica que gnome-screenshot esté funcionando correctamente y que tu entorno de escritorio no esté bloqueando las capturas de pantalla.

### Contacto
Para cualquier pregunta o sugerencia, por favor contacta al desarrollador.

Nota: Asegúrate de usar este software de manera ética y legal. El uso no autorizado de keyloggers puede ser ilegal y contra las políticas de muchas organizaciones.


Este README proporciona una visión general de cómo instalar y usar el keylogger, así como detalles sobre los requisitos y la funcionalidad del programa. Asegúrate de ajustar cualquier detalle específico según sea necesario.
