#pragma once

/// /section  stream interface midi objects
/// ref: http://www.gweep.net/~prefect/eng/reference/protocol/midispec.html

/// send a note on event (also set vel = 0 for noteoff)
struct NoteOn {

	const int channel;	///< channel 1 - 16
	const int pitch;	///< pitch 0 - 127
	const int velocity;	///< velocity 0 - 127
	
	explicit NoteOn(const int channel, const int pitch, const int velocity=64) :
		channel(channel), pitch(pitch), velocity(velocity) {}
};

/// send a note off event (velocity is usually ignored
struct NoteOff {

	const int channel;	///< channel 1 - 16
	const int pitch;	///< pitch 0 - 127
	const int velocity;	///< velocity 0 - 127
	
	explicit NoteOff(const int channel, const int pitch, const int velocity=64) :
		channel(channel), pitch(pitch), velocity(velocity) {}
};

/// change a control value aka send a CC message
struct ControlChange {

	const int channel;		///< channel 1 - 16
	const int controller;	///< controller 0 - 127
	const int value;		///< value 0 - 127
	
	explicit ControlChange(const int channel, const int controller, const int value) :
		channel(channel), controller(controller), value(value) {}
};

/// change a program value (ie an instrument)
struct ProgramChange {

	const int channel;	///< channel 1 - 16
	const int value;	///< value 0 - 127
	
	explicit ProgramChange(const int channel, const int value) :
		channel(channel), value(value) {}
};

/// change the pitch bend value
struct PitchBend {

	const int channel;	///< channel 1 - 16
	const int value;	///< value 0 - 16383
	
	explicit PitchBend(const int channel, const int value) :
		channel(channel), value(value) {}
};

/// change an aftertouch value
struct Aftertouch {

	const int channel;	///< channel 1 - 16
	const int value;	///< value 0 - 127
	
	explicit Aftertouch(const int channel, const int value) :
		channel(channel), value(value) {}
};

/// change a poly aftertouch value
struct PolyAftertouch {

	const int channel;	///< channel 1 - 16
	const int pitch;	///< controller 0 - 127
	const int value;	///< value 0 - 127
	
	explicit PolyAftertouch(const int channel, const int pitch, const int value) :
		channel(channel), pitch(pitch), value(value) {}
};

/// start a raw midi byte stream
struct StartMidi {
	explicit StartMidi() {}
};

/// finish a midi byte stream
struct FinishMidi {
	explicit FinishMidi() {}
};
