#include "cereal/record.hpp"

namespace cereal_test {

void
to_string(const Record &record, std::string &data)
{
    std::ostringstream stream;
    cereal::BinaryOutputArchive archive(stream);
    archive(record);
    data = stream.str();
}

void
from_string(Record &record, const std::string &data)
{
    std::stringstream stream(data);
    cereal::BinaryInputArchive archive(stream);
    archive(record);
}

void serialize_iteration(std::ostringstream &stream, const Record *records, size_t iterations){
    cereal::BinaryOutputArchive archive(stream);
    for(size_t s = 0; s < iterations; s++){
        archive(records[s]);
    }
}

void deserialize_iteration(std::stringstream &stream, Record *records, size_t iterations){
    cereal::BinaryInputArchive archive(stream);
    for(size_t s = 0; s < iterations; s++){
        archive(records[s]);
    }
}

} // namespace
