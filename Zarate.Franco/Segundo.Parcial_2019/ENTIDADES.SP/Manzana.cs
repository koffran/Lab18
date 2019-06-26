using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ENTIDADES.SP
{
  public class Manzana: Fruta
  {
    protected string _provinciaOrigen;

    public Manzana(string color, double peso, string provincia):base(color,peso)
    {
      this._provinciaOrigen = provincia;
    }

    public string Nombre
    {
      get
      {
        return "Manzana";
      }
    }

    public override bool TieneCarozo
    {
      get
      {
        return true;
      }
    }

    public override string ToString()
    {
      return base.FrutaToString() + " " + this.Nombre;
    }

  }

  
}
