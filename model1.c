#include <stdio.h>
#include <math.h>
#include "lcgrand.c"

#define Q_LIMIT 100
#define BUSY
#define IDLEE

int next_event_type, num_custs_delayed, num_delays_required, num_events, num_in_q, server_status;
float area_num_in_q, area_server_status, mean_interarrival, mean_service, sim_time, time_arrival[Q_LIMIT + 1], time_last_event, time_next_event[3],total_of_delays;
FILE *infile, *outfile;

void initialize(void);
void timing(void);
void arrive(void);
void depart(void);
void report(void);
void update_time_avg_stats(void);
float expon(float mean);

main() {
    infile = fopen("mm1.in", "r");
    outfile = fopen("mm1.out", "w");

    num_events= 2;
    fscanf(infile, "%f %f %d", &mean_interarrival, &mean_service, &num_delays_required);
    fprintf(outfile, "single-server queueing system\n\n");
    fprintf(outfile, "Mean interarrival time%11.3f minutes \n\n", mean_interarrival);
    fprintf(outfile, "Mean_service time%16.3f minutes \n\n", mean_service);
    fprint(outfile, "Number of customers%14d \n\n", num_delays_required);
    
    initialize();

    while (num_custs_delayed < num_delays_required) {
        timing();

        update_time_avg_stats();

        switch (next_event_type) {
            case 1:
                arrive();
                break;
            case 2:
                depart();
                break;
                }
                }
    report();

    fclose(infile);
    fclose(outfile);

    return 0;
}
