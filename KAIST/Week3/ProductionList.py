from PlanNode import PlanNode

import matplotlib.pyplot as plt
import numpy as np
class ProductionList():
    def __init__(self, Filename):

        self.nodeHead = PlanNode(-1, '', '', '', '', '', '', '')
        self.nodeTail = PlanNode(-1, '', '', '', '', '', '', '')

        # Problem 2. setup the node relations between the nodeTail and nodeHead in
        # the properties. Use setNextNode and setPrevNode method of
        # the nodes

        self.nodeHead.set???????????????????????
        self.nodeTail.set????????????????????????

        f = open(Filename)
        temp = f.readlines()
        f.close()

        dataset = []
        for row in temp:
            dataset.append(row[:-1].split(','))
        Dataset = np.asarray(dataset[1:]).T

        numNos = Dataset[0].astype('int')
        strSerialNumbers = Dataset[1].astype('str')
        strModels = Dataset[2].astype('str')
        numModelNumbers = Dataset[3].astype('int')
        dateStart = Dataset[4].astype('str')
        numAssemblyOrders = Dataset[5].astype('int')
        dateEnd = Dataset[6].astype('str')
        strOrderOrigins = Dataset[7].astype('str')

        for i in range(len(numNos)):
            node = PlanNode(numNos[i], strSerialNumbers[i], strModels[i], numModelNumbers[i], dateStart[i],
                            numAssemblyOrders[i], dateEnd[i], strOrderOrigins[i])
            node.printOut()
            self.addLast(node)

        self.showPlanChart()

    def addLast(self, node):
        # Problem 3. complete the method to add the node in the parameter to the
        # last of the linked list. The tail should be always at the
        # last, so the node in the parameter should be the previous
        # node of the tail

        nodeLast = ???????????????????????????
        nodeLast.set??????????????
        node.set??????????????????
        node.set???????????????????????
        self.nodeTail.?????????????????

    def showPlanChart(self):

        allStartDate = []
        allModel = []
        node = self.nodeHead

        # Problem 4. iterate from nodeHead to nodeTail to retrieve the
        # start data and the model of all plan nodes.
        ????????? node.getNextNode() ??????????????????
            node = node.?????????????
            allStartDate.append(node.dateStart)
            allModel.append(node.strModel)

        plt.figure(1)
        plt.subplot(211)
        Uniq_allModel = list(set(allModel))
        Counting_allModel = [allModel.count(a) for a in Uniq_allModel]
        xlabel = [i for i in range(len(Uniq_allModel))]
        plt.bar(xlabel[0:10], Counting_allModel[0:10], align='center')
        plt.xticks(xlabel[0:10], Uniq_allModel[0:10])
        plt.xlabel('Model')
        plt.ylabel('Number of Orders')

        plt.subplot(212)
        Uniq_allStartDate = list(set(allStartDate))
        Counting_dateStart = [allStartDate.count(a) for a in Uniq_allStartDate]
        xlabel = [i for i in range(len(Uniq_allStartDate))]
        plt.bar(xlabel[0:10], Counting_dateStart[0:10], align='center')
        plt.xticks(xlabel[0:10], Uniq_allStartDate[0:10])
        plt.xlabel('Date')
        plt.ylabel('Number of Orders')
        plt.show()