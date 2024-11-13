#ifndef COMMUNICATION_H
#define COMMUNICATION_H

#include <Arduino.h>
#include <SoftwareSerial.h>

/**
 * @class Communication
 * @brief Provides methods to manage serial communication with a connected device.
 */
class Communication {
public:
    /**
     * @brief Constructs a Communication instance with predefined RX and TX pins.
     */
    Communication();

    /**
     * @brief Initializes the SoftwareSerial connection with the set baud rate.
     */
    void begin();
    /**
     * @brief Sends a message over SoftwareSerial to the connected device.
     * @param message The message to send.
     */
    void sendMessage(const String &message);
    /**
     * @brief Reads an incoming message from the connected device.
     * @return The received message as a String.
     */
    String readMessage();
     /**
     * @brief Draws a tic-tac-toe board based on the provided board state.
     * @param board 3x3 character array representing the board state.
     */
    void drawBoard(char board[3][3]); /**< SoftwareSerial instance for RX and TX communication. */

private:
    SoftwareSerial mySerial;
};

#endif // COMMUNICATION_H
