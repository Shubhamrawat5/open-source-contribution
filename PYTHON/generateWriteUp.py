import sys
from PyQt5.QtWidgets import QFormLayout, QLineEdit, QPushButton, QApplication, QWidget, QPlainTextEdit
from PyQt5.QtGui import QFont
import pyautogui as pg

class Main(QWidget):
    def __init__(self):
        super().__init__()
        self.width = 600
        self.height = 900
        self.title = "Automation"
        self.left = 30
        self.top = 30

        self.fontSize = 13
        self.font = "Arial"

        self.setWindowTitle(self.title)
        self.setGeometry(self.left, self.top, self.width, self.height)
        self.setFixedSize(self.width, self.height)

    def initUI(self):
        self.form = QFormLayout()
        self.inputs = {
            "Title": "banner",
            "Site": "site",
            "Url": "url",
            "Input Format": "inp_form",
            "Output Format": "out_form",
            "Constraints" : "consts",
            "Sample Input": "as",
            "Sample Output": "sa",
            "Explanation": "exp",
            "My Code": "code",
            "Submit": "submit",
            "Screenshot": "scshot"
        }
        for key, value in self.inputs.items():
            if key == "Submit" or key == "Screenshot":
                globals()["{0}_inp".format(value)] = QPushButton(key, self)
                globals()["{0}_inp".format(value)].setFont(QFont(self.font, self.fontSize))
                if key == "Submit":
                    globals()["{0}_inp".format(value)].clicked.connect(self.getInput)
                    globals()["{0}_inp".format(value)].move(self.width-100, self.height-50)

                else:
                    globals()["{0}_inp".format(value)].clicked.connect(self.getScreen)
                    globals()["{0}_inp".format(value)].move(self.width-200, self.height-50)
            elif key in "TitleSiteUrl":
                globals()["{0}_inp".format(value)] = QLineEdit()
                globals()["{0}_inp".format(value)].setFont(QFont(self.font, self.fontSize))
                globals()["{0}_inp".format(value)].setFixedSize(200, 20)
            else:
                globals()["{0}_inp".format(value)] = QPlainTextEdit()
                globals()["{0}_inp".format(value)].setFont(QFont(self.font, self.fontSize))
                globals()["{0}_inp".format(value)].setFixedSize(200, 50)

            self.form.addRow(key, globals()["{0}_inp".format(value)])

        self.setLayout(self.form)

    def getInput(self):
        for key, value in self.inputs.items():
            if not key in "SubmitScreenshot":
                if key in "TitleSiteUrl":
                    globals()[value] = globals()["{0}_inp".format(value)].text()
                else:
                    globals()[value] = globals()["{0}_inp".format(value)].toPlainText()
        self.createFile()
    def getScreen(self):
        try:
            #if banner.upper() in 'CONPRNAUXNULCOMLPT<>:\"/\\|?* ':
            #    raise Exception("File name cannot be {0}".format(banner))
            print("asdfds")
            self.screenshot = pg.screenshot()
            self.screenshot.save(r"./screenshot.png")
        except Exception as e:
            print("Error: {0}".format(e))

    def createFile(self):
        with open("{0}.txt".format(banner), "w+") as f:
            for key, value in self.inputs.items():
                if not (key == "Submit" or key == "Screenshot") and not globals()[value] in " ":
                    if key in "ExplanationMy Code":
                        f.write("{0}: \n{1}\n\n".format(key, globals()[value]))    
                    else:
                        f.write("{0}: {1}\n\n".format(key, globals()[value]))
            f.close()
if __name__ == "__main__":
    app = QApplication(sys.argv)
    win = Main()
    win.initUI()
    win.show()
    sys.exit(app.exec_())