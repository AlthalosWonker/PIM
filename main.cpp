#include <iostream>// Biblioteca para leitura e gravação de variaveis
#include <string.h>// Biblioteca para manipular variaveis tipo string
#include <locale.h>// Biblioteca necessária para criação da Struct
#include <fstream> // Biblioteca para importar arquivo para o Txt
#include <bits/stdc++.h>
#define TAM 100
using namespace std;

//==================VARIAVEIS GLOBAIS ================
int i,existe;// declara variavel do tipo inteiro i e existe
string Linha,i_scr, candidatonum="n"; // declara variavel tipo string Linha, i_scr candidatonum com valor definido inicialmente em n
char senha[100]; //define variavel senha e seu tamanho max
char senhaMaster[50] = "academicorh"; //define variavel senhaMaster e seu valor
int main(); //Declara o metodo main para uso em qualquer lugar do codigo
void menuCd(), menuRh(); //Declara as funções menuRh e menuCd para uso em qualquer lugar do codigo

// ==================== STRUCT ====================
struct InfVaga{ //Estrutura para as vagas
	string Cargo;
	string Descricao;
	string Competencias;
	string Periodo;
	int AnoExperiencia;
	float Salario;

}pos[TAM];

struct InfCadidato{ //Estrutura para o candidato
    string Nome;
    string Cpf;
    string email;
    char senha[100];
    char sexo;
    string nivelescola;
    string uf;
    string rua;
    string bairro;
    string cidade;
    string competencias;

}cd[TAM];

//=======================RH========================

//=====================LIMPA VAGAS=====================

void ApagaTudo(void){ //Função para limpeza de todos os txt alteraveis em codigo
    char op;
    fstream Limpa; //Cria variavel do tipo arquivo nomeada Limpa
    string txt [4] = {"Cadastro.txt"\
                     ,"Candidato.txt"\
                     ,"EscolhaVaga.txt"\
                     ,"login.txt"\
                     }; //Armazena os nomes dos arquivos gerados em codigos para limpeza

    for(int i=0; i<=3; i++){ //for para limpar todos os arquivos
        Limpa.open(txt[i], ios::out); //instacia arquivo nomeado
        if(Limpa.is_open())//verificar se arquivo abriu
        {
            Limpa.close();//fecha arquivo
            op='p';//salva op como p
        }
        else{//se arquivo não abrir retorna mensagem abaixo
            cout << "ERRO! Não foi possível limpar o arquivo"<<txt[i];
            cout << "Deseja tentar novamente?\n Se sim digite 's' \nSe não 'n'\nOpção: ";
            cin >> op;
            if(op=='s'){//caso op seja s, executa função novamente
                ApagaTudo();
            }else if(op=='n'){ // caso seja n, volta ao menu
                menuRh();
            }else{cout<<"ERRO NA EXECUÇÃO!";}//caso seja diferente retorna erro
        }
    }
    if(op=='p'){
    cout << "\n_________Todos os dados foram limpos__________\n";//após limpar os arquivos retorna aviso
    system("pause");//aguarda usuario
    menuRh();//retorna menuRh
    }else{cout<<"ERRO NA EXECUÇÃO!";}
}

//===VERIFICAR QUAL O NÚMERO DA ÚLTIMA VAGA SALVA=====

int QualUltimoNumeroCargo(void){//Verifica e retorna o ultimo codigo dos cargos

    ifstream UltimoNumero; //Cria variavel do tipo arquivo nomeada Limpa
    UltimoNumero.open("Cadastro.txt");//Abre arquivo Cadastro.txt
    i=0;//declara que i é igual a 0

    if(UltimoNumero.is_open())//Verifica se arquivo abriu
    {
        while(getline(UltimoNumero,Linha)) //Inicia laço de repetição com condição de rodar as linhas do arquivo aberto e armazenar em variavel Linha
        {
            i_scr = "Cargo." + to_string(i);//Concatena valor para a variavel i_scr
            if(Linha == i_scr) //Verifica se Linha é igual a i_sct
                i++;//Caso seja igual i incrementa 1
        }
        UltimoNumero.close();//Fecha arquivo
        return i;//retorna valor de i, que representa o ultimo codigo do cargo
    }
    else//caso arquivo não abra
    {
        UltimoNumero.close();//fecha arquivo
        return i=0;//retorna que o codigo é 0
    }
}

