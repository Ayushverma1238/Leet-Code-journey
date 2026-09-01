class AuthenticationManager {
private:
    int ttl;
    // Map storing tokenId -> absolute expiration time
    std::unordered_map<std::string, int> expiryMap;

public:
    AuthenticationManager(int timeToLive) {
        ttl = timeToLive;
    }
    
    void generate(string tokenId, int currentTime) {
        expiryMap[tokenId] = currentTime + ttl;
    }
    
    void renew(string tokenId, int currentTime) {
        // Token must exist and its expiry time must be strictly greater than currentTime
        if (expiryMap.count(tokenId) && expiryMap[tokenId] > currentTime) {
            expiryMap[tokenId] = currentTime + ttl;
        }
    }
    
    int countUnexpiredTokens(int currentTime) {
        int count = 0;
        for (const auto& [id, expiryTime] : expiryMap) {
            if (expiryTime > currentTime) {
                count++;
            }
        }
        return count;
    }
};