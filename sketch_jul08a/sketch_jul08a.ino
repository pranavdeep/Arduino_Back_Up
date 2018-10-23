/*
Fabiano A. Arndt - 2016
www.youtube.com/user/fabianoallex
www.facebook.com/dicasarduino
fabianoallex@gmail.com
*/
  
/*************************************************************************************************************
*******************************BIT ARRAY *********************************************************************
**************************************************************************************************************
mais informações aqui: http://fabianoallex.blogspot.com.br/2015/09/arduino-array-de-bits.html
**************************************************************************************************************/
class BitArray2D {
  private:
    unsigned int _rows;
    unsigned int _columns;
    unsigned int _cols_array; //pra cada 8 colunas, 1 byte é usado 
    byte**       _bits;
  public:
    BitArray2D(unsigned int rows, unsigned int columns){
      _rows       = rows;
      _columns    = columns;
      _cols_array = columns/8 + (_columns%8 ? 1 : 0) + 1; //divide por 8 o número de colunas
      _bits = (byte **)malloc(_rows * sizeof(byte *));
      for(int i=0;i<_rows;i++){ _bits[i] = (byte *)malloc(  _cols_array  *  sizeof(byte)); } //cria varios arrays
      clear();
    }
    unsigned int rows(){ return _rows; }
    unsigned int columns(){ return _columns; }
    void clear() { 
      for(int i=0;i<_rows;i++){      
        for(int j=0; j<_cols_array;j++) { _bits[i][j] = B00000000; }       
      }   
    }
    void write(unsigned int row, unsigned int column, int value){
      byte b = _bits[row][ column/8 + (column%8 ? 1 : 0) ];
      unsigned int bit = column%8;    
      if (value) { b |= (1 << bit); } else { b &= ~(1 << bit);  }
      _bits[row][ column/8 + (column%8 ? 1 : 0) ] = b;
    }
    void write(byte value){
      for(int i=0;i<_rows;i++){      
        for(int j=0; j<_cols_array;j++) {      
          _bits[i][j] = value ? B11111111 : B00000000;     
        }       
      }  
    }
    int read(unsigned int row, unsigned int column){
      byte b = _bits[row][ column/8 + (column%8 ? 1 : 0) ];
      unsigned int bit = column%8;    
      return (b & (1 << bit)) != 0;
    }
    void toggle(unsigned int row, unsigned int column){ write(row, column, !read(row, column)); }
    void toggle(){ for(int i=0;i<_rows;i++){      for(int j=0; j<_columns;j++) {      toggle(i,j);   }   }   }
};
/*************************************************************************************************************
*******************************FIM BIT ARRAY *****************************************************************
**************************************************************************************************************/
     
/*************************************************************************************************************
************************************CLASSE UNIQUE RANDOM******************************************************
**************************************************************************************************************
mais informações aqui: http://fabianoallex.blogspot.com.br/2015/09/arduino-numeros-aleatorio-repetidos-e.html
*************************************************************************************************************/
class UniqueRandom{
  private:
    int _index;
    int _min;
    int _max;
    int _size;
    int* _list;
    void _init(int min, int max) {
      _list = 0; 
      if (min < max) { _min = min; _max = max; } else { _min = max; _max = min; }
      _size = _max - _min; 
      _index = 0;
    }    
  public:
    UniqueRandom(int max)           { _init(0,   max); randomize(); } //construtor com 1 parametro
    UniqueRandom(int min, int max)  { _init(min, max); randomize(); } //construtor com 2 parametros
    void randomize() {
      _index = 0;
      if (_list == 0) { _list = (int*) malloc(size() * sizeof(int)); }  
      for (int i=0; i<size(); i++) {   _list[i] = _min+i;  }   //preenche a lista do menor ao maior valor
      //embaralha a lista
      for (int i=0; i<size(); i++) {  
        int r = random(0, size());     //sorteia uma posição qualquer
        int aux = _list[i];               
        _list[i] = _list[r];
        _list[r] = aux;
      }
    }
    int next() {                                  //retorna o proximo numero da lista
      int n = _list[_index++];
      if (_index >= size() ) { _index = 0;} //após recuper o ultimo numero, recomeça na posicao 0
      return n;
    }
    void first() { _index = 0; }
    boolean eof() { return size() == _index+1; }
    int size() { return _size; }
    int getIndex() {  return _index; }
    ~UniqueRandom(){ free ( _list ); }  //destrutor
};
/*************************************************************************************************************
************************************FIM CLASSE UNIQUE RANDOM**************************************************
*************************************************************************************************************/
     
