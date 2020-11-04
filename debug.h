/* In this header are macros tho facilitate debugging */
# define BOLD				"\033[1m"
# define BLACK				"\033[30m"
# define RED				"\033[31m"
# define GREEN				"\033[32m"
# define YELLOW				"\033[33m"
# define BLUE				"\033[34m"
# define MAGENTA			"\033[35m"
# define CYAN				"\033[36m"
# define WHITE				"\033[37m"
# define ORANGE				"\033[38;5;202m"

# define ANSI_RESET			"\033[0m"

# define DEBUG(msg,...) fprintf(stderr, BOLDGREEN"[LOG](%s:%d)" RED msg ANSI_RESET"\n" , __FILE__, __LINE__, ##__VA_ARGS__)

_HIDDEN_ void _intp		(int *ptr,	size_t len)	{size_t i; i = 0;while (i < len) {printf("%d\n", ptr[i]); i++;};}
_HIDDEN_ void _boolp	(bool *ptr, size_t len)	{size_t i; i = 0;while (i < len) {ptr[i] == true ? printf("True\n") : printf("False\n"); i++;}}
_HIDDEN_ void _vectp	(_V2 **ptr, size_t len)	{size_t i; i = 0; while (i < len) {printf("(%d,%d)\n", ptr[i]->x, ptr[i]->y); i++;}}
_HIDDEN_ void _nodep	(_Node *ptr,size_t len)	{while (ptr != NULL){printf("%s\n", ptr->data);ptr = ptr->next;}}
_HIDDEN_ void _defp		(void *ptr, size_t len)	{_DEBUG_("PRINTING WITH UNDEFINED TYPE (likely char *, use printf instead)");}


# define _PRINT_1D(array, size) _Generic((array),\
	int		*: _intp_  ((int  *) array, size),\
	bool	*: _boolp_ ((bool *) array, size),\
	_Node	*: _nodep_ ((_Node *)array, size),\
	default	 : _defp_  (array, size))
