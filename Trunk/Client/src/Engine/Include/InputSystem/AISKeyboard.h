
#pragma once

#include "AISDeviceObject.h"

namespace AIS
{

	//! Keyboard scan codes
	enum KeyCode
	{
		KC_UNASSIGNED  = 0x00,
		KC_ESCAPE      = 0x01,	// Esc
		KC_1           = 0x02,	// number 1
		KC_2           = 0x03,	// number 2
		KC_3           = 0x04,	// number 3
		KC_4           = 0x05,	// number 4
		KC_5           = 0x06,	// number 5
		KC_6           = 0x07,	// number 6
		KC_7           = 0x08,	// number 7
		KC_8           = 0x09,	// number 8
		KC_9           = 0x0A,	// number 9
		KC_0           = 0x0B,	// number 0
		KC_MINUS       = 0x0C,  // -  on main keyboard
		KC_EQUALS      = 0x0D,	// =  on main keyboard
		KC_BACK        = 0x0E,  // <- Backspace
		KC_TAB         = 0x0F,	// Tab
		KC_Q           = 0x10,	
		KC_W           = 0x11,
		KC_E           = 0x12,
		KC_R           = 0x13,
		KC_T           = 0x14,
		KC_Y           = 0x15,
		KC_U           = 0x16,
		KC_I           = 0x17,
		KC_O           = 0x18,
		KC_P           = 0x19,
		KC_LBRACKET    = 0x1A,	// { [
		KC_RBRACKET    = 0x1B,	// } ]
		KC_RETURN      = 0x1C,  // Enter on main keyboard
		KC_LCONTROL    = 0x1D,	// Left Ctrl
		KC_A           = 0x1E,
		KC_S           = 0x1F,
		KC_D           = 0x20,
		KC_F           = 0x21,
		KC_G           = 0x22,
		KC_H           = 0x23,
		KC_J           = 0x24,
		KC_K           = 0x25,
		KC_L           = 0x26,
		KC_SEMICOLON   = 0x27,	// ;
		KC_APOSTROPHE  = 0x28,	// '
		KC_GRAVE       = 0x29,  // accent
		KC_LSHIFT      = 0x2A,	// Left shift
		KC_BACKSLASH   = 0x2B,	// "\"反斜杠
		KC_Z           = 0x2C,
		KC_X           = 0x2D,
		KC_C           = 0x2E,
		KC_V           = 0x2F,
		KC_B           = 0x30,
		KC_N           = 0x31,
		KC_M           = 0x32,
		KC_COMMA       = 0x33,	// , on main keyboard
		KC_PERIOD      = 0x34,  // . on main keyboard
		KC_SLASH       = 0x35,  // / on main keyboard
		KC_RSHIFT      = 0x36,	// Right shift
		KC_MULTIPLY    = 0x37,  // * on numeric keypad
		KC_LMENU       = 0x38,  // left Alt
		KC_SPACE       = 0x39,	// Space
		KC_CAPITAL     = 0x3A,	// CapsLock
		KC_F1          = 0x3B,
		KC_F2          = 0x3C,
		KC_F3          = 0x3D,
		KC_F4          = 0x3E,
		KC_F5          = 0x3F,
		KC_F6          = 0x40,
		KC_F7          = 0x41,
		KC_F8          = 0x42,
		KC_F9          = 0x43,
		KC_F10         = 0x44,
		KC_NUMLOCK     = 0x45,	// NumLock
		KC_SCROLL      = 0x46,  // Scroll Lock
		KC_NUMPAD7     = 0x47,
		KC_NUMPAD8     = 0x48,
		KC_NUMPAD9     = 0x49,
		KC_SUBTRACT    = 0x4A,  // - on numeric keypad
		KC_NUMPAD4     = 0x4B,
		KC_NUMPAD5     = 0x4C,
		KC_NUMPAD6     = 0x4D,
		KC_ADD         = 0x4E,  // + on numeric keypad
		KC_NUMPAD1     = 0x4F,
		KC_NUMPAD2     = 0x50,
		KC_NUMPAD3     = 0x51,
		KC_NUMPAD0     = 0x52,
		KC_DECIMAL     = 0x53,  // . on numeric keypad
		KC_OEM_102     = 0x56,	// < > | on UK/Germany keyboards
		KC_F11         = 0x57,
		KC_F12         = 0x58,
		KC_F13         = 0x64,  //                     (NEC PC98)
		KC_F14         = 0x65,  //                     (NEC PC98)
		KC_F15         = 0x66,  //                     (NEC PC98)
		KC_KANA        = 0x70,  // (Japanese keyboard)
		KC_ABNT_C1     = 0x73,  // / ? on Portugese (Brazilian) keyboards
		KC_CONVERT     = 0x79,  // (Japanese keyboard)
		KC_NOCONVERT   = 0x7B,  // (Japanese keyboard)
		KC_YEN         = 0x7D,  // (Japanese keyboard)
		KC_ABNT_C2     = 0x7E,  // Numpad . on Portugese (Brazilian) keyboards
		KC_NUMPADEQUALS= 0x8D,  // = on numeric keypad (NEC PC98)
		KC_PREVTRACK   = 0x90,  // Previous Track (KC_CIRCUMFLEX on Japanese keyboard)
		KC_AT          = 0x91,  //                     (NEC PC98)
		KC_COLON       = 0x92,  //                     (NEC PC98)
		KC_UNDERLINE   = 0x93,  //                     (NEC PC98)
		KC_KANJI       = 0x94,  // (Japanese keyboard)
		KC_STOP        = 0x95,  //                     (NEC PC98)
		KC_AX          = 0x96,  //                     (Japan AX)
		KC_UNLABELED   = 0x97,  //                        (J3100)
		KC_NEXTTRACK   = 0x99,  // Next Track
		KC_NUMPADENTER = 0x9C,  // Enter on numeric keypad
		KC_RCONTROL    = 0x9D,	// Right Ctrl
		KC_MUTE        = 0xA0,  // Mute
		KC_CALCULATOR  = 0xA1,  // Calculator
		KC_PLAYPAUSE   = 0xA2,  // Play / Pause
		KC_MEDIASTOP   = 0xA4,  // Media Stop
		KC_VOLUMEDOWN  = 0xAE,  // Volume -
		KC_VOLUMEUP    = 0xB0,  // Volume +
		KC_WEBHOME     = 0xB2,  // Web home
		KC_NUMPADCOMMA = 0xB3,  // , on numeric keypad (NEC PC98)
		KC_DIVIDE      = 0xB5,  // / on numeric keypad
		KC_SYSRQ       = 0xB7,
		KC_RMENU       = 0xB8,  // right Alt
		KC_PAUSE       = 0xC5,  // Pause
		KC_HOME        = 0xC7,  // Home on arrow keypad
		KC_UP          = 0xC8,  // UpArrow on arrow keypad
		KC_PGUP        = 0xC9,  // PgUp on arrow keypad
		KC_LEFT        = 0xCB,  // LeftArrow on arrow keypad
		KC_RIGHT       = 0xCD,  // RightArrow on arrow keypad
		KC_END         = 0xCF,  // End on arrow keypad
		KC_DOWN        = 0xD0,  // DownArrow on arrow keypad
		KC_PGDOWN      = 0xD1,  // PgDn on arrow keypad
		KC_INSERT      = 0xD2,  // Insert on arrow keypad
		KC_DELETE      = 0xD3,  // Delete on arrow keypad
		KC_LWIN        = 0xDB,  // Left Windows key
		KC_RWIN        = 0xDC,  // Right Windows key
		KC_APPS        = 0xDD,  // AppMenu key
		KC_POWER       = 0xDE,  // System Power
		KC_SLEEP       = 0xDF,  // System Sleep
		KC_WAKE        = 0xE3,  // System Wake
		KC_WEBSEARCH   = 0xE5,  // Web Search
		KC_WEBFAVORITES= 0xE6,  // Web Favorites
		KC_WEBREFRESH  = 0xE7,  // Web Refresh
		KC_WEBSTOP     = 0xE8,  // Web Stop
		KC_WEBFORWARD  = 0xE9,  // Web Forward
		KC_WEBBACK     = 0xEA,  // Web Back
		KC_MYCOMPUTER  = 0xEB,  // My Computer
		KC_MAIL        = 0xEC,  // Mail
		KC_MEDIASELECT = 0xED   // Media Select
	};