/*************************************************************************************************************
*******************************LEDCONTROL ALTERADA************************************************************
mais informações: http://fabianoallex.blogspot.com.br/2015/09/arduino-alteracoes-na-biblioteca.html
**************************************************************************************************************/
//the opcodes for the MAX7221 and MAX7219
#define OP_DECODEMODE  9
#define OP_INTENSITY   10
#define OP_SCANLIMIT   11
#define OP_SHUTDOWN    12
#define OP_DISPLAYTEST 15
class LedControl {
  private :
    byte spidata[16];
    byte * status;
    int SPI_MOSI;
    int SPI_CLK;
    int SPI_CS;
    int maxDevices;
    int _auto_send;
    void spiTransfer(int addr, volatile byte opcode, volatile byte data) {
      int offset   = addr*2;
      int maxbytes = maxDevices*2;
      for(int i=0;i<maxbytes;i++)  { spidata[i]=(byte)0; }
      spidata[offset+1] = opcode;
      spidata[offset]   = data;
      digitalWrite(SPI_CS,LOW);
      for(int i=maxbytes;i>0;i--) { shiftOut(SPI_MOSI,SPI_CLK,MSBFIRST,spidata[i-1]); }
      digitalWrite(SPI_CS,HIGH);
    }
  public:
    LedControl(int dataPin, int clkPin, int csPin, int numDevices) {
      _auto_send  = true;
      SPI_MOSI    = dataPin;
      SPI_CLK     = clkPin;
      SPI_CS      = csPin;
      maxDevices  = numDevices;
      pinMode(SPI_MOSI, OUTPUT);
      pinMode(SPI_CLK,  OUTPUT);
      pinMode(SPI_CS,   OUTPUT);
      digitalWrite(SPI_CS, HIGH);
      status      = new byte[maxDevices * 8]; //instancia o array de acordo com a quantia de displays usados
      for(int i=0;i<maxDevices * 8 ;i++) { status[i]=0x00; }
      for(int i=0;i<maxDevices;i++) {
        spiTransfer(i, OP_DISPLAYTEST,0);
        setScanLimit(i, 7);               //scanlimit is set to max on startup
        spiTransfer(i, OP_DECODEMODE,0);  //decode is done in source
        clearDisplay(i);
        shutdown(i,true);                 //we go into shutdown-mode on startup
      }
    }
    void startWrite() {  _auto_send = false;  };
    void send() {
      for (int j=0; j<maxDevices; j++) {
        int offset = j*8;
        for(int i=0;i<8;i++) { spiTransfer(j, i+1, status[offset+i]); }
      }
      _auto_send = true;
    }
    int getDeviceCount(){ return maxDevices; }
    void shutdown(int addr, bool b){
      if(addr<0 || addr>=maxDevices) return;
      spiTransfer(addr, OP_SHUTDOWN, b ? 0 : 1);
    }
    void setScanLimit(int addr, int limit){
      if(addr<0 || addr>=maxDevices) return;
      if(limit>=0 && limit<8) spiTransfer(addr, OP_SCANLIMIT,limit);
    }
    void setIntensity(int addr, int intensity) {
      if(addr<0 || addr>=maxDevices)   {  return;                                    }
      if(intensity>=0 && intensity<16) {  spiTransfer(addr, OP_INTENSITY, intensity); }
    }
    void clearDisplay(int addr){
      if(addr<0 || addr>=maxDevices) return;
      int offset = addr*8;
      for(int i=0;i<8;i++) {
        status[offset+i] = 0;
        if (_auto_send) { spiTransfer(addr, i+1, status[offset+i]); }
      }
    }
    void setLed(int addr, int row, int column, boolean state) {
      if(addr<0 || addr>=maxDevices)             { return; }
      if(row<0 || row>7 || column<0 || column>7) { return; }
      int offset = addr*8;
      byte val = B10000000 >> column;
      if(state) { status[offset+row] = status[offset+row] | val; } else { val=~val; status[offset+row] = status[offset+row]&val; }
      if (_auto_send) { spiTransfer(addr, row+1, status[offset+row]); }
    }
    void setRow(int addr, int row, byte value) {
      if(addr<0 || addr>=maxDevices) return;
      if(row<0 || row>7) return;
      int offset = addr*8;
      status[offset+row] = value;
      if (_auto_send) { spiTransfer(addr, row+1, status[offset+row]); }
    }
    void setColumn(int addr, int col, byte value) {
      if(addr<0 || addr>=maxDevices) return;
      if(col<0 || col>7)             return;
      byte val;
      for(int row=0; row<8; row++) {
        val=value >> (7-row);
        val=val & 0x01;
        setLed(addr,row,col,val);
      }
    }
};
/*************************************************************************************************************
*******************************FIM LEDCONTROL ALTERADA********************************************************
**************************************************************************************************************/
     
