#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/socket.h>
#include <bluetooth/bluetooth.h>
#include <bluetooth/hci.h>
#include <bluetooth/hci_lib.h>

// uses hci to scan for devices to pair
int ble_pair() {
    int device_id = hci_get_route(NULL);
    int sock = hci_open_dev(device_id);

    if (device_id < 0 || sock < 0) {
        perror("error opening ble hci device\n");
        exit(1);
    }

    uint8_t scan_type = 0x01;
    uint16_t interval = htobs(0x0010);
    uint16_t window = htobs(0x0010);
    uint8_t own_type = 0x00;
    uint8_t filter_policy = 0x00;

    if (hci_le_set_scan_parameters(sock, scan_type, interval, window, own_type, filter_policy, 1000) < 0) {
        perror("failed to set scan parameters"\n);
        close(sock);
        return 1;
    }
    if (hci_le_set_scan_enable(sock, 0x01, 0x00, 1000) < 0) {
        perror("failed to enable scanning");
        close(sock);
        return 1;
    }

    uint8_t buf[HCI_MAX_EVENT_SIZE];
    printf("scanning for devices to pair...");

    while (1) {
        ssize_t len = read(sock, buf, sizeof(buf));
        if (len < 0) {
            fprintf(stderr, )
        }
    }
}
