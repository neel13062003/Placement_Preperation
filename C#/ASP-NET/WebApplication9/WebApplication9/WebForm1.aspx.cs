using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace WebApplication9
{
    public partial class WebForm1 : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {

        }
        protected void Details(object sender, EventArgs e)
        {
            LabelResult.Text = "Valid or Not ?";
            bool valid = true;
            string str = TextBox1.Text;
            if(str == "")
            {
                valid = false;
            }

            if(TextBox2.Text != TextBox3.Text)
            {
                valid = false;
            }

                if (valid)
                {
                    LabelName1.Text = "Valid";
                }
                else
                {
                    LabelName1.Text = "Not Valid";
                }
        }
        
    }
}