/*************************************************************************************************************
************************************CLASSE ROTARY ENCODER*****************************************************
mais informações: http://fabianoallex.blogspot.com.br/2016/05/arduino-rotary-encoder.html
*************************************************************************************************************/
#define ROTARY_NO_BUTTON     255
         
struct RotaryEncoderLimits{
  int min;
  int max;
};
         
class RotaryEncoder {
  private:
    byte _pin_clk;
    byte _pin_dt;
    byte _pin_sw;
    volatile byte _num_results;
    volatile int _result;
    volatile int * _results;
    byte _index_result;
    RotaryEncoderLimits * _limits;
    byte _a : 1;
    byte _b : 1;
  public:
    RotaryEncoder(byte pin_clk, byte pin_dt, byte pin_sw = ROTARY_NO_BUTTON, byte num_results=1, RotaryEncoderLimits * limits=0){   //parametro do botao opcional
      _pin_clk = pin_clk;
      _pin_dt = pin_dt;
      _pin_sw = pin_sw;
      pinMode(_pin_clk, INPUT);
      pinMode(_pin_dt, INPUT);
      if (_pin_sw != ROTARY_NO_BUTTON){ 
        pinMode(_pin_sw, INPUT); 
        digitalWrite(_pin_sw, HIGH);
      }
      if (num_results == 0) { num_results = 1; }
      _num_results = num_results;
      _results = new int[_num_results];
      for (int i; i<_num_results; i++){ _results[i] = (limits) ? limits[i].min : 0; }
      _index_result = 0;
      _limits = limits;
      _a = false;
      _b = false;
    }
    byte getIndex() { return _index_result; }
    void next()     { _index_result++; if (_index_result >= _num_results) { _index_result = 0; } } 
    void update_a() {
      _result = 0;
      delay (1);
      if( digitalRead(_pin_clk) != _a ) { 
        _a = !_a;
        if ( _a && !_b ) { _result = -1; }
      }
      if (_results[_index_result]+_result >= _limits[_index_result].min && 
          _results[_index_result]+_result <= _limits[_index_result].max ) {
        _results[_index_result] += _result;
      }
    }
    void update_b() {
      _result = 0;
      delay (1);
      if( digitalRead(_pin_dt) != _b ) {  
        _b = !_b;
        if ( _b && !_a ) { _result = +1; }
      }
      if (_results[_index_result]+_result >= _limits[_index_result].min && 
          _results[_index_result]+_result <= _limits[_index_result].max ) {
        _results[_index_result] += _result;
      }
    }
    int read(){ return _result; }                                        //retorn -1, 0 ou 1.
    int getValue(int index=-1) {                                         //retorna o valor da variável corrente ou a passada como parametro
      if (index < 0 ){ return _results[_index_result]; }
      return _results[index];
    }
    void setValue(int value, int index=-1){ _results[ (index==-1) ? _index_result : index] = value; }         //caso a variável inicializa em determinado valor diferente de zero, utilizar esse método.
    int buttonRead(){ return (_pin_sw == ROTARY_NO_BUTTON) ? LOW : digitalRead(_pin_sw); }
};
/*************************************************************************************************************
************************************FIM CLASSE ROTARY ENCODER*************************************************
*************************************************************************************************************/
     
