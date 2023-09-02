using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace WebApplication21
{
    public partial class WebForm1 : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {

        }

        protected void _infoWizard_FinishButtonClick(object sender, WizardNavigationEventArgs e)
        {
            _summaryLabel.Text = string.Format(
             "<h2>Thank you for submitting your information!</h2>" +
             "Name: {0} {1}<br /><br/>Address: {2}<br/>" +
             "{3}, {4}<br /><br />Prefs: {5} {6}<br />",
                        _firstNameTextBox.Text,
                        _lastNameTextBox.Text, _streetTextBox.Text,
                        _cityTextBox.Text, _stateTextBox.Text,
                        _colorTextBox.Text, _numberTextBox.Text);
            _infoWizard.Visible = false;
        }
    }
}