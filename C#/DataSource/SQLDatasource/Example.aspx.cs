using System;

namespace YourNamespace
{
    public partial class example : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            if (!IsPostBack)
            {
                // You can handle additional logic here if needed.
            }
        }
    }
}
