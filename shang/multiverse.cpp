// Copyright (c) 2017-2019 The Multiverse developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "entry.h"
#include <iostream>
#include <exception>
#include <walleve/walleve.h>

#include "crypto.h"
#include "mpvss.h"

using namespace multiverse;

void MvShutdown()
{
    CMvEntry::GetInstance().Stop();
}

void test_()
{
    srand(time(0));
    for (size_t count = 50; count <= 50; count++)
    {
        uint256 nInitValue;
        std::vector<uint256> vID;
        std::map<uint256,CMPSecretShare> mapSS;
        std::vector<CMPCandidate> vCandidate;

        CMPSecretShare ssWitness;

        boost::posix_time::ptime t0;
        std::cout << "Test mpvss begin: count " << count << "\n{\n";
        vID.resize(count); 

        vCandidate.resize(count);
        //Setup
        t0 = boost::posix_time::microsec_clock::universal_time();
        for (int i = 0;i < count;i++)
        {
            vID[i] = uint256(i + 1);
            mapSS[vID[i]] = CMPSecretShare(vID[i]);

            CMPSealedBox box;
            mapSS[vID[i]].Setup(count + 1,box);   
            vCandidate[i] = CMPCandidate(vID[i],1,box);
            nInitValue = nInitValue ^ mapSS[vID[i]].myBox.vCoeff[0];
        }
        std::cout << "\tSetup : " << ((boost::posix_time::microsec_clock::universal_time() - t0).ticks() / count) <<"\n";
        std::cout << "\tInit value = " << nInitValue.GetHex() << "\n";
        {
            CMPSealedBox box;
            ssWitness.Setup(count + 1,box);
        }

        
        //Enroll
        t0 = boost::posix_time::microsec_clock::universal_time();
        for (int i = 0;i < count;i++)
        {   
            std::cout << i << std::endl;
            mapSS[vID[i]].Enroll(vCandidate);
        }
        std::cout << "\tEnroll : " << ((boost::posix_time::microsec_clock::universal_time() - t0).ticks() / count) <<"\n";
        ssWitness.Enroll(vCandidate);
        
        // Distribute
        t0 = boost::posix_time::microsec_clock::universal_time();
        for (int i = 0;i < count;i++)
        {
            std::map<uint256,std::vector<uint256> > mapShare;
            mapSS[vID[i]].Distribute(mapShare);
            for (int j = 0;j < count;j++)
            {
                if (i != j)
                {
                    assert( mapSS[vID[j]].Accept(vID[i],mapShare[vID[j]]) );
                }
            }
        }
        std::cout << "\tDistribute : " << ((boost::posix_time::microsec_clock::universal_time() - t0).ticks() / count) <<"\n";
 
        // Publish
        t0 = boost::posix_time::microsec_clock::universal_time();
        std::vector< std::map<uint256,std::vector<uint256> > > vecMapShare;
        vecMapShare.resize(count);
        for (int i = 0;i < count;i++)
        {
            mapSS[vID[i]].Publish(vecMapShare[i]);
        }

        for (int i = 0;i < count;i++)
        {
            bool fCompleted = false;
            for (int j = 0;j < count;j++)
            {
                int indexFrom = (i + j) % count;
                assert( mapSS[vID[i]].Collect(vID[indexFrom], vecMapShare[indexFrom], fCompleted) );
            }
            assert( fCompleted );
        }

        bool fCompleted = false;
        for (int i = 0; i < count; i++)
        {
            assert( ssWitness.Collect(vID[i],vecMapShare[i],fCompleted) );
        }
        assert( fCompleted );

        std::cout << "\tPublish : " << ((boost::posix_time::microsec_clock::universal_time() - t0).ticks() / count) <<"\n";

        // Reconstruct 
        t0 = boost::posix_time::microsec_clock::universal_time();
        for (int i = 0;i < count;i++)
        {
            uint256 nRecValue;
            std::map<uint256,std::pair<uint256,std::size_t> > mapSecret;
            mapSS[vID[i]].Reconstruct(mapSecret);
            for (std::map<uint256,std::pair<uint256,std::size_t> >::iterator it = mapSecret.begin();it != mapSecret.end();++it)
            {
                nRecValue = nRecValue ^ (*it).second.first;
            }
            std::cout << "\tReconstruct candidate " << i << " : " << nRecValue.GetHex() << "\n";
            assert( nRecValue == nInitValue );
        }
        std::cout << "\tReconstruct : " << ((boost::posix_time::microsec_clock::universal_time() - t0).ticks() / count) <<"\n";;

        uint256 nRecValue;
        std::map<uint256,std::pair<uint256,std::size_t> > mapSecret;
        ssWitness.Reconstruct(mapSecret);
        for (std::map<uint256,std::pair<uint256,std::size_t> >::iterator it = mapSecret.begin();it != mapSecret.end();++it)
        {
            nRecValue = nRecValue ^ (*it).second.first;
        }
        std::cout << "\tReconstruct witness : " << nRecValue.GetHex() << "\n";
        std::cout << "}\n";
        assert( nRecValue == nInitValue );
    }
}

int main(int argc,char **argv)
{
    //test_();
    //return 0;
    CMvEntry& mvEntry = CMvEntry::GetInstance();
    try
    {
        if (mvEntry.Initialize(argc,argv))
        {
            mvEntry.Run();
        }
    }
    catch (std::exception& e)
    {
        StdError(__PRETTY_FUNCTION__, e.what());
    }
    catch (...)
    {
        StdError(__PRETTY_FUNCTION__, "unknown");
    }

    mvEntry.Exit();

    return 0;
}