//==================FUNÇÃO PARA CADASTRAR =============
void CadastrandoVaga(void){//Função para cadastrar vaga

	int cod=0;//cria variavel cod do tipo inteiro
	char continuar;//cria variavel de texto nomeada de continuar
	ofstream vaga;//Cria variavel do tipo arquivo nomeada vaga
	QualUltimoNumeroCargo();//Executa função para descobrir o ultimo codigo dos cargos
	vaga.open("Cadastro.txt", ios::app);//Abre arquivo Cadastro.txt
    system("cls");//Limpa tela
	do{//Incia laço de repetição para cadastro da vaga
       //Objetivo é salvar as informações das vagas com base no seu Struct
		system ("cls");//limpa
		cout<<"________ACADEMICO RH________\
         \n_____TRABALHE CONOSOCO______\n\n\n";
		cout<<"_______CADASTRO DE CARGO___________";

		cout << "\n\nDigite o nome do cargo: " << endl;
	    fflush(stdin);//Faz limpeza do buffer
	    getline(cin, pos[i].Cargo);//Salva valor da linha preenchida no buffer
	    vaga << "Cargo." << i <<"\n" << pos[i].Cargo << "\n";//salva valor do codigo e nome da vaga


	    cout << "\nDigite breve descrição da vaga: " << endl;
	    fflush(stdin);
	    getline(cin, pos[i].Descricao);
	    vaga << pos[i].Descricao << "\n" ;


		cout<<"\nQuantos anos de experiência é exigido: ";
		cin>>pos[i].AnoExperiencia;
		vaga << pos[i].AnoExperiencia << "\n";

		cout<<"\nQual o salario oferecido R$ ";
		cin>>pos[i].Salario;
		vaga << pos[i].Salario << "\n";


		cout<<"\nQUAIS AS COMPETENCIAS EXIGIDAS:";
		fflush(stdin);
		getline(cin, pos[i].Competencias);
	    vaga << pos[i].Competencias << "\n" ;

		cout<<"\n\n__ESCOLHA O PERÍODO DA VAGA__";
		cout<<"\n[0]Matutino ; [1]Vespertino ; [2]Noturno";
		do{//inicia laço de reptição para impedir caracter invalido
			cout<<"\nDigite o código do periodo:";
			cin>>cod;
			switch (cod)
			{
				case 0:
					pos[i].Periodo ="Matutino";
					vaga << pos[i].Periodo << "\n";
					break;
				case 1:
					pos[i].Periodo = "Vespertino";
					vaga << pos[i].Periodo << "\n";
					 break;
				case 2:
					pos[i].Periodo = "Noturno";
					vaga << pos[i].Periodo << "\n";
					break;
				default:
					cout<<"ERRO! DIGITE O CÓDIGO CORRETO";
					cod=4;
			}
		}while(cod == 4);//caso caracter informado esteja fora do escopo, repete laço
		cout<<("\n\nDeseja cadastrar mais uma vaga? \n Se sim digite 's' \n Se não 'n'") << endl;
		cin>>continuar;
		i++;
	}while((continuar == 's' || continuar == 'S') && i<=100);//continua executatndo se usuario responder s e as vagas criadas forem menos que 100
	vaga.close();//fecha arquivo
	fflush(stdin);//Limpa buffer
	menuRh();//Vai para menuRh;
}

//=================LISTA DE VAGAS CADASTRADAS=================

