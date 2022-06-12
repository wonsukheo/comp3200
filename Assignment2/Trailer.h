#pragma once

namespace assignment2
{
	class Trailer
	{
	public:
		Trailer(unsigned int weight);
		~Trailer();

		Trailer(const Trailer& other);

		unsigned int GetWeight() const;

	private:
		unsigned int mWeight;
	};
}