/*************************************************************************************************************
*******************************CLASSES TETRIS GAME************************************************************
**************************************************************************************************************/
const int TETRIS_TIME_INIT = 700; //tempo entre deslocamento dos inimigos
const int TETRIS_TIME_INC  = 20;  //incremento da velocidade
enum Direction        { DIR_STOP, DIR_TOP, DIR_LEFT, DIR_BOTTOM, DIR_RIGHT};
enum TetrisGameStatus { TETRIS_GAME_ON, TETRIS_GAME_OVER };
enum TetrisBlockTypes { TETRIS_I, TETRIS_J, TETRIS_L, TETRIS_O, TETRIS_S, TETRIS_Z, TETRIS_T, TETRIS_COUNT_BTYPES};
struct Position       { int row, column; };
struct Block          { byte row0:4; byte row1:4; byte row2:4; byte row3:4; };  //4 bit cada linha
//blocos e suas rotacoes
Block block_i[] = { {B1111, B0000, B0000, B0000}, {B0001, B0001, B0001, B0001} };
Block block_j[] = { {B0000, B0010, B0010, B0011}, {B0000, B0000, B0001, B0111}, {B0000, B0110, B0010, B0010}, {B0000, B0000, B0111, B0100} };
Block block_l[] = { {B0000, B0010, B0010, B0110}, {B0000, B0000, B0100, B0111}, {B0000, B0011, B0010, B0010}, {B0000, B0000, B0111, B0001} };
Block block_o[] = { {B0000, B0000, B0110, B0110} };
Block block_s[] = { {B0000, B0001, B0011, B0010}, {B0000, B0000, B0110, B0011} };
Block block_z[] = { {B0000, B0000, B0110, B1100}, {B0000, B1000, B1100, B0100} };
Block block_t[] = { {B0000, B0000, B0010, B0111}, {B0000, B0010, B0011, B0010}, {B0000, B0000, B0111, B0010}, {B0000, B0001, B0011, B0001} };
class TetrisBlock{
  private:
    Block _block;       //bloco que vai descendo. player
    Position _position; //posição do bloco na tela. pode assumir posição negativa
    TetrisBlockTypes _blockType;
    byte _blockTypeRotation;
  public:
    Position getPosition()  { return _position; }
    byte getRow(int row) { 
      if (row == 0 ) return _block.row0;
      if (row == 1 ) return _block.row1;
      if (row == 2 ) return _block.row2;
      if (row == 3 ) return _block.row3; 
      return 0;
    }
    byte getColumn(int col) {
      byte b = 0;
      for (int i=0;i<4;i++){ bitWrite(b, 3-i, bitRead(getRow(i), 3-col) );  }
      return b;
    }
    int read(int row, int column){
      byte b = getRow(row);
      unsigned int bit = column%8;    
      return (b & (1 << bit)) != 0;
    }
    void left()   { _position.column--;  }
    void right()  { _position.column++;  }
    void bottom() { _position.row++;     }
    void top()    { _position.row--;     }
    void generateBlock(byte col) {
      _position.row = 0; 
      _position.column = col; 
      _blockType =  (TetrisBlockTypes) random(0, TETRIS_COUNT_BTYPES);
      _blockTypeRotation = 0;
       
      if ( _blockType == TETRIS_I ){ _block = block_i[_blockTypeRotation]; }
      if ( _blockType == TETRIS_J ){ _block = block_j[_blockTypeRotation]; }
      if ( _blockType == TETRIS_L ){ _block = block_l[_blockTypeRotation]; }
      if ( _blockType == TETRIS_O ){ _block = block_o[_blockTypeRotation]; }
      if ( _blockType == TETRIS_S ){ _block = block_s[_blockTypeRotation]; }
      if ( _blockType == TETRIS_Z ){ _block = block_z[_blockTypeRotation]; }
      if ( _blockType == TETRIS_T ){ _block = block_t[_blockTypeRotation]; }
       
      if (!getRow(0))   { _position.row--;
        if (!getRow(1))   { _position.row--;          
          if (!getRow(2))   { _position.row--; } } }
    }
    void rotate(int direction = 1){
      int maxPos = 0;
      if ( _blockType == TETRIS_I ){ maxPos = sizeof(block_i)/sizeof(Block); }
      if ( _blockType == TETRIS_J ){ maxPos = sizeof(block_j)/sizeof(Block); }
      if ( _blockType == TETRIS_L ){ maxPos = sizeof(block_l)/sizeof(Block); }
      if ( _blockType == TETRIS_O ){ maxPos = sizeof(block_o)/sizeof(Block); }
      if ( _blockType == TETRIS_S ){ maxPos = sizeof(block_s)/sizeof(Block); }
      if ( _blockType == TETRIS_Z ){ maxPos = sizeof(block_z)/sizeof(Block); }
      if ( _blockType == TETRIS_T ){ maxPos = sizeof(block_t)/sizeof(Block); }
      (direction==1) ? _blockTypeRotation++ : _blockTypeRotation--;
      if (_blockTypeRotation == 255)    { _blockTypeRotation = maxPos-1; }
      if (_blockTypeRotation >= maxPos) { _blockTypeRotation = 0; }
      if ( _blockType == TETRIS_I ){ _block = block_i[_blockTypeRotation]; }
      if ( _blockType == TETRIS_J ){ _block = block_j[_blockTypeRotation]; }
      if ( _blockType == TETRIS_L ){ _block = block_l[_blockTypeRotation]; }
      if ( _blockType == TETRIS_O ){ _block = block_o[_blockTypeRotation]; }
      if ( _blockType == TETRIS_S ){ _block = block_s[_blockTypeRotation]; }
      if ( _blockType == TETRIS_Z ){ _block = block_z[_blockTypeRotation]; }
      if ( _blockType == TETRIS_T ){ _block = block_t[_blockTypeRotation]; }
    }
};
   
