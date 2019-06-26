using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ENTIDADES.SP
{
  public class Cajon<T>: ISerializar 
  {
    protected int _capacidad;
    protected List<T> _elementos;
    protected double _precioUnitario;

    public List<T> Elementos
    {
      get
      {
        return this._elementos;
      }
    }

    public double PrecioTotal
    {
      get
      {
        return this._precioUnitario * this._elementos.Count;
      }
    }

    public Cajon()
    {
      this._elementos = new List<T>();
    }
    public Cajon(int capacidad):this()
    {
      this._capacidad = capacidad;
    }
    public Cajon (double precio, int capacidad):this(capacidad)
    {
      this._precioUnitario = precio;
    }

    public override string ToString()
    {
      return "Capacidad: " + this._capacidad.ToString() + "\nCantidad de elementos: " + this._elementos.Count.ToString() + "\n Precio total: " + this.PrecioTotal + "\n Elementos: " + this.Elementos;
    }

    public static Cajon<T> operator + (Cajon<T> c, T elemento)
    {
      if(c._elementos.Count < c._capacidad)
      {
        c._elementos.Add(elemento);
      }
      return c;
    }

    public bool Xml(string s)
    {
      return true;
    }
    //Implementar (implicitamente) ISerializar en Cajon y manzana
    //Implementar (explicitamente) IDeserializar en manzana
    //Los archivos .xml guardarlos en el escritorio del cliente
  }
}
