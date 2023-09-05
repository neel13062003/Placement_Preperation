using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

public partial class applicationobjectlearn : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {
        // This event handler will be automatically associated with the Load event.
        // You don't need to specify it in the markup when AutoEventWireup is "true."
        
        Application.Lock();
        int c = (int)Application["counter"];
        c = c + 1;
        Application["counter"] = c;
        Application.UnLock();
        
        Response.Write("Page view="+c.ToString());
    }
}