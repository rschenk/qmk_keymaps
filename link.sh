#!/bin/bash

# generate absolute paths
cur_dir=$(cd "$(dirname "$0")"; pwd)
qmk_dir=$(cd "${cur_dir}/../qmk_firmware"; pwd)

set -x


ln -sfn ${cur_dir}/planck \
        ${qmk_dir}/keyboards/planck/keymaps/rschenk

ln -sfn ${cur_dir}/cospad \
        ${qmk_dir}/keyboards/kprepublic/cospad/keymaps/rschenk
