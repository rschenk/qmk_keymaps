#!/bin/bash

# generate absolute paths
cur_dir=$(cd "$(dirname "$0")"; pwd)
qmk_dir=$(cd "${cur_dir}/../qmk_firmware"; pwd)

set -x

ln -sfn ${cur_dir}/user \
        ${qmk_dir}/users/rschenk

ln -sfn ${cur_dir}/fifi \
        ${qmk_dir}/keyboards/crkbd/keymaps/rschenk

ln -sfn ${cur_dir}/cospad \
        ${qmk_dir}/keyboards/kprepublic/cospad/keymaps/rschenk
