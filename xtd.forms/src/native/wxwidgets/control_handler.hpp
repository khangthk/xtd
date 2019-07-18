#pragma once

#include <memory>
#include <set>
#include <thread>
#include <xtd/xtd.delegates>
#include <xtd/xtd.diagnostics>
#include "../../../include/xtd/forms/keys.hpp"
#include "../../../include/xtd/forms/message.hpp"
#include "../../../include/xtd/forms/message.hpp"
#include "../../../include/xtd/forms/window_messages.hpp"
#include "../../../include/xtd/forms/window_message_keys.hpp"
#include <wx/frame.h>
#include <wx/textctrl.h>

class control_handler;

template<typename TControl>
class control_wrapper : public TControl {
public:
  control_wrapper(control_handler* event_handler, wxWindow *parent, wxWindowID id, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = 0) : TControl(parent, id, pos, size, style), event_handler_(event_handler) {}
  control_wrapper(control_handler* event_handler, wxWindow *parent, wxWindowID id, const wxString& label, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = 0) : TControl(parent, id, label, pos, size, style), event_handler_(event_handler) {}

private:
  bool is_clipboard_event(wxEventType event_type) const {
    static std::set<wxEventType> event_types = {wxEVT_TEXT_COPY, wxEVT_TEXT_CUT, wxEVT_TEXT_PASTE};
    return event_types.find(event_type) != event_types.end();
  }

  bool is_command_event(wxEventType event_type) const {
    static std::set<wxEventType> event_types = {wxEVT_BUTTON, wxEVT_CHECKBOX, wxEVT_CHOICE, wxEVT_LISTBOX, wxEVT_LISTBOX_DCLICK, wxEVT_CHECKLISTBOX, wxEVT_MENU, wxEVT_SLIDER, wxEVT_RADIOBOX, wxEVT_RADIOBUTTON, wxEVT_SCROLLBAR, wxEVT_VLBOX, wxEVT_COMBOBOX, wxEVT_TOOL_RCLICKED, wxEVT_TOOL_DROPDOWN, wxEVT_TOOL_ENTER, wxEVT_COMBOBOX_DROPDOWN, wxEVT_COMBOBOX_CLOSEUP};
    return event_types.find(event_type) != event_types.end();
  }
  
  bool is_cursor_event(wxEventType event_type) const {
    static std::set<wxEventType> event_types = {wxEVT_SET_CURSOR};
    return event_types.find(event_type) != event_types.end();
  }
  
  bool is_generic_command_event(wxEventType event_type) const {
    static std::set<wxEventType> event_types = {wxEVT_COMMAND_LEFT_CLICK, wxEVT_COMMAND_LEFT_DCLICK, wxEVT_COMMAND_RIGHT_CLICK, wxEVT_COMMAND_RIGHT_DCLICK, wxEVT_COMMAND_SET_FOCUS, wxEVT_COMMAND_KILL_FOCUS, wxEVT_COMMAND_ENTER};
    return event_types.find(event_type) != event_types.end();
  }
  
  bool is_gesture_event(wxEventType event_type) const {
    static std::set<wxEventType> event_types = {wxEVT_GESTURE_PAN, wxEVT_GESTURE_ZOOM, wxEVT_GESTURE_ROTATE, wxEVT_TWO_FINGER_TAP, wxEVT_LONG_PRESS, wxEVT_PRESS_AND_TAP};
    return event_types.find(event_type) != event_types.end();
  }
  
  bool is_help_event(wxEventType event_type) const {
    static std::set<wxEventType> event_types = {wxEVT_HELP, wxEVT_DETAILED_HELP};
    return event_types.find(event_type) != event_types.end();
  }
  
  bool is_key_event(wxEventType event_type) const {
    static std::set<wxEventType> event_types = {wxEVT_CHAR, wxEVT_CHAR_HOOK, wxEVT_NAVIGATION_KEY, wxEVT_KEY_DOWN, wxEVT_KEY_UP, wxEVT_HOTKEY, wxEVT_AFTER_CHAR};
    return event_types.find(event_type) != event_types.end();
  }

  bool is_mouse_event(wxEventType event_type) const {
    static std::set<wxEventType> event_types = {wxEVT_LEFT_DOWN, wxEVT_LEFT_UP, wxEVT_MIDDLE_DOWN, wxEVT_MIDDLE_UP, wxEVT_RIGHT_DOWN, wxEVT_RIGHT_UP, wxEVT_MOTION, wxEVT_ENTER_WINDOW, wxEVT_LEAVE_WINDOW, wxEVT_LEFT_DCLICK, wxEVT_MIDDLE_DCLICK, wxEVT_RIGHT_DCLICK, wxEVT_SET_FOCUS, wxEVT_KILL_FOCUS, wxEVT_CHILD_FOCUS, wxEVT_MOUSEWHEEL, wxEVT_AUX1_DOWN, wxEVT_AUX1_UP, wxEVT_AUX1_DCLICK, wxEVT_AUX2_DOWN, wxEVT_AUX2_UP, wxEVT_AUX2_DCLICK /*, wxEVT_MAGNIFY*/};
    return event_types.find(event_type) != event_types.end();
  }
  
