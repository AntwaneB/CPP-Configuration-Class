/**
 * Copyright 2015 Antoine Buchser
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * 	 http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <iostream>
#include <stdexcept>
#include "Config.hpp"

Config::Config()
{
}

Config::~Config()
{
}

Config::Param&	Config::operator [](const std::string& key)
{
	if (_params.find(key) == _params.end())
	{
		_params.insert(std::map<std::string, Param>::value_type(key, Param("")));
	}

	return (_params.find(key)->second);
}

Config::Param&	Config::operator [](const char key[])
{
	return (this->operator[](std::string(key)));
}

Config::Param::Param(const std::string & value)
	: _status(Config::Param::VALUE), _value(value)
{
}

Config::Param::Param(const std::map<std::string, Param>& map)
	: _status(Config::Param::MAP), _map(map)
{
}

Config::Param::Param()
{
}

Config::Param& Config::Param::operator [](const std::string& key)
{
	if (_map.find(key) == _map.end())
	{
		_map.insert(std::map<std::string, Param>::value_type(key, Param("")));
	}

	_status = Config::Param::MAP;

	return (_map.find(key)->second);
}

Config::Param& Config::Param::operator [](const char key[])
{
	return (this->operator[](std::string(key)));
}

Config::Param& Config::Param::operator = (bool value)
{
	_status = Config::Param::VALUE;

	_value = value ? "true" : "false";

	return (*this);
}

Config::Param& Config::Param::operator = (char value)
{
	_status = Config::Param::VALUE;

	_value = std::to_string(value);

	return (*this);
}

Config::Param& Config::Param::operator = (short value)
{
	_status = Config::Param::VALUE;

	_value = std::to_string(value);

	return (*this);
}

Config::Param& Config::Param::operator = (int value)
{
	_status = Config::Param::VALUE;

	_value = std::to_string(value);

	return (*this);
}

Config::Param& Config::Param::operator = (long value)
{
	_status = Config::Param::VALUE;

	_value = std::to_string(value);

	return (*this);
}

Config::Param& Config::Param::operator = (double value)
{
	_status = Config::Param::VALUE;

	_value = std::to_string(value);

	return (*this);
}

Config::Param& Config::Param::operator = (float value)
{
	_status = Config::Param::VALUE;

	_value = std::to_string(value);

	return (*this);
}

Config::Param& Config::Param::operator = (std::string const & value)
{
	_status = Config::Param::VALUE;

	_value = value;

	return (*this);
}

Config::Param& Config::Param::operator = (const char value[])
{
	_status = Config::Param::VALUE;

	_value = value;

	return (*this);
}

Config::Param::operator bool (void) const
{
	if (_status == Config::Param::MAP)
		throw std::runtime_error("Current index is not a valid value");

	return (_value == "true");
}

Config::Param::operator char (void) const
{
	if (_status == Config::Param::MAP)
		throw std::runtime_error("Current index is not a valid value");

	return (std::stoi(_value));
}

Config::Param::operator short (void) const
{
	if (_status == Config::Param::MAP)
		throw std::runtime_error("Current index is not a valid value");

	return (std::stoi(_value));
}

Config::Param::operator int (void) const
{
	if (_status == Config::Param::MAP)
		throw std::runtime_error("Current index is not a valid value");

	return (std::stoi(_value));
}

Config::Param::operator long (void) const
{
	if (_status == Config::Param::MAP)
		throw std::runtime_error("Current index is not a valid value");

	return (std::stol(_value));
}

Config::Param::operator double (void) const
{
	if (_status == Config::Param::MAP)
		throw std::runtime_error("Current index is not a valid value");

	return (std::stod(_value));
}

Config::Param::operator float (void) const
{
	if (_status == Config::Param::MAP)
		throw std::runtime_error("Current index is not a valid value");

	return (static_cast<float>(std::stod(_value)));
}

Config::Param::operator std::string (void) const
{
	if (_status == Config::Param::MAP)
		throw std::runtime_error("Current index is not a valid value");

	return (_value);
}
