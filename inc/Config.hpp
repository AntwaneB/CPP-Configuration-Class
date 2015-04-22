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

#ifndef CONFIG_HPP
#define	CONFIG_HPP

#include <string>
#include <map>

class Config
{
public:
	class Param
	{
	public:
		enum Status { MAP, VALUE };

	public:
		Param();
		Param(std::string const & value);
		Param(std::map<std::string, Param> const & map);

		operator bool () const;
		operator char () const;
		operator short () const;
		operator int () const;
		operator long () const;
		operator double () const;
		operator float () const;
		operator std::string () const;

		Param& operator = (bool);
		Param& operator = (char);
		Param& operator = (short);
		Param& operator = (int);
		Param& operator = (long);
		Param& operator = (double);
		Param& operator = (float);
		Param& operator = (std::string const &);
		Param& operator = (const char[]);

		Param& operator [] (std::string const &);
		Param& operator [] (const char[]);

	private:
		Param::Status						_status;
		std::string							_value;
		std::map<std::string, Param>	_map;
	};

public:
	Config();
	virtual ~Config();

	Config::Param&	operator [] (std::string const &);
	Config::Param&	operator [] (const char[]);

private:
	std::map<std::string, Param>	_params;
};

#endif	/* CONFIG_HPP */
