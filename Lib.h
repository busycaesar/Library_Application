//******************************************************************//
//                                                                  //
// NAME       : DEV JIGISHKUMAR SHAH                                // 
// STUDENT ID : 131623217                                           //
// MAIL ID    : djshah11@myseneca.ca                                //
// COURSE     : OOP 244 NCC                                         //
// SUBMISSION : SENECA LIBRARY APPLICATION (MILESTONE 3)            //
//                                                                  //
//******************************************************************// 
//                                                                  //
// AUTHENTICITY DECLARATION :                                       //
// I DECLARE THAT THIS SUBMISSION IS THE RESULT OF MY OWN WORK AND  //
// HAS NOT BEEN SHARED WITH ANY OTHR STUDENT OR 3RD PARTY CONTENT   //
// PROVIDER. THIS SUBMITTED PIECE OF WORK IS ENTIRELY OF MY OWN     //
// CREATION.                                                        //
//                                                                  //
//******************************************************************//

#ifndef SDDS_LIB_H
#define SDDS_LIB_H

namespace sdds
{

    // MAXIMUM NUMBER OF DAYS A BOOK CAN BE BORROWED WITHOUT ANY PANELTY.
    const int SDDS_MAX_LOAN_DAYS = 15;

    // MAXIMUM WORDS IN THE TITLE OF THE PUBLICATION.
    const int SDDS_TITLE_WIDTH = 30;

    // MAXIMUM WORDS IN THE TITLE OF THE AUTHOR OF THE PUBLICATION.
    const int SDDS_AUTHOR_WIDTH = 15;

    // MAXIMUM WORDS IN THE ID OF SHELF.
    const int SDDS_SHELF_ID_LEN = 4;

    // MAXIMUM NUMBER OF PUBLICATION AVAILABE IN THE LIBRARY..
    const int SDDS_LIBRARY_CAPACITY = 5000;

}

#endif // !SDDS_LIB_H
