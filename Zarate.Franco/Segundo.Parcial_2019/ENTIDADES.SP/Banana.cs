using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ENTIDADES.SP
{
  public class Banana : Fruta
  {
    protected string _paisOrigen;

    public Banana(string color, double peso, string pais):base(color,peso)
    {
      this._paisOrigen = pais;
    }

    public string Nombre
    {
      get
      {
        return "Banana";
      }
    }
    public override bool TieneCarozo
    {
      get
      {
        return false;
      }
    }

    public override string ToString()
    {
      return base.FrutaToString() + " " + this.Nombre;
    }
  } 
}
