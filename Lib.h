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