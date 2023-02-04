#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
char create[] = {'c' , 'r' , 'e' , 'a' , 't' , 'e' , 'f' , 'i' , 'l' , 'e', '\0'};
char insert[] = {'i' , 'n' , 's' , 'e' , 'r' , 't' , '\0'};
char root[] = {'r' , 'o' , 'o' , 't' , '\0'};
char cat[] = {'c' , 'a' , 't' , '\0'};
char rem[] = {'r' , 'e' , 'm' , 'o' , 'v' , 'e' , '\0'};
char cop[] = {'c' , 'o' , 'p' , 'y' , '\0'};
char cut[] = {'c' , 'u' , 't' , '\0'};
char paste[] = {'p' , 'a' , 's' , 't' , 'e' , '\0'};
char find[] = {'f' , 'i' , 'n' , 'd' , '\0'};
char count[] = {'-' , 'c' , 'o' , 'u' , 'n' , 't' , '\0'};
char at[] = {'-' , 'a' , 't' , '\0'};
char byword[] = {'-' , 'b' , 'y' , 'w' , 'o' , 'r' , 'd' , '\0'};
char all[] = {'-' , 'a' , 'l' , 'l' , '\0'};
char rep[] = {'r' , 'e' , 'p' , 'l' , 'a' , 'c' , 'e' , '\0'};
char grep[] = {'g' , 'r' , 'e' , 'p' , '\0'};
char c[] = {'-' , 'c' , '\0'};
char l[] = {'-' , 'l' , '\0'};
char str[] = {'-' , 's' , 't' , 'r' , '\0'};
char undo[] = {'u' , 'n' , 'd' , 'o' , '\0'};
char autoindent[] = {'a' , 'u' ,'t' , 'o' , '-' , 'i' , 'n' , 'd' , 'e' , 'n' , 't' , '\0'};
char comp[] = {'c' , 'o' , 'm' , 'p' , 'a' , 'r' , 'e' , '\0'};
char tree[] = {'t' , 'r' , 'e' , 'e' , '\0'};
char arman[] = {'a' , 'r' , 'm' , 'a' , 'n' , '\0'};
int findwhere(char a[] , int n , char b[] , int m){
    int length = 0;
    for(int i = 0 ; i < n ; i++){
        if(a[i] == b[length]){
            length++;
            if(length == m){
                return i-length+1;
            }
        }
        else{
            length = 0;
        }
    }
    return -1;
}
void findword(char a[] , int n , char b[] , int m){
    int t = 0;
    int length = 0;
    for(int i = 0 ; i < n ; i++){
        if(a[i] == b[length]){
            length++;
            if(length == m){
                t++;
                int j = 0;
                for(int k = 0 ; k <= i ; k++){
                    if(a[k] == ' ')
                        j++;
                }
                printf("%d" , j+1);
            }
        }
        else{
            length = 0;
        }
    }
    if(t == 0)
        printf("NEVER");
}
int findcount(char a[] , int n , char b[] , int m){
    int t = 0;
    int length = 0;
    for(int i = 0 ; i < n ; i++){
        if(a[i] == b[length]){
            length++;
            if(length == m){
                t++;
                length = 0;
            }
        }
        else{
            length = 0;
        }
    }
    return t;
}
int findat(char a[] , int n , char b[] , int m , int atwhat){
    int t = 0;
    int length = 0;
    for(int i = 0 ; i < n ; i++){
        if(a[i] == b[length]){
            length++;
            if(length == m){
                t++;
                if(t == atwhat){
                    return i-length+1;
                }
                else{
                    length = 0;
                }
            }
        }
        else{
            length = 0;
        }
    }
    return -1;
}
void findall(char a[] , int n , char b[] , int m){
    int length = 0;
    int t = 0;
    for(int i = 0 ; i < n ; i++){
        if(a[i] == b[length]){
            length++;
            if(length == m){
                t++;
                printf("%d\n" , i - length+1);
                length = 0;
            }
        }
        else{
            length = 0;
        }
    }
    if(t == 0){
        printf("never");
    }
}
void cls(char a[] , int n){
    for(int i = 0 ; i < n ; i++){
        a[i] = 0;
    }
}
void slash(char a[]){
    int i = 0;
    while(a[i] != NULL){
        a[i] = a[i+1];
    }
}
void quotation(char a[] , int n){
    for(int i = 0 ; i < n-2 ; i++){
        a[i] = a[i+1];
    }
    a[n-1] = NULL;
    a[n-2] = NULL;
}
int main(){
    char request[50];
    char garbage[100];
    char zapundo[100];
    for(int i = 0 ; i < 100 ; i++){
        zapundo[i] = 0;
    }
    FILE* fptr;
    if(!(fptr = fopen("undo" , "r"))){
        fptr = fopen("undo" , "w");
        fclose(fptr);
    }
    mkdir(root);
    scanf("%s" , request);
    if(strcmp(request , create) == 0){
        scanf("%s" , garbage);
        char whatfile[50];
        char zap[50];
        char space = getchar();
        gets(whatfile);
        int h = 0;
        while(whatfile[h] != NULL){
            h++;
        }
        if(whatfile[0] == '"'){
             quotation(whatfile , h);
        }
        int i = 0 , t = 0 , k = 0;
        for(int j = 0 ; j < 50 ; j++){
            if(whatfile[j] == '/')
                t++;
        }
        for(int j = 0 ; j < t ; j++){
            while(whatfile[i] != '/'){
                zap[k] = whatfile[i];
                k++;
                i++;
            }
            if(j == 0){
                //printf("T");
                i++;
                cls(zap , 50);
                k = 0;
            }
            else if(strcmp(zap , root) == 0){
                //printf("T");
                chdir(root);
                cls(zap , 50);
                k = 0;
                i++;
            }
            else{
                //printf("T");
                mkdir(zap);
                chdir(zap);
                cls(zap , 50);
                i++;
                k = 0;
            }
        }
        k = 0;
        cls(zap , 50);
        while(whatfile[i] != 0){
            zap[k] = whatfile[i];
            k++;
            i++;
        }
        FILE* fptr;
        fptr = fopen(zap , "w");
        fclose(fptr);
        for(int j = 0 ; j < t-1 ; j++){
            //printf("%d" , t);
            chdir("..");
        }
    }
    else if(strcmp(insert , request) == 0){
        char address[50];
        char note[50];
        scanf("%s %s" ,garbage , address);
        for(int i = 0 ; i < 49 ; i++){
            address[i] = address[i+1];
        }
        FILE* fptr;
        if(!(fptr = fopen(address , "r"))){
            printf("file does not exist");
            fclose(fptr);
            return 0;
        }
        else{
            fptr = fopen(address , "r");
            int n = 0;
            char ch;
            while((ch = fgetc(fptr)) != EOF){
                zapundo[n] = ch;
                n++;
            }
            fclose(fptr);
            fptr = fopen("undo" , "w");
            fprintf(fptr , "%s" , zapundo);
            fclose(fptr);
            scanf("%s" , garbage);
            char space;
            scanf("%c" , &space);
            char c;
            scanf("%c" , &c);
            for(int i = 0 ; i < 50 ; i++){
                note[i] = 0;
            }
            if(c == '"'){
                char d = getchar();
                int i = 0;
                int r = 0;
                while(r == 0){
                    note[i] = d;
                    i++;
                    d = getchar();
                    if(d == '"'){
                        if(note[i-1]== '\\')
                            continue;
                        else
                            break;
                    }
                }
            }
            else{
                scanf("%s" , note);
                for(int i = 49 ; i > 0 ; i--){
                note[i] = note[i-1];
                }
                note[0] = c;
            }
            scanf("%s" , garbage);
            int line , letter;
            scanf("%d:%d" , &line , &letter);
            for(int i = 0 ; i < 50 ; i++){
                if(note[i] == '\\' && note[i+1] == 'n' && note[i-1] != '\\'){
                    for(int j = i+1 ; j < 49 ; j++){
                        note[j] = note[j+1];
                    }
                    note[i] = '\n';
                }
                else if(note[i] == '\\' && note[i+1] == 'n' && note[i-1] == '\\'){
                    for(int j = i ; j < 49 ; j++){
                        note[j] = note[j+1];
                    }
                }
                else if(note[i] == '\\' && note[i+1] == '"'){
                    for(int j = i ; j < 49 ; j++){
                        note[j] = note[j+1];
                    }
                }
            }
            fptr = fopen(address , "w");
            for(int i = 1 ; i < line ; i++){
                fprintf(fptr , "\n");
            }
            for(int i = 0 ; i < letter ; i++){
                fprintf(fptr , " ");
            }
            fprintf(fptr , "%s" , note);
            fclose(fptr);
        }
    }
    else if(strcmp(request , cat) == 0){
        scanf("%s" , garbage);
        chdir("root");
        char address[50];
        scanf("%s" , address);
        char ch;
        FILE* fptr;
        if(!(fptr = fopen(address , "r")))
            printf("Not exist!");
        else{
            fptr = fopen(address , "r");
            while((ch = fgetc(fptr)) != EOF)
                printf("%c" , ch);
            fclose(fptr);
        }
        chdir("..");
    }
    else if(strcmp(request , rem) == 0){
        scanf("%s" , garbage);
        char address[50];
        char fb[2];
        scanf("%s" , address);
        for(int i = 0 ; i < 49 ; i++){
            address[i] = address[i+1];
        }
        int line , letter , size;
        scanf("%s %d:%d %s %d %s" , garbage , &line , &letter , garbage , &size , fb);
        FILE* fptr;
        if(!(fptr = fopen(address , "r")))
            printf("Not exist!");
        else{
            fptr = fopen(address , "r");
            char zap[50];
            int i = 0;
            char ch;
            while((ch = fgetc(fptr)) != EOF){
                zap[i] = ch;
                zapundo[i] = ch;
                i++;
            }
            fclose(fptr);
            fptr = fopen("undo" , "w");
            fprintf(fptr , "%s" , zapundo);
            fclose(fptr);
            int p = 0 , w = 0;
            line = line-1;
            while(p != line){
                if(zap[w] == '\n')
                    p++;
                w++;
            }
            for(int j = 0 ; j < letter ; j++){
                w++;
            }
            if(fb[1] == 'f'){
                int q = 1;
                for(int j = 0 ; j < size ; j++){
                    for(int k = w ; k < 50 - q ; k++){
                        zap[k]=zap[k+1];
                    }
                    q++;
                }
            }
            else{
                for(int j = w ; j < 50 ; j++){
                    zap[j-size] = zap[j];
                }
                for(int j = 49 ; j > 49-size ; j--){
                    zap[j] = 0;
                }
            }
            fclose(fptr);
            FILE* ptr = fopen(address , "w");
            fprintf(ptr , "%s" , zap);
            fclose(ptr);
        }
    }
    else if(strcmp(request , cop) == 0){
        char address[50];
        char zap[50];
        char fb[2];
        int line , letter , size;
        scanf("%s %s %s %d:%d %s %d %s" , garbage , address , garbage , &line , &letter , garbage , &size , fb);
        for(int i = 0 ; i < 49 ; i++){
            address[i] = address[i+1];
        }
        char ch;
        FILE* fptr;
        if(!(fptr = fopen(address , "r"))){
            printf("Not exist!");
            return 0;
        }
        else{
            int i = 0;
            for(int j = 0 ; j < 50 ; j++){
                zap[j] = 0;
            }
            fptr = fopen(address , "r");
            while((ch = fgetc(fptr)) != EOF){
                zap[i] = ch;
                i++;
            }
            fclose(fptr);
        }
        int p = 0 , w = 0;
        line = line-1;
        while(p != line){
            if(zap[w] == '\n')
                p++;
            w++;
        }
        for(int j = 0 ; j < letter ; j++){
            w++;
        }
        char zap2[size];
        for(int j = 0 ; j < 50 ; j++){
            zap2[j] = 0;
        }
        if(fb[1] == 'f'){
            for(int j = 0 ; j < size ; j++){
                zap2[j] = zap[w];
                w++;
            }
        }
        else{
            for(int j = size-1 ; j >= 0 ; j--){
                zap2[j] = zap[w-1];
                w--;
            }
        }
        FILE* ptr;
        ptr = fopen("clipboard" , "w");
        fprintf(ptr , "%s" , zap2);
        fclose(ptr);
    }
    else if(strcmp(request , cut) == 0){
        char address[50];
        char zap[50];
        char fb[2];
        int line , letter , size;
        scanf("%s %s %s %d:%d %s %d %s" , garbage , address , garbage , &line , &letter , garbage , &size , fb);
        for(int i = 0 ; i < 49 ; i++){
            address[i] = address[i+1];
        }
        char ch;
        FILE* fptr;
        if(!(fptr = fopen(address , "r"))){
            printf("Not exist!");
            return 0;
        }
        else{
            int i = 0;
            fptr = fopen(address , "r");
            while((ch = fgetc(fptr)) != EOF){
                zap[i] = ch;
                zapundo[i] = ch;
                i++;
            }
            fclose(fptr);
            fptr = fopen("undo" , "w");
            fprintf(fptr , "%s" , zapundo);
            fclose(fptr);
        }
        int p = 0 , w = 0;
        line = line-1;
        while(p != line){
            if(zap[w] == '\n')
                p++;
            w++;
        }
        for(int j = 0 ; j < letter ; j++){
            w++;
        }
        char zap2[size];
        for(int j = 0 ; j < 50 ; j++){
            zap2[j] = 0;
        }
        if(fb[1] == 'f'){
            for(int j = 0 ; j < size ; j++){
                zap2[j] = zap[w];
                w++;
            }
        }
        else{
            for(int j = size-1 ; j >= 0 ; j--){
                zap2[j] = zap[w-1];
                w--;
            }
        }
        FILE* ptr;
        ptr = fopen("clipboard" , "w");
        fprintf(ptr , "%s" , zap2);
        fclose(ptr);
        p = 0 , w = 0;
        while(p != line){
            if(zap[w] == '\n')
                p++;
            w++;
        }
        for(int j = 0 ; j < letter ; j++){
            w++;
        }
        if(fb[1] == 'f'){
            int q = 1;
            for(int j = 0 ; j < size ; j++){
                for(int k = w ; k < 50 - q ; k++){
                    zap[k]=zap[k+1];
                }
                q++;
            }
        }
        else{
            for(int j = w ; j < 50 ; j++){
                zap[j-size] = zap[j];
            }
            for(int j = 49 ; j > 49-size ; j--){
                zap[j] = 0;
            }
        }
        ptr = fopen(address , "w");
        fprintf(ptr , "%s" , zap);
        fclose(ptr);
    }
    else if(strcmp(request , paste) == 0){
        int line , letter;
        char address[50];
        char zap[50];
        char zap2[50];
        scanf("%s %s %s %d:%d" , garbage , address , garbage , &line , &letter);
        for(int i = 0 ; i < 49 ; i++){
            address[i] = address[i+1];
        }
        FILE* fptr;
        if(!(fptr = fopen(address , "r"))){
            printf("Not exist!");
            return 0;
        }
        else{
            for(int k = 0 ; k < 50 ; k++){
                zap[k] = 0;
            }
            int i = 0;
            char ch;
            fptr = fopen(address , "r");
            while((ch = fgetc(fptr)) != EOF){
                zap[i] = ch;
                zapundo[i] = ch;
                i++;
            }
            fclose(fptr);
            fptr = fopen("undo" , "w");
            fprintf(fptr , "%s" , zapundo);
            fclose(fptr);
        }
        int j = 0;
        char ch;
        for(int k = 0 ; k < 50 ; k++){
            zap2[k] = 0;
        }
        fptr = fopen("clipboard" , "r");
        while((ch = fgetc(fptr)) != EOF){
            zap2[j] = ch;
            j++;
        }
        fclose(fptr);
        int p = 0 , w = 0;
        line = line-1;
        while(p != line){
            if(zap[w] == '\n')
                p++;
            w++;
        }
        for(int j = 0 ; j < letter ; j++){
            w++;
        }
        j = 0;
        while(zap2[j] != 0){
            j++;
        }
        int o = 0;
        while(zap[o] != 0){
            o++;
        }
        char zap3[o+j];
        for(int i = 0 ; i < o+j ; i++){
            zap3[i] = 0;
        }
        for(int i = 0 ; i < o+j ; i++){
            if(i < w){
                zap3[i] = zap[i];
            }
            else if(i == w){
                while(i < w + j){
                   zap3[i] = zap2[i-w];
                   i++;
                }
                i--;
            }
            else{
                zap3[i] = zap[i-j];
            }
        }
        fptr = fopen(address , "w");
        fprintf(fptr , "%s" , zap3);
        fclose(fptr);
    }
    else if(strcmp(request , find) == 0){
        char what[50];
        char zap[50];
        char address[50];
        for(int j = 0 ; j < 50 ; j++){
            zap[j] = 0;
            what[j] = 0;
            address[j] = 0;
        }
        scanf("%s" , garbage);
        char space , c;
        scanf("%c" , &space);
        scanf("%c" , &c);
        if(c == '"'){
            char d = getchar();
            int i = 0;
            while(1){
                what[i] = d;
                i++;
                d = getchar();
                if(d == '"'){
                    if(what[i-1]== '\\')
                        continue;
                    else
                        break;
                }
            }
        }
        else{
            scanf("%s" , what);
            for(int i = 49 ; i > 0 ; i--){
                what[i] = what[i-1];
            }
            what[0] = c;
        }
        scanf("%s %s" , garbage , address);
        for(int i = 0 ; i < 49 ; i++){
            address[i] = address[i+1];
        }
        FILE* fptr;
        int size = 0;
        while(what[size] != 0)
            size++;
        if(!(fptr = fopen(address , "r"))){
            printf("Not exist!");
            return 0;
        }
        else{
            scanf("%c" , &space);
            if(space == '\n'){
                char ch;
                int i = 0;
                fptr = fopen(address , "r");
                while((ch = fgetc(fptr)) != EOF){
                    zap[i] = ch;
                    i++;
                }
            int save = findwhere(zap , 50 , what , size);
            printf("%d" , save);
            return 0;
            }
            else{
                char whatelse[10];
                scanf("%s" , whatelse);
                if(strcmp(whatelse , count) == 0){
                    char ch;
                    int i = 0;
                    fptr = fopen(address , "r");
                    while((ch = fgetc(fptr)) != EOF){
                        zap[i] = ch;
                        i++;
                    }
                    printf("%d" , findcount(zap , 50 , what , size));
                    return 0;
                }
                else if(strcmp(whatelse , at) == 0){
                    int atwhat;
                    scanf("%d" , &atwhat);
                    char ch;
                    int i = 0;
                    fptr = fopen(address , "r");
                    while((ch = fgetc(fptr)) != EOF){
                        zap[i] = ch;
                        i++;
                    }
                    printf("%d" , findat(zap , 50 , what , size , atwhat));
                    return 0;
                }
                else if(strcmp(whatelse , all) == 0){
                    char ch;
                    int i = 0;
                    fptr = fopen(address , "r");
                    while((ch = fgetc(fptr)) != EOF){
                        zap[i] = ch;
                        i++;
                    }
                    findall(zap , 50 , what , size);
                    return 0;
                }
                else if(strcmp(byword , whatelse) == 0){
                    char ch;
                    int i = 0;
                    fptr = fopen(address , "r");
                    while((ch = fgetc(fptr)) != EOF){
                        zap[i] = ch;
                        i++;
                    }
                    findword(zap , 50 , what , size);
                }
            }
        }
    }
    else if(strcmp(request , rep) == 0){
        char address[50];
        char have[50];
        char want[50];
        for(int i = 0 ; i < 50 ; i++){
            have[i] = 0;
            want[i] = 0;
        }
        scanf("%s" , garbage);
        char space , c;
        scanf("%c" , &space);
        scanf("%c" , &c);
        if(c == '"'){
            char d = getchar();
            int i = 0;
            while(1){
                have[i] = d;
                i++;
                d = getchar();
                if(d == '"'){
                    if(have[i-1]== '\\')
                        continue;
                    else
                        break;
                }
            }
        }
        else{
            scanf("%s" , have);
            for(int i = 49 ; i > 0 ; i--){
                have[i] = have[i-1];
            }
            have[0] = c;
        }
        scanf("%s" , garbage);
        scanf("%c" , &space);
        scanf("%c" , &c);
        if(c == '"'){
            char d = getchar();
            int i = 0;
            while(1){
                want[i] = d;
                i++;
                d = getchar();
                if(d == '"'){
                    if(want[i-1]== '\\')
                        continue;
                    else
                        break;
                }
            }
        }
        else{
            scanf("%s" , want);
            for(int i = 49 ; i > 0 ; i--){
                want[i] = want[i-1];
            }
            want[0] = c;
        }
        scanf("%s %s" , garbage , address);
        for(int i = 0 ; i < 49 ; i++){
            address[i] = address[i+1];
        }
        FILE* fptr;
        if(!(fptr = fopen(address , "r"))){
            printf("Not exist!");
            return 0;
        }
        fptr = fopen(address , "r");
        int n = 0;
        char ch;
        while((ch = fgetc(fptr)) != EOF){
            zapundo[n] = ch;
            n++;
        }
        fclose(fptr);
        fptr = fopen("undo" , "w");
        fprintf(fptr , "%s" , zapundo);
        fclose(fptr);
        char zap[50];
        for(int i = 0 ; i < 50 ; i++){
            zap[i] = 0;
        }
        int i = 0;
        fptr = fopen(address , "r");
        while((ch = fgetc(fptr)) != EOF){
            zap[i] = ch;
            i++;
        }
        fclose(fptr);
        scanf("%c" , &space);
        if(space == '\n'){
            int start = findwhere(zap , 50 , have , strlen(have));
            if(start == -1){
                printf("Not found");
                return 0;
            }
            else{
                for(int i = start ; i < strlen(zap) ; i++){
                    zap[i] = zap[i+strlen(have)];
                }
                char zap3[strlen(zap) + strlen(want)];
                for(int i = 0 ; i < strlen(zap) + strlen(want) ; i++){
                    zap3[i] = 0;
                }
                for(int i = 0 ; i < strlen(zap) + strlen(want) ; i++){
                    if(i < start){
                        zap3[i] = zap[i];
                    }
                    else if(i == start){
                        while(i < start + strlen(want)){
                            zap3[i] = want[i-start];
                            i++;
                        }
                        i--;
                    }
                    else{
                        zap3[i] = zap[i-strlen(want)];
                    }
                }
                for(int i = strlen(want) + strlen(zap) ; i < strlen(zap3) ; i++){
                    zap3[i] = 0;
                }
                fptr = fopen(address , "w");
                fprintf(fptr , "%s" , zap3);
                fclose(fptr);
                return 0;
            }
        }
        else{
            char whatelse[10];
            int start;
            scanf("%s" , whatelse);
            if(strcmp(whatelse , all) == 0){
                start = findwhere(zap , 50 , have , strlen(have));
                while(start != -1){
                   for(int i = start ; i < strlen(zap) ; i++){
                    zap[i] = zap[i+strlen(have)];
                    }
                    char zap3[strlen(zap) + strlen(want)];
                    for(int i = 0 ; i < strlen(zap) + strlen(want) ; i++){
                        zap3[i] = 0;
                    }
                    for(int i = 0 ; i < strlen(zap) + strlen(want) ; i++){
                        if(i < start){
                            zap3[i] = zap[i];
                        }
                        else if(i == start){
                            while(i < start + strlen(want)){
                                zap3[i] = want[i-start];
                                i++;
                            }
                            i--;
                        }
                        else{
                            zap3[i] = zap[i-strlen(want)];
                        }
                    }
                    for(int i = strlen(want) + strlen(zap) ; i < strlen(zap3) ; i++){
                        zap3[i] = 0;
                    }
                    for(int i = 0 ; i < 50 ; i++){
                        zap[i] = zap3[i];
                    }
                    start = findwhere(zap , 50 , have , strlen(have));
                }
                fptr = fopen(address , "w");
                fprintf(fptr , "%s" , zap);
                fclose(fptr);
            }
            else if(strcmp(whatelse , at) == 0){
                int towhere;
                scanf("%d" , &towhere);
                char zap2[50] , zap4[50];
                for(int i = 0 ; i < 50 ; i++){
                    zap2[i] = 0;
                }
                int times = 0;
                for(int i = 0 ; i < 50 ; i++){
                    zap2[i] = 0;
                    zap2[i] = zap[i];
                    zap4[i] = zap2[i];
                }
                int startnew = findwhere(zap , 50 , have , strlen(have));
                while(towhere-1){
                    if(startnew == -1){
                    printf("Not found");
                    return 0;
                    }
                else{
                    for(int i = startnew ; i < strlen(zap) ; i++){
                        zap[i] = zap[i+strlen(have)];
                    }
                    char zap3[strlen(zap) + strlen(want)];
                    for(int i = 0 ; i < strlen(zap) + strlen(want) ; i++){
                        zap3[i] = 0;
                    }
                    for(int i = 0 ; i < strlen(zap) + strlen(want) ; i++){
                        if(i < startnew){
                            zap3[i] = zap[i];
                        }
                        else if(i == startnew){
                            while(i < startnew + strlen(want)){
                                zap3[i] = want[i-startnew];
                                i++;
                            }
                            i--;
                        }
                        else{
                            zap3[i] = zap[i-strlen(want)];
                        }
                    }
                    for(int i = strlen(want) + strlen(zap) ; i < strlen(zap3) ; i++){
                        zap3[i] = 0;
                    }
                    towhere--;
                    for(int i = 0 ; i < strlen(zap)+100 ; i++){
                        zap[i] = zap3[i];
                    }
                    times++;
                    startnew = findwhere(zap , 50 , have , strlen(have));
                }
                    start = startnew + (times * (strlen(have)-strlen(want)));
                }
                for(int i = start ; i < strlen(zap4) ; i++){
                    zap4[i] = zap4[i+strlen(have)];
                }
                char zap3[strlen(zap4) + strlen(want)];
                char zapp[100];
                int j = 0;
                for(int i = 0 ; i < strlen(zap4) + strlen(want) ; i++){
                    zap3[i] = 0;
                }
                for(int i = 0 ; i < strlen(zap4) + strlen(want) ; i++){
                    if(i < start){
                        zap3[i] = zap4[i];
                        zapp[j] = zap3[i];
                        j++;
                    }
                    else if(i == start){
                        while(i < start + strlen(want)){
                            zap3[i] = want[i-start];
                            zapp[j] = zap3[i];
                            j++;
                            i++;
                        }
                        i--;
                    }
                    else{
                        zap3[i] = zap4[i-strlen(want)];
                        zapp[i] = zap3[i];
                        j++;
                    }
                }
                for(int i = strlen(want) + strlen(zap4) ; i < strlen(zap3) ; i++){
                    zap3[i] = 0;
                }
                fptr = fopen(address , "w");
                fprintf(fptr , "%s" , zapp);
                fclose(fptr);
            }
        }
    }
    else if(strcmp(request , grep) == 0){
        char op[5];
        scanf("%s" , op);
        if(strcmp(op , str) == 0){
            char pattern[20];
            char pat[200];
            scanf("%s %s" , pattern , garbage);
            for(int i = 0 ; i < strlen(pattern) ; i++){
                pat[i] = pattern[i];
            }
            char enter = getchar();
            while(enter != '\n'){
                char address[50];
                scanf("%s" , address);
                for(int i = 0 ; i < 49 ; i++){
                    address[i] = address[i+1];
                }
                FILE* fptr;
                if(!(fptr = fopen(address , "r"))){
                    printf("Not exist!");
                    return 0;
                }
                else{
                    char ch;
                    char zap[100];
                    for(int i = 0 ; i < 100 ; i++){
                        zap[i] = 0;
                    }
                    int i = 0;
                    fptr = fopen(address , "r");
                    while((ch = fgetc(fptr)) != EOF){
                        zap[i] = ch;
                    i++;
                    }
                    fclose(fptr);
                    int j = 0;
                    for(int i = 0 ; i < 100 ; i++){
                        if(zap[i] == pat[j]){
                            j++;
                            if(j == strlen(pat)){
                                char saveback[30];
                                char saveforward[30];
                                for(int n = 0 ; n < 30 ; n++){
                                    saveback[n] = 0;
                                    saveforward[n] = 0;
                                }
                                int save = i;
                                int save2 = i;
                                int k = 0;
                                while(zap[save] != '\n' && save >= 0){
                                    saveback[k] = zap[save];
                                    save--;
                                    k++;
                                }
                                printf("%s:" , address);
                                for(int n = k-1 ; n >= 0 ; n--){
                                    printf("%c" , saveback[n]);
                                }
                                k = 0;
                                while(zap[save2] != '\n' && save2 != strlen(saveforward)){
                                    saveforward[k] = zap[save2];
                                    save2++;
                                    k++;
                                }
                                for(int n = 1 ; n < strlen(saveforward) ; n++){
                                    printf("%c" , saveforward[n]);
                                }
                                printf("\n");
                                j = 0;
                            }
                        }
                        else{
                            j = 0;
                        }
                    }
                }
                enter = getchar();
            }
        }
        else if(strcmp(op , c) == 0){
            char pattern[20];
            int times = 0;
            scanf("%s %s %s" ,garbage , pattern , garbage);
            char enter = getchar();
            while(enter != '\n'){
                char address[50];
                scanf("%s" , address);
                for(int i = 0 ; i < 49 ; i++){
                    address[i] = address[i+1];
                }
                FILE* fptr;
                if(!(fptr = fopen(address , "r"))){
                    printf("Not exist!");
                    return 0;
                }
                else{
                    char ch;
                    char zap[100];
                    for(int i = 0 ; i < 100 ; i++){
                        zap[i] = 0;
                    }
                    int i = 0;
                    fptr = fopen(address , "r");
                    while((ch = fgetc(fptr)) != EOF){
                        zap[i] = ch;
                    i++;
                    }
                    fclose(fptr);
                    int j = 0;
                    for(int i = 0 ; i < 100 ; i++){
                        if(zap[i] == pattern[j]){
                            j++;
                            if(j == strlen(pattern)){
                                times++;
                                j = 0;
                            }
                        }
                        else{
                            j = 0;
                        }
                    }
                }
                enter = getchar();
            }
            printf("%d" , times);
        }
        else if(strcmp(op , l) == 0){
            char pattern[20];
            int times = 0;
            scanf("%s %s %s" ,garbage , pattern , garbage);
            char enter = getchar();
            while(enter != '\n'){
                char address[50];
                scanf("%s" , address);
                for(int i = 0 ; i < 49 ; i++){
                    address[i] = address[i+1];
                }
                FILE* fptr;
                if(!(fptr = fopen(address , "r"))){
                    printf("Not exist!");
                    return 0;
                }
                else{
                    char ch;
                    char zap[100];
                    for(int i = 0 ; i < 100 ; i++){
                        zap[i] = 0;
                    }
                    int i = 0;
                    fptr = fopen(address , "r");
                    while((ch = fgetc(fptr)) != EOF){
                        zap[i] = ch;
                    i++;
                    }
                    fclose(fptr);
                    int j = 0;
                    for(int i = 0 ; i < 100 ; i++){
                        if(zap[i] == pattern[j]){
                            j++;
                            if(j == strlen(pattern)){
                                times++;
                                j = 0;
                                printf("%s\n" , address);
                            }
                        }
                        else{
                            j = 0;
                        }
                    }
                }
                enter = getchar();
            }
        }
    }
    else if(strcmp(request , undo) == 0){
        char address[50];
        scanf("%s %s" , garbage , address);
        for(int i = 0 ; i < 49 ; i++){
        address[i] = address[i+1];
        }
        if(!(fptr = fopen(address , "r"))){
            printf("Not exist!");
            return 0;
        }
        else{
            char ch;
            char zap[100];
            for(int i = 0 ; i < 100 ; i++){
                zap[i] = 0;
            }
            int i = 0;
            fptr = fopen("undo" , "r");
            while((ch = fgetc(fptr)) != EOF){
                zap[i] = ch;
            i++;
            }
            fclose(fptr);
            fptr = fopen(address , "w");
            fprintf(fptr , "%s" , zap);
            fclose(fptr);
        }
    }
    else if(strcmp(request , autoindent) == 0){
        char address[50];
        scanf("%s %s" , garbage , address);
        for(int i = 0 ; i < 49 ; i++){
        address[i] = address[i+1];
        }
        if(!(fptr = fopen(address , "r"))){
            printf("Not exist!");
            return 0;
        }
        else{
            char ch;
            char zap[100];
            for(int i = 0 ; i < 100 ; i++){
                zap[i] = 0;
            }
            int i = 0;
            int n = 0 , m = 0;
            fptr = fopen(address , "r");
            while((ch = fgetc(fptr)) != EOF){
                zap[i] = ch;
                if(zap[i] == '{')
                    n++;
                else if(zap[i] == '}')
                    m++;
            i++;
            }
            fclose(fptr);
            if(n != m){
                printf("Can't be corrected");
                return 0;
            }
            else{
                char zap2[100];
                for(int i = 0 ; i < strlen(zap) ; i++){
                    if(zap[i] == '{'){
                        if(zap[i+1] != '\n'){
                            for(int j = 0 ; j < 100 ; j++){
                                if(j < i+1)
                                    zap2[j] = zap[j];
                                else if(j == i+1)
                                    zap2[j] = '\n';
                                else
                                    zap2[j] = zap[j-1];
                            }
                            for(int j = 0 ; j < 100 ; j++){
                                zap[j] = zap2[j];
                                zap2[j] = 0;
                            }
                        }
                        i++;
                    }
                    else if(zap[i] == '}'){
                        if(zap[i+1] != '\n'){
                            for(int j = 0 ; j < 100 ; j++){
                                if(j < i)
                                    zap2[j] = zap[j];
                                else if(j == i)
                                    zap2[j] = '\n';
                                else
                                    zap2[j] = zap[j-1];
                            }
                            for(int j = 0 ; j < 100 ; j++){
                                zap[j] = zap2[j];
                                zap2[j] = 0;
                            }
                        }
                        i++;
                    }
                }
                for(int i = 0 ; i < strlen(zap) ; i++){
                    if(zap[i] == '{' && i != 0){
                        if(zap[i-1] != ' ' && zap[i-1] != '\n'){
                            for(int j = 0 ; j < 100 ; j++){
                                if(j < i)
                                    zap2[j] = zap[j];
                                else if(j == i)
                                    zap2[j] = ' ';
                                else
                                    zap2[j] = zap[j-1];
                            }
                            for(int j = 0 ; j < 100 ; j++){
                                zap[j] = zap2[j];
                                zap2[j] = 0;
                            }
                        }
                    }
                }
                for(int i = 0 ; i < strlen(zap) ; i++){
                    if(zap[i] == '}'){
                        if(zap[i-1] != '\n' && i != 0){
                            for(int j = 0 ; j < 100 ; j++){
                                if(j < i-1)
                                    zap2[j] = zap[j];
                                else if(j == i-1)
                                    zap2[j] = '\n';
                                else
                                    zap2[j] = zap[j-1];
                            }
                            for(int j = 0 ; j < 100 ; j++){
                                zap[j] = zap2[j];
                                zap2[j] = 0;
                            }
                        }
                        i++;
                    }
                }
                int left_count = 0 , right_count = 0;
                int j = 0;
                for(int i = 0 ; i < strlen(zap) ; i++){
                    if(zap[i] == '{'){
                        left_count++;
                        zap2[j] = zap[i];
                        j++;
                    }
                    else if(zap[i] == '}'){
                        right_count++;
                        zap2[j] = zap[i];
                        j++;
                    }
                    else if(zap[i] == '\n' && zap[i-1] == '{'){
                        int times = left_count - right_count;
                        zap2[j] = zap[i];
                        j++;
                        int k = 0;
                        while(k < times){
                            zap2[j] = '\t';
                            k++;
                            j++;
                        }
                    }
                    else if(zap[i] == '\n' && zap[i+1] == '}'){
                        int times = left_count - right_count - 1;
                        zap2[j] = zap[i];
                        j++;
                        int k = 0;
                        while(k < times){
                            zap2[j] = '\t';
                            k++;
                            j++;
                        }
                    }
                    else{
                        zap2[j] = zap[i];
                        j++;
                    }
                }
                for(int i = 0 ; i < 200 ; i++){
                    zap[i] = zap2[i];
                    zap2[i] = 0;
                }
                printf("%s" , zap);
            }
        }
    }
    else if(strcmp(request , comp) == 0){
        char address1[50] , address2[50];
        char zap[100] , zap2[100];
        scanf("%s %s %s %s" , garbage , address1 , garbage , address2);
        for(int i = 0 ; i < 49 ; i++){
        address1[i] = address1[i+1];
        }
        if(!(fptr = fopen(address1 , "r"))){
            printf("The first one doesn't exist!");
            return 0;
        }
        else{
            for(int i = 0 ; i < 49 ; i++){
            address2[i] = address2[i+1];
            }
            if(!(fptr = fopen(address2 , "r"))){
                printf("The scond one doesn't exist!");
                return 0;
            }
            else{
                for(int i = 0 ; i < 100 ; i++){
                    zap2[i] = 0;
                    zap[i] = 0;
                }
                char ch;
                int i = 0;;
                fptr = fopen(address1 , "r");
                while((ch = fgetc(fptr)) != EOF){
                    zap[i] = ch;
                    i++;
                }
                fclose(fptr);
                i = 0;
                fptr = fopen(address2 , "r");
                while((ch = fgetc(fptr)) != EOF){
                    zap2[i] = ch;
                    i++;
                }
                fclose(fptr);
                int line1 = 1 , line2 = 1;
                for(int i = 0 ; i < 100 ; i++){
                    if(zap[i] == '\n'){
                        line1++;
                    }
                    if(zap2[i] == '\n'){
                        line2++;
                    }
                }
                int timeline = 1;
                char zap3[100] , zap4[100];
                for(int k = 0 ; k < 100 ; k++){
                    zap3[k] = 0;
                    zap4[k] = 0;
                }
                int m = 0, n = 0, k = 0;
                while(1){
                    if(timeline <= line1 && timeline <= line2){
                        while(zap[m] != '\n'){
                            zap3[k] = zap[m];
                            k++;
                            m++;
                        }
                        m++;
                        k = 0;
                        while(zap2[n] != '\n'){
                            zap4[k] = zap2[n];
                            k++;
                            n++;
                        }
                        n++;
                        k = 0;
                        if(strcmp(zap3 , zap4) == 0){
                            printf("=======#%d=======\nsame!\n\n" , timeline);
                        }
                        else{
                            printf("=======#%d=======\n%s\n%s\n\n" , timeline , zap3 , zap4);
                        }
                        for(int j = 0 ; j < 100 ; j++){
                            zap3[j] = 0;
                            zap4[j] = 0;
                        }
                        timeline++;
                    }
                    else if(timeline <= line1){
                        for(int p = m ; p < strlen(zap) ; p++){
                            zap3[k] = zap[p];
                            k++;
                        }
                        k = 0;
                        printf("=====line:%d -%s- line:%d=====\n%s\n\n" , timeline , address1 , line1 , zap3);
                        timeline++;
                    }
                    else if(timeline <= line2){
                        for(int p = n ; p < strlen(zap2) ; p++){
                            zap4[k] = zap2[p];
                            k++;
                        }
                        k = 0;
                        printf("=====line:%d ## %s ## line:%d=====\n%s\n\n" , timeline , address2 , line2 , zap4);
                        timeline++;
                    }
                    else{
                        break;
                    }
                }
            }
        }
    }
    else if(strcmp(request , tree) == 0){
        int depth;
        scanf("%d" , &depth);
        if(depth < -1){
            printf("Invalid depth");
        }
        else if(depth == 0){
            printf("root");
        }
        else if(depth == 1){
            chdir("root");
            DIR *d;
            struct dirent *dir;
            d = opendir(".");
            if (d) {
                while ((dir = readdir(d)) != NULL) {
                printf("%s\n", dir->d_name);
            }
            closedir(d);
            }
            chdir("..");
        }
        else if(depth == -1){

        }
        else{
            int times = 0;
        }
    }
    else if(strcmp(request , arman) == 0){
        char request2[10];
        char request3[10];
        char zapp[100];
        scanf("%s" , request2);
        if(strcmp(request2 , cat) == 0){
            scanf("%s" , garbage);
            for(int i = 0 ; i < 100 ; i++){
                zapp[i] = 0;
            }
            chdir("root");
            char address[50];
            scanf("%s" , address);
            char ch;
            FILE* fptr;
            if(!(fptr = fopen(address , "r")))
                printf("Not exist!");
            else{
                int i = 0;
                fptr = fopen(address , "r");
                while((ch = fgetc(fptr)) != EOF){
                zapp[i] = ch;
                i++;
                }
            }
            fclose(fptr);
            chdir("..");
        }
        else if(strcmp(request2 , grep) == 0){
            char op[5];
            scanf("%s" , op);
            if(strcmp(op , str) == 0){
                char pattern[20];
                char pat[200];
                scanf("%s %s" , pattern , garbage);
                for(int i = 0 ; i < strlen(pattern) ; i++){
                    pat[i] = pattern[i];
                }
                char enter = getchar();
                int index = 0;
                while(enter != '\n'){
                    char address[50];
                    scanf("%s" , address);
                    for(int i = 0 ; i < 49 ; i++){
                        address[i] = address[i+1];
                    }
                    FILE* fptr;
                    if(!(fptr = fopen(address , "r"))){
                        printf("Not exist!");
                        return 0;
                    }
                    else{
                        char ch;
                        char zap[100];
                        for(int i = 0 ; i < 100 ; i++){
                            zap[i] = 0;
                        }
                        int i = 0;
                        fptr = fopen(address , "r");
                        while((ch = fgetc(fptr)) != EOF){
                            zap[i] = ch;
                        i++;
                        }
                        fclose(fptr);
                        int j = 0;
                        for(int i = 0 ; i < 100 ; i++){
                            if(zap[i] == pat[j]){
                                j++;
                                if(j == strlen(pat)){
                                    char saveback[30];
                                    char saveforward[30];
                                    for(int n = 0 ; n < 30 ; n++){
                                        saveback[n] = 0;
                                        saveforward[n] = 0;
                                    }
                                    int save = i;
                                    int save2 = i;
                                    int k = 0;
                                    while(zap[save] != '\n' && save >= 0){
                                        saveback[k] = zap[save];
                                        save--;
                                        k++;
                                    }
                                    //printf("%s:" , address);
                                    for(int n = k-1 ; n >= 0 ; n--){
                                        //printf("%c" , saveback[n]);
                                        zapp[index] = saveback[n];
                                        index++;
                                    }
                                    k = 0;
                                    while(zap[save2] != '\n' && save2 != strlen(saveforward)){
                                        saveforward[k] = zap[save2];
                                        save2++;
                                        k++;
                                    }
                                    for(int n = 1 ; n < strlen(saveforward) ; n++){
                                        //printf("%c" , saveforward[n]);
                                        zapp[index] = saveforward[n];
                                        index++;
                                    }
                                    for(int n = index ; n < 100 ; n++){
                                        zapp[n] = 0;
                                    }
                                    //printf("\n");
                                    j = 0;
                                }
                            }
                            else{
                                j = 0;
                            }
                        }
                    }
                    enter = getchar();
                }
            }
            else if(strcmp(op , c) == 0){
                char pattern[20];
                char pat[200];
                int times = 0;
                scanf("%s %s %s" ,garbage , pattern , garbage);
                for(int i = 0 ; i < strlen(pattern) ; i++){
                    pat[i] = pattern[i];
                }
                char enter = getchar();
                while(enter != '\n'){
                    char address[50];
                    scanf("%s" , address);
                    for(int i = 0 ; i < 49 ; i++){
                        address[i] = address[i+1];
                    }
                    FILE* fptr;
                    if(!(fptr = fopen(address , "r"))){
                        printf("Not exist!");
                        return 0;
                    }
                    else{
                        char ch;
                        char zap[100];
                        for(int i = 0 ; i < 100 ; i++){
                            zap[i] = 0;
                        }
                        int i = 0;
                        fptr = fopen(address , "r");
                        while((ch = fgetc(fptr)) != EOF){
                            zap[i] = ch;
                        i++;
                        }
                        fclose(fptr);
                        int j = 0;
                        for(int i = 0 ; i < 100 ; i++){
                            if(zap[i] == pat[j]){
                                j++;
                                if(j == strlen(pat)){
                                    times++;
                                    j = 0;
                                }
                            }
                            else{
                                j = 0;
                            }
                        }
                    }
                    enter = getchar();
                }
                //printf("%d" , times);
            }
            else if(strcmp(op , l) == 0){
                char pattern[20];
                char pat[200];
                int times = 0;
                scanf("%s %s %s" ,garbage , pattern , garbage);
                char enter = getchar();
                for(int i = 0 ; i < strlen(pattern) ; i++){
                    pat[i] = pattern[i];
                }
                while(enter != '\n'){
                    char address[50];
                    scanf("%s" , address);
                    for(int i = 0 ; i < 49 ; i++){
                        address[i] = address[i+1];
                    }
                    FILE* fptr;
                    if(!(fptr = fopen(address , "r"))){
                        printf("Not exist!");
                        return 0;
                    }
                    else{
                        char ch;
                        char zap[100];
                        for(int i = 0 ; i < 100 ; i++){
                            zap[i] = 0;
                        }
                        int i = 0;
                        fptr = fopen(address , "r");
                        while((ch = fgetc(fptr)) != EOF){
                            zap[i] = ch;
                        i++;
                        }
                        fclose(fptr);
                        int j = 0;
                        for(int i = 0 ; i < 100 ; i++){
                            if(zap[i] == pat[j]){
                                j++;
                                if(j == strlen(pat)){
                                    times++;
                                    j = 0;
                                    int m = 0;
                                    //printf("%s\n" , address);
                                    for(int k = 0 ; k < strlen(address) ; k++){
                                        zapp[m] = address[k];
                                        m++;
                                    }
                                    zapp[m] = '\n';
                                }
                            }
                            else{
                                j = 0;
                            }
                        }
                    }
                    enter = getchar();
                }
            }
        }
        scanf("%s %s" , garbage , request3);
        if(strcmp(request3 , insert) == 0){
            char address[50];
            scanf(" %s%s" , garbage ,address);
            for(int i = 0 ; i < 49 ; i++){
                address[i] = address[i+1];
            }
            FILE* fptr;
            if(!(fptr = fopen(address , "r"))){
                printf("file does not exist");
                fclose(fptr);
                return 0;
            }
            else{
                fptr = fopen(address , "w");
                fprintf(fptr , "%s" , zapp);
                fclose(fptr);
            }
        }
    }
    return 0;
}