  bool is_scroll_event(wxEventType event_type) const {
    static std::set<wxEventType> event_types = {wxEVT_SCROLLWIN_TOP, wxEVT_SCROLLWIN_BOTTOM, wxEVT_SCROLLWIN_LINEUP, wxEVT_SCROLLWIN_LINEDOWN, wxEVT_SCROLLWIN_PAGEUP, wxEVT_SCROLLWIN_PAGEDOWN, wxEVT_SCROLLWIN_THUMBTRACK, wxEVT_SCROLLWIN_THUMBRELEASE};
    return event_types.find(event_type) != event_types.end();
  }
  
  bool is_scrollbar_event(wxEventType event_type) const {
    static std::set<wxEventType> event_types = {wxEVT_SCROLL_TOP, wxEVT_SCROLL_BOTTOM, wxEVT_SCROLL_LINEUP, wxEVT_SCROLL_LINEDOWN, wxEVT_SCROLL_PAGEUP, wxEVT_SCROLL_PAGEDOWN, wxEVT_SCROLL_THUMBTRACK, wxEVT_SCROLL_THUMBRELEASE,  wxEVT_SCROLL_CHANGED};
    return event_types.find(event_type) != event_types.end();
  }

  bool is_spin_event(wxEventType event_type) const {
    static std::set<wxEventType> event_types = {wxEVT_SPIN_UP, wxEVT_SPIN_DOWN, wxEVT_SPIN};
    return event_types.find(event_type) != event_types.end();
  }

  bool is_system_event(wxEventType event_type) const {
    static std::set<wxEventType> event_types = {wxEVT_SIZE, wxEVT_MOVE, wxEVT_CLOSE_WINDOW, wxEVT_END_SESSION, wxEVT_QUERY_END_SESSION, wxEVT_ACTIVATE_APP, wxEVT_ACTIVATE, wxEVT_CREATE, wxEVT_DESTROY, wxEVT_SHOW, wxEVT_ICONIZE, wxEVT_MAXIMIZE, wxEVT_MOUSE_CAPTURE_CHANGED, wxEVT_MOUSE_CAPTURE_LOST, wxEVT_PAINT, wxEVT_ERASE_BACKGROUND, wxEVT_NC_PAINT, wxEVT_MENU_OPEN, wxEVT_MENU_CLOSE, wxEVT_MENU_HIGHLIGHT, wxEVT_CONTEXT_MENU, wxEVT_SYS_COLOUR_CHANGED, wxEVT_DISPLAY_CHANGED, wxEVT_QUERY_NEW_PALETTE, wxEVT_PALETTE_CHANGED, wxEVT_JOY_BUTTON_DOWN, wxEVT_JOY_BUTTON_UP, wxEVT_JOY_MOVE, wxEVT_JOY_ZMOVE, wxEVT_DROP_FILES, wxEVT_INIT_DIALOG, wxEVT_IDLE, wxEVT_UPDATE_UI, wxEVT_SIZING, wxEVT_MOVING, wxEVT_MOVE_START, wxEVT_MOVE_END, wxEVT_HIBERNATE};
    return event_types.find(event_type) != event_types.end();
  }

  bool is_text_event(wxEventType event_type) const {
    static std::set<wxEventType> event_types = {wxEVT_TEXT, wxEVT_TEXT_ENTER, wxEVT_TEXT_URL, wxEVT_TEXT_MAXLEN};
    return event_types.find(event_type) != event_types.end();
  }

  bool is_thread_event(wxEventType event_type) const {
    static std::set<wxEventType> event_types = {wxEVT_THREAD, wxEVT_ASYNC_METHOD_CALL};
    return event_types.find(event_type) != event_types.end();
  }