class TetrisGame {
  private:
    BitArray2D * _display;   //display com todos os objetos da tela. recebido como parâmetro
    BitArray2D * _recipient; //recepiente onde os blocos vão se acumulando. criado internamente pela classe
    TetrisBlock * _block;
    Direction _direction;
    TetrisGameStatus _tetrisGameStatus;
    unsigned long _last_millis;
    unsigned long _last_millis_player;
    int _time;
    int _score;
    byte _fast : 1;          //acelerar a descida
    UniqueRandom * _ur;      //utilizado no game over
    void _gameOver(){ 
      _tetrisGameStatus = TETRIS_GAME_OVER; 
      _direction   = DIR_STOP;
      _time = 20;
    }
    void _inc_speed(){
      _score++;
      _time -= TETRIS_TIME_INC;
    }
    void _start(){
      _recipient->clear();
      _last_millis = 0;
      _score = 0;
      _time = TETRIS_TIME_INIT;
      _fast = 0;
      _direction = DIR_STOP;
      _tetrisGameStatus = TETRIS_GAME_ON; 
      _newBlock();
    }
    void _newBlock() {
      _block->generateBlock( _display->columns() / 2 - 1 );
      if (_testCollision()){ _gameOver(); }
    }
    void _updateDisplay() {
      if (_tetrisGameStatus == TETRIS_GAME_ON) { _display->clear();  }
      for (int r=0; r<4; r++) {
        for (int c=0; c<4; c++) { 
          if ( _block->read(r, c) ) { 
            _display->write(_block->getPosition().row+r, _block->getPosition().column+c,  HIGH ); 
          }
        }
      }
      for (int row=0; row<_display->rows(); row++) {
        for (int col=0; col<_display->columns(); col++) {
          boolean val = _recipient->read(row, col);
          if (val) { _display->write(row, col,  val ); }
        }
      }
    }
    boolean _testCollision(){
      int col = _block->getPosition().column;  //coluna do bloco em relacao ao recepiente. pode ser negativa
      int row = _block->getPosition().row;     //linha do bloco em relacao ao recepiente. pode ser negativa
      for (byte c=0; c<4; c++){
        for (byte r=0; r<4; r++){
          if (! _block->read(r, c) )            { continue;  }  
          if ( row+r < 0 )                      {return true;}  
          if ( row+r >= _display->rows() )      {return true;}
          if ( col+c < 0 )                      {return true;}
          if ( col+c >= _display->columns() )   {return true;}
          if ( _recipient->read(row+r, col+c) ) {return true;}
        }
      }
      return false;
    }
    boolean _canLeft(){
      _block->left();
      boolean r = ! _testCollision();
      _block->right();
      return r;
    }
    boolean _canRight(){
      _block->right();
      boolean r = ! _testCollision();
      _block->left();
      return r;
    }
    boolean _canBottom(){
      _block->bottom();
      boolean r = ! _testCollision();
      _block->top();
      return r;
    }
    boolean _canRotate(){
      _block->rotate();
      boolean r = ! _testCollision();
      _block->rotate(-1);
      return r;
    }
    void _blockToRecipient(){
      for (byte c=0; c<4; c++){
        for (byte r=0; r<4; r++){
          if ( _block->read(r, c) ){ _recipient->write(_block->getPosition().row+r, _block->getPosition().column+c, HIGH); }
        }
      }
      _verifyCompleteRow();
      _newBlock();
    }
    void _verifyCompleteRow(){
      for (int row=0; row<_recipient->rows(); row++) {
        boolean complete = true;
        for (int col=0; col<_recipient->columns(); col++) {
          if (! _recipient->read(row, col) ) { complete = false; break; }
        }
        if (complete){ 
          _incScore(); 
          //move as linhas pra baixo
          for (int row2 = row; row2>=0; row2--) {
            for (int col2=0; col2<_recipient->columns(); col2++){
              _recipient->write(row2, col2,  (row2>0) ? _recipient->read(row2-1, col2) : 0 );
            }
          }
        }
      }
    }
    void _incScore(){
      _score++;
      _time -= TETRIS_TIME_INC;
    }
    void _runGameOver(){
      int r   = _ur->next();
      int row = (r / _display->columns());
      int col = (r % _display->columns());
      _display->write(row, col, HIGH );
      if ( _ur->getIndex() == (_ur->size()-1) ) {
        _ur->randomize();
        _ur->first();
        _start(); 
      }
    }
    void _runPlayer() {
      if (_direction == DIR_LEFT  && _canLeft()  ) { _block->left();  }
      if (_direction == DIR_RIGHT && _canRight() ) { _block->right(); }
      _direction = DIR_STOP;
    }
    void _runBlock() {
      _canBottom() ? _block->bottom() : _blockToRecipient() ;
      _direction = DIR_STOP; 
    }
  public:
    TetrisGame(BitArray2D * display){ 
      _display   = display;
      _recipient = new BitArray2D( _display->rows(), _display->columns() );
      _ur        = new UniqueRandom( _display->rows() * _display->columns() );
      _block     = new TetrisBlock();
      _start();
    }
    void fast()   { _fast = 1; }  //acelerar o deslocamento
    void noFast() { _fast = 0; }  //descida do bloco na velocidade normal
    void left()   { _direction = DIR_LEFT;   }
    void right()  { _direction = DIR_RIGHT;  }
    void bottom() { _direction = DIR_BOTTOM; }
    void rotate() { if (_canRotate()) { _block->rotate(); } }
    int getScore(){ return _score; }
    Position getPosition() { return _block->getPosition(); }
    int update(){
      int r = false;
      if (millis() - _last_millis > ( (_fast==1) ? 50 : _time ) ) { 
        r = true;
        _last_millis = millis();  
        if (_tetrisGameStatus == TETRIS_GAME_ON)   { _runBlock(); } 
        if (_tetrisGameStatus == TETRIS_GAME_OVER) { _runGameOver(); }
      }
      if (millis() - _last_millis_player > 70 ) {  //atualiza os movimentos do player a cada 70ms
        r = true;
        _last_millis_player = millis();  
        if (_tetrisGameStatus == TETRIS_GAME_ON)   { _runPlayer(); } 
      }
      if (r) { _updateDisplay(); }
      return r; //r-->indica se houve mudança no display
    }
};
/*************************************************************************************************************
*******************************FIM CLASSES TETRIS GAME********************************************************
**************************************************************************************************************/
   
