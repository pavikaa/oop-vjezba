#pragma once
class Description
{
	friend std::ostream& operator<< (std::ostream&, const Description&);
	friend std::istream& operator>> (std::istream&, Description&);
	friend bool operator==(const Description&, const Description&);
	int noEpisode;
	float length;
	std::string name;
public:
	Description() :noEpisode(0), length(0.0), name("Pilot") {}
	Description(int noEpisode, float length, std::string name) :noEpisode(noEpisode), length(length), name(name) {}
	~Description() {}
	void setnoEpisode(int);
	void setLength(float);
	void setName(std::string);
	int getnoEpisode() const;
	float getLength() const;
	std::string getName() const;
};