  xtd::forms::keys convert_to_key_data(const wxKeyEvent& key_event) {
    xtd::forms::keys key_data = xtd::forms::keys::none;
    if (key_event.GetUnicodeKey() != WXK_NONE)
      key_data = static_cast<xtd::forms::keys>(key_event.GetUnicodeKey());
    else {
      switch (key_event.GetKeyCode()) {
      case WXK_START: key_data = xtd::forms::keys::launch_application1; break;
      case WXK_LBUTTON: key_data = xtd::forms::keys::lbutton; break;
      case WXK_RBUTTON: key_data = xtd::forms::keys::rbutton; break;
      case WXK_CANCEL: key_data = xtd::forms::keys::cancel; break;
      case WXK_MBUTTON: key_data = xtd::forms::keys::mbutton; break;
      case WXK_CLEAR: key_data = xtd::forms::keys::clear; break;
      case WXK_SHIFT: key_data = xtd::forms::keys::shift_key; break;
      case WXK_ALT: key_data = xtd::forms::keys::alt; break;
      case WXK_CONTROL: key_data = xtd::forms::keys::control_key; break;
      case WXK_MENU: key_data = xtd::forms::keys::menu; break;
      case WXK_PAUSE: key_data = xtd::forms::keys::pause; break;
      case WXK_CAPITAL: key_data = xtd::forms::keys::capital; break;
      case WXK_END: key_data = xtd::forms::keys::end; break;
      case WXK_HOME: key_data = xtd::forms::keys::home; break;
      case WXK_LEFT: key_data = xtd::forms::keys::left; break;
      case WXK_UP: key_data = xtd::forms::keys::up; break;
      case WXK_RIGHT: key_data = xtd::forms::keys::right; break;
      case WXK_DOWN: key_data = xtd::forms::keys::down; break;
      case WXK_SELECT: key_data = xtd::forms::keys::select; break;
      case WXK_PRINT: key_data = xtd::forms::keys::print; break;
      case WXK_EXECUTE: key_data = xtd::forms::keys::execute; break;
      case WXK_SNAPSHOT: key_data = xtd::forms::keys::snapshot; break;
      case WXK_INSERT: key_data = xtd::forms::keys::insert; break;
      case WXK_HELP: key_data = xtd::forms::keys::help; break;
      case WXK_NUMPAD0: key_data = xtd::forms::keys::num_pad0; break;
      case WXK_NUMPAD1: key_data = xtd::forms::keys::num_pad1; break;
      case WXK_NUMPAD2: key_data = xtd::forms::keys::num_pad2; break;
      case WXK_NUMPAD3: key_data = xtd::forms::keys::num_pad3; break;
      case WXK_NUMPAD4: key_data = xtd::forms::keys::num_pad4; break;
      case WXK_NUMPAD5: key_data = xtd::forms::keys::num_pad5; break;
      case WXK_NUMPAD6: key_data = xtd::forms::keys::num_pad6; break;
      case WXK_NUMPAD7: key_data = xtd::forms::keys::num_pad7; break;
      case WXK_NUMPAD8: key_data = xtd::forms::keys::num_pad8; break;
      case WXK_NUMPAD9: key_data = xtd::forms::keys::num_pad9; break;
      case WXK_MULTIPLY: key_data = xtd::forms::keys::multiply; break;
      case WXK_ADD: key_data = xtd::forms::keys::add; break;
      case WXK_SEPARATOR: key_data = xtd::forms::keys::separator; break;
      case WXK_DIVIDE: key_data = xtd::forms::keys::divide; break;
      case WXK_F1: key_data = xtd::forms::keys::f1; break;
      case WXK_F2: key_data = xtd::forms::keys::f2; break;
      case WXK_F3: key_data = xtd::forms::keys::f3; break;
      case WXK_F4: key_data = xtd::forms::keys::f4; break;
      case WXK_F5: key_data = xtd::forms::keys::f5; break;
      case WXK_F6: key_data = xtd::forms::keys::f6; break;
      case WXK_F7: key_data = xtd::forms::keys::f7; break;
      case WXK_F8: key_data = xtd::forms::keys::f8; break;
      case WXK_F9: key_data = xtd::forms::keys::f9; break;
      case WXK_F10: key_data = xtd::forms::keys::f10; break;
      case WXK_F11: key_data = xtd::forms::keys::f11; break;
      case WXK_F12: key_data = xtd::forms::keys::f12; break;
      case WXK_F13: key_data = xtd::forms::keys::f13; break;
      case WXK_F14: key_data = xtd::forms::keys::f14; break;
      case WXK_F15: key_data = xtd::forms::keys::f15; break;
      case WXK_F16: key_data = xtd::forms::keys::f16; break;
      case WXK_F17: key_data = xtd::forms::keys::f17; break;
      case WXK_F18: key_data = xtd::forms::keys::f18; break;
      case WXK_F19: key_data = xtd::forms::keys::f19; break;
      case WXK_F20: key_data = xtd::forms::keys::f20; break;
      case WXK_F21: key_data = xtd::forms::keys::f21; break;
      case WXK_F22: key_data = xtd::forms::keys::f22; break;
      case WXK_F23: key_data = xtd::forms::keys::f23; break;
      case WXK_F24: key_data = xtd::forms::keys::f24; break;
      case WXK_NUMLOCK: key_data = xtd::forms::keys::num_lock; break;
      case WXK_SCROLL: key_data = xtd::forms::keys::scroll; break;
      case WXK_PAGEUP: key_data = xtd::forms::keys::page_up; break;
      case WXK_PAGEDOWN: key_data = xtd::forms::keys::page_down; break;
        /// --> num pad special keys
      case WXK_NUMPAD_SPACE: key_data = xtd::forms::keys::space; break;
      case WXK_NUMPAD_TAB: key_data = xtd::forms::keys::tab; break;
      case WXK_NUMPAD_ENTER: key_data = xtd::forms::keys::enter; break;
      case WXK_NUMPAD_F1: key_data = xtd::forms::keys::f1; break;
      case WXK_NUMPAD_F2: key_data = xtd::forms::keys::f2; break;
      case WXK_NUMPAD_F3: key_data = xtd::forms::keys::f3; break;
      case WXK_NUMPAD_F4: key_data = xtd::forms::keys::f4; break;
      case WXK_NUMPAD_HOME: key_data = xtd::forms::keys::home; break;
      case WXK_NUMPAD_LEFT: key_data = xtd::forms::keys::left; break;
      case WXK_NUMPAD_UP: key_data = xtd::forms::keys::up; break;
      case WXK_NUMPAD_RIGHT: key_data = xtd::forms::keys::right; break;
      case WXK_NUMPAD_DOWN: key_data = xtd::forms::keys::down; break;
      case WXK_NUMPAD_PAGEUP: key_data = xtd::forms::keys::page_up; break;
      case WXK_NUMPAD_PAGEDOWN: key_data = xtd::forms::keys::page_down; break;
      case WXK_NUMPAD_END: key_data = xtd::forms::keys::end; break;
      case WXK_NUMPAD_BEGIN: key_data = xtd::forms::keys::home; break; // ???
      case WXK_NUMPAD_INSERT: key_data = xtd::forms::keys::insert; break;
      case WXK_NUMPAD_DELETE: key_data = xtd::forms::keys::del; break;
      case WXK_NUMPAD_EQUAL: key_data = static_cast<xtd::forms::keys>('='); break;
        /// <-- num pad special keys
      case WXK_NUMPAD_MULTIPLY: key_data = xtd::forms::keys::multiply; break;
      case WXK_NUMPAD_ADD: key_data = xtd::forms::keys::add; break;
      case WXK_NUMPAD_SEPARATOR: key_data = xtd::forms::keys::separator; break;
      case WXK_NUMPAD_SUBTRACT: key_data = xtd::forms::keys::subtract; break;
      case WXK_NUMPAD_DECIMAL: key_data = xtd::forms::keys::decimal; break;
      case WXK_NUMPAD_DIVIDE: key_data = xtd::forms::keys::divide; break;
      case WXK_WINDOWS_LEFT: key_data = xtd::forms::keys::lwin; break;
      case WXK_WINDOWS_RIGHT: key_data = xtd::forms::keys::rwin; break;
      case WXK_WINDOWS_MENU: key_data = xtd::forms::keys::apps; break;
      //case WXK_RAW_CONTROL: key_data = xtd::forms::keys::control_key; break;
      case WXK_SPECIAL1: key_data = xtd::forms::keys::oem_semicolon; break;
      case WXK_SPECIAL2: key_data = xtd::forms::keys::oem_plus; break;
      case WXK_SPECIAL3: key_data = xtd::forms::keys::oem_comma; break;
      case WXK_SPECIAL4: key_data = xtd::forms::keys::oem_minus; break;
      case WXK_SPECIAL5: key_data = xtd::forms::keys::oem_period; break;
      case WXK_SPECIAL6: key_data = xtd::forms::keys::oem_question; break;
      case WXK_SPECIAL7: key_data = xtd::forms::keys::oem_tilde; break;
      case WXK_SPECIAL8: key_data = xtd::forms::keys::oem_open_brackets; break;
      case WXK_SPECIAL9: key_data = xtd::forms::keys::oem_pipe; break;
      case WXK_SPECIAL10: key_data = xtd::forms::keys::oem_close_brackets; break;
      case WXK_SPECIAL11: key_data = xtd::forms::keys::oem_quotes; break;
      case WXK_SPECIAL12: key_data = xtd::forms::keys::oem_backslash; break;
      case WXK_SPECIAL13: key_data = xtd::forms::keys::oem1; break;
      case WXK_SPECIAL14: key_data = xtd::forms::keys::oem102; break;
      case WXK_SPECIAL15: key_data = xtd::forms::keys::oem2; break;
      case WXK_SPECIAL16: key_data = xtd::forms::keys::oem3; break;
      case WXK_SPECIAL17: key_data = xtd::forms::keys::oem4; break;
      case WXK_SPECIAL18: key_data = xtd::forms::keys::oem5; break;
      case WXK_SPECIAL19: key_data = xtd::forms::keys::oem6; break;
      case WXK_SPECIAL20: key_data = xtd::forms::keys::oem7; break;
      case WXK_BROWSER_BACK: key_data = xtd::forms::keys::browser_back; break;
      case WXK_BROWSER_FORWARD: key_data = xtd::forms::keys::browser_forward; break;
      case WXK_BROWSER_REFRESH: key_data = xtd::forms::keys::browser_refresh; break;
      case WXK_BROWSER_STOP: key_data = xtd::forms::keys::browser_stop; break;
      case WXK_BROWSER_SEARCH: key_data = xtd::forms::keys::browser_search; break;
      case WXK_BROWSER_FAVORITES: key_data = xtd::forms::keys::browser_favorites; break;
      case WXK_BROWSER_HOME: key_data = xtd::forms::keys::browser_home; break;
      case WXK_VOLUME_MUTE: key_data = xtd::forms::keys::volume_mute; break;
      case WXK_VOLUME_DOWN: key_data = xtd::forms::keys::volume_down; break;
      case WXK_VOLUME_UP: key_data = xtd::forms::keys::volume_up; break;
      case WXK_MEDIA_NEXT_TRACK: key_data = xtd::forms::keys::media_next_track; break;
      case WXK_MEDIA_PREV_TRACK: key_data = xtd::forms::keys::media_previous_track; break;
      case WXK_MEDIA_STOP: key_data = xtd::forms::keys::media_stop; break;
      case WXK_MEDIA_PLAY_PAUSE: key_data = xtd::forms::keys::media_play_pause; break;
      case WXK_LAUNCH_MAIL: key_data = xtd::forms::keys::launch_mail; break;
      case WXK_LAUNCH_APP1: key_data = xtd::forms::keys::launch_application1; break;
      case WXK_LAUNCH_APP2: key_data = xtd::forms::keys::launch_application2; break;
      default: break;
      }
    }

    if (key_event.AltDown()) key_data += xtd::forms::keys::alt;
    if (key_event.CmdDown()) key_data += xtd::forms::keys::control;
    if (key_event.MetaDown()) key_data += xtd::forms::keys::command;
    if (key_event.ShiftDown()) key_data += xtd::forms::keys::shift;

    return key_data;
  }
  
