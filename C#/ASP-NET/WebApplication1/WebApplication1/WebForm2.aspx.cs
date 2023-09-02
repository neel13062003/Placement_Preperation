using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace WebApplication1
{
    public partial class WebForm2 : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {

        }

        protected void Create_Table(object sender, EventArgs e)
        {
            Table t = new Table();
            int r = Convert.ToInt32(DropDownList1.SelectedValue);
            int c = Convert.ToInt32(DropDownList2.SelectedValue);
            for(int i = 0; i < r; i++)
            {
                TableRow tr = new TableRow();
                for(int j = 0; j < c; j++)
                {
                    TableCell tc = new TableCell();
                    if (i == 0)
                    {
                        LinkButton lb = new LinkButton();
                        lb.Text = "Page2";
                        lb.PostBackUrl = "WebForm1.aspx";
                        tc.Controls.Add(lb);
                    }
                    else if (i == 1)
                    {
                        HyperLink hl = new HyperLink();
                        hl.Text = "Page2";
                        hl.NavigateUrl = "WebForm2.aspx";
                        tc.Controls.Add(hl);
                    }
                    else
                    {
                        Button b = new Button();
                        b.Text = "Button";
                        tc.Controls.Add(b);
                    }
                    tr.Controls.Add(tc);
                }
                t.Controls.Add(tr);
            }
            PlaceHolder1.Controls.Add(t);
        }
    }
}