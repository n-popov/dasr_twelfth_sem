class Handler {
public:
    virtual void preProcess() {}
    virtual void postProcess() {}
    virtual void run() = 0;
    virtual bool accessAllowed(string username) {
        return true;
    }
    virtual ~Handler() = default;
};