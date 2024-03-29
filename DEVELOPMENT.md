# Development

---

Week 1:
- Built Box2D library and linked it to my project
- Created the basic class framework
- Researched Box2D and how it works

Week 2:
 - **4/25/20** 
    - Created the classes needed and basic framework
    - Added a SceneController class and started to set up the Box2D
     enviornment and necessary objects that will be displayed on the screen
    - Still need to finish setting up the objects and displaying the UI
     
 - **4/26/20** 
   - Added a SceneObjects class that was supposed to keep track of all the
    different objects on the screen like the ball, paddle, and blocks.
    - Had some trouble getting the working and using the structs
    - Still need to be able to display the objects in the UI

 - **4/27/20**
    - Deleted the SceneObjects class and created separate classes for each
     object
     - Finished creating the main setup of the objects
     - Started working on the UI and actually seeing the objects on the screen
     - Still need to understand Box2D and the conversion of the units between
      Cinder and Box2D
      - Keep tweaking UI and making it look like the actual game

 - **4/28/20**
    - Able to make the UI look like I wanted
    - Started looking into the conversions and make sure Cinder and Box2D
     matched up
     - Started to understand the conversion between the two so they align
      but still not perfect
      - Able to update the world to see the gravity on the ball
      - Changed the color so you can see the different blocks
      
 Week 3:
  - **4/29/20**
     - Took away the gravity and manually creating the forces
     - Able to move the paddle side to side and stops when colliding with the
      side wall
      
   - **4/28/20**
      - Working with collisions
      - Able to trigger the collision and set listener but cannot detect what
       body is connected with the contact
       
  - **5/3/20**
     - Able to remove the blocks when ball collides with it
     - Added the game over message
     
   - **5/4/20**
       - Added comments
       - Added tests
       - Updated Read.me
       - Done!