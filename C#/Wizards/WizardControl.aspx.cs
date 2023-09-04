using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

public partial class wizardcontrollearn : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {
        if(!IsPostBack)
        Wizard1.ActiveStepIndex = 0;

    }
    protected void Wizard1_FinishButtonClick(object sender, WizardNavigationEventArgs e)
    {
        Label1.Text = DropDownList1.SelectedItem.Text;
        Label2.Text = TextBox1.Text;
        Label4.Text = TextBox2.Text;

        //data base connectivity



    }
    protected void Wizard1_NextButtonClick(object sender, WizardNavigationEventArgs e)
    {
        if (e.CurrentStepIndex == 0)
            Lblmobileselected.Text = DropDownList1.SelectedItem.Text;
        else if( e.NextStepIndex==2)
            Lblpaymentmobile.Text=DropDownList1.SelectedItem.Text;
    }
    protected void Wizard1_CancelButtonClick(object sender, EventArgs e)
    {
       
        Wizard1.ActiveStepIndex = 3;
    }
}
wizardcontrollearn.aspx.cs
Displaying wizardcontrollearn.aspx.cs.
Learn Wizard and Multiview
Prof. Ravindra Vyas
•
Yesterday
Learn Wizard and Multiview

Gridviewexperiment.aspx.cs
Text

wizardcontrollearn.aspx
Unknown File

wizardcontrollearn.aspx.cs
Text

Gridviewexperiment.aspx
Unknown File
Class comments
