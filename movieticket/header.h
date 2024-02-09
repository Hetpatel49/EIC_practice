/*this is header.h file*/
typedef struct ticket
{
    int ticketno;
    int screen;
    char *movie;
    char *seat;
    char *time;
    char *date;
    int price;
} ticket_t;

ticket_t *tickets;

void init(ticket_t *);
int selectoption(void);
int selectmovie(ticket_t *);
char seatchar(int);
int str_to_int(char []);
void print_available_seats();
void reservation(int *, ticket_t *);
void cancel(int **);
void print_ticket(ticket_t *);

/*
typedef struct dll_node_{

    void *data;
    struct dll_node_ *next;
} dll_node_t;

typedef struct dll_{
    dll_node_t *head;
} dll_t;

dll_t *get_new_dll();
int dll_insert_data (dll_t *dll, void *data);
int add_data_to_dll(dll_t *dll, void *data);

#define ITERATE_LIST_BEGIN(list_ptr, node_ptr)                              \
{                                                                           \
    dll_node_t *_node_ptr = NULL;                                           \
    node_ptr = list_ptr->head;                                              \
    for(; node_ptr!= NULL; node_ptr = _node_ptr){                           \
        if(!node_ptr) break;                                                \
        _node_ptr = node_ptr->right;

#define ITERATE_LIST_END  }}
*/
