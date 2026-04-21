#include <stdio.h>

#define TOTAL_IPS 10

unsigned char MR[4] = {255, 255, 255, 0};
unsigned char IPs[TOTAL_IPS][4];

int main() {
    FILE *archivo;
    unsigned int a, b, c, d;
    int i = 0;

    archivo = fopen("ips.txt", "r");
    if (archivo == NULL) {
        printf("Error: no se pudo abrir el archivo ips.txt\n");
        return 1;
    }

    while (i < TOTAL_IPS && fscanf(archivo, "%u.%u.%u.%u", &a, &b, &c, &d) == 4) {
        if (a > 255 || b > 255 || c > 255 || d > 255) {
            printf("Error: IP invalida en la linea %d\n", i + 1);
            fclose(archivo);
            return 1;
        }

        IPs[i][0] = (unsigned char)a;
        IPs[i][1] = (unsigned char)b;
        IPs[i][2] = (unsigned char)c;
        IPs[i][3] = (unsigned char)d;
        i++;
    }

    fclose(archivo);

    if (i < TOTAL_IPS) {
        printf("Error: el archivo debe contener exactamente %d direcciones IP\n", TOTAL_IPS);
        return 1;
    }

    for (i = 0; i < TOTAL_IPS; i++) {
        MR[0] = 255;
        MR[1] = 255;
        MR[2] = 255;
        MR[3] = 0;

        printf("IP: %d.%d.%d.%d\n", IPs[i][0], IPs[i][1], IPs[i][2], IPs[i][3]);

        if (IPs[i][0] & 128) {
            if (IPs[i][0] & 64) {
                if (IPs[i][0] & 32) {
                    if (IPs[i][0] & 16) {
                        printf("Clase: E\n\n");
                        continue;
                    } else {
                        printf("Clase: D\n\n");
                        continue;
                    }
                } else {
                    printf("Clase: C\n");
                    MR[3] = 0;
                }
            } else {
                printf("Clase: B\n");
                MR[2] = 0;
                MR[3] = 0;
            }
        } else {
            printf("Clase: A\n");
            MR[1] = 0;
            MR[2] = 0;
            MR[3] = 0;
        }

        printf("Ip de Red = %d.%d.%d.%d\n",
               IPs[i][0] & MR[0],
               IPs[i][1] & MR[1],
               IPs[i][2] & MR[2],
               IPs[i][3] & MR[3]);

        printf("Ip de Broadcast = %d.%d.%d.%d\n",
               IPs[i][0] | (255 - MR[0]),
               IPs[i][1] | (255 - MR[1]),
               IPs[i][2] | (255 - MR[2]),
               IPs[i][3] | (255 - MR[3]));

        if ((IPs[i][0] & MR[0]) == IPs[i][0] &&
            (IPs[i][1] & MR[1]) == IPs[i][1] &&
            (IPs[i][2] & MR[2]) == IPs[i][2] &&
            (IPs[i][3] & MR[3]) == IPs[i][3]) {
            printf("Tipo: Red\n");
        } else if ((IPs[i][0] | (255 - MR[0])) == IPs[i][0] &&
                   (IPs[i][1] | (255 - MR[1])) == IPs[i][1] &&
                   (IPs[i][2] | (255 - MR[2])) == IPs[i][2] &&
                   (IPs[i][3] | (255 - MR[3])) == IPs[i][3]) {
            printf("Tipo: Broadcast\n");
        } else {
            printf("Tipo: Host\n");
        }

        printf("Rango: %d.%d.%d.%d hasta %d.%d.%d.%d\n",
               IPs[i][0] & MR[0],
               IPs[i][1] & MR[1],
               IPs[i][2] & MR[2],
               (IPs[i][3] & MR[3]) + 1,
               IPs[i][0] | (255 - MR[0]),
               IPs[i][1] | (255 - MR[1]),
               IPs[i][2] | (255 - MR[2]),
               (IPs[i][3] | (255 - MR[3])) - 1);

        printf("\n");
    }

    return 0;
}
