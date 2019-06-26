using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ENTIDADES.SP
{
  interface IDeserializar
  {
    bool Xml(string s, out Fruta fruta);
  }
}