void ListaVaga(void){ //Lista vagas salvas
	ifstream ListaV;
	int n,ProximaLinha;
	ListaV.open("Cadastro.txt");
    system("cls");
    cout<<"________ACADEMICO RH________\
         \n_____TRABALHE CONOSOCO______\n\n\n";
	cout << "_________LISTA DE VAGAS CADASTRADAS___________\n\n";

	if(ListaV.is_open())
	{
		n=0;
		i=0;
		while(getline(ListaV,Linha))
		{
		    i_scr = "Cargo." + to_string(i);
            if(Linha == i_scr )
            {
				ProximaLinha = n + 1;
				i++;
            }
			else
            {
				if(ProximaLinha == n)
					{
					cout << "Cargo." << i-1 <<": " << Linha << "\n";
					ProximaLinha = 0;
					}
            }
         n++;
		}
		ListaV.close();
	}
	else
		{
		cout << "ERRO!! Não foi possível abrir o arquivo";
		}
    fflush(stdin);
    system("pause");
    if(candidatonum=="n"){
    menuRh();
    }else{
        menuCd();
    }
}

//======================DADOS VAGA=====================

void BuscaVaga(void){ //Busca vagas pelo codigo
    ifstream Busca;
    Busca.open("Cadastro.txt");
    int Cargo;
    string ProximoCargo;
    string Impressao [8] = {""\
                            ,"Nome do cargo.........."\
                            ,"Descrição.............."\
                            ,"Anos de experiência...."\
                            ,"Salário................"\
                            ,"Competências..........."\
                            ,"Período................"\
                            };//determina layout de exibição dos dados

    system("cls");
    cout<<"__________ACADEMICO RH__________\
         \n_______TRABALHE CONOSOCO________\n\n\n";
    cout<<"_______VAGAS CADASTRADAS________\n\n";
    cout << "Digite o número do Cargo o qual deseja buscar :";
    cin >> Cargo;
    cout << "\n";

    i_scr = "Cargo." + to_string(Cargo);
    ProximoCargo = "Cargo." + to_string(Cargo + 1);
    i = 0;

    if(Busca.is_open())
    {
        while(getline(Busca,Linha))
        {
            if(Linha == i_scr)
                i_scr = "1";//determina q i_scr é 1
            if(i_scr == "1" && Linha != ProximoCargo) //se for 1 e linha for difernete de cargo faz
            {
                cout << Impressao[i] << Linha << "\n";//concatena valor com a formação, cada linha é uma posição do vetor
                i++;
            }
            else//se if for false
            {
                if(i_scr == "1")//se i_scr é igual 1
                    i_scr = "0";//salva como 0

            }
        }
        if(i == 0)// se i for igual a 0, vaga não está na lista
        {
            cout << "_____Vaga não encontrada!!!_____\n";
        }
        Busca.close();

        system("pause");

        if(candidatonum=="n"){//caso candidato for igual a n, usuario é rh
            menuRh();
        }else{//caso contrario é candidato
            menuCd();
            }
    }
    else
    {
        cout << "ERRO! Não foi possível abrir o arquivo";
    }

}

//==============LISTAR CANDIDATOS===============

void ListaCandidato(){//Listar cadidatos salvos - Repete função ListaVaga, apenas muda arquivo
ifstream ListaV;
	int n,ProximaLinha;
	ListaV.open("Candidato.txt");
    system("cls");
    cout<<"__________ACADEMICO RH__________\
         \n_______TRABALHE CONOSOCO________\n\n\n";
	cout<<"_____CANDIDATOS CADASTRADOS_____\n\n";

	if(ListaV.is_open())
	{
		n=0;
		i=0;
		while(getline(ListaV,Linha))
		{
		    i_scr = "Candidato." + to_string(i);
            if(Linha == i_scr )
            {
				ProximaLinha = n + 1;
				i++;
            }
			else
            {
				if(ProximaLinha == n)
					{
					cout << "Candidato." << i-1 <<": " << Linha << "\n";
					ProximaLinha = 0;
					}
            }
         n++;
		}
		ListaV.close();
	}
	else
		{
		cout << "ERRO!! Não foi possível abrir o arquivo";
		}
    fflush(stdin);
    system("pause");
    menuRh();
}

