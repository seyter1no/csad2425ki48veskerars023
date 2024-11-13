#ifndef COMMUNICATION_H
#define COMMUNICATION_H

#include <string>
#include <windows.h> // Для використання Windows API
/**
 * Global variable representing the communication port name.
 */
extern std::string port;
/**
 * Global variable representing the baud rate for serial communication.
 */
extern int baudRate;
/**
 * @class SerialCommunication
 * @brief Manages serial communication with a device.
 */
class SerialCommunication {
private:
    HANDLE hSerial = INVALID_HANDLE_VALUE; /**< Handle to the serial port */

public:
    /**
     * @brief Connects to the serial port with the specified port name and baud rate.
     * @param port The name of the port to connect to (e.g., "COM3").
     * @param baudRate The baud rate for the connection (e.g., 9600).
     * @return True if the connection was successful, otherwise false.
     */
    bool connect(const std::string& port, int baudRate);
    /**
     * @brief Sends a message over the serial connection.
     * @param message The message to send to the connected device.
     * @return The response from the device as a string.
     */
    std::string sendMessage(const std::string& message);
    /**
     * @brief Disconnects from the serial port, if connected.
     */
    void disconnect();
    /**
     * @brief Renders a graphical representation of the board based on the provided state.
     * @param boardState The string representing the current board state.
     */
    void drawBoard(const std::string& boardState);
};
/**
 * @brief Loads configuration values from an INI file.
 * @param filename The path to the INI configuration file.
 */
void loadConfig(const std::string& filename);

#endif // COMMUNICATION_H