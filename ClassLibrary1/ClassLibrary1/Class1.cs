using System;
using System.Data;

namespace ClassLibrary1
{
    public class Numero
    {
        /*Ambas opciones del método DecimalBinario convertirán un número decimal
a binario, en caso de ser posible. Caso contrario retornará "Valor inválido".
Reutilizar código*/

        private double numero;

        public string DecimalBinario(double numero)
        {
            string retorno = "";

            int num = (int)numero;
            while(num>1)
            {
                int resto = num % 2;
                retorno = resto.ToString() + retorno;

                num = num / 2;
            }

            return retorno;
        }

        public string DecimalBinario(string numero)
        {
            string retorno = "Valor invalido";
            double numeroDecimal;
            if (double.TryParse(numero, out  numeroDecimal))
                retorno = this.DecimalBinario(numeroDecimal);
             return retorno;

            
            
        }
    }
}
