
struct BigInt *initialize(char *str);

void display(struct BigInt*num);

struct BigInt *insert_front(struct BigInt *output, int val);

struct BigInt *insert_end(struct BigInt *position, int val);

void freeBigInt(struct BigInt *num);

struct BigInt *Sum(struct BigInt *n1, struct BigInt *n2);

struct BigInt *Sub(struct BigInt *n1, struct BigInt *n2);

struct BigInt *Product(struct BigInt *n1, struct BigInt *n2);

struct BigInt *Divide(struct BigInt *n1, struct BigInt *n2);

int compareBigInt(struct BigInt *num1, struct BigInt *num2);

int getLength(struct BigInt *num);

struct node *create_node(int digit);