  bool ProcessEvent(wxEvent &event) override;
  bool process_clipboard_event(wxEvent &event);
  bool process_command_event(wxEvent &event);
  bool process_cursor_event(wxEvent &event);
  bool process_generic_command_event(wxEvent &event);
  bool process_gesture_event(wxEvent &event);
  bool process_help_event(wxEvent &event);
  bool process_key_event(wxEvent &event);
  bool process_mouse_event(wxEvent &event);
  bool process_scroll_event(wxEvent &event);
  bool process_scrollbar_event(wxEvent &event);
  bool process_spin_event(wxEvent &event);
  bool process_system_event(wxEvent &event);
  bool process_text_event(wxEvent &event);
  bool process_thread_event(wxEvent &event);

  control_handler* event_handler_;
};

class control_handler {
public:
  control_handler() = default;

  template<typename control>
  void create(wxWindow *parent, wxWindowID id, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = 0) {
    this->control_ = new control_wrapper<control>(this, parent, id, pos, size, style);
  }
  
  template<typename control>
  void create(wxWindow *parent, wxWindowID id, const wxString& label, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = 0) {
    this->control_ = new control_wrapper<control>(this, parent, id, label, pos, size, style);
  }

  void register_wnd_proc(xtd::delegate<void(xtd::forms::message&)> wnd_proc) {
    this->wnd_proc_ = wnd_proc;
  }
  
