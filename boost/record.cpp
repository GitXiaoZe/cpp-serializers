#include "boost/record.hpp"

namespace boost_test {

void
to_string(const Record &record, std::string &data)
{
    std::ostringstream stream;
    boost::archive::binary_oarchive archiver(stream);
    archiver << record;

    data = stream.str();
}

void
from_string(Record &record, const std::string &data)
{
    std::stringstream stream(data);
    boost::archive::binary_iarchive archiver(stream);
    archiver >> record;
}

void serialize_iteration(std::ostringstream &stream, const Record *records, size_t iterations){
    boost::archive::binary_oarchive archiver(stream);
    for(size_t s = 0; s < iterations; s++){
        archiver << records[s];
    }
}

void deserialize_iteration(std::stringstream &stream, Record *records, size_t iterations){
    boost::archive::binary_iarchive archiver(stream);
        for(size_t s = 0; s < iterations; s++){
        archiver >> records[s];
    }
}

} // namespace
