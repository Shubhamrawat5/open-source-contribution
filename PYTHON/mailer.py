import smtplib
import sys
def main():
    if sys.argv[1] == '-h' or sys.argv[1] == '--help':
        print("mailer.py [mode -l(--list) || -s(--single) ] [user -mail format- ] [password] [msg_count]")
        return
    elif sys.argv[1] == '-l' or sys.argv[1] == '--list':
        mod = 'list'
    else:
        mod = 'single'

    user = sys.argv[2]
    password = sys.argv[3]
    msg_count = int(sys.argv[4]) #or in the list mode, user_count

    if mod == 'list':
        to = []
        for _ in range(msg_count):
            to.append(input('Enter the email addresses of people you want to send email to:    '))
        subject = input('Enter the header, subject of the mail:    ')
        body = input('Enter the body text:\n')
        message = 'Subject: {}\n\n{}'.format(subject, body)
        try:
            server = smtplib.SMTP_SSL('smtp.gmail.com', 465)
            server.ehlo()
            server.login(user,password)
            for user in to:
                server.sendmail(user, to, message)
            print("All e-mails have been succesfully sent")    
        except Exception as e:
            print("{0} at this user: {1}".format(e, user))
    else:
        for _ in range(msg_count):
            to = input('Enter the email address of the person you want to send email to:    ')
            subject = input('Enter the header, subject of the mail:    ')
            body = input('Enter the body text:\n')
            message = 'Subject: {}\n\n{}'.format(subject, body)
            try:
                server = smtplib.SMTP_SSL('smtp.gmail.com', 465)
                server.ehlo()
                server.login(user,password)
                server.sendmail(user, to, message)
                print("E-mail has been succesfully sent")
            except Exception as e:
                print("Something went wrong... \n {0}".format(e))
            
if __name__ == '__main__':
    main()