  void unregister_wnd_proc() {
    //this->wnd_proc_ = xtd::delegate<void(xtd::forms::message&)>();
  }
  
  intptr_t send_message(intptr_t hwnd, int msg, intptr_t wparam, intptr_t lparam, intptr_t handle) {
    if (this->wnd_proc_ == nullptr) return -1;
    xtd::forms::message message = xtd::forms::message::create(hwnd, msg, wparam, lparam, 0, handle);
    this->wnd_proc_(message);
    return message.result();
  }

  wxWindow* control() const {return this->control_;}
  void clear_control() {this->control_ = nullptr;}

private:
  xtd::delegate<void(xtd::forms::message&)> wnd_proc_;
  wxWindow* control_;
};

template<typename TControl>
inline bool control_wrapper<TControl>::ProcessEvent(wxEvent& event) {
  if (is_clipboard_event(event.GetEventType())) return this->process_clipboard_event(event);
  if (is_command_event(event.GetEventType())) return this->process_command_event(event);
  if (is_cursor_event(event.GetEventType())) return this->process_cursor_event(event);
  if (is_generic_command_event(event.GetEventType())) return this->process_generic_command_event(event);
  if (is_gesture_event(event.GetEventType())) return this->process_gesture_event(event);
  if (is_key_event(event.GetEventType())) return this->process_key_event(event);
  if (is_mouse_event(event.GetEventType())) return this->process_mouse_event(event);
  if (is_scroll_event(event.GetEventType())) return this->process_scroll_event(event);
  if (is_scrollbar_event(event.GetEventType())) return this->process_scrollbar_event(event);
  if (is_spin_event(event.GetEventType())) return this->process_spin_event(event);
  if (is_system_event(event.GetEventType())) return this->process_system_event(event);
  if (is_text_event(event.GetEventType())) return this->process_thread_event(event);
  if (is_thread_event(event.GetEventType())) return this->process_thread_event(event);
  return this->TControl::ProcessEvent(event);
}

