// Copyright © 2017-2020 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#pragma once

///  Registered HD version bytes
///
/// - SeeAlso: https://github.com/satoshilabs/slips/blob/master/slip-0132.md
enum TWHDVersion {
    TWHDVersionNone = 0,

    // Bitcoin
    TWHDVersionXPUB = 0x0488b21e,
    TWHDVersionXPRV = 0x0488ade4,
    TWHDVersionYPUB = 0x049d7cb2,
    TWHDVersionYPRV = 0x049d7878,
    TWHDVersionZPUB = 0x04b24746,
    TWHDVersionZPRV = 0x04b2430c,

    // Litecoin
    TWHDVersionLTUB = 0x019da462,
    TWHDVersionLTPV = 0x019d9cfe,
    TWHDVersionMTUB = 0x01b26ef6,
    TWHDVersionMTPV = 0x01b26792,

    // Decred
    TWHDVersionDPUB = 0x2fda926,
    TWHDVersionDPRV = 0x2fda4e8,

    // Dogecoin
    TWHDVersionDGUB = 0x02facafd,
    TWHDVersionDGPV = 0x02fac398,
};

bool TWHDVersionIsPublic(enum TWHDVersion version);

bool TWHDVersionIsPrivate(enum TWHDVersion version);