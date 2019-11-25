#ifndef CHATBOT_H_
#define CHATBOT_H_

#include <wx/bitmap.h>
#include <string>
#include <iostream>

class GraphNode; // forward declaration
class ChatLogic; // forward declaration

class ChatBot
{
private:
    // data handles (owned)
    wxBitmap *_image; // avatar image

    // data handles (not owned)
    GraphNode *_currentNode;
    GraphNode *_rootNode;
    ChatLogic *_chatLogic;

    // proprietary functions
    int ComputeLevenshteinDistance(std::string s1, std::string s2);

public:
    // constructors / destructors
    ChatBot();                     // constructor WITHOUT memory allocation
    ChatBot(std::string filename); // constructor WITH memory allocation
    ~ChatBot();

    //// STUDENT CODE
    ////
    ChatBot(const ChatBot &source){
        std::cout << "COPY content"  << std::endl;

    _image=source._image; // avatar image

    _currentNode=source._currentNode;
    _rootNode=source._rootNode;
    _chatLogic=source._chatLogic;
    
    };
    
    ChatBot &operator=(const ChatBot &source){
    std::cout << "COPY = content"  << std::endl;
        if (this == &source)
            return *this;

         _image = new wxBitmap();
        _image = source._image;
         _currentNode=source._currentNode;
    	_rootNode=source._rootNode;
    	_chatLogic=source._chatLogic;
        return *this;
    }
    
    ChatBot(ChatBot &&source)noexcept  {
    
     
  this->_image = source._image;
  source._image = nullptr;
  this->_currentNode = source._currentNode;
  source._currentNode = nullptr;
  this->_rootNode = source._rootNode;
  source._rootNode = nullptr;
  this->_chatLogic = source._chatLogic;
  source._chatLogic = nullptr;
    std::cout << "MOVING content "<< std::endl;

    }
    
    ChatBot &operator=(ChatBot &&source)noexcept {
    
     
     	 if (this == &source)
            return *this;
        
  
  this->_image = source._image;
  source._image = NULL;
  this->_currentNode = source._currentNode;
  source._currentNode = nullptr;
  this->_rootNode = source._rootNode;
  source._rootNode = nullptr;
  _chatLogic = source._chatLogic;
  source._chatLogic = nullptr;
      std::cout << "MOVING (sign) " << std::endl;
  return *this;
    

    }
    ////
    //// EOF STUDENT CODE

    // getters / setters
    void SetCurrentNode(GraphNode *node);
    void SetRootNode(GraphNode *rootNode) { _rootNode = rootNode; }
    void SetChatLogicHandle(ChatLogic *chatLogic) { _chatLogic = chatLogic; }
    wxBitmap *GetImageHandle() { return _image; }

    // communication
    void ReceiveMessageFromUser(std::string message);
};

#endif /* CHATBOT_H_ */