#include <stdio.h>
#include <memory>
#include <cassert>

int main()
{
    std::shared_ptr<int> sptr = std::make_shared<int>(200);
    assert(sptr.use_count() == 1);
    {
        std::shared_ptr<int> sptr1 = sptr;
        assert(sptr.get() == sptr1.get());
        assert(sptr.use_count() == 2);
    }
    assert(sptr.use_count() == 1);

    return 0;
}