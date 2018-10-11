#include "clientes.h"
#include "publicaciones.h"

int masActivos (eCliente* clientes, int tam_clientes, ePublicacion* publicaciones,int tam_publicaciones);
int masPausados (eCliente* clientes, int tam_clientes, ePublicacion* publicaciones,int tam_publicaciones);
int masPublicaciones (eCliente* clientes, int tam_clientes, ePublicacion* publicaciones,int tam_publicaciones);
void mostrarPorRubro (ePublicacion* publicaciones, int tam_publicaciones);
void RubroConMasPublicaciones (ePublicacion* publicaciones,int tam_publicaciones);