//==============DADOS CANDIDATOS==================
void BuscaCandidato(void){//Buscar candidado pelo codigos - Repete função BuscaVaga, apenas muda arquivo e layout, tb permite que o candidato olhe seus dados
    ifstream Busca;
    Busca.open("Candidato.txt");
    int Candidato;
    string ProximoCandidato;
    string Impressao [12] = {""\
                            ,"Nome do Candidato....."\
                            ,"CPF..................."\
                            ,"e-mail................"\
                            ,"Sexo.................."\
                            ,"Nivel Escolar........."\
                            ,"UF...................."\
                            ,"Rua..................."\
                            ,"Bairro................"\
                            ,"Cidade................"\
                            ,"Competencias.........."\
                            };
    system("cls");
    cout<<"__________ACADEMICO RH__________\
         \n_______TRABALHE CONOSOCO________\n\n\n";
    cout<<"___INFORMAÇÕES DE CANDIDATOS____\n\n";
    cout << "Digite o número do Candidato o qual deseja buscar :";
    cin >> Candidato;
    cout << "\n";

    i_scr = "Candidato." + to_string(Candidato);
    ProximoCandidato = "Candidato." + to_string(Candidato + 1);
    i = 0;

    if(Busca.is_open())
    {
        while(getline(Busca,Linha))
        {
            if(Linha == i_scr)
                i_scr = "1";
            if(i_scr == "1" && Linha != ProximoCandidato)
            {
                cout << Impressao[i] << Linha << "\n";
                i++;
            }
            else
            {
                if(i_scr == "1")
                    i_scr = "0";

            }
        }
        fflush(stdin);

        Busca.close();

        system("pause");
        if(candidatonum=="n"){
            menuRh();
        }else{
            menuCd();
            }
    }
    else
    {
        cout << "ERRO! Não foi possível abrir o arquivo";
    }

}

//=================CONSULTAR VAGAS DO CANDIDATO=========

void ConsultaCandidato(){//Função para rh ver as vagas que candidatos escolheram
    ifstream Lista;
	int i,ProximaLinha,codcand;
	string temp,cargo,cand;
	Lista.open("EscolhaVaga.txt");
    system("cls");
    cout<<"__________ACADEMICO RH__________\
         \n_______TRABALHE CONOSOCO________\n\n\n";
	cout<<"____LISTA DE VAGAS ESCOLHIDAS___\n\n";

    cout<<"Informe o Codigo do Candidato: ";
    cin>>codcand;
    cand="Candidato."+to_string(codcand);//Salva informação do candidato para consulta
	if(Lista.is_open())
	{
		while(getline(Lista,Linha)){//inicia laço de repetição para verificação de linha
            temp=""; //limpa variavel
            cargo=""; //limpa variavel
            for (i=0; i<Linha.size();i++){//inicia laço de repetição para verificação de caracter
                if(Linha[i] != '-'){//verifica se caracter é diferente de -, delimitador usado para salvar vagas
                    temp = temp + Linha[i]; //salva 1 caracter por vez ate achar o -
                }else{
                    break;//caso if retorne false, fecha laço
                }
            }if(temp==cand){//verifica se variavel temp é igual a variavel cand
                for(i=i+1; i<Linha.size();i++){//retoma laço a partir do -
                    cargo = cargo + Linha[i];//salva cargo na variavel cargo,caracter por caracter
                }
                cout<<cargo<<"\n";//exibe cargo escolhido pelo candidato
            }
		}
		Lista.close();//fecha arquivo
	}
	else
		{
		cout << "ERRO!! Não foi possível abrir o arquivo";
		}
    fflush(stdin);
    cout<<endl;
    system("pause");
    menuRh();//volta para o menuRh
}

