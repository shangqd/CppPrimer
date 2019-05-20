#include <sys/prctl.h>
void SetThreadName(const char* name)
{
    ::prctl(PR_SET_NAME, name, 0, 0, 0);
}

    template<typename InputFunc, typename TransFunc>
    bool Execute(const uint32_t nTotal, InputFunc fnInput, TransFunc fnTrans)
    {
        std::atomic_size_t nCurrent;
        nCurrent.store(0);

        uint8_t nThreads = std::min(nTotal, (uint32_t)nParallelNum);
        std::vector<std::future<bool> > vFuture(nThreads);
        for (int i = 0; i < nThreads; ++i)
        {
            vFuture[i] = std::async(std::launch::async, [&] {
                try
                {
                    size_t nIndex;
                    while ((nIndex = nCurrent.fetch_add(1)) < nTotal)
                    {
                        auto params = fnInput(nIndex);
                        ExecuteFunction(fnTrans, params, IsTuple<typename std::decay<decltype(params)>::type>());
                    }
                    return true;
                }
                catch (std::exception& e)
                {
                    blockhead::StdError(__PRETTY_FUNCTION__, e.what());
                    return false;
                }
            });
        }

        bool ret = true;
        std::for_each(vFuture.begin(), vFuture.end(), [&ret] (std::future<bool>& f) { ret &= f.get(); });
        return ret;
    }