//
// Created by somatic_robot on 2/28/20.
//

#ifndef ROBOT_MAP_EDITOR_HISTORY_HH
#define ROBOT_MAP_EDITOR_HISTORY_HH

#include <list>
#include <pcl-1.7/pcl/point_cloud.h>
#include <pcl-1.7/pcl/point_types.h>

namespace  robot_map_editor {
namespace utils {
    template <typename T>
    class History {
    public:
        explicit History(std::shared_ptr<T> original) : currentObj_(std::move(original)){
            current_ = 0;
        }
    public:
        void MaxSize(size_t mx){
            maxSize_ = mx;
        }

        void Changed(const T& pc) {
            if(current_ >= maxSize_)
                return;
            history_.emplace_back(pc);
            current_++;
        }

        void StepBack(){
            if(current_ == 0)
                return;
            current_--;
            *currentObj_ = history_[current_];
        }

        void StepForward() {
            if(current_ >= history_.size() - 1)
                return;
            current_++;
            *currentObj_ = history_[current_];
        }
    private:
        size_t maxSize_ = 10;
        size_t current_;
        std::vector<T> history_;

        std::shared_ptr<T> currentObj_;
    };
}}

#endif //ROBOT_MAP_EDITOR_HISTORY_HH