//==============MENU RH=============
void menuRh(){
    int escolha=0;
    char op;
    system("cls");
    cout<<"__________ACADEMICO RH__________\
         \n_______TRABALHE CONOSOCO________\n\n\n";
    cout<<"______________RH_______________\n";
    cout<<"1 - Cadastrar vaga\
         \n2 - Listar vagas\
         \n3 - Buscar vaga\
         \n4 - Listar candidatos cadastrados\
         \n5 - Buscar dados do candidato\
         \n6 - Ver escolhas dos candidatos\
         \n7 - Limpar todos os dados salvos\
         \n0 - Voltar Inicio\
         \nOpção: ";
	cin>>escolha;
	switch(escolha){//determina qual função executar com base na escolha do usuario
	    case 1:
            CadastrandoVaga(); //acessa função CadastrandoVaga
            break;
        case 2:
            ListaVaga(); //acessa função ListaVaga
            break;
        case 3:
            BuscaVaga(); //acessa função  BuscaVaga
            break;
        case 4:
            ListaCandidato(); //acessa função  ListaCandidato
            break;
        case 5:
            BuscaCandidato(); //acessa função BuscaCandidato
            break;
        case 6:
            ConsultaCandidato(); //acessa função ConsultaCandidato
            break;
        case 7:
            cout<<"AVISO - ESTÁ AÇÃO IRÁ APAGAR TODOS OS DADOS SALVOS\nSe sim digite 's' \nSe não 'n'\nOpção: ";
            cin>>op;
            if(op=='s'){
                ApagaTudo(); //acessa função ConsultaCandidato
            }else if(op=='n'){
                menuRh(); //retorna menuRh
            }else{cout<<"ERRO DE EXECUÇÃO!";}
            break;
        case 0:
            main(); //Volta para o Main
            break;
        default:
            cout<<"ERRO DE EXECUÇÃO!";//caso n esteja no escopo retorna erro
	}
}

//=================CANDIDATO=====================

//=================VALIDAR EMAIL JA CADASTRADO============
int validaEmail(string valor){//recebe valor como paramentro, valor representaria email de login
    ifstream Login;
    existe = 0;
    Login.open("login.txt");
    if(Login.is_open())
    {
        while(getline(Login,Linha))
        {
            if(Linha == valor)//verifica se valor é igual a linha que representa o email
            existe=1;//salva 1 na variavel existe
        }
        Login.close();//fecha arquivo
        return existe;//retorna valor inteiro = 1 para função
    }
    else
    {
        Login.close();//fecha arquiv
        return existe=0;//retorna valor inteiro = 0 para função
    }
}


//=================VALIDAR LOGIN CORRETO============

string validaLogin(string email, string senha){//recebe como paramento email e senha para validação
    ifstream Login;
    string candidatonum = "n";
    int user=0;
    string ProximoCandidato;
    string Impressao [4] = { "Email.........."\
                            ,"Senha.........."\
                            ,""\
                            };
    Login.open("login.txt");
    i_scr = email;
    ProximoCandidato = "Candidato." + to_string(user+1);
    i = 0;

    if(Login.is_open())
    {
        while(getline(Login,Linha))
        {
            if(Linha == i_scr)//Verifica se a linha é igual ao email enviado
                i_scr = "1";
            if(i_scr == "1" && Linha != ProximoCandidato)//se a linha for igual ao email faz
            {
                Impressao[i] = Linha;//salva linha na posição de i
                i++;// acrescenta i em 1
            }
            else
            {
                if(i_scr == "1")
                   i_scr = "0"; //zera valor de i_scr caso de erro

            }
        }if(Impressao[1]==senha){//verifica se a senha está certa
            return candidatonum = Impressao[2];//retorna o numero do candidato
        }else{
                return candidatonum="n";//se não estiver certa a senha, retorna q candidatonum = n
            }


        Login.close();//fecha arquivo
    }
    else
    {
        cout << "ERRO! Não foi possível abrir o arquivo";
    }
}


//=================PEGA NUMERO ULTIMO CANDIDATO============

int QualUltimoNumeroCandidato(void){//Executa função igual QualUltimoNumeroCargo, so muda arquivo e valor de i_scr

    ifstream UltimoNumero;
    UltimoNumero.open("Candidato.txt");
    i=0;

    if(UltimoNumero.is_open())
    {
        while(getline(UltimoNumero,Linha))
        {
            i_scr = "Candidato." + to_string(i);
            if(Linha == i_scr)
                i++;
        }
        UltimoNumero.close();
        return i;
    }
    else
    {
        UltimoNumero.close();
        return i=0;
    }
}

//=================CRIAR CANDIDATO============

