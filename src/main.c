#include <stdio.h>
#include <kv.h>

int main() {
    kv_t *table = kv_init(32);
    printf("%p\n", table);
    printf("%ld\n", table->capacity);

    kv_put(table, "hehe", "haha");
    //kv_put(table, "hehe", "hoho");
    //kv_put(table, "lala", "baba");
    kv_put(table, "egg", "protein");
    
    for (int i = 0; i < table->capacity; i++) {
        if (table->entries[i].key) {
            printf("[%d] %s: %s\n",
                    i,
                    table->entries[i].key,
                    table->entries[i].value);
        }
    }

    char *val = kv_get(table, "hehe");
    char *val2 = kv_get(table, "egg");
    char *val3 = kv_get(table, "This_doesnt_exist");

    printf("%s %s %s\n", val, val2, val3);

    //return 0;
}
