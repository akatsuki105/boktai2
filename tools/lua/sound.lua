-- mGBA lua script
-- 再生中のサウンドIDを gMPlayTable の各プレイヤーから調べて表示し続ける

-- バッファを作成
local buf = console:createBuffer("Sound")

-- これら4つの値はゲームごとに違うので、調べる必要がある, 他の値は m4a 共通
local M_PLAY_TABLE = 0x0825E3EC  -- gMPlayTable, ROM 上の MusicPlayer の配列
local M_PLAY_COUNT = 32  -- gMPlayTable の要素数
local SONG_TABLE = 0x0825E56C  -- gSongTable, ROM 上の Song の配列, 添字がサウンドID
local SONG_COUNT = 1000  -- gSongTable の要素数

buf:setSize(40, M_PLAY_COUNT+2) -- 文字数単位

local MUSIC_PLAYER_SIZE = 12  -- sizeof(MusicPlayer), info(4), track(4), numTracks(1) + 埋め(1), unk_A(2)
local SONG_SIZE = 8  -- sizeof(Song), header(4), ms(2), me(2)

-- MusicPlayerInfo.status
local STATUS_TRACK = 0x0000FFFF  -- 演奏中のトラックごとに立つビット, 全部 0 なら演奏が終わっている
local STATUS_PAUSE = 0x80000000  -- 停止中のビット

local players
-- songs[ms][songHeader] = サウンドID
local songs

local loadPlayers = function()
  local result = {}
  for ms = 0, M_PLAY_COUNT - 1 do
    local info = emu:read32(M_PLAY_TABLE + ms * MUSIC_PLAYER_SIZE)
    -- info が NULL のプレイヤーは使われない
    if info ~= 0 then
      table.insert(result, { ms = ms, info = info, lastID = 0 })
    end
  end
  return result
end

local loadSongs = function()
  local result = {}
  for id = 0, SONG_COUNT - 1 do
    local entry = SONG_TABLE + id * SONG_SIZE
    local header = emu:read32(entry)  -- Song.header
    local ms = emu:read16(entry + 4)  -- Song.ms, gMPlayTable の添字
    result[ms] = result[ms] or {}
    result[ms][header] = id
  end
  return result
end

local isPlaying = function(status)
  return (status & STATUS_TRACK) ~= 0 and (status & STATUS_PAUSE) == 0
end

local showPlayer = function(player)
  local current = "-"
  if isPlaying(emu:read32(player.info + 4)) then  -- MusicPlayerInfo.status
    local header = emu:read32(player.info)  -- MusicPlayerInfo.songHeader
    local id = songs[player.ms] and songs[player.ms][header]
    if id then
      player.lastID = id
      current = tostring(id)
    else
      -- gSongTable を経由せずに再生された場合
      current = string.format("0x%08X", header)
    end
  end
  buf:print(string.format("[%2d] = %4s (last: %4d)\n", player.ms, current, player.lastID))
end

-- 毎フレーム, 各プレイヤーの再生中のサウンドIDを表示
callbacks:add("frame", function()
  -- 読み込み時にゲームが始まっていないことがあるので, 最初のフレームでテーブルを読む
  if not players then
    players = loadPlayers()
    songs = loadSongs()
  end

  buf:clear()
  buf:moveCursor(0, 0)
  for _, player in ipairs(players) do
    showPlayer(player)
  end
end)