/*************************************************************************************************************
*******************************DISPLAY************************************************************************
**************************************************************************************************************/
   
/*
rotation indica qual parte do display estará para cima
   
         TOP
L  . . . . . . . . R
E  . . . . . . . . I
F  . . . . . . . . G
T  . . . . . . . . H
   . . . . . . . . T
   . . . . . . . .
   . . . . . . . .
   . . . . . . . .   
       BOTTOM
       
*/
enum Rotation {TOP, LEFT, BOTTOM, RIGHT};
   
struct Display {
  int index;
  Position position; 
  Rotation rotation;
};
   
/*************************************************************************************************************
*******************************FIM DISPLAY********************************************************************
**************************************************************************************************************/
   
/*************************************************************************************************************
*******************************DECLARACAO DOS OBJETOS*********************************************************
**************************************************************************************************************/
/*
 tamanho display real
 * * * * * * * * * * * * * * * *
 * * * * * * * * * * * * * * * *
 * * * * * * * * * * * * * * * *
 * * * * * * * * * * * * * * * *
 * * * * * * * * * * * * * * * *
 * * * * * * * * * * * * * * * *
 * * * * * * * * * * * * * * * *
 * * * * * * * * * * * * * * * * 
*/
     
const int LINHAS  = 16;
const int COLUNAS = 8;
  
