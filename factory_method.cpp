#include <iostream>



#define LOG_INFO(log)   std::cout << __LINE__ << ": " << __FUNCTION__ <<  ": " << log << std::endl
#define LOG_ERROR(log)  std::cerr << __LINE__ << ": " << __FUNCTION__ << ": " << log << std::endl

struct Image{

};

struct JpegBuffer {

};


class JpegEncoder {

public:
    virtual int UpdateQuality(const size_t quality) = 0;
    virtual int Encode(const Image& ncvimg, JpegBuffer& jpeg_stream) = 0;
    virtual int Init() = 0;

};

class TurboJpeg: public JpegEncoder {
public:
    TurboJpeg() {
        LOG_INFO("TurboJpeg");
    }

    ~TurboJpeg() {
        LOG_INFO("TurboJpeg");
    }


public:

    virtual int Init() override {
        LOG_INFO("TurboJpeg");
        return 0;

    }

    virtual int UpdateQuality(const size_t quality) override {
        LOG_INFO("TurboJpeg");
        return 0;

    }

    virtual int Encode(const Image& ncvimg, JpegBuffer& jpeg_stream) override {
        LOG_INFO("TurboJpeg");
        return 0;

    }

};

class HisiJpeg: public JpegEncoder{

public:
    HisiJpeg() {
        LOG_INFO("HisiJpeg");
    }

    ~HisiJpeg() {
        LOG_INFO("HisiJpeg");
    }


public:

    virtual int Init() override {


        LOG_INFO("HisiJpeg ok");
        return 0;

        LOG_INFO("HisiJpeg failed");
        return -1;
    }

    virtual int UpdateQuality(const size_t quality) override {
        LOG_INFO("HisiJpeg");
        return 0;

    }

    virtual int Encode(const Image& ncvimg, JpegBuffer& jpeg_stream) override {
        LOG_INFO("HisiJpeg");
        return 0;

    }

};


class Factory {
public:
    virtual JpegEncoder* CreateJpegEncoder() = 0;
    virtual int DestroyJpegEncoder(JpegEncoder* jenc) = 0;
};

class TurboFactory: public Factory{

public:
    virtual JpegEncoder* CreateJpegEncoder() override {

        JpegEncoder* jenc = nullptr;
        jenc = new (std::nothrow) TurboJpeg();
        return jenc;
    }

    virtual int DestroyJpegEncoder(JpegEncoder* jenc) override {

        if (jenc) {
            delete jenc;
        }

        return 0;
    }
};


class HisiFactory: public Factory {

public:
    virtual JpegEncoder* CreateJpegEncoder() override {

        JpegEncoder* jenc = nullptr;
        jenc = new (std::nothrow) HisiJpeg();
        return jenc;
    }

    virtual int DestroyJpegEncoder(JpegEncoder* jenc) override {
        if (jenc) {
            delete jenc;
        }
    }
};


int main(int argc, char* argv[])
{
    Factory* factory = new HisiFactory();//TurboFactory();
    JpegEncoder* jenc = factory->CreateJpegEncoder();

    Image img;
    JpegBuffer buf;
    jenc->Encode(img, buf);

    factory->DestroyJpegEncoder(jenc);

    delete factory;
}
