#ifndef slic3r_MsgDialog_hpp_
#define slic3r_MsgDialog_hpp_

#include <string>
#include <unordered_map>

#include <wx/dialog.h>
#include <wx/font.h>
#include <wx/bitmap.h>

class wxBoxSizer;
class wxCheckBox;
class wxStaticBitmap;

namespace Slic3r {

namespace GUI {


// A message / query dialog with a bitmap on the left and any content on the right
// with buttons underneath.
struct MsgDialog : wxDialog
{
	MsgDialog(MsgDialog &&) = delete;
	MsgDialog(const MsgDialog &) = delete;
	MsgDialog &operator=(MsgDialog &&) = delete;
	MsgDialog &operator=(const MsgDialog &) = delete;
	virtual ~MsgDialog() = default;

	// TODO: refactor with CreateStdDialogButtonSizer usage

protected:
	enum {
		CONTENT_WIDTH = 50,
		CONTENT_MAX_HEIGHT = 60,
		BORDER = 30,
		VERT_SPACING = 15,
		HORIZ_SPACING = 5,
	};

	// button_id is an id of a button that can be added by default, use wxID_NONE to disable
	MsgDialog(wxWindow *parent, const wxString &title, const wxString &headline, wxWindowID button_id = wxID_OK, wxBitmap bitmap = wxNullBitmap);

	wxFont boldfont;
	wxBoxSizer *content_sizer;
	wxBoxSizer *btn_sizer;
	wxStaticBitmap *logo;
};


// Generic error dialog, used for displaying exceptions
class ErrorDialog : public MsgDialog
{
public:
	// If monospaced_font is true, the error message is displayed using html <code><pre></pre></code> tags,
	// so that the code formatting will be preserved. This is useful for reporting errors from the placeholder parser.
	ErrorDialog(wxWindow *parent, const wxString &msg, bool courier_font);
	ErrorDialog(ErrorDialog &&) = delete;
	ErrorDialog(const ErrorDialog &) = delete;
	ErrorDialog &operator=(ErrorDialog &&) = delete;
	ErrorDialog &operator=(const ErrorDialog &) = delete;
	virtual ~ErrorDialog() = default;

private:
	wxString msg;
};


// Generic info dialog, used for displaying exceptions
class InfoDialog : public MsgDialog
{
public:
	InfoDialog(wxWindow *parent, const wxString &title, const wxString &msg);
	InfoDialog(InfoDialog&&) = delete;
	InfoDialog(const InfoDialog&) = delete;
	InfoDialog&operator=(InfoDialog&&) = delete;
	InfoDialog&operator=(const InfoDialog&) = delete;
	virtual ~InfoDialog() = default;

private:
	wxString msg;
};


}
}

#endif
