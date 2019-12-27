#pragma once
class EpisodeNotFoundException:public std::runtime_error
{
	std::string name;
public:

	EpisodeNotFoundException(std::string name) :name(name), std::runtime_error("No such episode found.") {}
	std::string getName() const;
};
