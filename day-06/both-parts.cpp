#include <cstdio>
#include <vector>

#define MAX_SPAWN 9

using namespace std;

typedef unsigned long ul;

ul countIndividuals(vector<ul> *population) {
    ul population_size = 0;
    for (ul p : (*population)) {
        population_size += p;
    }
    return population_size;
}

void printPopulation(vector<ul> *population) {
    printf("%6d -> ", countIndividuals(population));
    for (ul p: (*population)) {
        printf("%lu ", p);
    }
    printf("\n");
}

vector<ul> *constructNextPopulation(vector<ul> *current_pop, vector<ul> *next_pop, int remaining_days) {
    if (!remaining_days) {
        return current_pop;
    }
    for (int i = 0; i < MAX_SPAWN; i++) {
        (*next_pop)[i] = (*current_pop)[(i + 1) % MAX_SPAWN];
    }
    (*next_pop)[6] += (*current_pop)[0];
    return constructNextPopulation(next_pop, current_pop, remaining_days - 1);
}

unsigned long calculateNextPopulationSize(vector<ul> population, int remaining_days) {
    vector<ul> v1(population);
    vector<ul> v2(MAX_SPAWN, 0);
    vector<ul> *last_population = constructNextPopulation(&v1, &v2, remaining_days);
    return countIndividuals(last_population);
}

int main() {
    int input;
    vector<ul> population(MAX_SPAWN, 0);
    while (scanf("%d%*c", &input) != EOF) {
        population[input] ++;
    }
    printf("%lu\n", calculateNextPopulationSize(population, 80));
  	printf("%lu\n", calculateNextPopulationSize(population, 256));
}