Display displays_8x8[] = {
  {1, {0,0}, BOTTOM},
  {0, {8,0}, TOP}
};
      
BitArray2D ba(LINHAS, COLUNAS); //8 linhas e 16 colunas, usada para armazenar o estado do display
TetrisGame tetris(&ba);
     
RotaryEncoderLimits lim[] = { {-1000,1000} };  //limites máximos e mínimos que as variaveis podem atingir
RotaryEncoder       re(A0, A1, 4, 1, lim);  //pino clk, pino dt, pino sw, qtd variaveis, limites
  
LedControl lc=LedControl(10,12,11,2);  //pin 10: DataIn ; pin 12: CLK ;  pin 11: LOAD   --- 2 display 8x8
/*************************************************************************************************************
*******************************FIM DECLARACAO DOS OBJETOS*****************************************************
**************************************************************************************************************/
       
/*************************************************************************************************************
*******************************TRATAMENTO DAS INTERRUPÇÕES****************************************************
**************************************************************************************************************/
//interrupções dos pinos A0 e A1 via Pin Change Interrupt
ISR(PCINT1_vect) {
  volatile static byte lastVal_a0 = LOW;
  volatile static byte lastVal_a1 = LOW;
  byte val_a0 = digitalRead(A0);
  byte val_a1 = digitalRead(A1);
  if (lastVal_a0 != val_a0){ re.update_a(); lastVal_a0 = val_a0; }
  if (lastVal_a1 != val_a1){ re.update_b(); lastVal_a1 = val_a1; }
}
      
