//#include "breadwallet-core/breadwallet-core.h"

//Support headers
#include "breadwallet-core/support/BRAddress.h"
#include "breadwallet-core/support/BRBech32.h"
#include "breadwallet-core/support/BRArray.h"
#include "breadwallet-core/support/BRCrypto.h"
#include "breadwallet-core/support/BRAssert.h"
#include "breadwallet-core/support/BRFileService.h"
#include "breadwallet-core/support/BRBIP32Sequence.h"
#include "breadwallet-core/support/BRInt.h"
#include "breadwallet-core/support/BRBIP39Mnemonic.h"
#include "breadwallet-core/support/BRKey.h"
#include "breadwallet-core/support/BRBIP39WordsEn.h"
#include "breadwallet-core/support/BRKeyECIES.h"
#include "breadwallet-core/support/BRBase.h"
#include "breadwallet-core/support/BRSet.h"
#include "breadwallet-core/support/BRBase58.h"

//include headers
#include "breadwallet-core/include/BRCryptoAccount.h"
#include "breadwallet-core/include/BRCryptoAddress.h"
#include "breadwallet-core/include/BRCryptoAmount.h"
#include "breadwallet-core/include/BRCryptoBase.h"
#include "breadwallet-core/include/BRCryptoCipher.h"
#include "breadwallet-core/include/BRCryptoCoder.h"
#include "breadwallet-core/include/BRCryptoCurrency.h"
#include "breadwallet-core/include/BRCryptoFeeBasis.h"
#include "breadwallet-core/include/BRCryptoHash.h"
#include "breadwallet-core/include/BRCryptoHasher.h"
#include "breadwallet-core/include/BRCryptoKey.h"
#include "breadwallet-core/include/BRCryptoNetwork.h"
#include "breadwallet-core/include/BRCryptoPayment.h"
#include "breadwallet-core/include/BRCryptoPeer.h"
#include "breadwallet-core/include/BRCryptoSigner.h"
#include "breadwallet-core/include/BRCryptoStatus.h"
#include "breadwallet-core/include/BRCryptoSync.h"
#include "breadwallet-core/include/BRCryptoTransfer.h"
#include "breadwallet-core/include/BRCryptoUnit.h"
#include "breadwallet-core/include/BRCryptoWallet.h"
#include "breadwallet-core/include/BRCryptoWalletManager.h"
#include "breadwallet-core/include/BRCryptoWalletManagerClient.h"

//crypto headers
#include "breadwallet-core/crypto/BRCryptoAccountP.h"
#include "breadwallet-core/crypto/BRCryptoAddressP.h"
#include "breadwallet-core/crypto/BRCryptoAmountP.h"
#include "breadwallet-core/crypto/BRCryptoBaseP.h"
#include "breadwallet-core/crypto/BRCryptoConfig.h"
#include "breadwallet-core/crypto/BRCryptoFeeBasisP.h"
#include "breadwallet-core/crypto/BRCryptoHashP.h"
#include "breadwallet-core/crypto/BRCryptoKeyP.h"
#include "breadwallet-core/crypto/BRCryptoNetworkP.h"
#include "breadwallet-core/crypto/BRCryptoPaymentP.h"
#include "breadwallet-core/crypto/BRCryptoStatusP.h"
#include "breadwallet-core/crypto/BRCryptoTransferP.h"
#include "breadwallet-core/crypto/BRCryptoWalletManagerP.h"
#include "breadwallet-core/crypto/BRCryptoWalletP.h"

//Bitcoin headers
#include "breadwallet-core/bitcoin/BRChainParams.h"
#include "breadwallet-core/bitcoin/BRBIP38Key.h"
#include "breadwallet-core/bitcoin/BRBloomFilter.h"
#include "breadwallet-core/bitcoin/BRMerkleBlock.h"
#include "breadwallet-core/bitcoin/BRPeerManager.h"
#include "breadwallet-core/bitcoin/BRSyncManager.h"
#include "breadwallet-core/bitcoin/BRTransaction.h"
#include "breadwallet-core/bitcoin/BRWallet.h"
#include "breadwallet-core/bitcoin/BRPaymentProtocol.h"
#include "breadwallet-core/bitcoin/BRWalletManager.h"
#include "breadwallet-core/bitcoin/BRPeer.h"
#include "breadwallet-core/bitcoin/BRWalletManagerPrivate.h"

//bcash headers
#include "breadwallet-core/bcash/BRBCashAddr.h"
#include "breadwallet-core/bcash/BRBCashParams.h"

//etherum headers
#include "breadwallet-core/ethereum/BREthereum.h"
#include "breadwallet-core/ethereum/test.h"

//generic headers
#include "breadwallet-core/generic/BRGeneric.h"
#include "breadwallet-core/generic/BRGenericBase.h"
#include "breadwallet-core/generic/BRGenericClient.h"
#include "breadwallet-core/generic/BRGenericHandlers.h"
//#include "breadwallet-core/generic/BRGenericHedera.h"
#include "breadwallet-core/generic/BRGenericPrivate.h"
#include "breadwallet-core/generic/BRGenericRipple.h"

//hedera headers
/*#include "breadwallet-core/hedera/BRHedera.h"
#include "breadwallet-core/hedera/BRHederaAccount.h"
#include "breadwallet-core/hedera/BRHederaAddress.h"
#include "breadwallet-core/hedera/BRHederaBase.h"
#include "breadwallet-core/hedera/BRHederaCrypto.h"
#include "breadwallet-core/hedera/BRHederaFeeBasis.h"
#include "breadwallet-core/hedera/BRHederaSerialize.h"
#include "breadwallet-core/hedera/BRHederaTransaction.h"
#include "breadwallet-core/hedera/BRHederaWallet.h"

#include "breadwallet-core/hedera/proto/BasicTypes.pb-c.h"
#include "breadwallet-core/hedera/proto/CryptoTransfer.pb-c.h"
#include "breadwallet-core/hedera/proto/Duration.pb-c.h"
#include "breadwallet-core/hedera/proto/Timestamp.pb-c.h"
#include "breadwallet-core/hedera/proto/Transaction.pb-c.h"
#include "breadwallet-core/hedera/proto/TransactionBody.pb-c.h"
#include "breadwallet-core/hedera/proto/protobuf-c.h" */

//skipped ripple headers

//vendor headers
// ed25519 headers
/*#include "breadwallet-core/vendor/ed25519/ed25519.h"
#include "breadwallet-core/vendor/ed25519/fe.h"
#include "breadwallet-core/vendor/ed25519/fixedint.h"
#include "breadwallet-core/vendor/ed25519/ge.h"
#include "breadwallet-core/vendor/ed25519/precomp_data.h"
#include "breadwallet-core/vendor/ed25519/sc.h"
#include "breadwallet-core/vendor/ed25519/sha512.h"*/


//sep256k1 headers
//no header files

//sqlite3 headers
#include "breadwallet-core/vendor/sqlite3/config.h"
#include "breadwallet-core/vendor/sqlite3/sqlite3.h"
#include "breadwallet-core/vendor/sqlite3/sqlite3ext.h"






