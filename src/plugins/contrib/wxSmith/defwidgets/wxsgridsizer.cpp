#include "../wxsheaders.h"
#include "wxsgridsizer.h"

wxString wxsGridSizer::GetProducingCode(const wxsCodeParams& Params)
{
    return wxString::Format(_T("%s = new wxGridSizer(%d,%d,%d,%d);"),
        Params.VarName.c_str(),
        Rows, Cols, VGap, HGap );
}

bool wxsGridSizer::MyXmlLoad()
{
    Rows = XmlGetInteger(_T("rows"));
    Cols = XmlGetInteger(_T("cols"));
    VGap = XmlGetInteger(_T("vgap"));
    HGap = XmlGetInteger(_T("hgap"));
    return true;
}

bool wxsGridSizer::MyXmlSave()
{
    XmlSetInteger(_T("rows"),Rows);
    XmlSetInteger(_T("cols"),Cols);
    XmlSetInteger(_T("vgap"),VGap);
    XmlSetInteger(_T("hgap"),HGap);
    return true;
}


void wxsGridSizer::MyCreateProperties()
{
    Properties.Add2IProperty(_("Cols x rows:"),Cols,Rows);
    Properties.Add2IProperty(_("VGap x HGap:"),VGap,HGap);
    wxsWidget::MyCreateProperties();
}

void wxsGridSizer::Init()
{
	Rows = 0;
	Cols = 0;
	VGap = 0;
	HGap = 0;
}

wxSizer* wxsGridSizer::ProduceSizer(wxWindow* Panel)
{
	return new wxGridSizer(Rows,Cols,VGap,HGap);
}
