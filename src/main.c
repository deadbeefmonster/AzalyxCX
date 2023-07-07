#define G_LOG_USE_STRUCTURED 1

#include <glib.h>
#include <event2/event.h>
#include <event2/bufferevent.h>
#include <stdlib.h>

#include "cli_arguments.h"
#include "configuration.h"
#include "crypto_aes.h"
#include "service.h"

#define BLITZKRIEG_VERSION "v0.1.0"
#define BLITZKRIEG_DEVELOPER "Christoff Humphries <christoff@deadbeef.monster>"
#define BLITZKRIEG_COPYRIGHT "(c) 2023"


int
main(int argc, char **argv) {
    printf("\033[38;5;25m.\033[38;5;25m.\033[38;5;25m.\033[38;5;25m.\033[38;5;25m.\033[38;5;25m.\033[38;5;25m.\033[38;5;25m.\033[38;5;25m.\033[38;5;25m.\033[38;5;25m.\033[38;5;25m.\033[38;5;25m.\033[38;5;25m.\033[38;5;25m.\033[38;5;25m.\033[38;5;25m.\033[38;5;25m.\033[38;5;25m.\033[38;5;25m.\033[38;5;25m.\033[38;5;25m.\033[38;5;25m.\033[38;5;25m.\033[38;5;25m.\033[38;5;25m.\033[38;5;25m.\033[38;5;25m.\033[38;5;25m.\033[38;5;25m.\033[38;5;25m.\033[38;5;25m.\033[38;5;25m.\033[38;5;25m.\033[38;5;25m.\033[38;5;25m.\033[38;5;25m.\033[38;5;25m.\033[38;5;25m.\033[38;5;25m.\033[38;5;25m.\033[38;5;25m.\033[38;5;25m.\033[38;5;25m.\033[38;5;25m.\033[38;5;25m.\033[38;5;25m.\033[38;5;25m.\033[38;5;25m.\033[38;5;25m.\033[38;5;25m.\033[38;5;25m.\033[38;5;25m.\033[38;5;25m.\033[38;5;25m.\033[38;5;25m.\033[38;5;25m.\033[38;5;25m.\033[38;5;25m.\033[38;5;25m.\033[38;5;25m.\033[38;5;25m.\033[38;5;25m.\033[38;5;25m.\033[38;5;25m.\033[38;5;25m.\033[38;5;25m.\033[38;5;25m.\033[38;5;25m.\033[38;5;25m.\033[38;5;25m.\033[38;5;25m.\033[38;5;25m.\033[38;5;25m.\033[38;5;25m.\033[38;5;25m.\033[38;5;25m.\033[38;5;25m.\n");
    printf("\033[38;5;24m.\033[38;5;161me\033[38;5;161me\033[38;5;161me\033[38;5;161me\033[38;5;161me\033[38;5;161me\033[38;5;161me\033[38;5;24m.\033[38;5;24m.\033[38;5;161me\033[38;5;161me\033[38;5;161me\033[38;5;24m.\033[38;5;24m.\033[38;5;24m.\033[38;5;24m.\033[38;5;161me\033[38;5;161me\033[38;5;161me\033[38;5;24m.\033[38;5;161me\033[38;5;161me\033[38;5;161me\033[38;5;161me\033[38;5;161me\033[38;5;161me\033[38;5;161me\033[38;5;161me\033[38;5;161me\033[38;5;24m.\033[38;5;161me\033[38;5;161me\033[38;5;161me\033[38;5;161me\033[38;5;161me\033[38;5;161me\033[38;5;161me\033[38;5;161me\033[38;5;24m.\033[38;5;161me\033[38;5;161me\033[38;5;161me\033[38;5;24m.\033[38;5;24m.\033[38;5;161me\033[38;5;161me\033[38;5;161me\033[38;5;24m.\033[38;5;161me\033[38;5;161me\033[38;5;161me\033[38;5;161me\033[38;5;161me\033[38;5;161me\033[38;5;161me\033[38;5;24m.\033[38;5;24m.\033[38;5;161me\033[38;5;161me\033[38;5;161me\033[38;5;24m.\033[38;5;161me\033[38;5;161me\033[38;5;161me\033[38;5;161me\033[38;5;161me\033[38;5;161me\033[38;5;24m.\033[38;5;24m.\033[38;5;161me\033[38;5;161me\033[38;5;161me\033[38;5;161me\033[38;5;161me\033[38;5;161me\033[38;5;24m.\033[38;5;24m.\n");
    printf("\033[38;5;23m:\033[38;5;162m@\033[38;5;162m@\033[38;5;162m@\033[38;5;162m@\033[38;5;162m@\033[38;5;162m@\033[38;5;162m@\033[38;5;162m@\033[38;5;23m:\033[38;5;162m@\033[38;5;162m@\033[38;5;162m@\033[38;5;23m:\033[38;5;23m:\033[38;5;23m:\033[38;5;23m:\033[38;5;162m@\033[38;5;162m@\033[38;5;162m@\033[38;5;23m:\033[38;5;162m@\033[38;5;162m@\033[38;5;162m@\033[38;5;162m@\033[38;5;162m@\033[38;5;162m@\033[38;5;162m@\033[38;5;162m@\033[38;5;162m@\033[38;5;23m:\033[38;5;162m@\033[38;5;162m@\033[38;5;162m@\033[38;5;162m@\033[38;5;162m@\033[38;5;162m@\033[38;5;162m@\033[38;5;162m@\033[38;5;23m:\033[38;5;162m@\033[38;5;162m@\033[38;5;162m@\033[38;5;23m:\033[38;5;23m:\033[38;5;162m@\033[38;5;162m@\033[38;5;162m@\033[38;5;23m:\033[38;5;162m@\033[38;5;162m@\033[38;5;162m@\033[38;5;162m@\033[38;5;162m@\033[38;5;162m@\033[38;5;162m@\033[38;5;162m@\033[38;5;23m:\033[38;5;162m@\033[38;5;162m@\033[38;5;162m@\033[38;5;23m:\033[38;5;162m@\033[38;5;162m@\033[38;5;162m@\033[38;5;162m@\033[38;5;162m@\033[38;5;162m@\033[38;5;23m:\033[38;5;162m@\033[38;5;162m@\033[38;5;162m@\033[38;5;162m@\033[38;5;162m@\033[38;5;162m@\033[38;5;162m@\033[38;5;162m@\033[38;5;23m:\n");
    printf("\033[38;5;22m-\033[38;5;163m%%\033[38;5;163m%%\033[38;5;163m%%\033[38;5;22m-\033[38;5;22m-\033[38;5;163m%%\033[38;5;163m%%\033[38;5;163m%%\033[38;5;22m-\033[38;5;163m%%\033[38;5;163m%%\033[38;5;163m%%\033[38;5;22m-\033[38;5;22m-\033[38;5;22m-\033[38;5;22m-\033[38;5;163m%%\033[38;5;163m%%\033[38;5;163m%%\033[38;5;22m-\033[38;5;22m-\033[38;5;22m-\033[38;5;22m-\033[38;5;163m%%\033[38;5;163m%%\033[38;5;163m%%\033[38;5;22m-\033[38;5;22m-\033[38;5;22m-\033[38;5;22m-\033[38;5;22m-\033[38;5;22m-\033[38;5;22m-\033[38;5;22m-\033[38;5;163m%%\033[38;5;163m%%\033[38;5;163m%%\033[38;5;22m-\033[38;5;22m-\033[38;5;163m%%\033[38;5;163m%%\033[38;5;163m%%\033[38;5;22m-\033[38;5;163m%%\033[38;5;163m%%\033[38;5;163m%%\033[38;5;22m-\033[38;5;22m-\033[38;5;163m%%\033[38;5;163m%%\033[38;5;163m%%\033[38;5;22m-\033[38;5;22m-\033[38;5;163m%%\033[38;5;163m%%\033[38;5;163m%%\033[38;5;22m-\033[38;5;163m%%\033[38;5;163m%%\033[38;5;163m%%\033[38;5;22m-\033[38;5;163m%%\033[38;5;163m%%\033[38;5;163m%%\033[38;5;22m-\033[38;5;22m-\033[38;5;22m-\033[38;5;22m-\033[38;5;163m%%\033[38;5;163m%%\033[38;5;163m%%\033[38;5;22m-\033[38;5;22m-\033[38;5;22m-\033[38;5;22m-\033[38;5;22m-\033[38;5;22m-\n");
    printf("\033[38;5;21m+\033[38;5;164m&\033[38;5;164m&\033[38;5;164m&\033[38;5;164m&\033[38;5;164m&\033[38;5;164m&\033[38;5;164m&\033[38;5;21m+\033[38;5;21m+\033[38;5;164m&\033[38;5;164m&\033[38;5;164m&\033[38;5;21m+\033[38;5;21m+\033[38;5;21m+\033[38;5;21m+\033[38;5;164m&\033[38;5;164m&\033[38;5;164m&\033[38;5;21m+\033[38;5;21m+\033[38;5;21m+\033[38;5;21m+\033[38;5;164m&\033[38;5;164m&\033[38;5;164m&\033[38;5;21m+\033[38;5;21m+\033[38;5;21m+\033[38;5;21m+\033[38;5;21m+\033[38;5;21m+\033[38;5;21m+\033[38;5;164m&\033[38;5;164m&\033[38;5;164m&\033[38;5;21m+\033[38;5;21m+\033[38;5;21m+\033[38;5;164m&\033[38;5;164m&\033[38;5;164m&\033[38;5;164m&\033[38;5;164m&\033[38;5;164m&\033[38;5;21m+\033[38;5;21m+\033[38;5;21m+\033[38;5;164m&\033[38;5;164m&\033[38;5;164m&\033[38;5;164m&\033[38;5;164m&\033[38;5;164m&\033[38;5;164m&\033[38;5;21m+\033[38;5;21m+\033[38;5;164m&\033[38;5;164m&\033[38;5;164m&\033[38;5;21m+\033[38;5;164m&\033[38;5;164m&\033[38;5;164m&\033[38;5;164m&\033[38;5;164m&\033[38;5;21m+\033[38;5;21m+\033[38;5;164m&\033[38;5;164m&\033[38;5;164m&\033[38;5;21m+\033[38;5;21m+\033[38;5;21m+\033[38;5;21m+\033[38;5;21m+\033[38;5;21m+\n");
    printf("\033[38;5;20m*\033[38;5;165m|\033[38;5;165m|\033[38;5;165m|\033[38;5;165m|\033[38;5;165m|\033[38;5;165m|\033[38;5;165m|\033[38;5;165m|\033[38;5;20m*\033[38;5;165m|\033[38;5;165m|\033[38;5;165m|\033[38;5;20m*\033[38;5;20m*\033[38;5;20m*\033[38;5;20m*\033[38;5;165m|\033[38;5;165m|\033[38;5;165m|\033[38;5;20m*\033[38;5;20m*\033[38;5;20m*\033[38;5;20m*\033[38;5;165m|\033[38;5;165m|\033[38;5;165m|\033[38;5;20m*\033[38;5;20m*\033[38;5;20m*\033[38;5;20m*\033[38;5;20m*\033[38;5;20m*\033[38;5;165m|\033[38;5;165m|\033[38;5;165m|\033[38;5;20m*\033[38;5;20m*\033[38;5;20m*\033[38;5;20m*\033[38;5;165m|\033[38;5;165m|\033[38;5;165m|\033[38;5;165m|\033[38;5;165m|\033[38;5;165m|\033[38;5;20m*\033[38;5;20m*\033[38;5;20m*\033[38;5;165m|\033[38;5;165m|\033[38;5;165m|\033[38;5;165m|\033[38;5;165m|\033[38;5;165m|\033[38;5;20m*\033[38;5;20m*\033[38;5;20m*\033[38;5;165m|\033[38;5;165m|\033[38;5;165m|\033[38;5;20m*\033[38;5;165m|\033[38;5;165m|\033[38;5;165m|\033[38;5;165m|\033[38;5;165m|\033[38;5;20m*\033[38;5;20m*\033[38;5;165m|\033[38;5;165m|\033[38;5;165m|\033[38;5;20m*\033[38;5;165m|\033[38;5;165m|\033[38;5;165m|\033[38;5;165m|\033[38;5;20m*\n");
    printf("\033[38;5;19m=\033[38;5;166m!\033[38;5;166m!\033[38;5;166m!\033[38;5;19m=\033[38;5;19m=\033[38;5;166m!\033[38;5;166m!\033[38;5;166m!\033[38;5;19m=\033[38;5;166m!\033[38;5;166m!\033[38;5;166m!\033[38;5;19m=\033[38;5;19m=\033[38;5;19m=\033[38;5;19m=\033[38;5;166m!\033[38;5;166m!\033[38;5;166m!\033[38;5;19m=\033[38;5;19m=\033[38;5;19m=\033[38;5;19m=\033[38;5;166m!\033[38;5;166m!\033[38;5;166m!\033[38;5;19m=\033[38;5;19m=\033[38;5;19m=\033[38;5;19m=\033[38;5;19m=\033[38;5;166m!\033[38;5;166m!\033[38;5;166m!\033[38;5;19m=\033[38;5;19m=\033[38;5;19m=\033[38;5;19m=\033[38;5;19m=\033[38;5;166m!\033[38;5;166m!\033[38;5;166m!\033[38;5;19m=\033[38;5;166m!\033[38;5;166m!\033[38;5;166m!\033[38;5;19m=\033[38;5;19m=\033[38;5;166m!\033[38;5;166m!\033[38;5;166m!\033[38;5;19m=\033[38;5;166m!\033[38;5;166m!\033[38;5;166m!\033[38;5;19m=\033[38;5;19m=\033[38;5;166m!\033[38;5;166m!\033[38;5;166m!\033[38;5;19m=\033[38;5;166m!\033[38;5;166m!\033[38;5;166m!\033[38;5;19m=\033[38;5;19m=\033[38;5;19m=\033[38;5;19m=\033[38;5;166m!\033[38;5;166m!\033[38;5;166m!\033[38;5;19m=\033[38;5;19m=\033[38;5;166m!\033[38;5;166m!\033[38;5;166m!\033[38;5;19m=\n");
    printf("\033[38;5;18m#\033[38;5;167m:\033[38;5;167m:\033[38;5;167m:\033[38;5;167m:\033[38;5;167m:\033[38;5;167m:\033[38;5;167m:\033[38;5;167m:\033[38;5;18m#\033[38;5;167m:\033[38;5;167m:\033[38;5;167m:\033[38;5;167m:\033[38;5;167m:\033[38;5;167m:\033[38;5;18m#\033[38;5;167m:\033[38;5;167m:\033[38;5;167m:\033[38;5;18m#\033[38;5;18m#\033[38;5;18m#\033[38;5;18m#\033[38;5;167m:\033[38;5;167m:\033[38;5;167m:\033[38;5;18m#\033[38;5;18m#\033[38;5;18m#\033[38;5;18m#\033[38;5;167m:\033[38;5;167m:\033[38;5;167m:\033[38;5;167m:\033[38;5;167m:\033[38;5;167m:\033[38;5;167m:\033[38;5;167m:\033[38;5;18m#\033[38;5;167m:\033[38;5;167m:\033[38;5;167m:\033[38;5;18m#\033[38;5;18m#\033[38;5;167m:\033[38;5;167m:\033[38;5;167m:\033[38;5;18m#\033[38;5;167m:\033[38;5;167m:\033[38;5;167m:\033[38;5;18m#\033[38;5;18m#\033[38;5;167m:\033[38;5;167m:\033[38;5;167m:\033[38;5;18m#\033[38;5;167m:\033[38;5;167m:\033[38;5;167m:\033[38;5;18m#\033[38;5;167m:\033[38;5;167m:\033[38;5;167m:\033[38;5;167m:\033[38;5;167m:\033[38;5;167m:\033[38;5;18m#\033[38;5;167m:\033[38;5;167m:\033[38;5;167m:\033[38;5;167m:\033[38;5;167m:\033[38;5;167m:\033[38;5;167m:\033[38;5;167m:\033[38;5;18m#\n");
    printf("\033[38;5;17m@\033[38;5;168m:\033[38;5;168m:\033[38;5;168m:\033[38;5;168m:\033[38;5;168m:\033[38;5;168m:\033[38;5;168m:\033[38;5;17m@\033[38;5;17m@\033[38;5;168m:\033[38;5;168m:\033[38;5;168m:\033[38;5;168m:\033[38;5;168m:\033[38;5;168m:\033[38;5;17m@\033[38;5;168m:\033[38;5;168m:\033[38;5;168m:\033[38;5;17m@\033[38;5;17m@\033[38;5;17m@\033[38;5;17m@\033[38;5;168m:\033[38;5;168m:\033[38;5;168m:\033[38;5;17m@\033[38;5;17m@\033[38;5;17m@\033[38;5;17m@\033[38;5;168m:\033[38;5;168m:\033[38;5;168m:\033[38;5;168m:\033[38;5;168m:\033[38;5;168m:\033[38;5;168m:\033[38;5;168m:\033[38;5;17m@\033[38;5;168m:\033[38;5;168m:\033[38;5;168m:\033[38;5;17m@\033[38;5;17m@\033[38;5;168m:\033[38;5;168m:\033[38;5;168m:\033[38;5;17m@\033[38;5;168m:\033[38;5;168m:\033[38;5;168m:\033[38;5;17m@\033[38;5;17m@\033[38;5;168m:\033[38;5;168m:\033[38;5;168m:\033[38;5;17m@\033[38;5;168m:\033[38;5;168m:\033[38;5;168m:\033[38;5;17m@\033[38;5;168m:\033[38;5;168m:\033[38;5;168m:\033[38;5;168m:\033[38;5;168m:\033[38;5;168m:\033[38;5;17m@\033[38;5;17m@\033[38;5;168m:\033[38;5;168m:\033[38;5;168m:\033[38;5;168m:\033[38;5;168m:\033[38;5;168m:\033[38;5;17m@\033[38;5;17m@\n");
    printf("\033[38;5;17m@\033[38;5;17m@\033[38;5;17m@\033[38;5;17m@\033[38;5;17m@\033[38;5;17m@\033[38;5;17m@\033[38;5;17m@\033[38;5;17m@\033[38;5;17m@\033[38;5;17m@\033[38;5;17m@\033[38;5;17m@\033[38;5;17m@\033[38;5;17m@\033[38;5;17m@\033[38;5;17m@\033[38;5;17m@\033[38;5;17m@\033[38;5;17m@\033[38;5;17m@\033[38;5;17m@\033[38;5;17m@\033[38;5;17m@\033[38;5;17m@\033[38;5;17m@\033[38;5;17m@\033[38;5;17m@\033[38;5;17m@\033[38;5;17m@\033[38;5;17m@\033[38;5;17m@\033[38;5;17m@\033[38;5;17m@\033[38;5;17m@\033[38;5;17m@\033[38;5;17m@\033[38;5;17m@\033[38;5;17m@\033[38;5;17m@\033[38;5;17m@\033[38;5;17m@\033[38;5;17m@\033[38;5;17m@\033[38;5;17m@\033[38;5;17m@\033[38;5;17m@\033[38;5;17m@\033[38;5;17m@\033[38;5;17m@\033[38;5;17m@\033[38;5;17m@\033[38;5;17m@\033[38;5;17m@\033[38;5;17m@\033[38;5;17m@\033[38;5;17m@\033[38;5;17m@\033[38;5;17m@\033[38;5;17m@\033[38;5;17m@\033[38;5;17m@\033[38;5;17m@\033[38;5;17m@\033[38;5;17m@\033[38;5;17m@\033[38;5;17m@\033[38;5;17m@\033[38;5;17m@\033[38;5;17m@\033[38;5;17m@\033[38;5;17m@\033[38;5;17m@\033[38;5;17m@\033[38;5;17m@\033[38;5;17m@\033[38;5;17m@\033[38;5;17m@\n");

    printf("\033[38;5;201m%s %s\n", "Blitzkrieg", BLITZKRIEG_VERSION);
    printf("\033[38;5;165m%s\n", "A protocol research and C coding project masquerading as a C2.");
    printf("\033[38;5;168m%s, %s\n", BLITZKRIEG_COPYRIGHT, BLITZKRIEG_DEVELOPER);
    printf("\n\E[0m");

    gchar **cli_args;                                        /* CLI arguments */
    struct settings *conf = g_slice_new(struct settings);    /* All settings */
    struct event_base *base;                                 /* LibEvent */
    GArray *ServiceDatas = g_array_new(FALSE, FALSE, sizeof(struct server_data *));    /* Services */

    /* Init glib */
    g_log_set_handler(G_LOG_DOMAIN,
                      G_LOG_LEVEL_MASK,
                      g_log_default_handler,
                      NULL);

    /* Init libevent */
    base = event_base_new();
    if (!base)
        g_error("event_base_new() failed");

    /* Init configuration */
    conf->service_enable_dns = SERVICE_STATUS_UNKNOWN;
    conf->service_enable_http = SERVICE_STATUS_UNKNOWN;
    conf->service_enable_smtp = SERVICE_STATUS_UNKNOWN;

    /* Read command line arguments */
    cli_args = g_strdupv(argv);
    cli_arguments_parse(cli_args, conf);
    g_strfreev(cli_args);




    /*
     * TESTING STUFF
     */


    /* Service provisioning, setup, and registering. - Create sockets,
     * register callbacks */
    /* TODO: plugin hook */
    if (conf->service_enable_dns == SERVICE_STATUS_ENABLED) {
        /* TODO: plugin hook */

        struct service_data *service_data_dns;
        service_data_dns =
                service_generate(SERVICE_TYPE_DNS, SERVICE_PROTO_UDP, 53, base);
        g_array_append_val(ServiceDatas, service_data_dns);
        g_info("Service DNS Loaded");

        /* TODO: plugin hook */
    }
    if (conf->service_enable_http == SERVICE_STATUS_ENABLED) {
        /* TODO: plugin hook */

        struct service_data *service_data_http;
        service_data_http =
                service_generate(SERVICE_TYPE_HTTP, SERVICE_PROTO_TCP, 80, base);
        g_array_append_val(ServiceDatas, service_data_http);
        g_info("Service HTTP Loaded");

        /* TODO: plugin hook */
    }
    if (conf->service_enable_smtp == SERVICE_STATUS_ENABLED) {
        /* TODO: plugin hook */

        struct service_data *service_data_smtp;
        service_data_smtp =
                service_generate(SERVICE_TYPE_SMTP, SERVICE_PROTO_TCP, 25, base);
        g_array_append_val(ServiceDatas, service_data_smtp);
        g_info("Service SMTP Loaded");

        /* TODO: plugin hook */
    }
    /* TODO: plugin_hook */

    /* TODO: plugin hook */
    event_base_dispatch(base);
    /* TODO: plugin hook */

    /* Cleanup */
    /* XXX - Close all sockets */
    if (conf)
        g_slice_free(struct settings, conf);
    if (ServiceDatas)
        g_array_free(ServiceDatas, TRUE);

    return (EXIT_SUCCESS);
}