template<typename TControl>
inline bool control_wrapper<TControl>::process_clipboard_event(wxEvent& event) {
  return this->TControl::ProcessEvent(event);
}

template<typename TControl>
inline bool control_wrapper<TControl>::process_command_event(wxEvent& event) {
  return this->TControl::ProcessEvent(event);
}

template<typename TControl>
inline bool control_wrapper<TControl>::process_cursor_event(wxEvent& event) {
  return this->TControl::ProcessEvent(event);
}

template<typename TControl>
inline bool control_wrapper<TControl>::process_generic_command_event(wxEvent& event) {
  wxWindow* window = reinterpret_cast<wxWindow*>(event.GetEventObject());
  if (!window) return this->TControl::ProcessEvent(event);
  intptr_t hwnd = reinterpret_cast<intptr_t>(window->GetHandle());
  
  if (event.GetEventType() == wxEVT_COMMAND_ENTER)
    this->event_handler_->send_message(hwnd, WM_COMMAND, 0, 0, reinterpret_cast<intptr_t>(&event));
  return this->TControl::ProcessEvent(event);
}

template<typename TControl>
inline bool control_wrapper<TControl>::process_help_event(wxEvent& event) {
  return this->TControl::ProcessEvent(event);
}

template<typename TControl>
inline bool control_wrapper<TControl>::process_gesture_event(wxEvent& event) {
  return this->TControl::ProcessEvent(event);
}

template<typename TControl>
inline bool control_wrapper<TControl>::process_key_event(wxEvent& event) {
  wxWindow* window = reinterpret_cast<wxWindow*>(event.GetEventObject());
  if (!window) return this->TControl::ProcessEvent(event);
  intptr_t hwnd = reinterpret_cast<intptr_t>(window->GetHandle());

  if (event.GetEventType() == wxEVT_KEY_DOWN) {
    this->event_handler_->send_message(hwnd, WM_KEYDOWN, static_cast<intptr_t>(convert_to_key_data(static_cast<wxKeyEvent&>(event))), 0, reinterpret_cast<intptr_t>(&event));
    event.Skip();
  }
  if (event.GetEventType() == wxEVT_CHAR) {
    this->event_handler_->send_message(hwnd, WM_CHAR, static_cast<wxKeyEvent&>(event).GetUnicodeKey(), 0, reinterpret_cast<intptr_t>(&event));
    event.Skip();
  }
  if (event.GetEventType() == wxEVT_KEY_UP) {
    this->event_handler_->send_message(hwnd, WM_KEYUP, static_cast<intptr_t>(convert_to_key_data(static_cast<wxKeyEvent&>(event))), 0, reinterpret_cast<intptr_t>(&event));
    event.Skip();
  }

  return this->TControl::ProcessEvent(event);
}

