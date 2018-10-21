#pragma once
#include "Octree.h"

namespace PCC
{
    // Data the help store and write the encoded data
    struct EncodedData
    {
        EncodedData() : maxDepth(0) {};
        bool isValid();

        BoundingBox sceneBoundingBox;
        unsigned char maxDepth;
        std::vector<unsigned char> encodedData;
    };

    struct TransveralData
    {
        TransveralData(unsigned char level_, Index index_, Node node_) : level(level_), index(index_), node(node_) {}

        unsigned char level;
        Index index;
        Node node;
    };

    class Encoder
    {
        public:
            Encoder();
            virtual ~Encoder();

            EncodedData encode(Octree& octree);

        protected:
            void DepthFirstTransveral(Octree& octree, EncodedData& encodeData);
    };

}