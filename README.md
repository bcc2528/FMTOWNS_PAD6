# FMTOWNS_PAD6
FM TOWNS用6ボタンパッドのボタン入力状態を返すHigh Cコンパイラ用ライブラリ(+α)です。オマケでTBIOSのEGB_paletteを使わずにVsync待ち、パレット変更を行う関数付き。  
自作のFM TOWNS用High CコンパイラソースコードにPAD6.hをインクルードしてコンパイル、PAD6.libをリンクしてください。  
High C コンパイラ V1.7 L12でコンパイル及びテスト。  


testフォルダ内のtest.expはこのライブラリを使用して6ボタンパッドのテストを行うプログラムです。ライブラリそのものを使う予定が無くとも、これで6ボタンパッドの動作確認ができます。2ボタンパッドで実行すると十字キーを押した際にCXYZボタンが押されるという判定になるのは仕様です。  RUNとSELECTボタンを同時押しすることで終了します。


# 関数説明   


### 関数: PAD6_in(int port)
このライブラリの肝心要の関数。6ボタンパッドの入力状態を取得します。2ボタンパッドを接続時にこの関数を呼ぶと、Up・Down・Left・RingがそれぞれZ・X・Y・Cも同時に押されているという判定になってしまいます。2ボタンパッド使用時は通常のTBIOS SND_joy_in_1・2を呼んでください。
#### 引数: int型 port
ポート番号指定。0でパッド1側の読み込み、1でパッド2側の読み込み、それ以外の場合は返り値が0xffffffffで返ってくる。  
#### 返り値: unsigned int型
0-11bitの計12bitにそれぞれのボタン入力状態が格納される。bitがオフの時はボタンが押されていて、オンの時はボタンが離されている。  
各bitのボタン割り当て  
0bit: Up  
1bit: Down  
2bit: Left  
3bit: Right  
4bit: A  
5bit: B  
6bit: RUN  
7bit: SELECT  
8bit: Z  
9bit: Y  
10bit: X  
11bit: C  
RUNが押されている場合はUpとDownは離されている、SELECTが押されている場合はLeft・Rightは離されている判定となります。  

##
### 関数: Vsync_wait()
この関数を読み出すとVsync期間に到達するまで停止します。ループ内に1箇所入れることで約1/60(画面モードによっては55?)秒単位で一定ウェイトを取ることができます。
#### 引数: なし
#### 戻り値: なし

##
### 関数: Set_palette(unsigned char num, unsigned char r, unsigned g, unsigned b)
画面の1パレット分のみを変更します。16色及び256色画面でのみ有効。
#### 引数: unsigned char型 num
パレット番号を指定します。16色画面モードでは0～15、256色画面モードでは0～255の値まで有効です。
#### 引数: unsigned char型 r
赤の明度を設定します。16色画面では上位4bit(4～7bit)に対して16階調、256色画面では256階調で設定します。
#### 引数: unsigned char型 g
緑の明度を設定します。16色画面では上位4bit(4～7bit)に対して16階調、256色画面では256階調で設定します。
#### 引数: unsigned char型 b
青の明度を設定します。16色画面では上位4bit(4～7bit)に対して16階調、256色画面では256階調で設定します。
#### 戻り値: なし


#
参考: Oh! FM TOWNS 1994年12月号 142p INSIDE TOWNS 「貴方のオリジナルソフトでも6ボタンパッドを！」(Makken著)