void CadastrarCandidato(){ //Executa função semelhante a CadastrandoVaga, porem se adequando ao struct do candidato
    QualUltimoNumeroCandidato();
    int cod=0;
	ofstream Candidato, Login;
	Candidato.open("Candidato.txt", ios::app);
	Login.open("login.txt", ios::app);
    	system ("cls");
    	cout<<"__________ACADEMICO RH__________\
             \n_______TRABALHE CONOSOCO________\n\n\n";
		cout<<"______CADASTRO DE CANDIDATO_____\n";
		cout << "\n\nDigite o seu nome: " << endl;
	    fflush(stdin);
	    getline(cin, cd[i].Nome);
	    Candidato << "Candidato." << i <<"\n" << cd[i].Nome << "\n";


	    cout << "\n\nDigite o seu CPF (APENAS NÚMEROS): " << endl;
	    fflush(stdin);
	    getline(cin, cd[i].Cpf);
	    Candidato << cd[i].Cpf << "\n";

	    cout << "\n\nDigite o seu email: " << endl;
	    fflush(stdin);
	    cin>> cd[i].email;
	    Candidato << cd[i].email <<"\n";
	    Login<<cd[i].email <<"\n";

	    int valor = validaEmail(cd[i].email);
	    if(valor == 1){
            cout<<"Email já cadastrado";
            fflush(stdin);
            getchar();
            CadastrarCandidato();
	    }else
        cout << "\n\nDigite a sua senha: " << endl;
	    fflush(stdin);
	    cin>>cd[i].senha;
	    char crip[100] ="";//gera variavel char de tamanho 100
	    for(int a=0; a<=strlen(cd[i].senha);a++){ //executa criptografia de cesar para salvar senha
            crip[a] = cd[i].senha[a] + 5;
	    }
        Login << crip<<"\n";//salva senha no arquivo login.txt
        Login<<"Candidato." << i <<"\n";//salva candidato
        do{cout<< "\n\nInforme seu sexo: [F ou M] "<<endl;
            fflush(stdin);
            cin>>cd[i].sexo;
        }while((cd[i].sexo!='m')&&(cd[i].sexo!='f'));
        Candidato<<cd[i].sexo<<"\n";

        do{cout<<"\n\nInforme seu nivel escolar: \
            \n0 - Fundamental Incompleto\
            \n1 - Fundamental 1 completo\
            \n2 - Fundamental 2 completo\
            \n3 - Médio incompleto\
            \n4 - Médio completo\
            \n5 - Superior Incompleto\
            \n6 - Superior completo"<<endl;
			cin>>cod;
			switch (cod)
			{
				case 0:
					cd[i].nivelescola ="Fundamental Incompleto";
					Candidato << cd[i].nivelescola << "\n";
					break;
				case 1:
					cd[i].nivelescola ="Fundamental 1 completo";
					Candidato << cd[i].nivelescola << "\n";
					 break;
				case 2:
					cd[i].nivelescola ="Fundamental 2 completo";
					Candidato << cd[i].nivelescola << "\n";
					break;
                case 3:
					cd[i].nivelescola ="Médio incompleto";
					Candidato << cd[i].nivelescola << "\n";
					break;
                case 4:
					cd[i].nivelescola ="Médio completo";
					Candidato << cd[i].nivelescola << "\n";
					break;
                case 5:
					cd[i].nivelescola ="Superior Incompleto";
					Candidato << cd[i].nivelescola << "\n";
					break;
                case 6:
					cd[i].nivelescola ="Superior completo";
					Candidato << cd[i].nivelescola << "\n";
					break;
				default:
					cout<<"ERRO! DIGITE O CÓDIGO CORRETO";
					cod=99;
			}
		}while(cod == 99);

		cout << "\n\nDigite o UF: " << endl;
	    fflush(stdin);
	    getline(cin, cd[i].uf);
	    Candidato << cd[i].uf <<"\n";

	    cout << "\n\nDigite sua rua: " << endl;
	    fflush(stdin);
	    getline(cin, cd[i].rua);
	    Candidato << cd[i].rua <<"\n";

	    cout << "\n\nDigite seu Bairro: " << endl;
	    fflush(stdin);
	    getline(cin, cd[i].bairro);
	    Candidato << cd[i].bairro <<"\n";

	    cout << "\n\nDigite sua Cidade: " << endl;
	    fflush(stdin);
	    getline(cin, cd[i].cidade );
	    Candidato << cd[i].cidade <<"\n";

	    cout << "\n\nDigite suas competencias: " << endl;
	    fflush(stdin);
	    getline(cin, cd[i].competencias);
	    Candidato << cd[i].competencias <<"\n";
	    Candidato.close();
	    Login.close();
	    cout<<"CADASTRO REALIZADO COM SUCESSO!\n";
        system("pause");
	    main();

}


