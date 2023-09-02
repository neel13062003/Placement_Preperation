using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace WebApplication7
{
    public partial class WebForm1 : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {

        }

        protected void Details(object sender, EventArgs e)
        {
            LabelResult.Text = "Submitted Results";

            LabelName.Text = TextBox1.Text.Trim();
            LabelGender.Text = RadioButtonList1.Text;
            LabelDrop.Text = DropDownList1.Text;
            //LabelSub.Text = CheckBoxList1.Text;
            LabelSurvey.Text = RadioButtonList2.Text;

            foreach (ListItem item in CheckBoxList1.Items)
                if (item.Selected)
                    LabelSub.Text += item.ToString() + " | ";
        }

    }
}