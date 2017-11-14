#include <QCoreApplication>
#include <QByteArray>
#include <QDebug>
    void pegaEpassa(QByteArray ba);
QByteArray pacote = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ-0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QByteArray bloco;
    bloco = pacote;

    // qDebug() <<   <<endl<<endl;

    pegaEpassa(bloco);

    return a.exec();
}
///SUPONHA QUE o pacote original tenha 10 vezes 8192.
/// então quando passarmos o pacote como parametro teremos que corta-lo e comparar novamente.
/// se continuar então essa função faz chamada a si mesma enquanto for preciso.
void pegaEpassa(QByteArray ba)
{
    if(ba.size() >=55  )///sabemos que vai ser maior do que o permitido
                        ///então descobrimos o tamanho real dela, o quanto maior é do máximo permitido
    {                                        //pega o tamanho atual do pacote e subitrai do máximo permitido.
        int comparaTamanho = ba.size() - 55 ;//estamos descobrindo o tamanho do pacote 62-55=7

        /// SE for maior que o permitido temos que fazer novamente esse processo.
        if( comparaTamanho > 55)//tem mais conteudo maior do que o permitido?
        {
            QByteArray bloco2;

            bloco2 = ba; //ba ainda tem o tamnanho original, e pode ser que seja maior que 55 mas não menor que isso.
/** graficamente temos:
 *         ( 0|1|2|.........................|55 ) |56| ....
 * bloco2 [( MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM ) MMMMMMMMMMMMMMMMMMMMMMMM...]   contem o valor original
 * bloco2.remove(0,  55) REMOVE A PRIMEIRA PARTE, DEIXANDO O RESTANTE AQUI DENTRO.
 * bloco2 [ MMMMMMMMMMMMMMMMMMMMMMMM...]
 *
 * ba [( MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM ) MMMMMMMMMMMMMMMMMMMMMMMM...]    contem o valor original do parametro.
 * ba.resize(55)        guarda apenas o que está dentro dos parenteses
 * ba [(MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM)]
 *
 */
            bloco2.remove(0, 55);       ///removemos o tamanho da parte original
            ba.resize(55);              ///redefinir o tamanho da parte original para o tamanho máximo permitido.

            qDebug() <<"variavel:" << ba <<endl <<endl;    //      fazEnvio(ba);               ///FUNÇÃO MODULADAR DO ENVIO E LEITURA DOS DADOS.

            pegaEpassa(bloco2);         ///recursividade. porque sabemos q o bloco2 ainda precisa ser tratado.
        }else{//se menor que o máximo permitido no segundo momento
            QByteArray bloco3;
            bloco3 = ba;            ///copiamos o valor integral do parametro da função.

            bloco3.remove(0,55);    //remove a parte do parametro

            ba.resize(55);          ///redimensiona com certeza do tamanho o parametro.
                    qDebug() <<"variavel:" << ba <<endl <<endl;//fazEnvio(ba);
                   qDebug() <<"variavel b3:" << bloco3 <<endl <<endl;// fazEnvio(bloco3);
        }
    }//se menor que o máximo permitido.
    else
    {
        //escreve no connect pq ba agora é menor que o máximo permitido.
        qDebug() <<"variavel:" << ba <<endl <<endl;    //       fazEnvio(ba);
    }
}