	class AIR_INPUT_API KeyEvent : public EventBase
	{
	public:
		KeyEvent(unsigned int evtType, DeviceObject* obj, KeyCode kc, unsigned int txt)
        : EventBase(evtType, obj), key(kc), text(txt)
        {}
        KeyEvent(const KeyEvent&other)
        : EventBase(other.GetEventType(), other.GetEventSender()), key(other.key), text(other.text)
        {}
		virtual ~KeyEvent() {}

	public:
		const KeyCode	key;
		unsigned int	text;
	};


	class AIR_INPUT_API KeyListener
	{
	public:
		virtual ~KeyListener() {}
		virtual bool keyPressed(const KeyEvent &arg) = 0;
		virtual bool keyReleased(const KeyEvent &arg) = 0;		
	};


	class AIR_INPUT_API Keyboard : public DeviceObject
	{
	public:
		virtual ~Keyboard() {};

		virtual bool isKeyDown(KeyCode key) const = 0;

		virtual void setEventCallback(KeyListener *keyListener) { mListener = keyListener;}

		KeyListener* getEventCallback() const {return mListener;}

		enum TextTranslationMode
		{
			Off,
			Unicode,
			Ascii
		};

		virtual void setTextTranslation(TextTranslationMode mode);

		TextTranslationMode getTextTranslation() const {return mTextMode;}

		virtual const std::string& getAsString(KeyCode kc) = 0;

		//! Enum of bit position of modifer
		enum Modifier
		{
			Shift = 0x0000001,
			Ctrl  = 0x0000010,
			Alt   = 0x0000100
		};

		bool isModifierDown(Modifier mod) const;

		virtual void copyKeyStates(char keys[256]) const = 0;
		
	protected:
		Keyboard(const std::string &vendor, bool buffered, int devID, InputManager* creator)
			: DeviceObject(vendor, AISKeyboard, buffered, devID, creator),
			mModifiers(0), mListener(0), mTextMode(Unicode) {}

		//! Bit field that holds status of Alt, Ctrl, Shift
		unsigned int		mModifiers;
		KeyListener			*mListener;
		TextTranslationMode	mTextMode;
	};


}