template<typename TControl>
inline bool control_wrapper<TControl>::process_mouse_event(wxEvent& event) {
  wxWindow* window = reinterpret_cast<wxWindow*>(event.GetEventObject());
  if (!window) return this->TControl::ProcessEvent(event);
  intptr_t hwnd = reinterpret_cast<intptr_t>(window->GetHandle());
  wxMouseEvent& mouse_event = static_cast<wxMouseEvent&>(event);
  wxMouseState mouse_state = wxGetMouseState();
  int virtual_keys = 0;
  if (mouse_state.ControlDown()) virtual_keys += MK_CONTROL;
  if (mouse_state.ShiftDown()) virtual_keys += MK_SHIFT;
  if (mouse_state.LeftIsDown()) virtual_keys += MK_LBUTTON;
  if (mouse_state.MiddleIsDown()) virtual_keys += MK_MBUTTON;
  if (mouse_state.RightIsDown()) virtual_keys += MK_RBUTTON;
  if (mouse_state.Aux1IsDown()) virtual_keys += MK_XBUTTON1;
  if (mouse_state.Aux2IsDown()) virtual_keys += MK_XBUTTON2;

  if (event.GetEventType() == wxEVT_LEFT_DOWN) this->event_handler_->send_message(hwnd, WM_LBUTTONDOWN, virtual_keys, mouse_state.GetX() + (mouse_state.GetY() << 16), reinterpret_cast<intptr_t>(&event));
  if (event.GetEventType() == wxEVT_MIDDLE_DOWN) this->event_handler_->send_message(hwnd, WM_MBUTTONDOWN, virtual_keys, mouse_state.GetX() + (mouse_state.GetY() << 16), reinterpret_cast<intptr_t>(&event));
  if (event.GetEventType() == wxEVT_RIGHT_DOWN) this->event_handler_->send_message(hwnd, WM_RBUTTONDOWN, virtual_keys, mouse_state.GetX() + (mouse_state.GetY() << 16), reinterpret_cast<intptr_t>(&event));
  if (event.GetEventType() == wxEVT_LEFT_UP) this->event_handler_->send_message(hwnd, WM_LBUTTONUP, virtual_keys, mouse_state.GetX() + (mouse_state.GetY() << 16), reinterpret_cast<intptr_t>(&event));
  if (event.GetEventType() == wxEVT_MIDDLE_UP) this->event_handler_->send_message(hwnd, WM_MBUTTONUP, virtual_keys, mouse_state.GetX() + (mouse_state.GetY() << 16), reinterpret_cast<intptr_t>(&event));
  if (event.GetEventType() == wxEVT_RIGHT_UP) this->event_handler_->send_message(hwnd, WM_RBUTTONUP, virtual_keys, mouse_state.GetX() + (mouse_state.GetY() << 16), reinterpret_cast<intptr_t>(&event));
  if (event.GetEventType() == wxEVT_MOTION) this->event_handler_->send_message(hwnd, WM_MOUSEMOVE, virtual_keys, mouse_state.GetX() + (mouse_state.GetY() << 16), reinterpret_cast<intptr_t>(&event));
  if (event.GetEventType() == wxEVT_ENTER_WINDOW) this->event_handler_->send_message(hwnd, WM_MOUSEENTER, 0, 0, reinterpret_cast<intptr_t>(&event));
  if (event.GetEventType() == wxEVT_LEAVE_WINDOW) this->event_handler_->send_message(hwnd, WM_MOUSELEAVE, 0, 0, reinterpret_cast<intptr_t>(&event));
  if (event.GetEventType() == wxEVT_LEFT_DCLICK) this->event_handler_->send_message(hwnd, WM_LBUTTONDBLCLK, virtual_keys, mouse_state.GetX() + (mouse_state.GetY() << 16), reinterpret_cast<intptr_t>(&event));
  if (event.GetEventType() == wxEVT_MIDDLE_DCLICK) this->event_handler_->send_message(hwnd, WM_MBUTTONDBLCLK, virtual_keys, mouse_state.GetX() + (mouse_state.GetY() << 16), reinterpret_cast<intptr_t>(&event));
  if (event.GetEventType() == wxEVT_RIGHT_DCLICK) this->event_handler_->send_message(hwnd, WM_RBUTTONDBLCLK, virtual_keys, mouse_state.GetX() + (mouse_state.GetY() << 16), reinterpret_cast<intptr_t>(&event));
  if (event.GetEventType() == wxEVT_SET_FOCUS) this->event_handler_->send_message(hwnd, WM_SETFOCUS, 0, 0, reinterpret_cast<intptr_t>(&event));
  if (event.GetEventType() == wxEVT_KILL_FOCUS) this->event_handler_->send_message(hwnd, WM_KILLFOCUS, 0, 0, reinterpret_cast<intptr_t>(&event));
  if (event.GetEventType() == wxEVT_CHILD_FOCUS) this->event_handler_->send_message(hwnd, WM_CHILDACTIVATE, 0, 0, reinterpret_cast<intptr_t>(&event));
  if (event.GetEventType() == wxEVT_MOUSEWHEEL) this->event_handler_->send_message(hwnd, mouse_event.GetWheelAxis() == wxMouseWheelAxis::wxMOUSE_WHEEL_VERTICAL ? WM_MOUSEWHEEL : WM_MOUSEHWHEEL, virtual_keys + ((mouse_event.GetWheelRotation() < 0 ? -mouse_event.GetWheelDelta() : mouse_event.GetWheelDelta()) << 16), mouse_state.GetX() + (mouse_state.GetY() << 16), reinterpret_cast<intptr_t>(&event));
  if (event.GetEventType() == wxEVT_AUX1_DOWN || event.GetEventType() == wxEVT_AUX2_DOWN) this->event_handler_->send_message(hwnd, WM_XBUTTONDOWN, virtual_keys, mouse_state.GetX() + (mouse_state.GetY() << 16), reinterpret_cast<intptr_t>(&event));
  if (event.GetEventType() == wxEVT_AUX1_UP || event.GetEventType() == wxEVT_AUX2_UP) this->event_handler_->send_message(hwnd, WM_XBUTTONUP, virtual_keys, mouse_state.GetX() + (mouse_state.GetY() << 16), reinterpret_cast<intptr_t>(&event));
  if (event.GetEventType() == wxEVT_AUX1_DCLICK || event.GetEventType() == wxEVT_AUX2_DCLICK) this->event_handler_->send_message(hwnd, WM_XBUTTONDBLCLK, virtual_keys, mouse_state.GetX() + (mouse_state.GetY() << 16), reinterpret_cast<intptr_t>(&event));
  return this->TControl::ProcessEvent(event);
}

