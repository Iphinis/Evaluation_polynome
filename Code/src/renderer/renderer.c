#include "renderer.h"


int SCREEN_WIDTH = 800;
int SCREEN_HEIGHT = 800;


double evaluerPolynome(polynome p, double x) {
    double resultat = 0.0;

    for (int i = 0; i <= p.deg; ++i) {
        resultat += p.coeffs[i] * pow(x, i);
    }

    return resultat;
}


void tracerPoints(SDL_Renderer* renderer, int screenWidth, int screenHeight, polynome p, int nombrePoints, double xMin, double xMax, double yMin, double yMax) {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);

    // Dessiner la grille, les axes, etc.

    // Tracer la série de points du polynôme
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255); // Couleur bleue

    double intervalle = (xMax - xMin) / (nombrePoints - 1);

    for (int i = 1; i < nombrePoints; ++i) {
        double x1 = xMin + (i - 1) * intervalle;
        double y1 = evaluerPolynome(p, x1);
        int screenX1 = (i - 1) * screenWidth / (nombrePoints - 1);
        int screenY1 = screenHeight - (y1 - yMin) / (yMax - yMin) * screenHeight;

        double x2 = xMin + i * intervalle;
        double y2 = evaluerPolynome(p, x2);
        int screenX2 = i * screenWidth / (nombrePoints - 1);
        int screenY2 = screenHeight - (y2 - yMin) / (yMax - yMin) * screenHeight;

        SDL_RenderDrawLine(renderer, screenX1, screenY1, screenX2, screenY2);
    }

    // Dessiner la grille
    SDL_SetRenderDrawColor(renderer, 200, 200, 200, 255);
    for (int x = 0; x < screenWidth; x += screenWidth / 20) {
        SDL_RenderDrawLine(renderer, x, 0, x, screenHeight);
    }
    for (int y = 0; y < screenHeight; y += screenHeight / 20) {
        SDL_RenderDrawLine(renderer, 0, y, screenWidth, y);
    }

    // Axes des abscisses et ordonnées
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderDrawLine(renderer, 0, screenHeight / 2, screenWidth, screenHeight / 2); // Axe des abscisses
    SDL_RenderDrawLine(renderer, screenWidth / 2, 0, screenWidth / 2, screenHeight); // Axe des ordonnées

    // Afficher les valeurs des axes
    TTF_Init();
    TTF_Font* font = TTF_OpenFont("src/renderer/arial.ttf", 16); // Vous pouvez ajuster la taille

    if (font == NULL) {
        fprintf(stderr, "Erreur lors de l'ouverture de la police : %s\n", TTF_GetError());
        TTF_Quit();
        return;
    }

    char buffer[20];

    // Afficher les valeurs sur l'axe des abscisses
    for (int x = screenWidth / 20; x < screenWidth; x += screenWidth / 20) {
        double value = xMin + (double)x / screenWidth * (xMax - xMin);
        snprintf(buffer, sizeof(buffer), "%.2f", value);
        SDL_Color textColor = {0, 0, 0, 255};
        SDL_Surface* textSurface = TTF_RenderText_Solid(font, buffer, textColor);
        SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);

        int textWidth, textHeight;
        SDL_QueryTexture(textTexture, NULL, NULL, &textWidth, &textHeight);

        SDL_Rect destRect = {x - textWidth / 2, screenHeight / 2 + 5, textWidth, textHeight};
        SDL_RenderCopy(renderer, textTexture, NULL, &destRect);

        SDL_FreeSurface(textSurface);
        SDL_DestroyTexture(textTexture);
    }

    // Afficher les valeurs sur l'axe des ordonnées
    for (int y = screenHeight / 20; y < screenHeight; y += screenHeight / 20) {
        double value = yMax - (double)y / screenHeight * (yMax - yMin);
        snprintf(buffer, sizeof(buffer), "%.2f", value);
        SDL_Color textColor = {0, 0, 0, 255};
        SDL_Surface* textSurface = TTF_RenderText_Solid(font, buffer, textColor);
        SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);

        int textWidth, textHeight;
        SDL_QueryTexture(textTexture, NULL, NULL, &textWidth, &textHeight);

        SDL_Rect destRect = {screenWidth / 2 + 5, y - textHeight / 2, textWidth, textHeight};
        SDL_RenderCopy(renderer, textTexture, NULL, &destRect);

        SDL_FreeSurface(textSurface);
        SDL_DestroyTexture(textTexture);
    }

    TTF_CloseFont(font);
    TTF_Quit();    

    SDL_RenderPresent(renderer);
}


int tracerPolynome(polynome p) {
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Event event;

    // Création de la fenêtre SDL
    SDL_Window* window = SDL_CreateWindow("Polynôme Points", SCREEN_WIDTH, SCREEN_HEIGHT, 800, 600, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    if (window == NULL) {
        printf("Erreur lors de la création de la fenêtre SDL : %s\n", SDL_GetError());
        SDL_Quit();
        return EXIT_FAILURE;
    }

    // Création du rendu SDL
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL) {
        printf("Erreur lors de la création du rendu SDL : %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return EXIT_FAILURE;
    }

    // Paramètres
    int nombrePoints = 100;
    double xMin = -5.0;
    double xMax = 5.0;
    double yMin = -5.0;
    double yMax = 5.0;

    // Appel de la fonction tracerPoints
    tracerPoints(renderer, SCREEN_WIDTH, SCREEN_HEIGHT, p, nombrePoints, xMin, xMax, yMin, yMax);

    // Boucle d'événements
    int quit = 0;
    while (!quit) {
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    quit = 1;
                    break;
                case SDL_WINDOWEVENT:
                    if (event.window.event == SDL_WINDOWEVENT_SIZE_CHANGED) {
                        SCREEN_WIDTH = event.window.data1;
                        SCREEN_HEIGHT = event.window.data2;
                    }
                    break;
                case SDL_MOUSEWHEEL:
                    if (event.wheel.y > 0) {
                        // Zoom in
                        xMin *= 0.9;
                        xMax *= 0.9;
                        yMin *= 0.9;
                        yMax *= 0.9;
                    } else if (event.wheel.y < 0) {
                        // Zoom out
                        xMin /= 0.9;
                        xMax /= 0.9;
                        yMin /= 0.9;
                        yMax /= 0.9;
                    }
                    break;
            }
            tracerPoints(renderer, SCREEN_WIDTH, SCREEN_HEIGHT, p, nombrePoints, xMin, xMax, yMin, yMax);
        }
        SDL_Delay(10);  // Ajoute une pause pour éviter de surcharger le processeur
    }

    // Libération des ressources
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return EXIT_SUCCESS;
}