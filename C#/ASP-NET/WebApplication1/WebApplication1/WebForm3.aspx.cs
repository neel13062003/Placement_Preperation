using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace WebApplication1
{
    public partial class WebForm3 : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {

        }

        protected void Calendar1_DayRender(object sender, DayRenderEventArgs e)
        {
            if (e.Day.Date >= (new DateTime(2023, 07, 31)) && e.Day.Date <= (new DateTime(2023, 08, 05)))
            {
                Calendar1.SelectedDates.Add(e.Day.Date);
                Label l = new Label();
                l.Text = "  Sessional";
                e.Cell.Controls.Add(l);
            }
            else if (e.Day.Date >= (new DateTime(2023, 09, 11)) && e.Day.Date <= (new DateTime(2023, 09, 16)))
            {
                Calendar1.SelectedDates.Add(e.Day.Date);
                Label l = new Label();
                l.Text = "  Viva";
                e.Cell.Controls.Add(l);
            }
            else if (e.Day.Date >= (new DateTime(2023, 11, 27)) && e.Day.Date <= (new DateTime(2023, 12, 02)))
            {
                Calendar1.SelectedDates.Add(e.Day.Date);
                Label l = new Label();
                l.Text = "  External";
                e.Cell.Controls.Add(l);
            }
        }
    }
}