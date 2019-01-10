#ifndef HELP_H
#define HELP_H

#include "ingameobjects.h"

/**
 * @brief Short description
 *
 * Description
 */
class Help : public InGameObjects {

public:

    /**
     * @brief       Short description
     * @param X     X description
     */
    Help(QPixmap picture);

    /**
     * @brief       Short description
     * @param X     X description
     */
    ~Help();

    /**
     * @brief       Short description
     * @param X     X description
     */
    void mousePressEvent(QGraphicsSceneMouseEvent *);

    /**
     * @brief       Short description
     * @param X     X description
     */
    qint16 currentStep();

    /**
     * @brief       Short description
     * @param X     X description
     */
    void nextStep();

private:
    qint16 _step = 1; //!<
};

#endif // HELP_H