void setup_interrupts(){
  //-----PCI - Pin Change Interrupt ----
  pinMode(A0,INPUT);   // set Pin as Input (default)
  digitalWrite(A0,HIGH);  // enable pullup resistor
  pinMode(A1,INPUT);   // set Pin as Input (default)
  digitalWrite(A1,HIGH);  // enable pullup resistor
  cli();
  PCICR |= 0b00000010; // habilita a porta C - Pin Change Interrupts
  PCMSK1 |= 0b00000011; // habilita interrupção da porta c nos pinos: PCINT8 (A0) e PCINT9(A1)
  sei();
}
/*************************************************************************************************************
*******************************FIM TRATAMENTO DAS INTERRUPÇÕES****************************************************
**************************************************************************************************************/
void update_display() {
  lc.startWrite();
  for (int lin=0; lin<ba.rows(); lin++) {
    for (int col=0; col<ba.columns(); col++) {
      for (int i=0; i<sizeof(displays_8x8)/sizeof(Display); i++) {
        int l = lin - displays_8x8[i].position.row;
        int c = col - displays_8x8[i].position.column;
        if (l>=0 && l<=7 && c>=0 && c<=7) {
          if (displays_8x8[i].rotation == BOTTOM) {            c=7-c; l=7-l;   }
          if (displays_8x8[i].rotation == LEFT)   { int aux=c; c=l;   l=7-aux; }
          if (displays_8x8[i].rotation == RIGHT)  { int aux=l; l=c;   c=7-aux; }
          lc.setLed(displays_8x8[i].index, l, c, ba.read(lin, col) );
        }
      }
    }
  }   
  lc.send();
}
   
void setup() { 
  lc.shutdown(0,false);
  lc.setIntensity(0,1);
  lc.clearDisplay(0);  
  lc.shutdown(1,false);
  lc.setIntensity(1,1);
  lc.clearDisplay(1);  
    
  setup_interrupts();
  randomSeed(analogRead(A2));
  re.setValue(0, 0);  //inicializa o rotary em 0
}
        
void loop() {
  static int val_encoder = 0;
  static boolean change = false;
   
  if (re.getValue(0) < val_encoder && !change){ tetris.left();  change = true; }  //sentido anti-horario move para esquerda
  if (re.getValue(0) > val_encoder && !change){ tetris.right(); change = true; }  //sentido horario move para direita
     
  val_encoder = re.getValue(0);
   
  if ( tetris.update() ) { 
    change = false;
    update_display(); 
  }  
       
  //controla o click do botao do enconder
  //clique curto --> rotate
  //clique longo --> fast
  static byte lastb = HIGH; //leitura anterior do botão
  static unsigned long m_pressed = 0;  //millis na borda de subida do botão
   
  int b = re.buttonRead();
  if( !b && lastb ) {    //borda de subida
    m_pressed = millis();
    delay(70);
  }
  if( b && !lastb ) {    //borda de descida
    if (millis() - m_pressed < 350) {
      tetris.rotate();
      m_pressed = millis();
    }
  } 
  if( !b &&  millis()-m_pressed > 350){
    tetris.fast(); 
  } else {
    tetris.noFast(); 
  }
  lastb = b;
} 
