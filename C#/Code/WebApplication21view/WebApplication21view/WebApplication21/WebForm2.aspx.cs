using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace WebApplication21
{
    public partial class WebForm2 : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            if (_infoMultiView.ActiveViewIndex == 0)
            {
                btnPrevious.Visible = false;
            }
        }

        protected void btnPrevious_Click(object sender, EventArgs e)
        {
            if (_infoMultiView.ActiveViewIndex > 0)
            {
                _infoMultiView.ActiveViewIndex--;
                btnPrevious.Visible = true;
            }
            else
            {
                btnPrevious.Visible = false;
            }
        }

        protected void btnNext_Click(object sender, EventArgs e)
        {
            if (_infoMultiView.ActiveViewIndex < _infoMultiView.Views.Count - 1)
            {
                _infoMultiView.ActiveViewIndex++;

            }
            else
            {
                btnPrevious.Visible = false;
            }
        }

        protected void BTN1_click(object sender, EventArgs e)
        {
            _summaryLabel.Text = string.Format(
             "<h2>Thank you for submitting your information!</h2>" +
             "Name: {0} {1}<br /><br/>Address: {2}<br/>" +
             "{3}, {4}<br /><br />Prefs: {5} {6}<br />",
                        _firstNameTextBox.Text,
                        _lastNameTextBox.Text, _streetTextBox.Text,
                        _cityTextBox.Text, _stateTextBox.Text,
                        _colorTextBox.Text, _numberTextBox.Text);
            _infoMultiView.Visible = false;
        }
    }
}