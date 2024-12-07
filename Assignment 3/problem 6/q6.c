#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

struct equipment {
    bool op_status;
    int fuelLvl;
    int activity_schedule;
};

struct sensor{
    int soilNutrients;
    int ph;
    bool pest_activity;
};

struct gps {
    double x;
    double y;
};

struct soil_metrics {
    char soil_texture[10];
    int soil_density;
};

struct weather_forecast {
    int temperature;
    int rainfallLvl;
    char windPatterns[20];
};

struct crop {
    char crop_type[10];
    int growth_stage;
    double crop_yield;
    struct weather_forecast* weather;
};

struct field {
    struct gps coords;
    struct soil_metrics soil;
    int moistureLvl;
    struct crop* crops; 
    int num_crops;      
    struct sensor sensors;
};

struct reg_hubs {
    struct field* fields; 
    int num_fields;       
    int yield_pred;
    int resource_distr;
    char emrgncy_rspns_plan[100];
};

struct weather_forecast* create_weather_forecast(int temp, int rainfall, const char* windPatterns);
struct crop* create_crops(int num_crops);
struct field create_field();
struct reg_hubs create_regional_hub();
void display_regional_hub(struct reg_hubs hub);
void free_regional_hub(struct reg_hubs* hub);


int main() {
    struct reg_hubs hub = create_regional_hub();

    display_regional_hub(hub);

    free_regional_hub(&hub);

    return 0;
}

struct weather_forecast* create_weather_forecast(int temp, int rainfall, const char* windPatterns) {
    struct weather_forecast* wf = malloc(sizeof(struct weather_forecast));
    wf->temperature = temp;
    wf->rainfallLvl = rainfall;
    strcpy(wf->windPatterns, windPatterns);
    return wf;
}

struct crop* create_crops(int num_crops) {
    struct crop* crops = malloc(num_crops * sizeof(struct crop));
    for (int i = 0; i < num_crops; i++) {
        printf("Enter details for crop %d:\n", i + 1);
        printf("Crop type: ");
        scanf("%s", crops[i].crop_type);
        printf("Growth stage: ");
        scanf("%d", &crops[i].growth_stage);
        printf("Crop yield: ");
        scanf("%lf", &crops[i].crop_yield);

        crops[i].weather = create_weather_forecast(25, 50, "Moderate Winds");
    }
    return crops;
}

struct field create_field() {
    struct field f;

    printf("Enter GPS coordinates (x y): ");
    scanf("%lf %lf", &f.coords.x, &f.coords.y);
    printf("Enter soil texture: ");
    scanf("%s", f.soil.soil_texture);
    printf("Enter soil density: ");
    scanf("%d", &f.soil.soil_density);

    printf("Enter moisture level: ");
    scanf("%d", &f.moistureLvl);
    printf("Enter number of crops: ");
    scanf("%d", &f.num_crops);
    f.crops = create_crops(f.num_crops);
    printf("Enter soil nutrients level: ");
    scanf("%d", &f.sensors.soilNutrients);
    printf("Enter soil pH: ");
    scanf("%d", &f.sensors.ph);
    printf("Is there pest activity? (1 for Yes, 0 for No): ");
    scanf("%d", (int*)&f.sensors.pest_activity);

    return f;
}

struct reg_hubs create_regional_hub() {
    struct reg_hubs hub;

    printf("Enter number of fields in the hub: ");
    scanf("%d", &hub.num_fields);
    hub.fields = (struct field*)malloc(hub.num_fields * sizeof(struct field));

    for (int i = 0; i < hub.num_fields; i++) {
        printf("Initializing field %d:\n", i + 1);
        hub.fields[i] = create_field();
    }

    printf("Enter yield prediction: ");
    scanf("%d", &hub.yield_pred);
    printf("Enter resource distribution: ");
    scanf("%d", &hub.resource_distr);
    printf("Enter emergency response plan: ");
    getchar();
    fgets(hub.emrgncy_rspns_plan, sizeof(hub.emrgncy_rspns_plan), stdin);

    return hub;
}

void display_regional_hub(struct reg_hubs hub) {
    printf("\n\t\tRegional Hub Details\t\t\n");
    printf("Number of fields: %d\n", hub.num_fields);
    printf("Yield prediction: %d\n", hub.yield_pred);
    printf("Resource distribution: %d\n", hub.resource_distr);
    printf("Emergency response plan: %s\n", hub.emrgncy_rspns_plan);

    for (int i = 0; i < hub.num_fields; i++) {
        printf("\nField %d:\n", i + 1);
        printf("  GPS Coordinates: (%.2f, %.2f)\n", hub.fields[i].coords.x, hub.fields[i].coords.y);
        printf("  Soil Texture: %s\n", hub.fields[i].soil.soil_texture);
        printf("  Soil Density: %d\n", hub.fields[i].soil.soil_density);
        printf("  Moisture Level: %d\n", hub.fields[i].moistureLvl);
        printf("  Sensor Data - Nutrients: %d, pH: %d, Pest Activity: %s\n",
               hub.fields[i].sensors.soilNutrients,
               hub.fields[i].sensors.ph,
               hub.fields[i].sensors.pest_activity ? "Yes" : "No");

        for (int j = 0; j < hub.fields[i].num_crops; j++) {
            printf("\tCrop %d:\n", j + 1);
            printf("\t\tType: %s, Growth Stage: %d, Yield: %.2f\n",
                   hub.fields[i].crops[j].crop_type,
                   hub.fields[i].crops[j].growth_stage,
                   hub.fields[i].crops[j].crop_yield);
            printf("\t\tWeather - Temp: %d, Rainfall: %d, Winds: %s\n",
                   hub.fields[i].crops[j].weather->temperature,
                   hub.fields[i].crops[j].weather->rainfallLvl,
                   hub.fields[i].crops[j].weather->windPatterns);
        }
    }
}

void free_regional_hub(struct reg_hubs* hub) {
    for (int i = 0; i < hub->num_fields; i++) {
        for (int j = 0; j < hub->fields[i].num_crops; j++) {
            free(hub->fields[i].crops[j].weather); 
        }
        free(hub->fields[i].crops); 
    }
    free(hub->fields); 
}
