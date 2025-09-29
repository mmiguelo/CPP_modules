#include "../sed.hpp"

// replaces s1 for s2 inside buffer
static void replace_in_buffer(std::string &buffer, const std::string &s1, const std::string &s2)
{
	if (s1.empty())
		return ;
	size_t	pos = 0;
	while((pos = buffer.find(s1, pos)) != std::string::npos)
	{
		buffer.erase(pos, s1.length());
		buffer.insert(pos, s2);
		pos += s2.length();
	}
}

void sed(const std::string &filename, const std::string &s1, const std::string &s2)
{
	//opens file
	std::ifstream infile(filename.c_str());
	if (!infile)
	{
		std::cerr << R << "Error: Cannot open file " << RST << std::endl;
		return ;
	}

	std::ofstream outfile((filename + ".replace").c_str(), std::ios::out | std::ios::binary);
    if (!outfile)
    {
        std::cerr << R << "Error: cannot create output file" << RST << std::endl;
        return ;
    }

	std::string buffer;
	char	chunk[CHUNK_SIZE + 1];
	std::string overlap;

	while (!infile.eof())
	{
		infile.read(chunk, CHUNK_SIZE);
		std::streamsize bytesRead = infile.gcount();
		buffer = overlap + std::string(chunk, bytesRead);

		replace_in_buffer(buffer, s1, s2);
		if (buffer.length() >= s1.length() - 1)
		{
			overlap = buffer.substr(buffer.length() - (s1.length() - 1));
			buffer.erase(buffer.length() - (s1.length() - 1));
		}
		else
		{
			overlap = buffer;
			buffer.clear();
		}
        outfile << buffer;
	}

	// process leftovers
	if (!overlap.empty())
	{
		replace_in_buffer(overlap, s1, s2);
		outfile << overlap;
	}

	infile.close();
	outfile.close();
}