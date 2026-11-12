#include <iostream>
#include <vector>
#include <cstring>
#include <cstdint>

struct NetworkExtension {
    int8_t type;
    int8_t length;
    const char* payload;
};

class PacketProcessor {
public:
    void consolidateExtensions(int8_t num_extensions, const NetworkExtension* ext_array) {
        int8_t total_buffer_size = 0;
        for (size_t i = 0; i < num_extensions; ++i) {
            total_buffer_size += ext_array[i].length; 
        }

        std::cout << "Calculated total size: " << (int)total_buffer_size << " bytes." << std::endl;
        char* consolidated_buffer = new char[total_buffer_size];

        size_t current_offset = 0;
        for (size_t i = 0; i < num_extensions; ++i) {
            std::memcpy(consolidated_buffer + current_offset, ext_array[i].payload, ext_array[i].length);
            current_offset += ext_array[i].length;
        }

        std::cout << "Safely consolidated " << (int)num_extensions << " protocol extensions." << std::endl;
        delete[] consolidated_buffer;
    }
};

int main() {
    const char* dummy_data = "A"; 
    NetworkExtension crafted_packet[2];
    
    crafted_packet[0].type = 0x01;
    crafted_packet[0].length = 100;
    crafted_packet[0].payload = dummy_data;

    crafted_packet[1].type = 0x02;
    crafted_packet[1].length = 50;
    crafted_packet[1].payload = dummy_data;

    PacketProcessor processor;
    processor.consolidateExtensions(2, crafted_packet);

    return 0;
}