template<typename TControl>
inline bool control_wrapper<TControl>::process_scroll_event(wxEvent& event) {
  return this->TControl::ProcessEvent(event);
}

template<typename TControl>
inline bool control_wrapper<TControl>::process_scrollbar_event(wxEvent& event) {
  return this->TControl::ProcessEvent(event);
}

template<typename TControl>
inline bool control_wrapper<TControl>::process_spin_event(wxEvent& event) {
  return this->TControl::ProcessEvent(event);
}

template<typename TControl>
inline bool control_wrapper<TControl>::process_system_event(wxEvent& event) {
  wxWindow* window = reinterpret_cast<wxWindow*>(event.GetEventObject());
  if (!window) return this->TControl::ProcessEvent(event);
  intptr_t hwnd = reinterpret_cast<intptr_t>(window->GetHandle());

  if (event.GetEventType() == wxEVT_CLOSE_WINDOW) this->event_handler_->send_message(hwnd, WM_CLOSE, 0, 0, reinterpret_cast<intptr_t>(&event));
  else if (event.GetEventType() == wxEVT_DESTROY) this->event_handler_->send_message(hwnd, WM_DESTROY, 0, 0, reinterpret_cast<intptr_t>(&event));
  else if (event.GetEventType() == wxEVT_MOVE) this->event_handler_->send_message(hwnd, WM_MOVE, 0, window->GetPosition().x + (window->GetPosition().y << 16), reinterpret_cast<intptr_t>(&event));
  else if (event.GetEventType() == wxEVT_NULL) this->event_handler_->send_message(hwnd, WM_NULL, 0, 0, reinterpret_cast<intptr_t>(&event));
  else if (event.GetEventType() == wxEVT_SHOW) this->event_handler_->send_message(hwnd, WM_SHOWWINDOW, static_cast<wxShowEvent&>(event).IsShown(), 0, reinterpret_cast<intptr_t>(&event));
  else if (event.GetEventType() == wxEVT_SIZE) this->event_handler_->send_message(hwnd, WM_SIZE, 0, window->GetSize().GetWidth() + (window->GetSize().GetHeight() << 16), reinterpret_cast<intptr_t>(&event));
  //else if (event.GetEventType() == wxEVT_ENTER_SIZEMOVE) this->event_handler_->send_message(hwnd, WM_ENTERSIZEMOVE, 0, 0, reinterpret_cast<intptr_t>(&event));
  //else if (event.GetEventType() == wxEVT_EXIT_SIZEMOVE) this->event_handler_->send_message(hwnd, WM_EXITSIZEMOVE, 0, 0, reinterpret_cast<intptr_t>(&event));
  return this->TControl::ProcessEvent(event);
}

template<typename TControl>
inline bool control_wrapper<TControl>::process_text_event(wxEvent& event) {
  wxWindow* window = reinterpret_cast<wxWindow*>(event.GetEventObject());
  if (!window) return this->TControl::ProcessEvent(event);
  intptr_t hwnd = reinterpret_cast<intptr_t>(window->GetHandle());
  
  if (event.GetEventType() == wxEVT_TEXT) {
    wxCStrData str_data = static_cast<wxCommandEvent&>(event).GetString().c_str();
    const char* str = str_data.AsChar();
    this->event_handler_->send_message(hwnd, WM_SETTEXT, 0, reinterpret_cast<intptr_t>(str), reinterpret_cast<intptr_t>(&event));
  }
  
  return this->TControl::ProcessEvent(event);
}

template<typename TControl>
inline bool control_wrapper<TControl>::process_thread_event(wxEvent& event) {
  return this->TControl::ProcessEvent(event);
}
