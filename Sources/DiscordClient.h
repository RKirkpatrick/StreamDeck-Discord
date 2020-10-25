#pragma once

#include <functional>
#include <string>

class DiscordClientThread;
class RpcConnection;

class DiscordClient {
 public:
#define DISCORD_CLIENT_RPCSTATES \
  X(UNINITIALIZED) X(CONNECTING) X(REQUESTING_USER_PERMISSION) \
    X(REQUESTING_ACCESS_TOKEN) X(AUTHENTICATING_WITH_ACCESS_TOKEN) \
    X(REQUESTING_VOICE_STATE) X(READY) X(CONNECTION_FAILED) \
    X(AUTHENTICATION_FAILED) X(DISCONNECTED)

  enum class RpcState {
#define X(y) y,
    DISCORD_CLIENT_RPCSTATES
#undef X
  };
  static const char* getRpcStateName(RpcState state);

  struct State {
    RpcState rpcState;
    bool isDeafened;
    bool isMuted;
  };
  typedef std::function<void(const State&)> StateCallback;
  struct Credentials {
    std::string accessToken;
    std::string refreshToken;
    std::string setValue;
  };
  typedef std::function<void(const Credentials&)> CredentialsCallback;

  DiscordClient(
    const std::string& appId,
    const std::string& appSecret,
    const Credentials& credentials);
  ~DiscordClient();

  State getState() const;
  void onStateChanged(StateCallback);
  void onReady(StateCallback);
  void onCredentialsChanged(CredentialsCallback);

  void setIsMuted(bool);
  void setIsDeafened(bool);

  // Easy mode...
  void initializeWithBackgroundThread();

  // ... or, call these
  void initialize();
  bool processEvents();

  std::string getAppId() const;
  std::string getAppSecret() const;

 private:
  RpcConnection* mConnection;
  State mState;
  Credentials mCredentials;
  StateCallback mReadyCallback;
  StateCallback mStateCallback;
  CredentialsCallback mCredentialsCallback;
  std::string mAppId;
  std::string mAppSecret;
  DiscordClientThread* mProcessingThread;

  Credentials getOAuthCredentials(
    const std::string& grantType,
    const std::string& secretType,
    const std::string& secret);
  void setRpcState(RpcState state);
  void setRpcState(RpcState oldState, RpcState newState);
  std::string getNextNonce();
  bool processInitializationEvents();
  void startAuthenticationWithNewAccessToken();
};
