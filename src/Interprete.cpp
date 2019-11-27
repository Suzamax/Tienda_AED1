#include "Interprete.h"

Interprete::Interprete(DiccP *dic) { dp = dic; }

Interprete::~Interprete() {}

void Interprete::getCmd(string cmd)
{
    if (cmd == "insertar") pInsertar();
    if (cmd == "palabras") pPalabras();
    if (cmd == "precios") pPrecios();
    if (cmd == "eliminar") pEliminar();
    if (cmd == "producto") pProducto();
}

void Interprete::pInsertar()
{
    Producto *p = new Producto();
    p->leer();
    dp->insertar(p);
}

void Interprete::pPrecios()
{
    double min, max;
    cin >> min;
    cin >> max;
    dp->precios(min, max);
}

void Interprete::pPalabras() {
    string s;
    cin >> s;
    cout << "palabras " << s << endl;
    int i = 0;
    s = Utilidades::tolow(s);
    TablaHash *tabla = dp->getTabla();
    Par<Producto*> *par = tabla->consultar(Utilidades::FNV(s, tabla->getMax()), s);
    if (par)
    {
        list<Producto*> l = *par->getList();
        i = Utilidades::Mostrar(l);
    }
   cout << "Total: " << i << " productos" << endl;
}

void Interprete::pProducto()
{
    unsigned long id;
    cin >> id;
    dp->producto(id);
}

void Interprete::pEliminar()
{
    unsigned long id;
    cin >> id;
    dp->eliminar(id);
}
