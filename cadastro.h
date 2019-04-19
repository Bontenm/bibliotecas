#ifndef cadastro_h
#define cadastro_h

void cadastroNave(infoNave *In){
    In = (infoNave*) malloc(sizeof(infoNave));

    In->prefixo = (char*) malloc(sizeof(char)*100);
    scanf("%[^\n]%*c", In->prefixo);
    printf("prefixo: %s\n", In->prefixo);

    In->aeronave = (char*) malloc (sizeof(char)*100);
    scanf("%[^\n]%*c", In->aeronave);
    printf("aeronave: %s\n", In->aeronave);
}

void cadastroPessoa(infoPessoa *Ip){
    Ip = (infoPessoa*) malloc(sizeof(infoPessoa));

    Ip->NomePrograma = (char*) malloc(100*sizeof(char));
        fflush(stdin);
        scanf("%[^\n]%*c",Ip->NomePrograma);
        printf("Nome Do Programa = %s\n", Ip->NomePrograma);
    
    Ip->NomePessoa = (char*) malloc(100*sizeof(char));
        fflush(stdin);
        scanf("%[^\n]%*c", Ip->NomePessoa);
        printf("Nome da Pessoa = %s\n", Ip->NomePessoa);

    Ip->CPF = (char*) malloc(100*sizeof(char));
        fflush(stdin);
        scanf("%[^\n]%*c", Ip->CPF);
        printf("CPF = %s\n", Ip->CPF);

    Ip->Categoria = (char*) malloc(100*sizeof(char));
        fflush(stdin);
        scanf("%[^\n]%*c",Ip->Categoria);
        printf("Categoria = %s\n", Ip->Categoria);      

    fflush(stdin);
    scanf("%lf", Ip->SaldoMilhas);
    printf("Saldo Milhas = %.2lf\n", Ip->SaldoMilhas);
}

int valida_horario(int *hora, int *minuto){
    int aux1,aux2;
    aux1 = *hora;
    aux2 = *minuto;

    while( (aux1<0 || aux1>23) || (aux2<0 || aux2>59) ){
        printf("Horario invalido, insira outro:\n");
        scanf("%d%*c%d", &aux1, &aux2);
    }
    *hora = aux1;
    *minuto = aux2;
    return 0;
}

void cadastroVoo(infoAero *Ia){
    Ia = (infoAero*) malloc(sizeof(infoAero));
    Ia->aerOri = (char*) malloc(sizeof(char)*10);
    Ia->aeroDest = (char*) malloc(sizeof(char)*10);

    scanf("%[^\n]%*c", Ia->aerOri);
    scanf("%[^\n]%*c", Ia->siglaOri);
    printf("sigla = %s\n", Ia->siglaOri);

    scanf("%[^\n]%*c", Ia->aeroDest);
    scanf("%[^\n]%*c", Ia->siglaDest);
    printf("sigla = %s\n", Ia->siglaDest);

    int horaChegada = 0, horaPartida = 0;
    int minutoChegada = 0, minutoPartida = 0;
    
    scanf("%d%*c%d", &horaPartida, &minutoPartida);
    valida_horario(&horaPartida, &minutoPartida);
    printf("hora da partida = %d:%d\n", horaPartida, minutoPartida);

    scanf("%d%*c%d", &horaChegada, &minutoChegada);
    valida_horario(&horaChegada, &minutoChegada);
    printf("hora da chegada = %d:%d\n", horaChegada, minutoChegada);
}

#endif