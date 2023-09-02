using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace WebApplication1
{
    public partial class WebForm1 : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {

        }

        protected void Calculate(object sender, CommandEventArgs e)
        {
            int n1=Convert.ToInt32(TextBox1.Text);
            int n2=Convert.ToInt32(TextBox2.Text);
            switch (e.CommandName)
            {
                case "Add":
                    TextBox3.Text=Convert.ToString(n1 + n2);
                    break;
                case "Sub":
                    TextBox3.Text = Convert.ToString(n1 - n2);
                    break;
                case "Mul":
                    TextBox3.Text= Convert.ToString(n1 * n2);
                    break;
                case "Div":
                    if (n2 == 0)
                    {
                        TextBox2.BorderColor=System.Drawing.Color.Red;
                        Button5.Enabled = false;
                        break;
                    }
                    TextBox3.Text=Convert.ToString(n1 / n2);
                    break;
            }
        }

        protected void Click(object sender, EventArgs e)
        {

        }
    }
}