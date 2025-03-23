#ifndef ENGINE_HPP
#define ENGINE_HPP

#include <chrono>
#include <iostream>
#include <limits>
#include <string>
#include <string_view>
#include <thread>

#ifdef _WIN32
#include <windows.h>
#define CLEAR_SCREEN "cls"
#else
#include <cstdlib>
#define CLEAR_SCREEN "clear"
#endif

#define GREEN  "\033[32m"
#define BLUE   "\033[34m"
#define RED    "\033[31m"
#define WHITE  "\033[37m"
#define YELLOW "\033[33m"
#define RESET  "\033[0m"

/**
 * @brief: Operaciones que puede realizar el jugador
 */
enum class Operation
{
    SHOW_BOARD,   //< Mostrar el tablero
    SHOW_DETAILS, //< Mostrar detalles de un elemento
    EXIT,         //< Salir del juego
    UNKNOWN       //< Operación desconocida
};

/**
 * @brief: Información del jugador
 */
struct PlayerInfo
{
    std::string_view name;
    std::string_view level;
};

/**
 * @brief: Clase que inicializa el motor del juego
 */
class Engine
{
public:
    /**
     * @brief: Inicializa el motor del juego
     */
    void start(const PlayerInfo& player);

private:
    /**
     * @brief: Inicializa los recursos del tablero
     */
    void initResources();

    /**
     * @brief: Inicializa los elementos del tablero
     */
    void initEntities();

    /**
     * @brief: Consola interactiva
     */
    void interactiveConsole();

    /**
     * @brief: Muestra el banner de bienvenida
     */
    void showBanner();

    /**
     * @brief: Limpia la pantalla antes de mostrar el menú
     */
    void clearScreen();

    PlayerInfo m_player; //< Information del jugador
};

#endif // ENGINE_HPP