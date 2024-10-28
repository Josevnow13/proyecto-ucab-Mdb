#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std; 

//ESTRUCTURAS DE DATOS

struct episodes {
    string name;
    int year, time, num_episodes;
    episodes* next;
};

struct seasons {
    string name;
    int year;
    seasons* next;
    episodes* episode;
};

void insert_at_theend_season(seasons*& head, const string name, int ano, episodes* episodes) {
    seasons* nueva_temp = new seasons;
    nueva_temp->name = name;
    nueva_temp->episode = episodes;
    nueva_temp->year = ano;
    nueva_temp->next = NULL;

    if (head == NULL) {
        head = nueva_temp;
    } else {
        seasons* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = nueva_temp;
    }
}

void insert_episode(episodes*& head, const string& name, const int& year, const int& time, const int& num) {
    episodes* new_episode = new episodes;
    new_episode->name = name;
    new_episode->year = year;
    new_episode->time = time;
    new_episode->num_episodes = num;
    new_episode->next = NULL;

    if (head == NULL) {
        head = new_episode;
    } else {
        episodes* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = new_episode;
    }
}

episodes* create_episode_list(const string& name, const int& season_year) {
    episodes* head = NULL;
    insert_episode(head, "Episodio 1", season_year, 45, 1);
    insert_episode(head, "Episodio 2", season_year, 50, 2);
    // ... agregar más episodios según la temporada
    return head;
}

void display_seasons(seasons* head) {
    if (head == NULL) {
        cout << "No hay temporadas disponibles." << endl;
        return;
    }
    while (head != NULL) {
        cout << "Temporada: " << head->name << " (" << head->year << ")" << endl;
        episodes* current_episode = head->episode;
        while (current_episode != NULL) {
            cout << "  Episodio: " << current_episode->name << " (" << current_episode->year << ")" << endl;
            cout << "    Duración: " << current_episode->time << " minutos" << endl;
            cout << "    Número de episodios: " << current_episode->num_episodes << endl;
            current_episode = current_episode->next;
        }
        head = head->next;
    }
}

int main() {
    seasons* head = NULL;

    // Crear la primera temporada y sus episodios
    episodes* first_season_episodes = create_episode_list("Temporada 1", 2023);
    insert_at_theend_season(head, "Temporada 1", 2023, first_season_episodes);

    // Crear la segunda temporada y sus episodios
    episodes* second_season_episodes = create_episode_list("Temporada 2", 2024);
    insert_at_theend_season(head, "Temporada 2", 2024, second_season_episodes);

    // Mostrar las temporadas y episodios
    display_seasons(head);

    return 0;
}