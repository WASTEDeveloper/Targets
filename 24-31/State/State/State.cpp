#include "stdafx.h"
#include "State.h"

Grant::Grant(State * state_)
{
	_state = state_;
}

status Grant::get_status()
{
	return _state->get_status();
}

void Grant::Process()
{
	_state = _state->Process();
}

void Grant::Delayed()
{
	_state = _state->Delay();
}

void Grant::Accept()
{
	_state = _state->Accept();
}

void Grant::Deny()
{
	_state = _state->Deny();
}

void Grant::Recall()
{
	_state = _state->Recall();
}

status State::get_status() const
{
	return _status;
}

State * State::Create()
{
	return this;
}

State * State::Process()
{
	return this;
}

State * State::Delay()
{
	return this;
}

State * State::Accept()
{
	return this;
}

State * State::Deny()
{
	return this;
}

State * State::Recall()
{
	return this;
}

Created::Created()
{
	_status = status::created;
}

State * Created::Process()
{
	return new Processed();
}

State * Created::Delay()
{

	return new Delayed();
}

Processed::Processed()
{
	_status = status::processing;
}

State * Processed::Delay()
{
	return new Delayed();
}

State * Processed::Accept()
{
	return new Accepted();
}

State * Processed::Deny()
{
	return new Denyed();
}

Delayed::Delayed()
{
	_status = status::delayed;
}

State * Delayed::Process()
{
	return new Processed();
}

Accepted::Accepted()
{
	_status = status::accepted;
}

State * Accepted::Recall()
{
	return new Recalled();
}

Denyed::Denyed()
{
	_status = status::denyed;
}

Recalled::Recalled()
{
	_status = status::recalled;
}
