/*
Указатель на функцию
*/
int area(int a) {
    return a * a;
}

int perimeter(int a) {
    return a + a + a + a;
}

int main(int argc, char *[]) {
    int (*formula)(int) =  argc % 2 ? &area : &perimeter;
    return formula(argc);
}