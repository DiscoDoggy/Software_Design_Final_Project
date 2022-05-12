 > As you complete each section you **must** remove the prompt text. Every *turnin* of this project includes points for formatting of this README so keep it clean and keep it up to date. 
 > Prompt text is any lines beginning with "\>"
 > Replace anything between \<...\> with your project specifics and remove angle brackets. For example, you need to name your project and replace the header right below this line with that title (no angle brackets). 
<h2> Library System </h2>
 > Your author list below should include links to all members GitHub (remove existing author).
 
 > Authors: \<[Wanfang Li](https://github.com/wli229)\>
  \<[Chris Tillman](https://github.com/Orangechrisy)\>
  \<[Alexander Kaattari-Lim](https://github.com/akaatt)\>
 
 > You will be forming a group of **THREE** students and working on an interesting project. A list of proposed project ideas that have been successful in previous quarters is given in the project specifications link on iLearn. You can select an idea from the list and decide which design patterns you will use to implement it. If you want to propose your own original idea, you will have to contact an instructor to discuss the project and obtain written permission before you submit your project proposal. Your project needs to implement two design patterns.The project work should be divided almost equally among team members and each member is expected to work on at least one design pattern (more than one partner may work on a pattern) and some of its test cases. You can of course help each other, but it needs to be clear who will be responsible for which patterns and for which features.
 
 > ## Expectations
 > * Incorporate **at least two** distinct design patterns. You need to include at least *one* design pattern that we will teach this session:
 >   * Composite, Strategy, Abstract Factory, Visitor, or Decorator
 > * All design patterns need to be linked together (it can't be two distinct projects)
 > * Your project should be implemented in C++. If you wish to choose anoher programming language (e.g. Java, Python), please discuss with your lab TA to obtain permission.
 > * You can incorporate additional technologies/tools but they must be approved (in writing) by the instructor or the TA.
 > * Each member of the group **must** be committing code regularly and make sure their code is correctly attributed to them. We will be checking attributions to determine if there was equal contribution to the project.
> * All project phases are to be submitted to this GitHub repository. You should modify this README file to reflect the different phases of the project. In addition, you should regularly hold sprint meetings with your group.

## Project Description
 > Your project description should summarize the project you are proposing. Be sure to include <br>
 ><strong> * Why is it important or interesting to you?</strong><br>
 <p>  *Chris, Wanfang, and Alex have a passion for books and free accessible education. Before the pandemic, we would all happily frequent libraries but none of us have 
    truly investigated the underlaying software engineering of the technical systems that allow libraries to run. In our pursuit of knowledge, we believe that this
    project will better help us undertstand our community libraries from a more holistic point of view. </p><br>
    
 > <strong>* What languages/tools/technologies do you plan to use? (This list may change over the course of the project) </strong><br>
 >   * [toolname](link) - Short description <br><br>
 
   *We plan to use C++ and most likely its standard libraries such as the exception, string, vector, etc. We also plan to use git and git hub for our development flow. <br>
   
 > <strong> *What will be the input/output of your project? </strong><br>
 
  Some input would be account information, log in information, book searches, account information. Output will be user recomenndations, account debt, displaying books in various formats,  and account information. <br>
  

<h2>Design and Strategy Pattern Response to Proposal </h2>
For this project, we decided to use the factory pattern and the strategy pattern. The factory pattern in this case is a valuable pattern because it allows us to create different objects dynamically at run time and use their functions. For this project, there is a load and a save function. When loading library people from the allLibraryPeople.txt file, our program must figure out at runtime whether or not to create a User or an Admin. The factory then adds them all to a vector which becomes vector of all people associated with the library System. The Strategy pattern is good for deciding on a behavior at run time. In this program, there are multiple ways to sort a vector of books. You can sort alphabetically by title, alphabetically by author, and reverse alphabetically.The strategy pattern here allows us to based on the user's preferences, decide at run time which sort to  perform. 



 > ## Phase II
 
## Class Diagram


<a href = "https://docs.google.com/drawings/d/1ea1PQy0E-BS6zDrluWHfRV1S4kCliBEUnwRA3bCM4H0/edit?usp=sharing">Link to OMT Class Diagram</a>
 
 > ## Phase III
 > You will need to schedule a check-in with the TA (during lab hours or office hours). Your entire team must be present. 
 > * Before the meeting you should perform a sprint plan like you did in Phase II
 > * In the meeting with your TA you will discuss: 
 >   - How effective your last sprint was (each member should talk about what they did)
 >   - Any tasks that did not get completed last sprint, and how you took them into consideration for this sprint
 >   - Any bugs you've identified and created issues for during the sprint. Do you plan on fixing them in the next sprint or are they lower priority?
 >   - What tasks you are planning for this next sprint.

 > ## Final deliverable
 > All group members will give a demo to the TA during lab time. The TA will check the demo and the project GitHub repository and ask a few questions to all the team members. 
 > Before the demo, you should do the following:
 > * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
 > * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Kanban board. 
 
 ## Screenshots
 > Screenshots of the input/output after running your application
 ![image](https://user-images.githubusercontent.com/77080120/110721350-3b65cd80-81c5-11eb-9ae3-fedb66ea101a.png)
![image](https://user-images.githubusercontent.com/77080120/110721471-7d8f0f00-81c5-11eb-9897-47fcc2433ef1.png)
![image](https://user-images.githubusercontent.com/77080120/110721499-8a136780-81c5-11eb-8179-61c4f6696efb.png)

 ## Installation/Usage
 First, clone the repository recursively onto your local machine. In order to run this program you will need CMake in order to be able to build the program. Once you have cmake, on your own machine terminal, enter the directory where the repository you just cloned is stored. Run Cmake3 . and then make right after then enter ./test. You will then be prompted to register or login by the library system and can proceed to do either.
## Testing
 Because our program has a lot of circular dependcies in it at times getting things to compile together so they could be unit tested was difficult so we would also have to resort to using couts and visually and manually testing cases to make sure that a function was not broken. Google suite unit tests were also used. 
 