//=================CANDIDATO ESCOLHE VAGA============

void EscolheVaga(){//Função para candidatos escolherem vagas
    QualUltimoNumeroCargo();
    int escolha=0,valida=0,tamanhoCargo=0,tamanhoCD=0, achouCargo=0;
    string escolhida, cargo, candidato;
    ofstream EscolhaVaga;
    ifstream Cargo,LerVaga;
    system("cls");
    EscolhaVaga.open("EscolhaVaga.txt", ios::app);
    LerVaga.open("EscolhaVaga.txt");
    Cargo.open("Cadastro.txt");
    cout<<"__________ACADEMICO RH__________\
         \n_______TRABALHE CONOSOCO________\n\n\n";
    cout<<"_________ESCOLHA VAGA___________\n";
    cout<<"\nDigite o codigo da vaga\n";
    cout<<"Código: ";
    cin>>escolha;

    escolhida = candidatonum + "-" + "Cargo." + to_string(escolha); //salva a vaga escolhida na variavel
    while(LerVaga.eof()){
        tamanhoCD++; //determina tamanho de linhas do arquivo
    }
    while(Cargo.eof()){
        tamanhoCargo++; //determina tamanho de linhas do arquivo
    }
    for(int a=0; a<=tamanhoCargo;a++){//for para procurar o cargo escolhido no arquivo
        while(getline(Cargo,cargo)){
            if(cargo=="Cargo."+to_string(escolha)){
                achouCargo++;//se achar salva mais 1 na variavel
            }
        }
    }
    for(int a=0; a<=tamanhoCD;a++){//for para verificar se a vaga ja foi escolhida pelo usuario
        while(getline(LerVaga,candidato)){
            if(candidato==escolhida){
                valida++;//se achar salva mais 1 na variavel
            }
        }
    }
    if(achouCargo==0){
        cout<<"Código inválido!\n";//caso cargo n exista retorna erro
    }else{
        if(valida!=0){
            cout<<"Você ja escolheu essa vaga!\n";//caso ja tiver escolhido retorna erro
        }else{
            EscolhaVaga<<escolhida<<"\n";//passando das validações, salva no arquivo
            cout<<"Vaga escolhida com sucesso!\n";
        }
    }
    EscolhaVaga.close();
    LerVaga.close();
    Cargo.close();
    system("pause");
    menuCd();

}


//=================VER VAGAS ESCOLHIDAS============

void VerVagasEscolhidas(){//função para mostrar as vagas escolhidas pelo candidato, segue mesmo padrao da ConsultaCandidato
    ifstream Lista;
	int i,ProximaLinha;
	string temp,cargo;
	Lista.open("EscolhaVaga.txt");
    system("cls");
    cout<<"__________ACADEMICO RH__________\
         \n_______TRABALHE CONOSOCO________\n\n\n";
	cout<<"________VAGAS ESCOLHIDAS________\n\n";

	if(Lista.is_open())
	{
		while(getline(Lista,Linha)){
            temp="";
            cargo="";
            for (i=0; i<Linha.size();i++){
                if(Linha[i] != '-'){
                    temp = temp + Linha[i];
                }else{
                    break;
                }
            }if(temp==candidatonum){
                for(i=i+1; i<Linha.size();i++){
                    cargo = cargo + Linha[i];
                }
                cout<<cargo<<"\n";
            }
		}
		Lista.close();
	}
	else
		{
		cout << "ERRO!! Não foi possível abrir o arquivo";
		}
    fflush(stdin);
    cout<<endl;
    system("pause");
    menuCd();
}


//==============MENU CANDIDATO=============

