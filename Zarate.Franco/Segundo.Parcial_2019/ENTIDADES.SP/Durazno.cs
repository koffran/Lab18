using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ENTIDADES.SP
{
  public class Durazno : Fruta
  {
    protected int _cantPelusa;

    public Durazno(string color, double peso, int cantPelusa):base(color,peso)
    {
      this._cantPelusa = cantPelusa;
    }

    public string Nombre
    {
      get
      {
        return "Durazno";
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