void menuCd(){
    int escolha=0;
    system("cls");
    cout<<"__________ACADEMICO RH__________\
         \n_______TRABALHE CONOSOCO________\n\n\n";
    cout<<"___________CANDIDATO____________\n";
    cout<<"1 - Listar Vagas (Irá exibir todas as vagas cadastradas)\
         \n2 - Escolher Vaga (Irá salvar uma vaga escolhida por você)\
         \n3 - Buscar Vaga(Irá mostrar todos os dados de uma vaga)\
         \n4 - Ver vagas escolhidas\
         \n0 - Voltar Inicio\
         \nOpção: ";
    fflush(stdin);
	cin>>escolha;
	switch(escolha){
	    case 1:
            ListaVaga(); //Executa função ListaVaga
            break;
        case 2:{
            EscolheVaga();} //Executa função EscolheVaga
            break;
        case 3:
            BuscaVaga(); //Executa função BuscaVaga
            break;
        case 4:
            VerVagasEscolhidas(); //Executa função VerVagasEscolhidas
            break;
        case 0:
            main(); //volta para o main
            break;
        default:
            cout<<"ERROR";
	}
}

//==============INICIO DA FUNÇÃO PRINCIPAL=============

int main() {
    int escolha=0,entra=0;
    string login,user;
    char senha[100];
    system("cls");
	setlocale(LC_ALL, "Portuguese");
	system("title Academico RH");
	cout<<"__________ACADEMICO RH__________\
         \n_______TRABALHE CONOSOCO________\n\n\n";
    cout<<"Escolha uma opção para continuar\n";
	cout <<  "1 - RH\
            \n2 - Cadidato\
            \n3 - Cadastrar Candidato\
            \n9 - Sobre nós\
            \n0 - Fechar Programa\
            \nOpção: ";
	cin>>escolha;
	switch(escolha){
	    case 1:
	        do{//inicia laço de repetição ate senha for correta
                system("cls");
                cout<<"__________ACADEMICO RH__________\
                     \n_______TRABALHE CONOSOCO________\n\n\n";
                cout<<"__________LOGIN RH______________";
                cout<<"\nInforme a senha\n";
                fflush(stdin);
                cin>>senha;
                if(strcmp(senha,senhaMaster)==0){//compara string para validação se for igual faz
                    menuRh();
                }else{//se não for retorna erro
                    cout<<"Login Inválido!\n";
                    fflush(stdin);
                    system("pause");
                    entra=0;
                }
	        }while(entra==0);
            break;

        case 2:{
                do{//inicia laço de repetição ate login for correto
                    system("cls");
                    cout<<"__________ACADEMICO RH__________\
                         \n_______TRABALHE CONOSOCO________\n\n\n";
                    cout<<"________LOGIN CANDIDATO_________";
                    cout<<"\nInforme o login\n";
                    fflush(stdin);
                    cin>>login;
                    cout<<"\nInforme a senha\n";
                    fflush(stdin);
                    cin>>senha;
                    char crip[100] ="";
                    for(int a=0; a<=strlen(senha);a++){ //criptografa a senha na cifra de cesar
                        crip[a] = senha[a] + 5;
                    }candidatonum=validaLogin(login,crip);//usa a função validalogin para analisar se os dados estão corretos
                    if(candidatonum!="n"){//se estiverem inicia menu
                        menuCd();
                    }else{//senão, retorna erro
                        cout<<"Login Inválido!\n";
                        system("pause");
                        entra=0;
                        }
                }while(entra==0);
            }break;

        case 3:
            CadastrarCandidato();//Inicia função CadastrarCandidato
            break;
        case 9:{ //abre arquivo salvo para exibição dos creditos do projeto
            system("cls");
            ifstream sobrenos;
            sobrenos.open("sobrenos.txt");
            while(!sobrenos.eof()){
                getline(sobrenos,Linha);
                cout<<Linha<<endl;
            }
            sobrenos.close();
            }
            fflush(stdin);
            system("pause");
            main();
            break;
        case 0: //fecha programa
            cout<<"Obrigado pela preferência!";
            exit(1);
            return 1;
        default:
            cout<<"ERROR";
	}

	return 0;
}

